/******************************************************************************
*文件名称:  csystemsetting.cpp
*描    述:  设置管理
*作    者:  
*创建日期:  
*当前版本:  
*版本历史:
*注    释:  设置全局管理类，对设置进行读取跟修改操作。
*
*******************************************************************************/

/***********************************头文件*************************************/
#include "csystemsetting.h"
#include <QSettings>
#include <QString>
#include <QDir>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <QTextCodec>
#include <QDateTime>


/***********************************常量定义***********************************/


CSystemSetting *CSystemSetting::m_instance = NULL;

CSystemSetting::CSystemSetting(QObject *parent) :
        QObject(parent)
        , mp_currentLang(NULL)
		, mp_currentQtLang(NULL)
{
    //初始化
    initParameters();
  
	//ReadConfigureInfo();

}

void CSystemSetting::initParameters()
{	
   
    //defaultStoragePosition = "";
  
    //皮肤
    skinType = 0;
	skinColor = QColor(216, 216, 216);
    SkinPixmap = "";

    skinCustom1 = "";
    skinCustom2 = "";
    
}

void CSystemSetting::setSettingInstance(CSystemSetting* pointer)
{
    if (m_instance != NULL && m_instance != pointer)
    {
        delete m_instance;
        m_instance = NULL;
    }

    m_instance = pointer;
}

