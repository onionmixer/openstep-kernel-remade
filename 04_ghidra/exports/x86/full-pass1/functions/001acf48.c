/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001acf48 */

int FUN_001acf48(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x1ac) = param_1 + 0x1a8;
  *(int *)(param_1 + 0x1a8) = param_1 + 0x1a8;
  *(int *)(param_1 + 0x1b4) = param_1 + 0x1b0;
  *(int *)(param_1 + 0x1b0) = param_1 + 0x1b0;
  uVar1 = _objc_msgSend(PTR_s_NXConditionLock_001f9d64,PTR_s_alloc_001f9210);
  *(undefined4 *)(param_1 + 0x1b8) = uVar1;
  _objc_msgSend(uVar1,PTR_s_initWith__001f9214,0);
  _objc_msgSend(param_1,PTR_s_setLastReadyState__001f9c6c,1);
  uVar1 = _objc_msgSend(PTR_s_NXConditionLock_001f9d64,PTR_s_alloc_001f9210);
  *(undefined4 *)(param_1 + 0x1c0) = uVar1;
  _objc_msgSend(uVar1,PTR_s_initWith__001f9214,0);
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined1 *)(param_1 + 0x1c8) = 0;
  *(byte *)(param_1 + 0x18a) = *(byte *)(param_1 + 0x18a) & 0xfc;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  iVar2 = 0;
  do {
    uVar1 = _IOForkThread(_sdIoThread,param_1);
    *(undefined4 *)(param_1 + 400 + iVar2 * 4) = uVar1;
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return param_1;
}

