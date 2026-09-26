/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178c64 */

undefined4 __regparm1 _vm_object_deallocate(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  undefined4 uVar4;
  
  while( true ) {
    if (param_2 == 0) {
      return param_1;
    }
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    _vm_cache_lock = 1;
    UNLOCK();
    piVar1 = (int *)(param_2 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    sVar3 = *(short *)(param_2 + 0x18);
    *(short *)(param_2 + 0x18) = sVar3 + -1;
    if (sVar3 != 1) break;
    if ((*(byte *)(param_2 + 0x46) & 8) != 0) {
      if (0 < *(short *)(param_2 + 0x1a)) {
        iVar2 = param_2;
        if (DAT_001f6f3c != &_vm_object_cached_list) {
          DAT_001f6f3c[0x13] = param_2;
          iVar2 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar2;
        *(undefined4 **)(param_2 + 0x50) = DAT_001f6f3c;
        *(int **)(param_2 + 0x4c) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        LOCK();
        _vm_cache_lock = 0;
        UNLOCK();
        DAT_001f6f3c = (undefined4 *)param_2;
        _vm_object_deactivate_pages(param_2);
        LOCK();
        *(undefined4 *)(param_2 + 0x10) = 0;
        UNLOCK();
        uVar4 = _vm_object_cache_trim();
        return uVar4;
      }
      *(byte *)(param_2 + 0x46) = *(byte *)(param_2 + 0x46) & 0xf7;
    }
    _vm_object_remove(*(undefined4 *)(param_2 + 0x28));
    LOCK();
    _vm_cache_lock = 0;
    UNLOCK();
    iVar2 = *(int *)(param_2 + 0x20);
    param_1 = _vm_object_terminate(param_2);
    param_2 = iVar2;
  }
  LOCK();
  *(undefined4 *)(param_2 + 0x10) = 0;
  UNLOCK();
  LOCK();
  UNLOCK();
  uVar4 = _vm_cache_lock;
  _vm_cache_lock = 0;
  return uVar4;
}

