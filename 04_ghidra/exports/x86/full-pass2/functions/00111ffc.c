/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111ffc */

void _ptsstart(int param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(&DAT_001e56d4 + (uint)(byte)*(short *)(param_1 + 0x38) * 0x10);
  if ((*(short *)(param_1 + 0x38) != 0) && ((*(byte *)(param_1 + 0x41) & 1) == 0)) {
    if ((*puVar1 & 0x10) != 0) {
      *puVar1 = *puVar1 & 0xffffffef;
      *(undefined1 *)(puVar1 + 3) = 8;
    }
    _ptcwakeup(param_1,1);
  }
  return;
}

