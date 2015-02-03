#ifndef BBQ_H
#define BBQ_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "json.h"
#include "libzpaq.h"

namespace BBQ {
    // Import
    using namespace std;

    class Archive {
    private:
        // zpaq i/o
        class FileStream : public libzpaq::Reader,
                           public libzpaq::Writer {
        private:
            string filename;
            libzpaq::SHA1 sha1;
            libzpaq::AES_CTR* aes;
            FILE* fh;
        public:
            FileStream(const string& fname, const char* m);
            ~FileStream() {
                delete aes;
            };
            // Reader stream
            int get();
            int read(char* buf, int n);
            // Writer
            void put(int c);
            void write(const char* buf, int n);  // write buf[n]
        };

        JSON::Value hdrs;
        FileStream* archive;
    public:
        // Ctor
        Archive(const char* filename);
        Archive(string filename);
        // Dtor
        ~Archive();
        // Encryption
        bool key(const char* key);
        // Listing
        vector<string> getFileList();
        vector<string> getHeaders();
        // Editing
        bool add(const string& fileName);
        bool addBuf(const string& fileName, char* buf, int len);
        bool remove(string& fileName);
        bool move(const string& from, const string& to);
        // Tests
        bool exists(const string& fileName);
        bool isDir(const string& fileName);
        bool isFile(const string& fileName);
        // Headers
        JSON::Value headers();
        void headers(JSON::Value hdrs);
        // Traversing
        vector<string> listFiles(const string& dirName);
        vector<string> listDirs(const string& dirName);
        vector<string> glob(const string& dirName, const string& pattern);
    };
}

#endif
