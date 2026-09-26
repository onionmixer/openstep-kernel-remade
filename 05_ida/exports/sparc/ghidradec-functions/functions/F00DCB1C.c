
/* WARNING: Removing unreachable block (ram,0xf00dd31c) */
/* WARNING: Removing unreachable block (ram,0xf00dd36c) */
/* WARNING: Removing unreachable block (ram,0xf00dd0ec) */
/* WARNING: Removing unreachable block (ram,0xf00dd2dc) */
/* WARNING: Removing unreachable block (ram,0xf00dd068) */
/* WARNING: Removing unreachable block (ram,0xf00dce9c) */
/* WARNING: Removing unreachable block (ram,0xf00dd130) */
/* WARNING: Removing unreachable block (ram,0xf00dd094) */
/* WARNING: Removing unreachable block (ram,0xf00dd16c) */
/* WARNING: Removing unreachable block (ram,0xf00dcf1c) */
/* WARNING: Removing unreachable block (ram,0xf00dd1a0) */
/* WARNING: Removing unreachable block (ram,0xf00dd0bc) */
/* WARNING: Removing unreachable block (ram,0xf00dd1ec) */
/* WARNING: Removing unreachable block (ram,0xf00dcfa8) */
/* WARNING: Removing unreachable block (ram,0xf00dcf54) */
/* WARNING: Removing unreachable block (ram,0xf00dd21c) */
/* WARNING: Removing unreachable block (ram,0xf00dd270) */
/* WARNING: Removing unreachable block (ram,0xf00dcffc) */
/* WARNING: Removing unreachable block (ram,0xf00dd2b0) */
/* WARNING: Removing unreachable block (ram,0xf00dcfc8) */
/* WARNING: Removing unreachable block (ram,0xf00dcfdc) */
/* WARNING: Removing unreachable block (ram,0xf00dd2c4) */
/* WARNING: Removing unreachable block (ram,0xf00dd014) */
/* WARNING: Removing unreachable block (ram,0xf00dd284) */
/* WARNING: Removing unreachable block (ram,0xf00dd234) */
/* WARNING: Removing unreachable block (ram,0xf00dcf90) */
/* WARNING: Removing unreachable block (ram,0xf00dd1d8) */
/* WARNING: Removing unreachable block (ram,0xf00dcecc) */
/* WARNING: Removing unreachable block (ram,0xf00dd0d4) */
/* WARNING: Removing unreachable block (ram,0xf00dd1b8) */
/* WARNING: Removing unreachable block (ram,0xf00dd158) */
/* WARNING: Removing unreachable block (ram,0xf00dd080) */
/* WARNING: Removing unreachable block (ram,0xf00dd204) */
/* WARNING: Removing unreachable block (ram,0xf00dd140) */
/* WARNING: Removing unreachable block (ram,0xf00dd040) */
/* WARNING: Removing unreachable block (ram,0xf00dd248) */
/* WARNING: Removing unreachable block (ram,0xf00dd028) */
/* WARNING: Removing unreachable block (ram,0xf00dd100) */
/* WARNING: Removing unreachable block (ram,0xf00dd344) */
/* WARNING: Removing unreachable block (ram,0xf00dd388) */
/* WARNING: Removing unreachable block (ram,0xf00dcf78) */

