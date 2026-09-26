/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bc56c */

int FUN_001bc56c(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  undefined4 uVar11;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = -1;
  local_38 = 0;
  local_3c = 0;
  uVar6 = *(undefined4 *)(param_1 + 0x1c);
  local_44 = 0;
  local_48 = 0;
  local_4c = 0;
  local_50 = 0;
  bVar3 = false;
  uVar4 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_streamForUserPort__001f96f0,
                        *(undefined4 *)(param_1 + 0xc));
  if (*(int *)(param_1 + 0x14) == 1) {
    __NXAudioStreamInfo(uVar4,&local_8,&local_c);
    _audio_snd_reply_ret_samples(param_2,*(undefined4 *)(param_1 + 0x10),local_8,local_c);
    local_30 = 0;
  }
  else {
    iVar8 = *(int *)(param_1 + 4) + -0x28;
    local_10 = param_1 + 0x28;
LAB_001bc634:
    iVar9 = local_10;
    if (0 < iVar8) {
      switch(*(undefined4 *)(local_10 + 4)) {
      case 0:
        local_10 = local_10 + 0x28;
        iVar8 = iVar8 + -0x28;
        if ((local_30 == 0) && (local_34 == 1)) {
          local_30 = 0x67;
        }
        local_34 = 0;
        goto LAB_001bc634;
      case 1:
        iVar9 = (*(ushort *)(local_10 + 0x1e) & 0xfff) + 0x20;
        local_10 = local_10 + iVar9;
        iVar8 = iVar8 - iVar9;
        goto LAB_001bc634;
      case 2:
        iVar8 = iVar8 + -0x18;
        local_38 = *(undefined4 *)(local_10 + 0xc);
        local_3c = *(undefined4 *)(local_10 + 0x10);
        local_10 = local_10 + 0x18;
        uVar5 = _objc_msgSend(uVar4,PTR_s_channel_001f97b0,&local_14,&local_18);
        __NXAudioGetBufferOptions(uVar5);
        uVar5 = *(undefined4 *)(iVar9 + 0x14);
        uVar11 = local_18;
        break;
      case 3:
        iVar8 = iVar8 + -0x10;
        local_28 = local_28 | *(uint *)(local_10 + 0xc);
        local_10 = local_10 + 0x10;
        goto LAB_001bc634;
      case 4:
        local_10 = local_10 + 0x10;
        iVar8 = iVar8 + -0x10;
        uVar5 = _objc_msgSend(uVar4,PTR_s_channel_001f97b0,&local_14,&local_18);
        __NXAudioGetBufferOptions(uVar5);
        uVar5 = local_14;
        uVar11 = *(undefined4 *)(iVar9 + 0xc);
        break;
      case 5:
        goto switchD_001bc64b_caseD_5;
      default:
        local_30 = 0x66;
        goto LAB_001bc79d;
      }
      uVar5 = _objc_msgSend(uVar4,PTR_s_channel_001f97b0,0,uVar5,uVar11);
      __NXAudioSetBufferOptions(uVar5);
      goto LAB_001bc634;
    }
LAB_001bc79d:
    if (local_30 == 0) {
      if ((local_28 & 2) != 0) {
        __NXAudioStreamControl(uVar4,2,0,0);
      }
      if ((local_28 & 1) != 0) {
        __NXAudioStreamControl(uVar4,3,0,0);
      }
      if ((local_28 & 4) != 0) {
        __NXAudioStreamControl(uVar4,0,0,0);
      }
      iVar8 = *(int *)(param_1 + 4) + -0x28;
      local_10 = param_1 + 0x28;
      while (0 < iVar8) {
        iVar9 = 0;
        switch(*(undefined4 *)(local_10 + 4)) {
        case 0:
          iVar8 = iVar8 + -0x28;
          local_2c = *(uint *)(local_10 + 0xc);
          local_24 = *(undefined4 *)(local_10 + 0x24);
          iVar9 = *(int *)(local_10 + 0x20);
          local_44 = *(undefined4 *)(local_10 + 0x14);
          local_10 = local_10 + 0x28;
          break;
        case 1:
          iVar8 = iVar8 + -0x20;
          local_2c = *(uint *)(local_10 + 0xc);
          iVar9 = *(int *)(local_10 + 0x10);
          local_44 = *(undefined4 *)(local_10 + 0x18);
          local_10 = local_10 + 0x20;
          break;
        case 2:
        case 5:
          iVar8 = iVar8 + -0x18;
          local_10 = local_10 + 0x18;
          break;
        case 3:
        case 4:
          iVar8 = iVar8 + -0x10;
          local_10 = local_10 + 0x10;
        }
        if (iVar9 != 0) {
          bVar10 = (local_2c & 1) != 0;
          if ((local_34 == 0) && ((local_2c & 2) != 0)) {
            bVar10 = bVar10 | 2;
          }
          if ((local_2c & 8) != 0) {
            bVar10 = bVar10 | 4;
          }
          if ((local_2c & 0x10) != 0) {
            bVar10 = bVar10 | 8;
          }
          if ((local_2c & 4) != 0) {
            bVar10 = bVar10 | 0x10;
          }
          if ((local_2c & 0x20) != 0) {
            bVar10 = bVar10 | 0x20;
          }
          if (local_34 == 0) {
            if (bVar3) {
              FUN_001bc4e8(0,uVar4,local_48,local_4c,local_50,local_3c,local_38);
              __NXAudioPlayStreamData(uVar4,local_24,iVar9,uVar6,local_44,bVar10);
            }
            else {
              iVar7 = _objc_msgSend(uVar4,PTR_s_type_001f9764);
              local_48 = 2;
              if (iVar7 == 3) {
                local_48 = 1;
              }
              __NXAudioPlayStream(uVar4,local_24,iVar9,uVar6,2,local_48,0x8000,0x8000,local_3c,
                                  local_38,local_44,bVar10);
            }
          }
          else if (bVar3) {
            FUN_001bc4e8(local_34,uVar4,local_48,local_4c,local_50,local_3c,local_38);
            __NXAudioRecordStreamData(uVar4,iVar9,uVar6,local_44,bVar10);
          }
          else {
            __NXAudioRecordStream(uVar4,iVar9,uVar6,local_3c,local_38,local_44,bVar10);
          }
        }
      }
      if ((local_28 & 8) != 0) {
        __NXAudioStreamControl(uVar4,1,0,0);
      }
      local_30 = 100;
    }
    else {
      iVar8 = *(int *)(param_1 + 4) + -0x28;
      local_10 = param_1 + 0x28;
      while (0 < iVar8) {
        switch(*(undefined4 *)(local_10 + 4)) {
        case 0:
          iVar8 = iVar8 + -0x28;
          puVar1 = (undefined4 *)(local_10 + 0x20);
          puVar2 = (undefined4 *)(local_10 + 0x24);
          local_10 = local_10 + 0x28;
          uVar6 = _IOVmTaskSelf(*puVar2,*puVar1);
          _vm_deallocate_EXTERNAL(uVar6);
          break;
        case 1:
          local_10 = local_10 + 0x20;
          iVar8 = iVar8 + -0x20;
          break;
        case 2:
        case 5:
          local_10 = local_10 + 0x18;
          iVar8 = iVar8 + -0x18;
          break;
        case 3:
        case 4:
          local_10 = local_10 + 0x10;
          iVar8 = iVar8 + -0x10;
        }
      }
    }
  }
  return local_30;
switchD_001bc64b_caseD_5:
  iVar8 = iVar8 + -0x18;
  local_48 = *(undefined4 *)(local_10 + 0xc);
  local_4c = *(undefined4 *)(local_10 + 0x10);
  local_50 = *(undefined4 *)(local_10 + 0x14);
  bVar3 = true;
  local_10 = local_10 + 0x18;
  goto LAB_001bc634;
}

