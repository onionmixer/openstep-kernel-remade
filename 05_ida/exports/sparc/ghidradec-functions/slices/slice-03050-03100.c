/* GHIDRADEC_FUNCTION index=3050 start=0xf00e208c */

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
/* GHIDRADEC_FUNCTION index=3051 start=0xf00e22e4 */

undefined8 _audio_mulaw8_peak(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar2 = 0;
    if (param_3 >> 2 != 0) {
      do {
        sVar1 = *(sword *)(_audio_muLaw + (uint)*param_2 * 2);
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        uVar2 = uVar2 + 1;
        param_2 = param_2 + 4;
      } while (uVar2 < param_3 >> 2);
    }
    *param_5 = *param_4;
  }
  else {
    uVar2 = 0;
    if (param_3 >> 2 != 0) {
      do {
        sVar1 = *(sword *)(_audio_muLaw + (uint)*param_2 * 2);
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        sVar1 = *(sword *)(_audio_muLaw + (uint)param_2[2] * 2);
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_5 < (uint)(int)sVar1) {
          *param_5 = (int)sVar1;
        }
        uVar2 = uVar2 + 1;
        param_2 = param_2 + 4;
      } while (uVar2 < param_3 >> 2);
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3052 start=0xf00e2408 */

undefined8 _audio_linear16_peak(int param_1,word *param_2,uint param_3,uint *param_4,uint *param_5)

{
  word wVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  word *pwVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar4 = 0;
    if (param_3 >> 1 == 0) {
      uVar2 = *param_4;
    }
    else {
      do {
        iVar3 = (uint)*param_2 * 0x10000;
        if (iVar3 < 0) {
          iVar3 = (uint)*param_2 * -0x10000;
        }
        if (*param_4 < (uint)(iVar3 >> 0x10)) {
          *param_4 = iVar3 >> 0x10;
        }
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 2;
      } while (uVar4 < param_3 >> 1);
      uVar2 = *param_4;
    }
    *param_5 = uVar2;
  }
  else {
    uVar4 = 0;
    if (param_3 >> 1 != 0) {
      wVar1 = *param_2;
      while( true ) {
        iVar3 = (uint)wVar1 * 0x10000;
        pwVar5 = param_2 + 1;
        if (iVar3 < 0) {
          iVar3 = (uint)wVar1 * -0x10000;
        }
        if (*param_4 < (uint)(iVar3 >> 0x10)) {
          *param_4 = iVar3 >> 0x10;
        }
        iVar3 = (uint)*pwVar5 * 0x10000;
        param_2 = param_2 + 2;
        if (iVar3 < 0) {
          iVar3 = (uint)*pwVar5 * -0x10000;
        }
        if (*param_5 < (uint)(iVar3 >> 0x10)) {
          *param_5 = iVar3 >> 0x10;
        }
        uVar4 = uVar4 + 1;
        if (param_3 >> 1 <= uVar4) break;
        wVar1 = *param_2;
      }
    }
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3053 start=0xf00e2508 */

undefined8 _audio_linear8_peak(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  byte *pbVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar4 = 0;
    if (param_3 >> 1 == 0) {
      uVar1 = *param_4;
    }
    else {
      do {
        bVar3 = *param_2 ^ 0x80;
        bVar2 = bVar3 | *param_2 & 0x7f;
        if ((bVar3 & 0x80) != 0) {
          bVar2 = -bVar2;
        }
        if (*param_4 < (uint)(int)(char)bVar2) {
          *param_4 = (int)(char)bVar2;
        }
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 2;
      } while (uVar4 < param_3 >> 1);
      uVar1 = *param_4;
    }
    *param_5 = uVar1;
  }
  else {
    uVar4 = 0;
    if (param_3 >> 1 == 0) {
      uVar1 = *param_5;
      goto loc_F00E2628;
    }
    bVar2 = *param_2;
    while( true ) {
      pbVar5 = param_2 + 1;
      bVar3 = bVar2 ^ 0x80 | bVar2 & 0x7f;
      if (((bVar2 ^ 0x80) & 0x80) != 0) {
        bVar3 = -bVar3;
      }
      if (*param_4 < (uint)(int)(char)bVar3) {
        *param_4 = (int)(char)bVar3;
      }
      param_2 = param_2 + 2;
      bVar3 = *pbVar5 ^ 0x80;
      bVar2 = bVar3 | *pbVar5 & 0x7f;
      if ((bVar3 & 0x80) != 0) {
        bVar2 = -bVar2;
      }
      if (*param_5 < (uint)(int)(char)bVar2) {
        *param_5 = (int)(char)bVar2;
      }
      uVar4 = uVar4 + 1;
      if (param_3 >> 1 <= uVar4) break;
      bVar2 = *param_2;
    }
  }
  uVar1 = *param_5;
loc_F00E2628:
  *param_5 = uVar1 << 8;
  *param_4 = *param_4 << 8;
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3054 start=0xf00e2644 */

undefined8 _audio_clear_peaks(undefined4 *param_1,int param_2)

{
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
  undefined4 unaff_i3;
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
  while (param_2 = param_2 + -1, param_2 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return CONCAT44(0xffffffff,param_1);
}
/* GHIDRADEC_FUNCTION index=3055 start=0xf00e266c */

undefined8 _audio_max_peak(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
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
  undefined4 unaff_i3;
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
  uVar2 = 0;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
  }
  return CONCAT44(0xffffffff,uVar2);
}
/* GHIDRADEC_FUNCTION index=3056 start=0xf00e26a0 */

undefined8 _audio_add_peak(int param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
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
  undefined4 unaff_i3;
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
  if (param_4 != 0) {
    *(undefined4 *)(param_1 + *param_3 * 4) = param_2;
    iVar1 = *param_3;
    *param_3 = iVar1 + 1;
    if (iVar1 + 1 == param_4) {
      *param_3 = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3057 start=0xf00e26dc */

/* WARNING: Removing unreachable block (ram,0xf00e2758) */
/* WARNING: Removing unreachable block (ram,0xf00e26f4) */

undefined8 _audio_makeIMuLawTab(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
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
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  sword asStack_808 [512];
  int aiStack_408 [258];
  
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
  if (dword_F012EF60 == 0) {
    iVar1 = 0x4000;
    _IOMalloc();
    iVar5 = 0;
    iVar4 = 0;
    puVar2 = (undefined2 *)((int)register0x00000038 + -0x808);
    puVar3 = (undefined *)((int)register0x00000038 + -8);
    do {
      *(undefined2 **)(puVar3 + -0x400) = puVar2;
      *puVar2 = (sword)iVar5;
      puVar3 = puVar3 + 4;
      iVar5 = iVar5 + 1;
      puVar2[1] = *(sword *)(_audio_muLaw + iVar4) >> 2;
      iVar4 = iVar4 + 2;
      puVar2 = puVar2 + 2;
    } while (iVar5 < 0x100);
    dword_F012EF60 = iVar1;
    _qsort((undefined *)((int)register0x00000038 + -0x408),0x100,4,sub_F00E2890);
    iVar1 = 0;
    iVar4 = -0x2000;
    puVar3 = (undefined *)((int)register0x00000038 + -8);
    do {
      puVar2 = *(undefined2 **)(puVar3 + -0x400);
      if ((int)puVar3 <= (int)((int)register0x00000038 + 0x3f0)) {
        if ((0 < iVar4 - (sword)puVar2[1]) &&
           (*(sword *)(*(int *)(puVar3 + -0x3fc) + 2) - iVar4 < iVar4 - (sword)puVar2[1])) {
          puVar3 = puVar3 + 4;
        }
        puVar2 = *(undefined2 **)(puVar3 + -0x400);
      }
      *(char *)(dword_F012EF60 + iVar1) = (char)*puVar2;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar1 < 0x4000);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3058 start=0xf00e27d8 */

/* WARNING: Removing unreachable block (ram,0xf00e27f0) */

undefined8 _audio_freeIMuLawTab(undefined4 param_1,undefined4 param_2)

{
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
  undefined4 unaff_i3;
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
  if (dword_F012EF60 != 0) {
    _IOFree(dword_F012EF60,0x4000);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3059 start=0xf00e2800 */

undefined8 _audio_shortToMulaw(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  uint uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar1 = (param_1 << 0x10) >> 0x12;
  if (iVar1 < 0x2000) {
    if (iVar1 < -0x2000) {
      uVar2 = (uint)*dword_F012EF60;
    }
    else {
      uVar2 = (uint)dword_F012EF60[iVar1 + 0x2000];
    }
  }
  else {
    uVar2 = (uint)dword_F012EF60[0x3fff];
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3060 start=0xf00e2868 */

undefined8 _audio_byteToMulaw(char param_1,undefined4 param_2)

{
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
  undefined4 unaff_i3;
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
  return CONCAT44(param_2,(uint)*(byte *)(param_1 + dword_F012EF60 + 0x2000));
}
/* GHIDRADEC_FUNCTION index=3061 start=0xf00e28c4 */

/* WARNING: Removing unreachable block (ram,0xf00e2a08) */
/* WARNING: Removing unreachable block (ram,0xf00e2ac0) */
/* WARNING: Removing unreachable block (ram,0xf00e29f8) */

undefined8 _strtol(char *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  bVar2 = false;
  cVar1 = *param_1;
  pcVar6 = param_1;
  while( true ) {
    iVar5 = (int)cVar1;
    pcVar7 = pcVar6 + 1;
    if (((iVar5 == 0x20) || ((iVar5 - 9U & 0xff) < 2)) || (bVar11 = false, iVar5 == 10)) {
      bVar11 = true;
    }
    if (!bVar11) break;
    cVar1 = *pcVar7;
    pcVar6 = pcVar7;
  }
  if (iVar5 == 0x2d) {
    cVar1 = *pcVar7;
    bVar2 = true;
loc_F00E293C:
    iVar5 = (int)cVar1;
    pcVar7 = pcVar6 + 2;
  }
  else if (iVar5 == 0x2b) {
    cVar1 = *pcVar7;
    goto loc_F00E293C;
  }
  if (((param_3 == 0) || (param_3 == 0x10)) &&
     ((iVar5 == 0x30 && ((*pcVar7 == 'x' || (*pcVar7 == 'X')))))) {
    cVar1 = pcVar7[1];
    param_3 = 0x10;
  }
  else {
    if (((param_3 != 0) && (bVar11 = param_3 == 0, param_3 != 2)) ||
       ((bVar11 = param_3 == 0, iVar5 != 0x30 ||
        ((*pcVar7 != 'b' && (bVar11 = param_3 == 0, *pcVar7 != 'B')))))) goto loc_F00E29C8;
    cVar1 = pcVar7[1];
    param_3 = 2;
  }
  iVar5 = (int)cVar1;
  pcVar7 = pcVar7 + 2;
  bVar11 = param_3 == 0;
loc_F00E29C8:
  if ((bVar11) && (param_3 = 10, iVar5 == 0x30)) {
    param_3 = 8;
  }
  uVar9 = 0x80000000;
  if (!bVar2) {
    uVar9 = 0x7fffffff;
  }
  uVar3 = uVar9;
  .urem(uVar9,param_3);
  .udiv(uVar9,param_3);
  uVar10 = 0;
  iVar8 = 0;
  do {
    uVar4 = iVar5 - 0x30;
    if (9 < (uVar4 & 0xff)) {
      if (((iVar5 - 0x41U & 0xff) < 0x1a) || (bVar11 = false, (iVar5 - 0x61U & 0xff) < 0x1a)) {
        bVar11 = true;
      }
      if (!bVar11) {
loc_F00E2ADC:
        if (iVar8 < 0) {
          uVar10 = 0x80000000;
          if (!bVar2) {
            uVar10 = 0x7fffffff;
          }
        }
        else if (bVar2) {
          uVar10 = -uVar10;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar8 != 0) {
            param_1 = pcVar7 + -1;
          }
          *param_2 = param_1;
        }
        return CONCAT44(param_2,uVar10);
      }
      uVar4 = iVar5 - 0x37;
      if (0x19 < (iVar5 - 0x41U & 0xff)) {
        uVar4 = iVar5 - 0x57;
      }
    }
    if (param_3 <= (int)uVar4) goto loc_F00E2ADC;
    if (iVar8 < 0) {
loc_F00E2AB4:
      iVar8 = -1;
    }
    else if (uVar9 < uVar10) {
      iVar8 = -1;
    }
    else {
      iVar8 = 1;
      if ((uVar10 == uVar9) && ((int)uVar3 < (int)uVar4)) goto loc_F00E2AB4;
      .umul(uVar10,param_3);
      uVar10 = uVar10 + uVar4;
    }
    iVar5 = (int)*pcVar7;
    pcVar7 = pcVar7 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3062 start=0xf00e2b28 */

/* WARNING: Removing unreachable block (ram,0xf00e2c58) */
/* WARNING: Removing unreachable block (ram,0xf00e2d10) */
/* WARNING: Removing unreachable block (ram,0xf00e2c48) */

undefined8 _strtoul(char *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  bVar2 = false;
  cVar1 = *param_1;
  pcVar7 = param_1;
  while( true ) {
    iVar6 = (int)cVar1;
    pcVar8 = pcVar7 + 1;
    if (((iVar6 == 0x20) || ((iVar6 - 9U & 0xff) < 2)) || (bVar11 = false, iVar6 == 10)) {
      bVar11 = true;
    }
    if (!bVar11) break;
    cVar1 = *pcVar8;
    pcVar7 = pcVar8;
  }
  if (iVar6 == 0x2d) {
    cVar1 = *pcVar8;
    bVar2 = true;
loc_F00E2BA0:
    iVar6 = (int)cVar1;
    pcVar8 = pcVar7 + 2;
  }
  else if (iVar6 == 0x2b) {
    cVar1 = *pcVar8;
    goto loc_F00E2BA0;
  }
  if (((param_3 == 0) || (param_3 == 0x10)) &&
     ((iVar6 == 0x30 && ((*pcVar8 == 'x' || (*pcVar8 == 'X')))))) {
    cVar1 = pcVar8[1];
    param_3 = 0x10;
  }
  else {
    if (((param_3 != 0) && (bVar11 = param_3 == 0, param_3 != 2)) ||
       ((bVar11 = param_3 == 0, iVar6 != 0x30 ||
        ((*pcVar8 != 'b' && (bVar11 = param_3 == 0, *pcVar8 != 'B')))))) goto loc_F00E2C2C;
    cVar1 = pcVar8[1];
    param_3 = 2;
  }
  iVar6 = (int)cVar1;
  pcVar8 = pcVar8 + 2;
  bVar11 = param_3 == 0;
loc_F00E2C2C:
  if ((bVar11) && (param_3 = 10, iVar6 == 0x30)) {
    param_3 = 8;
  }
  uVar3 = 0xffffffff;
  .udiv(0xffffffff,param_3);
  iVar4 = -1;
  .urem(0xffffffff,param_3);
  uVar10 = 0;
  iVar9 = 0;
  do {
    uVar5 = iVar6 - 0x30;
    if (9 < (uVar5 & 0xff)) {
      if (((iVar6 - 0x41U & 0xff) < 0x1a) || (bVar11 = false, (iVar6 - 0x61U & 0xff) < 0x1a)) {
        bVar11 = true;
      }
      if (!bVar11) {
loc_F00E2D2C:
        if (iVar9 < 0) {
          uVar10 = 0xffffffff;
        }
        else if (bVar2) {
          uVar10 = -uVar10;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar9 != 0) {
            param_1 = pcVar8 + -1;
          }
          *param_2 = param_1;
        }
        return CONCAT44(param_2,uVar10);
      }
      uVar5 = iVar6 - 0x37;
      if (0x19 < (iVar6 - 0x41U & 0xff)) {
        uVar5 = iVar6 - 0x57;
      }
    }
    if (param_3 <= (int)uVar5) goto loc_F00E2D2C;
    if (iVar9 < 0) {
loc_F00E2D04:
      iVar9 = -1;
    }
    else if (uVar3 < uVar10) {
      iVar9 = -1;
    }
    else {
      iVar9 = 1;
      if ((uVar10 == uVar3) && (iVar4 < (int)uVar5)) goto loc_F00E2D04;
      .umul(uVar10,param_3);
      uVar10 = uVar10 + uVar5;
    }
    iVar6 = (int)*pcVar8;
    pcVar8 = pcVar8 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3063 start=0xf00e2d6c */

undefined8 _Event_server(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x2200018;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  if ((*(int *)(param_1 + 0x14) - 31000U < 9) &&
     (pcVar1 = *(code **)(*(int *)(param_1 + 0x14) * 4 + -0xff24a30), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3064 start=0xf00e3484 */

undefined8 _audio_server(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x2200018;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  if ((*(int *)(param_1 + 0x14) - 700U < 0x25) &&
     (*(code **)(unk_F00F90A8 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_F00F90A8 + *(int *)(param_1 + 0x14) * 4))(param_1,param_2);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3065 start=0xf00e4cf0 */

/* WARNING: Removing unreachable block (ram,0xf00e4d6c) */

undefined8
__NXAudioReplyStreamStatus
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
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
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_5;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_6;
  *(undefined *)((int)register0x00000038 + -0x45) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0x40;
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0x6a4;
  *(undefined4 *)((int)register0x00000038 + -0x38) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  puVar1 = (undefined *)((int)register0x00000038 + -0x48);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _msg_send(puVar1,0x21,1000);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3066 start=0xf00e4d7c */

/* WARNING: Removing unreachable block (ram,0xf00e4e14) */

undefined8
__NXAudioReplyRecordedData
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
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
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_5;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_6;
  *(undefined *)((int)register0x00000038 + -0x4d) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x4c) = 0x48;
  *(undefined4 *)((int)register0x00000038 + -0x48) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x40) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x38) = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0x6a5;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  puVar1 = (undefined *)((int)register0x00000038 + -0x50);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 6;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x90008;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)((int)register0x00000038 + 0x5c)
  ;
  _msg_send(puVar1,0x21,1000);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3067 start=0xf00e4e7c */

/* WARNING: Removing unreachable block (ram,0xf00e4f0c) */
/* WARNING: Removing unreachable block (ram,0xf00e4ee4) */
/* WARNING: Removing unreachable block (ram,0xf00e4ebc) */
/* WARNING: Removing unreachable block (ram,0xf00e4ed0) */
/* WARNING: Removing unreachable block (ram,0xf00e4ef8) */
/* WARNING: Removing unreachable block (ram,0xf00e4f20) */
/* WARNING: Removing unreachable block (ram,0xf00e4ea0) */

undefined8 _sparcfbConfigDisplay(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined6 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  if ((undefined4 *)_sparcfbs == (undefined4 *)0x0) {
    _sparcfbs = _fakeshmem;
    _bzero(_fakeshmem,0x448);
    *(undefined4 *)_sparcfbs = 0xabbaabba;
  }
  puVar1 = aCgfourteen;
  _find_node();
  if (puVar1 == (undefined *)0x0) {
loc_F00E4EE4:
    puVar3 = &aCgsix;
    _find_node();
    if (puVar3 != (undefined6 *)0x0) {
      iVar2 = 0;
      _cg6ConfigDisplay(0,puVar3);
      if (iVar2 == 0) goto loc_F00E4F34;
    }
    puVar1 = aSunwTcx;
    _find_node();
    uVar4 = 0xfffffd40;
    if (puVar1 == (undefined *)0x0) goto locret_F00E4F38;
    iVar2 = 0;
    _s24ConfigDisplay(0,puVar1);
    uVar4 = 0xfffffd40;
    if (iVar2 != 0) goto locret_F00E4F38;
  }
  else {
    iVar2 = 0;
    _cg14ConfigDisplay(0,puVar1);
    if (iVar2 != 0) goto loc_F00E4EE4;
  }
loc_F00E4F34:
  uVar4 = 0;
locret_F00E4F38:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3068 start=0xf00e4f40 */

/* WARNING: Removing unreachable block (ram,0xf00e4f5c) */
/* WARNING: Removing unreachable block (ram,0xf00e4f50) */
/* WARNING: Removing unreachable block (ram,0xf00e4f70) */
/* WARNING: Removing unreachable block (ram,0xf00e4f48) */

undefined8 _find_node(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar1 = (undefined *)((int)register0x00000038 + -0x160);
  _prom_stack_init(puVar1,0x154);
  puVar2 = puVar1;
  _prom_rootnode();
  _prom_findnode_byname();
  if (puVar2 == (undefined *)0x0) {
    puVar2 = (undefined *)0x0;
  }
  else {
    _prom_stack_fini(puVar1);
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3069 start=0xf00e4f80 */

/* WARNING: Removing unreachable block (ram,0xf00e4fb8) */
/* WARNING: Removing unreachable block (ram,0xf00e4f88) */

undefined8 _getproperty(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
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
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar1 = param_1;
  _prom_getproplen(param_1,param_2);
  if (iVar1 == 0) {
    param_3 = 1;
  }
  else if ((0 < iVar1) && (iVar1 == 4)) {
    _prom_getprop(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    param_3 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=3070 start=0xf00e4fd4 */

/* WARNING: Removing unreachable block (ram,0xf00e512c) */
/* WARNING: Removing unreachable block (ram,0xf00e50c4) */
/* WARNING: Removing unreachable block (ram,0xf00e5070) */
/* WARNING: Removing unreachable block (ram,0xf00e503c) */
/* WARNING: Removing unreachable block (ram,0xf00e502c) */
/* WARNING: Removing unreachable block (ram,0xf00e5050) */
/* WARNING: Removing unreachable block (ram,0xf00e50a0) */
/* WARNING: Removing unreachable block (ram,0xf00e50f4) */
/* WARNING: Removing unreachable block (ram,0xf00e5150) */
/* WARNING: Removing unreachable block (ram,0xf00e5000) */

sqword _cg14ConfigDisplay(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar3 = (undefined4 *)(_sparcfbs + param_1 * 0x44 + 8);
  uVar1 = param_2;
  _prom_getproplen(param_2,&aAddress);
  if (0 < (int)uVar1) {
    _prom_getprop(param_2,&aAddress,(undefined *)((int)register0x00000038 + -0x10));
  }
  _prom_getprop(param_2,&aReg,(undefined *)((int)register0x00000038 + -0x28));
  *puVar3 = 2;
  puVar3[1] = 0;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aWidth);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar2 = 0x480;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aWidth,(undefined *)((int)register0x00000038 + -0x2c));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x2c);
  }
  else {
    uVar2 = 0x480;
  }
  puVar3[8] = uVar2;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aHeight);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar2 = 900;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aHeight,(undefined *)((int)register0x00000038 + -0x2c));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x2c);
  }
  else {
    uVar2 = 900;
  }
  puVar3[9] = uVar2;
  puVar3[5] = *(undefined4 *)((int)register0x00000038 + -0xc);
  puVar3[6] = *(undefined4 *)((int)register0x00000038 + -0xc);
  puVar3[3] = *(undefined4 *)((int)register0x00000038 + -0x10);
  uVar2 = puVar3[8];
  .umul(uVar2,puVar3[9]);
  puVar3[7] = uVar2;
  puVar3[0xc] = 8;
  puVar3[0xd] = 1;
  uVar2 = puVar3[8];
  .umul(uVar2,puVar3[0xd]);
  puVar3[0xe] = uVar2;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3071 start=0xf00e5164 */

/* WARNING: Removing unreachable block (ram,0xf00e538c) */
/* WARNING: Removing unreachable block (ram,0xf00e532c) */
/* WARNING: Removing unreachable block (ram,0xf00e52d8) */
/* WARNING: Removing unreachable block (ram,0xf00e5288) */
/* WARNING: Removing unreachable block (ram,0xf00e5228) */
/* WARNING: Removing unreachable block (ram,0xf00e51d0) */
/* WARNING: Removing unreachable block (ram,0xf00e51f8) */
/* WARNING: Removing unreachable block (ram,0xf00e519c) */
/* WARNING: Removing unreachable block (ram,0xf00e51b4) */
/* WARNING: Removing unreachable block (ram,0xf00e520c) */
/* WARNING: Removing unreachable block (ram,0xf00e5264) */
/* WARNING: Removing unreachable block (ram,0xf00e52b8) */
/* WARNING: Removing unreachable block (ram,0xf00e5308) */
/* WARNING: Removing unreachable block (ram,0xf00e535c) */
/* WARNING: Removing unreachable block (ram,0xf00e53b0) */
/* WARNING: Removing unreachable block (ram,0xf00e5194) */

sqword _s24ConfigDisplay(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar10 = 0;
  puVar9 = (undefined4 *)(_sparcfbs + param_1 * 0x44 + 8);
  _prom_getprop(param_2,&aReg,(undefined *)((int)register0x00000038 + -0x1e8));
  uVar1 = param_2;
  _prom_parentnode();
  if (uVar1 == 0) {
    _panic(aCanTGetParentN);
  }
  else {
    uVar2 = uVar1;
    _prom_getproplen();
    if (uVar2 != 0) {
      _prom_getprop(uVar1,&aRanges,(undefined *)((int)register0x00000038 + -0x378));
      iVar10 = *(int *)((undefined *)((int)register0x00000038 + -0x378) +
                       *(int *)((int)register0x00000038 + -0x1e8) * 0x14 + 0xc);
    }
  }
  iVar3 = 0x100000;
  iVar11 = 0;
  _map_alloc(0x100000,_page_size);
  iVar4 = 0x100000;
  iVar7 = *(int *)((int)register0x00000038 + -0x1e4) + iVar10;
  .udiv(0x100000,_page_size);
  iVar8 = iVar3;
  if (0 < iVar4) {
    do {
      iVar11 = iVar11 + 1;
      _pmap_enter_dev(_kernel_pmap,iVar8,iVar7,0,3,0,1);
      iVar7 = iVar7 + _page_size;
      iVar8 = iVar8 + _page_size;
    } while (iVar11 < iVar4);
  }
  uVar5 = 0x2000;
  _map_alloc(0x2000,_page_size);
  _pmap_enter_dev(_kernel_pmap,uVar5,*(int *)((int)register0x00000038 + -0x184) + iVar10,0,3,0,1);
  *puVar9 = 3;
  puVar9[1] = 0;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aWidth);
  if (uVar1 == 0) {
    uVar6 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar6 = 0x480;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aWidth,(undefined *)((int)register0x00000038 + -0x37c));
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0x37c);
  }
  else {
    uVar6 = 0x480;
  }
  puVar9[8] = uVar6;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aHeight);
  if (uVar1 == 0) {
    uVar6 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar6 = 900;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aHeight,(undefined *)((int)register0x00000038 + -0x37c));
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0x37c);
  }
  else {
    uVar6 = 900;
  }
  puVar9[9] = uVar6;
  puVar9[5] = iVar3;
  puVar9[6] = 0;
  puVar9[2] = 0;
  puVar9[3] = uVar5;
  uVar5 = puVar9[8];
  .umul(uVar5,puVar9[9]);
  puVar9[7] = uVar5;
  puVar9[0xc] = 8;
  puVar9[0xd] = 1;
  uVar5 = puVar9[8];
  .umul(uVar5,puVar9[0xd]);
  puVar9[0xe] = uVar5;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3072 start=0xf00e53c4 */

/* WARNING: Removing unreachable block (ram,0xf00e5518) */
/* WARNING: Removing unreachable block (ram,0xf00e54b4) */
/* WARNING: Removing unreachable block (ram,0xf00e5460) */
/* WARNING: Removing unreachable block (ram,0xf00e542c) */
/* WARNING: Removing unreachable block (ram,0xf00e541c) */
/* WARNING: Removing unreachable block (ram,0xf00e5440) */
/* WARNING: Removing unreachable block (ram,0xf00e5490) */
/* WARNING: Removing unreachable block (ram,0xf00e54e4) */
/* WARNING: Removing unreachable block (ram,0xf00e553c) */
/* WARNING: Removing unreachable block (ram,0xf00e53f0) */

sqword _cg6ConfigDisplay(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar3 = (undefined4 *)(_sparcfbs + param_1 * 0x44 + 8);
  uVar1 = param_2;
  _prom_getproplen(param_2,&aAddress);
  if (0 < (int)uVar1) {
    _prom_getprop(param_2,&aAddress,(undefined *)((int)register0x00000038 + -0x1c));
  }
  _prom_getprop(param_2,&aReg,(undefined *)((int)register0x00000038 + -0x18));
  *puVar3 = 1;
  puVar3[1] = 0;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aWidth);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar2 = 0x480;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aWidth,(undefined *)((int)register0x00000038 + -0x24));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x24);
  }
  else {
    uVar2 = 0x480;
  }
  puVar3[8] = uVar2;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aHeight);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar2 = 900;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aHeight,(undefined *)((int)register0x00000038 + -0x24));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x24);
  }
  else {
    uVar2 = 900;
  }
  puVar3[9] = uVar2;
  puVar3[5] = *(undefined4 *)((int)register0x00000038 + -0x1c);
  puVar3[6] = *(undefined4 *)((int)register0x00000038 + -0x1c);
  puVar3[3] = 0;
  uVar2 = puVar3[8];
  .umul(uVar2,puVar3[9]);
  puVar3[7] = uVar2;
  puVar3[0xc] = 8;
  puVar3[0xd] = 1;
  uVar2 = puVar3[8];
  .umul(uVar2,puVar3[0xd]);
  puVar3[0xe] = uVar2;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3073 start=0xf00e5550 */

undefined8 _sparcfbLoadCmap(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  int iVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar3 = param_1 * 0x44 + 8;
  iVar5 = _sparcfbs + iVar3;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar3) != 0)) {
    uVar1 = *(uint *)(_sparcfbs + iVar3);
    if (uVar1 == 2) {
      iVar3 = *(int *)(iVar5 + 0xc);
      *(undefined4 *)(iVar3 + 0x4000) = 0;
      *(undefined4 *)(iVar3 + 0x4264) = 0x999999;
      *(undefined4 *)(iVar3 + 0x4198) = 0x666666;
      *(undefined4 *)(iVar3 + 0x43fc) = 0xffffff;
      uVar4 = 0;
    }
    else {
      if (uVar1 < 3) {
        uVar4 = 0xffffffff;
        if (uVar1 != 1) goto locret_F00E565C;
      }
      else {
        uVar4 = 0xffffffff;
        if (uVar1 != 3) goto locret_F00E565C;
      }
      puVar2 = *(undefined4 **)(iVar5 + 0xc);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[1] = 0;
      puVar2[1] = 0;
      *puVar2 = 0xff000000;
      puVar2[1] = 0xff000000;
      puVar2[1] = 0xff000000;
      puVar2[1] = 0xff000000;
      *puVar2 = 0x99000000;
      puVar2[1] = 0x99000000;
      puVar2[1] = 0x99000000;
      puVar2[1] = 0x99000000;
      *puVar2 = 0x66000000;
      puVar2[1] = 0x66000000;
      puVar2[1] = 0x66000000;
      puVar2[1] = 0x66000000;
      *puVar2 = 0;
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xfffffd40;
  }
locret_F00E565C:
  return CONCAT44(iVar5,uVar4);
}
/* GHIDRADEC_FUNCTION index=3074 start=0xf00e5664 */

