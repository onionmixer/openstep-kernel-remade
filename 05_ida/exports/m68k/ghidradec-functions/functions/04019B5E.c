
void _pn_set(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  
  param_1[1] = *param_1;
  piVar1 = param_1 + 2;
  _copystr(param_2,param_1[1],0x400,piVar1);
  *piVar1 = *piVar1 + -1;
  return;
}
