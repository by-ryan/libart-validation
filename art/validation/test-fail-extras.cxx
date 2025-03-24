#include <art/validation/test-result.hxx>

namespace art::validation
{

  void
  Test_fail_extras::
  print(std::ostream& o) const
  {
    extras_->do_print(o);
  }

}
