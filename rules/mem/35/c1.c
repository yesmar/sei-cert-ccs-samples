// MEM35-C: Compliant Solution (Integer)
#include <stdint.h>
#include <stdlib.h>
 
void function(size_t len) {
  long *p;
  if (len == 0 || len > SIZE_MAX / sizeof(long)) {
    /* Handle overflow */
  }
  p = (long *)malloc(len * sizeof(long));
  if (p == NULL) {
    /* Handle error */
  }
  free(p);
}
