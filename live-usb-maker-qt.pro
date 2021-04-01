# **********************************************************************
# * Copyright (C) 2017 MX Authors
# *
# * Authors: Adrian
# *          MX Linux <http://mxlinux.org>
# *
# * This is free software: you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation, either version 3 of the License, or
# * (at your option) any later version.
# *
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# *
# * You should have received a copy of the GNU General Public License
# * along with this package. If not, see <http://www.gnu.org/licenses/>.
# **********************************************************************/

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = usr/bin/live-usb-maker-qt
TEMPLATE = app


SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/cmd.cpp \
    src/about.cpp

HEADERS  += \
    src/mainwindow.h \
    src/version.h \
    src/cmd.h \
    src/about.h

FORMS    += \
    src/mainwindow.ui

TRANSLATIONS += translations/live-usb-maker-qt_am.ts \
                translations/live-usb-maker-qt_ar.ts \
                translations/live-usb-maker-qt_bg.ts \
                translations/live-usb-maker-qt_ca.ts \
                translations/live-usb-maker-qt_cs.ts \
                translations/live-usb-maker-qt_da.ts \
                translations/live-usb-maker-qt_de.ts \
                translations/live-usb-maker-qt_el.ts \
                translations/live-usb-maker-qt_es.ts \
                translations/live-usb-maker-qt_et.ts \
                translations/live-usb-maker-qt_eu.ts \
                translations/live-usb-maker-qt_fa.ts \
                translations/live-usb-maker-qt_fi.ts \
                translations/live-usb-maker-qt_fr.ts \
                translations/live-usb-maker-qt_he_IL.ts \
                translations/live-usb-maker-qt_hi.ts \
                translations/live-usb-maker-qt_hr.ts \
                translations/live-usb-maker-qt_hu.ts \
                translations/live-usb-maker-qt_id.ts \
                translations/live-usb-maker-qt_is.ts \
                translations/live-usb-maker-qt_it.ts \
                translations/live-usb-maker-qt_ja.ts \
                translations/live-usb-maker-qt_kk.ts \
                translations/live-usb-maker-qt_ko.ts \
                translations/live-usb-maker-qt_lt.ts \
                translations/live-usb-maker-qt_mk.ts \
                translations/live-usb-maker-qt_mr.ts \
                translations/live-usb-maker-qt_nb.ts \
                translations/live-usb-maker-qt_nl.ts \
                translations/live-usb-maker-qt_pl.ts \
                translations/live-usb-maker-qt_pt.ts \
                translations/live-usb-maker-qt_pt_BR.ts \
                translations/live-usb-maker-qt_ro.ts \
                translations/live-usb-maker-qt_ru.ts \
                translations/live-usb-maker-qt_sk.ts \
                translations/live-usb-maker-qt_sl.ts \
                translations/live-usb-maker-qt_sq.ts \
                translations/live-usb-maker-qt_sr.ts \
                translations/live-usb-maker-qt_sv.ts \
                translations/live-usb-maker-qt_tr.ts \
                translations/live-usb-maker-qt_uk.ts \
                translations/live-usb-maker-qt_zh_CN.ts \
                translations/live-usb-maker-qt_zh_TW.ts

RESOURCES += \
    src/images.qrc

