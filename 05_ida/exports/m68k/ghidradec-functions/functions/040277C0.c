
void sub_40277C0(undefined4 *param_1,int *param_2)

{
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    *param_2 = param_1[1] + (int)param_1;
    param_2[1] = (int)*(sword *)(param_1 + 2);
    param_2 = param_2 + 2;
  }
  return;
}
