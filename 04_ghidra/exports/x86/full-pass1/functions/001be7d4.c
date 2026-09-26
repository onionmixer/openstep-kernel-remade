/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be7d4 */

void _audio_linear16_peak(int param_1,short *param_2,uint param_3,uint *param_4,uint *param_5)

{
  short sVar1;
  uint uVar2;
  
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar2 = 0;
    if (param_3 >> 1 != 0) {
      do {
        sVar1 = *param_2;
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        param_2 = param_2 + 2;
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3 >> 1);
    }
    *param_5 = *param_4;
  }
  else {
    uVar2 = 0;
    if (param_3 >> 1 != 0) {
      do {
        sVar1 = *param_2;
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        sVar1 = param_2[1];
        param_2 = param_2 + 2;
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_5 < (uint)(int)sVar1) {
          *param_5 = (int)sVar1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3 >> 1);
    }
  }
  return;
}

