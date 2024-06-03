#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    int a=0;
    srand(time(NULL));
    for(int i=0; i<10;i++){
        a=rand()%(20-2+1)+2;
        cout<<a<<endl;
    }
    return 0;
}



