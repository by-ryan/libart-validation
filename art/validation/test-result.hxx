#ifndef art__validation__test_result_hxx_
#define art__validation__test_result_hxx_

#include <art/validation/test-fail-extras.hxx>

#include <optional>
#include <string>

namespace art::validation
{

  class Test_result
  {
  public:
    Test_result(std::string, std::string, int, std::string);

    Test_result(std::string, std::string, int, std::string, Test_fail_extras);

    std::string const&
    description() const;

    std::string const&
    file() const;

    int
    line() const;

    std::string const&
    message() const;

    void
    print(std::ostream&, bool) const;

  private:
    std::string description_;
    std::string file_;
    int line_;
    std::string message_;
    std::optional<Test_fail_extras> extras_;

  };

} // namespace art::validation

#endif
