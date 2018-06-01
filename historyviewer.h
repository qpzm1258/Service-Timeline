#ifndef HISTORYVIEWER_H
#define HISTORYVIEWER_H

#include <QWidget>
#include <QNetworkReply>

namespace Ui {
class HistoryViewer;
}

class HistoryViewer : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryViewer(QWidget *parent = 0);
    ~HistoryViewer();
    void SetHandlePhoto(QPixmap pixmap);
    void SetTransactorCardImage(QPixmap pixmap);
    void SetAgentCardImage(QPixmap pixmap);
    void SetHandlePhotoURL(QString url);
    void SetTransactorCardImageURL(QString url);
    void SetAgentCardImageURL(QString url);
    void Clear();

public slots:
    void replyFinishedHandle(QNetworkReply *reply);
    void replyFinishedTransactor(QNetworkReply *reply);
    void replyFinishedAgent(QNetworkReply *reply);

private:
    Ui::HistoryViewer *ui;
};

#endif // HISTORYVIEWER_H