/******************************************************************************
* 函  数: const QString CSystemSetting::writeSetting(bool isSuccessQuit)
*
* 描  述: 保存是否正常退出
*
* 参  数:bool isSuccessQuit
*
*
* 返回值:
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::writeSetting(bool isSuccessQuit)
{
    QSettings setting("RC", "CSystemSettings", this);
    setting.setValue("isSuccessQuit", isSuccessQuit);
}


/******************************************************************************
* 函  数: CSystemSetting::installAppLanguage(const QString &languageName)
*
* 描  述: 设置程序语言
*
* 参  数:
*           const QString &languageName 语言名字
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::installAppLanguage(const QString &languageName)
{
	QSettings l_languageSettings("./Data/language.ini", QSettings::IniFormat);
	l_languageSettings.setIniCodec("UTF-8");
    l_languageSettings.beginGroup("CURRENT");

    QByteArray l_byteArray = l_languageSettings
                         .value("currentLang", QString(""))
                         .toByteArray();

    QString l_currentLangName = QString(l_byteArray.constData());

    l_languageSettings.endGroup();


    //start up first time by yanyan
    if (QFile::exists("Data/favarite_language.ini"))
    {
        QSettings l_firstStartSetting("Data/favarite_language.ini", QSettings::IniFormat);
        l_firstStartSetting.setIniCodec("GB18030");

        QString langKey = l_firstStartSetting
                          .value("language", QString(""))
                          .toString();

//         l_languageSettings.beginGroup("LANGUAGE_NAME");
//         l_byteArray = l_languageSettings
//                       .value(langKey, QString(""))
//                       .toByteArray();
//         l_languageSettings.endGroup();

       // l_currentLangName = QString(l_byteArray.constData());
        l_currentLangName = langKey;

        QFile::remove("Data/favarite_language.ini");

        l_languageSettings.beginGroup("CURRENT");

        l_languageSettings.setValue("currentLang", l_currentLangName);

        l_languageSettings.endGroup();
    }


    //如果语言没有变化, 则不执行后面的语句
 /*   if (languageName == l_currentLangName)
    {
        return;
    }*/

    //检测语言文件存储路径
    QString l_langDirPath = "Data/Language/";
    QDir l_curPath = QDir::current();

    if (!l_curPath.cd(l_langDirPath))
    {
        l_curPath.mkpath(l_langDirPath);
    }

    if (languageName != "") //设置新语言
    {
        l_languageSettings.beginGroup("LANGUAGE_NAME");

        QStringList l_idList = l_languageSettings.childKeys();
        if (!l_idList.isEmpty())
        {
            for (int i = 0; i < l_idList.count(); i++)
            {
				//chenzanhua 20120315 modity
                /*QByteArray l_byteArray = l_languageSettings
                                         .value(l_idList.at(i), QString(""))
                                         .toByteArray();*/
                if (languageName == l_idList.at(i))//l_byteArray.constData()
                {
                    //将当前语言保存为新的语言
                    l_languageSettings.endGroup();
                    l_languageSettings.beginGroup("CURRENT");
                    l_languageSettings.setValue("currentLang", languageName);
                    l_languageSettings.endGroup();

                    l_languageSettings.beginGroup("LANGUAGE_FILE");
                    QByteArray l_byteArray = l_languageSettings
                                             .value(l_idList.at(i), QString(""))
                                             .toByteArray();
                    QString l_newLang = l_byteArray.constData();

                    QByteArray l_byteArrayQt = l_languageSettings
                            .value(l_idList.at(i)+"Qt", QString(""))
                                             .toByteArray();
                    QString l_newLangQt = l_byteArrayQt.constData();
                    l_languageSettings.endGroup();

                    if (l_newLang != "") //加载语言
                    {
                        if (mp_currentLang != NULL)
                        {
                            qApp->removeTranslator(mp_currentLang);
                        }

                        QTranslator *l_translator = new QTranslator(qApp);
                        l_translator->load(l_langDirPath + l_newLang);
                        qApp->installTranslator(l_translator);

                        mp_currentLang = l_translator;
                    }
                    if (l_newLangQt != "")
                    {
                        if (mp_currentQtLang != NULL)
                        {
                            qApp->removeTranslator(mp_currentQtLang);
                            mp_currentQtLang = NULL;
                        }
                        if(l_newLangQt != "default")
                        {
                            QTranslator *l_translator = new QTranslator(qApp);
                            l_translator->load(l_langDirPath + l_newLangQt);
                            qApp->installTranslator(l_translator);

                            mp_currentQtLang = l_translator;
                        }
                    }
                    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
                    emit signalChangeLanguage( languageName );//qiangzh 2011-09-19

                    return;
                }
            }
        }
    }
    else //将程序语言设置为当前语言
    {
        l_languageSettings.beginGroup("LANGUAGE_NAME");
        QStringList l_idList = l_languageSettings.childKeys();
        if (!l_idList.isEmpty())
        {
            for (int i = 0; i < l_idList.count(); i++)
            {
                if (l_currentLangName == l_idList.value(i))//l_byteArray.constData())
                {
                    l_languageSettings.endGroup();
                    l_languageSettings.beginGroup("LANGUAGE_FILE");
                    QByteArray l_byteArray = l_languageSettings
                                             .value(l_idList.at(i), QString(""))
                                             .toByteArray();
                    QString l_newLang = l_byteArray.constData();

                    QByteArray l_byteArrayQt = l_languageSettings
                            .value(l_idList.at(i)+"Qt", QString(""))
                                             .toByteArray();
                    QString l_newLangQt = l_byteArrayQt.constData();
                    l_languageSettings.endGroup();

                    if (l_newLang != "") //加载语言
                    {
                        if (mp_currentLang != NULL)
                        {
                            qApp->removeTranslator(mp_currentLang);
                        }

                        QTranslator *l_translator = new QTranslator(qApp);
                        l_translator->load(l_langDirPath + l_newLang);
                        qApp->installTranslator(l_translator);

                        mp_currentLang = l_translator;
                    }
                    if (l_newLangQt != "")
                    {
                        if (mp_currentQtLang != NULL)
                        {
                            qApp->removeTranslator(mp_currentQtLang);
                            mp_currentQtLang = NULL;
                        }
                        if(l_newLangQt != "default")
                        {
                            QTranslator *l_translator = new QTranslator(qApp);
                            l_translator->load(l_langDirPath + l_newLangQt);
                            qApp->installTranslator(l_translator);

                            mp_currentQtLang = l_translator;
                        }
                    }

                    emit signalChangeLanguage( l_currentLangName ); 

                    return;
                }
            }
        }
    }
}

/******************************************************************************
* 函  数: const QStringList CSystemSetting::getLanguageList()
*
* 描  述: 获取当前支持的语言列表
*
* 参  数:
*
*
* 返回值: const QStringList 语言列表
*
* 注  释:
*
******************************************************************************/
const QStringList CSystemSetting::getLanguageList()
{
    QSettings l_languageSettings("./Data/language.ini", QSettings::IniFormat);
    l_languageSettings.setIniCodec("UTF-8");
    l_languageSettings.beginGroup("LANGUAGE_NAME");

    QStringList l_idList = l_languageSettings.childKeys();
    QStringList l_languageList;

    if (!l_idList.isEmpty())
    {
        for (int i = 0; i < l_idList.count(); i++)
        {
            QByteArray l_byteArray = l_languageSettings
                                     .value(l_idList.at(i), QString(""))
                                     .toByteArray();

            l_languageList.append(QString(l_byteArray.constData()));
			m_languageMap.insert(l_idList.at(i),QString(l_byteArray.constData()));
        }
    }
    return l_languageList;
}

