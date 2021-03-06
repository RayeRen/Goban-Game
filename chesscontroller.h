﻿#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include <vector>
#include "realboard.h"
#include "chessitem.h"
#include "virtualboard.h"
#include "AI.h"

class ChessController :public QObject {
Q_OBJECT
public:
    ChessController(RealBoard &cb) : cb(cb), curChessBoard(cb.getChessBoard()),virtualBoard(WHITE) {
    }
    void startGame(bool isAIPlayer);
    void nextStep(int cx, int cy);
    ChessItem AIgo();

private:
    RealBoard &cb;
    const std::vector<std::vector<ItemType >>& curChessBoard;
    VirtualBoard virtualBoard;
    bool judge();
    int judgeSingleDirect(int dx, int dy) const;

    ChessItem nextStepItem;
    ItemType currentPlayer = BLACK; // 1p=1 or 2p=0  default 1p;
    int stepCnt;
    bool isAIPlayer = false; // default no AI
    bool isPlaying = false;
};

#endif // CHESSCONTROLLER_H
