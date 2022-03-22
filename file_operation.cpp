#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "menu.h";
#include "file_operation.h"

using namespace std;

struct Data_Darah {
    char kelas[4];
    char nim[10];
    char gol_dar[4];
    char jk;
};

struct Data_ {
    char kelas[4];
    char nim[10];
    char gol_dar[4];
    char jk[2];
};

struct Sort {
    string kelas;
    string nim;
    string gol_dar;
    string jk;
};

struct Rekap_Darah {
    char gol_dar[4];
    int jml_pria;
    int jml_wanita;
};


//Input Data Mahasiswa

void input_data() {
    struct Data_Darah Mahasiswa;
    fstream file;
    char confirm;

    do {
        system("cls");
        cout << endl << "\t\t\t\tInput Data Mahasiswa" << endl << endl;
        cout << "\tMasukkan Kelas               : ";
        cin >> Mahasiswa.kelas;
        cout << "\tMasukkan NIM                 : ";
        cin >> Mahasiswa.nim;
        cout << "\tMasukkan Golongan Darah      : ";
        cin >> Mahasiswa.gol_dar;
        cout << "\tMasukkan Jenis Kelamin (P/W) : ";
        cin >> Mahasiswa.jk;

        file.open("Data.txt", ios::app | ios::out);



        file << "\n";
        file << Mahasiswa.kelas;
        file << "\t";
        file << Mahasiswa.nim;
        file << "\t";
        file << Mahasiswa.gol_dar;
        file << "\t";
        file << Mahasiswa.jk;

        file.close();

        cout << endl << "Apakah anda ingin input data lagi ? (Y/N)" << endl;
        cin >> confirm;

    } while ((confirm == 'y') || (confirm == 'Y'));

    if ((confirm != 'y') || (confirm != 'Y')) {

        int ukuran = ukuran_file();

        sorting_jk(ukuran);

        sorting_goldar(ukuran);

        system("cls");
        pilih_menu();
    }

}

//Read Data Mahasiswa

void read_data() {
    struct Data_Darah Mahasiswa;
    FILE* file_data;
    char confirm;

    int ukuran = ukuran_file();

    sorting_jk(ukuran);

    sorting_goldar(ukuran);

    if ((file_data = fopen("Data.txt", "rt")) == NULL) {
        cout << "Data Error" << endl;
        exit(1);
    }

    system("cls");

    cout << endl << "\t\t\t\tData Mahasiswa" << endl << endl;

    cout << "\tKelas \tNIM \t\tGolongan Darah \tJenis Kelamin" << endl;

    fscanf(file_data, "%s %s %s %c", &Mahasiswa.kelas, &Mahasiswa.nim, &Mahasiswa.gol_dar, &Mahasiswa.jk);
    fscanf(file_data, "%s %s %s %c", &Mahasiswa.kelas, &Mahasiswa.nim, &Mahasiswa.gol_dar, &Mahasiswa.jk);
    while (!feof(file_data)) {
        printf("\t%-4s \t%-10s \t%-4s \t\t%-4c\n", Mahasiswa.kelas, Mahasiswa.nim, Mahasiswa.gol_dar, Mahasiswa.jk);
        fscanf(file_data, "%s %s %s %c", &Mahasiswa.kelas, &Mahasiswa.nim, &Mahasiswa.gol_dar, &Mahasiswa.jk);
    }

    cout << endl << "Apakah anda ingin kembali ? (Y/N)" << endl;
    cin >> confirm;

    if ((confirm == 'y') || (confirm == 'Y')) {
        system("cls");
        pilih_menu();
    }
    else {
        system("cls");
        read_data();
    }

}

//Mencari Jumlah Data Dalam File

int ukuran_file() {
    struct Data_Darah ukurdata;
    string memory, tempMemory;
    int ukuran = 0, tempUkuran;

    fstream file;

    file.open("Data.txt");

    do {
        tempMemory = memory;
        tempUkuran = ukuran;

        file >> ukurdata.kelas;
        file >> ukurdata.nim;
        file >> ukurdata.gol_dar;
        file >> ukurdata.jk;

        memory = ukurdata.nim;

        if (memory != tempMemory) {
            ukuran++;
        }
    } while (ukuran != tempUkuran);

    file.close();

    return ukuran - 1;
}

//Sorting Sesuai Golongan Darah

void sorting_goldar(int ukuran) {
    fstream file;

    const int line = ukuran;
    Sort* sort_data = new Sort[line];
    sort_data[line];
    Sort temp;

    file.open("Data.txt");

    for (int i = 0; i < ukuran; i++) {
        file >> sort_data[i].kelas;
        file >> sort_data[i].nim;
        file >> sort_data[i].gol_dar;
        file >> sort_data[i].jk;
    }

    for (int i = 0; i < line; i++) {
        for (int j = i + 1; j < line; j++) {
            if (sort_data[i].gol_dar > sort_data[j].gol_dar) {
                temp = sort_data[i];
                sort_data[i] = sort_data[j];
                sort_data[j] = temp;
            }
        }
    }

    file.close();

    file.open("Data.txt", ios::trunc | ios::out);

    for (int i = 0; i < ukuran; i++) {
        file << sort_data[i].kelas;
        file << "\t";
        file << sort_data[i].nim;
        file << "\t";
        file << sort_data[i].gol_dar;
        file << "\t";
        file << sort_data[i].jk << endl;
    }

    file.close();

    delete[]sort_data;
}

