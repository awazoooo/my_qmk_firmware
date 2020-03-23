#include <stdio.h>
#include "crkbd.h"

char timelog_str[24] = {};
uint32_t last_time = 0;
uint32_t elapsed_time = 0;

void set_timelog(void) {
  elapsed_time = timer_elapsed32(last_time);
  last_time = timer_read32();
  snprintf(timelog_str, sizeof(timelog_str), "TTERM: %ld", elapsed_time);
}

const char *read_timelog(void) {
  return timelog_str;
}
