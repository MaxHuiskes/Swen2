#include "headers/quibelt.h"
#include "headers/cbelt.h"
#include "cblock.h"
QUIBelt::QUIBelt(QWidget *parent, cBelt* belt)
    : QWidget(parent)
    , mLabel (this  )
    , mBelt (belt)
{

}
void QUIBelt::setBelt(cBelt *blt){      // set belt info to mainwindow
    mBelt = blt;
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mBelt->block + '\n' +
            "Motor on: " + QString::number(mBelt->getMotorStatus()) ;

    mLabel.setText(beltinfo);
}
void QUIBelt::setLabel(cblock *block){      // set block and change belt info
    if (mBelt->getOccupiedStatus()==0){
        mBelt->setBlock(block);

        QString beltinfo ="Conveyor belt number " +
                QString::number(mBelt->getBeltNr()) +
                '\n' + "Block on Conveyor belt: " +
                '\n' + block->print+ '\n' +
                "Motor on: " + QString::number(mBelt->getMotorStatus()) ;

        mLabel.setText(beltinfo);
    }
}
void QUIBelt::setNoBlock(cblock *block){      // set no block and change belt info
    mBelt->setNoBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + block->print+ '\n' +
            "Motor on: " + QString::number(mBelt->getMotorStatus()) ;

    mLabel.setText(beltinfo);
}

void QUIBelt::updateLabel(int change){
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + mBelt->block+ '\n' +
            "Motor on: " + QString::number(mBelt->getMotorStatus()) ;

    mLabel.setText(beltinfo);
}

//bool QUIBelt::motorStatus(){

//    return mBelt->getMotorStatus();
//}
