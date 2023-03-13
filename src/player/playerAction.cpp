#include <iostream>
#include "Player.hpp"
using namespace std;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual)) 
*/

// Getter
int getCombination() // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain
{

}

void nextAction(string action) // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
{

}

void doubleAction(string action) // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
{

}

void halfAction(string action) // Aksi dimana poin game menjadi setengahnya
{

}

virtual void useAbility() // Aksi dimana pemain menggunakan kartu ability yang dimilikinya
{
    
}
