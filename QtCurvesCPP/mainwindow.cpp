#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->RenderArea->setShape(renderArea::Astroid);
    this->ui->RenderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->RenderArea->setShape(renderArea::Cycloid);
    this->ui->RenderArea->repaint();
}

void MainWindow::on_btnHugens_clicked()
{
    this->ui->RenderArea->setShape(renderArea::HugensCycloid);
    this->ui->RenderArea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->RenderArea->setShape(renderArea::HypoCycloid);
    this->ui->RenderArea->repaint();
}