undefined8 _sparcfbClearDisplay(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar1 = param_1 * 0x44 + 8;
  iVar4 = _sparcfbs + iVar1;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar1) != 0)) {
    puVar3 = (uint *)(*(int *)(iVar4 + 0x14) + *(int *)(iVar4 + 0x1c));
    puVar6 = *(uint **)(iVar4 + 0x14);
    uVar2 = param_2 << 0x18 | param_2;
    if (puVar6 < puVar3) {
      *puVar6 = uVar2;
      while (puVar6 = puVar6 + 1, puVar6 < puVar3) {
        *puVar6 = uVar2;
      }
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 0xfffffd40;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=3075 start=0xf00e56e4 */

/* WARNING: Removing unreachable block (ram,0xf00e57d8) */
/* WARNING: Removing unreachable block (ram,0xf00e577c) */
/* WARNING: Removing unreachable block (ram,0xf00e57f0) */
/* WARNING: Removing unreachable block (ram,0xf00e5764) */

undefined8 _sparcfbFillRect(uint param_1,word *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  uint *puVar5;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  uint uVar9;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  word *pwVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar1 = param_1 * 0x44 + 8;
  iVar7 = _sparcfbs + iVar1;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar1) != 0)) {
    uVar6 = (uint)param_2[1];
    uVar9 = (uint)*param_2;
    uVar8 = (uint)param_2[2];
    param_2 = (word *)(uint)param_2[3];
    if (*(int *)(iVar7 + 0x34) == 1) {
      pwVar10 = (word *)0x0;
      if (param_2 != (word *)0x0) {
        do {
          uVar3 = uVar6;
          .umul(uVar6,*(undefined4 *)(iVar7 + 0x38));
          iVar1 = *(int *)(iVar7 + 0x14);
          uVar2 = uVar9;
          .umul(uVar9,*(undefined4 *)(iVar7 + 0x34));
          puVar4 = (undefined *)(iVar1 + uVar3 + uVar2);
          uVar3 = 0;
          if (uVar8 != 0) {
            do {
              *puVar4 = (char)param_3;
              uVar3 = uVar3 + 1;
              puVar4 = puVar4 + 1;
            } while (uVar3 < uVar8);
          }
          pwVar10 = (word *)((int)pwVar10 + 1);
          uVar6 = uVar6 + 1;
        } while (pwVar10 < param_2);
        pwVar10 = (word *)0x0;
      }
    }
    else {
      pwVar10 = (word *)0x0;
      if (*(int *)(iVar7 + 0x34) == 4) {
        if (param_2 == (word *)0x0) {
          pwVar10 = (word *)0x0;
        }
        else {
          do {
            uVar3 = uVar6;
            .umul(uVar6,*(undefined4 *)(iVar7 + 0x38));
            iVar1 = *(int *)(iVar7 + 0x18);
            uVar2 = uVar9;
            .umul(uVar9,*(undefined4 *)(iVar7 + 0x34));
            puVar5 = (uint *)(iVar1 + uVar3 + uVar2);
            uVar3 = 0;
            if (uVar8 != 0) {
              do {
                *puVar5 = param_3 << 0x18 | param_3;
                uVar3 = uVar3 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar3 < uVar8);
            }
            pwVar10 = (word *)((int)pwVar10 + 1);
            uVar6 = uVar6 + 1;
          } while (pwVar10 < param_2);
          pwVar10 = (word *)0x0;
        }
      }
      else {
        pwVar10 = (word *)0xfffffd39;
      }
    }
  }
  else {
    pwVar10 = (word *)0xfffffd40;
  }
  return CONCAT44(param_2,pwVar10);
}
/* GHIDRADEC_FUNCTION index=3076 start=0xf00e5844 */

