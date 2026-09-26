
undefined4 _xxx_host_info(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = _machine_info;
  param_2[1] = dword_40C22CC;
  param_2[2] = dword_40C22D0;
  param_2[3] = dword_40C22D4;
  param_2[4] = dword_40C22D8;
  return 0;
}
