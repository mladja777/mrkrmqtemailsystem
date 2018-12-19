/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *mailLabel;
    QLineEdit *emailEntry;
    QLabel *passwordLabel;
    QLineEdit *passwordEntry;
    QPushButton *runServerButton;
    QPushButton *runClientButton;
    QLabel *serverLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_4;
    QPushButton *sendButton;
    QPushButton *checkButton;
    QPushButton *statButton;
    QPushButton *deleteButton;
    QPushButton *cleanButton;
    QPushButton *receiveButton;
    QSpacerItem *verticalSpacer;
    QPushButton *logoutButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *dstMailEntry;
    QLabel *label_2;
    QTextEdit *messageEntry;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(778, 313);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mailLabel = new QLabel(centralWidget);
        mailLabel->setObjectName(QStringLiteral("mailLabel"));

        verticalLayout->addWidget(mailLabel);

        emailEntry = new QLineEdit(centralWidget);
        emailEntry->setObjectName(QStringLiteral("emailEntry"));
        emailEntry->setEnabled(false);

        verticalLayout->addWidget(emailEntry);

        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        verticalLayout->addWidget(passwordLabel);

        passwordEntry = new QLineEdit(centralWidget);
        passwordEntry->setObjectName(QStringLiteral("passwordEntry"));
        passwordEntry->setEnabled(false);

        verticalLayout->addWidget(passwordEntry);


        verticalLayout_3->addLayout(verticalLayout);

        runServerButton = new QPushButton(centralWidget);
        runServerButton->setObjectName(QStringLiteral("runServerButton"));

        verticalLayout_3->addWidget(runServerButton);

        runClientButton = new QPushButton(centralWidget);
        runClientButton->setObjectName(QStringLiteral("runClientButton"));

        verticalLayout_3->addWidget(runClientButton);

        serverLabel = new QLabel(centralWidget);
        serverLabel->setObjectName(QStringLiteral("serverLabel"));
        serverLabel->setEnabled(true);

        verticalLayout_3->addWidget(serverLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setEnabled(false);

        horizontalLayout->addWidget(loginButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setEnabled(true);

        horizontalLayout->addWidget(exitButton);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(false);
        textBrowser->setFrameShape(QFrame::StyledPanel);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setReadOnly(true);
        textBrowser->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(textBrowser);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setEnabled(false);

        verticalLayout_4->addWidget(sendButton);

        checkButton = new QPushButton(centralWidget);
        checkButton->setObjectName(QStringLiteral("checkButton"));
        checkButton->setEnabled(false);

        verticalLayout_4->addWidget(checkButton);

        statButton = new QPushButton(centralWidget);
        statButton->setObjectName(QStringLiteral("statButton"));
        statButton->setEnabled(false);

        verticalLayout_4->addWidget(statButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);

        verticalLayout_4->addWidget(deleteButton);

        cleanButton = new QPushButton(centralWidget);
        cleanButton->setObjectName(QStringLiteral("cleanButton"));
        cleanButton->setEnabled(false);

        verticalLayout_4->addWidget(cleanButton);

        receiveButton = new QPushButton(centralWidget);
        receiveButton->setObjectName(QStringLiteral("receiveButton"));
        receiveButton->setEnabled(false);

        verticalLayout_4->addWidget(receiveButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        logoutButton = new QPushButton(centralWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setEnabled(false);

        verticalLayout_4->addWidget(logoutButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        dstMailEntry = new QLineEdit(centralWidget);
        dstMailEntry->setObjectName(QStringLiteral("dstMailEntry"));

        verticalLayout_2->addWidget(dstMailEntry);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        messageEntry = new QTextEdit(centralWidget);
        messageEntry->setObjectName(QStringLiteral("messageEntry"));

        verticalLayout_2->addWidget(messageEntry);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 778, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        mailLabel->setText(QApplication::translate("MainWindow", "Enter your e-mail:", 0));
        passwordLabel->setText(QApplication::translate("MainWindow", "Enter you password:", 0));
        runServerButton->setText(QApplication::translate("MainWindow", "Run server", 0));
        runClientButton->setText(QApplication::translate("MainWindow", "Run client", 0));
        serverLabel->setText(QString());
        loginButton->setText(QApplication::translate("MainWindow", "LOGIN", 0));
        exitButton->setText(QApplication::translate("MainWindow", "EXIT", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        checkButton->setText(QApplication::translate("MainWindow", "Check", 0));
        statButton->setText(QApplication::translate("MainWindow", "Stat", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        cleanButton->setText(QApplication::translate("MainWindow", "Clean", 0));
        receiveButton->setText(QApplication::translate("MainWindow", "Receive", 0));
        logoutButton->setText(QApplication::translate("MainWindow", "LOGOUT", 0));
        label->setText(QApplication::translate("MainWindow", "To:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Message:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
