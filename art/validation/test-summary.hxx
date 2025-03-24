#ifndef art__validation__test_summary_hxx_
#define art__validation__test_summary_hxx_

#include <art/validation/test-result.hxx>

#include <cstdint>
#include <vector>

namespace art::validation
{

  class Test_summary
  {
  public:
    Test_summary() = default;

    void
    append(Test_result);

    void
    inc_pass();

    void
    inc_fail();

    void
    print(std::ostream&, bool, bool) const;

  private:
    std::vector<Test_result> results_;
    int pass_{};
    int fail_{};

  };

} // namespace art::validation

#endif
