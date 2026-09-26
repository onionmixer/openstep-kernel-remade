/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a7114 */

void FUN_001a7114(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_c;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    _objc_msgSend(param_1,PTR_s__initPartition_disktab__001f9c2c,0,param_3 + 0x2c);
    iVar4 = 1;
    local_c = 0xf0;
    iVar5 = param_1;
    do {
      iVar2 = iVar5;
      if (0 < *(int *)(local_c + 4 + param_3)) {
        iVar2 = _objc_msgSend(PTR_s_IODiskPartition_001f9ddc,PTR_s_new_001f9468);
        _objc_msgSend(iVar2,PTR_s_connectToPhysicalDisk__001f9c7c,uVar1);
        _objc_msgSend(iVar2,PTR_s__initPartition_disktab__001f9c2c,iVar4,param_3 + 0x2c);
        _objc_msgSend(iVar2,PTR_s_init_001f924c);
        _objc_msgSend(iVar2,PTR_s_registerDevice_001f948c);
        _objc_msgSend(iVar5,PTR_s_setLogicalDisk__001f9c98,iVar2);
        uVar3 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58,PTR_s_setLogicalDisk__001f9c98,
                              iVar2);
        _objc_msgSend(uVar3);
      }
      local_c = local_c + 0x30;
      iVar4 = iVar4 + 1;
      iVar5 = iVar2;
    } while (iVar4 < 7);
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s:  _probeLabel on partition != 0\n",uVar1);
  }
  return;
}