/* WARNING: Removing unreachable block (ram,0xf00e598c) */
/* WARNING: Removing unreachable block (ram,0xf00e5964) */
/* WARNING: Removing unreachable block (ram,0xf00e58ec) */
/* WARNING: Removing unreachable block (ram,0xf00e58dc) */
/* WARNING: Removing unreachable block (ram,0xf00e5904) */
/* WARNING: Removing unreachable block (ram,0xf00e597c) */
/* WARNING: Removing unreachable block (ram,0xf00e59a4) */
/* WARNING: Removing unreachable block (ram,0xf00e58c4) */

undefined8 _sparcfbMoveRect(uint param_1,word *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 unaff_l1;
  int iVar8;
  word *pwVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined *puVar14;
  undefined4 *puVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar1 = param_1 * 0x44 + 8;
  iVar8 = _sparcfbs + iVar1;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar1) != 0)) {
    uVar10 = (uint)param_2[1];
    uVar12 = (uint)*param_2;
    uVar11 = (uint)param_2[2];
    param_2 = (word *)(uint)param_2[3];
    if (*(int *)(iVar8 + 0x34) == 1) {
      pwVar9 = (word *)0x0;
      uVar13 = 0;
      if (param_2 != (word *)0x0) {
        do {
          uVar4 = uVar10;
          .umul(uVar10,*(undefined4 *)(iVar8 + 0x38));
          iVar1 = *(int *)(iVar8 + 0x14);
          uVar2 = uVar12;
          .umul(uVar12,*(undefined4 *)(iVar8 + 0x34));
          puVar14 = (undefined *)(iVar1 + uVar4 + uVar2);
          iVar1 = param_4;
          .umul(param_4,*(undefined4 *)(iVar8 + 0x38));
          iVar6 = *(int *)(iVar8 + 0x14);
          iVar3 = param_3;
          .umul(param_3,*(undefined4 *)(iVar8 + 0x34));
          uVar4 = 0;
          puVar5 = (undefined *)(iVar6 + iVar1 + iVar3);
          if (uVar11 != 0) {
            do {
              uVar4 = uVar4 + 1;
              *puVar5 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar5 = puVar5 + 1;
            } while (uVar4 < uVar11);
          }
          uVar10 = uVar10 + 1;
          pwVar9 = (word *)((int)pwVar9 + 1);
          param_4 = param_4 + 1;
        } while (pwVar9 < param_2);
        uVar13 = 0;
      }
    }
    else {
      pwVar9 = (word *)0x0;
      if (*(int *)(iVar8 + 0x34) == 4) {
        uVar13 = 0;
        if (param_2 != (word *)0x0) {
          do {
            uVar4 = uVar10;
            .umul(uVar10,*(undefined4 *)(iVar8 + 0x38));
            iVar1 = *(int *)(iVar8 + 0x18);
            uVar2 = uVar12;
            .umul(uVar12,*(undefined4 *)(iVar8 + 0x34));
            puVar15 = (undefined4 *)(iVar1 + uVar4 + uVar2);
            iVar1 = param_4;
            .umul(param_4,*(undefined4 *)(iVar8 + 0x38));
            iVar6 = *(int *)(iVar8 + 0x18);
            iVar3 = param_3;
            .umul(param_3,*(undefined4 *)(iVar8 + 0x34));
            uVar4 = 0;
            puVar7 = (undefined4 *)(iVar6 + iVar1 + iVar3);
            if (uVar11 != 0) {
              do {
                uVar4 = uVar4 + 1;
                *puVar7 = *puVar15;
                puVar15 = puVar15 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar4 < uVar11);
            }
            uVar10 = uVar10 + 1;
            pwVar9 = (word *)((int)pwVar9 + 1);
            param_4 = param_4 + 1;
          } while (pwVar9 < param_2);
          uVar13 = 0;
        }
      }
      else {
        uVar13 = 0xfffffd39;
      }
    }
  }
  else {
    uVar13 = 0xfffffd40;
  }
  return CONCAT44(param_2,uVar13);
}
/* GHIDRADEC_FUNCTION index=3077 start=0xf00e59f8 */