/******************************************************************************
* 函  数: const QString CSystemSetting::getCurrentLanguage()
*
* 描  述: 获取当前语言
*
* 参  数:
*
*
* 返回值: const QString 当前语言
*
* 注  释:
*
******************************************************************************/
const QString CSystemSetting::getCurrentLanguage()
{
    QSettings l_languageSettings("./Data/language.ini", QSettings::IniFormat);
    l_languageSettings.setIniCodec("UTF-8");
    l_languageSettings.beginGroup("CURRENT");

    QByteArray l_byteArray = l_languageSettings
                             .value("currentLang", QString(""))
                             .toByteArray();
    return QString(l_byteArray.constData());
}

/******************************************************************************
* 函  数: const QString CSystemSetting::readSetting()
*
* 描  述: 获取设置
*
* 参  数:
*
*
* 返回值:
*
* 注  释:
*
******************************************************************************/
const bool CSystemSetting::readSetting()
{
    QSettings setting("RC", "CSystemSettings", this);
    return setting.value("isSuccessQuit", true).toBool();
}

/******************************************************************************
* 函  数: CSystemSetting* getInstance(QObject *parent)
*
* 描  述: 返回类的单例实例
*
* 参  数:
*
*
* 返回值: 实例指针
*
* 注  释:
*
******************************************************************************/
CSystemSetting* CSystemSetting::getInstance(QObject *parent)
{
    if(m_instance == NULL)
    {
        m_instance = new CSystemSetting(parent);
    }

    return m_instance;
}

CSystemSetting::~CSystemSetting()
{
    if(m_instance != NULL)
    {
        m_instance->deleteLater();
        m_instance = NULL;
    }
}

/******************************************************************************
* 函  数: CSystemSetting::initSettingInfo(const QString &fileName)
*
* 描  述: 初始化设置信息
*
* 参  数: 输入:
*              const QString &fileName， 设置的配置文件
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::initSettingInfo(const QString &fileName)
{
    m_fileName = fileName;
    initParameters();
    resetSettingInfo(m_fileName);
}

/******************************************************************************
* 函  数: CSystemSetting::resetSettingInfo(const QString &fileName)
*
* 描  述: 重新加载设置信息
*
* 参  数: 输入:
*              const QString &fileName， 设置的配置文件
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::resetSettingInfo(const QString &fileName)
{
    QSettings l_cfg(fileName, QSettings::IniFormat);
    l_cfg.setIniCodec("GB18030"); // 设置配置文件的编码格式

    //皮肤
    skinType = l_cfg.value("skinType", skinType).toInt();
    skinColor = QColor(l_cfg.value("skinColor", skinColor).toString());
    SkinPixmap = l_cfg.value("SkinPixmap", SkinPixmap).toString();
    skinCustom1 = l_cfg.value("skinCustom1", skinCustom1).toString();
    skinCustom2 = l_cfg.value("skinCustom2", skinCustom2).toString();
}

QString CSystemSetting::GetConfigFileValue()
{
	QString l_CurrentViewStatus;

	QSettings l_cfg(m_fileName, QSettings::IniFormat);
	l_cfg.setIniCodec("GB18030");

	l_CurrentViewStatus = l_cfg.value("currentViewStatus", l_CurrentViewStatus).toString();

	return l_CurrentViewStatus;
}

/******************************************************************************
* 函  数: void CSystemSetting::setRectOfMainWidget(const QRect &rect)
*
* 描  述: 设置主界面的区域
*
* 参  数: 输入: rect, 设置的区域
*
*
*
* 返回值:
*
* 注  释: wangzhenzhi添加
*
******************************************************************************/
void CSystemSetting::setRectOfMainWidget(const QRect &rect)//设置主界面的区域
{
    qDebug()<<"存储主界面的区域"<<rect;
    setValueToFile("MainWidget/Rect", rect);
}

/******************************************************************************
* 函  数: QRect CSystemSetting::getPosOfMainWidget()//读取主界面的区域
*
* 描  述: 读取主界面的区域
*
* 参  数:
*
*
*
* 返回值: 读取的rect
*
* 注  释: wangzhenzhi添加
*
******************************************************************************/
QRect CSystemSetting::getRectOfMainWidget()//读取主界面的区域
{
    QRect l_defRect = QRect();//当没有读取到存储的数据时,用默认数据
//    QRect l_deskRect = QApplication::desktop()->rect();//取得桌面区域

    //晏炎 于2011-06-07修改, 解决在多屏下计算屏幕区域不对的问题
    QRect l_deskRect = QApplication::desktop()
                            ->availableGeometry(QApplication::desktop()
                                                ->screenNumber());

    l_defRect.setX(l_deskRect.width()-282-10);
    l_defRect.setY(160);
    l_defRect.setWidth(282);
    l_defRect.setHeight(621);

    //返回读取的Rect
    return getValueFromFile("MainWidget/Rect", l_defRect).toRect();
}

