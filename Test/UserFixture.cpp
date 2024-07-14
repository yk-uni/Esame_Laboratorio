//
// Created by yashk on 12/07/2024.
//


#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class UserSuite : public ::testing::Test {

protected:
protected:

    virtual void SetUp() {
        u.addShoppingList(s1);
        u.addShoppingList(s2);
    }

    ShoppingList s1{"Casa"};
    ShoppingList s2{"Lavoro"};
    ShoppingList s3{"Famiglia"};
    User u;

};


TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(s3);

    ASSERT_EQ(3,u.getMyLists().size());
}



TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("Casa");

    ASSERT_EQ(1,u.getMyLists().size());
}
