#include "renderarea.h"
#include<QPaintEvent>
#include<QPainter>
#include<math.h>
renderArea::renderArea(QWidget *parent) :
    QWidget(parent), mBackGroundColor(0,0,255),
    mShapeColor(255,255,255),
    mShape(Astroid)
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
QPointF renderArea::compute_astroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF (x, y);
}
void renderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);


    switch(mShape)
    {
    case Astroid:
        mBackGroundColor=Qt::red;
        break;

    case Cycloid:
        mBackGroundColor=Qt::green;
        break;

    case HugensCycloid:
        mBackGroundColor=Qt::blue;
        break;

    case HypoCycloid:
        mBackGroundColor=Qt::yellow;
        break;

    default:
        break;
    }

    painter.setBrush(mBackGroundColor);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(mShapeColor);
    // Drawing Area
    painter.drawRect(this->rect());
    QPoint center = this->rect().center();
    int stepcount =256;
    float scale = 40;
    float intervallength = 2* M_PI;
    float step = intervallength/stepcount;
    for(float t=0; t< intervallength; t+=step)
    {
        QPointF point = compute_astroid(t);

        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());

        painter.drawPoint(pixel);
    }

}
