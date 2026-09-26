/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a06dc */

int FUN_001a06dc(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_001e49bc == 0) {
    DAT_001e49bc = _objc_msgSend(param_1,PTR_s_alloc_001f9210);
    _objc_msgSend(DAT_001e49bc,PTR_s_setName__001f947c,s_EventSrcPCPointer0_001e4a2c);
    _objc_msgSend(DAT_001e49bc,PTR_s_setDeviceKind__001f9480,s_EventSrcPCPointer_001e4a3f);
    iVar1 = _objc_msgSend(DAT_001e49bc,PTR_s_init_001f924c);
    if (iVar1 == 0) {
      _objc_msgSend(DAT_001e49bc,PTR_s_free_001f921c);
    }
  }
  return DAT_001e49bc;
}

