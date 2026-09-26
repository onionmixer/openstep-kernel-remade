/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6f9c */

int FUN_001a6f9c(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_checkSafeConfig__001f9c4c,"setFormatted");
  if (iVar1 == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
    iVar1 = (int)param_3;
    _objc_msgSend(uVar2,PTR_s_setFormattedInternal__001f9ca0,iVar1);
    if (param_3 != '\0') {
      _objc_msgSend(uVar2,PTR_s_updatePhysicalParameters_001f93e4);
    }
    _objc_msgSend(uVar2,PTR_s_setFormattedInternal__001f9ca0,iVar1);
    _objc_msgSend(param_1,PTR_s_setFormattedInternal__001f9ca0,iVar1);
    iVar1 = 0;
  }
  return iVar1;
}

