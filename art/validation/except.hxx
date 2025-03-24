#ifndef art__validation__except_hxx_
#define art__validation__except_hxx_

#include <art/validation/test-fail-extras.hxx>

namespace art::validation
{

  class Fail
  {
  public:
    Fail(Test_fail_extras extras)
      : extras_{std::move(extras)}
    {}

    Test_fail_extras const&
    extras() const
    {
      return extras_;
    }

  private:
    Test_fail_extras extras_;

  };

} // namespace art::validation

#endif
