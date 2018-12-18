/********************************************************************************
** Form generated from reading UI file 'commandwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDWINDOW_H
#define UI_COMMANDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *buttonsLayout;
    QPushButton *sendButton;
    QPushButton *checkButton;
    QPushButton *statButton;
    QPushButton *deleteButton;
    QPushButton *receiveButton;
    QPushButton *cleanButton;
    QPushButton *logoutButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *textLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CommandWindow)
    {
        if (CommandWindow->objectName().isEmpty())
            CommandWindow->setObjectName(QStringLiteral("CommandWindow"));
        CommandWindow->resize(800, 288);
        centralwidget = new QWidget(CommandWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 91, 231));
        buttonsLayout = new QVBoxLayout(verticalLayoutWidget);
        buttonsLayout->setSpacing(0);
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        buttonsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(verticalLayoutWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        buttonsLayout->addWidget(sendButton);

        checkButton = new QPushButton(verticalLayoutWidget);
        checkButton->setObjectName(QStringLiteral("checkButton"));

        buttonsLayout->addWidget(checkButton);

        statButton = new QPushButton(verticalLayoutWidget);
        statButton->setObjectName(QStringLiteral("statButton"));

        buttonsLayout->addWidget(statButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        buttonsLayout->addWidget(deleteButton);

        receiveButton = new QPushButton(verticalLayoutWidget);
        receiveButton->setObjectName(QStringLiteral("receiveButton"));

        buttonsLayout->addWidget(receiveButton);

        cleanButton = new QPushButton(verticalLayoutWidget);
        cleanButton->setObjectName(QStringLiteral("cleanButton"));

        buttonsLayout->addWidget(cleanButton);

        logoutButton = new QPushButton(verticalLayoutWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));

        buttonsLayout->addWidget(logoutButton);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(110, 10, 661, 231));
        textLayout = new QVBoxLayout(verticalLayoutWidget_2);
        textLayout->setObjectName(QStringLiteral("textLayout"));
        textLayout->setContentsMargins(0, 0, 0, 0);
        CommandWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CommandWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        CommandWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CommandWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CommandWindow->setStatusBar(statusbar);

        retranslateUi(CommandWindow);

        QMetaObject::connectSlotsByName(CommandWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CommandWindow)
    {
        CommandWindow->setWindowTitle(QApplication::translate("CommandWindow", "MainWindow", 0));
        sendButton->setText(QApplication::translate("CommandWindow", "Send", 0));
        checkButton->setText(QApplication::translate("CommandWindow", "Check", 0));
        statButton->setText(QApplication::translate("CommandWindow", "Stat", 0));
        deleteButton->setText(QApplication::translate("CommandWindow", "Delete", 0));
        receiveButton->setText(QApplication::translate("CommandWindow", "Receive", 0));
        cleanButton->setText(QApplication::translate("CommandWindow", "Clean", 0));
        logoutButton->setText(QApplication::translate("CommandWindow", "Logout", 0));
    } // retranslateUi

};

namespace Ui {
    class CommandWindow: public Ui_CommandWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDWINDOW_H
