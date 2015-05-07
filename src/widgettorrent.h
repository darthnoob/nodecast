#ifndef WIDGETTORRENT_H
#define WIDGETTORRENT_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include <QImageReader>
#include <QMimeDatabase>
#include <QDesktopServices>

//#include "torrentpersistentdata.h"
#include "qtorrenthandle.h"
#include "qbtsession.h"
#include "global.h"

namespace Ui {
class widgettorrent;
}


struct Torrent_data {
    QString file="";
    QString type="";
    qint64 size=0;
};


class Widgettorrent : public QWidget
{
    Q_OBJECT

public:
    explicit Widgettorrent(Sphere_data a_sphere_data);
    ~Widgettorrent();    
    static void populate(Sphere_data a_sphere_data, QLayout *parent = 0);
    static void unckeck_widget_selected(Widgettorrent *wt);

    Sphere_data sphere_data;
    Torrent_data torrent_data;


protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);


signals:
    void emit_title();

private:
    void update_torrent_type_thumbnail();
    QTorrentHandle m_torrent;
    Ui::widgettorrent *ui;
    QPixmap *myPix;
    QLabel m_title;
    QLabel m_thumbnail;

    int mFirstX;
    int mFirstY;

    QProcess *videoPlayer;
    QTimer *timer_get_torrent_progress;
    QMimeDatabase m_mime_db;

private slots:
    void on_media_doubleClicked();
    void update_timer_torrent_progress();

public slots:
    void addTorrent(const QTorrentHandle &h);
};

#endif // WIDGETTORRENT_H
