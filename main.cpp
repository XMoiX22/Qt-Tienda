#include "tienda.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traducion;
    QStringList idiomas;
        idiomas << "Inglés" << "Español";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);
        if (idiomaSeleccionado == "Francés"){
                traducion.load(":/Calculadora_fr_FR.qm");
            }else if (idiomaSeleccionado == "Inglés"){
                traducion.load(":/tienda01_en.qm");
            }
            // Si es diferente de español, se instala la traducción en TODA la aplicación
            if (idiomaSeleccionado != "Español"){
                a.installTranslator(&traducion);
            }
            // Muestra la ventana principal
            Tienda w;
            w.show();
            return a.exec();
        }
