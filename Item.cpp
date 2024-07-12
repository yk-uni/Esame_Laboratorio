//
// Created by yashk on 10/07/2024.
//

#include "Item.h"

const string &Item::getItemName() const {
    return itemName;
}

const string &Item::getCategory() const {
    return category;
}

int Item::getItemQuantity() const {
    return itemQuantity;
}

void Item::setItemQuantity(int itemQuantity) {
    if(itemQuantity>=0)
        Item::itemQuantity = itemQuantity;
    else
        throw std::out_of_range("Item quantity entered is not positive");
}

bool Item::isBought() const {
    return bought;
}

void Item::setItemBought(bool bought) {
    Item::bought = bought;
}
