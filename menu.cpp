#include <QWidget>
#include <QCloseEvent>
#include "menu.h"
#include "game.h"
#include "ui_menu.h"

extern Game * game;

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    QWidget *frame = new QWidget(this);
    frame->setGeometry(0, 0, 300, 68);
    frame->setStyleSheet("background-image: url(:/images/logo.png)");

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_new_game_clicked()
{
    game->set_player_name(ui->player_name->toPlainText());
    game->start();

    hide();
}


void Menu::on_show_scores_clicked()
{
    game->show_scores();
}

void Menu::closeEvent (QCloseEvent *event)
{
    game->closeEvent(event);
}

void Menu::on_quit_clicked()
{
    game->closeEvent(nullptr);
}

