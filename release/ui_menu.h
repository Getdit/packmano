/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *new_game;
    QPushButton *show_scores;
    QPushButton *quit;
    QTextEdit *player_name;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(303, 258);
        new_game = new QPushButton(Menu);
        new_game->setObjectName(QString::fromUtf8("new_game"));
        new_game->setGeometry(QRect(50, 100, 80, 25));
        show_scores = new QPushButton(Menu);
        show_scores->setObjectName(QString::fromUtf8("show_scores"));
        show_scores->setGeometry(QRect(50, 140, 80, 25));
        quit = new QPushButton(Menu);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(50, 180, 80, 25));
        player_name = new QTextEdit(Menu);
        player_name->setObjectName(QString::fromUtf8("player_name"));
        player_name->setGeometry(QRect(140, 97, 131, 30));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush1(QColor(31, 35, 51, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        player_name->setPalette(palette);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Packman", nullptr));
        new_game->setText(QCoreApplication::translate("Menu", "Novo jogo", nullptr));
        show_scores->setText(QCoreApplication::translate("Menu", "Ver Scores", nullptr));
        quit->setText(QCoreApplication::translate("Menu", "Sair", nullptr));
        player_name->setPlaceholderText(QCoreApplication::translate("Menu", "Nome do jogador", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