/* WARNING: Removing unreachable block (ram,0xf00e5af0) */
/* WARNING: Removing unreachable block (ram,0xf00e5b8c) */
/* WARNING: Removing unreachable block (ram,0xf00e5c58) */
/* WARNING: Removing unreachable block (ram,0xf00e5cf4) */
/* WARNING: Removing unreachable block (ram,0xf00e5cdc) */
/* WARNING: Removing unreachable block (ram,0xf00e5c40) */
/* WARNING: Removing unreachable block (ram,0xf00e5ad4) */
/* WARNING: Removing unreachable block (ram,0xf00e5ba4) */
/* WARNING: Removing unreachable block (ram,0xf00e5b08) */
/* WARNING: Removing unreachable block (ram,0xf00e5c24) */

qword _sparcfbDrawRect(uint param_1,word *param_2,undefined4 param_3,byte *param_4)

{
  int iVar1;
  word wVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 unaff_l1;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 unaff_i1;
  uint uVar11;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar4 = -0x2c7;
  uVar8 = (uint)param_2[3];
  uVar9 = (uint)*param_2;
  uVar5 = (uint)param_2[1];
  iVar3 = param_1 * 0x44 + 8;
  wVar2 = param_2[2];
  uVar11 = (uint)wVar2;
  iVar10 = _sparcfbs + iVar3;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar3) != 0)) {
    switch(param_3) {
    case :
      iVar3 = *(int *)(iVar10 + 0x38);
      .div(iVar3,*(undefined4 *)(iVar10 + 0x34));
      if (*(int *)(iVar10 + 0x30) == 0x18) {
        .umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x18);
        .umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar6 = (undefined4 *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -1;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 7;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 7;
              }
              *puVar6 = *(undefined4 *)((int)&unk_F00FA060 + (uVar8 & 1) * 4);
              puVar6 = puVar6 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar6 = puVar6 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      else {
        .umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x14);
        .umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar7 = (undefined *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -1;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 7;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 7;
              }
              *puVar7 = *(undefined *)((int)&unk_F00FA068 + (uVar8 & 1));
              puVar7 = puVar7 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar7 = puVar7 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      break;
    case :
      iVar3 = *(int *)(iVar10 + 0x38);
      .div(iVar3,*(undefined4 *)(iVar10 + 0x34));
      if (*(int *)(iVar10 + 0x30) == 0x18) {
        .umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x18);
        .umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar6 = (undefined4 *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -2;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 6;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 6;
              }
              *puVar6 = *(undefined4 *)(unk_F00FA06C + (uVar8 & 3) * 4);
              puVar6 = puVar6 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar6 = puVar6 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      else {
        .umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x14);
        .umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar7 = (undefined *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -2;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 6;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 6;
              }
              *puVar7 = unk_F00FA080[uVar8 & 3];
              puVar7 = puVar7 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar7 = puVar7 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      break;
    case :
    case :
    case :
      iVar4 = -0x2c7;
    }
  }
  else {
    iVar4 = -0x2c0;
  }
  return (qword)CONCAT24(wVar2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3078 start=0xf00e5d7c */

/* WARNING: Removing unreachable block (ram,0xf00e5fb0) */
/* WARNING: Removing unreachable block (ram,0xf00e5f40) */
/* WARNING: Removing unreachable block (ram,0xf00e5e80) */
/* WARNING: Removing unreachable block (ram,0xf00e5dd8) */
/* WARNING: Removing unreachable block (ram,0xf00e5f08) */
/* WARNING: Removing unreachable block (ram,0xf00e5f58) */
/* WARNING: Removing unreachable block (ram,0xf00e5fc8) */
/* WARNING: Removing unreachable block (ram,0xf00e5dd0) */

undefined8 _sparcfbSaveRect(uint param_1,word *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined *puVar8;
  undefined4 unaff_l1;
  uint uVar9;
  uint uVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  uint uVar13;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar9 = (uint)param_2[2];
  uVar10 = (uint)param_2[3];
  uVar13 = (uint)*param_2;
  iVar1 = param_1 * 0x44 + 8;
  uVar12 = (uint)param_2[1];
  iVar11 = _sparcfbs + iVar1;
  if ((0xf < param_1) || (*(int *)(_sparcfbs + iVar1) == 0)) {
    uVar14 = 0xfffffd40;
    goto locret_F00E601C;
  }
  uVar2 = uVar9;
  .umul(uVar9,*(undefined4 *)(iVar11 + 0x34));
  .umul();
  iVar7 = uVar2 + 4;
  *(int *)((int)register0x00000038 + -0xc) = dword_F012EF6C;
  iVar1 = 0;
  iVar6 = dword_F012EF6C;
  while (iVar6 != 0) {
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    iVar6 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar7 <= *(int *)(iVar4 + 0x18)) goto loc_F00E5E28;
    iVar6 = *(int *)(iVar4 + 8);
    *(int *)((int)register0x00000038 + -0xc) = iVar6;
    iVar1 = iVar4;
  }
  iVar6 = *(int *)((int)register0x00000038 + -0xc);
loc_F00E5E28:
  if (iVar6 == 0) {
    if (dword_F012EF78 < iVar7) {
      iVar1 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar2 + 0x20);
      if (iVar1 != 0) {
        uVar14 = 0xffffffff;
        goto locret_F00E601C;
      }
    }
    else {
      *(undefined **)((int)register0x00000038 + -0xc) = unk_F01330E4;
      dword_F012EF78 = 0;
    }
  }
  else {
    dword_F012EF74 = dword_F012EF74 + -1;
    if (iVar1 == 0) {
      dword_F012EF6C = *(int *)(iVar6 + 8);
    }
    else {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar6 + 8);
    }
  }
  piVar5 = *(int **)((int)register0x00000038 + -0xc);
  DAT_f012ef70 = DAT_f012ef70 + 1;
  *piVar5 = DAT_f012ef70;
  piVar5[6] = iVar7;
  piVar5[1] = param_1;
  piVar5[2] = (int)dword_F012EF68;
  piVar5[3] = *(int *)(iVar11 + 0x34);
  *(word *)(piVar5 + 4) = *param_2;
  *(word *)((int)piVar5 + 0x12) = param_2[1];
  *(word *)(piVar5 + 5) = param_2[2];
  *(word *)((int)piVar5 + 0x16) = param_2[3];
  iVar1 = *(int *)(iVar11 + 0x38);
  dword_F012EF68 = piVar5;
  .div(iVar1,*(undefined4 *)(iVar11 + 0x34));
  if (*(int *)(iVar11 + 0x34) == 1) {
    puVar15 = (undefined *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
    .umul(uVar12,*(undefined4 *)(iVar11 + 0x38));
    iVar6 = *(int *)(iVar11 + 0x14);
    .umul(uVar13,*(undefined4 *)(iVar11 + 0x34));
    puVar8 = (undefined *)(iVar6 + uVar12 + uVar13);
    iVar11 = uVar10 - 1;
    if ((int)(uVar10 - 1) < 0) goto loc_F00E6014;
    do {
      uVar10 = (uint)param_2[2];
      while (uVar10 = uVar10 - 1, -1 < (int)uVar10) {
        *puVar15 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar15 = puVar15 + 1;
      }
      iVar6 = iVar11 + -1;
      puVar8 = puVar8 + (iVar1 - uVar9);
      iVar11 = iVar11 + -1;
    } while (-1 < iVar6);
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  else if (*(int *)(iVar11 + 0x34) == 4) {
    puVar16 = (undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
    .umul(uVar12,*(undefined4 *)(iVar11 + 0x38));
    iVar6 = *(int *)(iVar11 + 0x18);
    .umul(uVar13,*(undefined4 *)(iVar11 + 0x34));
    puVar3 = (undefined4 *)(iVar6 + uVar12 + uVar13);
    while (uVar10 = uVar10 - 1, -1 < (int)uVar10) {
      uVar12 = (uint)param_2[2];
      while (uVar12 = uVar12 - 1, -1 < (int)uVar12) {
        *puVar16 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar16 = puVar16 + 1;
      }
      puVar3 = puVar3 + (iVar1 - uVar9);
    }
loc_F00E6014:
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  else {
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  uVar14 = *puVar3;
locret_F00E601C:
  return CONCAT44(param_2,uVar14);
}
/* GHIDRADEC_FUNCTION index=3079 start=0xf00e6024 */

/* WARNING: Removing unreachable block (ram,0xf00e6184) */
/* WARNING: Removing unreachable block (ram,0xf00e6118) */
/* WARNING: Removing unreachable block (ram,0xf00e6100) */
/* WARNING: Removing unreachable block (ram,0xf00e616c) */
/* WARNING: Removing unreachable block (ram,0xf00e622c) */
/* WARNING: Removing unreachable block (ram,0xf00e60cc) */

undefined8 _sparcfbRestoreRect(uint param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  uint uVar8;
  undefined4 unaff_l3;
  int *piVar9;
  undefined4 unaff_l4;
  int iVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  int *piVar12;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  iVar2 = param_1 * 0x44 + 8;
  iVar10 = _sparcfbs + iVar2;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar2) != 0)) {
    bVar14 = dword_F012EF68 == (int *)0x0;
    piVar9 = dword_F012EF68;
    piVar12 = (int *)0x0;
    if (!bVar14) {
      iVar2 = *dword_F012EF68;
      while (piVar7 = piVar9, bVar14 = piVar7 == (int *)0x0, piVar9 = piVar7, iVar2 == 0) {
        piVar9 = (int *)piVar7[2];
        piVar12 = piVar7;
        if (piVar9 == (int *)0x0) {
          bVar14 = true;
          break;
        }
        iVar2 = *piVar9;
      }
    }
    uVar13 = 0xfffffd3e;
    if ((!bVar14) && (piVar9[3] == *(int *)(iVar10 + 0x34))) {
      wVar1 = *(word *)(piVar9 + 5);
      uVar8 = (uint)*(word *)((int)piVar9 + 0x16);
      iVar2 = *(int *)(iVar10 + 0x38);
      uVar3 = (uint)*(word *)((int)piVar9 + 0x12);
      uVar11 = (uint)*(word *)(piVar9 + 4);
      .div(iVar2,*(undefined4 *)(iVar10 + 0x34));
      if (*(int *)(iVar10 + 0x34) == 1) {
        piVar7 = piVar9 + 7;
        .umul(uVar3,*(undefined4 *)(iVar10 + 0x38));
        iVar5 = *(int *)(iVar10 + 0x14);
        .umul(uVar11,*(undefined4 *)(iVar10 + 0x34));
        puVar4 = (undefined *)(iVar5 + uVar3 + uVar11);
        while (uVar8 = uVar8 - 1, -1 < (int)uVar8) {
          uVar3 = (uint)*(word *)(piVar9 + 5);
          while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
            *puVar4 = *(undefined *)piVar7;
            piVar7 = (int *)((int)piVar7 + 1);
            puVar4 = puVar4 + 1;
          }
          puVar4 = puVar4 + (iVar2 - (uint)wVar1);
        }
      }
      else {
        piVar7 = piVar9 + 7;
        if (*(int *)(iVar10 + 0x34) == 4) {
          .umul(uVar3,*(undefined4 *)(iVar10 + 0x38));
          iVar5 = *(int *)(iVar10 + 0x18);
          .umul(uVar11,*(undefined4 *)(iVar10 + 0x34));
          piVar6 = (int *)(iVar5 + uVar3 + uVar11);
          while (uVar8 = uVar8 - 1, -1 < (int)uVar8) {
            uVar3 = (uint)*(word *)(piVar9 + 5);
            while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
              *piVar6 = *piVar7;
              piVar7 = piVar7 + 1;
              piVar6 = piVar6 + 1;
            }
            piVar6 = piVar6 + (iVar2 - (uint)wVar1);
          }
        }
      }
      if (piVar12 == (int *)0x0) {
        dword_F012EF68 = (int *)piVar9[2];
      }
      else {
        piVar12[2] = piVar9[2];
      }
      if (dword_F012EF74 < 10) {
        dword_F012EF74 = dword_F012EF74 + 1;
        piVar9[2] = (int)dword_F012EF6C;
        dword_F012EF6C = piVar9;
      }
      else {
        if (piVar9 != (int *)unk_F01330E4) {
          _kmem_free(_kernel_map,piVar9);
          uVar13 = 0;
          goto locret_F00E6254;
        }
        dword_F012EF78 = 0xc04;
      }
      uVar13 = 0;
    }
  }
  else {
    uVar13 = 0xfffffd40;
  }
