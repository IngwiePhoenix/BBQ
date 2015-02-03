#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "json.h"
#include "libzpaq.h"
#include "file_system.hpp"
#include "wildcard.hpp"

#include "libbbq.h"

namespace libzpaq {
void error(char const* e) {
    fprintf(stderr, "libzpaq: %s\n", e);
}
};

namespace BBQ {

using namespace std;
using namespace stlplus;

// FileStream
Archive::FileStream::FileStream(const string& fname, const char* m)
    : libzpaq::Reader(), libzpaq::Writer(),
        filename(fname) {
    cout << "Opening: " << fname << endl;
    fh = fopen(fname.c_str(), m);
}
Archive::FileStream::~FileStream() {
    fclose(fh);
}
// Reader
int Archive::FileStream::get() {
    return fgetc(fh);
}
int Archive::FileStream::read(char* buf, int n) {
    return fread(buf, n, 1, fh);
}
// Writer
void Archive::FileStream::put(int c) {
    fputc(c, fh);
}
void Archive::FileStream::write(const char* buf, int n) {
    fwrite(buf, n, 1, fh);
}

Archive::Archive(const char* filename) {
    archive = new FileStream(filename, "r");
}
Archive::Archive(string filename) {
    archive = new FileStream(filename.c_str(), "r");
}
Archive::~Archive() {
    delete archive;
}

}; // BBQ namespace
