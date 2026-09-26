
int _vno_close(int param_1)

{
  undefined4 uVar1;
  undefined uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x16);
  if ((*(sword *)(param_1 + 0xe) == 1) && ((*(uint *)(param_1 + 8) & 0x180) != 0)) {
    _vno_bsd_unlock(param_1,0x180);
  }
  uVar2 = _vn_close(uVar1,*(undefined4 *)(param_1 + 8),(int)*(sword *)(param_1 + 0xe));
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(sword *)(param_1 + 0xe) == 1) {
    _vn_rele(uVar1);
  }
  return (int)*(char *)(dword_40B57D4 + 100);
}
