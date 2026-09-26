/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f818 */

int FUN_0019f818(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_001e488c == 0) {
    DAT_001e488c = _objc_msgSend(param_1,PTR_s_alloc_001f9210);
    uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
    iVar2 = DAT_001e488c;
    *(undefined4 *)(DAT_001e488c + 0x124) = uVar1;
    _objc_msgSend(iVar2,PTR_s_setName__001f947c,s_EventSrcPCKeyboard0_001e48ea);
    _objc_msgSend(DAT_001e488c,PTR_s_setDeviceKind__001f9480,s_EventSrcPCKeyboard_001e48fe);
    iVar2 = _objc_msgSend(DAT_001e488c,PTR_s_init_001f924c);
    if (iVar2 == 0) {
      _objc_msgSend(DAT_001e488c,PTR_s_free_001f921c);
    }
  }
  return DAT_001e488c;
}

