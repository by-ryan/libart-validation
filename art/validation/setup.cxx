#include <art/validation/setup.hxx>

namespace art::validation
{

  Setup::
  Setup(std::string file, int line, std::function<void()> function)
    : file_{std::move(file)}, line_{line}, function_{function}
  {}

  std::string const&
  Setup::
  file() const
  {
    return file_;
  }

  int
  Setup::
  line() const
  {
    return line_;
  }

  Setup*
  Setup::
  next()
  {
    return Utility::Intrusive_list<Setup>::next();
  }

  Setup*
  Setup::
  previous()
  {
    return Utility::Intrusive_list<Setup>::previous();
  }

  void
  Setup::
  run()
  {
    function_();
  }

  Setup*
  Setup::
  first()
  {
    return Utility::Intrusive_list<Setup>::first();
  }

  Setup*
  Setup::
  last()
  {
    return Utility::Intrusive_list<Setup>::last();
  }

} // namespace art::validation
