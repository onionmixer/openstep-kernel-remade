/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c4c6c */

undefined4 FUN_001c4c6c(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar2 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964,
                        PTR_s_registerScreen_bounds_shmem_size_001f961c,param_1,&local_c,
                        param_1 + 0x1fc,&local_10);
  iVar3 = _objc_msgSend(uVar2);
  pvVar1 = *(void **)(param_1 + 0x1fc);
  if (iVar3 == -1) {
    uVar2 = 0xfffffd3e;
  }
  else if (local_10 < 0x1449) {
    _memset(pvVar1,0,local_10);
    *(undefined1 *)((int)pvVar1 + 8) = 1;
    *(undefined4 *)((int)pvVar1 + 0x30) = local_c;
    *(undefined4 *)((int)pvVar1 + 0x34) = local_8;
    _objc_msgSend(param_1,PTR_s_setToken__001f9614,iVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,local_10,0x1448);
    _IOLog("%s: shmem_size > sizeof (StdFBShmem_t)(%d<>%d)\n",uVar2);
    uVar2 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964,
                          PTR_s_unregisterScreen__001f9618,iVar3);
    _objc_msgSend(uVar2);
    uVar2 = 0xfffffd3e;
  }
  return uVar2;
}

