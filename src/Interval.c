#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#include "Interval.h"

_Ipart* init__Ipart(int mode, Number* value);
void d_print__Ipart(_Ipart* input);

// TEMPLATE:
// Function description
// @param   type      identifier  Description.
// @return  type                  Description.

// Instantiates a Number struct
// @param   int       infinity    Infinity mode. -1 = negative infinity, 0 = N/A, 1 = positive infinity.
// @param   long      value       Long signed integer value. Not applicable if @param:infinity = [+/-] 1.
// @return  Number*               Pointer of the instantiated struct.
Number* init_Number(int infinity, long value)
{
  Number* ret = malloc(sizeof(Number));
  ret->infinity = infinity;

  if(infinity == -1 || infinity == 1)
    ret->value = 0;
  else
  {
    if(value < LONG_MIN)
      ret->value = LONG_MIN;
    else if(value > LONG_MAX)
      ret->value = LONG_MAX;
    else
      ret->value = value;
  }

  return ret;
}

// Instantiates an _Ipart struct
// @property internal=true
// @param   int       mode        Range mode. 0 = open point, 1 = closed point.
// @param   Number*   value       Pointer of a Number struct of the range.
// @return  _Ipart*               Pointer of the instantiated _Ipart struct.
_Ipart* init__Ipart(int mode, Number* value)
{
  _Ipart* ret = malloc(sizeof(_Ipart));
  ret->mode = mode;
  ret->value = malloc(sizeof(Number));

  memcpy(ret->value, value, sizeof(Number));

  return ret;
}

// Instantiates an Interval struct
// @param   int       startMode   Range mode of the interval start. 0 = open point, 1 = closed point.
// @param   int       startInf    Infinity mode of the interval start. @ref:init_Number.infinity.
// @param   long      startValue  Long signed integer value.
// @return  Interval*             Pointer of the instantiated Interval.
Interval* init_Interval(int startMode, int startInfinity, long startValue,
                        int endMode, int endInfinity, long endValue)
{
  Interval* ret = malloc(sizeof(Interval));
  ret->start = malloc(sizeof(_Ipart));
  ret->end = malloc(sizeof(_Ipart));

  Number* start_val = init_Number(startInfinity, startValue);
  Number* end_val = init_Number(endInfinity, endValue);

  _Ipart* start = init__Ipart(startMode, start_val);
  _Ipart* end = init__Ipart(endMode, end_val);
  free(start_val);
  free(end_val);

  memcpy(ret->start, start, sizeof(_Ipart));
  memcpy(ret->end, end, sizeof(_Ipart));
  free(start);
  free(end);

  return ret;
}

void d_print_Number(Number* input)
{
  const char* format = "Infinity:\t%d\nValue:\t\t%ld\n\n";
  printf(format, input->infinity, input->value);
}

void d_print__Ipart(_Ipart* input)
{
  const char* format = "Mode:\t\t%d\nValue:\t\t*Number\n";
  printf(format, input->mode);

  d_print_Number(input->value);
}

void d_print_Interval(Interval* input)
{
  const char* format1 = "Start:\t\t*_Ipart\n";
  const char* format2 = "End:\t\t*_Ipart\n";

  printf("%s", format1);
  d_print__Ipart(input->start);

  printf("%s", format2);
  d_print__Ipart(input->end);
}

// Prints Number
// @param   Number*   input       Pointer of the Number struct to be printed.
void print_Number(Number* input)
{
  const char* format = "%s\n";
  char* num_value = Number_toString(input);

  printf(format, num_value);

  free(num_value);
}

// Converts Number structs into a string representation
// @param   Number*   input       Pointer of the Number struct to be converted.
// @return  char*                 Pointer of the converted string.
char* Number_toString(Number* input)
{
  char* ret;

  if(input->infinity == -1)
    ret = "-∞";
  else if(input->infinity == 1)
    ret = "∞";
  else
  {
    ret = malloc(sizeof(char) * 12 + 1);
    sprintf(ret, "%ld", input->value);
  }

  return ret;
}

// Converts Interval structs into a string representation
// @param   Interval* input       Pointer of the Interval struct to be converted.
// @return  char*                 Pointer of the converted string.
char* Interval_toString(Interval* input)
{
  char* ret;

  const char* format = "%s%s, %s%s";
  char* startBracket;
  char* endBracket;
  char* startPart;
  char* endPart;

  if(input->start->mode == 0)
    startBracket = "(";
  else
    startBracket = "[";

  if(input->end->mode == 0)
    endBracket = ")";
  else
    endBracket = "]";

  startPart = Number_toString(input->start->value);
  endPart = Number_toString(input->end->value);

  ret = malloc(sizeof(char) *
      ((strlen(startBracket) * 2) + (strlen(startPart) + strlen(endPart))) + 1);
  sprintf(ret, format, startBracket, startPart, endPart, endBracket);

  return ret;
}

// Prints interval
// @param   Interval* input       Pointer of the Interval struct to be printed.
void print_Interval(Interval* input)
{
  const char* format = "%s\n";
  char* interval = Interval_toString(input);

  printf(format, interval);

  free(interval);
}
