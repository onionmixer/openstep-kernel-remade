/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001af42c */

int FUN_001af42c(undefined *param_1,undefined4 param_2,int *param_3,char *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint **ppuVar4;
  char **ppcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  undefined4 uStack_6c;
  undefined *puStack_68;
  undefined *puStack_64;
  undefined **ppuStack_60;
  undefined *puStack_5c;
  int *piStack_58;
  char *pcStack_54;
  uint *puStack_50;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  undefined *local_34;
  undefined *local_30;
  uint local_2c;
  uint local_28 [5];
  int local_14 [4];
  
  local_38 = -0x2c2;
  local_3c = *param_5;
  local_2c = 0;
  iVar1 = 0x13;
  bVar8 = true;
  pcVar6 = param_4;
  pcVar7 = "Ev_ButtonEventNums";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    if (local_3c < 2) goto LAB_001afbc5;
    local_2c = 2;
    puStack_50 = (uint *)PTR_s_lock_001f9220;
    pcStack_54 = *(char **)(param_1 + 0x110);
    piStack_58 = (int *)0x1af487;
    _objc_msgSend();
    *param_3 = (int)*(short *)(param_1 + 500);
    param_3[1] = (int)*(short *)(param_1 + 0x1f6);
    piStack_58 = (int *)PTR_s_unlock_001f9474;
    puStack_5c = *(undefined **)(param_1 + 0x110);
    ppcVar5 = &puStack_5c;
    goto LAB_001afae2;
  }
  iVar1 = 0xd;
  bVar8 = true;
  pcVar6 = param_4;
  pcVar7 = "Ev_ShmemSize";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    if (local_3c != 0) {
      local_2c = 1;
      *param_3 = *(int *)(param_1 + 0x160);
      local_38 = 0;
    }
    goto LAB_001afbc5;
  }
  iVar1 = 0x1a;
  bVar8 = true;
  pcVar6 = param_4;
  pcVar7 = "Evs_CurrentWaitCursorInfo";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    if (local_3c < 6) goto LAB_001afbc5;
    local_2c = 6;
    puStack_50 = (uint *)PTR_s_lock_001f9220;
    pcStack_54 = *(char **)(param_1 + 0x110);
    piStack_58 = (int *)0x1af53b;
    _objc_msgSend();
    if (param_1[0x1d2] == '\x01') {
      uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x168) + 0x4c);
      local_14[3] = ((int)uVar2 >> 0x1f) << 0x18 | uVar2 >> 8;
      local_14[2] = uVar2 << 0x18;
    }
    else {
      local_14[2] = 0;
      local_14[3] = 0;
    }
    local_14[0] = local_14[2];
    local_14[1] = local_14[3];
    uVar2 = 0;
    do {
      param_3[uVar2] = local_14[uVar2];
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
    local_14[0] = *(int *)(param_1 + 0x1d4);
    local_14[1] = *(undefined4 *)(param_1 + 0x1d8);
    uVar2 = 0;
    do {
      param_3[uVar2 + 2] = local_14[uVar2];
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
    local_14[0] = *(int *)(param_1 + 0x1e4);
    local_14[1] = *(uint *)(param_1 + 0x1e8);
    uVar2 = 0;
    do {
      param_3[uVar2 + 4] = local_14[uVar2];
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
    ppuVar4 = &puStack_50;
    puStack_50 = (uint *)PTR_s_unlock_001f9474;
    uVar3 = *(undefined4 *)(param_1 + 0x110);
LAB_001afae1:
    ppcVar5 = (char **)((int)ppuVar4 + -4);
    *(undefined4 *)((int)ppuVar4 + -4) = uVar3;
  }
  else {
    iVar1 = 0x16;
    bVar8 = true;
    pcVar6 = param_4;
    pcVar7 = "Evs_DeviceControlInfo";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      if (local_3c < 3) goto LAB_001afbc5;
      local_2c = 3;
      puStack_50 = (uint *)PTR_s_lock_001f9220;
      pcStack_54 = *(char **)(param_1 + 0x110);
      piStack_58 = (int *)0x1af643;
      _objc_msgSend();
      piStack_58 = (int *)PTR_s_brightness_001f9a28;
      puStack_5c = param_1;
      ppuStack_60 = (undefined **)0x1af653;
      iVar1 = _objc_msgSend();
      *param_3 = iVar1;
      param_3[1] = *(int *)(param_1 + 0x1c4);
      ppuStack_60 = (undefined **)PTR_s_autoDimBrightness_001f9a24;
      puStack_64 = param_1;
      puStack_68 = (undefined *)0x1af671;
      iVar1 = _objc_msgSend();
      param_3[2] = iVar1;
      puStack_68 = PTR_s_unlock_001f9474;
      uStack_6c = *(undefined4 *)(param_1 + 0x110);
      ppcVar5 = (char **)&uStack_6c;
    }
    else {
      iVar1 = 0x15;
      bVar8 = true;
      pcVar6 = param_4;
      pcVar7 = "Evs_CurrentClickTime";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        if (local_3c < 2) goto LAB_001afbc5;
        local_2c = 2;
        puStack_50 = (uint *)PTR_s_lock_001f9220;
        pcStack_54 = *(char **)(param_1 + 0x110);
        piStack_58 = (int *)0x1af6cb;
        _objc_msgSend();
        local_14[3] = *(uint *)(param_1 + 0x1bc) >> 8;
        local_14[2] = *(uint *)(param_1 + 0x1bc) << 0x18;
        local_14[0] = local_14[2];
        local_14[1] = local_14[3];
        uVar2 = 0;
        do {
          param_3[uVar2] = local_14[uVar2];
          uVar2 = uVar2 + 1;
        } while (uVar2 < 2);
        ppuVar4 = &puStack_50;
        puStack_50 = (uint *)PTR_s_unlock_001f9474;
        uVar3 = *(undefined4 *)(param_1 + 0x110);
        goto LAB_001afae1;
      }
      iVar1 = 0x17;
      bVar8 = true;
      pcVar6 = param_4;
      pcVar7 = "Evs_CurrentAutoDimTime";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        if (local_3c < 2) goto LAB_001afbc5;
        local_2c = 2;
        puStack_50 = (uint *)PTR_s_lock_001f9220;
        pcStack_54 = *(char **)(param_1 + 0x110);
        piStack_58 = (int *)0x1af753;
        _objc_msgSend();
        local_14[3] = *(uint *)(param_1 + 0x1a0) >> 8;
        local_14[2] = *(uint *)(param_1 + 0x1a0) << 0x18;
        local_14[0] = local_14[2];
        local_14[1] = local_14[3];
        uVar2 = 0;
        do {
          param_3[uVar2] = local_14[uVar2];
          uVar2 = uVar2 + 1;
        } while (uVar2 < 2);
        puStack_50 = (uint *)PTR_s_unlock_001f9474;
        pcStack_54 = *(char **)(param_1 + 0x110);
        ppcVar5 = &pcStack_54;
        goto LAB_001afae2;
      }
      iVar1 = 0x18;
      bVar8 = true;
      pcVar6 = param_4;
      pcVar7 = "Evs_GetDeltaAutoDimTime";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar1 = 0x10;
        bVar8 = true;
        pcVar6 = param_4;
        pcVar7 = "Evs_GetIdleTime";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          if (local_3c < 2) goto LAB_001afbc5;
          local_2c = 2;
          puStack_50 = (uint *)PTR_s_lock_001f9220;
          pcStack_54 = *(char **)(param_1 + 0x110);
          piStack_58 = (int *)0x1af8af;
          _objc_msgSend();
          if (param_1[0x1d2] == '\x01') {
            if (param_1[0x1d3] == '\0') {
              uVar2 = *(int *)(param_1 + 0x1a0) -
                      (*(int *)(param_1 + 0x1a4) - *(int *)(*(int *)(param_1 + 0x168) + 0x10));
            }
            else {
              uVar2 = *(int *)(*(int *)(param_1 + 0x168) + 0x10) -
                      (*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0));
            }
            local_14[3] = uVar2 >> 8;
            local_14[2] = uVar2 << 0x18;
          }
          else {
            local_14[2] = 0;
            local_14[3] = 0;
          }
          local_14[0] = local_14[2];
          local_14[1] = local_14[3];
          uVar2 = 0;
          do {
            param_3[uVar2] = local_14[uVar2];
            uVar2 = uVar2 + 1;
          } while (uVar2 < 2);
          ppuVar4 = &puStack_50;
          puStack_50 = (uint *)PTR_s_unlock_001f9474;
          uVar3 = *(undefined4 *)(param_1 + 0x110);
        }
        else {
          iVar1 = 0x16;
          bVar8 = true;
          pcVar6 = param_4;
          pcVar7 = "Evs_CurrentClickSpace";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar8 = *pcVar6 == *pcVar7;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            if (local_3c < 2) goto LAB_001afbc5;
            local_2c = 2;
            puStack_50 = (uint *)PTR_s_lock_001f9220;
            pcStack_54 = *(char **)(param_1 + 0x110);
            piStack_58 = (int *)0x1af997;
            _objc_msgSend();
            *param_3 = (int)*(short *)(param_1 + 0x1b0);
            param_3[1] = (int)*(short *)(param_1 + 0x1b2);
            ppuVar4 = (uint **)&piStack_58;
            piStack_58 = (int *)PTR_s_unlock_001f9474;
            uVar3 = *(undefined4 *)(param_1 + 0x110);
          }
          else {
            iVar1 = 0xf;
            bVar8 = true;
            pcVar6 = param_4;
            pcVar7 = "Evs_AutoDimmed";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar8 = *pcVar6 == *pcVar7;
              pcVar6 = pcVar6 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (bVar8) {
              if (local_3c == 0) goto LAB_001afbc5;
              local_2c = 1;
              puStack_50 = (uint *)PTR_s_lock_001f9220;
              pcStack_54 = *(char **)(param_1 + 0x110);
              piStack_58 = (int *)0x1afa07;
              _objc_msgSend();
              *param_3 = (int)(char)param_1[0x1d3];
              ppuVar4 = (uint **)&piStack_58;
              piStack_58 = (int *)PTR_s_unlock_001f9474;
              uVar3 = *(undefined4 *)(param_1 + 0x110);
            }
            else {
              iVar1 = 0x14;
              bVar8 = true;
              pcVar6 = param_4;
              pcVar7 = "Evs_EventDeviceInfo";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar8 = *pcVar6 == *pcVar7;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar8);
              if (!bVar8) {
                local_2c = *param_5;
                puStack_50 = (uint *)PTR_s_lock_001f9220;
                pcStack_54 = *(char **)(param_1 + 0x170);
                piStack_58 = (int *)0x1afb1a;
                _objc_msgSend();
                local_40 = *(undefined4 **)(param_1 + 0x174);
                iVar1 = local_38;
                if ((undefined4 *)(param_1 + 0x174) != local_40) {
                  do {
                    ppuStack_60 = (undefined **)*local_40;
                    local_40 = (undefined4 *)local_40[1];
                    pcStack_54 = param_4;
                    piStack_58 = param_3;
                    puStack_5c = PTR_s_getIntValues_forParameter_count__001f9528;
                    puStack_64 = (undefined *)0x1afb5d;
                    puStack_50 = &local_2c;
                    iVar1 = _objc_msgSend();
                    if (iVar1 != -0x2c2) break;
                    iVar1 = local_38;
                  } while (local_40 != (undefined4 *)(param_1 + 0x174));
                }
                local_38 = iVar1;
                puStack_50 = (uint *)PTR_s_unlock_001f9474;
                pcStack_54 = *(char **)(param_1 + 0x170);
                piStack_58 = (int *)0x1afb8b;
                _objc_msgSend();
                if (local_38 == -0x2c2) {
                  puStack_50 = &local_2c;
                  pcStack_54 = param_4;
                  piStack_58 = param_3;
                  puStack_5c = PTR_s_getIntValues_forParameter_count__001f9528;
                  local_34 = param_1;
                  local_30 = PTR_s_IODevice_001fa400;
                  ppuStack_60 = &local_34;
                  puStack_64 = (undefined *)0x1afbc2;
                  local_38 = _objc_msgSendSuper();
                }
                goto LAB_001afbc5;
              }
              puStack_50 = (uint *)PTR_s_lock_001f9220;
              pcStack_54 = *(char **)(param_1 + 0x170);
              piStack_58 = (int *)0x1afa5a;
              _objc_msgSend();
              local_40 = *(undefined4 **)(param_1 + 0x174);
              if ((undefined4 *)(param_1 + 0x174) != local_40) {
                do {
                  if (local_3c < 4) break;
                  ppuStack_60 = (undefined **)*local_40;
                  local_40 = (undefined4 *)local_40[1];
                  local_28[0] = 0;
                  puStack_50 = local_28;
                  pcStack_54 = param_4;
                  piStack_58 = param_3 + local_2c;
                  puStack_5c = PTR_s_getIntValues_forParameter_count__001f9528;
                  puStack_64 = (undefined *)0x1afab3;
                  iVar1 = _objc_msgSend();
                  if (iVar1 == 0) {
                    local_3c = local_3c - local_28[0];
                    local_2c = local_2c + local_28[0];
                  }
                } while (local_40 != (undefined4 *)(param_1 + 0x174));
              }
              ppuVar4 = &puStack_50;
              puStack_50 = (uint *)PTR_s_unlock_001f9474;
              uVar3 = *(undefined4 *)(param_1 + 0x170);
            }
          }
        }
        goto LAB_001afae1;
      }
      if (local_3c < 2) goto LAB_001afbc5;
      local_2c = 2;
      puStack_50 = (uint *)PTR_s_lock_001f9220;
      pcStack_54 = *(char **)(param_1 + 0x110);
      piStack_58 = (int *)0x1af7df;
      _objc_msgSend();
      if (param_1[0x1d2] == '\x01') {
        if (param_1[0x1d3] == '\0') {
          uVar2 = *(int *)(param_1 + 0x1a4) - *(int *)(*(int *)(param_1 + 0x168) + 0x10);
          goto LAB_001af829;
        }
        local_14[2] = 0;
        local_14[3] = 0;
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x1a0);
LAB_001af829:
        local_14[3] = uVar2 >> 8;
        local_14[2] = uVar2 << 0x18;
      }
      local_14[0] = local_14[2];
      local_14[1] = local_14[3];
      uVar2 = 0;
      do {
        param_3[uVar2] = local_14[uVar2];
        uVar2 = uVar2 + 1;
      } while (uVar2 < 2);
      puStack_50 = (uint *)PTR_s_unlock_001f9474;
      pcStack_54 = *(char **)(param_1 + 0x110);
      ppcVar5 = &pcStack_54;
    }
  }
LAB_001afae2:
  *(undefined4 *)((int)ppcVar5 + -4) = 0x1afae7;
  _objc_msgSend();
  local_38 = 0;
LAB_001afbc5:
  *param_5 = local_2c;
  return local_38;
}

