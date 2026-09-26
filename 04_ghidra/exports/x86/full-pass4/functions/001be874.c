/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be874 */

void _audio_linear8_peak(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar3 = 0;
    if (param_3 >> 1 != 0) {
      do {
        bVar1 = *param_2 & 0x7f | *param_2 ^ 0x80;
        if ((char)bVar1 < '\0') {
          bVar1 = -bVar1;
        }
        if (*param_4 < (uint)(int)(char)bVar1) {
          *param_4 = (int)(char)bVar1;
        }
        param_2 = param_2 + 2;
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3 >> 1);
    }
    *param_5 = *param_4;
  }
  else {
    uVar3 = 0;
    if (param_3 >> 1 != 0) {
      do {
        pbVar2 = param_2 + 1;
        bVar1 = *param_2 & 0x7f | *param_2 ^ 0x80;
        if ((char)bVar1 < '\0') {
          bVar1 = -bVar1;
        }
        if (*param_4 < (uint)(int)(char)bVar1) {
          *param_4 = (int)(char)bVar1;
        }
        param_2 = param_2 + 2;
        bVar1 = *pbVar2 & 0x7f | *pbVar2 ^ 0x80;
        if ((char)bVar1 < '\0') {
          bVar1 = -bVar1;
        }
        if (*param_5 < (uint)(int)(char)bVar1) {
          *param_5 = (int)(char)bVar1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3 >> 1);
    }
  }
  *param_5 = *param_5 << 8;
  *param_4 = *param_4 << 8;
  return;
}

