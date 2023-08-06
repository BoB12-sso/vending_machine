#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    if(diff==0) money = 0;
    else money+=diff;
    ui->lcdNumber->display(money);

    if(money<100) ui->pbCoffee->setEnabled(false);
    else ui->pbCoffee->setEnabled(true);

    if(money<150) ui->pbTea->setEnabled(false);
    else ui->pbTea->setEnabled(true);

    if(money<200) ui->pbMilk->setEnabled(false);
    else ui->pbMilk->setEnabled(true);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    string fh = to_string(money/500);
    money %= 500;

    string oh = to_string(money / 100);
    money %= 100;

    string fw = to_string(money / 50);
    money %= 50;

    string ow = to_string(money / 10);

    string message = "500원: " + fh + "개, 100원: " + oh + "개, 50원: " + fw + "개, 10원: " + ow + "개";

    mb.information(nullptr,"title",message.c_str());
    changeMoney(0);
}



