#include "statistique.h"
#include "ui_statistique.h"

Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);

        QPieSeries *series = new QPieSeries();

        series->append("REFERENCE", 80);
        series->append("NB_MACHINE", 70);
        series->append("TYPE_PRODUIT", 50);
       // series->append("C#", 40);
       // series->append("PHP", 30);


        QPieSlice *slice = series->slices().at(1);
        slice->setExploded(true);
        slice->setLabelVisible(true);
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("chaine");


        QChartView *chartview = new QChartView(chart);
        chartview->setParent(ui->horizontalLayoutWidget);
        chartview->setGeometry(0,0,709,379);

}

Statistique::~Statistique()
{
    delete ui;
}
