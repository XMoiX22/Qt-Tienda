#include "finalizacion.h"
#include "ui_finalizacion.h"

Finalizacion::Finalizacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finalizacion)
{
    ui->setupUi(this);
    m_acept=false;
}

Finalizacion::~Finalizacion()
{
    delete ui;
}


Ui::Finalizacion *Finalizacion::getUi() const
{
    return ui;
}

void Finalizacion::setUi(Ui::Finalizacion *newUi)
{
    ui = newUi;
}

const QString &Finalizacion::detalles() const
{
    return m_detalles;
}

const QString &Finalizacion::nombre() const
{
    return m_nombre;
}

void Finalizacion::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

const QString &Finalizacion::cedula() const
{
    return m_cedula;
}

void Finalizacion::setCedula(const QString &newCedula)
{
    m_cedula = newCedula;
}

const QString &Finalizacion::mail() const
{
    return m_mail;
}

void Finalizacion::setMail(const QString &newMail)
{
    m_mail = newMail;
}

const QString &Finalizacion::telefono() const
{
    return m_telefono;
}

void Finalizacion::setTelefono(const QString &newTelefono)
{
    m_telefono = newTelefono;
}

const QString &Finalizacion::direccion() const
{
    return m_direccion;
}

void Finalizacion::setDireccion(const QString &newDireccion)
{
    m_direccion = newDireccion;
}

void Finalizacion::insertarDatos(QString nombre, QString cedula, QString telef, QString mail, QString direccion, QString detalles)
{
    setNombre(nombre);
    setCedula(cedula);
    setTelefono(telef);
    setMail(mail);
    setDireccion(direccion);
    m_detalles=detalles;
    presentacion();
}

void Finalizacion::presentacion()
{
    QString data="";
    QString encabezado="\n*********************************************************\n\t"+tr("- ABARROTES MOIX -")+"\n"
                                                                                                                  "\n*********************************************************\n"
                                                                                                                  "RUC: 9999999999\n"
                                                                                                                  ""+tr("Direccion")+": Av. y Av. Los Cedros y Las Encinas \nCapelo Quito 170503\n"
                                                                                                                                     ""+tr("Numero")+": (02) 2861-115\n"
                                                                                                                                                     "*********************************************************\n"
                                                                                                                                                     "\t      "+tr("CLIENTE")+"\n"
                                                                                                                                                                              "*********************************************************\n";
    data=encabezado;
    if(m_cedula!="9999999999"){
        QString name="\t"+tr("Nombre")+": "+m_nombre+"\n";
        QString cedula="\t"+tr("Cedula")+": "+m_cedula+"\n";
        QString telef="\t"+tr("Telefono")+": "+m_telefono+"\n";
        QString mail="\tE-Mail: "+m_mail+"\n";
        QString direc="\t"+tr("Direccion")+": "+m_direccion+"\n"
                                                            "*********************************************************\n";
        data+=name+cedula+telef+mail+direc+"\n"+"\n";
    }
    else{
        QString add="\t"+tr("CONSUMIDOR FINAL")+"\n\n*********************************************************\n";
        data+=add;
    }
    QString pro;
    pro=""+tr("Cant")+".\t"+tr("Producto")+"\t"+tr("P.Unitario")+"\tSubTotal\n"+m_detalles;

    data+=pro;

    ui->outDatos->setPlainText(data);
    calculosString();
}

void Finalizacion::generacion()
{
    QString fechaH=QDateTime::currentDateTime().toString("ddMMyyyy-hh:mm:ss");
    QFile archivo(fechaH+".txt");
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        datosArchivo<<ui->outDatos->toPlainText();
    }
    archivo.close();
}

void Finalizacion::calculosString()
{
    QString Subtotales="";
    float iva=m_subtotal*m_iva/100;
    Subtotales="*********************************************************\n"
               "\t\tSubTotal:\t"+QString::number(m_subtotal,'f',2)+"\n"
                                                                   "\t\tIVA"+QString::number(m_iva,'f',2)+"%:\t"+QString::number(iva,'f',2)+"\n"
                                                                                                                                            "\t\tTOTAL:\t"+QString::number(m_subtotal+iva,'f',2);
    ui->outDatos->appendPlainText(Subtotales);

}

void Finalizacion::setIva(int newIva)
{
    m_iva = newIva;
}

void Finalizacion::setSubtotal(float newSubtotal)
{
    m_subtotal = newSubtotal;
}

float Finalizacion::subtotal() const
{
    return m_subtotal;
}



void Finalizacion::on_buttonBox_accepted()
{
    m_acept=true;
    generacion();
}


void Finalizacion::on_buttonBox_rejected()
{
    //Eliminacion de los datos

}

