
void sub_402F0F2(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    *param_2 = 6;
  }
  else if (param_1 == 1) {
    *param_2 = 7;
  }
  else {
    *param_2 = 0x10;
    param_2[1] = 1;
    param_2[2] = param_1;
  }
  return;
}

