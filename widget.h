#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

namespace Ui {
class widget;
}

class widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();
    void changeMoney(int n);
    int money {0};



private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_500_clicked();

    void on_pb_100_clicked();

    void on_pbCoffee_clicked();

    void on_pbCoke_clicked();

    void on_pbTea_clicked();

    void on_pbMoney_clicked();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
