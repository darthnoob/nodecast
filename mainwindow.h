#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QSettings>
#include <QDir>
#include <QProcess>
#include <QFileDialog>
#include <QThread>
#include <QTimer>
#include <QPainter>
#include <QRadioButton>
#include <QScrollArea>
#include <QList>
#include <QIcon>
#include <QStaticText>
#include <QStackedWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHash>

#include "video.h"
#include "preferences.h"
#include "torrent.h"
#include "qbtsession.h"
#include "openuritorrent.h"
#include "downloadfromurldlg.h"
#include "widgettorrent.h"
#include "options_imp.h"
#include "transferlistfilterswidget.h"
#include "torrentpersistentdata.h"
#include "flowlayout.h"
#include "about_imp.h"
#include "account.h"
#include "newsphere.h"
#include "godcast_api.h"
#include "sphere.h"

#ifdef Q_OS_MAC
void fixNativeWindow( QMainWindow *window );
void minaturize( QMainWindow *window );
#endif


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:


protected slots:
    void loadPreferences(bool configure_session=true);
    void optionsSaved();
    void on_actionAbout_triggered();
    void processDownloadedFiles(QString path, QString url);
    void downloadFromURLList(const QStringList& urls);



private slots:
    void create_sphere(QString sphere_name);
    void addTorrent(const QTorrentHandle &h);

    void shutdownCleanUp();

    void on_actionQuit_triggered();

    void on_actionOpen_triggered();

    void on_actionPreferences_triggered();

    void on_pushButton_clicked();

    void on_listWidget_media_doubleClicked(const QModelIndex &index);

    void on_pushButton_play_clicked();

    void on_pushButton_torrent_info_clicked();


    void launch_timer_handle(QTorrentHandle h);
    void update_timer_torrent_progress();


    void on_pushButton_spherenew_clicked();


    void on_media_doubleClicked(QString title);


    void on_actionAccount_triggered();

    void refresh_spheres(QVariantMap sphere);


    void changePage(int current);


private:
    void populate();

    QStackedWidget *m_stacked_tab_medias;

    QPointer<about> aboutDlg;
    QPointer<newsphere> new_sphere;

    QPointer<account> accountDlg;
    QScrollArea *media_scroll;
    QWidget *media_container;
   // FlowLayout *flowLayout;

    QList <Widgettorrent*> list_torrents;

    QPointer<options_imp> options;
    TransferListWidget *transferList;
    TransferListFiltersWidget *transferListFilters;
    QSplitter *hSplitter;
    QSplitter *vSplitter;

    QList<Sphere *> m_spheres_private;
    QList<Sphere *> m_spheres_public;
    QHash<int, Sphere *> sphere_tab;

    QThread *thread_torrent;
    Torrent *torrent;
    QTimer *timer_get_torrent_progress;
    QTimer *timer_set_torrent_progress;

    QSettings settings;
    Ui::MainWindow *ui;
    Video video;
    Preferences prefs;
    QProcess *videoPlayer;
    Openuritorrent openuritorrent;
    int torrent_index;
    QTorrentHandle m_torrent;
    QPointer<downloadFromURL> downloadFromURLDialog;

   QPointer<Widgettorrent> widgettorrentThumbnail;

   Godcast_api *m_godcastapi;
};

#endif // MAINWINDOW_H