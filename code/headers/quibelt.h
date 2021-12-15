#ifndef QUIBELT_H
#define QUIBELT_H

#include <QWidget>
#include <QLabel>

class QUIBelt : public QWidget
{
    Q_OBJECT
public:
    explicit QUIBelt(QWidget *parent = nullptr);

private:
    QLabel mLabel;



signals:

};

#endif // QUIBELT_H
