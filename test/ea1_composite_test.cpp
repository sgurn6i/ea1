/* ea1_composite_test.cpp    -*- C++ -*-
   test ea1_composite main
   2016-12-13 12:56:05 Sgurn6i
*/
#include "ea1_composite.hpp"
#include "ea1_benri.h"
#include <gtest/gtest.h>

namespace
{
  TEST(CompositeTest, Instance)
  {
    ea1::Composite cp1("cp1");
    EXPECT_EQ(0, cp1.get_children_amt());
    EXPECT_EQ(EA1_OK, cp1.add_child(new ea1::Leaf("leaf1")));
    EXPECT_EQ(NULL, cp1.get_child(1));
    EXPECT_EQ(1, cp1.get_children_amt());
    cp1.delete_descendant();
    EXPECT_EQ(0, cp1.get_children_amt());
  }
  TEST(CompositeTest, AddRemove)
  {
    ea1::Composite * cp1 = new ea1::Composite("cp1");
    EXPECT_EQ(EA1_OK, cp1->add_child(new ea1::Leaf("leaf1")));
    EXPECT_NE(EA1_OK, cp1->add_child(NULL));
    ea1::Composite* cp2 = new ea1::Composite("cp2");
    EXPECT_EQ(false, cp1->has_child(cp2));
    EXPECT_EQ(NULL, cp1->get_child(1));
    auto leaf1 = dynamic_cast<ea1::Leaf *>(cp1->get_child(0));
    EXPECT_EQ(true, cp1->has_child(leaf1));
    ea1::Leaf * leaf2 = new ea1::Leaf("leaf2");
    ea1::Leaf * leaf3 = new ea1::Leaf("leaf3");
    EXPECT_EQ(1, cp1->get_children_amt());
    EXPECT_EQ(EA1_OK, cp2->add_child(leaf2));
    EXPECT_EQ(EA1_OK, cp1->add_child(cp2));
    EXPECT_NE(EA1_OK, cp1->remove_child(leaf2)); // 子ではないものをremove
    EXPECT_EQ(cp1, cp2->get_parent()); // 親子関係
    EXPECT_EQ(EA1_OK, cp2->add_child(leaf3));
    EXPECT_EQ(leaf3, cp2->get_child(1));
    EXPECT_EQ(leaf2, cp2->get_child(0));
    EXPECT_EQ(2, cp1->get_children_amt());
    EXPECT_EQ(EA1_OK, cp2->remove_child(leaf2)); // remove
    EXPECT_EQ(false, cp2->has_child(leaf2));
    EXPECT_EQ(1, cp2->get_children_amt());
    EXPECT_EQ(NULL, leaf2->get_parent());
    EXPECT_EQ(cp2, leaf3->get_parent());
    EXPECT_EQ(EA1_OK, cp1->add_child(leaf3)); // 奪い取り
    EXPECT_EQ(0, cp2->get_children_amt());
    EXPECT_EQ(false, cp2->has_child(leaf3));
    EXPECT_EQ(true, cp1->has_child(leaf3));
    EXPECT_EQ(cp1, leaf3->get_parent());
    ea1::Composite* cp3 = new ea1::Composite("cp3");
    cp3->add_child(leaf2);
    cp2->add_child(cp3);
    EXPECT_EQ(true, cp1->has_descendant(cp3)); // 孫
    EXPECT_EQ(true, cp1->has_descendant(leaf2));
    EXPECT_EQ(true, cp3->has_descendant(leaf2));
    ASSERT_NE(EA1_OK, cp3->add_child(cp1)); // 循環参照
    delete cp1;
    EXPECT_EQ(NULL, cp2->get_parent());
    cp3->delete_descendant();
    for (unsigned int ix = 0; ix < ea1::Named::get_instances_amt(); ix ++)
      {
        ea1::Named * ni = ea1::Named::get_instance(ix);
        fprintf(stderr, "instance %d: %s\n", ix, ni->get_name().c_str());
      }
    delete cp2;
    delete cp3;
    delete leaf1;
    delete leaf3;
    EXPECT_EQ(0, ea1::Named::get_instances_amt());
  }

} /* namespace */
