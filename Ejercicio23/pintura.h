#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include "ColorProperties.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Pintura; }
QT_END_NAMESPACE

class Pintura : public QWidget, public ColorProperties
{
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);
    ~Pintura();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::Pintura *ui;
    QList<QPoint> path;
};

#endif // PINTURA_H
