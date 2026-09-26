/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a75e0 */

void _volCheckRegister(undefined4 param_1,short param_2,short param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = _objc_msgSend(param_1,PTR_s_isPhysical_001f9c80);
  if (cVar1 == '\0') {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("volCheckRegister: %s is not a physical device\n",uVar2);
  }
  else {
    FUN_001a76a4(0,param_1,0,(int)param_2,(int)param_3);
  }
  return;
}