locret_F00E6254:
  return CONCAT44(param_2,uVar13);
}
/* GHIDRADEC_FUNCTION index=3080 start=0xf00e625c */

/* WARNING: Removing unreachable block (ram,0xf00e66fc) */
/* WARNING: Removing unreachable block (ram,0xf00e6690) */
/* WARNING: Removing unreachable block (ram,0xf00e6644) */
/* WARNING: Removing unreachable block (ram,0xf00e64c8) */
/* WARNING: Removing unreachable block (ram,0xf00e6458) */
/* WARNING: Removing unreachable block (ram,0xf00e6398) */
/* WARNING: Removing unreachable block (ram,0xf00e62f0) */
/* WARNING: Removing unreachable block (ram,0xf00e6420) */
/* WARNING: Removing unreachable block (ram,0xf00e6470) */
/* WARNING: Removing unreachable block (ram,0xf00e64e0) */
/* WARNING: Removing unreachable block (ram,0xf00e6678) */
/* WARNING: Removing unreachable block (ram,0xf00e66e4) */
/* WARNING: Removing unreachable block (ram,0xf00e67a4) */
/* WARNING: Removing unreachable block (ram,0xf00e62e8) */

undefined8 _sparcfbInvertRect(uint param_1,word *param_2)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  word *pwVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  undefined4 unaff_l0;
  undefined *puVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 unaff_l1;
  word *pwVar17;
  undefined *puVar18;
  undefined4 *puVar19;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar20;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar2 = (uint)*param_2;
  uVar6 = (uint)param_2[1];
  uVar10 = (uint)param_2[2];
  uVar3 = (uint)param_2[3];
  iVar7 = param_1 * 0x44 + 8;
  iVar13 = _sparcfbs + iVar7;
  if ((0xf < param_1) || (*(int *)(_sparcfbs + iVar7) == 0)) {
    iVar7 = -0x2c0;
    goto locret_F00E67CC;
  }
  if (*(int *)(_sparcfbs + iVar7) == 0) {
    iVar7 = -0x2c0;
  }
  else {
    uVar4 = uVar10;
    .umul(uVar10,*(undefined4 *)(iVar13 + 0x34));
    .umul();
    iVar15 = uVar4 + 4;
    *(word **)((int)register0x00000038 + -0xc) = dword_F012EF6C;
    iVar7 = 0;
    pwVar9 = dword_F012EF6C;
    while (pwVar9 != (word *)0x0) {
      iVar8 = *(int *)((int)register0x00000038 + -0xc);
      iVar11 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar15 <= *(int *)(iVar8 + 0x18)) goto loc_F00E6340;
      pwVar9 = *(word **)(iVar8 + 8);
      *(word **)((int)register0x00000038 + -0xc) = pwVar9;
      iVar7 = iVar8;
    }
    iVar11 = *(int *)((int)register0x00000038 + -0xc);
