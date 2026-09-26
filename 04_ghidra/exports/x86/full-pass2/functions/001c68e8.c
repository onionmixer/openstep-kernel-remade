/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c68e8 */

bool FUN_001c68e8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_alloc_001f9210,PTR_s_initFromDeviceDescription__001f9560,
                        param_3);
  iVar2 = _objc_msgSend(uVar1);
  if (iVar2 != 0) {
    _objc_msgSend(iVar2,PTR_s_setDeviceKind__001f9480,"frame buffer");
    _objc_msgSend(iVar2,PTR_s_registerDevice_001f948c);
  }
  return iVar2 != 0;
}

