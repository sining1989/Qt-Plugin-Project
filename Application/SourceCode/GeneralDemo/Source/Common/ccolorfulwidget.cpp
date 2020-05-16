/******************************************************************************
*文件名称:  ccolorfulwidget.cpp
*描    述:  提供换肤功能的基类, 在编写需要换肤功能的控件时, 继承此类, 代替QWidget使用.
*作    者: 
*创建日期:  
*当前版本:  
*版本历史:  
*
*注    释:
*
*******************************************************************************/

/***********************************头文件*************************************/
#include "ccolorfulwidget.h"
#include <QPainter>
#include <QDebug>
QList<QWidget*>* CColorfulWidget::mp_widgets = NULL;

/*******************************************************************************
* 函  数: CColorfulWidget::changeAllSkin()
*
* 描  述: 通知所有需要换肤的界面切换皮肤
*
* 参  数: 无
*
* 返回值: 无
*
* 注  释:
*
*******************************************************************************/
void CColorfulWidget::changeAllSkin()
{
    if(NULL != mp_widgets)
    {
        int l_type = 0;
        QVariant l_value;
        CSystemSetting::getInstance()->getSkinConfig(l_type, l_value);

        int count = mp_widgets->size();
        for(int i = 0; i < count; i++)
        {
            CColorfulWidget* p = static_cast<CColorfulWidget*>(mp_widgets->at(i));
            if(NULL != p)
            {
                p->setSkin(l_type, l_value);
            }
        }
    }
}

/******************************************************************************
* 函  数: CColorfulWidget::CColorfulWidget(QWidget *parent)
*
* 描  述: 构造函数
*
* 参  数: 输入:
*           QWidget *parent 父指针
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
CColorfulWidget::CColorfulWidget(QWidget *parent) :
        CFreeSizeWidget(parent)
        , m_isRefresh(true)
        , m_timeLine(NULL)
        , m_opacity(1)
{
    if(NULL == mp_widgets)
    {
        mp_widgets = new QList<QWidget*>();
    }
    mp_widgets->append(this);

    m_BGType = (BG_TYPE)CSystemSetting::getInstance()->skinType;
    m_backgroundColor = CSystemSetting::getInstance()->skinColor;
    m_backgroundPixmap = QPixmap(CSystemSetting::getInstance()->SkinPixmap);

    if (m_BGType == PIXMAP)
    {
        if (m_backgroundPixmap.isNull())
        {
            m_BGType = EMPTY;
        }
    }
    m_timeLine = new QTimeLine(800,this);   //时间控制
    m_timeLine->setUpdateInterval(100);
    m_timeLine->setEasingCurve(QEasingCurve::OutQuart);
    connect(m_timeLine,SIGNAL(valueChanged(qreal)),SLOT(animation(qreal)));
    connect(m_timeLine,SIGNAL(finished()),SLOT(slotFinished()));
}

/******************************************************************************
* 函  数: CColorfulWidget::~CColorfulWidget()
*
* 描  述: 析构函数
*
* 参  数: 无
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
CColorfulWidget::~CColorfulWidget()
{
    if (NULL != mp_widgets)
    {
//        qDebug() << "SIZE 2: " << mp_widgets->size();
        mp_widgets->removeOne(this);

        if(0 == mp_widgets->size())
        {
            delete mp_widgets;
            mp_widgets = NULL;
        }
    }
}

/******************************************************************************
* 函  数: CColorfulWidget::setSkin(int type, const QVariant &value)
*
* 描  述: 设置皮肤
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
void CColorfulWidget::setSkin(int type, const QVariant &value)
{
    if (type == COLOR)
    {
        setBackGroundColor(QColor(value.toString()));
    }
    else if (type == PIXMAP)
    {
        setBackGroundImage(QPixmap(value.toString()));
    }
    else if (type == EMPTY)
    {
        setBackGroundType(EMPTY);
    }
    if(m_timeLine->state() == QTimeLine::Running)
       m_timeLine->stop();

    m_timeLine->start();
}

void CColorfulWidget::animation(qreal value)
{
    m_opacity = value;
    repaint();
}

void CColorfulWidget::slotFinished()
{
    m_timeLine->stop();
}

void CColorfulWidget::setSkinBG(const QPixmap &pix)
{
    m_backgroundSkinMode = pix;

    if (m_BGType != EMPTY)
    {
        CFreeSizeWidget::setPixmap(m_backgroundSkinMode);
    }
}

/******************************************************************************
* 函  数: CColorfulWidget::setBackGroundColor(const QColor color)
*
* 描  述: 设置皮肤颜色
*
* 参  数: 输入:
*         const QColor color 背景色
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CColorfulWidget::setBackGroundColor(const QColor color)
{
    m_backgroundColor = color;
    setBackGroundType(COLOR);
}

/******************************************************************************
* 函  数: CColorfulWidget::setBackGroundImage(const QPixmap &pix)
*
* 描  述: 设置皮肤图片
*
* 参  数: 输入:
*         const QPixmap &pix 背景图片
*
* 返回值: 无
*
* 注  释:
*
******************************************************************************/
void CColorfulWidget::setBackGroundImage(const QPixmap &pix)
{
    if (pix.isNull())
    {
        return;
    }

    m_backgroundPixmap = pix;
    setBackGroundType(PIXMAP);
}

