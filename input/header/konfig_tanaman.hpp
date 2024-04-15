#ifndef __CONFIG_TANAMAN_HPP__
#define __CONFIG_TANAMAN_HPP__
#include "konfig_file.hpp"
#include <iostream>
using namespace std;


class Konfigurasi_Tanaman : public Konfigurasi_Item
{
private:
    string tipe;
    int duration_to_harvest;

public:
    Konfigurasi_Tanaman();
    Konfigurasi_Tanaman(int _id, string _kode, string _nama, string _tipe, int _duration_to_harvest, int harga);
    ~Konfigurasi_Tanaman();

    string getTipe();
    int getDurationToHarvest();

};


#endif