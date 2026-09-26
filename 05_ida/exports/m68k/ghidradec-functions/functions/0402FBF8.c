
undefined4 _svckudp_freeargs(int param_1,code *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if (*(int *)(iVar1 + 8) != 0) {
    _m_freem(*(int *)(iVar1 + 8));
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  if (param_3 == 0) {
    uVar2 = 1;
  }
  else {
    *(undefined4 *)(iVar1 + 0xc) = 2;
    uVar2 = (*param_2)((undefined4 *)(iVar1 + 0xc),param_3);
  }
  return uVar2;
}
