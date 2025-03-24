#ifndef art__validation__teardown_hxx_
#define art__validation__teardown_hxx_

#include <art/validation/utility.hxx>

#include <functional>
#include <source_location>
#include <string>

namespace art::validation
{

  class Teardown
    : Utility::Intrusive_list<Teardown>
  {
    friend Utility::Intrusive_list<Teardown>;

  public:
    Teardown(std::string, int, std::function<void()> function);

    std::string const&
    file() const;

    int
    line() const;

    Teardown*
    next();

    Teardown*
    previous();

    void
    run();

    static
    Teardown*
    first();

    static
    Teardown*
    last();

  private:
    std::string file_;
    int line_;
    std::function<void()> function_;

  };

} // namespace art::validation

#endif