/******************************************************************************
* 函  数: CSystemSetting::createSettingFile(const QString &fileName)
*
* 描  述: 创建默认设置文件
*
* 参  数: 输入:
*              const QString &fileName， 设置的配置文件
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::createSettingFile(const QString &fileName)
{
    m_fileName = fileName;

    QSettings l_cfg(fileName, QSettings::IniFormat);
    l_cfg.setIniCodec("Windows-1252"); // 设置配置文件的编码格式
    l_cfg.clear(); // 清空设置文件

    initParameters();

    //皮肤
    l_cfg.setValue("skinType", skinType);
    l_cfg.setValue("skinColor", skinColor.name());
    l_cfg.setValue("SkinPixmap", SkinPixmap);
    l_cfg.setValue("skinCustom1", skinCustom1);
    l_cfg.setValue("skinCustom2", skinCustom2);

}

/******************************************************************************
* 函  数: QVariant CSystemSetting::getValueFromFile(const QString &key)
*
* 描  述: 读取配置文件中配置项内容的常规通用方法
*
* 参  数: 输入: key, 设置的查询项
*
*
*
* 返回值: 读取的内容
*
* 注  释: wangzhenzhi添加
*
******************************************************************************/
QVariant CSystemSetting::getValueFromFile(const QString &key, const QVariant &defaultValue)
{
	QSettings l_cfg(m_fileName, QSettings::IniFormat);
	l_cfg.setIniCodec("GB18030");
	QString strTempOnly;
	QString sTempBak;
	QVariant qvarTemp;
	qvarTemp = l_cfg.value(key, defaultValue);
	strTempOnly = qvarTemp.toString();

	return l_cfg.value(key, defaultValue);
}

/******************************************************************************
* 函  数: CSystemSetting::setAutoRun(bool enable, bool curUserOnly)
*
* 描  述: 设置开机自动运行
*
* 参  数: 输入:
*              bool enable， TRUE:开启自动运行； FLASE：关闭自动运行
*              bool curUserOnly， TRUE：对当前用户有效；FALSE：对整个机器有效
*
* 返回值: bool, TRUE,设置成功
*
* 注  释:
*
******************************************************************************/
bool CSystemSetting::setAutoRun(bool enable, bool curUserOnly)
{
 //   for (int i = 0; i < AUTO_RUN_REG_COUNT; i++)
 //   {
 //       QSettings l_settings(s_strTypes[i], QSettings::NativeFormat);
 //       l_settings.setValue(s_strRegKey, "");
 //   }
 //   // 取消自动运行，退出
 //   if (!enable) 
	//{
	//	return true;
	//}
 //   // 设置自动运行
 //   int l_idx = 0;
 //   if (curUserOnly)
 //   {
 //       l_idx = 1;
 //   }
 //   QSettings l_settings(s_strTypes[l_idx], QSettings::NativeFormat);
 //   QString l_curDir = QDir::currentPath();
 //   l_settings.setValue(s_strRegKey,
 //                  QDir::toNativeSeparators(l_curDir + s_strAppName));

    return true;
}

/******************************************************************************
* 函  数: CSystemSetting::isAutoRun(bool curUserOnly)
*
* 描  述: 判断是否开机自动运行
*
* 参  数: 输入:
*              bool curUserOnly， TRUE：对当前用户有效；FALSE：对整个机器有效
*
* 返回值: bool, TRUE,开启自动运行；FALSE，自动运行已关闭
*
* 注  释:
*
******************************************************************************/
bool CSystemSetting::isAutoRun(bool curUserOnly)
{
    bool l_ret = false;
    int l_idx = 0;
    if (curUserOnly)
    {
        l_idx = 1;
    }
    //QSettings l_settings(s_strTypes[l_idx], QSettings::NativeFormat);
    //QString l_curDir = QDir::currentPath();
    //QString l_regPath = l_settings.value(s_strRegKey).toString();
    //QString l_appPath = QDir::toNativeSeparators(l_curDir + s_strAppName);
    //if (l_regPath.compare(l_appPath, Qt::CaseInsensitive) == 0)
    {
        l_ret = true;
    }

    return l_ret;
}

