#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "Hewan.hpp"
#include <vector>

class Herbivore : public Hewan
{
    private:
        const string tipe = "HERBIVORE";

    public:
        // Constructor & Destructor
        Herbivore();
        Herbivore(int, string, string, int, int);
        Herbivore(const Herbivore&);
        ~Herbivore();

        // Getter
        string getTipe();
        vector<string> getProduk();

        // Other Method
        void makan(Item* item);
};


#endif