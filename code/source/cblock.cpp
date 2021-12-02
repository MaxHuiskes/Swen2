#include "cblock.h"

cblock::cblock()
{

}

void cblock::block(int count, int mat){
    blockCount = count;
    matiraal = mat;
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
