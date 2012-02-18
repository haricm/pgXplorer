TEMPLATE	= app
TARGET		= pgXplorer

CONFIG		+= qt warn_on

HEADERS		= \
    database.h \
    table.h \
    pgxconsole.h \
    queryview.h \
    querymodel.h \
    connectionproperties.h \
    pgxeditor.h \
    function.h \
    functionlink.h \
    view.h \
    highlighter.h \
    licensedialog.h \
    tableview.h \
    tablelink.h \
    schema.h \
    newtableview.h \
    mainwin.h \
    schemalink.h \
    tablemodel.h \
    viewview.h \
    help.h
SOURCES		= main.cpp \
    database.cpp \
    table.cpp \
    pgxconsole.cpp \
    queryview.cpp \
    querymodel.cpp \
    connectionproperties.cpp \
    pgxeditor.cpp \
    function.cpp \
    functionlink.cpp \
    view.cpp \
    highlighter.cpp \
    licensedialog.cpp \
    newtableview.cpp \
    mainwin.cpp \
    schemalink.cpp \
    schema.cpp \
    tableview.cpp \
    tablelink.cpp \
    tablemodel.cpp \
    viewview.cpp \
    help.cpp
QT += sql translator

RESOURCES += pgXplorer.qrc

TRANSLATIONS = pgXplorer_ja.ts \
               pgXplorer_fr.ts \
               qt_ja.ts

RC_FILE = pgXplorer.rc

CODECFORTR = UTF-8

# install
target.path = C:/QtSDK/Examples/4.7/graphicsview/pgXplorer
sources.files = $$SOURCES $$HEADERS $$RESOURCES pgXplorer.pro
sources.path = C:/QtSDK/Examples/4.7/graphicsview/pgXplorer
INSTALLS += target sources

OTHER_FILES += \
    pgXplorer.rc




































































