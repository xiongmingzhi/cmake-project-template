/**
 * @author  Created by xzy on 2024/5/12
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/

#ifndef CMAKE_PROJECT_TEMPLATE_VGRIBBONWINDOW_H
#define CMAKE_PROJECT_TEMPLATE_VGRIBBONWINDOW_H

#include <QMainWindow>
#include "ui_vgribbonwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class VgribbonWindow; }
QT_END_NAMESPACE

class VgribbonWindow : public QMainWindow {
Q_OBJECT

public:
    explicit VgribbonWindow(QWidget *parent = nullptr);

    ~VgribbonWindow() override;

private:
    Ui::VGRibbonWindow* ui;
};


#endif //CMAKE_PROJECT_TEMPLATE_VGRIBBONWINDOW_H
