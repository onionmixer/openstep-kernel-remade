/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011142c */

void _ttselwakeup(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _spltty();
  if (*(int *)(param_1 + 0x28) != 0) {
    _selwakeup(*(int *)(param_1 + 0x28),*(uint *)(param_1 + 0x40) & 0x800);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffff7ff;
    _selthreadclear(param_1 + 0x28);
  }
  _splx(uVar1);
  return;
}

