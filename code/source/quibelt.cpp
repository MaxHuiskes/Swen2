#include "quibelt.h"

QUIBelt::QUIBelt(QWidget *parent)
    : QWidget(parent)
    , mLabel(this)
{
    mLabel.setText("hallo");
    //this->setBackgroundRole(QPalette::Shadow);
    this->setWindowTitle("hallo");
//    this->
}
