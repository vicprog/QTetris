TARGET = GTest

QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    ../QTetris/Tetris.cpp \
    ../QTetris/CreateFigure.cpp \
    ../QTetris/Figure.cpp \
    ../QTetris/Element.cpp \
    ../QTetris/FigureMove.cpp \
    main.cpp \
    test_tetris.cpp \
    test_createFigure.cpp \
    test_figureMove.cpp


HEADERS += \
    GTest.h \
    Tetris.h \
    mock_random.h \
    mock_tetris.h

INCLUDEPATH +=  \
    ../QTetris

LIBS += \
   /usr/lib/libgtest.so \
    /usr/lib/libgmock.so



