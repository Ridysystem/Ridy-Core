#include "boost/atomic.hpp"

using namespace boost;

template < typename T >

class atomic : public atomics::detail::base_atomic<T>

{

public:
  atomic() = default;
  explicit atomic(T v);

  atomic(atomic const&) = delete;
  atomic& operator=(atomic const&) = delete;

public:
  bool           is_lock_free();
  vold           store(T store);
  T              load();

  T              operator=(T v) volatile;
  operator       T() volatile const;

  T              exchange(T new_value);
  bool           compare_exchange_week(T & expected, T desired);
  bool           compare_exchange_strong(T & expected, T desired);

  T&             storage() ;
  T  const&      storage() const;
};
