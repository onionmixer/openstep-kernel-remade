/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134e98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00134e98(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = _splimp();
  iVar1 = *(int *)(param_1 + 4);
  while (iVar1 == 0) {
    _sleep(param_1);
    iVar1 = *(int *)(param_1 + 4);
  }
  _splx(uVar2);
  (**(code **)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0x5c))
            (*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  _vn_rele(*(undefined4 *)(param_1 + 8));
  uVar2 = _splimp();
  puVar3 = (undefined4 *)(param_1 & 0xffffff80);
  if (*(short *)((int)puVar3 + 10) != 0) {
    *(short *)(&DAT_001e917c + *(short *)((int)puVar3 + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)puVar3 + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)puVar3 + 10) = 0;
    if (0x7f < (uint)puVar3[1]) {
      _mclput(puVar3);
    }
    *puVar3 = _mfree;
    puVar3[1] = 0;
    puVar3[0x1f] = 0;
    _mfree = puVar3;
    _splx(uVar2);
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_mfree_001dcd08);
}

