#ifndef IDENTIFICACION_H
#define IDENTIFICACION_H

#include <QWidget>

class QLineEdit;
class QPushButton;
class QLabel; // Se agrega declaración de QLabel

class Identificacion : public QWidget {
    Q_OBJECT

public:
    explicit Identificacion(QWidget *parent = nullptr);

public slots:
    void showWindow();

private:
    QLineEdit *legajoEdit;
    QLineEdit *nombreEdit;
    QLineEdit *apellidoEdit;
    QLineEdit *captchaEdit;
    QPushButton *altaButton;
    QLabel *captchaLabel; // Se agrega declaración de QLabel
};

#endif // IDENTIFICACION_H
