#ifndef GAMEROW_H
#define GAMEROW_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

#include "appcontroller.h"
#include "objects/game.h"

namespace Ui
{
class GameRow;
}

class GameRow : public QWidget
{
    Q_OBJECT

public:
    explicit GameRow(QWidget* const parent, const Game& game, const DownloadKey& key, AppController* const controller);
    ~GameRow();

    static const int COVER_HEIGHT = 80;

private slots:
    void onClickDownload();
    void onDownloadThumbnail();
    void onTriggerDownloadMenu();
    void onTriggerUpload();
    void onUploads(const QList<Upload>& uploads);

private:
    QNetworkAccessManager* networkManager;

    Game game;
    DownloadKey downloadKey;
    AppController* const controller;

    QLabel* imageHolder;
    QProgressBar* downloadProgress;
    QPushButton* downloadButton;
    QMenu* downloadMenu;

    QList<Upload> pendingUploads;

    void refreshThumbnail();
};

#endif // GAMEROW_H
