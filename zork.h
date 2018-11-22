#ifndef ZORK_H
#define ZORK_H

#include "view.h"
#include "model.h"
#include "controller.h"

class Zork
{
public:
    Zork();
    void run();
private:
    Model model;
    View view;
    Controller controller;
};

#endif // ZORK_H
