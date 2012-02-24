#include <iostream>
#include "pointerList.h"
#include "arrayList.h"

int main()
{
    List * ab = new arrayList();
    ab->isIn(7);
    ab->lentgh();
    return 0;
}
