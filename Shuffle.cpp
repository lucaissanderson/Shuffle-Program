//-------------------------------
// Shuffle.cpp
// Count iters to reach original deck
// lzsander
//--------------------------------


#include "List.h"

using namespace std;

void shuffle(List& D){
    // split deck in half (latter half)
    List D_half;
    for(D.moveFront(); D.position()<(D.length()/2); D.moveNext());
    while(D.position()<D.length()){
        D_half.insertBefore(D.peekNext());
        D.eraseAfter();
    }
    // fill second half into D
    D.moveFront();
    D_half.moveFront();
    while(D_half.position()<D_half.length()-1){
        D.insertBefore(D_half.moveNext());
        D.moveNext();
    }
    // condition for odd/even 
    if(D_half.position()<D_half.length()) D.insertBefore(D_half.moveNext());
}

int main(int argc, char** argv){

    // check usage
    if(argc!=2){
        cerr << "Usage: " << argv[0] << "<num>" << endl;
    }

    // initiate deck
    List D;
    
    // counter
    int count;

    // loop for each deck size from 1 to n
    int n = atoi(argv[1]);

    cout << "deck size        shuffle count" << endl;
    cout << "------------------------------" << endl;

    for(int i=1; i<=n; i++){

        // create deck
        D.clear();
        for(int j=0; j<i; j++){
            D.insertBefore(j);
        }

        // create copy to compare against
        List cD = D;
        
        // shuffle deck until we reach original
        shuffle(D);

        for(count=1; !(D==cD); count++){
            shuffle(D);
        }
        
        cout.width(3);
        cout << i << "                " << count << endl;
    }

    return(EXIT_SUCCESS);
}
