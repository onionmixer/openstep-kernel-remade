/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2940 */

int FUN_001b2940(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = _objc_getClass(param_3);
  if (iVar2 == 0) {
    uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
    _IOLog("%s: %s: no such class.\n",uVar3);
    iVar2 = 0;
  }
  else {
    cVar1 = _objc_msgSend(iVar2,PTR_s_respondsTo__001f9464,PTR_s_probe_001f9a2c);
    if (cVar1 == '\0') {
      uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
      _IOLog("%s: %s does not respond to probe.\n",uVar3);
      iVar2 = 0;
    }
    else {
      iVar2 = _objc_msgSend(iVar2,PTR_s_probe_001f9a2c);
      if (iVar2 == 0) {
        uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
        _IOLog("%s: probe of %s failed\n",uVar3);
        iVar2 = 0;
      }
      else {
        iVar4 = _objc_msgSend(param_1,PTR_s_registerEventSource__001f9974,iVar2);
        if (iVar4 == 0) {
          uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
          _IOLog("%s: becomeOwner of %s failed\n",uVar3);
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}

