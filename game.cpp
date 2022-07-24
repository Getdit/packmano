#include <QGraphicsTextItem>
#include <QApplication>
#include <QTimer>
#include <QImage>
#include <QBrush>

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <random>

#include "game.h"
#include "enemy.h"
#include "cherry.h"
#include "block.h"
#include "goldapple.h"

extern QApplication a;

Game::Game(QWidget *parent): QGraphicsView(parent)
{
      menu = new Menu();
      records=NULL;

      scene = new QGraphicsScene();
      scene -> setSceneRect(0,0,800,600);
      scene -> setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));
      setScene(scene);

      setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

      setFixedSize(800, 600);

      show_menu();

}

void Game::gameover()
{
    add_score();
    scene->clear();
    hide();
    show_menu();
}

void Game::start()
{
    if (records!=NULL){
        records->closeEvent(nullptr);
    }

    for (int ry=0; ry < 15; ry++){
        for (int rx=0; rx < 20; rx++){
            if (mapa.at(ry).at(rx)==1 && !(ry == 7 && (rx == 7 || rx == 8 || rx == 9 || rx == 10 || rx == 11 || rx == 12)) ){
                std::random_device random_d;
                std::mt19937 generator(random_d());
                std::uniform_int_distribution<> distributor(0, 3);

                if (distributor(generator) == 1){
                    mapa[ry][rx] = 2;
                    scene -> addItem(new Block(rx, ry));
                }
            }
        }
    }

    player = new Player();
    player -> setPos(340,280);
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();

    scene -> addItem(player);

    Enemy * en0 = new Enemy();
    scene -> addItem(en0);

    Enemy * en1 = new Enemy();
    scene -> addItem(en1);

    Enemy * en2 = new Enemy();
    scene -> addItem(en2);

    Enemy * en3 = new Enemy();
    scene -> addItem(en3);

    Enemy * en4 = new Enemy();
    scene -> addItem(en4);

    Enemy * en5 = new Enemy();
    scene -> addItem(en5);

    Cherry * ch = new Cherry();
    scene -> addItem(ch);

    score = new Score();
    scene->addItem(score);

    show();
}

void Game::show_scores()
{
    records = new Records();
}

void Game::show_menu()
{
    menu->show();
}

void Game::set_player_name(QString n_name)
{
    player_name = n_name;
}

void Game::add_score()
{
    std::vector<std::pair<std::string, int>> records;
    std::pair<std::string, int> new_record;
    bool add_score = true;



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

            if (player_name.toStdString() == new_record.first){
                if (score->getScore() < new_record.second){
                    add_score = false;
                    records.push_back(new_record);
                }
            } else {
                records.push_back(new_record);
            }


        }

    } else {
        qDebug() << "Erro, não foi possível ler o arquivo. Por favor, verifique se possui permissões de leitura.";
    }
    reader.close();

    if (add_score){
        new_record.first = player_name.toStdString();
        new_record.second = score->getScore();
    }
    std::replace( new_record.first.begin(), new_record.first.end(), ';', ' ');
    records.push_back(new_record);

    sort(records.begin(), records.end(),
        [](const std::pair<std::string, int> & a, const std::pair<std::string, int> & b) -> bool
    {
        return a.second > b.second;
    });


    int rg;
    if (records.size() >10)
        rg = 10;
    else {
        rg = records.size();
    }

    std::ofstream writer("./records.data");

    if(writer.is_open())
    {
        for (int i = 0; i < rg; i++)
        {
            writer << records.at(i).first <<";" << records.at(i).second << std::endl;
        }

    } else {
        qDebug()  << "Erro, não foi possível abrir o arquivo. Por favor, verifique se possui permissões de escrita.";
    }


    writer.close();
}

void Game::closeEvent (QCloseEvent *event)
{
    scene->clear();
    delete menu;
    delete records;
    a.quit();
}


QVector<QVector<int>> Game::get_mapa()
{
    return mapa;
}

void Game::enable_sector(int rx, int ry)
{
    score->increase();
    mapa[ry][rx] = 1;

    std::random_device random_d;
    std::mt19937 generator(random_d());
    std::uniform_int_distribution<> distributor(0, 20);

    if (distributor(generator) == 11){
        scene->addItem(new GoldApple(rx, ry));
    }
}

bool Game::get_power_up_mode()
{
    return power_up_mode;
}

void Game::enable_power_up_mode()
{
    power_up_mode = true;
}

void Game::disable_power_up_mode()
{
    power_up_mode = false;
}

