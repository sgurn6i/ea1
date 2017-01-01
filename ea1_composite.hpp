/* ea1_composite.hpp    -*- C++ -*-
   親子関係。compositeパターン。
   2016-12-30 17:35:19 Sgurn6i
*/
#ifndef __EA1_COMPOSITE_H__
#define __EA1_COMPOSITE_H__

#include <string>
#include <vector>
#include "ea1_named.hpp"

namespace ea1
{
  /* 親子関係。
   * Composite は 0..N の Component を子として階層的に持つことができる。 */
  class Composite;
  /* 親子共通 component。
   * 親のdelete時に子をdeleteしないのは、SWIGでガーベジコレクト付きの
   * 言語にこのライブラリを使わせるから。 */
  class Component : public Named
  {
    friend class Composite;
  public:
    Component(const std::string& name);
    /* 親があれば登録抹消してもらってからデストラクトする。 */
    virtual ~Component();
    /* すべての子孫を全部delete。 */
    virtual void delete_descendant() = 0;
    /* 親を返す。無ければNullを返す。 */
    Composite * get_parent() const;
  protected:
    /* thisの親としてcsを設定。
     * 親としてふさわしくなければ、設定せずに負数を返す。
     * その上で、既に親(prev_csとする)が有れば、prev_csに登録抹消して
     * もらってからcsを設定する。 */
    virtual int set_parent(Composite& cs);
    /* cs が親であったら設定解除する。 */
    int unset_parent(Composite& cs);
  private:
    Composite * m_parent = NULL;
  };

  /* 子 */
  class Leaf : public Component
  {
  public:
    Leaf(const std::string& name = "leaf");
    virtual ~Leaf();
    virtual void delete_descendant(){ }
  };

  /* 親となりうるcomponent */
  class Composite : public Component
  {
  public:
    Composite(const std::string& name = "composite");
    /* すべての子に親としての設定を解除させてからデストラクトする。
     * 子は delete しない。*/
    virtual ~Composite();
    virtual void delete_descendant();
    /* cの親としてthisをcに設定させ、
     * OKならthisの子としてcを登録する。
     * thisがcの子孫だったら設定も登録もせずにエラー。*/
    virtual int add_child(Component*  c);
    /* cが子であったら登録抹消し、cに親としての設定を解除させる。
     * cはdeleteしない。
     * cが子でなかったら、EA1_STATUS1 を返す。*/
    int remove_child(Component* c);
    /* 登録された子の数。 */
    int get_children_amt() const;
    /* sn 番目の子を返す。無ければNULL返す。 */
    Component * get_child(int sn) const;
    /* その子はあんたの子か。 */
    bool has_child(Component * cp) const;
    /* その子はあんたの子孫か。 */
    bool has_descendant(Component * cp) const;
  private:
    std::vector <Component *> m_children;
  };

} /* namespace ea1 */

#endif /* __EA1_COMPOSITE_H__ */
