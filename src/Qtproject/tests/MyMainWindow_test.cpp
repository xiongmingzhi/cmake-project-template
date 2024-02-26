#include <QApplication>
#include <QPushButton>
#include <QVector>
#include <vector>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QSpinBox>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QScrollBar>
#include <QTreeWidget>
#include <QTableWidget>
#include <any>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <src/Qtproject/MyMainWindow.h>

template<class T>
void httpProcess(T&httpClass, const std::string url){
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("https://example.com/api"));
    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, httpClass, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            // 对响应数据进行处理
        } else {
            // 处理错误响应
            QString errorString = reply->errorString();
            // 处理错误信息
        }
        reply->deleteLater(); // 释放网络响应对象
    });
}




int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("Qt test");
    //创建一个垂直布局器
    QVBoxLayout *mainLayout = new QVBoxLayout(&w);
    //第一行
    QGroupBox* groupBox = new QGroupBox("文本");    //QGroupBox
    //label的使用
    QHBoxLayout* hlayout = new QHBoxLayout();
    //QGroupBox
    QPushButton* button = new QPushButton("显示文本");//QPUshbutton
    hlayout->addWidget(button, 0, Qt::AlignCenter);
    QLabel* label = new QLabel("hello, world");
    hlayout->addWidget(label, 0, Qt::AlignCenter);
    QString str = label->text();
    //QcheckBox
    QCheckBox* checkBox = new QCheckBox("选项");
    checkBox->setChecked(false);
    hlayout->addWidget(checkBox);
    //QspinBox
    QSpinBox* spinBox = new QSpinBox();
    spinBox->setRange(0, 50);
    spinBox->setValue(37);
    spinBox->setSingleStep(1);
    spinBox->setSuffix(" F");
    hlayout->addWidget(spinBox);


    // 第二行：QlineEdit的使用
    QHBoxLayout *topLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("Title:");
    QLineEdit *lineEdit = new QLineEdit("今晚很美！");
    //topLayout->addStretch();
    topLayout->addWidget(titleLabel);
    topLayout->addWidget(lineEdit);

    //Qcombox
    QComboBox* comboBox = new QComboBox();
    QStringList Qlist;
    Qlist << "晴天" << "阴天" << "小雨" << "大雨";
    comboBox->addItems(Qlist);
    QString text = comboBox->currentText();
    int index = comboBox->currentIndex();
    topLayout->addWidget(comboBox);

    //第三行 QTbalewidget
    QHBoxLayout *secondLayout = new QHBoxLayout();
    QTreeWidget* treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(2);
    treeWidget->setHeaderLabels(QStringList() << "Name" << "value");
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setText(0, "root");
    QTreeWidgetItem *child1 = new QTreeWidgetItem(root);
    child1->setText(0, "Child 1");
    child1->setText(1, "Value 1");

    QTreeWidgetItem *child2 = new QTreeWidgetItem(root);
    child2->setText(0, "Child 2");
    child2->setText(1, "Value 2");
    secondLayout->addWidget(treeWidget);

    //tableWidget
    QTableWidget* tableWidget = new QTableWidget();
    tableWidget->setWindowTitle("Qtabale example");
    tableWidget->setRowCount(3);
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Value");//设置表头
    tableWidget->setItem(0, 0, new QTableWidgetItem("Item 1"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("Value 1"));
    tableWidget->setItem(1, 0, new QTableWidgetItem("Item 2"));
    tableWidget->setItem(1, 1, new QTableWidgetItem("Value 2"));
    tableWidget->setItem(2, 0, new QTableWidgetItem("Item 3"));
    tableWidget->setItem(2, 1, new QTableWidgetItem("Value 3"));
    secondLayout->addWidget(tableWidget);


    //创建一个进度条
    QProgressBar* progressBar = new QProgressBar();
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setOrientation(Qt::Horizontal);

    groupBox->setLayout(hlayout);
    mainLayout->addWidget(groupBox);//groupBox有点像
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addWidget(progressBar);

    w.setLayout(mainLayout);
    w.setGeometry(400, 200, 800, 400);
    w.show();
//    MyMainWindow mainWindow;
//    mainWindow.show();
    return QApplication::exec();
}

