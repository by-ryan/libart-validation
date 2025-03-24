#include <art/validation/test-result.hxx>

namespace art::validation
{

  Test_result::
  Test_result(std::string description,
              std::string file,
              int line,
              std::string message)
    : description_{std::move(description)},
      file_{std::move(file)},
      line_{line},
      message_{std::move(message)}
  {}

  Test_result::
  Test_result(std::string description,
              std::string file,
              int line,
              std::string message,
              Test_fail_extras extras)
    : description_{std::move(description)},
      file_{std::move(file)},
      line_{line},
      message_{std::move(message)},
      extras_{extras}
  {}

  std::string const&
  Test_result::
  description() const
  {
    return description_;
  }

  std::string const&
  Test_result::
  file() const
  {
    return file_;
  }

  int
  Test_result::
  line() const
  {
    return line_;
  }

  std::string const&
  Test_result::
  message() const
  {
    return message_;
  }

  void
  Test_result::
  print(std::ostream& o, bool print_extras) const
  {
    o << "test: " << description() << ": " << message() << '\n';

    if (print_extras && extras_) {
      extras_->print(o);
    }
  }

} // namespace art::validation
