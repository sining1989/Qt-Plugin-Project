/********************************************************************************
** Form generated from reading UI file 'DemoLibraryA.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOLIBRARYA_H
#define UI_DEMOLIBRARYA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PluginA
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton2;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QWidget *PluginA)
    {
        if (PluginA->objectName().isEmpty())
            PluginA->setObjectName(QStringLiteral("PluginA"));
        PluginA->resize(400, 300);
        pushButton = new QPushButton(PluginA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 29, 75, 23));
        pushButton2 = new QPushButton(PluginA);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(0, 0, 86, 23));
        label = new QLabel(PluginA);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 58, 461, 251));
        pushButton_2 = new QPushButton(PluginA);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 30, 75, 23));
        label_2 = new QLabel(PluginA);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 270, 54, 12));

        retranslateUi(PluginA);

        QMetaObject::connectSlotsByName(PluginA);
    } // setupUi

    void retranslateUi(QWidget *PluginA)
    {
        PluginA->setWindowTitle(QApplication::translate("PluginA", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PluginA", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("PluginA", "\350\260\203\347\224\250B\346\217\222\344\273\266\345\212\250\347\224\273", Q_NULLPTR));
        label->setText(QApplication::translate("PluginA", "TextLabel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PluginA", "\345\217\221\345\220\221\344\270\273\347\250\213\345\272\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("PluginA", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PluginA: public Ui_PluginA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOLIBRARYA_H
