/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba9b8 */

int FUN_001ba9b8(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x94) == '\0') {
    *param_4 = 0;
    *param_3 = 0;
  }
  else {
    uVar1 = _audio_max_peak(*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0x98));
    *param_3 = uVar1;
    uVar1 = _audio_max_peak(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0x98));
    *param_4 = uVar1;
  }
  return param_1;
}

