#ifndef ASSURANCE_H
#define ASSURANCE_H

#include <QDialog>

namespace Ui {
class assurance;
}

class assurance : public QDialog
{
    Q_OBJECT

public:
    explicit assurance(QWidget *parent = nullptr);
    ~assurance();

private:
    Ui::assurance *ui;
};

#endif // ASSURANCE_H
