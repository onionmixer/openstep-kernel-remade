/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178f7c */

undefined4 _vm_object_destroy(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = _vm_object_lookup(param_1);
  uVar5 = 0;
  while( true ) {
    if (iVar4 == 0) {
      return uVar5;
    }
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    _vm_cache_lock = 1;
    UNLOCK();
    piVar1 = (int *)(iVar4 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    sVar3 = *(short *)(iVar4 + 0x18);
    *(short *)(iVar4 + 0x18) = sVar3 + -1;
    if (sVar3 != 1) break;
    if ((*(byte *)(iVar4 + 0x46) & 8) != 0) {
      if (0 < *(short *)(iVar4 + 0x1a)) {
        iVar2 = iVar4;
        if (DAT_001f6f3c != &_vm_object_cached_list) {
          DAT_001f6f3c[0x13] = iVar4;
          iVar2 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar2;
        *(undefined4 **)(iVar4 + 0x50) = DAT_001f6f3c;
        *(int **)(iVar4 + 0x4c) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        LOCK();
        _vm_cache_lock = 0;
        UNLOCK();
        DAT_001f6f3c = (undefined4 *)iVar4;
        _vm_object_deactivate_pages(iVar4);
        LOCK();
        *(undefined4 *)(iVar4 + 0x10) = 0;
        UNLOCK();
        uVar5 = _vm_object_cache_trim();
        return uVar5;
      }
      *(byte *)(iVar4 + 0x46) = *(byte *)(iVar4 + 0x46) & 0xf7;
    }
    _vm_object_remove(*(undefined4 *)(iVar4 + 0x28));
    LOCK();
    _vm_cache_lock = 0;
    UNLOCK();
    iVar2 = *(int *)(iVar4 + 0x20);
    uVar5 = _vm_object_terminate(iVar4);
    iVar4 = iVar2;
  }
  LOCK();
  *(undefined4 *)(iVar4 + 0x10) = 0;
  UNLOCK();
  LOCK();
  UNLOCK();
  uVar5 = _vm_cache_lock;
  _vm_cache_lock = 0;
  return uVar5;
}

