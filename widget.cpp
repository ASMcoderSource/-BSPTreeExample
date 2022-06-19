#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent){
    lines.append(Line({-100,-100}, {500,100}));
    lines.append(Line({-200,-100}, {500,-50}));
    lines.append(Line({-200,200}, {500,-150}));
}

Widget::~Widget(){
}

void Widget::paintEvent(QPaintEvent* e){
    QPainter paint(this);
    paint.setBrush(QColor(37, 46, 59));
    paint.drawRect(0,0, width(), height());
    QPen pen;
    pen.setColor(QColor(183, 191, 201));
    pen.setWidthF(1.5);
    paint.setPen(pen);
    for( auto line : lines ){
        paint.drawLine(transformToDisplay(line.A), transformToDisplay(line.B));
        pen.setColor(QColor(183, 191, 201));
        pen.setWidthF(1.5);
        paint.setPen(pen);
        paint.setBrush(QColor(255, 113, 0));
        paint.drawEllipse(transformToDisplay(line.A), 3, 3);
        paint.drawEllipse(transformToDisplay(line.B), 3, 3);

    }

    for( auto& a: lines ){
    for( auto& b: lines ){
        if( &a == &b )
            continue;
        auto point = a.intersectionPoint(b);
        if( !a.isPointInsideSegment(point) )
            continue;
        paint.setBrush(QColor(255, 0, 47));
        paint.drawEllipse(transformToDisplay(point), 3, 3);
    }
    }
}


QPoint Widget::transformToDisplay(Point p){
    QPoint window_point;
    window_point.rx() = p.x + width() / 2.0;
    window_point.ry() = -p.y + height() / 2.0;
    return window_point;
}
