#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>

namespace Ui {
class Records;
}

class Records : public QDialog
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    ~Records();
    void closeEvent (QCloseEvent *event);

private:
    Ui::Records *ui;
    void set_values();
};

#endif // RECORDS_H
