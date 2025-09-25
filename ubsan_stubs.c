#include <klee/klee.h>

void __ubsan_handle_add_overflow(void)
{
  klee_report_error(__FILE__, __LINE__,
                    "ubsan add overflow", "overflow.err");
}

void __ubsan_handle_divrem_overflow(void)
{
  klee_report_error(__FILE__, __LINE__,
                    "ubsan divrem overflow", "overflow.err");
}

void __ubsan_handle_sub_overflow(void)
{
  klee_report_error(__FILE__, __LINE__,
                    "ubsan sub overflow", "overflow.err");
}
