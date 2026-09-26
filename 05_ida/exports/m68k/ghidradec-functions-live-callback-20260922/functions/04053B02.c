
int _stack_usage(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*param_1 != -0x21524111) break;
    param_1 = param_1 + 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x3fd);
  return uVar1 * -4 + 0xff4;
}

