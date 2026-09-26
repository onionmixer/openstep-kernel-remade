/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fccc */

void _runlock(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(param_1 + 0x6c);
  *(short *)(param_1 + 0x6c) = sVar1 + -1;
  if ((short)(sVar1 + -1) < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_RUNLOCK_001dc557);
  }
  if (*(short *)(param_1 + 0x6c) == 0) {
    uVar2 = *(ushort *)(param_1 + 0x60);
    *(ushort *)(param_1 + 0x60) = uVar2 & 0xffde;
    if ((uVar2 & 2) != 0) {
      *(ushort *)(param_1 + 0x60) = uVar2 & 0xffdc;
      _wakeup(param_1);
    }
  }
  return;
}

