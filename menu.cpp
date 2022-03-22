#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "menu.h";
#include "file_operation.h"

using namespace std;

//Pilihan Menu
void menu() {
    cout << endl << "\t\t\t\tData Darah Mahasiswa" << endl << endl;
    cout << "\t1. Input Data" << endl;
    cout << "\t2. Read Data" << endl;
    cout << "\t3. Rekap Data" << endl;
    cout << "\t4. Exit" << endl;
    cout << "\tPilih Menu : ";
}

//Proses Memilih Menu
void pilih_menu() {
    system("cls");
    int pil;
    menu();
    cin >> pil;
    switch (pil) {
    case 1: {
        system("cls");
        input_data();
        break;
    }
    case 2: {
        system("cls");
        read_data();
        break;
    }
    case 3: {
        system("cls");
        rekap_data();
        break;
    }
    default:
        exit(0);
        break;
    }
}
