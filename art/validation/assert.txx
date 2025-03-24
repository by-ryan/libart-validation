namespace art::validation::Assert
{

  namespace
  {

    class Unary_expression_failure
    {
    public:
      Unary_expression_failure(std::string message,
                               std::string file,
                               std::uint32_t line,
                               std::string expr,
                               std::string val)
        : message_{std::move(message)},
          file_{std::move(file)},
          line_{line},
          expr_{std::move(expr)},
          val_{std::move(val)}
      {}

      void
      print(std::ostream& o) const
      {
        o << "  " << message_ << '\n';
        o << "    source: " << file_ << ':' << line_ << ":\n";
        o << "      expression: " << expr_ << '\n';
        o << "      value     : " << val_ << '\n';
      }

    private:
      std::string message_;
      std::string file_;
      std::uint32_t line_;
      std::string expr_;
      std::string val_;

    };

    class Binary_expression_failure
    {
    public:
      Binary_expression_failure(std::string message,
                                std::string file,
                                std::uint32_t line,
                                std::string lhs_expr,
                                std::string lhs_val,
                                std::string rhs_expr,
                                std::string rhs_val)
        : message_{std::move(message)},
          file_{std::move(file)},
          line_{line},
          lhs_expr_{std::move(lhs_expr)},
          lhs_val_{std::move(lhs_val)},
          rhs_expr_{std::move(rhs_expr)},
          rhs_val_{std::move(rhs_val)}
      {}

      void
      print(std::ostream& o) const
      {
        o << "  " << message_ << '\n';
        o << "    source: " << file_ << ':' << line_ << ":\n";
        o << "      left-hand expression : " << lhs_expr_ << '\n';
        o << "      left-hand value      : " << lhs_val_ << '\n';
        o << "      right-hand expression: " << rhs_expr_ << '\n';
        o << "      right-hand value     : " << rhs_val_ << '\n';
      }

    private:
      std::string message_;
      std::string file_;
      std::uint32_t line_;
      std::string lhs_expr_;
      std::string lhs_val_;
      std::string rhs_expr_;
      std::string rhs_val_;

    };

  } // namespace

  template<typename T>
  void
  assert_true(T const& value,
              std::string expr,
              std::source_location const& source)
  {
    if (value == true) {
      return;
    }

    std::string expr_str;

    if constexpr (has_output_operator<T>) {
      std::stringstream str;
      str << value;
      expr_str = str.str();
    }

    throw Fail{
      Unary_expression_failure{
        "expected expression to be true; was false",
        source.file_name(),
        source.line(),
        std::move(expr),
        std::move(expr_str)
      }
    };
  }

  template<typename T>
  void
  assert_false(T const& value,
               std::string expr,
               std::source_location const& source)
  {
    if (value == false) {
      return;
    }

    std::string expr_str;

    if constexpr (has_output_operator<T>) {
      std::stringstream str;
      str << value;
      expr_str = str.str();
    }

    throw Fail{
      Unary_expression_failure{
        "expected expression to be false; was true",
        source.file_name(),
        source.line(),
        std::move(expr),
        std::move(expr_str)
      }
    };
  }

  template<typename T>
  void
  assert_null(T const& value,
              std::string expr,
              std::source_location const& source)
  {
    if (value == nullptr) {
      return;
    }

    std::string expr_str;

    if constexpr (has_output_operator<T>) {
      std::stringstream str;
      str << value;
      expr_str = str.str();
    }

    throw Fail{
      Unary_expression_failure{
        "expected expression to be nullptr; was not",
        source.file_name(),
        source.line(),
        std::move(expr),
        std::move(expr_str)
      }
    };
  }

  template<typename T1, typename T2>
  void
  assert_equal(T1 const& lhs,
               T2 const& rhs,
               std::string lhs_expr,
               std::string rhs_expr,
               std::source_location const& source)
  {
    if (lhs == rhs) {
      return;
    }

    std::string lhs_val;
    std::string rhs_val;

    if constexpr (has_output_operator<T1>) {
      std::stringstream str;
      str << lhs;
      lhs_val = str.str();
    }

    if constexpr (has_output_operator<T2>) {
      std::stringstream str;
      str << rhs;
      rhs_val = str.str();
    }

    throw Fail{
      Binary_expression_failure{
        "expected lhs to equal rhs; they did not",
        source.file_name(),
        source.line(),
        std::move(lhs_expr),
        std::move(lhs_val),
        std::move(rhs_expr),
        std::move(rhs_val)
      }
    };
  }

  template<typename T1, typename T2>
  void
  assert_not_equal(T1 const& lhs,
                   T2 const& rhs,
                   std::string lhs_expr,
                   std::string rhs_expr,
                   std::source_location const& source)
  {
    if (lhs != rhs) {
      return;
    }

    std::string lhs_val;
    std::string rhs_val;

    if constexpr (has_output_operator<T1>) {
      std::stringstream str;
      str << lhs;
      lhs_val = str.str();
    }

    if constexpr (has_output_operator<T2>) {
      std::stringstream str;
      str << rhs;
      rhs_val = str.str();
    }

    throw Fail{
      Binary_expression_failure{
        "expected lhs to not equal rhs; they did not",
        source.file_name(),
        source.line(),
        std::move(lhs_expr),
        std::move(lhs_val),
        std::move(rhs_expr),
        std::move(rhs_val)
      }
    };
  }

} // namespace art::validation::Assert
