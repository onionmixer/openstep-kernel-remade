/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001437b0 */

undefined4 FUN_001437b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar1 = *(int *)(param_1 + 0x128);
  iVar3 = _iflush((int)*(short *)(iVar1 + 4));
  if ((iVar3 < 0) && ((param_2 == 0 || (iVar3 < 0)))) {
    uVar4 = 0x10;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar1 + 0xc) + 0x20);
    bVar5 = *(char *)(iVar2 + 0xd2) == '\0';
    if ((bVar5) && (*(char *)(iVar2 + 0xd1) == '\x02')) {
      *(undefined1 *)(iVar2 + 0xd1) = 1;
      _sbupdate(iVar1);
    }
    _kfree(*(undefined4 *)(iVar2 + 0x2d8),*(undefined4 *)(iVar2 + 0x9c));
    _brelse(*(undefined4 *)(iVar1 + 0xc));
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined2 *)(iVar1 + 4) = 0;
    if (iVar3 == 0) {
      (**(code **)(*(int *)(*(int *)(iVar1 + 8) + 0x1c) + 4))
                (*(int *)(iVar1 + 8),bVar5,1,*(undefined4 *)(_active_u + 0x1c));
      _binval(*(undefined4 *)(iVar1 + 8));
      _vn_rele(*(undefined4 *)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 8) = 0;
      iVar3 = _mounttab;
      if (iVar1 == _mounttab) {
        _mounttab = *(int *)(iVar1 + 0x20);
      }
      else {
        for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x20)) {
          if (*(int *)(iVar3 + 0x20) == iVar1) {
            *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
          }
        }
      }
      _kfree(iVar1,0x24);
    }
    uVar4 = 0;
  }
  return uVar4;
}

