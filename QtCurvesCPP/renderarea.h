#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class renderArea : public QWidget
{
    Q_OBJECT
public:
    explicit renderArea(QWidget *parent = nullptr);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    enum Shape_Type {Astroid, Cycloid, HugensCycloid, HypoCycloid};

    void setBackgroundColor(QColor color) {mBackGroundColor = color;}
    QColor getBackgroundColor(void)const {return mBackGroundColor;}

    void setShape (Shape_Type shape) {mShape = shape;}
    Shape_Type getShape(void) {return mShape;}
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
private:
    QPointF compute_astroid(float t);
private:
    QColor mBackGroundColor;
    QColor mShapeColor;
    Shape_Type mShape;

};

#endif // RENDERAREA_H
