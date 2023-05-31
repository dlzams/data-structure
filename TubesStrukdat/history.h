#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED
#include <iostream>
using namespace std;

#define infoDate(P) (P)->infoDate
#define infoHistory(P) (P)->infoHistory
#define nextHistory(P) (P)->nextHistory
#define nextDate(P) (P)->nextDate
#define nextCH(P) (P)->nextCH
#define first(L) ((L).first)

typedef struct date infotypeDate;
typedef struct elmDate *adrDate;

typedef struct history infotypeHistory;
typedef struct elmHistory *adrHistory;

struct date {
    string tanggal;
    string hari;
};
struct history {
    string time;
    string title;
    string domain;
};
struct elmDate {
    infotypeDate infoDate;
    adrDate nextDate;
    adrHistory nextCH; //ChildHistory
};
struct elmHistory {
    infotypeHistory infoHistory;
    adrHistory nextHistory;
};
struct List {
    adrDate first;
};

void createList(List &L);
adrDate newElementDate(infotypeDate x);
adrHistory newElementHistory(infotypeHistory x);
bool isEmpty(List L);
void selectMenu();
void deleteSomeHistory(List &L,string tanggal, string time);

/* KETENTUAN-KETENTUAN TUBES */
//Insert data parent
void insertDate(List &L,adrDate P);

//Show all data parent
void showAllDate(List L);

//Menghapus data parent beserta isinya
void deleteDate(List &L, string tanggal);

//Mencari data parent
adrDate findDate(List L, string tanggal);

//Mencari data child
adrHistory findHistory(List L, string time);

//Menambahkan data child
void insertHistoryMain(List &L, adrHistory P);
void insertHistorySecondary(List &L, adrHistory P, adrDate X);

//Menampilkan seluruh data data parent beserta childnya
void showAllData(List L);

//Mencari data child pada parent tertentu
void findSomeHistory(List L, string tanggal, string time);

//Menghapus data child pada parent tertentu beserta relasinya
void deleteHistory(List &L, string tanggal);

//Menghitung jumlah data child dari parent tertentu
int SumOfHistory(List L, string tanggal);

void database(List &L);

#endif // HISTORY_H_INCLUDED
