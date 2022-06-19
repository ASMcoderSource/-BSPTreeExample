#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QPainter>
#include "Line.h"

class Widget : public QWidget{
    Q_OBJECT

    QVector<Line> lines;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent* e) override;
    QPoint transformToDisplay(Point p);
};
#endif // WIDGET_H