qword -[OutputStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:]
                (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                uint param_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  uint uVar8;
  undefined4 unaff_l1;
  uint uVar9;
  uint uVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  uint uVar12;
  undefined4 unaff_l5;
  uint uVar13;
  undefined4 unaff_l6;
  uint uVar14;
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
  iVar11 = *(int *)(param_1 + 0x68);
  uVar8 = *(uint *)(param_3 + 8);
  uVar14 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  iVar7 = *(int *)((int)register0x00000038 + 100);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  uVar13 = 0;
  cVar1 = *(char *)((int)register0x00000038 + 0x5f);
  bVar2 = true;
  uVar10 = *(uint *)(param_1 + 0x70);
  uVar6 = *(int *)(param_3 + 4) - uVar8;
  uVar12 = *(uint *)(param_1 + 0x74);
  if (uVar6 < param_6) {
    param_6 = uVar6;
  }
  uVar4 = (uint)(iVar11 == 0);
  if ((*(int *)(param_1 + 0x78) == 0x8000) && (*(int *)(param_1 + 0x7c) == 0x8000)) {
    iVar3 = *(int *)(param_1 + 0x6c);
  }
  else {
    uVar4 = uVar4 | 2;
    iVar3 = *(int *)(param_1 + 0x6c);
  }
  if (iVar3 == 1) {
    if (*(int *)((int)register0x00000038 + 0x68) != 2) {
      iVar3 = *(int *)(param_1 + 0x6c);
      goto loc_F00DCBCC;
    }
    uVar4 = uVar4 | 0x10;
loc_F00DCBE4:
    iVar3 = *(int *)(param_1 + 100);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x6c);
loc_F00DCBCC:
    if (iVar3 == 2) {
      if (*(int *)((int)register0x00000038 + 0x68) == 1) {
        uVar4 = uVar4 | 0x20;
      }
      goto loc_F00DCBE4;
    }
    iVar3 = *(int *)(param_1 + 100);
  }
  if (iVar3 == 0x5622) {
    if (*(int *)((int)register0x00000038 + 0x60) != 0xac44) {
      iVar3 = *(int *)(param_1 + 100);
      goto loc_F00DCC18;
    }
    uVar4 = uVar4 | 4;
  }
  else {
    iVar3 = *(int *)(param_1 + 100);
loc_F00DCC18:
    if ((iVar3 == 0xac44) && (*(int *)((int)register0x00000038 + 0x60) == 0x5622)) {
      uVar4 = uVar4 | 8;
    }
  }
  if ((iVar11 == 3) && (iVar7 == 0)) {
    uVar4 = uVar4 | 0x40;
  }
  else if ((iVar11 == 3) && (iVar7 == 1)) {
    uVar4 = uVar4 | 0x80;
  }
  else if ((iVar11 == 0) && (iVar7 == 3)) {
    uVar4 = uVar4 | 0x100;
  }
  else if ((iVar11 == 0) && (iVar7 == 1)) {
    uVar4 = uVar4 | 0x200;
  }
  else if ((iVar11 == 1) && (iVar7 == 0)) {
    uVar4 = uVar4 | 0x400;
  }
  else if ((iVar11 == 1) && (iVar7 == 3)) {
    uVar4 = uVar4 | 0x800;
  }
  if (uVar4 == 0x18) {
    _audio_convertMonoToStereo(uVar8,uVar10,param_6,iVar11);
    uVar6 = param_6 << 1;
    uVar8 = param_6;
loc_F00DCF8C:
    _audio_resample44To22(uVar10,uVar12,uVar6,iVar11,param_1 + 0x80);
    uVar9 = param_6;
    param_6 = uVar8;
    goto loc_F00DD2E8;
  }
  uVar9 = param_6;
  if (uVar4 < 0x19) {
    if (uVar4 == 5) {
      uVar6 = param_6 >> 1;
      _audio_swapSamples(uVar8,uVar10,param_6 >> 2);
      uVar9 = uVar6;
loc_F00DD100:
      _audio_resample22To44(uVar10,uVar12,uVar6,iVar11);
      goto loc_F00DD2E8;
    }
    if (uVar4 < 6) {
      if (uVar4 == 2) {
loc_F00DD050:
        _audio_scaleSamples(uVar8,uVar10,param_6,iVar11,*(undefined4 *)(param_1 + 0x6c),
                            *(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c));
        uVar12 = uVar10;
        uVar14 = uVar8;
        goto loc_F00DD2E8;
      }
      if (uVar4 < 3) {
        uVar12 = uVar8;
        if (uVar4 == 0) goto loc_F00DD2E8;
        if (uVar4 == 1) {
          _audio_swapSamples(uVar8,uVar10,param_6 >> 1);
          uVar12 = uVar10;
          goto loc_F00DD2E8;
        }
      }
      else {
        if (uVar4 == 3) {
          _audio_swapSamples(uVar8,uVar10,param_6 >> 1);
          uVar8 = uVar10;
          uVar10 = uVar12;
          goto loc_F00DD050;
        }
        if (uVar4 == 4) {
          uVar6 = param_6 >> 1;
          uVar12 = uVar8;
          uVar9 = uVar6;
loc_F00DD248:
          _audio_resample22To44(uVar12,uVar10,uVar6,iVar11);
          uVar12 = uVar10;
          goto loc_F00DD2E8;
        }
      }
    }
    else {
      if (uVar4 == 0x10) {
        _audio_convertMonoToStereo(uVar8,uVar10,param_6 >> 1,iVar11);
        uVar12 = uVar10;
        uVar9 = param_6 >> 1;
        goto loc_F00DD2E8;
      }
      if (uVar4 < 0x11) {
        if (uVar4 == 8) {
          uVar4 = param_6 * 2;
          if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
            uVar4 = uVar6;
          }
          uVar12 = uVar8;
          param_6 = uVar4;
          uVar8 = uVar4 >> 1;
          goto loc_F00DD200;
        }
        if (uVar4 == 9) {
          uVar9 = param_6 * 2;
          if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
            uVar9 = uVar6;
          }
          _audio_resample44To22(uVar8,uVar10,uVar9,iVar11,param_1 + 0x80);
          _audio_swapSamples(uVar10,uVar12,uVar9 >> 2);
          param_6 = uVar9 >> 1;
          goto loc_F00DD2E8;
        }
      }
      else {
        if (uVar4 == 0x14) {
          uVar9 = param_6 >> 2;
          _audio_convertMonoToStereo(uVar8,uVar10,uVar9,iVar11);
          uVar6 = uVar9 << 1;
          goto loc_F00DD100;
        }
        if (uVar4 < 0x15) {
          if (uVar4 == 0x11) {
            _audio_swapSamples(uVar8,uVar10,param_6 >> 2);
            _audio_convertMonoToStereo(uVar10,uVar12,param_6 >> 1,iVar11);
            uVar9 = param_6 >> 1;
            goto loc_F00DD2E8;
          }
        }
        else if (uVar4 == 0x15) {
          uVar9 = param_6 >> 2;
          _audio_swapSamples(uVar8,uVar10,param_6 >> 3);
          _audio_convertMonoToStereo(uVar10,uVar12,uVar9,iVar11);
          uVar6 = uVar9 << 1;
          goto loc_F00DD248;
        }
      }
    }
  }
  else {
    if (uVar4 == 0x29) {
      param_6 = param_6 * 4;
      if (uVar6 <= param_6 && param_6 - uVar6 != 0) {
        param_6 = uVar6;
      }
      uVar4 = param_6 >> 1;
      _audio_swapSamples(uVar8,uVar10,uVar4);
      _audio_convertStereoToMono(uVar10,uVar12,param_6,iVar11,param_1 + 0x84);
      uVar8 = param_6 >> 2;
loc_F00DD200:
      _audio_resample44To22(uVar12,uVar10,uVar4,iVar11,param_1 + 0x80);
      uVar12 = uVar10;
      uVar9 = param_6;
      param_6 = uVar8;
      goto loc_F00DD2E8;
    }
    if (uVar4 < 0x2a) {
      if (uVar4 == 0x21) {
        uVar9 = param_6 * 2;
        if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
          uVar9 = uVar6;
        }
        _audio_swapSamples(uVar8,uVar10,uVar9 >> 1);
        _audio_convertStereoToMono(uVar10,uVar12,uVar9,iVar11,param_1 + 0x84);
        param_6 = uVar9 >> 1;
        goto loc_F00DD2E8;
      }
      if (uVar4 < 0x22) {
        if (uVar4 == 0x19) {
          _audio_swapSamples(uVar8,uVar10,param_6 >> 1);
          _audio_convertMonoToStereo(uVar10,uVar12,param_6,iVar11);
          uVar4 = param_6 << 1;
          uVar8 = param_6;
          goto loc_F00DD200;
        }
        if (uVar4 == 0x20) {
          uVar9 = param_6 * 2;
          if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
            uVar9 = uVar6;
          }
          _audio_convertStereoToMono(uVar8,uVar10,uVar9,iVar11,param_1 + 0x84);
          uVar12 = uVar10;
          param_6 = uVar9 >> 1;
          goto loc_F00DD2E8;
        }
      }
      else {
        if (uVar4 == 0x25) {
          uVar6 = param_6 >> 1;
          _audio_swapSamples(uVar8,uVar10,uVar6);
          _audio_convertStereoToMono(uVar10,uVar12,param_6,iVar11,param_1 + 0x84);
          goto loc_F00DD248;
        }
        if (uVar4 < 0x26) {
          if (uVar4 == 0x24) {
            _audio_convertStereoToMono(uVar8,uVar10,param_6,iVar11,param_1 + 0x84);
            uVar6 = param_6 >> 1;
            goto loc_F00DD100;
          }
        }
        else if (uVar4 == 0x28) {
          param_6 = param_6 * 4;
          if (uVar6 <= param_6 && param_6 - uVar6 != 0) {
            param_6 = uVar6;
          }
          _audio_convertStereoToMono(uVar8,uVar10,param_6,iVar11,param_1 + 0x84);
          uVar6 = param_6 >> 1;
          uVar8 = param_6 >> 2;
          goto loc_F00DCF8C;
        }
      }
      goto loc_F00DD2D8;
    }
    if (uVar4 == 0x101) {
      uVar9 = param_6 * 2;
      if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
        uVar9 = uVar6;
      }
      param_6 = uVar9 >> 1;
      _audio_swapSamples(uVar8,uVar10,param_6);
      _audio_convertLinear16ToLinear8(uVar10,uVar12,param_6,param_1 + 0x88);
      iVar11 = 3;
      goto loc_F00DD2E8;
    }
    if (uVar4 < 0x102) {
      if (uVar4 == 0x40) {
        _audio_convertLinear8ToLinear16(uVar8,uVar10,param_6 >> 1);
loc_F00DD008:
        iVar11 = 0;
        uVar12 = uVar10;
        uVar9 = param_6 >> 1;
        goto loc_F00DD2E8;
      }
      if (uVar4 == 0x80) {
        _audio_convertLinear8ToMulaw8(uVar8,uVar10,param_6);
        iVar11 = 1;
        uVar12 = uVar10;
        goto loc_F00DD2E8;
      }
    }
    else {
      if (uVar4 == 0x400) {
        _audio_convertMulaw8ToLinear16(uVar8,uVar10,param_6 >> 1);
        goto loc_F00DD008;
      }
      if (uVar4 < 0x401) {
        if (uVar4 == 0x201) {
          uVar9 = param_6 * 2;
          if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
            uVar9 = uVar6;
          }
          param_6 = uVar9 >> 1;
          _audio_swapSamples(uVar8,uVar10,param_6);
          _audio_convertLinear16ToMulaw8(uVar10,uVar12,param_6,param_1 + 0x88);
          iVar11 = 1;
          goto loc_F00DD2E8;
        }
      }
      else if (uVar4 == 0x800) {
        _audio_convertMulaw8ToLinear8(uVar8,uVar10,param_6);
        iVar11 = 3;
        uVar12 = uVar10;
        goto loc_F00DD2E8;
      }
    }
  }
