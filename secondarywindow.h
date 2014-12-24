#ifndef SECONDARYWINDOW_H
#define SECONDARYWINDOW_H

#include <QDialog>
#include <QObject>
#include <QSize>
#include <QWidget>
#include <QCloseEvent>

#include "appcontroller.h"

namespace Ui {
class SecondaryWindow;
}

class SecondaryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondaryWindow(QWidget* widget, AppController* controller, QWidget* parent = 0);
    ~SecondaryWindow();

private:
    void closeEvent(QCloseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void closeWindow();

    Ui::SecondaryWindow* ui;
    AppController* controller;
    QWidget* widget;

    QSize newWidgetSizeDiference;

    int dragClickX;
    int dragClickY;
    QObject* firstClicked;

    QWidget* topBar;

signals:

public slots:

private slots:
    void on_topBarCloseButton_clicked();

};

#endif // SECONDARYWINDOW_H
