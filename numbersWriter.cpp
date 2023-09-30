#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdio>
using namespace std;
int main (int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Always should receive 3 arguments\n";
        return 1;
    }

    string file1 = argv[1];
    string file2 = argv[2];
    string existingFile = file1;

    fstream f1, f2;
    f1.open(file1);
    f2.open(file2);
    if (f1.fail() && f2.fail()) {
        cout << "Could not open any of the files\n";
        return 1;
    }

    if (!f1.fail() && !f2.fail()) {
        cout << "Both files exist\n";
        return 1;
    }

    if (f1.fail()) {
        cout << "Found 2, but not 1\n";
        f1.open(file1, fstream::app);
        swap(f1, f2);
        existingFile = file2;
    } else {
        f2.open(file2, fstream::app);
    }

    for (int x ; f1 >> x ; ) {
        cout << "Reading " << x << " and writing " << x+1 << " to the other file\n";
        f2 << x+1 << "\n";
    }

    f1.close();
    f2.close();

    remove(existingFile.c_str());

    sleep(5);
    return 0;
}
