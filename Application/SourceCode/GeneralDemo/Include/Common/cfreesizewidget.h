/*******************************************************************************
*文件名称:  cfreesizewidget.h
*描    述:  提供根据控件大小按需要拉伸背景图的功能
*作    者:  
*创建日期:  
*当前版本:  
*版本历史: 
*          
*注    释:  将背景图按九宫格切片, 改变控件大小时, 四角的图片不变, 其余五个部分则平铺或拉伸
*
*******************************************************************************/
#ifndef CFREESIZEWIDGET_H
#define CFREESIZEWIDGET_H

/**********************************头文件***************************************/
#include <QtWidgets/QWidget>
#include <QPainter>

/**********************************类声明***************************************/
class CFreeSizeWidget : public QWidget
{
    Q_OBJECT

public:
    CFreeSizeWidget(QWidget *parent = 0);
    ~CFreeSizeWidget();

    void setConerWidthHeight(int widthLeft, int widthRight,
                             int heightTop, int heightBottom);//设置四角的范围
    void setPixmap(const QPixmap &pixmap);                    //设置背景图片
    void setFillMode(int mode);                               //设置填充模式
    void setMinimumWidth(int minw);
    void setMinimumHeight(int minh);
    void setMinimumSize(int minw, int minh);
    void setMinimumSize(const QSize &);

protected:
    //创建拉伸所需要的切片
    void createEdgePixmap(const QPixmap &background, QPixmap &edgeTop
                          , QPixmap &edgeBottom, QPixmap &edgeLeft
                          , QPixmap &edgeRight, QPixmap &padding);

    //绘制背景图片
    void drawBufferPixmap(const QPixmap &background, const QPixmap &edgeTop
                          , const QPixmap &edgeBottom, const QPixmap &edgeLeft
                          , const QPixmap &edgeRight, const QPixmap &padding
                          , QPixmap &buffer, int fillMode = 1);
    void paintEvent(QPaintEvent *event);

//private:
protected:
    QPixmap m_buffer;           //最终背景图片

    QPixmap m_backgroundImage;  //原始背景图
    QPixmap m_edgeTopImage;     //顶边图片
    QPixmap m_edgeBottomImage;  //底边图片
    QPixmap m_edgeLeftImage;    //左边图片
    QPixmap m_edgeRightImage;   //右边图片
    QPixmap m_paddingImage;     //中间区域图片

    bool m_isRefresh;           //是否已刷新


    int m_conerSize[4];         //四角的大小
    int m_FillMode;             //填充模式

    int m_minimumWidth;
    int m_minimumHeight;
};

#endif // CFREESIZEWIDGET_H
