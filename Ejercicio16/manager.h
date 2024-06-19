#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QVector>

#include "login.h"
#include "ventana.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager( QObject * parent = 0 );

    void iniciar();

private:
    Login * login;
    Ventana * ventana;

private slots:
    void slot_ingreso( bool valido, QStringList usuario );

};

#endif // MANAGER_H
