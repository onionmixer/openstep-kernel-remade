/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac3d8 */

undefined1 FUN_001ac3d8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_38;
  char local_2c;
  char local_28;
  int aiStack_24 [8];
  
  iVar5 = 0;
  iVar1 = _sd_idmap();
  uVar2 = _objc_msgSend(param_3,PTR_s_directDevice_001f9c84);
  local_38 = 0;
  local_28 = '\0';
  do {
    iVar3 = _objc_msgSend(uVar2,PTR_s_numberOfTargets_001f9410);
    if (iVar3 <= local_28) {
      if (iVar5 != 0) {
        _objc_msgSend(iVar5,PTR_s_free_001f921c);
      }
      return local_38;
    }
    iVar3 = 0;
    local_2c = '\0';
    do {
      if (iVar5 == 0) {
        iVar5 = _objc_msgSend(PTR_s_SCSIDisk_001f9d94,PTR_s_alloc_001f9210);
        _objc_msgSend(iVar5,PTR_s_setName__001f947c,"SCSIDisk");
        _objc_msgSend(iVar5,PTR_s_initResources_001f9ad4);
        _objc_msgSend(iVar5,PTR_s_setDevAndIdInfo__001f9c90,iVar1 + DAT_001e5170 * 0x24);
      }
      iVar4 = _objc_msgSend(uVar2,PTR_s_reserveTarget_lun_forOwner__001f9ad0,local_28,local_2c,iVar5
                           );
      if (iVar4 == 0) {
        iVar4 = _objc_msgSend(iVar5,PTR_s_SCSIDiskInit_targetId_lun_contro_001f9acc,DAT_001e5170,
                              local_28,local_2c,uVar2);
        if (iVar4 == 0) {
          aiStack_24[iVar3] = iVar5;
          iVar3 = iVar3 + 1;
          DAT_001e5170 = DAT_001e5170 + 1;
          iVar5 = 0;
          local_38 = 1;
        }
        else {
          _objc_msgSend(uVar2,PTR_s_releaseTarget_lun_forOwner__001f9ac8,local_28,local_2c,iVar5);
          if (iVar4 == 2) break;
        }
      }
      local_2c = local_2c + '\x01';
    } while (local_2c < '\b');
    local_2c = '\0';
    if (0 < iVar3) {
      do {
        iVar4 = aiStack_24[local_2c];
        *(byte *)(iVar4 + 0x18a) = *(byte *)(iVar4 + 0x18a) | 1;
        _objc_msgSend(iVar4,PTR_s_setDeviceKind__001f9480,"SCSIDisk");
        _objc_msgSend(iVar4,PTR_s_setIsPhysical__001f9ca8,1);
        _objc_msgSend(iVar4,PTR_s_registerDevice_001f948c);
        *(byte *)(iVar4 + 0x18a) = *(byte *)(iVar4 + 0x18a) | 2;
        local_2c = local_2c + '\x01';
      } while (local_2c < iVar3);
    }
    local_28 = local_28 + '\x01';
  } while( true );
}

