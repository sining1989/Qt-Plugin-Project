/*******************************************************************************
*文件名称:  cfreesizewidget.cpp
*描    述:  提供根据控件大小按需要拉伸背景图的功能
*作    者:  
*创建日期:  
*当前版本:  
*版本历史:  
*
*注    释:  将背景图按九宫格切片, 改变控件大小时, 四角的图片不变, 其余五个部分则平铺或拉伸
*
*******************************************************************************/

/***********************************头文件**************************************/
#include "cfreesizewidget.h"
#include <QDebug>

const int DRAW_TILED_MODE = 0;          //平铺模式
const int DRAW_STRETCHED_MODE = 1;      //拉伸模式

/*******************************************************************************
* 函  数: CFreeSizeWidget::CFreeSizeWidget(QWidget *parent)
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
*******************************************************************************/
CFreeSizeWidget::CFreeSizeWidget(QWidget *parent) :
    QWidget(parent)
    , m_FillMode(DRAW_STRETCHED_MODE)
    , m_isRefresh(true)
    , m_minimumWidth(0)
    , m_minimumHeight(0)
{
    m_conerSize[0] = 0;
    m_conerSize[1] = 0;
    m_conerSize[2] = 0;
    m_conerSize[3] = 0;
}

/*******************************************************************************
* 函  数: CFreeSizeWidget::~CFreeSizeWidget()
*
* 描  述: 析构函数
*
* 参  数: 无
*
* 返回值: 无
*
* 注  释:
*
*******************************************************************************/
CFreeSizeWidget::~CFreeSizeWidget()
{

}

/*******************************************************************************
* 函  数: CFreeSizeWidget::setConerWidthHeight(int widthLeft, int widthRight,
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
void CFreeSizeWidget::setConerWidthHeight(int widthLeft, int widthRight,
                                          int heightTop, int heightBottom)
{
    m_conerSize[0] = widthLeft;
    m_conerSize[1] = widthRight;
    m_conerSize[2] = heightTop;
    m_conerSize[3] = heightBottom;

    createEdgePixmap(m_backgroundImage, m_edgeTopImage
                     , m_edgeBottomImage, m_edgeLeftImage
                     , m_edgeRightImage, m_paddingImage);

    m_minimumWidth = m_conerSize[0] + m_conerSize[1];
    m_minimumHeight = m_conerSize[2] + m_conerSize[3];

    this->setMinimumWidth(m_minimumWidth);
    this->setMinimumHeight(m_minimumHeight);
}

/*******************************************************************************
* 函  数: CFreeSizeWidget::setPixmap(const QPixmap &pixmap)
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
void CFreeSizeWidget::setPixmap(const QPixmap &pixmap)
{
    //    if (小于coner的大小)
    //    {
    //        //...
    //    }
    m_backgroundImage = pixmap;

    if (m_conerSize[0] == 0 && m_conerSize[1] == 0 &&
        m_conerSize[2] == 0 && m_conerSize[3] == 0)
    {
        m_conerSize[0] = m_backgroundImage.width() / 2;
        m_conerSize[1] = m_backgroundImage.width() / 2;
        m_conerSize[2] = m_backgroundImage.height() / 2;
        m_conerSize[3] = m_backgroundImage.height() / 2;
    }

    createEdgePixmap(m_backgroundImage, m_edgeTopImage
                     , m_edgeBottomImage, m_edgeLeftImage
                     , m_edgeRightImage, m_paddingImage);

    m_isRefresh = true;
    update();
}

/*******************************************************************************
* 函  数: CFreeSizeWidget::setFillMode(int mode)
*
* 描  述: 设置填充模式
*
* 参  数: 输入:
*           int mode 填充模式
*
* 返回值: 无
*
* 注  释: mode含义: 0: 平铺; 1: 拉伸
*
******************************************************************************/
void CFreeSizeWidget::setFillMode(int mode)
{
    m_FillMode = mode;

    m_isRefresh = true;
    update();
}

