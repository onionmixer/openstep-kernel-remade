/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113ed0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _m_free(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = _splimp();
  if (*(short *)((int)param_1 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_mfree_001db1dd);
  }
  *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)param_1 + 10) = 0;
  if (0x7f < (uint)param_1[1]) {
    _mclput(param_1);
  }
  uVar1 = *param_1;
  *param_1 = _mfree;
  param_1[1] = 0;
  param_1[0x1f] = 0;
  _mfree = param_1;
  _splx(uVar2);
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  return uVar1;
}

