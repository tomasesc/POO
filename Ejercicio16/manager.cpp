#include "manager.h"

Manager::Manager( QObject * parent ) : QObject( parent ),
                                       login( new Login ),
                                       ventana( new Ventana )
{

    connect( login, SIGNAL( signal_usuarioValidado( bool, QStringList ) ),
             this, SLOT( slot_ingreso( bool, QStringList ) ) );

}

void Manager::iniciar()
{
    login->show();
}

void Manager::slot_ingreso( bool valido, QStringList usuario )
{
    if ( valido )  {
        login->hide();
        ventana->show();
        ventana->setWindowTitle( "Bienvenido: " + usuario.at( 0 ) );
    }
    else  {
        login->close();
    }
}