void CFreeSizeWidget::setMinimumWidth(int minw)
{
    if (minw > m_minimumWidth)
    {
        QWidget::setMinimumWidth(minw);
    }
}

void CFreeSizeWidget::setMinimumHeight(int minh)
{
    if (minh > m_minimumHeight)
    {
        QWidget::setMinimumHeight(minh);
    }
}

void CFreeSizeWidget::setMinimumSize(int minw, int minh)
{
    int l_minw = minw;
    int l_minh = minh;

    if (m_minimumWidth < minw)
    {
        l_minw = m_minimumWidth;
    }

    if (m_minimumHeight < minh)
    {
        l_minh = m_minimumHeight;
    }

    QWidget::setMinimumSize(l_minw, l_minh);
}

void CFreeSizeWidget::setMinimumSize(const QSize &size)
{
    QSize l_size(size);

    if (m_minimumWidth < size.width())
    {
        l_size.setWidth(m_minimumWidth);
    }

    if (m_minimumHeight < size.height())
    {
        l_size.setHeight(m_minimumHeight);
    }

    QWidget::setMinimumSize(l_size);
}


/*******************************************************************************
* 函  数: CFreeSizeWidget::createEdgePixmap()
*
* 描  述: 创建拉伸所需要的切片
*
* 参  数: 输入: 无
*
* 返回值: 无
*
* 注  释:
*
*******************************************************************************/
void CFreeSizeWidget::createEdgePixmap(const QPixmap &background, QPixmap &edgeTop
                                       , QPixmap &edgeBottom, QPixmap &edgeLeft
                                       , QPixmap &edgeRight, QPixmap &padding)
{
    //顶边范围
    QRect l_edgeTopRect(m_conerSize[0], 0, background.width()
            - (m_conerSize[0] + m_conerSize[1]), m_conerSize[2]);

    //底边范围
    QRect l_edgeBottomRect(m_conerSize[0], background.height()
            - m_conerSize[3], background.width() - (m_conerSize[0]
            + m_conerSize[1]), m_conerSize[3]);

    //左边范围
    QRect l_edgeLeftRect(0, m_conerSize[2], m_conerSize[0],
            background.height() - (m_conerSize[2] + m_conerSize[3]));

    //右边范围
    QRect l_edgeRightRect(background.width() - m_conerSize[1],
            m_conerSize[2], m_conerSize[1], background.height()
                    - (m_conerSize[2] + m_conerSize[3]));

    //中间区域范围
    QRect l_paddingRect(m_conerSize[0], m_conerSize[2],
            background.width() - (m_conerSize[0] + m_conerSize[1]),
            background.height() - (m_conerSize[2] + m_conerSize[3]));

    edgeTop = background.copy(l_edgeTopRect);
    edgeBottom = background.copy(l_edgeBottomRect);
    edgeLeft = background.copy(l_edgeLeftRect);
    edgeRight = background.copy(l_edgeRightRect);
    padding = background.copy(l_paddingRect);
}

