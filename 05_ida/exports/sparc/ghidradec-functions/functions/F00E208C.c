
/* WARNING: Removing unreachable block (ram,0xf00e22a8) */
/* WARNING: Removing unreachable block (ram,0xf00e22d0) */
/* WARNING: Removing unreachable block (ram,0xf00e2100) */

undefined8 _audio_mix(byte *param_1,byte *param_2,uint param_3,int param_4,int param_5)

{
  sword sVar1;
  byte bVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar4;
  undefined4 unaff_i3;
  int iVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar5 = 0;
  if (param_3 == 0) {
    iVar5 = 0;
    goto locret_F00E22DC;
  }
  if (param_5 != 0) {
    if (param_4 == 3) {
      iVar5 = param_3 - 1;
      if (iVar5 == -1) {
        iVar5 = 0;
      }
      else {
        do {
          iVar5 = iVar5 + -1;
          *param_2 = *param_1 ^ 0x80 | *param_1 & 0x7f;
          param_2 = param_2 + 1;
          param_1 = param_1 + 1;
        } while (iVar5 != -1);
        iVar5 = 0;
      }
    }
    else {
      _bcopy(param_1,param_2,param_3);
      iVar5 = 0;
    }
    goto locret_F00E22DC;
  }
  if (param_4 == 1) {
    iVar4 = param_3 - 1;
    if (iVar4 != -1) {
      bVar2 = *param_2;
      do {
        iVar3 = (int)*(sword *)(_audio_muLaw + (uint)bVar2 * 2) +
                (int)*(sword *)(_audio_muLaw + (uint)*param_1 * 2);
        param_1 = param_1 + 1;
        if (iVar3 < 0x8000) {
          if (iVar3 < -0x8000) {
            *param_2 = 0;
            goto loc_F00E229C;
          }
          bVar2 = (byte)((uint)(iVar3 * 0x10000) >> 0x10);
          _audio_shortToMulaw();
          *param_2 = bVar2;
        }
        else {
          *param_2 = 0x80;
loc_F00E229C:
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == -1) goto locret_F00E22DC;
        bVar2 = *param_2;
      } while( true );
    }
  }
  else if (param_4 < 2) {
    if (param_4 == 0) {
      iVar4 = (param_3 >> 1) - 1;
      if (iVar4 != -1) {
        sVar1 = *(sword *)param_2;
        do {
          iVar3 = (int)sVar1 + (int)*(sword *)param_1;
          param_1 = param_1 + 2;
          if (iVar3 < 0x8000) {
            if (iVar3 < -0x8000) {
              param_2[0] = 0x80;
              param_2[1] = 0;
              goto loc_F00E2190;
            }
            *(sword *)param_2 = (sword)iVar3;
          }
          else {
            param_2[0] = 0x7f;
            param_2[1] = 0xff;
loc_F00E2190:
            iVar5 = iVar5 + 1;
          }
          param_2 = param_2 + 2;
          iVar4 = iVar4 + -1;
          if (iVar4 == -1) goto locret_F00E22DC;
          sVar1 = *(sword *)param_2;
        } while( true );
      }
    }
    else {
loc_F00E22D0:
      _IOLog(aAudioUnrecogni_7);
    }
  }
  else {
    iVar4 = param_3 - 1;
    if (param_4 != 3) goto loc_F00E22D0;
    if (iVar4 != -1) {
      bVar2 = *param_2;
      do {
        iVar3 = (int)(char)(bVar2 ^ 0x80 | bVar2 & 0x7f) + (int)(char)*param_1;
        param_1 = param_1 + 1;
        if (iVar3 < 0x80) {
          if (iVar3 < -0x80) {
            *param_2 = 0;
            goto loc_F00E2208;
          }
          *param_2 = (byte)iVar3 ^ 0x80 | (byte)iVar3 & 0x7f;
        }
        else {
          *param_2 = 0xff;
loc_F00E2208:
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == -1) goto locret_F00E22DC;
        bVar2 = *param_2;
      } while( true );
    }
  }
  iVar5 = 0;
locret_F00E22DC:
  return CONCAT44(param_2,iVar5);
}
