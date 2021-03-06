INCLUDEPATH += $$PWD

FORMS += $$PWD/xmlConsoleDialog.ui \
    xmpp/statusWidget.ui \
    xmpp/roster.ui \
    $$PWD/profileDialog.ui

HEADERS += $$PWD/xmpp_client.h \
           $$PWD/xmlConsoleDialog.h \
    xmpp/capabilitiesCache.h \
    xmpp/utils.h \
    xmpp/vCardCache.h \
    xmpp/rosterItem.h \
    xmpp/rosterItemModel.h \
    xmpp/rosterItemSortFilterProxyModel.h \
    xmpp/rosterListView.h \
    xmpp/searchLineEdit.h \
    xmpp/statusWidget.h \
    xmpp/statusAvatarWidget.h \
    xmpp/statusTextWidget.h \
    xmpp/statusToolButton.h \
    $$PWD/profileDialog.h \
    $$PWD/chatGraphicsScene.h \
    $$PWD/chatGraphicsView.h \
    $$PWD/chatMsgGraphicsItem.h

SOURCES += $$PWD/xmpp_client.cpp \
           $$PWD/xmlConsoleDialog.cpp \
    xmpp/capabilitiesCache.cpp \
    xmpp/utils.cpp \
    xmpp/vCardCache.cpp \
    xmpp/rosterItem.cpp \
    xmpp/rosterItemModel.cpp \
    xmpp/rosterItemSortFilterProxyModel.cpp \
    xmpp/rosterListView.cpp \
    xmpp/searchLineEdit.cpp \
    xmpp/statusWidget.cpp \
    xmpp/statusAvatarWidget.cpp \
    xmpp/statusTextWidget.cpp \
    xmpp/statusToolButton.cpp \
    $$PWD/profileDialog.cpp \
    $$PWD/chatGraphicsScene.cpp \
    $$PWD/chatGraphicsView.cpp \
    $$PWD/chatMsgGraphicsItem.cpp

RESOURCES += \
    xmpp/xmpp.qrc

