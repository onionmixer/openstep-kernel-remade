
void sub_40431D2(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  *param_3 = *(undefined4 *)(param_1 + 0x18);
  *param_5 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = *param_4;
  return;
}
