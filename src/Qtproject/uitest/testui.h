/**
 * @author  Created by xzy on 2024/5/12
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/

#ifndef CMAKE_PROJECT_TEMPLATE_TESTUI_H
#define CMAKE_PROJECT_TEMPLATE_TESTUI_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Testui; }
QT_END_NAMESPACE

class Testui : public QMainWindow {
Q_OBJECT

public:
    explicit Testui(QWidget *parent = nullptr);

    ~Testui() override;

private:
    Ui::Testui *ui;
};


#endif //CMAKE_PROJECT_TEMPLATE_TESTUI_H
