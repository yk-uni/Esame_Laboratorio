//
// Created by yashk on 06/07/2024.
//

#include "ShoppingList.h"

void ShoppingList::addItem(const Item &item) {

    auto itr = shoppingList.find(item.getItemName());
    if (itr != shoppingList.end() && itr->second->getCategory()==item.getCategory()) //l'oggetto è già presente
    {
        int result= itr->second->getItemQuantity() + item.getItemQuantity();
        itr->second->setItemQuantity(result);
    }
    else
    {
        auto itemPtr= make_shared<Item>(item);
        shoppingList.insert(make_pair(item.getItemName(), itemPtr));
    }

    string itemCat=item.getCategory();   //serve in seguito per andare a stampare gli oggetti in base alla categoria
    bool flag=false;
    for(auto&it: categories)
    {
        if(it.first==itemCat)
        {
            flag=true;  //categoria già  presente, aggiorno numero oggetti nella categoria
            it.second++;
            break;
        }
    }
    if(!flag)
    {
        categories.insert(make_pair(itemCat,1));
    }

    notify();

}


void ShoppingList::removeItem(const string &name) {
    auto itr = shoppingList.find(name);
    if (itr == shoppingList.end()) {
        throw std::invalid_argument("Invalid item name");
    } else {
        auto itc= categories.find(itr->second->getCategory());      //tratto la mappa di categorie
        itc->second--;
        if(itc->second==0)//e' presente solo l'elemento in questione
        {
            categories.erase(itc);
        }

        itr->second->setItemQuantity(0);
        shoppingList.erase(itr);        //tratto la mappa di oggetti

        notify();
    }

}


const string &ShoppingList::getShoppingListName() const {
    return shoppingListName;
}



void ShoppingList::setBought(const string &name) {
    auto itr = shoppingList.find(name);

    if (itr != shoppingList.end()) {
        bool isBought = itr->second->isBought();
        if (isBought)
            itr->second->setItemBought(false);
        else
            itr->second->setItemBought(true);

        notify();
    } else
        throw std::invalid_argument("Invalid item name");
}


void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}


void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}


void ShoppingList::notify() {
    for (auto &itr:observers)
        itr->update(shoppingListName);
}


void ShoppingList::printNotBought() {

    int result = 0;
    cout << "Oggetti da acquistare: ";
    cout << endl;
    string cat;
    bool first;
    for (auto &itr: categories) {
        cat = itr.first;
        first = true;
        if(itr.second!=0) {
            for (auto &s: shoppingList) {
                if (s.second->getCategory() == cat) {
                    if (first) {
                        cout << "Categoria:  " << cat << endl;
                        first = false;
                    }

                    if (!s.second->isBought() && s.second->getItemQuantity() != 0) {
                        cout << s.first << "     " << s.second->getItemQuantity() << endl;
                        result += s.second->getItemQuantity();   //conto gli oggetti da acquistare;
                    }
                }
            }
        }
    }
    cout << endl;
    cout << "Numero totale oggetti da acquistare: " << result << endl;
    cout << endl;
}

void ShoppingList::setShoppingListName(const string &shoppingListName) {
    ShoppingList::shoppingListName = shoppingListName;
}

int ShoppingList::notBought() {
    int result=0;
    for (auto &itr: shoppingList) {
        if (!itr.second->isBought()) {
            result += itr.second->getItemQuantity();   //conto gli oggetti da acquistare;
        }
    }
    return result;
}

const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}

const map<string,int> &ShoppingList::getCategories() const {
    return categories;
}

const list<Item> &ShoppingList::getItems(string &category) const{
    list<Item> items;
    for (auto &itr: shoppingList) {
        if (itr.second->getCategory()==category) {
            items.push_back(*(itr.second));
        }
    }
    return items;
}

