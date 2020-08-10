#include "renderarea.h"
#include<QPaintEvent>
#include<QPainter>
renderArea::renderArea(QWidget *parent) :
    QWidget(parent), mBackGroundColor(0,0,255), mShapeColor(255,255,255)
{

}

QSize renderArea::sizeHint() const
{
    return QSize(400, 200);
}

QSize renderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

void renderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(mBackGroundColor);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(mShapeColor);
    // Drawing Area
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(),this->rect().bottomRight());
}
