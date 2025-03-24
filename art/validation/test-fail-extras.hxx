#ifndef art__validation__test_fail_extras_hxx_
#define art__validation__test_fail_extras_hxx_

#include <cstdint>
#include <memory>

namespace art::validation
{

  class Test_fail_extras
  {
  public:
    template<typename T>
    Test_fail_extras(T extras)
      : extras_{std::make_shared<Wrapper<T>>(std::move(extras))}
    {}

    void
    print(std::ostream&) const;

  private:
    struct Abstraction
    {
      virtual
      ~Abstraction() noexcept = default;

      virtual
      void
      do_print(std::ostream&) const = 0;

    };

    template<typename T>
    struct Wrapper
      : Abstraction
    {
      template<typename... Args>
      Wrapper(Args&&... args)
        : extras{std::forward<Args>(args)...}
      {}

      void
      do_print(std::ostream& o) const override
      {
        extras.print(o);
      }

      T extras;

    };

    std::shared_ptr<Abstraction const> extras_;

  };

} // namespace art::validation

#endif