loc_F00E6340:
    if (iVar11 == 0) {
      if (dword_F012EF78 < iVar15) {
        iVar7 = _kernel_map;
        _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4 + 0x20);
        if (iVar7 != 0) {
          iVar7 = -1;
          goto loc_F00E6534;
        }
      }
      else {
        *(undefined **)((int)register0x00000038 + -0xc) = unk_F01330E4;
        dword_F012EF78 = 0;
      }
    }
    else {
      dword_F012EF74 = dword_F012EF74 + -1;
      if (iVar7 == 0) {
        dword_F012EF6C = *(word **)(iVar11 + 8);
      }
      else {
        *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar11 + 8);
      }
    }
    pwVar9 = *(word **)((int)register0x00000038 + -0xc);
    DAT_f012ef70 = DAT_f012ef70 + 1;
    *(int *)pwVar9 = DAT_f012ef70;
    *(int *)(pwVar9 + 0xc) = iVar15;
    *(uint *)(pwVar9 + 2) = param_1;
    *(word **)(pwVar9 + 4) = dword_F012EF68;
    *(undefined4 *)(pwVar9 + 6) = *(undefined4 *)(iVar13 + 0x34);
    pwVar9[8] = *param_2;
    pwVar9[9] = param_2[1];
    pwVar9[10] = param_2[2];
    pwVar9[0xb] = param_2[3];
    iVar7 = *(int *)(iVar13 + 0x38);
    dword_F012EF68 = pwVar9;
    .div(iVar7,*(undefined4 *)(iVar13 + 0x34));
    if (*(int *)(iVar13 + 0x34) == 1) {
      puVar18 = (undefined *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
      .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
      iVar15 = *(int *)(iVar13 + 0x14);
      .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
      puVar14 = (undefined *)(iVar15 + uVar6 + uVar2);
      iVar13 = uVar3 - 1;
      if ((int)(uVar3 - 1) < 0) goto loc_F00E652C;
      do {
        uVar3 = (uint)param_2[2];
        while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
          *puVar18 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar18 = puVar18 + 1;
        }
        iVar15 = iVar13 + -1;
        puVar14 = puVar14 + (iVar7 - uVar10);
        iVar13 = iVar13 + -1;
      } while (-1 < iVar15);
      piVar5 = *(int **)((int)register0x00000038 + -0xc);
    }
    else if (*(int *)(iVar13 + 0x34) == 4) {
      puVar19 = (undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
      .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
      iVar15 = *(int *)(iVar13 + 0x18);
      .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
      puVar16 = (undefined4 *)(iVar15 + uVar6 + uVar2);
      while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
        uVar6 = (uint)param_2[2];
        while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
          *puVar19 = *puVar16;
          puVar16 = puVar16 + 1;
          puVar19 = puVar19 + 1;
        }
        puVar16 = puVar16 + (iVar7 - uVar10);
      }
loc_F00E652C:
      piVar5 = *(int **)((int)register0x00000038 + -0xc);
    }
    else {
      piVar5 = *(int **)((int)register0x00000038 + -0xc);
    }
    iVar7 = *piVar5;
  }
