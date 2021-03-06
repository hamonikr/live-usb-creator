/**********************************************************************
 *  mainwindow.h
 **********************************************************************
 * Copyright (C) 2017 MX Authors
 *
 * Authors: Adrian
 *          MX Linux <http://mxlinux.org>
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this package. If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QProcess>
#include <QTimer>
#include <QSettings>
#include <QFile>

#include <src/cmd.h>

const QString cli_utils = ". /usr/local/lib/cli-shell-utils/cli-shell-utils.bash;";

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(const QStringList &args);
    ~MainWindow();

    bool checkDestSize();
    bool isRunningLive();
    bool isToRam();
    void makeUsb(const QString &options);
    void progress();
    void setup();
    QString buildOptionList();
    QStringList buildUsbList();
    QStringList removeUnsuitable(const QStringList &devices); // remove unsuitable disks from the list (live and unremovable)
    QString LUM;


public slots:

private slots:
    void cleanup();
    void cmdStart();
    void cmdDone();
    void setConnections();
    void setDefaultMode(const QString &iso_name);
    void updateBar();
    void updateOutput();
    void on_buttonNext_clicked();
    void on_buttonAbout_clicked();
    void on_buttonHelp_clicked();
    void on_buttonBack_clicked();
    void on_buttonSelectSource_clicked();
    void on_buttonRefresh_clicked();
    void on_buttonOptions_clicked();
    void on_edit_label_textChanged(QString arg1);
//    void on_buttonEnter_clicked();
//    void on_lineEdit_returnPressed();
    void on_cb_update_clicked(bool checked);
    void on_cb_clone_mode_clicked(bool checked);
    void on_cb_clone_live_clicked(bool checked);
    void on_rb_dd_clicked();
    void on_rb_normal_clicked();
    bool isantiX_mx_family(QString arg1);

    void on_pushButtonLumLogFile_clicked();

private:
    Ui::MainWindow *ui;
    Cmd cmd;
    Cmd cmd2;
    QString device;
    QTimer timer;

    bool advancedOptions;
    int height;
    int iso_sectors;
    int start_io;
    int size_check;
};


#endif

