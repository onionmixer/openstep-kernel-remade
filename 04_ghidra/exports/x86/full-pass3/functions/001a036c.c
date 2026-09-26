/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a036c */

int FUN_001a036c(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = _objc_msgSend(PTR_s_PCPointer_001f9dac,PTR_s_activePointerDevice_001f953c);
  *(int *)(param_1 + 0x128) = iVar2;
  if (iVar2 == 0) {
    _IOLog(s_initPointer__Can_t_find_active_p_001e49c0);
    param_1 = 0;
  }
  else {
    cVar1 = _objc_msgSend(iVar2,PTR_s_respondsTo__001f9464,PTR_s_setEventTarget__001f9540);
    if (cVar1 == '\0') {
      _IOLog(s_initPointer__PCPointer0_does_not_001e49ef);
      param_1 = 0;
    }
    else {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_setEventTarget__001f9540,param_1);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_setEventTarget__001f9540,param_1);
    }
  }
  return param_1;
}

