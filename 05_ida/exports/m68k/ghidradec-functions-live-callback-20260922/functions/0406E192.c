
void sub_406E192(int param_1,undefined *param_2)

{
  word *pwVar1;
  
  pwVar1 = (word *)(param_2 + 10);
  *(undefined *)pwVar1 = 7;
  *pwVar1 = *pwVar1 & 0xff00;
  *param_2 = *(undefined *)(param_1 + 0x17d);
  *(undefined4 *)(param_2 + 2) = 10000;
  *(undefined4 *)(param_2 + 6) = 1;
  *(undefined4 *)(param_2 + 0x1a) = 2;
  *(undefined4 *)(param_2 + 0x1e) = 0;
  *(undefined4 *)(param_2 + 0x22) = 0;
  *(undefined4 *)(param_2 + 0x36) = 2;
  return;
}

