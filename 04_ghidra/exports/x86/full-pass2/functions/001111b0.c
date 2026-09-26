/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001111b0 */

void _ttwakeup(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _spltty();
  if (*(int *)(param_1 + 0x28) != 0) {
    _selwakeup(*(int *)(param_1 + 0x28),*(uint *)(param_1 + 0x40) & 0x800);
    _selthreadclear(param_1 + 0x28);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffff7ff;
  }
  _splx(uVar1);
  if ((*(byte *)(param_1 + 0x41) & 0x40) != 0) {
    _gsignal((int)*(short *)(param_1 + 0x44),0x17);
  }
  _wakeup(param_1);
  return;
}

