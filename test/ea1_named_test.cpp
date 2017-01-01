/* ea1_named_test.cpp    -*- C++ -*-
   test ea1_named main
   2016-12-13 12:56:05 Sgurn6i
*/
#include "ea1_named.hpp"
//#include "ea1_benri.h"
#include <gtest/gtest.h>

namespace
{
  TEST(NamedTest, Instance)
  {
    auto * n1 = new ea1::Named("n1");
    EXPECT_STREQ("n1", n1->get_name().c_str());
    auto * n2 = new ea1::Named("n2");
    ea1::Named n3d("n3");
    fprintf(stderr, "names: %s %s %s\n",
            n1->get_name().c_str(),
            n2->get_name().c_str(),
            n3d.get_name().c_str());
    EXPECT_EQ(3, ea1::Named::get_instances_amt());
    delete n2;
    EXPECT_EQ(2, ea1::Named::get_instances_amt());
    auto * n4 = new ea1::Named("n4");
    EXPECT_STREQ("n3", ea1::Named::get_instance(1)->get_name().c_str());
    EXPECT_EQ(3, ea1::Named::get_instances_amt());
    delete n1;
    delete n4;
    EXPECT_EQ(1, ea1::Named::get_instances_amt());
  }
} /* namespace */
