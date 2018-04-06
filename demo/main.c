#include <stdio.h>

#include "../src/Interval.h"

int main()
{
  // Interval #1: (-∞, ∞)
  Interval* interval1 = init_Interval(0, -1, 0, 0, 1, 0);
  // Interval #2: (-∞, -1]
  Interval* interval2 = init_Interval(0, -1, 0, 1, 0, -1);
  // Interval #3: (-1, 13)
  Interval* interval3 = init_Interval(0, 0, -1, 0, 0, 13);
  // Interval #4: [13, 17]
  Interval* interval4 = init_Interval(1, 0, 13, 1, 0, 17);
  // Interval #5: (17, ∞)
  Interval* interval5 = init_Interval(0, 0, 17, 0, 1, 0);
  // Interval #6: [–2147483648, 2147483647]
  Interval* interval6 = init_Interval(1, 0, -2147483648, 1, 0, 2147483647);
  // Interval #7: [-2147483650, 2147483650]
  // Interval will be clipped as the lower end is < LONG_MIN and the higher end
  // is > LONG_MAX
  Interval* interval7 = init_Interval(1, 0, 2147483650, 1, 0, 2147483650);

  printf("g16ML Demo Suite\n\n");

  printf("Demo #1:\t%s\n", Interval_toString(interval1));
  printf("Demo #2:\t%s ∪ %s ∪ %s ∪ %s\n",
      Interval_toString(interval2),
      Interval_toString(interval3),
      Interval_toString(interval4),
      Interval_toString(interval5));
  printf("Demo #3:\t%s\n", Interval_toString(interval6));
  printf("Demo #4:\t%s\n", Interval_toString(interval7));

  printf("\n");

  return 0;
}
