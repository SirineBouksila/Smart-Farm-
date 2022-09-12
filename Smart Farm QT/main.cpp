#include "mainwindow.h"
#include "sirine.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    c.ouvrirConnexion();
    Sirine w;
    w.show();
    /*MainWindow window;
        window.resize(400, 300);
        window.show();*/
    return a.exec();
}
