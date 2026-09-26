
void _ns_time_to_tsval(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = (int)(CONCAT44(param_1 % 1000,param_2) / 1000);
  param_3[1] = param_1 / 1000;
  return;
}
