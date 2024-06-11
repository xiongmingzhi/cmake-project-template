/**
 * @author  Created by xzy on 2024/5/12
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/

// You may need to build the project (run Qt uic code generator) to get "ui_Testui.h" resolved

#include "testui.h"
#include "ui_Testui.h"


Testui::Testui(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Testui) {
    ui->setupUi(this);
}

Testui::~Testui() {
    delete ui;
}
