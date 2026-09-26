
void _set_calendar_time_value(int *param_1)

{
  _set_clock(0,(sqword)param_1[1] * 1000 + (sqword)*param_1 * 1000000000);
  return;
}
