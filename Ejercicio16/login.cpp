#include "login.h"
#include "ui_login.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>

Login::Login(QWidget * parent) : QWidget(parent), ui(new Ui::Login), networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    connect(networkManager, &QNetworkAccessManager::finished, this, &Login::onNetworkReply);
}

Login::~Login()
{
    delete ui;
    delete networkManager;
}

void Login::slot_validarUsuario()
{
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();

    QJsonObject json;
    json["usuario"] = usuario;
    json["clave"] = clave;

    QNetworkRequest request(QUrl("http://localhost:8000/validar_usuario"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    networkManager->post(request, QJsonDocument(json).toJson());
}

void Login::onNetworkReply(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QString responseText(response);

        if (responseText == "denegado") {
            emit signal_usuarioValidado(false, QStringList());
        } else {
            QStringList usuario = responseText.split("::");
            emit signal_usuarioValidado(true, usuario);
        }
    } else {
        emit signal_usuarioValidado(false, QStringList());
    }

    reply->deleteLater();
}
