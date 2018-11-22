#include "zork.h"


Zork::Zork() : model(), view(), controller(&model, &view)
{

}

void Zork::run() {
    view.show();
}
