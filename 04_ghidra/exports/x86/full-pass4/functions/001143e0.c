/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001143e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _m_cat(int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    param_1 = (int *)*param_1;
    iVar1 = *param_1;
  }
  while( true ) {
    if (param_2 == (undefined4 *)0x0) {
      return;
    }
    uVar2 = param_1[1];
    if (0x7b < uVar2) break;
    if (0x7c < (int)(short)param_1[2] + uVar2 + (int)*(short *)(param_2 + 2)) break;
    _bcopy((void *)((int)param_2 + param_2[1]),
           (void *)((int)param_1 + (int)(short)param_1[2] + uVar2),(int)*(short *)(param_2 + 2));
    *(short *)(param_1 + 2) = (short)param_1[2] + *(short *)(param_2 + 2);
    uVar4 = _splimp();
    if (*(short *)((int)param_2 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001db1dd);
    }
    *(short *)(&DAT_001e917c + *(short *)((int)param_2 + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)param_2 + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)param_2 + 10) = 0;
    if (0x7f < (uint)param_2[1]) {
      _mclput(param_2);
    }
    puVar3 = (undefined4 *)*param_2;
    *param_2 = _mfree;
    param_2[1] = 0;
    param_2[0x1f] = 0;
    _mfree = param_2;
    _splx(uVar4);
    param_2 = puVar3;
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
  }
  *param_1 = (int)param_2;
  return;
}

