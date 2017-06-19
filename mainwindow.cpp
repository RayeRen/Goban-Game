#if _MSC_VER >= 1600    // VC2010
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>
#include <QMouseEvent>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent) {
    setWindowFlags(Qt::WindowMinimizeButtonHint);
    setFixedSize(485, 600);
    // chessboard 490 557
    setWindowTitle(tr("��������Ϸ"));

    humanPlayAction = new QAction("˫����Ϸ", this);
    humanPlayAction->setShortcuts(QKeySequence::New); // Ctrl+N
    connect(humanPlayAction, &QAction::triggered, this, &MainWindow::startHuman);

    AIPlayAction = new QAction("�˻���ս", this);
    AIPlayAction->setShortcuts(QKeySequence::SelectAll); // Ctrl+A
    connect(AIPlayAction, &QAction::triggered, this, &MainWindow::startAI);

    QMenu *file = menuBar()->addMenu(tr("&��ʼ"));
    file->addAction(humanPlayAction);
    file->addAction(AIPlayAction);

    QToolBar *toolBar = addToolBar(tr("&��ʼ"));
    toolBar->addAction(humanPlayAction);
    toolBar->addAction(AIPlayAction);

    setStyleSheet("QMainWindow {"
                          "background-image: url(:/images/chessBoard);"
                          "background-repeat:no-repeat;"
                          "background-position: bottom left"
                          "}");
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    float width = 32.2;
    float chessWidth = 0.95 * width;
    float topX = 17.f - width / 2 + (width - chessWidth) / 2;
    float topY = 107.f - width / 2 + (width - chessWidth) / 2;
    float cx = e->x() - topX, cy = e->y() - topY - width;
    int ccx = cx / width, ccy = cy / width;
    if (cx > ccx * width + chessWidth || cy > ccy * width + chessWidth) { return; }
    cc->nextStep(ccx, ccy);
    update();
}

void MainWindow::startHuman() {
    QMessageBox::information(this, tr("Information"), tr("��ʼ˫����Ϸ"));
    cc->startGame(false);
}

void MainWindow::startAI() {
    QMessageBox::information(this, tr("Information"), tr("��ʼ�˻���ս"));
    cc->startGame(true);
}

MainWindow::~MainWindow() {
}
