#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");
    setGeometry(200, 200, 300, 150);

    auto layout = new QGridLayout(this);

    lbl_usuario = new QLabel("Usuario:");
    lbl_contrasena = new QLabel("Contraseña:");

    txt_usuario = new QLineEdit();
    txt_contrasena = new QLineEdit();
    txt_contrasena->setEchoMode(QLineEdit::Password);

    btn_login = new QPushButton("Ingresar");

    layout->addWidget(lbl_usuario, 0, 0);
    layout->addWidget(txt_usuario, 0, 1);
    layout->addWidget(lbl_contrasena, 1, 0);
    layout->addWidget(txt_contrasena, 1, 1);
    layout->addWidget(btn_login, 2, 0, 1, 2);

    setLayout(layout);

    connect(btn_login, &QPushButton::clicked, this, &Login::verificarLogin);
}

void Login::verificarLogin() {
    QString usuario_ingresado = txt_usuario->text();
    QString contrasena_ingresada = txt_contrasena->text();
    if (usuario_ingresado == "admin" && contrasena_ingresada == "1111") {
        QMessageBox::information(this, "Ingreso exitoso", "Inicio de sesión exitoso.");
        abrirFormulario();
    } else {
        QMessageBox::warning(this, "Error", "Usuario y/o contraseña incorrectos");
        txt_usuario->clear();
        txt_contrasena->clear();
    }
}

void Login::abrirFormulario() {
    formulario = new Formulario();
    formulario->show();
    close();
}

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Formulario");
    setGeometry(300, 300, 400, 200);

    auto layout = new QGridLayout(this);

    lbl_legajo = new QLabel("Legajo:");
    lbl_nombre = new QLabel("Nombre:");
    lbl_apellido = new QLabel("Apellido:");
    lbl_captcha = new QLabel("Captcha:");

    txt_legajo = new QLineEdit();
    txt_nombre = new QLineEdit();
    txt_apellido = new QLineEdit();
    txt_captcha = new QLineEdit();

    btn_enviar = new QPushButton("Enviar");
    btn_limpiar = new QPushButton("Limpiar campos");
    QPushButton *btn_validar = new QPushButton("Validar");

    captcha_generado = QRandomGenerator::global()->bounded(10000);
    lbl_captcha->setText("Captcha: " + QString::number(captcha_generado));

    layout->addWidget(lbl_legajo, 0, 0);
    layout->addWidget(txt_legajo, 0, 1);
    layout->addWidget(lbl_nombre, 1, 0);
    layout->addWidget(txt_nombre, 1, 1);
    layout->addWidget(lbl_apellido, 2, 0);
    layout->addWidget(txt_apellido, 2, 1);
    layout->addWidget(lbl_captcha, 3, 0);
    layout->addWidget(txt_captcha, 3, 1);
    layout->addWidget(btn_validar, 3, 2);
    layout->addWidget(btn_enviar, 4, 0, 1, 2);
    layout->addWidget(btn_limpiar, 5, 0, 1, 2);

    setLayout(layout);

    connect(btn_limpiar, &QPushButton::clicked, this, &Formulario::limpiarCampos);
    connect(btn_enviar, &QPushButton::clicked, this, &Formulario::verificarCaptcha);
    connect(btn_validar, &QPushButton::clicked, this, &Formulario::verificarCaptcha);
}

void Formulario::limpiarCampos() {
    txt_legajo->clear();
    txt_nombre->clear();
    txt_apellido->clear();
    txt_captcha->clear();

    captcha_generado = QRandomGenerator::global()->bounded(10000);
    lbl_captcha->setText("Captcha: " + QString::number(captcha_generado));
}

void Formulario::verificarCaptcha() {
    QString captcha_ingresado = txt_captcha->text();
    if (captcha_ingresado == QString::number(captcha_generado)) {
        QMessageBox::information(this, "Captcha correcto", "Captcha ingresado correctamente.");
    } else {
        QMessageBox::warning(this, "Captcha incorrecto", "El captcha ingresado es incorrecto.");
        txt_captcha->clear();
    }
}
