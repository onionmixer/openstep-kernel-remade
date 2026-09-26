/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be98c */

void _audio_add_peak(int param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  
  if (param_4 != 0) {
    *(undefined4 *)(param_1 + *param_3 * 4) = param_2;
    iVar1 = *param_3;
    *param_3 = iVar1 + 1;
    if (iVar1 + 1 == param_4) {
      *param_3 = 0;
    }
  }
  return;
}

