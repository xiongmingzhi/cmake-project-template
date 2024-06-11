/**
 * @author  Created by xzy on 2024/5/5
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <QApplication>
#include "vgribbonwindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
    VgribbonWindow vgr_test;
    vgr_test.show();
    app.exec();
}