//Sorting Sesuai Jenis Kelamin

void sorting_jk(int ukuran) {
    fstream file;

    const int line = ukuran;
    Sort* sort_data = new Sort[line];
    sort_data[line];
    Sort temp;

    file.open("Data.txt");

    for (int i = 0; i < ukuran; i++) {
        file >> sort_data[i].kelas;
        file >> sort_data[i].nim;
        file >> sort_data[i].gol_dar;
        file >> sort_data[i].jk;
    }

    for (int i = 0; i < line; i++) {
        for (int j = i + 1; j < line; j++) {
            if (sort_data[i].jk > sort_data[j].jk) {
                temp = sort_data[i];
                sort_data[i] = sort_data[j];
                sort_data[j] = temp;
            }
        }
    }

    file.close();

    file.open("Data.txt", ios::trunc | ios::out);

    for (int i = 0; i < ukuran; i++) {
        file << sort_data[i].kelas;
        file << "\t";
        file << sort_data[i].nim;
        file << "\t";
        file << sort_data[i].gol_dar;
        file << "\t";
        file << sort_data[i].jk << endl;
    }

    file.close();

    delete[]sort_data;
}

//Proses Rekapitulasi Data

void rekap_data() {

    int ukuran = ukuran_file();

    sorting_jk(ukuran);

    sorting_goldar(ukuran);

    struct Data_Darah Data_Rekap;
    char confirm;
    FILE* file_rekap;
    fstream restart_file;

    char temp_gol_dar[4];

    restart_file.open("Rekap.txt", ios::trunc | ios::out);
    restart_file.close();

    if ((file_rekap = fopen("Data.txt", "rt")) == NULL) {
        cout << "file kosong" << endl;
        exit(1);
    }

    fscanf(file_rekap, "%s %s %s %c", &Data_Rekap.kelas, &Data_Rekap.nim, &Data_Rekap.gol_dar, &Data_Rekap.gol_dar);
    while (!feof(file_rekap)) {
        strcpy(temp_gol_dar, Data_Rekap.gol_dar);
        int jml_pria = 0;
        int jml_wanita = 0;
        int compare = strcmp(temp_gol_dar, Data_Rekap.gol_dar);

        while (!feof(file_rekap) && (compare == 0)) {

            if (Data_Rekap.jk == 'P') {
                jml_pria = jml_pria + 1;
            }
            //else if(Data_Rekap.jk == 'W') {
            else{
                jml_wanita = jml_wanita + 1;
            }
            fscanf(file_rekap, "%s %s %s %s", &Data_Rekap.kelas, &Data_Rekap.nim, &Data_Rekap.gol_dar, &Data_Rekap.jk);
            compare = strcmp(temp_gol_dar, Data_Rekap.gol_dar);
        }

        fstream file;
        file.open("Rekap.txt", ios_base::app);
        if (!file.is_open()) {
            cout << "file error" << endl;
        }
        else {
            file << temp_gol_dar;
            file << "\t";
            file << jml_pria;
            file << "\t";
            file << jml_wanita << endl;
        }

        file.close();
    }
    fclose(file_rekap);

    read_rekap_data();

    cout << endl << "Apakah anda ingin kembali ? (Y/N)" << endl;
    cin >> confirm;

    if ((confirm == 'y') || (confirm == 'Y')) {
        ofstream clearfile;
        clearfile.open("Rekap.txt", ofstream::out | ofstream::trunc);
        clearfile.close();
        pilih_menu();
    }
    else {
        ofstream clearfile;
        clearfile.open("Rekap.txt", ofstream::out | ofstream::trunc);
        clearfile.close();
        rekap_data();
    }
}

//Read File Rekap Data Darah Mahasiswa

void read_rekap_data() {
    struct Rekap_Darah file_rekap_darah;
    FILE* Rekap_data;

    if ((Rekap_data = fopen("Rekap.txt", "rt")) == NULL) {
        cout << "Data File Kosong" << endl;
        exit(1);
    }

    system("cls");
    cout << endl << "\t\t\tRekap Darah Data" << endl << endl;

    cout << "\tGolongan Darah \tJumlah Pria \tJumlah Wanita" << endl;

    fscanf(Rekap_data, "%s %d %d", &file_rekap_darah.gol_dar, &file_rekap_darah.jml_pria, &file_rekap_darah.jml_wanita);
    fscanf(Rekap_data, "%s %d %d", &file_rekap_darah.gol_dar, &file_rekap_darah.jml_pria, &file_rekap_darah.jml_wanita);
    while (!feof(Rekap_data)) {
        printf("\t%-4s \t\t%d \t\t%d\n", file_rekap_darah.gol_dar, file_rekap_darah.jml_pria, file_rekap_darah.jml_wanita);
        fscanf(Rekap_data, "%s %d %d", &file_rekap_darah.gol_dar, &file_rekap_darah.jml_pria, &file_rekap_darah.jml_wanita);
    }
    fclose(Rekap_data);
}