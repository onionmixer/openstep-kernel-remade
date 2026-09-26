/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a74d8 */

undefined4 FUN_001a74d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x1a4) == 0) {
    cVar1 = _objc_msgSend(param_1,PTR_s_isAnyBlockDevOpen_001f9c1c);
    if (cVar1 == '\0') {
      cVar1 = _objc_msgSend(param_1,PTR_s_isAnyOtherOpen_001f9c18);
      if (cVar1 == '\0') {
        uVar2 = 0;
      }
      else {
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
        _IOLog("%s: %s with other partitions open\n",uVar2);
        uVar2 = 0xfffffd2b;
      }
    }
    else {
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
      _IOLog("%s: %s with open block devices\n",uVar2);
      uVar2 = 0xfffffd2b;
    }
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
    _IOLog("%s: %s on partition != 0\n",uVar2);
    uVar2 = 0xfffffd2b;
  }
  return uVar2;
}

