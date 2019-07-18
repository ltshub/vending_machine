#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



widget::widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->pbCoke->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
}

widget::~widget()
{
    delete ui;
}

void widget::changeMoney(int n){

    money += n;

    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
    }
    else if(money >= 100 && money < 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
    }
    else if(money >= 150 && money < 200){
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }
    else{
        ui->pbCoke->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }

    ui->lcdNumber->display(money);
}

void widget::on_pb_10_clicked()
{
    changeMoney(10);
}

void widget::on_pb_50_clicked()
{
    changeMoney(50);
}

void widget::on_pb_100_clicked()
{
    changeMoney(100);
}

void widget::on_pb_500_clicked()
{
    changeMoney(500);
}


void widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}



void widget::on_pbMoney_clicked()
{
    int res[4] = {0};
    int arr[4] = {500, 100, 50 ,10};
    int idx {0};
    QString strTotal;
    QMessageBox msg;

    while(money != 0){
        res[idx] = money / arr[idx];
        money -= res[idx] * arr[idx++];
    }

    strTotal = QString("500won : %1\n100won : %2\n50won : %3\n10won : %4")
            .arg(res[0])
            .arg(res[1])
            .arg(res[2])
            .arg(res[3]);

    msg.information(nullptr, "return 'Jan Don'", strTotal);
    ui->lcdNumber->display(money);
}
