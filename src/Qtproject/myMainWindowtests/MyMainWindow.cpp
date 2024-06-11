/**
 * @author  Created by xzy on 2023/12/11
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/

#include "MyMainWindow.h"
#include <QMenu>

void MyMainWindow::createMenue() {
    //创建菜单栏
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    //创建File菜单并且添加动作
    QMenu* fileMenu = menuBar->addMenu(tr("File"));

    //添加动作
    QAction *newAction = new QAction(tr("New"), this);
    QAction *openAction = new QAction(tr("Open"), this);
    QAction *exitAction = new QAction(tr("Exit"), this);
    fileMenu->addActions(QList<QAction*>() << newAction<< openAction << exitAction);
    //槽函数
    connect(newAction, &QAction::triggered, this, &MyMainWindow::newFile);
    connect(openAction, &QAction::triggered, this, &MyMainWindow::openFile);
    connect(exitAction, &QAction::triggered, this, &MyMainWindow::close);

    //添加Edit 菜单
    QMenu* editMenu = menuBar->addMenu(tr("Edit"));
    QAction *cutAction = new QAction(tr("Cut"), this);
    QAction *copyAction = new QAction(tr("Copy"), this);
    QAction *pasteAction = new QAction(tr("Paste"), this);
    editMenu->addActions(QList<QAction*>() << cutAction<< copyAction << pasteAction);
    //槽函数
    connect(cutAction, &QAction::triggered, this, &MyMainWindow::cutText);
    connect(copyAction, &QAction::triggered, this, &MyMainWindow::copyText);
    connect(pasteAction, &QAction::triggered, this, &MyMainWindow::pasteText);

}

void MyMainWindow::createToolBar()
{
}



void MyMainWindow::newFile() {

}

void MyMainWindow::openFile() {

}

void MyMainWindow::exitApp() {

}

void MyMainWindow::cutText() {

}
void MyMainWindow::copyText() {

}

void MyMainWindow::pasteText() {

}


