CONFIG += debug

SOURCES += gail.cpp

Debug:DESTDIR = build
Release:DESTDIR = release/linux

TARGET = gail

# Additional files
DISTFILES += \
    .gitignore \
    _todo.txt

