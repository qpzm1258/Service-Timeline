#include "TakePhotos.h"
#include <QApplication>
#include <QTextCodec>
#include <qsharedmemory.h>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QSharedMemory shared("TakeAPhoto");
        if (shared.attach())
        {
            return 0;
        }
        shared.create(1);
    QApplication a(argc, argv);
    QTranslator m_qtTranslator;
        m_qtTranslator.load("zh_CN.qm");
        a.installTranslator(&m_qtTranslator);
    TakePhotos w;
    w.setWindowFlags(w.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    w.show();

    return a.exec();
}
