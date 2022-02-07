#ifndef TIENDA_H
#define TIENDA_H

#include <QMainWindow>
#include <producto.h>
#include <QDebug>
#include <QMessageBox>
#include <QPalette>
#include "acercade.h"
#include "finalizacion.h"
#include <QDateTime>

#define IVA 12
QT_BEGIN_NAMESPACE
namespace Ui { class Tienda; }
QT_END_NAMESPACE

class Tienda : public QMainWindow
{
    Q_OBJECT

public:
    Tienda(QWidget *parent = nullptr);
    ~Tienda();


private slots:
    void on_inNombre_currentIndexChanged(int index);

    void on_btnAgregar_released();

    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_actionAcerca_de_Tienda_triggered();

private:
    Ui::Tienda *ui;
    QList<Producto*>m_productos;
    void cargarProductos();
    float m_subtotal;
    void calcular();
    bool verificarCedula(QString as);
    bool checkVacios();
    void backgroundReset();
    void clearIn();
    QString m_details;
    void envioString();
    void clearOut();

};
#endif // TIENDA_H
