/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be578 */

int _audio_mix(byte *param_1,byte *param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  if (param_3 == 0) {
    local_8 = 0;
  }
  else if (param_5 == 0) {
    if (param_4 == 1) {
      while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
        iVar2 = (int)(short)(&_audio_muLaw)[*param_1] + (int)(short)(&_audio_muLaw)[*param_2];
        param_1 = param_1 + 1;
        if (iVar2 < 0x8000) {
          if (iVar2 < -0x8000) {
            *param_2 = 0;
            goto LAB_001be6e6;
          }
          bVar1 = _audio_shortToMulaw((int)(short)iVar2);
          *param_2 = bVar1;
        }
        else {
          *param_2 = 0x80;
LAB_001be6e6:
          local_8 = local_8 + 1;
        }
        param_2 = param_2 + 1;
      }
    }
    else {
      if (param_4 < 2) {
        if (param_4 == 0) {
          param_3 = param_3 >> 1;
          do {
            param_3 = param_3 - 1;
            if (param_3 == 0xffffffff) {
              return local_8;
            }
            iVar2 = (int)*(short *)param_1 + (int)*(short *)param_2;
            param_1 = param_1 + 2;
            if (iVar2 < 0x8000) {
              if (iVar2 < -0x8000) {
                param_2[0] = 0;
                param_2[1] = 0x80;
                goto LAB_001be63c;
              }
              *(short *)param_2 = (short)iVar2;
            }
            else {
              param_2[0] = 0xff;
              param_2[1] = 0x7f;
LAB_001be63c:
              local_8 = local_8 + 1;
            }
            param_2 = param_2 + 2;
          } while( true );
        }
      }
      else if (param_4 == 3) {
        do {
          param_3 = param_3 - 1;
          if (param_3 == 0xffffffff) {
            return local_8;
          }
          iVar2 = (int)(char)*param_1 + (int)(char)(*param_2 ^ 0x80 | *param_2 & 0x7f);
          param_1 = param_1 + 1;
          if (iVar2 < 0x80) {
            if (iVar2 < -0x80) {
              *param_2 = 0;
              goto LAB_001be68c;
            }
            *param_2 = (byte)iVar2 ^ 0x80 | (byte)iVar2 & 0x7f;
          }
          else {
            *param_2 = 0xff;
LAB_001be68c:
            local_8 = local_8 + 1;
          }
          param_2 = param_2 + 1;
        } while( true );
      }
      _IOLog("Audio: unrecognized format %d in mix\n",param_4);
    }
  }
  else if (param_4 == 3) {
    while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
      *param_2 = *param_1 ^ 0x80 | *param_1 & 0x7f;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  else {
    _bcopy(param_1,param_2,param_3);
  }
  return local_8;
}

