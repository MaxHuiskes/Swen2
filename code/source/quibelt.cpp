#include "headers/quibelt.h"
#include "headers/cbelt.h"
#include "cblock.h"
QUIBelt::QUIBelt(QWidget *parent)
    : QWidget(parent)
    , mLabel (this  )
{


}
void QUIBelt::setBelt(cBelt *blt){      // set belt info to mainwindow
    mBelt = blt;
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}
void QUIBelt::setLabel(cblock *block){      // set block and change belt info
    mBelt->setBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}
