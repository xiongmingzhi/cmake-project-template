/**
 * @author  Created by xzy on 2023/12/11
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/

#ifndef UNTITLED_MYMAINWINDOW_H
#define UNTITLED_MYMAINWINDOW_H
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MyMainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MyMainWindow(QWidget* parent = nullptr): QMainWindow(parent){
        createMenue();
        createToolBar();
    }
private:
    void createMenue();
    void createToolBar();

private slots:
    void newFile();
    void openFile();
    void exitApp();
    void cutText();
    void copyText();
    void pasteText();


};


#endif //UNTITLED_MYMAINWINDOW_H
