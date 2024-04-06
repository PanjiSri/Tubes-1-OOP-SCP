#include "Hewan.hpp"

Hewan::Hewan() :
    Item(), 
    standar_berat_panen(0), harga(0) {
    this->berat_saat_ini = 0;
}

// Hewan::Hewan(int _ID) :
//     Item(_ID), 
//     standar_berat_panen(dummy[_ID][4]), harga(dummy[_ID][5]) {
//     this->berat_saat_ini = 0;
//     nhewan++;
// }

Hewan::Hewan(const Hewan& other) :
    Item(other), 
    standar_berat_panen(other.standar_berat_panen), harga(other.harga) {
    this->berat_saat_ini = other.berat_saat_ini;
    nhewan++;
}

Hewan::~Hewan() {}

int Hewan::getBeratPanen() {
    return standar_berat_panen;
}

int Hewan::getHarga() {
    return harga;
}

int Hewan::getBeratSaatIni() {
    return berat_saat_ini;
}

int Hewan::getJumlahHewan() {
    return nhewan;
}

void Hewan::setBeratSaatIni(int tambahan_berat) {
    berat_saat_ini += tambahan_berat;
}

bool Hewan::isSiapPanen() {
    return berat_saat_ini >= standar_berat_panen;
}