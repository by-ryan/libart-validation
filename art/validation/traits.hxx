#ifndef art__validation__traits_hxx_
#define art__validation__traits_hxx_

#include <concepts>
#include <iostream>

namespace art::validation
{

  template<typename T>
  concept has_output_operator = requires(std::ostream& o, T const& value)
  {
    // check if T can be written to an std::ostream.
    //
    {
      o << value
    };

  };

} // namespace art::validation

#endif
