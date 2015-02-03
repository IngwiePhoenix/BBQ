#include <iostream>
#include <stdlib.h>

#include "libbbq.h"

using namespace std;

int main(int argc, char** argv) {
    if(argc < 2) {
        cerr << "Usage: " << argv[0] << " infile > outfile" << endl;
        return 2;
    }
    cout << "Reading: " << argv[1] << endl;
    BBQ::Archive ar(argv[1]);
}
