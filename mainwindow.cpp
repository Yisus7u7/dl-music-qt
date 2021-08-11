#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>

//autor: Yisus7u7 <jesuspixel5@gmail.com>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//"%(title)s-%(id)s.%(ext)s"

void MainWindow::on_actionquit_triggered()
{
    close();
}

void MainWindow::on_qt_about_triggered()
{
    QMessageBox::aboutQt(this, "Qt");
}

void MainWindow::on_actionabout_triggered()
{
    QString txt;
    txt = "Autor: Yisus7u7\n";
    txt += "dl-music-qt is a simple music downloader\n";
    txt += "for youtube videos made in C++ and Qt using\n";
    txt += "youtube-dl library.\n";
    QMessageBox::about(this, "dl-music-qt", txt);
}

void MainWindow::on_download_clicked()
{
    ui->label2->setText("wait a moment...");

    QString folder = QFileDialog::getExistingDirectory(this, "Open Directory To Save Music");
    QString geturl = ui->entryUrl->text();
    QDir::setCurrent(folder);
    QProcess::execute("youtube-dl --extract-audio --embed-thumbnail --audio-format mp3 " + geturl);
    ui->label2->setText("Download completed.");
    //system("youtube-dl bestaudio --extract-audio --embed-thumbnail --audio-format mp3 ");
}

void MainWindow::on_get_folder_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Open Directory To Save Music");

}

void MainWindow::on_pushButton_clicked()
{
    ui->entryUrl->paste();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->entryUrl->clear();
}
