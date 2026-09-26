/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001823c8 */

undefined4 _kern_IOProbeDriver(int param_1,void *param_2,size_t param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 local_10;
  void *local_c;
  char local_8;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffd3f;
  }
  else {
    pvVar2 = (void *)_IOMalloc(param_3 + 1);
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0xfffffd25;
    }
    else {
      _bcopy(param_2,pvVar2,param_3);
      *(undefined1 *)(param_3 + (int)pvVar2) = 0;
      uVar1 = _objc_msgSend(PTR_s_NXConditionLock_001f9d64,PTR_s_alloc_001f9210);
      _objc_msgSend(uVar1,PTR_s_initWith__001f9214,0);
      local_10 = uVar1;
      local_c = pvVar2;
      _IOForkThread(_configureThread,&local_10);
      _objc_msgSend(uVar1,PTR_s_lockWhen__001f9218,1);
      _objc_msgSend(uVar1,PTR_s_free_001f921c);
      _IOFree(pvVar2,param_3 + 1);
      uVar1 = 0;
      if (local_8 == '\0') {
        uVar1 = 0xfffffd40;
      }
    }
  }
  return uVar1;
}

