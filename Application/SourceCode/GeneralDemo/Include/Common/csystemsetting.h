/******************************************************************************
*文件名称:  csystemsetting.h
*描    述:  设置管理
*作    者:  
*创建日期:  
*当前版本:  
*版本历史:
*注    释:  设置全局管理类，对设置进行读取跟修改操作。
*
*******************************************************************************/
#ifndef CSYSTEMSETTING_H
#define CSYSTEMSETTING_H

/***********************************头文件*************************************/
#include <QString>
#include <QVariant>
#include <QColor>
#include <QObject>
#include <QRect>
#include <QTranslator>
#include <QDateTime>

/***********************************类声明*************************************/
class CSystemSetting : public QObject
{
    Q_OBJECT

// pugang:录制文件类型
public:
    enum RECORD_FILE_TYPE{
        RECORD_FILE_PCM = 0, //pcm
        RECORD_FILE_WAV, //wav
        RECORD_FILE_3GP // 3gp
    };
    //同步方式
    enum SYNC_TYPE
    {
        SYNC_SLOW, //慢同步（下载网络地址薄到本地）
        SYNC_REFRESH, //刷新同步
        SYNC_TWO_WAY //双向同步
    };
    //同步频率
    enum SYNC_FREQUENCY
    {
        SYNC_NEVER, //不同步
        SYNC_ONCE,//只同步一次（没有用了）
        SYNC_REPEAT,//重复同步（没有用了）
        SYNC_DO//要同步
    };

    //同步时间间隔
    enum SYNC_INTERVAL
    {
        ONE_DAY,
        ONE_WEEK,
        ONE_MONTH
    };

    static CSystemSetting* getInstance(QObject *parent = 0); //取得类的单例实例
    ~CSystemSetting();
    static void setSettingInstance(CSystemSetting* pointer);

    //void initDefaultStoragePosition(const QString &);

    void installAppLanguage(const QString &languageName = "");//设置程序语言
    const QStringList getLanguageList();                      //获取当前支持的语言列表
    const QString getCurrentLanguage();
    void writeSetting(bool);
    const bool readSetting();
    void initSettingInfo(const QString &fileName); // 初始化设置信息
    void resetSettingInfo(const QString &fileName); // 重新加载设置信息

	// 设置配置文件中配置项的内容
	void setValueToFile(const QString &key, const QVariant &value);
	QString GetConfigFileValue();
	QVariant getValueFromFile(const QString &key, const QVariant &defaultValue = QVariant());
	void createSettingFile(const QString &fileName); // 创建默认设置文件
    // 开机自动运行设置
    bool setAutoRun(bool enable, bool curUserOnly);
    bool isAutoRun(bool curUserOnly);

    void setSkinConfig(int type, const QVariant &value);        //设置皮肤参数
    void getSkinConfig(int &type, QVariant &value);             //获得皮肤参数
    void setRectOfMainWidget(const QRect &);                    //设置主界面的区域
    QRect getRectOfMainWidget();                                //读取主界面的区域
	void ReadConfigureInfo();

public:
    //皮肤
    enum SkinType{
        DefaultType = -1,
        ColorType,
        PixmapType
    };

    int skinType;
    QColor skinColor;
    QString SkinPixmap;
    QString skinCustom1;
    QString skinCustom2;
	QString defaultStoragePosition; // 默认存储位置
	QMap<QString, QString> m_languageMap;
  
signals:
    void signalUpdateSetting(QString key);
    
    void signalChangeLanguage(const QString & strLanguage ); //语言切换
    
private:
    explicit CSystemSetting(QObject *parent = 0);
    static CSystemSetting *m_instance;
	void initParameters();
    QString m_fileName; // 设置文件
    QTranslator *mp_currentLang; //当前语言, 用于切换语言时移除上次的语言
    QTranslator *mp_currentQtLang; //当前语言, 用于切换语言时移除上次的语言
    QString m_lastPath;//打开文件选择框的默认路径(根目录)
   

};

#endif // CSYSTEMSETTING_H
