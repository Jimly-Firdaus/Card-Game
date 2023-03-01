#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_
#include <iostream>
using namespace std;

class Ability{
    private:
        int cardNumber;
        string cardName;
        bool use;
    public:
        // default constructor.
        Ability();

        /*
            user-defined constructor.
            @param {int} cardNumber The number of the card.
            @param {string} cardName Card's name.
        */
        Ability(int cardNumber, string cardName);

        // destructor.
        ~Ability();

        // get card number.
        int getCardNumber() const;

        // get card name.
        string getCardName() const;

        // get card status.
        bool getStatus() const;

        // set card number. 
        void setCardNumber(int cardNumber);

        // set card name.
        void setCardName(int cardName);

        // set use = true.
        void setUsed();

        // set use = false.
        void setUnused();

        // print card's information.
        void getCardInfo();

        /*
            calling card.
            @param {int} cardNumber The number of card.
        */
        void callCard(int cardNumber);
};

#endif