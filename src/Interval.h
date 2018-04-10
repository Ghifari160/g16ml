#ifndef g16ML
#define g16ML 1

#ifndef LONG_MIN
#define LONG_MIN -2147483648
#endif

#ifndef LONG_MAX
#define LONG_MAX 2147483647
#endif

typedef struct
{
  int infinity;
  long value;
} Number;

typedef struct
{
  int mode;
  Number* value;
} _Ipart;

typedef struct
{
  _Ipart* start;
  _Ipart* end;
} Interval;

Number* init_Number(int infinity, long value);
Interval* init_Interval(int startMode, int startInfinity, long startValue,
                        int endMode, int endInfinity, long endValue);

char* Number_toString(Number* input);
char* Interval_toString(Interval* input);

void print_Number(Number* input);
void print_Interval(Interval* input);

void d_print_Number(Number* input);
void d_print_Interval(Interval* input);

char* getString_Union();
char* getString_Infinity();

#endif
