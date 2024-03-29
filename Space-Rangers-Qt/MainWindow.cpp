#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QPainter>
#include <QMouseEvent>
#include <QTime>

#include "t_scene_components.h"


#include "t_common_entities.h"

#include "spaceships/t_spaceship_system_trajectory_moving.h"
#include "spaceships/t_spaceship_system_following_another.h"
#include "spaceships/equipments/weapons/t_spaceship_rocket_weapon_launching_system.h"
#include "spaceships/equipments/t_rocket_moving_system.h"

#include "planets/t_planet_system_circle_moving.h"

#include "spaceships/t_component_spaceship.h"

#include "linear_algebra/t_2d_linear_algebra_systems.h"

#include "t_game_render_system.h"

#include <iostream>

#define qCurrentTime \
    QTime::currentTime().toString("hh:mm:ss")

t_scene_components g_scene_components {};

constexpr t_spaceship_id_entity t_enemy_spaceship_id { 2 };

t_spaceship_following_another_system spaceship_following_another { g_scene_components,
                                                                   t_player_spaceship_id,
                                                                   t_enemy_spaceship_id };

t_spaceship_rocket_weapon_launcher_system paceship_rocket_weapon_launcher { g_scene_components,
                                                                            t_player_spaceship_id };

t_rocket_system_moving rocket_moving { g_scene_components };

t_planet_system_circle_moving planet_circle_moving { g_scene_components };

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    repaint();

    std::vector<std::runtime_error> errors;
    
    complex_test_2d_container_system(errors);

    complex_test_2d_vector_systems(errors);

    for (const std::runtime_error& error : errors) {
        std::cout << "runtime error: " << error.what() << std::endl;
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event) {
    const QSize& size = ui->widget->size();

    QPainter painter { this };

    t_game_render_system render { size, painter, g_scene_components };

    render.update();

    resizeEvent(nullptr);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    const QSize& size = ui->widget->size();

    ui->space_ship_spin_box_x->setMaximum(size.width());
    ui->space_ship_spin_box_x_maximum->setText(QString::number(size.width()));

    ui->space_ship_spin_box_y->setMaximum(size.height());
    ui->space_ship_spin_box_y_maximum->setText(QString::number(size.height()));

    ui->space_ship_spin_box_x_enemy->setMaximum(size.width());
    ui->space_ship_spin_box_x_enemy_maximum->setText(QString::number(size.width()));

    ui->space_ship_spin_box_y_enemy->setMaximum(size.height());
    ui->space_ship_spin_box_y_enemy_maximum->setText(QString::number(size.height()));
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    if (!_setting_enemy_path) { return; }

    const QPoint point = event->pos();

    t_spaceship_component& spaceship = g_scene_components.spaceship(t_enemy_spaceship_id);
    spaceship.trajectory().emplace_back(point.x(), ui->widget->size().height() - point.y());

    repaint();
}

void MainWindow::timerEvent(QTimerEvent* event) {
    qDebug() << qCurrentTime << "qt timerEvent(QTimerEvent* event)";

    t_spaceship_component& spaceship = g_scene_components.spaceship(t_enemy_spaceship_id);

    t_spaceship_system_trajectory_moving spaceship_moving { spaceship };
    spaceship_moving.update();

    planet_circle_moving.update();

    if (_following) {
        spaceship_following_another.update();
        paceship_rocket_weapon_launcher.update();
        rocket_moving.update();
    }

    repaint();
}

void MainWindow::on_pushButton_3_clicked() {
    t_spaceship_component& spaceship = g_scene_components.spaceship(t_player_spaceship_id);

    spaceship.position() = {
        float (ui->space_ship_spin_box_x->value()),
        float (ui->space_ship_spin_box_y->value())
    };

    // std::cout << "spaceship { id: " << spaceship.id() << " } contains position { "
    //           << float (ui->space_ship_spin_box_x->value()) << ", " << float (ui->space_ship_spin_box_y->value())
    //           << " }" << std::endl;

    repaint();
}

void MainWindow::on_pushButton_4_clicked() {
    t_spaceship_component& spaceship = g_scene_components.spaceship(t_enemy_spaceship_id);

    spaceship.position() = {
        float (ui->space_ship_spin_box_x_enemy->value()),
        float (ui->space_ship_spin_box_y_enemy->value())
    };

    // std::cout << "spaceship { id: " << spaceship.id() << " } contains position { "
    //           << float (ui->space_ship_spin_box_x_enemy->value()) << ", " << float (ui->space_ship_spin_box_y_enemy->value())
    //           << " }" << std::endl;

    repaint();
}

void MainWindow::on_pushButton_5_clicked() {
    t_spaceship_component& spaceship = g_scene_components.spaceship(t_enemy_spaceship_id);

    spaceship.trajectory() = {};
    _setting_enemy_path = true;

    repaint();
}

void MainWindow::on_pushButton_6_clicked() {
    _setting_enemy_path = false;

    repaint();
}

void MainWindow::on_pushButton_7_clicked() {
    if (_timer_id > -1) {
        std::cout << "setting pause state" << std::endl;
        killTimer(_timer_id);
        _timer_id = -1;
        return;
    }

    std::cout << "setting play state" << std::endl;
    _timer_id = startTimer(500);
}


void MainWindow::on_pushButton_clicked() {
    _following = !_following;
}

