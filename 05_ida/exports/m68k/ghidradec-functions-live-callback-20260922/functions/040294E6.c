
void _rinval(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = _rtable;
  do {
    iVar1 = *(int *)puVar4;
    while (iVar3 = iVar1, iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 8);
      iVar2 = iVar3 + 0xc;
      if (param_1 == *(int *)(iVar3 + 0x30)) {
        _rp_rmhash(iVar3);
        *(sword *)(iVar3 + 0x12) = *(sword *)(iVar3 + 0x12) + 1;
        _binvalfree(iVar2);
        _dnlc_purge_vp(iVar2);
        if (1 < *(word *)(iVar3 + 0x12)) {
          sub_4029110(iVar3);
        }
        _vn_rele(iVar2);
      }
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
  } while (puVar4 < _unixauthtab);
  return;
}

