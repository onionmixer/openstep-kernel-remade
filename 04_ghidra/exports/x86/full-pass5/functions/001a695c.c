/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a695c */

uint FUN_001a695c(int param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int local_30;
  uint local_2c;
  int local_28;
  int local_18;
  uint local_14;
  int local_10;
  int local_c [2];
  
  local_18 = 0;
  uVar3 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
  uVar4 = _objc_msgSend(param_1,PTR_s_physicalBlockSize_001f9c54);
  local_28 = 0;
  local_2c = 0;
  uVar5 = _objc_msgSend(param_1,PTR_s_checkSafeConfig__001f9c4c,"writeLabel");
  if (uVar5 != 0) {
    return uVar5;
  }
  _objc_msgSend(uVar3,PTR_s_lockLogicalDisks_001f9c48);
  cVar1 = _objc_msgSend(uVar3,PTR_s_isFormatted_001f9398);
  if (cVar1 != '\0') {
    _objc_msgSend(param_1,PTR_s__freePartitions_001f9c44);
    *(undefined1 *)(param_1 + 0x1a8) = 0;
    iVar6 = *param_3;
    if ((iVar6 == 0x4e655854) || (iVar6 == 0x646c5632)) {
      local_14 = 0x1c48;
      piVar8 = param_3 + 0x716;
      local_30 = 0x1c46;
    }
    else {
      if (iVar6 != 0x646c5633) {
        uVar7 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        _IOLog("%s writeLabel: BAD LABEL\n",uVar7);
        uVar4 = 0xfffffd3e;
        goto LAB_001a6bff;
      }
      local_14 = 0x230;
      piVar8 = param_3 + 0x90;
      local_30 = 0x22e;
    }
    _IOGetTimestamp(local_c);
    param_3[10] = local_c[0];
    param_3[1] = 0;
    *(undefined2 *)piVar8 = 0;
    uVar5 = (uVar4 + 0x1c47) / uVar4;
    iVar10 = uVar4 * uVar5;
    local_2c = ~_page_mask & iVar10 + _page_mask;
    local_28 = _IOMalloc(local_2c);
    _put_disk_label(param_3,local_28);
    uVar2 = _checksum16(local_28,local_14 >> 1);
    *(ushort *)(local_28 + local_30) = uVar2 >> 8 | uVar2 << 8;
    iVar6 = _check_label(local_28,0);
    if (iVar6 != 0) {
      uVar7 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar6);
      _IOLog("%s writeLabel: BAD LABEL : %s\n",uVar7);
      uVar4 = 0xfffffd3e;
      goto LAB_001a6bff;
    }
    uVar4 = _objc_msgSend(param_1,PTR_s_NeXTpartitionOffset_001f9c50);
    if ((int)uVar4 < 0) goto LAB_001a6bff;
    iVar6 = 1;
    uVar9 = uVar4;
    do {
      uVar9 = uVar9 + uVar5;
      *(uint *)(local_28 + 4) =
           uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 * 0x1000000;
      uVar7 = _IOVmTaskSelf();
      uVar4 = _objc_msgSend(uVar3,PTR_s_writeAt_length_buffer_actualLeng_001f9cac,uVar9,iVar10,
                            local_28,&local_10,uVar7);
      if ((uVar4 == 0) && (local_10 == iVar10)) {
        local_18 = local_18 + 1;
      }
    } while ((uVar4 != 0xfffffbb2) && (iVar6 = iVar6 + 1, iVar6 < 4));
    if (local_18 != 0) {
      *(undefined1 *)(param_1 + 0x1a8) = 1;
      uVar4 = 0;
      _objc_msgSend(param_1,PTR_s__probeLabel__001f9c5c,param_3);
      goto LAB_001a6bff;
    }
    if (uVar4 == 0xfffffbb2) goto LAB_001a6bff;
  }
  uVar4 = 0xfffffd36;
LAB_001a6bff:
  _objc_msgSend(uVar3,PTR_s_unlockLogicalDisks_001f9c40);
  if (local_28 != 0) {
    _IOFree(local_28,local_2c);
  }
  return uVar4;
}

