#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "mainwindow.h"

class AutoTest : public QObject
{
    Q_OBJECT
public:
    explicit AutoTest(QObject *parent = nullptr);

signals:

public slots:
private slots:
    void testGui();
    void testGui_data();
    void testAdd();
    void testAdd_data();
    void testKeyEnterAdd();
    void testKeyEnterAdd_data();
    void testDelete();
    void testEditor();

private:
//    MainWindow window;

};

#endif // AUTOTEST_H
