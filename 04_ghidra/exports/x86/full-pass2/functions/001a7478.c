/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a7478 */

undefined4 FUN_001a7478(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = PTR_s_nextLogicalDisk_001f9c8c;
  iVar2 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58,PTR_s_nextLogicalDisk_001f9c8c);
  do {
    iVar2 = _objc_msgSend(iVar2,puVar3);
    if (iVar2 == 0) {
      return 0;
    }
    cVar1 = _objc_msgSend(iVar2,PTR_s_isBlockDeviceOpen_001f9c20);
    puVar3 = PTR_s_nextLogicalDisk_001f9c8c;
  } while (cVar1 == '\0');
  return 1;
}

