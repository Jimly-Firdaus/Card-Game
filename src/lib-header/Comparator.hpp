#ifndef _COMPARATOR_HPP_
#define _COMPARATOR_HPP_

class Comparator
{
public:
    // Getter & Setter
    void setIndex();
    void setCombinationType();

    // TODO: complete methods args (missing Deck type)
    /**
     * Get the strongest combination deck
     * @param Deck* arr_of_deck
     * @return int index of the strongest combination in arr_of_deck
     */
    int getStrongestCombination();

    /**
     * Get the strongest combination deck
     * @param Deck* arr_of_deck
     * @return double constant of the strongest combination in arr_of_deck
     */
    double getStrongestCombinationType();

    /**
     * Get the strongest combination deck
     * @param Deck* arr_of_deck
     * @return Comparator object contain index of the strongest combination & combinationConstant
     */
    Comparator compare();
    // Just in case this class needs to be extends
protected:
    int index;
    int combinationConstant;
};

#endif;
