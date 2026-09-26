/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c5fe4 */

undefined4 FUN_001c5fe4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964,
                        PTR_s_registerScreen_bounds_shmem_size_001f961c,param_1,&local_c,
                        param_1 + 0x1fc,&local_10);
  iVar2 = _objc_msgSend(uVar1);
  pvVar3 = (void *)_objc_msgSend(param_1,PTR_s__shmem_001f95d8);
  if (iVar2 == -1) {
    uVar1 = 0xfffffd3e;
  }
  else if (local_10 < 0x1449) {
    _bzero(pvVar3,local_10);
    *(undefined1 *)((int)pvVar3 + 8) = 1;
    *(undefined4 *)((int)pvVar3 + 0x30) = local_c;
    *(undefined4 *)((int)pvVar3 + 0x34) = local_8;
    _objc_msgSend(param_1,PTR_s_setToken__001f9614,iVar2);
    uVar1 = 0;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,local_10,0x1448);
    _IOLog("%s: shmem_size > sizeof (VGAShmem_t)(%d<>%d)\n",uVar1);
    uVar1 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964,
                          PTR_s_unregisterScreen__001f9618,iVar2);
    _objc_msgSend(uVar1);
    uVar1 = 0xfffffd3e;
  }
  return uVar1;
}