/******************************************************************************
* 函  数: CColorfulWidget::setBackGroundType(int type)
*
* 描  述: 切换当前背景模式, 单色或者图片, 如果不需要, 也可输入其他值, 即可设置为无背景模式
*
* 参  数: 输入:
*         int type 背景类型
*
* 返回值: 无
*
* 注  释: 输入参数含义: 0: 颜色模式; 1: 图片模式; -1: 无背景模式, 等同于QWidget
*
******************************************************************************/
void CColorfulWidget::setBackGroundType(int type)
{
    if (type != m_BGType)
    {
        if (type == EMPTY)
        {
            CFreeSizeWidget::setPixmap(m_backgroundOriginally);
        }
        else
        {
            CFreeSizeWidget::setPixmap(m_backgroundSkinMode);
        }
    }

    switch (type)
    {
        case COLOR:
        case PIXMAP:
        {
            m_BGType = (BG_TYPE)type;
            break;
        }

        default:
        {
            m_BGType = EMPTY;
            break;
        }
    }

    m_isRefresh = true;
    //update();
}

/*******************************************************************************
* 函  数: CColorfulWidget::setConerWidthHeight(int widthLeft, int widthRight,
*                                             int heightTop, int heightBottom)
*
* 描  述: 设置四角的范围
*
* 参  数: 输入:
*            int widthLeft          左边宽
*            int widthRight         右边宽
*            int heightTop          顶边高
*            int heightBottom       底边高
*
* 返回值: 无
*
* 注  释:
*
*******************************************************************************/
void CColorfulWidget::setConerWidthHeight(int widthLeft, int widthRight,
                                          int heightTop, int heightBottom)
{
    CFreeSizeWidget::setConerWidthHeight(widthLeft, widthRight,
                                         heightTop, heightBottom);

    createEdgePixmap(m_backgroundOriginally, m_edgeTopImage
                     , m_edgeBottomImage, m_edgeLeftImage
                     , m_edgeRightImage, m_paddingImage);
}

/*******************************************************************************
* 函  数: CColorfulWidget::setPixmap(const QPixmap &pixmap)
*
* 描  述: 设置背景图片
*
* 参  数: 输入:
*           const QPixmap &pixmap 背景图片
*
* 返回值: 无
*
* 注  释:
*
*******************************************************************************/
void CColorfulWidget::setPixmap(const QPixmap &pixmap)
{
    m_backgroundOriginally = pixmap;

    if (m_BGType == EMPTY)
    {
        CFreeSizeWidget::setPixmap(m_backgroundOriginally);
    }

//    QImage l_tmpImage = m_backgroundOriginally.toImage();
//    l_tmpImage = l_tmpImage.createAlphaMask()
//                        .convertToFormat(QImage::Format_ARGB32_Premultiplied);

//    l_tmpImage.invertPixels(QImage::InvertRgb);
//    l_tmpImage.setAlphaChannel(l_tmpImage);

//    m_maskPixmap = QPixmap::fromImage(l_tmpImage);
    m_maskPixmap = m_backgroundOriginally;

    createEdgePixmap(m_maskPixmap, m_edgeTopImage
                     , m_edgeBottomImage, m_edgeLeftImage
                     , m_edgeRightImage, m_paddingImage);
}

/******************************************************************************
* 函  数: CColorfulWidget::paintEvent(QPaintEvent *event)
*
* 描  述: 绘制事件
*
* 参  数: 输入:
*           QPaintEvent *event
*
* 返回值: 无
*
* 注  释: 继承此类后, 如果需要重载paintEvent, 务必在重载时先执行该类的paintEvent.
*
*
******************************************************************************/
void CColorfulWidget::paintEvent(QPaintEvent *event)
{
    if (m_BGType != EMPTY)
    {
        QPainter l_painter(this);
        l_painter.setOpacity(m_opacity);
        //大小变化后, 重新生成背景
        if (m_buffer.size() != size() || m_isRefresh == true)
        {
            //初始化背景
            m_buffer = QPixmap(this->size());
            m_buffer.fill(Qt::transparent);

            //填充区域蒙版
            drawBufferPixmap(m_maskPixmap, m_edgeTopImage
                             , m_edgeBottomImage, m_edgeLeftImage
                             , m_edgeRightImage, m_paddingImage
                             , m_buffer);

            //设置渲染模式
            QPainter l_tmpPainter(&m_buffer);
            l_tmpPainter.setRenderHint(QPainter::Antialiasing);
            l_tmpPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);

            switch (m_BGType)
            {
                case COLOR: //颜色模式, 填充纯色
                    l_tmpPainter.fillRect(m_buffer.rect(), m_backgroundColor);
                    break;

                case PIXMAP: //图片模式, 绘制图片, 填充模式为平铺
                    l_tmpPainter.drawTiledPixmap(m_buffer.rect(), m_backgroundPixmap);
                    break;

                default:
                    QWidget::paintEvent(event);
                    break;
            }
            m_isRefresh = false;
        }
        //绘制背景
        l_painter.drawPixmap(0, 0, m_buffer);
    }
        CFreeSizeWidget::paintEvent(event);
}
void CColorfulWidget::showEvent(QShowEvent *e)
{
    scroll(1,0);
    scroll(-1,0);
    CFreeSizeWidget::showEvent(e);
}
