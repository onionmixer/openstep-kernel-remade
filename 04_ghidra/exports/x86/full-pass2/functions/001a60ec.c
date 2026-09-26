/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a60ec */

int FUN_001a60ec(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = _objc_msgSend(param_1,PTR_s_isInstanceOpen_001f9394);
  if (cVar1 == '\0') {
    iVar2 = _objc_msgSend(param_1,PTR_s_nextLogicalDisk_001f9c8c);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      uVar3 = _objc_msgSend(param_1,PTR_s_nextLogicalDisk_001f9c8c,PTR_s_isOpen_001f9c88);
      cVar1 = _objc_msgSend(uVar3);
      iVar2 = (int)cVar1;
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

