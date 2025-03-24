#ifndef art__validation__utility_hxx_
#define art__validation__utility_hxx_

#include <cstddef>

namespace art::validation::Utility
{

  template<typename T>
  class Intrusive_list
  {
  protected:
    Intrusive_list()
    {
      if (!first_ || !last_) {
        first_ = this;
        last_ = this;
      }

      first_->prev_ = this;
      last_->next_ = this;

      prev_ = last_;
      next_ = first_;

      last_ = this;

      ++counter_;
    }

    Intrusive_list(Intrusive_list const&) = delete;
    Intrusive_list(Intrusive_list&&) = delete;

    ~Intrusive_list() noexcept
    {
      if (first_ == this) {
        first_ = next_;
      }

      if (last_ == this) {
        last_ = prev_;
      }

      prev_->next_ = next_;
      next_->prev_ = prev_;

      --counter_;
    }

    Intrusive_list& operator=(Intrusive_list const&) = delete;
    Intrusive_list& operator=(Intrusive_list&&) = delete;

    T*
    previous()
    {
      return static_cast<T*>(prev_);
    }

    T*
    next()
    {
      return static_cast<T*>(next_);
    }

    static
    T*
    first()
    {
      return static_cast<T*>(first_);
    }

    static
    T*
    last()
    {
      return static_cast<T*>(last_);
    }

    static
    std::size_t
    count()
    {
      return counter_;
    }

  private:
    Intrusive_list<T>* prev_{nullptr};
    Intrusive_list<T>* next_{nullptr};

    static Intrusive_list<T>* first_;
    static Intrusive_list<T>* last_;

    static std::size_t counter_;

  };

  template<typename T>
  Intrusive_list<T>* Intrusive_list<T>::first_{nullptr};

  template<typename T>
  Intrusive_list<T>* Intrusive_list<T>::last_{nullptr};

  template<typename T>
  std::size_t Intrusive_list<T>::counter_{0};

  template<typename T>
  class Current
  {
  public:
    explicit
    Current(T* current)
    {
      current_ = current;
    }

    ~Current() noexcept
    {
      current_ = nullptr;
    }

    static
    T*
    get()
    {
      return current_;
    }

  private:
    static T* current_;

  };

  template<typename T>
  T* Current<T>::current_{nullptr};

} // namespace art::validation::Utility

#endif
