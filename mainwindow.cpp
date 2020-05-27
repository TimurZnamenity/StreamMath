#include "HandleWidget.hpp"
#include "mainwindow.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto handleWidget = new HandleWidget();
    setCentralWidget( handleWidget );
}

MainWindow::~MainWindow()
{
}