/******************************************************************************
* 函  数: CSystemSetting::setSkinConfig(int type, const QVariant &value)
*
* 描  述: 设置皮肤参数
*
* 参  数: 输入:
*         int type              背景类型
*         const QVariant &value 取值(颜色模式为颜色, 图片模式为图片路径)
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::setSkinConfig(int type, const QVariant &value)
{
    QSettings l_cfg(m_fileName, QSettings::IniFormat);
    l_cfg.setIniCodec("GB18030");

    if (type == ColorType)
    {
        l_cfg.setValue("skinColor", QColor(value.toString()).name());
        skinColor = QColor(value.toString());
    }
    else if (type == PixmapType)
    {
        if (QPixmap(value.toString()).isNull())
        {
            return;
        }

        l_cfg.setValue("SkinPixmap", value);
        SkinPixmap = value.toString();
    }

    l_cfg.setValue("skinType", type);
    skinType = type;

    emit signalUpdateSetting("skinChanged");
}

/******************************************************************************
* 函  数: CSystemSetting::getSkinConfig(int &type, QVariant &value)
*
* 描  述: 获得皮肤参数
*
* 参  数: 输入:
*         int type          背景类型
*         QVariant &value   取值(颜色模式为颜色, 图片模式为图片路径)
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::getSkinConfig(int &type, QVariant &value)
{
    type = skinType;
//        qDebug()<<__FILE__<<__LINE__<<type<<SkinPixmap;
    if (type == ColorType)
    {
        value = QVariant(skinColor);
    }
    else if (type == PixmapType)
    {
        //解决异常情况时无法正确获取皮肤图片的bug
        QString l_path;
        QDir l_dir;
        if(l_dir.exists(QApplication::applicationDirPath()+"/Res"))
        {
            l_path = QApplication::applicationDirPath();
        }else
            if(l_dir.exists(QApplication::applicationDirPath()+"/../Res"))
            {
                l_path = QApplication::applicationDirPath()+"/..";
            }

        if (!QFile::exists(l_path+"/"+SkinPixmap))
        {
//            qDebug()<<__FILE__<<__LINE__<<type<<l_path<<SkinPixmap;
            QSettings l_cfg(m_fileName, QSettings::IniFormat);
            l_cfg.setIniCodec("GB18030");

            type = DefaultType;
            l_cfg.setValue("skinType", type);
            skinType = type;

            return;
        }

        value = QVariant(l_path +"/"+SkinPixmap);
    }
}
/******************************************************************************
* 函  数: CSystemSetting::setValueToFile(const QString &key, const QVariant &value)
*
* 描  述: 设置配置文件中配置项的内容
*
* 参  数: 输入:
*              const QString &key， 设置的配置项
*              const QVariant &value， 设置的内容
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CSystemSetting::setValueToFile(const QString &key, const QVariant &value)
{
	QSettings l_cfg(m_fileName, QSettings::IniFormat);
	l_cfg.setIniCodec("GB18030");

	if (l_cfg.value(key) != value)
	{
		l_cfg.setValue(key, value); // 存储其他值
		resetSettingInfo(m_fileName);
	}
	//系统热键切换的时候可能不需要重写配置文件，但是每次都必须重新注册一次，所以要放到
	//外面来发这个信号
	emit signalUpdateSetting(key);

}



////判断输入的邮件地址是否有效 
//bool CSystemSetting::isEmaiAvailabity(QString emailaddress)
//{
//	QRegExp rxlen("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"); ///w+([-+.]/w+)*@/w+([-.]/w+)*/./w+([-.]/w+)*    ^[/w-]+(/.[/w-]+)*@[/w-]+(/.[/w-]+)+$
//    int pos = 0;
//	if (emailaddress.isEmpty())
//	{
//		return true;
//	}
//	else
//	{
//		if ((pos = rxlen.indexIn(emailaddress,pos)) != -1)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//}
//
//
////根据中文获取相应的拼音
//QString CSystemSetting::ConvertChineseUnicodeToPyt(const QString &strChinese)
//{
//
//	qDebug()<<" ConvertChineseUnicodeToPyt: "<<strChinese;
//	const static int pyValue[] = {-20319,-20317,-20304,-20295,-20292,-20283,-20265,-20257,-20242,-20230,-20051,-20036,-20032,-20026,
//		-20002,-19990,-19986,-19982,-19976,-19805,-19784,-19775,-19774,-19763,-19756,-19751,-19746,-19741,-19739,-19728,
//		-19725,-19715,-19540,-19531,-19525,-19515,-19500,-19484,-19479,-19467,-19289,-19288,-19281,-19275,-19270,-19263,
//		-19261,-19249,-19243,-19242,-19238,-19235,-19227,-19224,-19218,-19212,-19038,-19023,-19018,-19006,-19003,-18996,
//		-18977,-18961,-18952,-18783,-18774,-18773,-18763,-18756,-18741,-18735,-18731,-18722,-18710,-18697,-18696,-18526,
//		-18518,-18501,-18490,-18478,-18463,-18448,-18447,-18446,-18239,-18237,-18231,-18220,-18211,-18201,-18184,-18183,
//		-18181,-18012,-17997,-17988,-17970,-17964,-17961,-17950,-17947,-17931,-17928,-17922,-17759,-17752,-17733,-17730,
//		-17721,-17703,-17701,-17697,-17692,-17683,-17676,-17496,-17487,-17482,-17468,-17454,-17433,-17427,-17417,-17202,
//		-17185,-16983,-16970,-16942,-16915,-16733,-16708,-16706,-16689,-16664,-16657,-16647,-16474,-16470,-16465,-16459,
//		-16452,-16448,-16433,-16429,-16427,-16423,-16419,-16412,-16407,-16403,-16401,-16393,-16220,-16216,-16212,-16205,
//		-16202,-16187,-16180,-16171,-16169,-16158,-16155,-15959,-15958,-15944,-15933,-15920,-15915,-15903,-15889,-15878,
//		-15707,-15701,-15681,-15667,-15661,-15659,-15652,-15640,-15631,-15625,-15454,-15448,-15436,-15435,-15419,-15416,
//		-15408,-15394,-15385,-15377,-15375,-15369,-15363,-15362,-15183,-15180,-15165,-15158,-15153,-15150,-15149,-15144,
//		-15143,-15141,-15140,-15139,-15128,-15121,-15119,-15117,-15110,-15109,-14941,-14937,-14933,-14930,-14929,-14928,
//		-14926,-14922,-14921,-14914,-14908,-14902,-14894,-14889,-14882,-14873,-14871,-14857,-14678,-14674,-14670,-14668,
//		-14663,-14654,-14645,-14630,-14594,-14429,-14407,-14399,-14384,-14379,-14368,-14355,-14353,-14345,-14170,-14159,
//		-14151,-14149,-14145,-14140,-14137,-14135,-14125,-14123,-14122,-14112,-14109,-14099,-14097,-14094,-14092,-14090,
//		-14087,-14083,-13917,-13914,-13910,-13907,-13906,-13905,-13896,-13894,-13878,-13870,-13859,-13847,-13831,-13658,
//		-13611,-13601,-13406,-13404,-13400,-13398,-13395,-13391,-13387,-13383,-13367,-13359,-13356,-13343,-13340,-13329,
//		-13326,-13318,-13147,-13138,-13120,-13107,-13096,-13095,-13091,-13076,-13068,-13063,-13060,-12888,-12875,-12871,
//		-12860,-12858,-12852,-12849,-12838,-12831,-12829,-12812,-12802,-12607,-12597,-12594,-12585,-12556,-12359,-12346,
//		-12320,-12300,-12120,-12099,-12089,-12074,-12067,-12058,-12039,-11867,-11861,-11847,-11831,-11798,-11781,-11604,
//		-11589,-11536,-11358,-11340,-11339,-11324,-11303,-11097,-11077,-11067,-11055,-11052,-11045,-11041,-11038,-11024,
//		-11020,-11019,-11018,-11014,-10838,-10832,-10815,-10800,-10790,-10780,-10764,-10587,-10544,-10533,-10519,-10331,
//		-10329,-10328,-10322,-10315,-10309,-10307,-10296,-10281,-10274,-10270,-10262,-10260,-10256,-10254};
//	const char pyString[396][7] = {"a","ai","an","ang","ao","ba","bai","ban","bang","bao","bei","ben","beng","bi","bian","biao",
//		"bie","bin","bing","bo","bu","ca","cai","can","cang","cao","ce","ceng","cha","chai","chan","chang","chao","che","chen",
//		"cheng","chi","chong","chou","chu","chuai","chuan","chuang","chui","chun","chuo","ci","cong","cou","cu","cuan","cui",
//		"cun","cuo","da","dai","dan","dang","dao","de","deng","di","dian","diao","die","ding","diu","dong","dou","du","duan",
//		"dui","dun","duo","e","en","er","fa","fan","fang","fei","fen","feng","fo","fou","fu","ga","gai","gan","gang","gao",
//		"ge","gei","gen","geng","gong","gou","gu","gua","guai","guan","guang","gui","gun","guo","ha","hai","han","hang",
//		"hao","he","hei","hen","heng","hong","hou","hu","hua","huai","huan","huang","hui","hun","huo","ji","jia","jian",
//		"jiang","jiao","jie","jin","jing","jiong","jiu","ju","juan","jue","jun","ka","kai","kan","kang","kao","ke","ken",
//		"keng","kong","kou","ku","kua","kuai","kuan","kuang","kui","kun","kuo","la","lai","lan","lang","lao","le","lei",
//		"leng","li","lia","lian","liang","liao","lie","lin","ling","liu","long","lou","lu","lv","luan","lue","lun","luo",
//		"ma","mai","man","mang","mao","me","mei","men","meng","mi","mian","miao","mie","min","ming","miu","mo","mou","mu",
//		"na","nai","nan","nang","nao","ne","nei","nen","neng","ni","nian","niang","niao","nie","nin","ning","niu","nong",
//		"nu","nv","nuan","nue","nuo","o","ou","pa","pai","pan","pang","pao","pei","pen","peng","pi","pian","piao","pie",
//		"pin","ping","po","pu","qi","qia","qian","qiang","qiao","qie","qin","qing","qiong","qiu","qu","quan","que","qun",
//		"ran","rang","rao","re","ren","reng","ri","rong","rou","ru","ruan","rui","run","ruo","sa","sai","san","sang",
//		"sao","se","sen","seng","sha","shai","shan","shang","shao","she","shen","sheng","shi","shou","shu","shua",
//		"shuai","shuan","shuang","shui","shun","shuo","si","song","sou","su","suan","sui","sun","suo","ta","tai",
//		"tan","tang","tao","te","teng","ti","tian","tiao","tie","ting","tong","tou","tu","tuan","tui","tun","tuo",
//		"wa","wai","wan","wang","wei","wen","weng","wo","wu","xi","xia","xian","xiang","xiao","xie","xin","xing",
//		"xiong","xiu","xu","xuan","xue","xun","ya","yan","yang","yao","ye","yi","yin","ying","yo","yong","you",
//		"yu","yuan","yue","yun","za","zai","zan","zang","zao","ze","zei","zen","zeng","zha","zhai","zhan","zhang",
//		"zhao","zhe","zhen","zheng","zhi","zhong","zhou","zhu","zhua","zhuai","zhuan","zhuang","zhui","zhun","zhuo",
//		"zi","zong","zou","zu","zuan","zui","zun","zuo"};
//
//	//if ( NULL == strChinese )
//	if ( strChinese.isEmpty() )
//	{
//		return NULL;
//	}
//
//	int chrasc = 0;        
//
//	char* strPinyin = NULL;
//
//	QByteArray ba = strChinese.toLocal8Bit();
//
//	int ChineseLen = ba.length();
//	char* TempChinese = new char[ChineseLen+1];
//	if ( NULL == TempChinese )
//	{
//		return NULL;
//	}
//
//	memset(TempChinese,0,ChineseLen+1);
//	TempChinese = (char*)ba.data();
//
//	//转换ANSI,字符部分不变，汉字转换成相应的拼音
//	char *returnstr = new char[6*ChineseLen +1];
//	memset(returnstr,0,6*ChineseLen +1);
//
//	int offset = 0;
//	for (int j = 0; j < ChineseLen;) // 循环处理字节数组
//	{
//		if (TempChinese[j] >= 0 && TempChinese[j] < 128) // 非汉字处理
//		{
//			returnstr[offset] = TempChinese[j];
//			offset++;
//			j++;
//			continue;
//		}
//
//		// 汉字处理
//		chrasc = TempChinese[j] * 256 + TempChinese[j+1]+256;
//
//		if (chrasc > 0 && chrasc < 160)
//		{
//			returnstr[offset]= TempChinese[j];
//			offset++;
//			j++;
//		}
//		else
//		{
//			for (int i = (sizeof(pyValue)/sizeof(pyValue[0]) - 1); i >= 0; i--)
//			{
//				if (pyValue[i] <= chrasc)
//				{
//					qstrcpy(returnstr+offset ,pyString[i]);
//					offset += strlen(pyString[i]);
//					break;
//				}
//			}
//			j +=2;
//		}
//	}
//	if(strlen(returnstr)>0)
//	{
//		strPinyin = new char[strlen(returnstr)+1];
//		if ( NULL == strPinyin )
//		{
//			return NULL;
//		}
//
//		memset(strPinyin,0,strlen(returnstr)+1);
//		qstrcpy(strPinyin,returnstr);
//	}
//	QString sResult(strPinyin);
//
//	qDebug()<<" ConvertChineseUnicodeToPyt: result: "<<sResult;
//	return sResult;
//}
//
//
//
//////时间转换, 获取当前时间到1970.1.1.00.00.00 的秒数 20130120 zhusizhi
//ulong CSystemSetting::dateTimeToSecond(const QDateTime &dateTime)
//{
//	qint64 int64 = dateTime.toMSecsSinceEpoch();
//	return (ulong) (int64/1000);
//}
//
///////将秒数（从1970.1.1.00.00.00）换成UTC日期时间，
///////输入参数
//QDateTime CSystemSetting::secondToDateTimeUTC(long long lSecond)
//{
//	QDateTime dateTimeUTC;
//	dateTimeUTC.setMSecsSinceEpoch(lSecond*1000);
//	return dateTimeUTC.toUTC();
//}
//
///////将秒数（从1970.1.1.00.00.00）换成Local日期时间，
///////输入参数
//QDateTime CSystemSetting::secondToDateTimeLocal(long lSecond)
//{
//	QDateTime datetimeUTC = secondToDateTimeUTC(lSecond);
//	QDateTime datetimeLocal(datetimeUTC.toLocalTime());
//	return datetimeLocal;
//}
//
//////strUTC 的格式如下：2010:10:01T12:32:4
//////中间带T的表示是UTC时间，其它的格式表示为本地时间 zhusizhi 20130121
//QDateTime CSystemSetting::stringToDateTimeUTC(const QString& strTime)
//{
//	if (!strTime.contains("T"))
//	{
//		QStringList sListTemp = strTime.split(" ");
//		QString sTemp1 = sListTemp.at(0);
//		QString sTemp2 = sListTemp.at(1);
//		//异常处理：日期和时间为空时，直接赋0
//		if (sTemp1.isEmpty() || sTemp2.isEmpty())
//		{
//			sTemp1 = QString("00-00-00");
//			sTemp2 = QString("00:00:00");
//		}
//		int iYYYY = 0;
//		int iMM = 0;
//		int iDD = 0;
//		if (sTemp1.contains("."))
//		{
//			QStringList sListDate = sTemp1.split(".");
//
//			iYYYY = sListDate.at(0).toInt();
//			iMM = sListDate.at(1).toInt();
//			iDD= sListDate.at(2).toInt();
//		} 
//		else if (sTemp1.contains("-"))
//		{
//			QStringList sListDate = sTemp1.split("-");
//
//			iYYYY = sListDate.at(0).toInt();
//			iMM = sListDate.at(1).toInt();
//			iDD= sListDate.at(2).toInt();
//		} 
//				
//		QStringList sListTime = sTemp2.split(":");
//		int iHH = sListTime.at(0).toInt();
//		int imm= sListTime.at(1).toInt();
//		int iSS= sListTime.at(2).toInt();
//
//		////此处为异常处理, 不带T时用本地时间
//		QDateTime timeLocal( QDate(iYYYY,iMM,iDD), QTime(iHH,imm,iSS), Qt::LocalTime);
//		return timeLocal;
//	}
//	else
//	{
//		QStringList sListTemp = strTime.split("T");
//		QString sTemp1 = sListTemp.at(0);
//		QString sTemp2 = sListTemp.at(1);
//		//异常处理：日期和时间为空时，直接赋0
//		if (sTemp1.isEmpty() || sTemp2.isEmpty())
//		{
//			sTemp1 = QString("00-00-00");
//			sTemp2 = QString("00:00:00");
//		}
//		int iYYYY = 0;
//		int iMM = 0;
//		int iDD = 0;
//		if (sTemp1.contains("."))
//		{
//			QStringList sListDate = sTemp1.split(".");
//
//			iYYYY = sListDate.at(0).toInt();
//			iMM = sListDate.at(1).toInt();
//			iDD= sListDate.at(2).toInt();
//		} 
//		else if (sTemp1.contains("-"))
//		{
//			QStringList sListDate = sTemp1.split("-");
//
//			iYYYY = sListDate.at(0).toInt();
//			iMM = sListDate.at(1).toInt();
//			iDD= sListDate.at(2).toInt();
//		} 
//
//		QStringList sListTime = sTemp2.split(":");
//		int iHH = sListTime.at(0).toInt();
//		int imm= sListTime.at(1).toInt();
//		int iSS= sListTime.at(2).toInt();
//
//		////此处为异常处理, 带T时用UTC时间
//		QDateTime timeUTC( QDate(iYYYY,iMM,iDD), QTime(iHH,imm,iSS), Qt::UTC );
//		return timeUTC;
//	}
//}
//
//int CSystemSetting::getSysTimeZone()
//{
//	return 24 - QDateTime(QDate(1970,1,2), QTime(0,0,0), Qt::LocalTime).toTime_t() / 3600;
//}
