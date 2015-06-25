#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void update();
    void start_timer();
    void stop_timer();

private:
    Ui::MainWindow *ui;
    QTimer *m_Timer;
    void convert_time(int sec);
    int seconds;
    int minutes;
    int hours;
};

#endif // MAINWINDOW_H
