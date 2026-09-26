/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9c54 */

uint FUN_001b9c54(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 uint param_6,char param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_8 = 0;
  local_c = 0;
  local_18 = 0;
  bVar4 = true;
  local_24 = *(int *)(param_1 + 0x68);
  iVar1 = *(int *)(param_1 + 0x70);
  iVar7 = *(int *)(param_1 + 0x74);
  iVar2 = *(int *)(param_3 + 8);
  local_1c = param_6;
  uVar6 = *(int *)(param_3 + 4) - iVar2;
  if (uVar6 < param_6) {
    local_1c = uVar6;
  }
  bVar9 = local_24 == 0;
  if ((*(int *)(param_1 + 0x78) != 0x8000) || (*(int *)(param_1 + 0x7c) != 0x8000)) {
    bVar9 = bVar9 | 2;
  }
  uVar5 = (uint)bVar9;
  if ((*(int *)(param_1 + 0x6c) == 1) && (param_10 == 2)) {
    uVar5 = uVar5 | 0x10;
  }
  else if ((*(int *)(param_1 + 0x6c) == 2) && (param_10 == 1)) {
    uVar5 = uVar5 | 0x20;
  }
  if ((*(int *)(param_1 + 100) == 0x5622) && (param_8 == 0xac44)) {
    uVar5 = uVar5 | 4;
  }
  else if ((*(int *)(param_1 + 100) == 0xac44) && (param_8 == 0x5622)) {
    uVar5 = uVar5 | 8;
  }
  if (local_24 == 3) {
    if (param_9 == 0) {
      uVar5 = uVar5 | 0x40;
    }
    else {
      if (param_9 != 1) goto LAB_001b9d54;
      uVar5 = uVar5 | 0x80;
    }
  }
  else {
LAB_001b9d54:
    if (local_24 == 0) {
      if (param_9 == 3) {
        uVar5 = uVar5 | 0x100;
      }
      else {
        if (param_9 != 1) goto LAB_001b9d74;
        uVar5 = uVar5 | 0x200;
      }
    }
    else {
LAB_001b9d74:
      if (local_24 == 1) {
        if (param_9 == 0) {
          uVar5 = uVar5 | 0x400;
        }
        else if (param_9 == 3) {
          uVar5 = uVar5 | 0x800;
        }
      }
    }
  }
  uVar8 = local_1c;
  if (uVar5 == 0x18) {
    _audio_convertMonoToStereo(iVar2,iVar1,local_1c,local_24);
    _audio_resample44To22(iVar1,iVar7,local_1c * 2,local_24,param_1 + 0x80);
    goto LAB_001ba36f;
  }
  if (uVar5 < 0x19) {
    if (uVar5 == 5) {
      _audio_swapSamples(iVar2,iVar1,local_1c >> 2);
      _audio_resample22To44(iVar1,iVar7,local_1c >> 1,local_24);
      uVar8 = local_1c >> 1;
      goto LAB_001ba36f;
    }
    if (uVar5 < 6) {
      if (uVar5 == 2) {
        local_14 = _audio_scaleSamples(iVar2,iVar1,local_1c,local_24,*(undefined4 *)(param_1 + 0x6c)
                                       ,*(undefined4 *)(param_1 + 0x78),
                                       *(undefined4 *)(param_1 + 0x7c));
        iVar7 = iVar1;
        goto LAB_001ba36f;
      }
      if (uVar5 < 3) {
        iVar7 = iVar2;
        if (uVar5 == 0) goto LAB_001ba36f;
        if (uVar5 == 1) {
          _audio_swapSamples(iVar2,iVar1,local_1c >> 1);
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
      }
      else {
        if (uVar5 == 3) {
          _audio_swapSamples(iVar2,iVar1,local_1c >> 1);
          local_14 = _audio_scaleSamples(iVar1,iVar7,local_1c,local_24,
                                         *(undefined4 *)(param_1 + 0x6c),
                                         *(undefined4 *)(param_1 + 0x78),
                                         *(undefined4 *)(param_1 + 0x7c));
          goto LAB_001ba36f;
        }
        if (uVar5 == 4) {
          uVar8 = local_1c >> 1;
          iVar7 = iVar2;
          goto LAB_001ba2d0;
        }
      }
    }
    else {
      if (uVar5 == 0x10) {
        _audio_convertMonoToStereo(iVar2,iVar1,local_1c >> 1,local_24);
        iVar7 = iVar1;
        uVar8 = local_1c >> 1;
        goto LAB_001ba36f;
      }
      if (uVar5 < 0x11) {
        if (uVar5 == 8) {
          uVar8 = local_1c * 2;
          if (uVar6 < local_1c * 2) {
            uVar8 = uVar6;
          }
          local_1c = uVar8 >> 1;
          iVar7 = iVar2;
          uVar6 = uVar8;
          goto LAB_001ba24c;
        }
        if (uVar5 == 9) {
          uVar8 = local_1c * 2;
          if (uVar6 < local_1c * 2) {
            uVar8 = uVar6;
          }
          local_1c = uVar8 >> 1;
          _audio_resample44To22(iVar2,iVar1,uVar8,local_24,param_1 + 0x80);
          _audio_swapSamples(iVar1,iVar7,uVar8 >> 2);
          goto LAB_001ba36f;
        }
      }
      else {
        if (uVar5 == 0x14) {
          uVar8 = local_1c >> 2;
          _audio_convertMonoToStereo(iVar2,iVar1,uVar8,local_24);
          _audio_resample22To44(iVar1,iVar7,uVar8 * 2,local_24);
          goto LAB_001ba36f;
        }
        if (uVar5 < 0x15) {
          if (uVar5 == 0x11) {
            _audio_swapSamples(iVar2,iVar1,local_1c >> 2);
            _audio_convertMonoToStereo(iVar1,iVar7,local_1c >> 1,local_24);
            uVar8 = local_1c >> 1;
            goto LAB_001ba36f;
          }
        }
        else if (uVar5 == 0x15) {
          uVar8 = local_1c >> 2;
          _audio_swapSamples(iVar2,iVar1,local_1c >> 3);
          _audio_convertMonoToStereo(iVar1,iVar7,uVar8,local_24);
          _audio_resample22To44(iVar7,iVar1,uVar8 * 2,local_24);
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
      }
    }
  }
  else {
    if (uVar5 == 0x29) {
      uVar8 = local_1c << 2;
      if (uVar6 < local_1c << 2) {
        uVar8 = uVar6;
      }
      local_1c = uVar8 >> 2;
      uVar6 = uVar8 >> 1;
      _audio_swapSamples(iVar2,iVar1,uVar6);
      _audio_convertStereoToMono(iVar1,iVar7,uVar8,local_24,param_1 + 0x84);
LAB_001ba24c:
      _audio_resample44To22(iVar7,iVar1,uVar6,local_24,param_1 + 0x80);
      iVar7 = iVar1;
      goto LAB_001ba36f;
    }
    if (uVar5 < 0x2a) {
      if (uVar5 == 0x21) {
        uVar8 = local_1c * 2;
        if (uVar6 < local_1c * 2) {
          uVar8 = uVar6;
        }
        local_1c = uVar8 >> 1;
        _audio_swapSamples(iVar2,iVar1,local_1c);
        _audio_convertStereoToMono(iVar1,iVar7,uVar8,local_24,param_1 + 0x84);
        goto LAB_001ba36f;
      }
      if (uVar5 < 0x22) {
        if (uVar5 == 0x19) {
          _audio_swapSamples(iVar2,iVar1,local_1c >> 1);
          _audio_convertMonoToStereo(iVar1,iVar7,local_1c,local_24);
          _audio_resample44To22(iVar7,iVar1,local_1c * 2,local_24,param_1 + 0x80);
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
        if (uVar5 == 0x20) {
          uVar8 = local_1c * 2;
          if (uVar6 < local_1c * 2) {
            uVar8 = uVar6;
          }
          local_1c = uVar8 >> 1;
          _audio_convertStereoToMono(iVar2,iVar1,uVar8,local_24,param_1 + 0x84);
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
      }
      else {
        if (uVar5 == 0x25) {
          _audio_swapSamples(iVar2,iVar1,local_1c >> 1);
          _audio_convertStereoToMono(iVar1,iVar7,local_1c,local_24,param_1 + 0x84);
LAB_001ba2d0:
          _audio_resample22To44(iVar7,iVar1,local_1c >> 1,local_24);
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
        if (uVar5 < 0x26) {
          if (uVar5 == 0x24) {
            _audio_convertStereoToMono(iVar2,iVar1,local_1c,local_24,param_1 + 0x84);
            _audio_resample22To44(iVar1,iVar7,local_1c >> 1,local_24);
            goto LAB_001ba36f;
          }
        }
        else if (uVar5 == 0x28) {
          uVar8 = local_1c << 2;
          if (uVar6 < local_1c << 2) {
            uVar8 = uVar6;
          }
          local_1c = uVar8 >> 2;
          _audio_convertStereoToMono(iVar2,iVar1,uVar8,local_24,param_1 + 0x84);
          _audio_resample44To22(iVar1,iVar7,uVar8 >> 1,local_24,param_1 + 0x80);
          goto LAB_001ba36f;
        }
      }
    }
    else {
      if (uVar5 == 0x101) {
        uVar8 = local_1c * 2;
        if (uVar6 < local_1c * 2) {
          uVar8 = uVar6;
        }
        local_1c = uVar8 >> 1;
        _audio_swapSamples(iVar2,iVar1,local_1c);
        _audio_convertLinear16ToLinear8(iVar1,iVar7,local_1c,param_1 + 0x88);
        local_24 = 3;
        goto LAB_001ba36f;
      }
      if (uVar5 < 0x102) {
        if (uVar5 == 0x40) {
          _audio_convertLinear8ToLinear16(iVar2,iVar1,local_1c >> 1);
          local_24 = 0;
          iVar7 = iVar1;
          uVar8 = local_1c >> 1;
          goto LAB_001ba36f;
        }
        if (uVar5 == 0x80) {
          _audio_convertLinear8ToMulaw8(iVar2,iVar1,local_1c);
          local_24 = 1;
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
      }
      else {
        if (uVar5 == 0x400) {
          uVar8 = local_1c >> 1;
          _audio_convertMulaw8ToLinear16(iVar2,iVar1,uVar8);
          local_24 = 0;
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
        if (uVar5 < 0x401) {
          if (uVar5 == 0x201) {
            uVar8 = local_1c * 2;
            if (uVar6 < local_1c * 2) {
              uVar8 = uVar6;
            }
            local_1c = uVar8 >> 1;
            _audio_swapSamples(iVar2,iVar1,local_1c);
            _audio_convertLinear16ToMulaw8(iVar1,iVar7,local_1c,param_1 + 0x88);
            local_24 = 1;
            goto LAB_001ba36f;
          }
        }
        else if (uVar5 == 0x800) {
          _audio_convertMulaw8ToLinear8(iVar2,iVar1,local_1c);
          local_24 = 3;
          iVar7 = iVar1;
          goto LAB_001ba36f;
        }
      }
    }
  }
  _IOLog("Audio: unsupported mixing conversion 0x%x\n",uVar5);
  bVar4 = false;
  iVar7 = iVar2;
LAB_001ba36f:
  if (bVar4) {
    if (*(char *)(param_1 + 0x94) != '\0') {
      if (local_24 == 0) {
        _audio_linear16_peak(*(undefined4 *)(param_1 + 0x6c),iVar7,local_1c,&local_8,&local_c);
      }
      else if (local_24 == 3) {
        _audio_linear8_peak(*(undefined4 *)(param_1 + 0x6c),iVar7,local_1c,&local_8,&local_c);
      }
      else if (local_24 == 1) {
        _audio_mulaw8_peak(*(undefined4 *)(param_1 + 0x6c),iVar7,local_1c,&local_8,&local_c);
      }
    }
    local_18 = _audio_mix(iVar7,param_5,local_1c,local_24,(int)param_7);
  }
  *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + uVar8;
  if (local_14 < local_18) {
    local_14 = local_18;
  }
  piVar3 = *(int **)(param_1 + 0x8c);
  while( true ) {
    if ((int *)(param_1 + 0x8c) == piVar3) {
      return local_1c;
    }
    if ((param_4 == *piVar3) || (*piVar3 == 0)) break;
    piVar3 = (int *)piVar3[5];
  }
  *piVar3 = param_4;
  piVar3[1] = uVar8;
  piVar3[2] = local_8;
  piVar3[3] = local_c;
  piVar3[4] = local_14;
  return local_1c;
}

