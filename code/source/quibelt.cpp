#include "headers/quibelt.h"
#include "headers/cbelt.h"
#include "clift.h"
#include "cblock.h"
QUIBelt::QUIBelt(QWidget *parent, cBelt* belt)
    : QWidget(parent)
    , mLabel (this  )
    , mBelt (belt)
{

}
QUIBelt::QUIBelt(QWidget *parent, cLift* belt)
    : QWidget(parent)
    , mLabel (this  )
    , mLift (belt)
{

}

QUIBelt::~QUIBelt(){

}

void QUIBelt::setBelt(cBelt *blt){      // set belt info to mainwindow
    mBelt = blt;
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mBelt->block + '\n' ;

    mLabel.setText(beltinfo);
}

void QUIBelt::setLift(){      // set belt info to mainwindow

    QString beltinfo ="Conveyor belt number " +
            QString::number(mLift->getBeltNr()) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mLift->block + '\n' ;

    mLabel.setText(beltinfo);
}

void QUIBelt::setLabel(cblock *block){      // set block and change belt info
    if (mBelt->getOccupiedStatus()==0){
        mBelt->setBlock(block);

        QString beltinfo ="Conveyor belt number " +
                QString::number(mBelt->getBeltNr()) +
                '\n' + "Block on Conveyor belt: " +
                '\n' + block->print+ '\n' ;

        mLabel.setText(beltinfo);
    }
}
void QUIBelt::setLiftLabel(cblock *block){      // set block and change belt info
    if (mLift->getOccupiedStatus()==0){
        mLift->setBlock(block);

        QString beltinfo ="Conveyor belt number " +
                QString::number(mLift->getBeltNr()) +
                '\n' + "Block on Conveyor belt: " +
                '\n' + block->print+ '\n' ;

        mLabel.setText(beltinfo);
    }
}
void QUIBelt::setNoBlock(cblock *block){      // set no block and change belt info
    mBelt->setNoBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + block->print+ '\n' ;

    mLabel.setText(beltinfo);
}

void QUIBelt::updateLabel(){
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + mBelt->block+ '\n' +
            "Motor on: " + QString::number(mBelt->getMotorStatus()) ;

    mLabel.setText(beltinfo);
}

