#include <art/validation/test-summary.hxx>

#include <iostream>

namespace art::validation
{

  void
  Test_summary::
  append(Test_result result)
  {
    results_.emplace_back(std::move(result));
  }

  void
  Test_summary::
  inc_pass()
  {
    ++pass_;
  }

  void
  Test_summary::
  inc_fail()
  {
    ++fail_;
  }

  void
  Test_summary::
  print(std::ostream& o, bool print_extras, bool stats) const
  {
    for (auto const& j : results_) {
      j.print(o, print_extras);
    }

    if (stats) {
      auto total = pass_ + fail_;

      o << "test statistics:\n"
        << "tests       : " << total << '\n'
        << "tests passed: " << pass_ << '\n'
        << "tests failed: " << fail_ << '\n'
        ;
    }
  }

} // namespace art::validation
