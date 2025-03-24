#include <art/validation/teardown.hxx>

namespace art::validation
{

  Teardown::
  Teardown(std::string file, int line, std::function<void()> function)
    : file_{std::move(file)}, line_{line}, function_{function}
  {}

  std::string const&
  Teardown::
  file() const
  {
    return file_;
  }

  int
  Teardown::
  line() const
  {
    return line_;
  }

  Teardown*
  Teardown::
  next()
  {
    return Utility::Intrusive_list<Teardown>::next();
  }

  Teardown*
  Teardown::
  previous()
  {
    return Utility::Intrusive_list<Teardown>::previous();
  }

  void
  Teardown::
  run()
  {
    function_();
  }

  Teardown*
  Teardown::
  first()
  {
    return Utility::Intrusive_list<Teardown>::first();
  }

  Teardown*
  Teardown::
  last()
  {
    return Utility::Intrusive_list<Teardown>::last();
  }

} // namespace art::validation
