#include <fstream>
#include <string>
#include <sstream>

#include "records.h"
#include "ui_records.h"
#include "game.h"

extern Game * game;

Records::Records(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);

    QWidget *frame = new QWidget(this);
    frame->setGeometry(0, 0, 300, 68);
    frame->setStyleSheet("background-image: url(:/images/logo.png)");

    set_values();

    show();
}

Records::~Records()
{
    delete ui;
}

void Records::set_values()
{
    std::vector<std::pair<std::string, int>> records;
    std::pair<std::string, int> new_record;



    std::fstream reader("./records.data");

    if (reader.is_open())
    {
        std::string tmp, tmp1, name;
        while (getline(reader, tmp))
        {
            std::stringstream strValue(tmp);

            bool flag = true;
            std::stringstream to_read(tmp);


            while(getline(to_read, tmp1, ';'))
            {
                if (flag){
                    new_record.first = tmp1;
                    flag = false;
                } else {
                    std::stringstream strScore(tmp1);
                    strScore >> new_record.second;
                }
            }

            records.push_back(new_record);
        }

    } else {
        qDebug() << "Erro, não foi possível ler o arquivo. Por favor, verifique se possui permissões de leitura.";
    }
    reader.close();

    sort(records.begin(), records.end(),
        [](const std::pair<std::string, int> & a, const std::pair<std::string, int> & b) -> bool
    {
        return a.second > b.second;
    });

    int r_lenght = records.size();
    std::string n1,n2, n3, n4, n5, n6, n7, n8, n9, n10, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;

    n1 = "--------";
    n2 = "--------";
    n3 = "--------";
    n4 = "--------";
    n5 = "--------";
    n6 = "--------";
    n7 = "--------";
    n8 = "--------";
    n9 = "--------";
    n10 = "--------";
    s1 = "--------";
    s2 = "--------";
    s3 = "--------";
    s4 = "--------";
    s5 = "--------";
    s6 = "--------";
    s7 = "--------";
    s8 = "--------";
    s9 = "--------";
    s10 = "--------";

    for (int i=0; i<r_lenght; i++){
        if (i == 0)
        {
            n1 = records.at(0).first;
            s1 = std::to_string(records.at(0).second);
        }
        else if (i == 1)
        {
            n2 = records.at(1).first;
            s2 = std::to_string(records.at(1).second);
        }
        else if (i == 2)
        {
            n3 = records.at(2).first;
            s3 = std::to_string(records.at(2).second);
        }
        else if (i == 3)
        {
            n4 = records.at(3).first;
            s4 = std::to_string(records.at(3).second);
        }
        else if (i == 4)
        {
            n5 = records.at(4).first;
            s5 = std::to_string(records.at(4).second);
        }
        else if (i == 5)
        {
            n6 = records.at(5).first;
            s6 = std::to_string(records.at(5).second);
        }
        else if (i == 6)
        {
            n7 = records.at(6).first;
            s7 = std::to_string(records.at(6).second);
        }
        else if (i == 7)
        {
            n8 = records.at(7).first;
            s8 = std::to_string(records.at(7).second);
        }
        else if (i == 8)
        {
            n9 = records.at(8).first;
            s9 = std::to_string(records.at(8).second);
        }
        else if (i == 9)
        {
            n10 = records.at(9).first;
            s10 = std::to_string(records.at(9).second);
        }

    }

    ui->name_1->setText(QString::fromStdString(n1));
    ui->score_1->setText(QString::fromStdString(s1));

    ui->name_2->setText(QString::fromStdString(n2));
    ui->score_2->setText(QString::fromStdString(s2));

    ui->name_3->setText(QString::fromStdString(n3));
    ui->score_3->setText(QString::fromStdString(s3));

    ui->name_4->setText(QString::fromStdString(n4));
    ui->score_4->setText(QString::fromStdString(s4));

    ui->name_5->setText(QString::fromStdString(n5));
    ui->score_5->setText(QString::fromStdString(s5));

    ui->name_6->setText(QString::fromStdString(n6));
    ui->score_6->setText(QString::fromStdString(s6));

    ui->name_7->setText(QString::fromStdString(n7));
    ui->score_7->setText(QString::fromStdString(s7));

    ui->name_8->setText(QString::fromStdString(n8));
    ui->score_8->setText(QString::fromStdString(s8));

    ui->name_9->setText(QString::fromStdString(n9));
    ui->score_9->setText(QString::fromStdString(s9));

    ui->name_10->setText(QString::fromStdString(n10));
    ui->score_10->setText(QString::fromStdString(s10));
}

void Records::closeEvent (QCloseEvent *event)
{
    game->records=NULL;
    delete this;
}
