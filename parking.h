#ifndef PARKING_H
#define PARKING_H
#include"cparking.h"
#include <QDialog>

namespace Ui {
class parking;
}

class parking : public QDialog
{
    Q_OBJECT

public:
    explicit parking(QWidget *parent = nullptr);
    ~parking();

private slots:
    void on_pushButton_clicked();

    void on_supp_park_clicked();

    void on_park_ajout_clicked();

    void on_mod_park_clicked();

private:
    Ui::parking *ui;
    Cparking tmp1;

};

#endif // PARKING_H
