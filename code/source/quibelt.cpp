<<<<<<< HEAD
#include "quibelt.h"
#include "cbelt.h"

QUIBelt::QUIBelt(QWidget *parent, cBelt *belt)
    : QWidget(parent)
    , mLabel(this)
    , mBelt(belt)
{
    QString beltinfo ="Conveyor belt number " + QString::number(mBelt->beltnr) + '\n' + "Block on Conveyor belt " + QString::number(mBelt->block);
=======
#include "headers/quibelt.h"
#include "headers/cbelt.h"

QUIBelt::QUIBelt(QWidget *parent, cBelt *belt)
    : QWidget(parent)
    , mLabel (this  )
    , mBelt  (belt  )
{

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->beltnr) + '\n' +
            "Block on Conveyor belt " +
            QString::number(mBelt->block);
>>>>>>> 859f368ad50eae11180f0528618ff21e07127aec

    mLabel.setText(beltinfo);
}

void QUIBelt::setButton(){
    mBelt->setBlock();

    mLabel.setText(" ");


//    QString beltinfo ="Conveyor belt number " + QString::number(beltcount->beltnr) + '\n' + "Block on Conveyor belt " + QString::number(beltcount->block);
//    mLabel.setText(beltinfo);
}
