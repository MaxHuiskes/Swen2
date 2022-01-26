#include "QUILift.h"
#include "clift.h"
#include "cblock.h"
#include <QDebug>

QUILift::QUILift(QWidget *parent)
    : QWidget(parent)
    , mLabel (this  )
{

}

QUILift::~QUILift(){}

void QUILift::setLift(cLift *lift){      // set belt info to mainwindow
    mLift = lift;
    QString beltinfo ="Conveyor belt number " +
            QString::number(mLift->getBeltNr()) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mLift->block + '\n' + "LiftStatus: " +QString::number( mLift->getLiftStatus()) ;

    mLabel.setText(beltinfo);
}

void QUILift::setLiftLabel(cblock *block){      // set block and change belt info
    if(mLift->getOccupiedStatus() == 0){

        qDebug() << block->print;
        mLift->setBlock(block);

        QString beltinfo ="Conveyor belt number " +
                QString::number(mLift->getBeltNr()) +
                '\n' + "Block on Conveyor belt: " +
                '\n' + mLift->bl->print+ '\n' + "LiftStatus: " +QString::number( mLift->getLiftStatus()) ;

        mLabel.setText(beltinfo);
    }
}

void QUILift::setNoBlock(cblock *block){      // set no block and change belt info
    mLift->setNoBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mLift->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + block->print+ '\n' + "LiftStatus: " +QString::number( mLift->getLiftStatus());

    mLabel.setText(beltinfo);
}


void QUILift::updateLiftStatus(cblock *block){      // set no block and change belt info
    QString beltinfo ="Conveyor belt number " +
            QString::number(mLift->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + block->print + '\n' +
            "LiftStatus: " + QString::number( mLift->getLiftStatus());
    mLabel.setText(beltinfo);
}
