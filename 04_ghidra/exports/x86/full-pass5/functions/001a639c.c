/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a639c */

undefined4 FUN_001a639c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  uint local_38;
  int local_34;
  int local_2c;
  char local_24 [32];
  
  uVar4 = _objc_msgSend(param_3,PTR_s_directDevice_001f9c84);
  local_2c = 0;
  uVar5 = _objc_msgSend(uVar4,PTR_s_name_001f9228);
  local_34 = 0;
  local_38 = 0;
  bVar1 = false;
  bVar2 = false;
  cVar3 = _objc_msgSend(uVar4,PTR_s_isPhysical_001f9c80);
  if (cVar3 == '\0') {
    return 0;
  }
  iVar6 = _objc_msgSend(uVar4,PTR_s_nextLogicalDisk_001f9c8c);
  if (iVar6 == 0) {
    iVar6 = _objc_msgSend(PTR_s_IODiskPartition_001f9ddc,PTR_s_new_001f9468);
    _sprintf(local_24,"%sa",uVar5);
    _objc_msgSend(iVar6,PTR_s_setName__001f947c,local_24);
    _objc_msgSend(iVar6,PTR_s_setDeviceKind__001f9480,"IODiskPartition");
    _objc_msgSend(iVar6,PTR_s_setDriveName__001f9c78,"IODiskPartition Partition");
    _objc_msgSend(iVar6,PTR_s_setLocation__001f9484,0);
    _objc_msgSend(iVar6,PTR_s_init_001f924c);
    _objc_msgSend(iVar6,PTR_s_registerDevice_001f948c);
    _objc_msgSend(iVar6,PTR_s_connectToPhysicalDisk__001f9c7c,uVar4);
    _objc_msgSend(uVar4,PTR_s_setLogicalDisk__001f9c98,iVar6);
    *(undefined1 *)(iVar6 + 0x1a8) = 0;
    *(undefined1 *)(iVar6 + 0x1a9) = 0;
    *(undefined1 *)(iVar6 + 0x1aa) = 0;
    _objc_msgSend(uVar4,PTR_s_registerUnixDisk__001f9c74,0);
    _objc_msgSend(iVar6,PTR_s_registerUnixDisk__001f9c74,0);
  }
  else {
    _objc_msgSend(iVar6,PTR_s_connectToPhysicalDisk__001f9c7c,uVar4);
    *(undefined1 *)(iVar6 + 0x1a8) = 0;
    *(undefined1 *)(iVar6 + 0x1a9) = 0;
    *(undefined1 *)(iVar6 + 0x1aa) = 0;
  }
  iVar7 = _objc_msgSend(uVar4,PTR_s_lastReadyState_001f9c70);
  iVar10 = 0;
  do {
    iVar8 = _objc_msgSend(uVar4,PTR_s_updateReadyState_001f9cbc);
    if (iVar8 != 1) {
      if (iVar8 == 0) break;
      if (iVar8 == 2) {
        if (0 < iVar10) {
          _IOLog("\n");
        }
        goto LAB_001a66f8;
      }
    }
    if (iVar10 == 0) {
      _IOLog("%s: Waiting for drive to come ready",uVar5);
    }
    else {
      _IOLog(".");
    }
    _IOSleep(1000);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0xf);
  if (0 < iVar10) {
    _IOLog("\n");
  }
  _objc_msgSend(uVar4,PTR_s_setLastReadyState__001f9c6c,iVar8);
  if (iVar8 == 0) {
    if (iVar7 != 0) {
      _objc_msgSend(uVar4,PTR_s_updatePhysicalParameters_001f93e4);
    }
    cVar3 = _objc_msgSend(uVar4,PTR_s_isFormatted_001f9398);
    if (cVar3 != '\0') {
      local_34 = _objc_msgSend(uVar4,PTR_s_blockSize_001f93a8);
      _objc_msgSend(iVar6,PTR_s_setPhysicalBlockSize__001f9c68,local_34);
      local_38 = _objc_msgSend(uVar4,PTR_s_diskSize_001f93d0);
      bVar1 = true;
      local_2c = _IOMalloc(0x1c5c);
      iVar7 = _objc_msgSend(iVar6,PTR_s_readLabel__001f93bc,local_2c);
      if (iVar7 == 0) {
        bVar2 = true;
        _objc_msgSend(iVar6,PTR_s__probeLabel__001f9c5c,local_2c);
      }
      else {
        _IOLog("%s: No Valid Disk Label\n",uVar5);
        _objc_msgSend(iVar6,PTR_s_setBlockSize__001f9c64,local_34);
        uVar4 = _objc_msgSend(uVar4,PTR_s_diskSize_001f93d0);
        _objc_msgSend(iVar6,PTR_s_setDiskSize__001f9c60,uVar4);
      }
      goto LAB_001a66f8;
    }
    pcVar11 = "%s: Disk Unformatted\n";
  }
  else {
    pcVar11 = "%s: Disk Not Ready\n";
  }
  _IOLog(pcVar11,uVar5);
LAB_001a66f8:
  if (bVar1) {
    _IOLog("%s: Device Block Size: %u bytes\n",uVar5,local_34);
    uVar9 = (local_38 >> 10) * local_34;
    if (uVar9 < 0x2801) {
      uVar9 = local_38 * local_34;
      pcVar11 = "%s: Device Capacity:   %u KB\n";
    }
    else {
      pcVar11 = "%s: Device Capacity:   %u MB\n";
    }
    _IOLog(pcVar11,uVar5,uVar9 >> 10);
  }
  if (bVar2) {
    _IOLog("%s: Disk Label:        %s\n",uVar5,local_2c + 0xc);
  }
  if (local_2c != 0) {
    _IOFree(local_2c,0x1c5c);
  }
  return 1;
}

