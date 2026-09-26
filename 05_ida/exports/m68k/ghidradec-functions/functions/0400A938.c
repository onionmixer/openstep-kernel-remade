
void _timevalfix(int *param_1)

{
  if (param_1[1] < 0) {
    *param_1 = *param_1 + -1;
    param_1[1] = param_1[1] + 1000000;
  }
  if (999999 < param_1[1]) {
    *param_1 = *param_1 + 1;
    param_1[1] = param_1[1] + -1000000;
  }
  return;
}
