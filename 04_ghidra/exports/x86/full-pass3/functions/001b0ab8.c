/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0ab8 */

bool FUN_001b0ab8(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_001e532c == 0) {
    iVar1 = _objc_msgSend(param_1,PTR_s_alloc_001f9210);
    DAT_001e532c = iVar1;
    *(undefined4 *)(iVar1 + 0x10c) = 0;
    _objc_msgSend(iVar1,PTR_s_setUnit__001f9478,0);
    _objc_msgSend(DAT_001e532c,PTR_s_setName__001f947c,"event0");
    _objc_msgSend(DAT_001e532c,PTR_s_setDeviceKind__001f9480,"event");
    iVar1 = _objc_msgSend(DAT_001e532c,PTR_s_init_001f924c);
    return iVar1 != 0;
  }
  return true;
}

