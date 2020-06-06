#ifndef KEYLISTENNER_H
#define KEYLISTENNER_H

#include <QObject>

class KeyListenner : public QObject
{
public:
    KeyListenner();
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

#endif // KEYLISTENNER_H
