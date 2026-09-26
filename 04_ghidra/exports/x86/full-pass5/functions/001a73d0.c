/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a73d0 */

undefined4 FUN_001a73d0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _objc_msgSend(param_1,PTR_s_nextLogicalDisk_001f9c8c);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      cVar1 = _objc_msgSend(iVar2,PTR_s_isOpen_001f9c88);
      if (cVar1 == '\0') {
        _objc_msgSend(iVar2,PTR_s_free_001f921c);
        _objc_msgSend(param_1,PTR_s_setLogicalDisk__001f9c98,0);
        uVar3 = 0;
      }
      else {
        uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        _IOLog("%s: _freePartitions with open partitions\n",uVar3);
        uVar3 = 0xfffffd2b;
      }
    }
  }
  else {
    uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: _freePartitions on partition != 0\n",uVar3);
    uVar3 = 0xfffffd2b;
  }
  return uVar3;
}

