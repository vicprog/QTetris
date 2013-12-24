#-------------------------------------------------
#
# Project created by QtCreator 2013-12-11T21:48:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTetris
TEMPLATE = app


SOURCES += main.cpp\
        QTerris.cpp \
    Tetris.cpp \
    CreateFigure.cpp \
    Figure.cpp \
    Element.cpp \
    Random.cpp \
    FigureMove.cpp

HEADERS  += QTerris.h \
    Tetris.h \
    IController.h \
    ITimer.h \
    CreateFigure.h \
    IRandom.h \
    Figure.h \
    Element.h \
    Random.h \
    FigureMove.h \
    ITetris.h
