/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a7c70 */

void FUN_001a7c70(undefined4 param_1,short param_2,short param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  
  uVar2 = _IOMalloc(0x1c5c);
  cVar1 = _objc_msgSend(param_1,PTR_s_isRemovable_001f93c8);
  bVar6 = cVar1 != '\0';
  iVar3 = _objc_msgSend(param_1,PTR_s_nextLogicalDisk_001f9c8c);
  if (iVar3 == 0) {
    _IOLog("volCheck: physDev with no logicalDisk!!\n");
    iVar3 = -0x44c;
  }
  else {
    iVar3 = _objc_msgSend(iVar3,PTR_s_readLabel__001f93bc,uVar2);
  }
  if (iVar3 == 0) {
    uVar5 = 0;
  }
  else {
    cVar1 = _objc_msgSend(param_1,PTR_s_isFormatted_001f9398);
    uVar5 = 2;
    if (cVar1 != '\0') {
      uVar5 = 1;
    }
  }
  cVar1 = _objc_msgSend(param_1,PTR_s_isWriteProtected_001f9cb0);
  if (cVar1 != '\0') {
    bVar6 = bVar6 | 2;
  }
  uVar4 = _objc_msgSend(param_1,PTR_s_name_001f9228,bVar6);
  _vol_notify_dev((int)param_2,(int)param_3,"",uVar5,uVar4);
  _IOFree(uVar2,0x1c5c);
  return;
}

