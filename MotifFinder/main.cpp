#include"choosewindow.h"
#include<QApplication>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    ChooseWindow w;
    w.show();

    return a.exec();
}
