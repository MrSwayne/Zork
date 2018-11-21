#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "ipushcallback.h"

class Menu : public QWidget
{
    Q_OBJECT
public:
    std::string getName();
    virtual void setup() = 0;
    virtual void destroy() = 0;
protected:
    explicit Menu(std::string name, IPushCallBack *ipcb = nullptr);
    std::string name;
    IPushCallBack *ipcb = nullptr;
    QWidget *container;
private slots:
       virtual void handlePushButtons() = 0;
};

#endif // MENU_H
