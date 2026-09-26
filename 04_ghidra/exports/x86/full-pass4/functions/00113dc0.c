/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113dc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _m_get(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = _splimp();
  puVar3 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)_m_more(param_1,param_2);
  }
  else {
    if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&DAT_001db1d3);
    }
    *(short *)((int)_mfree + 10) = (short)param_2;
    _DAT_001e917c = _DAT_001e917c + -1;
    *(short *)(&DAT_001e917c + param_2 * 2) = *(short *)(&DAT_001e917c + param_2 * 2) + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar3[1] = 0xc;
  }
  _splx(uVar2);
  return puVar3;
}

