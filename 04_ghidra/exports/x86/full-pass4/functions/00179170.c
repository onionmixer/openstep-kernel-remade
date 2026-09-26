/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179170 */

undefined4 _vm_object_cache_object(undefined4 *param_1,byte param_2)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar5 = 4;
  }
  else {
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    UNLOCK();
    piVar1 = param_1 + 4;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(byte *)((int)param_1 + 0x46) = *(byte *)((int)param_1 + 0x46) & 0xf7 | (param_2 & 1) << 3;
    LOCK();
    param_1[4] = 0;
    UNLOCK();
    LOCK();
    _vm_cache_lock = 0;
    UNLOCK();
    while (param_1 != (undefined4 *)0x0) {
      do {
      } while (_vm_cache_lock != 0);
      LOCK();
      _vm_cache_lock = 1;
      UNLOCK();
      piVar1 = param_1 + 4;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      sVar3 = *(short *)(param_1 + 6);
      *(short *)(param_1 + 6) = sVar3 + -1;
      if (sVar3 != 1) {
        LOCK();
        param_1[4] = 0;
        UNLOCK();
        LOCK();
        _vm_cache_lock = 0;
        UNLOCK();
        break;
      }
      if ((*(byte *)((int)param_1 + 0x46) & 8) != 0) {
        if (0 < *(short *)((int)param_1 + 0x1a)) {
          puVar4 = param_1;
          if ((undefined4 **)DAT_001f6f3c != &_vm_object_cached_list) {
            DAT_001f6f3c[0x13] = param_1;
            puVar4 = _vm_object_cached_list;
          }
          _vm_object_cached_list = puVar4;
          param_1[0x14] = DAT_001f6f3c;
          param_1[0x13] = &_vm_object_cached_list;
          _vm_object_cached = _vm_object_cached + 1;
          LOCK();
          _vm_cache_lock = 0;
          UNLOCK();
          DAT_001f6f3c = param_1;
          _vm_object_deactivate_pages(param_1);
          LOCK();
          param_1[4] = 0;
          UNLOCK();
          _vm_object_cache_trim();
          break;
        }
        *(byte *)((int)param_1 + 0x46) = *(byte *)((int)param_1 + 0x46) & 0xf7;
      }
      _vm_object_remove(param_1[10]);
      LOCK();
      _vm_cache_lock = 0;
      UNLOCK();
      puVar4 = (undefined4 *)param_1[8];
      _vm_object_terminate(param_1);
      param_1 = puVar4;
    }
    uVar5 = 0;
  }
  return uVar5;
}

