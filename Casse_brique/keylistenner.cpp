#include "keylistenner.h"

KeyListenner::KeyListenner() : QObject()
{

}

bool KeyListenner::eventFilter(QObject* obj, QEvent* event)
{
    printf("OK");
    return true;
}
