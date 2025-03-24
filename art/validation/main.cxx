#include <art/validation/main.hxx>

#include <art/validation/exec.hxx>
#include <art/validation/test-summary.hxx>

#include <cstring>

namespace art::validation
{

  int
  main(int argc, char* argv[])
  {
    int verbosity{0};
    bool print_stats{false};

    for (int i = 1; i < argc; ++i) {
      if (strcmp(argv[i], "--verbose") == 0) {
        ++verbosity;
      }
      else if (strcmp(argv[i], "-v") == 0) {
        ++verbosity;
      }
      else if (strcmp(argv[i], "--stats") == 0) {
        print_stats = true;
      }
    }

    Test_summary summary;

    bool success = exec(summary);

    bool print_summary = verbosity > 0;
    bool print_extras = verbosity > 1;

    if (print_summary) {
      summary.print(std::cout, print_extras, print_stats);
    }

    return success ? 0 : -1;
  }

} // namespace art::validation
