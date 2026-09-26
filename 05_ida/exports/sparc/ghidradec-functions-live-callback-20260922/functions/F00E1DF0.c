
/* WARNING: Removing unreachable block (ram,0xf00e1f3c) */
/* WARNING: Removing unreachable block (ram,0xf00e1f20) */

undefined8 _audio_convertStereoToMono(byte *param_1,undefined2 *param_2,uint param_3,int param_4)

{
  byte bVar1;
  sword sVar2;
  undefined uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  uVar6 = param_3 >> 1;
  if (param_4 == 1) {
    while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
      bVar1 = *param_1;
      pbVar5 = param_1 + 1;
      param_1 = param_1 + 2;
      iVar4 = (int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2) +
              (int)*(sword *)(_audio_muLaw + (uint)*pbVar5 * 2) +
              ((int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2) +
               (int)*(sword *)(_audio_muLaw + (uint)*pbVar5 * 2) & 1U);
      uVar3 = (undefined)((uint)((iVar4 - (iVar4 >> 0x1f)) * 0x8000) >> 0x10);
      _audio_shortToMulaw();
      *(undefined *)param_2 = uVar3;
      param_2 = (undefined2 *)((int)param_2 + 1);
    }
  }
  else {
    if (param_4 < 2) {
      param_3 = param_3 >> 2;
      if (param_4 == 0) {
        while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
          sVar2 = *(sword *)param_1;
          pbVar5 = param_1 + 2;
          param_1 = param_1 + 4;
          iVar4 = (int)sVar2 + (int)*(sword *)pbVar5 + ((int)sVar2 + (int)*(sword *)pbVar5 & 1U);
          *param_2 = (sword)((uint)(iVar4 - (iVar4 >> 0x1f)) >> 1);
          param_2 = param_2 + 1;
        }
        goto locret_F00E1F44;
      }
    }
    else if (param_4 == 3) {
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        bVar1 = *param_1;
        pbVar5 = param_1 + 1;
        param_1 = param_1 + 2;
        iVar4 = (int)(char)bVar1 + (int)(char)*pbVar5 + ((int)(char)bVar1 + (int)(char)*pbVar5 & 1U)
        ;
        *(char *)param_2 = (char)((uint)(iVar4 - (iVar4 >> 0x1f)) >> 1);
        param_2 = (undefined2 *)((int)param_2 + 1);
      }
      goto locret_F00E1F44;
    }
    _IOLog(aAudioUnrecogni_6);
  }
locret_F00E1F44:
  return CONCAT44(param_2,param_1);
}

