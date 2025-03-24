#include <art/validation/test-case.hxx>

namespace art::validation
{

  Test_case::
  Test_case(std::string description,
            std::string file,
            int line,
            std::function<void()> function)
    : description_{std::move(description)},
      file_{std::move(file)},
      line_{line},
      function_{function}
  {}

  std::string const&
  Test_case::
  description() const
  {
    return description_;
  }

  std::string const&
  Test_case::
  file() const
  {
    return file_;
  }

  int
  Test_case::
  line() const
  {
    return line_;
  }

  Test_case&
  Test_case::
  next()
  {
    return *Utility::Intrusive_list<Test_case>::next();
  }

  Test_case&
  Test_case::
  previous()
  {
    return *Utility::Intrusive_list<Test_case>::previous();
  }

  void
  Test_case::
  run()
  {
    function_();
  }

  Test_case&
  Test_case::
  first()
  {
    return *Utility::Intrusive_list<Test_case>::first();
  }

  Test_case&
  Test_case::
  last()
  {
    return *Utility::Intrusive_list<Test_case>::last();
  }

} // namespace art::validation
