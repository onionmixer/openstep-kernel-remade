/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be71c */

void _audio_mulaw8_peak(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  short sVar1;
  uint uVar2;
  
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar2 = 0;
    if (param_3 >> 2 != 0) {
      do {
        sVar1 = (&_audio_muLaw)[*param_2];
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        param_2 = param_2 + 4;
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3 >> 2);
    }
    *param_5 = *param_4;
  }
  else {
    uVar2 = 0;
    if (param_3 >> 2 != 0) {
      do {
        sVar1 = (&_audio_muLaw)[*param_2];
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        sVar1 = (&_audio_muLaw)[param_2[2]];
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_5 < (uint)(int)sVar1) {
          *param_5 = (int)sVar1;
        }
        param_2 = param_2 + 4;
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3 >> 2);
    }
  }
  return;
}

