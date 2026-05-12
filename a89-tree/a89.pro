QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/domain/Movie.cpp \
    src/helpers/Helpers.cpp \
    src/helpers/RepoOutput.cpp \
    src/main.cpp \
    src/repo/CSV.repo.cpp \
    src/repo/HTML.repo.cpp \
    src/repo/Memory.repo.cpp \
    src/repo/TextFile.repo.cpp \
    src/services/Movie.services.cpp \
    src/ui/Menu.gui.cpp \
    src/ui/Menu.ui.cpp \
    src/ui/Menu.ui.input.cpp \
    src/ui/Menu.ui.output.cpp

HEADERS += \
    src/domain/Movie.h \
    src/exceptions/MovieServicesException.h \
    src/exceptions/RepoException.h \
    src/helpers/Helpers.h \
    src/helpers/RepoOutput.h \
    src/repo/CSV.repo.h \
    src/repo/HTML.repo.h \
    src/repo/Memory.repo.h \
    src/repo/Repo.repo.h \
    src/repo/TextFile.repo.h \
    src/services/Movie.services.h \
    src/ui/Menu.gui.h \
    src/ui/Menu.ui.h \
    src/ui/Menu.ui.input.h \
    src/ui/Menu.ui.output.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/repo/data/movies.txt \
    src/repo/data/playlist.txt \
    src/repo/output/movies.html \
    src/repo/output/playlist.html \
    src/uml.drawio
