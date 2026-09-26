/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba95c */

void FUN_001ba95c(int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  
  *(char *)(param_1 + 0x94) = param_3;
  if ((param_3 != '\0') && (*(int *)(param_1 + 0x9c) == 0)) {
    uVar1 = _IOMalloc(0x40);
    *(undefined4 *)(param_1 + 0x9c) = uVar1;
    uVar1 = _IOMalloc(0x40);
    *(undefined4 *)(param_1 + 0xa0) = uVar1;
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0x9c),0x10);
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0xa0),0x10);
  }
  return;
}

