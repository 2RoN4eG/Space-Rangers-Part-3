#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent* event);

    void resizeEvent(QResizeEvent* event);

    void mousePressEvent(QMouseEvent* event);

    void timerEvent(QTimerEvent* event);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    bool _setting_enemy_path {};
    bool _following {};

    int _timer_id { -1 };
};

#endif // MAINWINDOW_H