loc_F00E6534:
  if (-1 < iVar7) {
    uVar3 = uRam00000018;
    pwVar9 = dword_F012EF68;
    if (dword_F012EF68 != (word *)0x0) {
      iVar7 = *(int *)dword_F012EF68;
      while (iVar7 == 0) {
        pwVar9 = *(word **)(pwVar9 + 4);
        if (pwVar9 == (word *)0x0) goto loc_F00E6574;
        iVar7 = *(int *)pwVar9;
      }
      uVar3 = *(uint *)(pwVar9 + 0xc);
    }
loc_F00E6574:
    puVar12 = (uint *)(pwVar9 + 0xe);
    iVar7 = (uVar3 >> 2) - 1;
    iVar13 = param_1 - 0xf;
    while (-1 < iVar13) {
      *puVar12 = ~*puVar12;
      puVar12 = puVar12 + 1;
      iVar7 = iVar7 + -1;
      iVar13 = iVar7;
    }
    iVar7 = param_1 * 0x44 + 8;
    iVar13 = _sparcfbs + iVar7;
    if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar7) != 0)) {
      bVar20 = dword_F012EF68 == (word *)0x0;
      pwVar9 = (word *)0x0;
      param_2 = dword_F012EF68;
      if (!bVar20) {
        iVar7 = *(int *)dword_F012EF68;
        pwVar17 = dword_F012EF68;
        while (bVar20 = pwVar17 == (word *)0x0, param_2 = pwVar17, iVar7 == 0) {
          param_2 = *(word **)(pwVar17 + 4);
          pwVar9 = pwVar17;
          if (param_2 == (word *)0x0) {
            bVar20 = true;
            break;
          }
          pwVar17 = param_2;
          iVar7 = *(int *)param_2;
        }
      }
      iVar7 = -0x2c2;
      if ((!bVar20) && (*(int *)(param_2 + 6) == *(int *)(iVar13 + 0x34))) {
        wVar1 = param_2[10];
        uVar3 = (uint)param_2[0xb];
        iVar7 = *(int *)(iVar13 + 0x38);
        uVar6 = (uint)param_2[9];
        uVar2 = (uint)param_2[8];
        .div(iVar7,*(undefined4 *)(iVar13 + 0x34));
        if (*(int *)(iVar13 + 0x34) == 1) {
          pwVar17 = param_2 + 0xe;
          .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
          iVar15 = *(int *)(iVar13 + 0x14);
          .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
          puVar14 = (undefined *)(iVar15 + uVar6 + uVar2);
          while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
            uVar6 = (uint)param_2[10];
            while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
              *puVar14 = *(undefined *)pwVar17;
              pwVar17 = (word *)((int)pwVar17 + 1);
              puVar14 = puVar14 + 1;
            }
            puVar14 = puVar14 + (iVar7 - (uint)wVar1);
          }
        }
        else {
          pwVar17 = param_2 + 0xe;
          if (*(int *)(iVar13 + 0x34) == 4) {
            .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
            iVar15 = *(int *)(iVar13 + 0x18);
            .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
            puVar16 = (undefined4 *)(iVar15 + uVar6 + uVar2);
            while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
              uVar6 = (uint)param_2[10];
              while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
                *puVar16 = *(undefined4 *)pwVar17;
                pwVar17 = pwVar17 + 2;
                puVar16 = puVar16 + 1;
              }
              puVar16 = puVar16 + (iVar7 - (uint)wVar1);
            }
          }
        }
        if (pwVar9 == (word *)0x0) {
          dword_F012EF68 = *(word **)(param_2 + 4);
        }
        else {
          *(undefined4 *)(pwVar9 + 4) = *(undefined4 *)(param_2 + 4);
        }
        if (dword_F012EF74 < 10) {
          dword_F012EF74 = dword_F012EF74 + 1;
          *(word **)(param_2 + 4) = dword_F012EF6C;
          dword_F012EF6C = param_2;
        }
        else {
          if (param_2 != (word *)unk_F01330E4) {
            _kmem_free(_kernel_map,param_2);
            iVar7 = 0;
            goto locret_F00E67CC;
          }
          dword_F012EF78 = 0xc04;
        }
        iVar7 = 0;
      }
    }
    else {
      iVar7 = -0x2c0;
    }
  }
locret_F00E67CC:
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=3081 start=0xf00e67d4 */

/* WARNING: Removing unreachable block (ram,0xf00e6914) */
/* WARNING: Removing unreachable block (ram,0xf00e6890) */

undefined8 _sparcfbRestoreMode(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar2 = param_1 * 0x44 + 8;
  iVar4 = _sparcfbs + iVar2;
  if ((0xf < param_1) || (*(int *)(_sparcfbs + iVar2) == 0)) {
    uVar5 = 0xfffffd40;
    goto locret_F00E6A20;
  }
  uVar1 = *(uint *)(_sparcfbs + iVar2);
  if (uVar1 == 2) {
    if (*(int *)(iVar4 + 0x40) != 0) {
      (**(code **)(iVar4 + 0x40))(param_1);
    }
    if (*(int *)(iVar4 + 0x30) != 8) {
      *(undefined4 *)(iVar4 + 0x30) = 8;
      *(undefined4 *)(iVar4 + 0x34) = 1;
      uVar5 = *(undefined4 *)(iVar4 + 0x20);
      .umul(uVar5,*(undefined4 *)(iVar4 + 0x34));
      *(undefined4 *)(iVar4 + 0x38) = uVar5;
      uVar5 = 0;
      goto locret_F00E6A20;
    }
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        if (*(int *)(iVar4 + 0x40) == 0) {
          uVar5 = 0;
        }
        else {
          (**(code **)(iVar4 + 0x40))(param_1);
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0xffffffff;
      }
      goto locret_F00E6A20;
    }
    if (uVar1 != 3) {
      uVar5 = 0xffffffff;
      goto locret_F00E6A20;
    }
    if (*(int *)(iVar4 + 4) != 0) {
      puVar3 = *(undefined4 **)(iVar4 + 8);
      iVar2 = 0;
      do {
        *puVar3 = 0x66;
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar2 < 0x100000);
    }
    *(undefined4 *)(iVar4 + 0x30) = 8;
    *(undefined4 *)(iVar4 + 0x34) = 1;
    uVar5 = *(undefined4 *)(iVar4 + 0x20);
    .umul(uVar5,*(undefined4 *)(iVar4 + 0x34));
    *(undefined4 *)(iVar4 + 0x38) = uVar5;
    iVar2 = param_1 * 0x44 + 8;
    if (param_1 < 0x10) {
      if (*(int *)(_sparcfbs + iVar2) == 0) {
        uVar5 = 0;
        goto locret_F00E6A20;
      }
      uVar1 = *(uint *)(_sparcfbs + iVar2);
      if (uVar1 != 2) {
        if (uVar1 < 3) {
          uVar5 = 0;
          if (uVar1 != 1) goto locret_F00E6A20;
        }
        else {
          uVar5 = 0;
          if (uVar1 != 3) goto locret_F00E6A20;
        }
        puVar3 = *(undefined4 **)(_sparcfbs + iVar2 + 0xc);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[1] = 0;
        puVar3[1] = 0;
        *puVar3 = 0xff000000;
        puVar3[1] = 0xff000000;
        puVar3[1] = 0xff000000;
        puVar3[1] = 0xff000000;
        *puVar3 = 0x99000000;
        puVar3[1] = 0x99000000;
        puVar3[1] = 0x99000000;
        puVar3[1] = 0x99000000;
        *puVar3 = 0x66000000;
        puVar3[1] = 0x66000000;
        puVar3[1] = 0x66000000;
        puVar3[1] = 0x66000000;
        *puVar3 = 0;
        uVar5 = 0;
        goto locret_F00E6A20;
      }
      iVar2 = *(int *)(_sparcfbs + iVar2 + 0xc);
      *(undefined4 *)(iVar2 + 0x4000) = 0;
      *(undefined4 *)(iVar2 + 0x4264) = 0x999999;
      *(undefined4 *)(iVar2 + 0x4198) = 0x666666;
      *(undefined4 *)(iVar2 + 0x43fc) = 0xffffff;
    }
  }
  uVar5 = 0;
locret_F00E6A20:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=3082 start=0xf00e6a28 */

sqword _Sparc_Framebuffer_Map(undefined4 param_1,uint param_2)

