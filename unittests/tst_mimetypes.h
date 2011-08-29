#ifndef TST_MIMETYPES_H_INCLUDED
#define TST_MIMETYPES_H_INCLUDED

#include <QtCore/QObject>

class tst_mimetypes : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();

    void test_QMimeType_isValid();
    void test_QMimeType_name();
    void test_QMimeType_displayName();
    void test_QMimeType_iconUrl();
    void test_QMimeType_fileExtentions();

    void test_QServiceAction_isValid();
    void test_QServiceAction_name();
    void test_QServiceAction_displayName();
    void test_QServiceAction_iconUrl();

    void test_QMimeTypeRegistry_mimeTypes();
    void test_QMimeTypeRegistry_findMimeType();
    void test_QMimeTypeRegistry_fileExtentions();
    void test_QMimeTypeRegistry_extractFileExtention();
    void test_QMimeTypeRegistry_findMimeTypes();
    void test_QMimeTypeRegistry_determineMimeType();
    void test_QMimeTypeRegistry_serviceActions();
    void test_QMimeTypeRegistry_findServiceAction();
    void test_QMimeTypeRegistry_setUserAlwaysSelectsApplication();
    void test_QMimeTypeRegistry_findApplications();
};

#endif
