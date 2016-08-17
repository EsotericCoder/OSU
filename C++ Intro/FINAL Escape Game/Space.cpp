/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Space Class
 ************************************************************************/

#include "Space.hpp"

Space::Space(){
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = NULL;

}

Space::Space(Player *p){
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = p;

}
void Space::addSpace(Space *one, Space *two, Space *three, Space *four){
    space1 = one;
    space2 = two;
    space3 = three;
    space4 = four;
}

Space* Space::getSpace(int i)
{
    if (i == 1) {
        return space1;
    }else if (i == 2){
        return space2;
    }else if (i == 3){
        return space3;
    }else{
        return space4;
    }
}