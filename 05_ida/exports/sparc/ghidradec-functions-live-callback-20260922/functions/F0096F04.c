
void _set_intreg(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0xfeff4004;
  if (param_2 != 0) {
    puVar1 = (undefined4 *)0xfeff4008;
  }
  *puVar1 = param_1;
  return;
}

