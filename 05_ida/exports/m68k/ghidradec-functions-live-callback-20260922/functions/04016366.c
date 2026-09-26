
undefined4 _unp_connect2(sword *param_1,sword *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*param_1 == *param_2) {
    iVar2 = *(int *)(param_2 + 4);
    *(int *)(iVar1 + 0xc) = iVar2;
    if (*param_1 == 1) {
      *(int *)(iVar2 + 0xc) = iVar1;
      _soisconnected(param_2);
      _soisconnected(param_1);
    }
    else {
      if (*param_1 != 2) {
                    /* WARNING: Subroutine does not return */
        _panic(aUnpConnect2);
      }
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
      *(int *)(iVar2 + 0x10) = iVar1;
      _soisconnected(param_1);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x29;
  }
  return uVar3;
}

