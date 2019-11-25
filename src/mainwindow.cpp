#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setStyleSheet("QLabel#title{font-size:40px; font:bold;}QLabel, QLineEdit, QDateEdit, QDateTimeEdit, QComboBox, QListView, QSpinBox{color:white;font-size:25px; margin:0px;}QMainWindow{border-image: url(:/res/bkg.jpg) 0 0 0 0 stretch stretch;}QMessageBox QLabel{color:black;}");
  this->setCentralWidget(new LoginWindow(this));
}

MainWindow::~MainWindow()
{
  delete ui;
}
