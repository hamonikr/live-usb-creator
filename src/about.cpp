#include <QApplication>
#include <QFileInfo>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDebug>

#include "about.h"
#include "cmd.h"

// display doc as normal user when run as root
void displayDoc(QString url, QString title, bool runned_as_root) {
    if (system("command -v mx-viewer >/dev/null") == 0) {
        if (system(("mx-viewer " + url.toUtf8() + " \"" + title.toUtf8() + "\"&").toStdString().c_str()) != 0) {
            qWarning() << "Failed to execute mx-viewer";
        }
    } else {
        if (!runned_as_root) {
            if (system(("DISPLAY=$DISPLAY xdg-open " + url.toUtf8()).toStdString().c_str()) != 0) {
                qWarning() << "Failed to open URL as normal user";
            }
        } else {
            Cmd cmd;
            QString user = cmd.getCmdOut("logname", true).trimmed();
            if (system(("runuser -l " + user.toUtf8() + " -c \"env XDG_RUNTIME_DIR=/run/user/$(id -u " +
                        user.toUtf8() + ") DISPLAY=$DISPLAY xdg-open " + url.toUtf8() + "\"&").toStdString().c_str()) != 0) {
                qWarning() << "Failed to open URL as root user";
            }
        }
    }
}

void displayAboutMsgBox(QString title, QString message, QString licence_url, QString license_title, bool runned_as_root) {
    QString copyrightInfo = "<p align=\"center\">Copyright 2017 MX Linux</p>";
    QString hamonikrInfo = "<p align=\"center\">Copyright 2018-2024 HamoniKR</p>";
    QString newLink = "<p align=\"center\"><a href=\"http://hamonikr.org\">http://hamonikr.org</a><br /></p>";

    // 메시지에 저작권 정보와 새로운 링크 추가
    message += newLink + copyrightInfo + hamonikrInfo;

    QMessageBox msgBox(QMessageBox::NoIcon, title, message);
    QPushButton *btnLicense = msgBox.addButton(QApplication::tr("License"), QMessageBox::HelpRole);
    QPushButton *btnChangelog = msgBox.addButton(QApplication::tr("Changelog"), QMessageBox::HelpRole);
    QPushButton *btnCancel = msgBox.addButton(QApplication::tr("Cancel"), QMessageBox::NoRole);
    btnCancel->setIcon(QIcon::fromTheme("window-close"));

    msgBox.exec();

    if (msgBox.clickedButton() == btnLicense) {
        displayDoc(licence_url, license_title, runned_as_root);
    } else if (msgBox.clickedButton() == btnChangelog) {
        QDialog *changelog = new QDialog();
        changelog->setWindowTitle(QApplication::tr("Changelog"));
        changelog->resize(600, 500);

        QTextEdit *text = new QTextEdit;
        text->setReadOnly(true);
        Cmd cmd;
        text->setText(cmd.getCmdOut("zless /usr/share/doc/" + QFileInfo(QCoreApplication::applicationFilePath()).fileName() + "/changelog.gz"));

        QPushButton *btnClose = new QPushButton(QApplication::tr("&Close"));
        btnClose->setIcon(QIcon::fromTheme("window-close"));
        QApplication::connect(btnClose, &QPushButton::clicked, changelog, &QDialog::close);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(text);
        layout->addWidget(btnClose);
        changelog->setLayout(layout);
        changelog->exec();
        delete changelog;
    }
}
