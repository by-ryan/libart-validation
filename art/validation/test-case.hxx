#ifndef art__validation__test_case_hxx_
#define art__validation__test_case_hxx_

#include <art/validation/utility.hxx>

#include <functional>
#include <source_location>
#include <string>

namespace art::validation
{

  class Test_case
    : Utility::Intrusive_list<Test_case>
  {
    friend Utility::Intrusive_list<Test_case>;

  public:
    Test_case(std::string, std::string, int, std::function<void()> function);

    std::string const&
    description() const;

    std::string const&
    file() const;

    int
    line() const;

    Test_case&
    next();

    Test_case&
    previous();

    void
    run();

    static
    Test_case&
    first();

    static
    Test_case&
    last();

  private:
    std::string description_;
    std::string file_;
    int line_;
    std::function<void()> function_;

  };

} // namespace art::validation

#endif
