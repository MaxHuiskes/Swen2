#ifndef QUILIFT_H
#define QUILIFT_H
#include <QWidget>
#include <QLabel>

class cLift;
class cblock;

class QUILift : public QWidget
{
    Q_OBJECT
public:
    QUILift(QWidget *parent);
    virtual ~QUILift();
    void setLift(cLift*);
    void setNoBlock(cblock*);
    void setLiftLabel(cblock*);

private:
    cLift  *mLift;
    QLabel mLabel;
};

#endif // QUILIFT_H
