#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_new_game_clicked();
    void closeEvent (QCloseEvent *event);
    void on_show_scores_clicked();

    void on_quit_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
