#include "cblock.h"

cblock::cblock()
{

}



int cblock::order(){
    for (int i = 0; i < blockCount; i++){
        return i;
    }
    if(blockCount == '0'){
        return 0;
    } else {
        return -1;
    }
}
