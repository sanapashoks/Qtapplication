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
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
private:
    QColor mBackGroundColor;
    QColor mShapeColor;
};

#endif // RENDERAREA_H
