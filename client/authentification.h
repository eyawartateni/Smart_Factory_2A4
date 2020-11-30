#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <connection.h>

#include <QDialog>

namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();
   bool authentifier();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_clicked(bool checked);

private:
    Ui::authentification *ui;
};

#endif // AUTHENTIFICATION_H
