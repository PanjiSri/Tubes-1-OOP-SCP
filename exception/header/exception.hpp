#include <iostream>
#include <exception>
using namespace std;

class FilePathTidakValid : public exception
{
public:
    const char *what() const throw()
    {
        return "File Path Tidak Valid";
    }
};

class NamaPemainTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "Nama tidak valid, sudah ada pemain dengan nama yang sama";
    }
};

class CarnivoraTidakMakanSayurException : public exception
{
public:
    const char *what() const throw()
    {
        return "Carnivore hanya memakan produk hewan";
    }
};

class HerbivoraTidakMakanDagingException : public exception
{
public:
    const char *what() const throw()
    {
        return "Herbivore hanya memakan produk tanaman";
    }
};

class MaterialPlantTidakDimakanException : public exception
{
public:
    const char *what() const throw()
    {
        return "Produk tanaman material tidak bisa dimakan";
    }
};