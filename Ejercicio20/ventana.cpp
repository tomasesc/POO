#include "ventana.h"
#include "ui_ventana.h"
#include <QFont>



Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://freshprompts-blog-images.s3.amazonaws.com/background-drawing-ideas/color.jpg"));
    manager->get(request);

    ui->boton_salir->setTexto( "Salir" );
    ui->boton_salir->colorear(Boton::Blanco);

    ui->boton1->setTexto("Mi dentista");
    ui->boton1->colorear(Boton::Magenta);

    ui->boton2->setTexto("Visitas");
    ui->boton2->colorear(Boton::Violeta);

    ui->boton3->setTexto("Tecnicas de higiene");
    ui->boton3->colorear(Boton::Azul);

    ui->boton4->setTexto("Mi boca");
    ui->boton4->colorear(Boton::Verde);


   


    connect(ui->boton_salir, SIGNAL(signal_clic()), this, SLOT(close()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
     this->repaint();
     this->show();

}

void Ventana::paintEvent(QPaintEvent *)
{
        QPainter painter(this);
       if(!im.isNull()) {
           painter.drawImage(0, 0, im.scaled(this->size()));
       }
}
