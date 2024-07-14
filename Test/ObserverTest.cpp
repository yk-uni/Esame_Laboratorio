//
// Created by yashk on 12/07/2024.
//


#include "gtest/gtest.h"
#include "../Observer.h"
#include "../ShoppingList.h"


class ObserverTest : public testing::Test, public Observer {
public:
    void update(const string& listName) override {
        updated = true;
    }

    bool isUpdated() const {
        return updated;
    }

protected:

    void SetUp() override {
        s.subscribe(this);

    }

    void TearDown() override {
        s.unsubscribe(this);
    }

    bool updated = false;
    ShoppingList s {"Casa"};
    Item carta {"carta","bagno",3};

};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    s.addItem(carta);
    ASSERT_TRUE(isUpdated());
}


