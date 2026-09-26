/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b84cc */

void FUN_001b84cc(int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x50) = (int)param_3;
  if ((param_3 != 0) && (*(int *)(param_1 + 0x58) == 0)) {
    uVar1 = _IOMalloc(0x40);
    *(undefined4 *)(param_1 + 0x58) = uVar1;
    uVar1 = _IOMalloc(0x40);
    *(undefined4 *)(param_1 + 0x5c) = uVar1;
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0x58),0x10);
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0x5c),0x10);
  }
  return;
}

