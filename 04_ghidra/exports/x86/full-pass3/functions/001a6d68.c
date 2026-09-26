/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6d68 */

void FUN_001a6d68(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  undefined *local_8;
  
  uVar2 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
  iVar3 = _objc_msgSend(param_1,PTR_s_checkSafeConfig__001f9c4c,"eject");
  if (iVar3 == 0) {
    _objc_msgSend(param_1,PTR_s__freePartitions_001f9c44);
    *(undefined1 *)(param_1 + 0x1a8) = 0;
    local_c = param_1;
    local_8 = PTR_s_IOLogicalDisk_001fa158;
    _objc_msgSendSuper(&local_c,PTR_s_setFormattedInternal__001f9ca0,0);
    cVar1 = _objc_msgSend(uVar2,PTR_s_needsManualPolling_001f9c38);
    if (cVar1 != '\0') {
      _vol_check_manual_poll();
    }
    _objc_msgSend(uVar2,PTR_s_ejectPhysical_001f9c34);
  }
  return;
}

