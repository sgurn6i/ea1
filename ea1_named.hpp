/* ea1_named.hpp    -*- C++ -*-
   名前ありの基底。instance数数え上げ付き。
   2017-01-01 15:55:38 Sgurn6i
*/
#ifndef _EA1_NAMED_H_
#define _EA1_NAMED_H_

#include <string>
#include <vector>

namespace ea1
{
  /* 名前ありの基底。
   * instance 数を数える。 */
  class Named
  {
  public:
    Named(const std::string& name = "");
    virtual ~Named();
    virtual const std::string& get_name() const { return m_name; }
    /* static関数 */
    /* インスタンスの総数 */
    static unsigned int get_instances_amt();
    /* sn番目のインスタンスを得る。無ければ NULLを返す。 */
    static Named * get_instance(unsigned int sn);
  private:
    std::string m_name;
    static std::vector<Named *> m_instances;
  };
} /* namespace ea1 */
#undef LOG_TAG

#endif /* _EA1_NAMED_H_ */
