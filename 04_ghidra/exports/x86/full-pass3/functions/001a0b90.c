/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0b90 */

bool FUN_001a0b90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = _objc_msgSend(param_1,PTR_s_alloc_001f9210,PTR_s_initFromDeviceDescription__001f9560,
                        param_3);
  iVar4 = _objc_msgSend(uVar3);
  *(undefined4 *)(iVar4 + 0x128) = 0;
  cVar2 = _objc_msgSend(iVar4,PTR_s_mouseInit__001f9564,param_3);
  iVar1 = DAT_001e8660;
  if (cVar2 != '\0') {
    DAT_001e8660 = DAT_001e8660 + 1;
    _objc_msgSend(iVar4,PTR_s_setUnit__001f9478,iVar1);
    _objc_msgSend(iVar4,PTR_s_registerDevice_001f948c);
    DAT_001e8664 = iVar4;
  }
  else {
    _IOLog(s_PCPointer_probe__mouseInit_failu_001e4b2a);
    _objc_msgSend(iVar4,PTR_s_free_001f921c);
  }
  return cVar2 != '\0';
}

