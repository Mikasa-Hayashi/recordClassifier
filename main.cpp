#include <QCoreApplication>
#include <QTextCodec>
#include "windows.h"
#include "classifier.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    #ifdef Q_OS_WIN
    SetConsoleOutputCP(CP_UTF8); // Переключает консоль на UTF-8
    #endif
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    Classifier classifier;
    classifier.loadData("", "");
    classifier.classify();
    classifier.saveResults("");



    return a.exec();
}
