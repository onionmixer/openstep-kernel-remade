/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bdf50 */

int _audio_scaleSamples(byte *param_1,undefined2 *param_2,uint param_3,int param_4,int param_5,
                       int param_6,int param_7)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = 0;
  iVar2 = param_6 >> 8;
  iVar5 = param_7 >> 8;
  if (param_4 == 1) {
    if (param_5 == 1) {
      while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
        iVar3 = (int)(short)(&_audio_muLaw)[*param_1] * ((iVar2 + iVar5) / 2) >> 7;
        param_1 = param_1 + 1;
        if (iVar3 < 0x8000) {
          if (iVar3 < -0x8000) {
            *(undefined1 *)param_2 = 0;
            goto LAB_001be18e;
          }
          uVar1 = _audio_shortToMulaw((int)(short)iVar3);
          *(undefined1 *)param_2 = uVar1;
        }
        else {
          *(undefined1 *)param_2 = 0x80;
LAB_001be18e:
          iVar8 = iVar8 + 1;
        }
        param_2 = (undefined2 *)((int)param_2 + 1);
      }
    }
    else if (param_5 == 2) {
      param_3 = param_3 >> 1;
      while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
        iVar3 = (short)(&_audio_muLaw)[*param_1] * iVar2 >> 7;
        if (iVar3 < 0x8000) {
          if (iVar3 < -0x8000) {
            *(undefined1 *)param_2 = 0;
            goto LAB_001be1ea;
          }
          uVar1 = _audio_shortToMulaw((int)(short)iVar3);
          *(undefined1 *)param_2 = uVar1;
        }
        else {
          *(undefined1 *)param_2 = 0x80;
LAB_001be1ea:
          iVar8 = iVar8 + 1;
        }
        puVar4 = (undefined1 *)((int)param_2 + 1);
        iVar3 = (short)(&_audio_muLaw)[param_1[1]] * iVar5 >> 7;
        param_1 = param_1 + 2;
        if (iVar3 < 0x8000) {
          if (iVar3 < -0x8000) {
            *puVar4 = 0;
            goto LAB_001be22e;
          }
          uVar1 = _audio_shortToMulaw((int)(short)iVar3);
          *puVar4 = uVar1;
        }
        else {
          *puVar4 = 0x80;
LAB_001be22e:
          iVar8 = iVar8 + 1;
        }
        param_2 = param_2 + 1;
      }
    }
  }
  else {
    if (param_4 < 2) {
      if (param_4 == 0) {
        uVar7 = param_3 >> 1;
        if (param_5 != 1) {
          if (param_5 != 2) {
            return 0;
          }
          param_3 = param_3 >> 2;
          while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
            pbVar6 = param_1 + 2;
            *param_2 = (short)((uint)(*(short *)param_1 * param_6) >> 0xf);
            param_1 = param_1 + 4;
            param_2[1] = (short)((uint)(*(short *)pbVar6 * param_7) >> 0xf);
            param_2 = param_2 + 2;
          }
          return 0;
        }
        do {
          uVar7 = uVar7 - 1;
          if (uVar7 == 0xffffffff) {
            return iVar8;
          }
          iVar2 = (int)*(short *)param_1 * ((param_6 + param_7) / 2) >> 0xf;
          param_1 = param_1 + 2;
          if (iVar2 < 0x8000) {
            if (iVar2 < -0x8000) {
              *param_2 = 0x8000;
              goto LAB_001bdfe4;
            }
            *param_2 = (short)iVar2;
          }
          else {
            *param_2 = 0x7fff;
LAB_001bdfe4:
            iVar8 = iVar8 + 1;
          }
          param_2 = param_2 + 1;
        } while( true );
      }
    }
    else if (param_4 == 3) {
      if (param_5 == 1) {
        do {
          param_3 = param_3 - 1;
          if (param_3 == 0xffffffff) {
            return iVar8;
          }
          iVar3 = (int)(char)*param_1 * ((iVar2 + iVar5) / 2) >> 7;
          param_1 = param_1 + 1;
          if (iVar3 < 0x80) {
            if (iVar3 < -0x80) {
              *(undefined1 *)param_2 = 0x80;
              goto LAB_001be0a0;
            }
            *(char *)param_2 = (char)iVar3;
          }
          else {
            *(undefined1 *)param_2 = 0x7f;
LAB_001be0a0:
            iVar8 = iVar8 + 1;
          }
          param_2 = (undefined2 *)((int)param_2 + 1);
        } while( true );
      }
      if (param_5 != 2) {
        return 0;
      }
      param_3 = param_3 >> 1;
      do {
        param_3 = param_3 - 1;
        if (param_3 == 0xffffffff) {
          return iVar8;
        }
        iVar3 = (char)*param_1 * iVar2 >> 7;
        if (iVar3 < 0x80) {
          if (iVar3 < -0x80) {
            *(undefined1 *)param_2 = 0x80;
            goto LAB_001be0e0;
          }
          *(char *)param_2 = (char)iVar3;
        }
        else {
          *(undefined1 *)param_2 = 0x7f;
LAB_001be0e0:
          iVar8 = iVar8 + 1;
        }
        puVar4 = (undefined1 *)((int)param_2 + 1);
        iVar3 = (char)param_1[1] * iVar5 >> 7;
        param_1 = param_1 + 2;
        if (iVar3 < 0x80) {
          if (iVar3 < -0x80) {
            *puVar4 = 0x80;
            goto LAB_001be104;
          }
          *puVar4 = (char)iVar3;
        }
        else {
          *puVar4 = 0x7f;
LAB_001be104:
          iVar8 = iVar8 + 1;
        }
        param_2 = param_2 + 1;
      } while( true );
    }
    _IOLog("Audio: unrecognized format %d in scaleSamples\n",param_4);
  }
  return iVar8;
}

