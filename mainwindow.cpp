#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * Initializes MainWindow class.
 * @param parent Parent window.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Timer = new QTimer(this);
    m_Timer->setTimerType(Qt::PreciseTimer);

    //przypisz metode start_timer() do nacisniecia na przycisk
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(start_timer()));

    //przypisz metode stop_timer() do nacisniecia na przycisk
    connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(stop_timer()));

    //przypisz zdarzeniu uplywu czasu metode update()
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(update()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::start_timer
 * Starts a timer and sets second count to zero.
 */
void MainWindow::start_timer()
{
    seconds = 0;
    m_Timer->start(1000);
}

/**
 * @brief MainWindow::stop_timer
 * Stops a timer.
 */
void MainWindow::stop_timer()
{
    m_Timer->stop();
}

/**
 * @brief MainWindow::convert_time
 * Converts time from seconds to human readable format.
 * @param sec Number of seconds to convert to human readable format
 */
void MainWindow::convert_time(int sec)
{
    if(sec/60==1)
    {
        minutes++;
        seconds = 0;
    }
    if(minutes/60==1)
    {
        hours++;
        minutes = 0;
    }
}

/**
 * @brief MainWindow::update
 * Updates a timer.
 */
void MainWindow::update()
{
    seconds++;
    convert_time(seconds);

    //wyswietl czas
    if(seconds < 10 && minutes < 10 && hours < 10)
        ui->labelTime->setText(tr("0%1:0%2:0%3").arg(hours).arg(minutes).arg(seconds));

    if(seconds >= 10 && minutes < 10 && hours < 10)
        ui->labelTime->setText(tr("0%1:0%2:%3").arg(hours).arg(minutes).arg(seconds));

    if(seconds < 10 && minutes >= 10 && hours < 10)
        ui->labelTime->setText(tr("0%1:%2:0%3").arg(hours).arg(minutes).arg(seconds));

    if(seconds >= 10 && minutes >= 10 && hours < 10)
        ui->labelTime->setText(tr("0%1:%2:%3").arg(hours).arg(minutes).arg(seconds));

    if(seconds < 10 && minutes < 10 && hours >= 10)
        ui->labelTime->setText(tr("%1:0%2:0%3").arg(hours).arg(minutes).arg(seconds));

    if(seconds < 10 && minutes >= 10 && hours >= 10)
        ui->labelTime->setText(tr("%1:%2:0%3").arg(hours).arg(minutes).arg(seconds));

    if(seconds >= 10 && minutes >= 10 && hours >= 10)
        ui->labelTime->setText(tr("%1:%2:%3").arg(hours).arg(minutes).arg(seconds));
}

