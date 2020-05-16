#ifndef COLORITEM_H
#define COLORITEM_H

#include <QGraphicsItem>
#include <QGraphicsSceneDragDropEvent>
#include <QApplication>

//! [0]
class ColorItem : public QGraphicsItem
{
public:
    ColorItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QColor color;
};
//! [0]

#endif
