#include <QDebug>
#include <QEventLoop>

#include "cmd.h"

Cmd::Cmd(QObject *parent) : QProcess(parent) {}

void Cmd::halt() {
    if (state() != QProcess::NotRunning) {
        terminate();
        waitForFinished(5000);
        kill();
        waitForFinished(1000);
    }
}

bool Cmd::run(const QString &cmd, bool quiet) {
    QByteArray output;
    return run(cmd, output, quiet);
}

// Util function for getting bash command output
QString Cmd::getCmdOut(const QString &cmd, bool quiet) {
    QByteArray output;
    run(cmd, output, quiet);
    return output;
}

bool Cmd::run(const QString &cmd, QByteArray &output, bool quiet) {
    if (this->state() != QProcess::NotRunning) {
        qDebug() << "Process already running:" << this->program() << this->arguments();
        return false;
    }
    if (!quiet) qDebug().noquote() << cmd;
    QEventLoop loop;
    connect(this, static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            &loop, &QEventLoop::quit);
    start("/bin/bash", QStringList() << "-c" << cmd);
    loop.exec();
    disconnect(this, static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
               nullptr, nullptr);
    output = readAll().trimmed();
    return (exitStatus() == QProcess::NormalExit && exitCode() == 0);
}
