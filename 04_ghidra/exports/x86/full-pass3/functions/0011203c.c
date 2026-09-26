/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011203c */

void _ptcwakeup(int param_1,uint param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(uint **)(&DAT_001e56d4 + (uint)(byte)*(short *)(param_1 + 0x38) * 0x10);
  if (*(short *)(param_1 + 0x38) != 0) {
    if ((param_2 & 1) != 0) {
      uVar2 = _spltty();
      if (puVar1[1] != 0) {
        _selwakeup(puVar1[1],*puVar1 & 1);
        _selthreadclear(puVar1 + 1);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
      _splx(uVar2);
      _wakeup(param_1 + 0x1c);
    }
    if ((param_2 & 2) != 0) {
      uVar2 = _spltty();
      if (puVar1[2] != 0) {
        _selwakeup(puVar1[2],*puVar1 & 2);
        _selthreadclear(puVar1 + 2);
        *puVar1 = *puVar1 & 0xfffffffd;
      }
      _splx(uVar2);
      _wakeup(param_1 + 4);
    }
  }
  return;
}

