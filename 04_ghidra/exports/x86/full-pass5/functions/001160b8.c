/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001160b8 */

void _sohasoutofband(int param_1)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = *(short *)(param_1 + 0x5a);
  if (sVar1 < 0) {
    _gsignal(-(int)sVar1,0x10);
  }
  else if ((0 < sVar1) && (uVar2 = _pfind((int)sVar1), uVar2 != 0)) {
    _psignal(uVar2,(char *)0x10);
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    _selwakeup(*(int *)(param_1 + 0x34),*(byte *)(param_1 + 0x38) & 0x10);
    _selthreadclear(param_1 + 0x34);
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xef;
  }
  return;
}

