#include "mimetyperegistry.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QCoreApplication app (argc, argv);

    // Instantiate two objects of QMimeTypeRegistry to make sure the class can be instantiated
    QScopedPointer<QMimeTypeRegistry> mimeTypeRegistry1 (new QMimeTypeRegistry());
    QScopedPointer<QMimeTypeRegistry> mimeTypeRegistry2 (new QMimeTypeRegistry());

    qDebug() << "Hello world";
    return 0;
}
