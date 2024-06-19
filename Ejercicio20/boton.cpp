#include "boton.h"
#include "ui_boton.h"

#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Boton), currentColor(Blanco)
{
    ui->setupUi(this);
}

Boton::~Boton()
{
    delete ui;
}

void Boton::colorear(Boton::Color colorCode)
{
    currentColor = colorCode;
    update(); // Forzar una actualización de la apariencia
}

void Boton::setTexto(QString texto)
{
    ui->lTexto->setText( texto );
}

void Boton::paintEvent(QPaintEvent *)
{
    QColor color;
    // Aquí asignamos el color basado en el valor de currentColor
    switch (currentColor) {
    case Azul:
        color = QColor(120, 121,211,128); // Azul
        break;
    case Verde:
        color = QColor(122, 223, 95,128); // Verde
        break;
    case Magenta:
        color = QColor(222, 41, 140,128); // Magenta
        break;
    case Violeta:
        color = QColor(220, 32, 239,128); // Violeta
        break;
    default:
        color = QColor(255, 255, 255,128); // Blanco (color por defecto)
    }

    QPainter painter(this);
    painter.fillRect(rect(), color);
    //painter.drawImage("C:/Users/Alexis/Desktop/FACU/TERCER-AÑO/POO/Ej20/Fondo.jpg");
}

void Boton::mousePressEvent(QMouseEvent *)
{
    emit signal_clic();
}
