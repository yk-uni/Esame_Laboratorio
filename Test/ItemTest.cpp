//
// Created by yashk on 12/07/2024.
//



#include "gtest/gtest.h"
#include"../Item.h"


TEST(ItemSuite,TestConstructor)
{
    Item i("pane","cibo",6);
    ASSERT_EQ(i.getItemQuantity(),6);
    ASSERT_EQ(i.getCategory(),"cibo");
    ASSERT_EQ(i.getItemName(),"pane");

    ASSERT_THROW(Item i2("pane","cibo",-2) ,out_of_range);
}


TEST(ItemSuite, TestSetItemquantity) {
    Item i("pane","cibo",3);
    ASSERT_THROW(i.setItemQuantity(-2),out_of_range);
}
