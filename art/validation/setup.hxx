#ifndef art__validation__setup_hxx_
#define art__validation__setup_hxx_

#include <art/validation/utility.hxx>

#include <functional>
#include <source_location>
#include <string>

namespace art::validation
{

  class Setup
    : Utility::Intrusive_list<Setup>
  {
    friend Utility::Intrusive_list<Setup>;

  public:
    Setup(std::string, int, std::function<void()> function);

    std::string const&
    file() const;

    int
    line() const;

    Setup*
    next();

    Setup*
    previous();

    void
    run();

    static
    Setup*
    first();

    static
    Setup*
    last();

  private:
    std::string file_;
    int line_;
    std::function<void()> function_;

  };

} // namespace art::validation

#endif

