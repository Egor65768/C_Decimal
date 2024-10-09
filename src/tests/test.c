#include "test.h"

int main() {
  int failed = 0;
  Suite *s21_string_test[] = {test_add(),
                              test_sub(),
                              test_mod(),
                              test_mul(),
                              test_help_func(),
                              test_div(),
                              test_is_equal(),
                              test_is_greater_or_equal(),
                              test_is_greater(),
                              test_is_less_or_equal(),
                              test_is_less(),
                              test_is_not_equal(),
                              test_funck(),
                              test_convert(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
