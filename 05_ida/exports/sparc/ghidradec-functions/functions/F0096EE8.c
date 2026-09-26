
void _set_intmask(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0xfeff8008;
  if (param_2 != 0) {
    puVar1 = (undefined4 *)0xfeff800c;
  }
  *puVar1 = param_1;
  return;
}
