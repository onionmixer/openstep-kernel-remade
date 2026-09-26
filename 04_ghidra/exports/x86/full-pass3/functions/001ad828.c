/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ad828 */

void * FUN_001ad828(undefined4 param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = (void *)_IOMalloc(0x44);
  _bzero(pvVar1,0x44);
  if (param_3 == 0) {
    uVar2 = _objc_msgSend(PTR_s_NXConditionLock_001f9d64,PTR_s_alloc_001f9210);
    *(undefined4 *)((int)pvVar1 + 0x1c) = uVar2;
    _objc_msgSend(uVar2,PTR_s_initWith__001f9214,0);
  }
  else {
    *(int *)((int)pvVar1 + 0x18) = param_3;
  }
  return pvVar1;
}

