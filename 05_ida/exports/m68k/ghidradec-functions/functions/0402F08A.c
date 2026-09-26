
void sub_402F08A(undefined4 param_1,undefined4 *param_2)

{
  switch(param_1) {
  case :
    *param_2 = 0;
    break;
  case :
    *param_2 = 8;
    break;
  case :
    *param_2 = 9;
    break;
  case :
    *param_2 = 10;
    break;
  case :
    *param_2 = 0xb;
    break;
  case :
    *param_2 = 0xc;
    break;
  :
    *param_2 = 0x10;
    param_2[1] = 0;
    param_2[2] = param_1;
  }
  return;
}
