
void _rfree(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x30) + 0x126) + 0x16);
  *piVar1 = *piVar1 + -1;
  _rinactive(param_1);
  sub_402930E(param_1,1);
  return;
}