/*******************************************************************************
* 函  数: CFreeSizeWidget::drawBufferPixmap(const QPixmap &background
*                                          , const QPixmap &edgeTop
*                                          , const QPixmap &edgeBottom
*                                          , const QPixmap &edgeLeft
*                                          , const QPixmap &edgeRight
*                                          , const QPixmap &padding
*                                          , QPixmap &buffer
*                                          , int fillMode)
*
* 描  述: 创建拉伸所需要的切片
*
* 参  数: 输入:
*           const QPixmap &background       原始背景图片
*           const QPixmap &edgeTop          顶边图片
*           const QPixmap &edgeBottom       底边图片
*           const QPixmap &edgeLeft         左边图片
*           const QPixmap &edgeRight        右边图片
*           const QPixmap &padding          中间区域图片
*           QPixmap &buffer                 最终背景图片
*           int fillMode                    填充模式
*
* 返回值: 无
*
* 注  释:
*
*******************************************************************************/
void CFreeSizeWidget::drawBufferPixmap(const QPixmap &background
                                       , const QPixmap &edgeTop
                                       , const QPixmap &edgeBottom
                                       , const QPixmap &edgeLeft
                                       , const QPixmap &edgeRight
                                       , const QPixmap &padding
                                       , QPixmap &buffer, int fillMode)
{
    QPainter l_painter(&buffer);

    l_painter.setRenderHint(QPainter::SmoothPixmapTransform);

    //绘制四角
    //top left coner
    l_painter.drawPixmap(0, 0, m_conerSize[0], m_conerSize[2],
            background, 0, 0, m_conerSize[0], m_conerSize[2]);
    //top right coner
    l_painter.drawPixmap(width() - m_conerSize[1], 0, m_conerSize[1],
            m_conerSize[2], background, background.width()
                    - m_conerSize[1], 0, m_conerSize[1], m_conerSize[2]);
    //bottom left coner
    l_painter.drawPixmap(0, height() - m_conerSize[3], m_conerSize[0],
            m_conerSize[3], background, 0, background.height()
                    - m_conerSize[3], m_conerSize[0], m_conerSize[3]);
    //bottom right coner
    l_painter.drawPixmap(width() - m_conerSize[1], height() - m_conerSize[3],
            m_conerSize[1], m_conerSize[3], background,
            background.width() - m_conerSize[1],
            background.height() - m_conerSize[3], m_conerSize[1],
            m_conerSize[3]);

    //绘制四边和中间区域
    QRect l_edgeTopRect(m_conerSize[0], 0, buffer.width() - (m_conerSize[0]
            + m_conerSize[1]), m_conerSize[2]);

    QRect l_edgeBottomRect(m_conerSize[0], buffer.height() - m_conerSize[3],
            buffer.width() - (m_conerSize[0] + m_conerSize[1]), m_conerSize[3]);

    QRect l_edgeLeftRect(0, m_conerSize[2], m_conerSize[0], buffer.height()
            - (m_conerSize[2] + m_conerSize[3]));

    QRect l_edgeRightRect(buffer.width() - m_conerSize[1], m_conerSize[2],
            m_conerSize[1], buffer.height() - (m_conerSize[2] + m_conerSize[3]));

    QRect l_paddingRect(m_conerSize[0], m_conerSize[2], buffer.width()
            - (m_conerSize[0] + m_conerSize[1]), buffer.height()
            - (m_conerSize[2] + m_conerSize[3]));


    if (fillMode == DRAW_TILED_MODE) //平铺模式绘制
    {
        l_painter.drawTiledPixmap(l_edgeTopRect, edgeTop);
        l_painter.drawTiledPixmap(l_edgeBottomRect, edgeBottom);
        l_painter.drawTiledPixmap(l_edgeLeftRect, edgeLeft);
        l_painter.drawTiledPixmap(l_edgeRightRect, edgeRight);
        l_painter.drawTiledPixmap(l_paddingRect, padding);
    }
    else //拉伸模式
    {
        l_painter.drawPixmap(l_edgeTopRect, edgeTop);
        l_painter.drawPixmap(l_edgeBottomRect, edgeBottom);
        l_painter.drawPixmap(l_edgeLeftRect, edgeLeft);
        l_painter.drawPixmap(l_edgeRightRect, edgeRight);
        l_painter.drawPixmap(l_paddingRect, padding);
    }

}

void CFreeSizeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter l_painter(this);

    if (m_buffer.size() != size() || m_isRefresh == true)
    {
        m_isRefresh = false;
        m_buffer = QPixmap(this->size());
        m_buffer.fill(Qt::transparent);
        drawBufferPixmap(m_backgroundImage, m_edgeTopImage
                         , m_edgeBottomImage, m_edgeLeftImage
                         , m_edgeRightImage, m_paddingImage
                         , m_buffer, m_FillMode);
    }

    l_painter.drawPixmap(0, 0, m_buffer);
}
