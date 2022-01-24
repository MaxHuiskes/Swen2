#ifndef QUIBELT_H
#define QUIBELT_H

#include <QWidget>
#include <QLabel>

class cBelt;
class cblock;
class cLift;
class QUIBelt : public QWidget
{
    Q_OBJECT
public:
    QUIBelt(QWidget *parent, cBelt*);
    QUIBelt(QWidget *parent, cLift*);
    virtual ~QUIBelt();
    void setBelt(cBelt*);
    void setLift();
    void setLabel(cblock*);
    void setNoBlock(cblock*);
    void setLiftLabel(cblock*);

private:
    QLabel mLabel;
    cBelt  *mBelt;
    cLift *mLift;
public slots:
    void updateLabel();

};

#endif // QUIBELT_H
