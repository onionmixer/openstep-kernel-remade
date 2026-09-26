/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141f1c */

void _iunlock(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x44);
  *(ushort *)(param_1 + 0x44) = uVar1 & 0xfffe;
  if ((uVar1 & 0x10) != 0) {
    *(ushort *)(param_1 + 0x44) = uVar1 & 0xffee;
    _wakeup(param_1);
  }
  return;
}

