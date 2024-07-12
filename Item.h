//
// Created by yashk on 10/07/2024.
//

#ifndef ESAME_LABORATORIO_ITEM_H
#define ESAME_LABORATORIO_ITEM_H

#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class Item {
public:
    Item(string s, string c, int q=1):  itemName(std::move(s)),category(std::move(c)){
        if(q>=0)
            itemQuantity=q;
        else
            throw out_of_range("Item quantity entered is not positive");
    }

    const string &getItemName() const;

    const string &getCategory() const;

    int getItemQuantity() const;

    void setItemQuantity(int itemQuantity);

    bool isBought() const;

    void setItemBought(bool bought);

private:
    string itemName;
    string category;
    int itemQuantity;
    bool bought=false;
};


#endif //ESAME_LABORATORIO_ITEM_H