{
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
  undefined4 unaff_i3;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3083 start=0xf00ec204 */
//Error decompiling function: __internal_object_copyFromZone @ 0xf00ec204
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=3084 start=0xf00ec254 */

/* WARNING: Removing unreachable block (ram,0xf00ec26c) */
/* WARNING: Removing unreachable block (ram,0xf00ec27c) */
/* WARNING: Removing unreachable block (ram,0xf00ec258) */

undefined8 __internal_object_copy(int param_1,undefined4 param_2)

{
  int iVar1;
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
  undefined4 unaff_i3;
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
  iVar1 = param_1;
  _NXZoneFromPtr();
  if (iVar1 == 0) {
    iVar1 = param_1;
    _NXDefaultMallocZone(param_1);
  }
  __internal_object_copyFromZone(param_1,param_2,iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3085 start=0xf00ec28c */

/* WARNING: Removing unreachable block (ram,0xf00ec2a8) */
/* WARNING: Removing unreachable block (ram,0xf00ec29c) */

sqword __internal_object_dispose(int *param_1,uint param_2)

{
  int *piVar1;
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
  undefined4 unaff_i3;
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
  if (param_1 != (int *)0x0) {
    piVar1 = param_1;
    __objc_getFreedObjectClass();
    *param_1 = (int)piVar1;
    _free(param_1);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3086 start=0xf00ec2b8 */

/* WARNING: Removing unreachable block (ram,0xf00ec364) */
/* WARNING: Removing unreachable block (ram,0xf00ec330) */
/* WARNING: Removing unreachable block (ram,0xf00ec2fc) */
/* WARNING: Removing unreachable block (ram,0xf00ec2d8) */
/* WARNING: Removing unreachable block (ram,0xf00ec318) */
/* WARNING: Removing unreachable block (ram,0xf00ec338) */
/* WARNING: Removing unreachable block (ram,0xf00ec37c) */
/* WARNING: Removing unreachable block (ram,0xf00ec2d0) */

undefined8 __internal_object_reallocFromZone(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
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
  undefined4 unaff_i3;
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
  uVar1 = 0;
  if (param_1 == (uint *)0x0) {
    ___objc_error(0,aReallocatingNi,0);
  }
  __objc_getFreedObjectClass();
  if (*param_1 == uVar1) {
    ___objc_error(param_1,aReallocatingFr,0);
    uVar1 = *param_1;
  }
  else {
    uVar1 = *param_1;
  }
  puVar2 = *(uint **)(uVar1 + 0x14);
  if (param_2 < puVar2) {
    puVar3 = param_1;
    _object_getClassName(param_1);
    puVar2 = param_1;
    ___objc_error(param_1,aSURequestedSiz,puVar3,param_2);
  }
  uVar1 = *param_1;
  __objc_getFreedObjectClass();
  *param_1 = (uint)puVar2;
  (*(code *)*param_3)(param_3,param_1,param_2);
  if (param_3 == (uint *)0x0) {
    puVar2 = param_1;
    _object_getClassName(param_1);
    ___objc_error(param_1,aFailedOutOfMem,puVar2,param_2);
    param_3 = (uint *)0x0;
  }
  else {
    *param_3 = uVar1;
  }
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=3087 start=0xf00ec398 */

/* WARNING: Removing unreachable block (ram,0xf00ec3b0) */
/* WARNING: Removing unreachable block (ram,0xf00ec3c0) */
/* WARNING: Removing unreachable block (ram,0xf00ec39c) */

undefined8 __internal_object_realloc(int param_1,undefined4 param_2)

{
  int iVar1;
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
  undefined4 unaff_i3;
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
  iVar1 = param_1;
  _NXZoneFromPtr();
  if (iVar1 == 0) {
    iVar1 = param_1;
    _NXDefaultMallocZone(param_1);
  }
  __internal_object_reallocFromZone(param_1,param_2,iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3088 start=0xf00ec3d0 */
//Error decompiling function: _object_copy @ 0xf00ec3d0
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=3089 start=0xf00ec3f0 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _object_copyFromZone @ 0xf00ec3f0
/* GHIDRADEC_FUNCTION index=3090 start=0xf00ec414 */
//Error decompiling function: _object_dispose @ 0xf00ec414
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=3091 start=0xf00ec430 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _object_realloc @ 0xf00ec430
/* GHIDRADEC_FUNCTION index=3092 start=0xf00ec450 */
//Error decompiling function: _object_reallocFromZone @ 0xf00ec450
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=3093 start=0xf00ec474 */

/* WARNING: Removing unreachable block (ram,0xf00ec498) */

undefined8 _object_setInstanceVariable(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar1 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar1 = *param_1;
    _class_getInstanceVariable();
    if (iVar1 != 0) {
      *(undefined4 *)((int)param_1 + *(int *)(iVar1 + 8)) = param_3;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3094 start=0xf00ec4bc */

/* WARNING: Removing unreachable block (ram,0xf00ec4e0) */

undefined8 _object_getInstanceVariable(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
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
  iVar1 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar1 = *param_1;
    _class_getInstanceVariable();
    if (iVar1 == 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = *(undefined4 *)((int)param_1 + *(int *)(iVar1 + 8));
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3095 start=0xf00ec918 */

void __threadFreeExceptionStack(int param_1)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  puVar2 = unk_F012F048;
  iVar1 = DAT_f012f058;
  do {
    bVar3 = (undefined4 *)puVar2 == (undefined4 *)0x0;
    if (iVar1 == param_1) {
loc_F00EC950:
      if (!bVar3) {
        *(undefined4 *)puVar2 = 0;
        *(undefined4 *)((int)puVar2 + 0xc) = 0;
        *(undefined4 *)((int)puVar2 + 0x10) = 0;
      }
      return;
    }
    puVar2 = *(undefined **)((int)puVar2 + 0x14);
    if ((undefined4 *)puVar2 == (undefined4 *)0x0) {
      bVar3 = true;
      goto loc_F00EC950;
    }
    iVar1 = *(int *)((int)puVar2 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3096 start=0xf00ecb4c */

/* WARNING: Removing unreachable block (ram,0xf00ecbec) */
/* WARNING: Removing unreachable block (ram,0xf00ecb90) */
/* WARNING: Removing unreachable block (ram,0xf00ecbd8) */
/* WARNING: Removing unreachable block (ram,0xf00ecc10) */
/* WARNING: Removing unreachable block (ram,0xf00ecb50) */

undefined8 __NXAddAltHandler(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
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
  undefined4 unaff_i3;
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
  puVar1 = param_1;
  _current_thread_EXTERNAL();
  puVar4 = unk_F012F048;
  puVar2 = DAT_f012f058;
  do {
    if (puVar2 == puVar1) {
loc_F00ECB9C:
      uVar5 = *(uint *)((int)puVar4 + 0xc);
      if (uVar5 == *(uint *)((int)puVar4 + 8)) {
        if (*(undefined **)((int)puVar4 + 4) == unk_F012EF88) {
          *(uint *)((int)puVar4 + 8) = uVar5 + 1;
          uVar5 = (uVar5 + 1) * 0xc;
          _malloc();
          *(uint *)((int)puVar4 + 4) = uVar5;
          _bcopy(unk_F012EF88,uVar5,0xc0);
          uVar5 = *(uint *)((int)puVar4 + 0xc);
        }
        else {
          uVar5 = *(uint *)((int)puVar4 + 8);
          *(uint *)((int)puVar4 + 8) = uVar5 + 1;
          uVar3 = *(uint *)((int)puVar4 + 4);
          _realloc(uVar3,(uVar5 + 1) * 0xc);
          *(uint *)((int)puVar4 + 4) = uVar3;
          uVar5 = *(uint *)((int)puVar4 + 0xc);
        }
      }
      *(uint *)((int)puVar4 + 0xc) = uVar5 + 1;
      iVar6 = uVar5 * 0xc + *(uint *)((int)puVar4 + 4);
      *(uint *)(uVar5 * 0xc + *(uint *)((int)puVar4 + 4)) = *(uint *)puVar4;
      *(uint *)puVar4 = (int)((iVar6 - *(uint *)((int)puVar4 + 4)) * -0x55555555) >> 1 | 1;
      *(uint **)(iVar6 + 4) = param_1;
      *(undefined4 *)(iVar6 + 8) = param_2;
      return CONCAT44(param_2,*(uint *)puVar4);
    }
    puVar4 = *(undefined **)((int)puVar4 + 0x14);
    if ((uint *)puVar4 == (uint *)0x0) {
      sub_F00EC878();
      puVar4 = (undefined *)puVar1;
      goto loc_F00ECB9C;
    }
    puVar2 = *(uint **)((int)puVar4 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3097 start=0xf00ecc90 */

/* WARNING: Removing unreachable block (ram,0xf00ecd1c) */

undefined8 __NXRemoveAltHandler(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
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
  undefined4 unaff_i3;
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
  puVar3 = unk_F012F048;
  iVar1 = (param_1 + -1) / 2;
  iVar2 = unk_F012F048._0_4_;
  do {
    if (iVar2 == param_1) {
      *(int *)((int)puVar3 + 0xc) = iVar1 * 4 >> 2;
      *(int *)puVar3 = *(int *)(iVar1 * 0xc + *(int *)((int)puVar3 + 4));
locret_F00ECD24:
      return CONCAT44(param_2,param_1);
    }
    puVar3 = *(undefined **)((int)puVar3 + 0x14);
    if ((int *)puVar3 == (int *)0x0) {
      sub_F00EC96C(param_1,1);
      goto locret_F00ECD24;
    }
    iVar2 = *(int *)puVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3098 start=0xf00ecd2c */

/* WARNING: Removing unreachable block (ram,0xf00ecd70) */
/* WARNING: Removing unreachable block (ram,0xf00ecd30) */

undefined8 __NXAddHandler(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
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
  undefined4 unaff_i3;
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
  piVar1 = param_1;
  _current_thread_EXTERNAL();
  puVar4 = unk_F012F048;
  piVar3 = DAT_f012f058;
  do {
    if (piVar3 == piVar1) {
      iVar2 = *(int *)puVar4;
      piVar1 = (int *)puVar4;
loc_F00ECD80:
      param_1[0x1d] = iVar2;
      *piVar1 = (int)param_1;
      param_1[0x1e] = 0;
      return CONCAT44(param_2,param_1);
    }
    puVar4 = *(undefined **)((int)puVar4 + 0x14);
    if ((int *)puVar4 == (int *)0x0) {
      sub_F00EC878();
      iVar2 = *piVar1;
      goto loc_F00ECD80;
    }
    piVar3 = *(int **)((int)puVar4 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3099 start=0xf00ecd94 */

/* WARNING: Removing unreachable block (ram,0xf00ecdd8) */

undefined8 __NXRemoveHandler(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
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
  undefined4 unaff_i3;
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
  puVar2 = unk_F012F048;
  iVar1 = unk_F012F048._0_4_;
  do {
    if (iVar1 == param_1) {
      *(int *)puVar2 = *(int *)(param_1 + 0x74);
locret_F00ECDE0:
      return CONCAT44(param_2,param_1);
    }
    puVar2 = *(undefined **)((int)puVar2 + 0x14);
    if ((int *)puVar2 == (int *)0x0) {
      sub_F00EC96C(param_1,0);
      goto locret_F00ECDE0;
    }
    iVar1 = *(int *)puVar2;
  } while( true );
}

