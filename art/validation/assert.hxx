#ifndef art__validation__assert_hxx_
#define art__validation__assert_hxx_

#include <art/validation/except.hxx>
#include <art/validation/traits.hxx>

#include <cstdint>
#include <source_location>
#include <sstream>
#include <string>

namespace art::validation::Assert
{

  template<typename T>
  void
  assert_true(T const&,
              std::string,
              std::source_location const& = std::source_location::current());

  template<typename T>
  void
  assert_false(T const&,
               std::string,
               std::source_location const& = std::source_location::current());

  template<typename T>
  void
  assert_null(T const&,
              std::string,
              std::source_location const& = std::source_location::current());

  template<typename T>
  void
  assert_not_null(T const&,
                  std::string,
                  std::source_location const& = std::source_location::current());

  template<typename T1, typename T2 = T1>
  void
  assert_equal(T1 const&,
               T2 const&,
               std::string,
               std::string,
               std::source_location const& = std::source_location::current());

  template<typename T1, typename T2 = T1>
  void
  assert_not_equal(T1 const&,
                   T2 const&,
                   std::string,
                   std::string,
                   std::source_location const& = std::source_location::current());

} // namespace art::validation::Assert

#include <art/validation/assert.txx>

#endif
