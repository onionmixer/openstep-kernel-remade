/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be374 */

void _audio_convertStereoToMono(byte *param_1,undefined2 *param_2,uint param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = param_3 >> 1;
  if (param_4 == 1) {
    while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      param_1 = param_1 + 2;
      uVar3 = _audio_shortToMulaw((int)(short)((int)((int)(short)(&_audio_muLaw)[bVar1] +
                                                     (int)(short)(&_audio_muLaw)[*pbVar4] +
                                                    ((int)(short)(&_audio_muLaw)[bVar1] +
                                                     (int)(short)(&_audio_muLaw)[*pbVar4] & 1U)) / 2
                                              ));
      *(undefined1 *)param_2 = uVar3;
      param_2 = (undefined2 *)((int)param_2 + 1);
    }
  }
  else {
    if (param_4 < 2) {
      if (param_4 == 0) {
        param_3 = param_3 >> 2;
        while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
          sVar2 = *(short *)param_1;
          pbVar4 = param_1 + 2;
          param_1 = param_1 + 4;
          iVar5 = (int)sVar2 + (int)*(short *)pbVar4 + ((int)sVar2 + (int)*(short *)pbVar4 & 1U);
          *param_2 = (short)((uint)(iVar5 - (iVar5 >> 0x1f)) >> 1);
          param_2 = param_2 + 1;
        }
        return;
      }
    }
    else if (param_4 == 3) {
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        bVar1 = *param_1;
        pbVar4 = param_1 + 1;
        param_1 = param_1 + 2;
        iVar5 = (int)(char)bVar1 + (int)(char)*pbVar4 + ((int)(char)bVar1 + (int)(char)*pbVar4 & 1U)
        ;
        *(char *)param_2 = (char)((uint)(iVar5 - (iVar5 >> 0x1f)) >> 1);
        param_2 = (undefined2 *)((int)param_2 + 1);
      }
      return;
    }
    _IOLog("Audio: unrecognized format %d in convMono\n",param_4);
  }
  return;
}