loc_F00DD2D8:
  _IOLog(aAudioUnsupport,uVar4);
  bVar2 = false;
  uVar12 = uVar8;
loc_F00DD2E8:
  if (bVar2) {
    if (*(char *)(param_1 + 0x94) != '\0') {
      if (iVar11 == 0) {
        _audio_linear16_peak
                  (*(undefined4 *)(param_1 + 0x6c),uVar12,param_6,
                   (undefined *)((int)register0x00000038 + -0x14),
                   (undefined *)((int)register0x00000038 + -0x18));
      }
      else if (iVar11 == 3) {
        _audio_linear8_peak(*(undefined4 *)(param_1 + 0x6c),uVar12,param_6,
                            (undefined *)((int)register0x00000038 + -0x14),
                            (undefined *)((int)register0x00000038 + -0x18));
      }
      else if (iVar11 == 1) {
        _audio_mulaw8_peak(*(undefined4 *)(param_1 + 0x6c),uVar12,param_6,
                           (undefined *)((int)register0x00000038 + -0x14),
                           (undefined *)((int)register0x00000038 + -0x18));
      }
    }
    _audio_mix(uVar12,param_5,param_6,iVar11,(int)cVar1);
    uVar13 = uVar12;
  }
  *(uint *)(param_3 + 8) = *(int *)(param_3 + 8) + uVar9;
  if (uVar14 < uVar13) {
    uVar14 = uVar13;
  }
  piVar5 = *(int **)(param_1 + 0x8c);
  iVar11 = *(int *)((int)register0x00000038 + -0x14);
  iVar7 = *(int *)((int)register0x00000038 + -0x18);
  if ((int *)(param_1 + 0x8c) != piVar5) {
    iVar3 = *piVar5;
    while ((param_4 != iVar3 && (iVar3 != 0))) {
      piVar5 = (int *)piVar5[5];
      if ((int *)(param_1 + 0x8c) == piVar5) goto locret_F00DD40C;
      iVar3 = *piVar5;
    }
    *piVar5 = param_4;
    piVar5[1] = uVar9;
    piVar5[2] = iVar11;
    piVar5[3] = iVar7;
    piVar5[4] = uVar14;
  }
locret_F00DD40C:
  return (qword)CONCAT14(cVar1,param_6);
}
