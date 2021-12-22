<<<<<<< HEAD
#include "quibelt.h"

QUIBelt::QUIBelt(QWidget *parent)
    : QWidget(parent)
    , mLabel(this)
{
    mLabel.setText("hallo");
    //this->setBackgroundRole(QPalette::Shadow);
    this->setWindowTitle("hallo");
//    this->
=======
#include "headers/quibelt.h"

QUIBelt::QUIBelt(QWidget *parent, cBelt *belt)
    : QWidget(parent)
    , mLabel(this)
{
    beltcount = belt;
    QString beltinfo ="Conveyor belt number " + QString::number(beltcount->beltnr) + '\n' + "Block on Conveyor belt " + QString::number(beltcount->block);

    mLabel.setText(beltinfo);
>>>>>>> ddc3f6c92caffd4c2e8764ab9f918f61cbd5c400
}
