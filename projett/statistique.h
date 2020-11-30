#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

namespace Ui {
class Statistique;
}

class Statistique : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *parent = nullptr);
    ~Statistique();

private:
    Ui::Statistique *ui;
};

#endif // STATISTIQUE_H
