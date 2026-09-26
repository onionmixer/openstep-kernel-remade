/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be960 */

uint _audio_max_peak(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
  }
  return uVar2;
}

