/* ea1_named.cpp    -*- C++ -*-
   親子関係。compositeパターン。
   2016-12-30 17:35:58 Sgurn6i
*/
#include "ea1_named.hpp"
#include "ea1_debug.h"
#include "ea1_benri.h"
#define LOG_TAG "ea1_named"

std::vector<ea1::Named *> ea1::Named::m_instances;

ea1::Named::Named(const std::string& name)
  : m_name(name)
{
  m_instances.push_back(this);
}

ea1::Named::~Named()
{
  for (auto itr = m_instances.begin(); itr != m_instances.end(); itr ++)
    {
      if (*itr == this)
        {
          m_instances.erase(itr);
          break;
        }
    }
}

unsigned int ea1::Named::get_instances_amt()
{
  return (unsigned int)m_instances.size();
}

ea1::Named * ea1::Named::get_instance(unsigned int sn)
{
  if (sn >= get_instances_amt())
    {
      return NULL;
    }
  return m_instances[sn];
}
  
