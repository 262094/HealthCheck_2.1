QT       += core gui webenginecore webenginewidgets sql network



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bmi.cpp \
    diet.cpp \
    exercises.cpp \
    kcal.cpp \
    liczeniebmi.cpp \
    liczeniekcal.cpp \
    liczeniewhr.cpp \
    main.cpp \
    healtcheck.cpp \
    whr.cpp

HEADERS += \
    bmi.h \
    diet.h \
    exercises.h \
    healtcheck.h \
    kcal.h \
    liczeniebmi.h \
    liczeniekcal.h \
    liczeniewhr.h \
    whr.h

FORMS += \
    bmi.ui \
    diet.ui \
    exercises.ui \
    healtcheck.ui \
    kcal.ui \
    whr.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Check.qrc \
    photo.qrc
