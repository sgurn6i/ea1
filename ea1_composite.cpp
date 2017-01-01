/* pfamily.cpp    -*- C++ -*-
   親子関係。compositeパターン。
   2016-12-30 17:35:58 Sgurn6i
*/
#include "ea1_composite.hpp"
#include "ea1_debug.h"
#include "ea1_benri.h"
#define LOG_TAG "ea1_composite"


ea1::Component::Component(const std::string& name)
  : Named(name)
{
}

ea1::Component::~Component()
{
  if (m_parent)
    {
      m_parent->remove_child(this);
    }
}

int ea1::Component::set_parent(Composite& cs)
{
  if (m_parent)
    {
      m_parent->remove_child(this);
    }
  m_parent = &cs;
  return EA1_OK;
}

int ea1::Component::unset_parent(Composite& cs)
{
  if (&cs == m_parent)
    {
      m_parent = NULL;
      return EA1_OK;
    }
  else
    {
      return EA1_STATUS1;
    }
}

ea1::Composite * ea1::Component::get_parent() const
{
  return m_parent;
}

ea1::Leaf::Leaf(const std::string& name)
  :ea1::Component(name)
{
  LOGD("Leaf %s", name.c_str());
}

ea1::Leaf::~Leaf()
{
  LOGD("~Leaf %s", get_name().c_str());
}

ea1::Composite::Composite(const std::string& name)
  : ea1::Component(name)
{
  LOGD("Composite %s", name.c_str());
}

ea1::Composite::~Composite()
{
  for (auto itr = m_children.begin(); itr != m_children.end(); itr ++)
    {
      if(*itr != NULL)
        {
          (*itr)->unset_parent(*this);
        }
    }
  LOGD("~Composite %s", get_name().c_str());
}

void ea1::Composite::delete_descendant()
{
  while (! m_children.empty())
    {
      ea1::Component * c = m_children.back();
      if (c && (c->get_parent() == this))
        {
          c->delete_descendant();
          delete c;
        }
    }
}

int ea1::Composite::add_child(Component * c)
{
  if (c == NULL)
    return EA1_EINVAL;
  /* 循環参照チェック。cがthisの祖先なら子にできない。 */
  ea1::Composite * cs1 = dynamic_cast<ea1::Composite *>(c);
  if ((cs1 != NULL) && cs1->has_descendant(this))
    {
      LOGE("%s %s: my ancient %s cannot be my child",
           get_name().c_str(), __func__, c->get_name().c_str());
      return EA1_EINVAL;
    }
  int rc = c->set_parent(*this);
  if (rc == EA1_OK)
    {
      m_children.push_back(c);
    }
  return rc;
}

int ea1::Composite::remove_child(Component * c)
{
  if (c == NULL)
    return EA1_EINVAL;
  if (c->get_parent() != this)
    {
      LOGE("%s %s: %s does not assume me as the parent",
           get_name().c_str(), __func__, c->get_name().c_str());
      return EA1_STATUS1;
    }
  int rc = EA1_STATUS1;
  auto itr = m_children.begin();
  while (itr != m_children.end())
    {
      if (*itr == c)
        {
          c->unset_parent(*this);
          itr = m_children.erase(itr);
          LOGD("%s %s removed child %s",
               get_name().c_str(), __func__, c->get_name().c_str());
          rc = EA1_OK;
        }
      else
        {
          itr ++;
        }
    }
  return rc;
}


int ea1::Composite::get_children_amt() const
{
  return (int)m_children.size();
}

ea1::Component * ea1::Composite::get_child(int sn) const
{
 if (sn >= (int)m_children.size())
    return NULL;
  return m_children[sn];
}

bool ea1::Composite::has_child(Component * cn) const
{
#if 0
  for (auto itr = m_children.begin(); itr != m_children.end(); itr ++)
    {
      if (*itr == cn)
        return true;
    }
#else
  if (cn && (cn->get_parent() == this))
      return true;
#endif
  return false;
}

bool ea1::Composite::has_descendant(Component * cn) const
{
  ea1::Component * curr = cn;
  while (curr != NULL)
    {
      curr = curr->get_parent();
      if (curr == this)
        return true;
    } 
  return false;
}

