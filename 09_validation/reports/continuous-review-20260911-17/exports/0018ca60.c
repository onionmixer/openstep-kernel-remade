
void _linw(undefined2 param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  
  while (param_3 != 0) {
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  }
  return;
}

