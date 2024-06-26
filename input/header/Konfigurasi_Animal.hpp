#ifndef __ANIMAL_CONFIG_HPP__
#define __ANIMAL_CONFIG_HPP__
#include "Konfigurasi_Item.hpp"
#include <iostream>
using namespace std;

class Konfigurasi_Animal : public Konfigurasi_Item
{
private:
    string tipe;
    int weight_to_harvest;

public:
    // Konstruktor dan destruktor
    Konfigurasi_Animal();
    Konfigurasi_Animal(int _id, string _kode, string _nama, string _tipe, int _weight_to_harvest, int _harga);
    ~Konfigurasi_Animal();

    // Getter
    string getTipe();
    int getWeightToHarvest();    

};


#endif