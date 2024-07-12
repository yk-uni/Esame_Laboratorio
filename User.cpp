//
// Created by yashk on 11/07/2024.
//

#include "User.h"

void User::addShoppingList(ShoppingList& shoppingList) {
    auto sListPtr= make_shared<ShoppingList>(shoppingList);
    myLists.insert(make_pair(shoppingList.getShoppingListName(), sListPtr));
    shoppingList.subscribe(this);
}


void User::removeShoppingList(const string &name) {
    auto itr = myLists.find(name);
    if (itr == myLists.end()) {
        throw std::invalid_argument("Invalid shopping list name");
    } else {
        itr->second->unsubscribe(this);
        myLists.erase(name);
    }
}


void User::update(const string &listName) {

    auto itr = myLists.find(listName);
    cout << "Lista ' " << listName << " ' aggiornata: " << endl;
    cout << endl;
    itr->second->printNotBought();
}

const map<string, shared_ptr<ShoppingList>> &User::getMyLists() const {
    return myLists;
}
