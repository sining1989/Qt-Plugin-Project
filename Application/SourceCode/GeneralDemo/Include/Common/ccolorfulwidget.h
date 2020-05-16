/*******************************************************************************
*文件名称:  ccolorfulwidget.h
*描    述:  提供换肤功能的基类, 在编写需要换肤功能的控件时, 继承此类, 代替QWidget使用.
*作    者:  
*创建日期:  
*当前版本:  
*版本历史:  
*
*注    释:
*
*******************************************************************************/
#ifndef CCOLORFULWIDGET_H
#define CCOLORFULWIDGET_H

/**********************************头文件***************************************/
#include <QtWidgets/QWidget>
#include <QVariant>
#include <QList>
#include <QTimeLine>
#include "csystemsetting.h"
#include "cfreesizewidget.h"

/**********************************类声明***************************************/
class CColorfulWidget : public CFreeSizeWidget
{
    Q_OBJECT

public:
    CColorfulWidget(QWidget *parent = 0);
    virtual ~CColorfulWidget();

    virtual void setSkin(int type, const QVariant &value);  //设置皮肤
    virtual void setSkinBG(const QPixmap &pix);
    virtual void setBackGroundColor(const QColor color);    //设置皮肤颜色
    virtual void setBackGroundImage(const QPixmap &pix);    //设置皮肤图片
    virtual void setBackGroundType(int type);               //设置当前背景类型(单色或者图片)

    virtual void setConerWidthHeight(int widthLeft, int widthRight,
                             int heightTop, int heightBottom);//设置四角的范围
    virtual void setPixmap(const QPixmap &pixmap);                    //设置背景图片

protected:
    void paintEvent(QPaintEvent *event);        //绘制事件

public:
    enum BG_TYPE{EMPTY = -1, COLOR, PIXMAP};

protected:
    void showEvent(QShowEvent *);
    QPixmap m_maskPixmap;           //区域蒙版图片
    QPixmap m_buffer;               //换肤图片

    QPixmap m_edgeTopImage;         //顶边图片
    QPixmap m_edgeBottomImage;      //底边图片
    QPixmap m_edgeLeftImage;        //左边图片
    QPixmap m_edgeRightImage;       //右边图片
    QPixmap m_paddingImage;         //中间区域图片

    BG_TYPE m_BGType;               //背景类型(颜色, 图片, 默认为无背景)
    QColor m_backgroundColor;       //背景色颜色值
    QPixmap m_backgroundPixmap;     //背景图片
    QPixmap m_backgroundOriginally; //大背景图
    QPixmap m_backgroundSkinMode;
    bool m_isRefresh;               //是否已刷新

public:
    static void changeAllSkin();

private slots:
    void animation(qreal);
    void slotFinished();
private:
    static QList<QWidget*>  *mp_widgets;
    QTimeLine *m_timeLine;
    qreal m_opacity;
};

#endif // CCOLORFULWIDGET_H
