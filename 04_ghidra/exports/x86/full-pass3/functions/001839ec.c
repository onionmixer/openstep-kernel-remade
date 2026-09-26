/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001839ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _sdioctl(ushort param_1,int param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  byte local_b8;
  undefined4 local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_98 [8];
  uint local_90;
  uint local_8c;
  int local_88 [6];
  int aiStack_70 [4];
  uint local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 local_57;
  int local_56;
  int local_52;
  int local_4e;
  undefined1 local_4a;
  uint local_48;
  int local_44;
  byte local_40;
  byte local_3d;
  int local_3c;
  char local_38;
  int local_34;
  undefined4 local_20 [7];
  
  uVar6 = (param_1 & 0xf8) >> 3;
  local_a8 = 0;
  local_ac = 0;
  iVar5 = *param_3;
  if (0x10 < uVar6) {
    return 6;
  }
  if (_DAT_001e7568 != (short)(param_1 >> 8)) {
    return 6;
  }
  iVar7 = uVar6 * 0x24;
  if (param_2 == 0x20006415) {
LAB_00183ac0:
    uVar6 = param_1 & 7;
    if (uVar6 == 7) {
      uVar6 = 0;
    }
    local_a4 = *(int *)(&DAT_001e7328 + uVar6 * 4 + iVar7);
  }
  else {
    if (param_2 < 0x20006416) {
      if (param_2 != -0x3fab8cff) {
        if (param_2 < -0x3fab8cfe) {
          if (param_2 != -0x7ffb9be9) {
            return 0x16;
          }
        }
        else {
          if (0x20006401 < param_2) {
            return 0x16;
          }
          if (param_2 < 0x20006400) {
            return 0x16;
          }
        }
        goto LAB_00183ac0;
      }
    }
    else if (param_2 < 0x4004641a) {
      if (param_2 < 0x40046418) {
        if (param_2 != 0x40046417) {
          return 0x16;
        }
        goto LAB_00183ac0;
      }
    }
    else if ((param_2 != 0x40087305) && (param_2 != 0x40306405)) {
      return 0x16;
    }
    local_a4 = *(int *)(&DAT_001e7324 + iVar7);
  }
  if (local_a4 == 0) {
    return 6;
  }
  if (param_2 == 0x20006415) {
    cVar1 = _objc_msgSend(local_a4,PTR_s_isRemovable_001f93c8);
    if (cVar1 != '\0') {
      local_ac = _objc_msgSend(local_a4,PTR_s_eject_001f93cc);
    }
  }
  else if (param_2 < 0x20006416) {
    if (param_2 == -0x3fab8cff) {
      if (param_3[5] == 0) {
        uVar6 = 0;
        local_b0 = 0;
LAB_00183e20:
        _bzero(&local_58,0x54);
        local_58 = _objc_msgSend(local_a4,PTR_s_target_001f93d4);
        local_57 = _objc_msgSend(local_a4,PTR_s_lun_001f93d8);
        local_56 = *param_3;
        local_52 = param_3[1];
        local_4e = param_3[2];
        local_4a = param_3[3] == 0;
        local_44 = param_3[6];
        local_b8 = ~*(byte *)((int)param_3 + 0x49);
        local_40 = *(byte *)((int)param_3 + 0x49) & 4 |
                   local_40 & 0xf8 | local_b8 & 1 | *(byte *)((int)param_3 + 0x49) & 2;
        local_3d = (char)param_3[0x12] << 4 | local_3d & 0xf;
        puVar4 = PTR_s_sdCdbRead_buffer_client__001f93e0;
        if (param_3[3] == 1) {
          puVar4 = PTR_s_sdCdbWrite_buffer_client__001f93dc;
        }
        local_48 = uVar6;
        local_ac = _objc_msgSend(local_a4,puVar4,&local_58,local_b0,_kernel_map);
        param_3[7] = local_3c;
        if ((local_3c == 0xd) && (local_38 == '\x02')) {
          param_3[7] = 3;
        }
        *(char *)(param_3 + 8) = local_38;
        param_3[0xf] = local_34;
        if (param_3[5] < local_34) {
          param_3[0xf] = param_3[5];
        }
        param_3[0x11] = 0;
        param_3[0x10] = 0;
        if ((param_3[3] == 0) && (local_34 != 0)) {
          local_a8 = _copyout(local_b0,param_3[4],param_3[0xf]);
        }
        if (param_3[7] == 2) {
          puVar9 = local_20;
          pcVar3 = (char *)((int)param_3 + 0x21);
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined4 *)pcVar3 = *puVar9;
            puVar9 = puVar9 + 1;
            pcVar3 = pcVar3 + 4;
          }
          *(undefined2 *)pcVar3 = *(undefined2 *)puVar9;
        }
      }
      else {
        uVar2 = _objc_msgSend(*(int *)(&DAT_001e7324 + iVar7),PTR_s_controller_001f939c);
        _objc_msgSend(uVar2,PTR_s_getDMAAlignment__001f93a0,local_98);
        if (param_3[3] == 1) {
          local_90 = local_8c;
        }
        if (local_90 < 2) {
          uVar6 = param_3[5];
        }
        else {
          uVar6 = (param_3[5] + local_90) - 1 & -local_90;
        }
        local_b0 = _objc_msgSend(uVar2,PTR_s_allocateBufferOfLength_actualSta_001f93a4,uVar6,
                                 &local_9c,&local_a0);
        if ((param_3[3] != 1) || (local_a8 = _copyin(param_3[4],local_b0,param_3[5]), local_a8 == 0)
           ) goto LAB_00183e20;
        param_3[7] = 9;
      }
      if (param_3[5] == 0) goto LAB_00184058;
    }
    else {
      if (param_2 < -0x3fab8cfe) {
        if (param_2 != -0x7ffb9be9) {
          return 0x16;
        }
        local_ac = _objc_msgSend(local_a4,PTR_s_setFormatted__001f93b8,(int)(char)*param_3);
        goto LAB_00184058;
      }
      if (param_2 == 0x20006400) {
        uVar2 = _IOMalloc(0x1c5c);
        local_ac = _objc_msgSend(local_a4,PTR_s_readLabel__001f93bc,uVar2);
        if (local_ac == 0) {
          local_a8 = _copyout(uVar2,iVar5,0x1c5c);
        }
        local_a0 = 0x1c5c;
        local_9c = uVar2;
      }
      else {
        if (param_2 != 0x20006401) {
          return 0x16;
        }
        uVar2 = _IOMalloc(0x1c5c);
        local_a8 = _copyin(iVar5,uVar2,0x1c5c);
        if (local_a8 == 0) {
          local_ac = _objc_msgSend(local_a4,PTR_s_writeLabel__001f93c0,uVar2);
        }
        local_a0 = 0x1c5c;
        local_9c = uVar2;
      }
    }
    _IOFree(local_9c,local_a0);
  }
  else {
    puVar4 = PTR_s_diskSize_001f93d0;
    if (param_2 == 0x40046419) {
LAB_00183d31:
      iVar5 = _objc_msgSend(local_a4,puVar4);
    }
    else {
      if (0x40046419 < param_2) {
        if (param_2 == 0x40087305) {
          local_ac = _objc_msgSend(local_a4,PTR_s_updatePhysicalParameters_001f93e4);
          if (local_ac != 0) goto LAB_00184061;
          uVar2 = _objc_msgSend(local_a4,PTR_s_blockSize_001f93a8);
          iVar5 = _objc_msgSend(local_a4,PTR_s_diskSize_001f93d0);
          iVar5 = iVar5 + -1;
          local_b8 = (byte)((uint)uVar2 >> 0x18);
          *(byte *)(param_3 + 1) = local_b8;
          *(char *)((int)param_3 + 5) = (char)((uint)uVar2 >> 0x10);
          *(char *)((int)param_3 + 6) = (char)((uint)uVar2 >> 8);
          *(char *)((int)param_3 + 7) = (char)uVar2;
          local_b8 = (byte)((uint)iVar5 >> 0x18);
          *(byte *)param_3 = local_b8;
          *(char *)((int)param_3 + 1) = (char)((uint)iVar5 >> 0x10);
          *(char *)((int)param_3 + 2) = (char)((uint)iVar5 >> 8);
          *(char *)((int)param_3 + 3) = (char)iVar5;
        }
        else {
          if (param_2 != 0x40306405) {
            return 0x16;
          }
          _bzero(local_88,0x30);
          pcVar3 = (char *)_objc_msgSend(local_a4,PTR_s_driveName_001f93c4);
          _strcpy((char *)local_88,pcVar3);
          local_60 = _objc_msgSend(local_a4,PTR_s_blockSize_001f93a8);
          local_5c = DAT_001e756c;
          if (local_60 != 0) {
            uVar6 = (local_60 + 0x1c5b) / local_60;
            iVar7 = 3;
            iVar5 = uVar6 * 3;
            do {
              aiStack_70[iVar7] = iVar5;
              iVar5 = iVar5 - uVar6;
              iVar7 = iVar7 + -1;
            } while (-1 < iVar7);
          }
          piVar8 = local_88;
          for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
            *param_3 = *piVar8;
            piVar8 = piVar8 + 1;
            param_3 = param_3 + 1;
          }
        }
        goto LAB_00184058;
      }
      if (param_2 != 0x40046417) {
        puVar4 = PTR_s_blockSize_001f93a8;
        if (param_2 != 0x40046418) {
          return 0x16;
        }
        goto LAB_00183d31;
      }
      cVar1 = _objc_msgSend(local_a4,PTR_s_isFormatted_001f9398);
      iVar5 = (int)cVar1;
    }
    *param_3 = iVar5;
  }
LAB_00184058:
  if (local_ac == 0) {
    return local_a8;
  }
LAB_00184061:
  iVar5 = _objc_msgSend(local_a4,PTR_s_errnoFromReturn__001f93b4,local_ac);
  return iVar5;
}

