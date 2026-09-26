/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3ef4 */

int FUN_001a3ef4(int param_1)

{
  int iVar1;
  
  iVar1 = _objc_getClass("IODevice");
  if (param_1 != iVar1) {
    _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_registerClass__001f9ce8,param_1);
  }
  if (DAT_001e50c0 == '\0') {
    DAT_001e8674 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
    DAT_001e8668 = 0;
    DAT_001e8670 = &DAT_001e866c;
    DAT_001e866c = &DAT_001e866c;
    DAT_001e8680 = &DAT_001e867c;
    DAT_001e867c = &DAT_001e867c;
    DAT_001e8684 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
    DAT_001e50c0 = '\x01';
  }
  return param_1;
}

