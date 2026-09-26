/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a05a8 */

undefined4 FUN_001a05a8(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  undefined *local_8;
  
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  if (*(int *)(param_1 + 0x124) == 0) {
    uVar2 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
    *(undefined4 *)(param_1 + 0x124) = uVar2;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
  local_c = param_1;
  local_8 = PTR_s_IOEventSource_001fa068;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  uVar2 = _objc_msgSend(param_1,PTR_s_initPointer_001f9550);
  iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_getResolution_001f9554);
  *(int *)(param_1 + 0x134) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x134) = 0x48;
  }
  *(int *)(param_1 + 0x138) = (int)(0x4800 / (ulonglong)*(uint *)(param_1 + 0x134));
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_getInverted_001f9558);
  *(undefined1 *)(param_1 + 0x19c) = uVar1;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  _objc_msgSend(param_1,PTR_s_setPointerScaling_data__001f9544,5,&DAT_001d58bc);
  return uVar2;
}

