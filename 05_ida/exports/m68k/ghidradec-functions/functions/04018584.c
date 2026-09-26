
void sub_4018584(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    _vn_rele(iVar1);
  }
  return;
}
