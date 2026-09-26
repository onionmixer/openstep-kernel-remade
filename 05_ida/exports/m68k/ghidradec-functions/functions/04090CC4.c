
undefined4 _PMGetPowerStatus(undefined4 *param_1)

{
  *param_1 = 0xff;
  param_1[1] = 0xff;
  param_1[2] = 0;
  return 0;
}
