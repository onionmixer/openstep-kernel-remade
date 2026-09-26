
void _disksort_init(int param_1)

{
  int iVar1;
  
  _bzero(param_1,0x26);
  sub_4036D3E(param_1);
  iVar1 = param_1 + 0xe;
  *(int *)(param_1 + 0x12) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x16) = 0x14;
  return;
}
