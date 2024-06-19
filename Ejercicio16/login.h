#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
    class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget * parent = 0);
    ~Login();

private:
    Ui::Login *ui;
    QNetworkAccessManager *networkManager;

private slots:
    void slot_validarUsuario();
    void onNetworkReply(QNetworkReply* reply);

signals:
    void signal_usuarioValidado(bool valido, QStringList usuario);
};

#endif // LOGIN_H
