
undefined4 _unp_externalize(int param_1)

{
  int iVar1;
  sword *psVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  uVar6 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  piVar7 = (int *)(*(int *)(param_1 + 4) + param_1);
  iVar3 = _ufavail();
  if (iVar3 < (int)uVar6) {
    iVar3 = 0;
    if (uVar6 != 0) {
      do {
        _unp_discard(*piVar7);
        *piVar7 = 0;
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar3 < (int)uVar6);
    }
    uVar4 = 0x28;
  }
  else {
    iVar3 = 0;
    if (uVar6 != 0) {
      do {
        iVar5 = _ufalloc(0);
        if (iVar5 < 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aUnpExternalize);
        }
        iVar1 = *piVar7;
        *(int *)(*(int *)(_active_u + 0x146) + iVar5 * 4) = iVar1;
        psVar2 = (sword *)(iVar1 + 0x10);
        *psVar2 = *psVar2 + -1;
        _unp_rights = _unp_rights + -1;
        *piVar7 = iVar5;
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar3 < (int)uVar6);
    }
    uVar4 = 0;
  }
  return uVar4;
}

