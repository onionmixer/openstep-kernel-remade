/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a338 */

uint _vm_policy_apply(int param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar5 = 0;
  if (((2 < *(short *)(param_1 + 0x18)) &&
      (piVar1 = *(int **)(param_1 + 0x28), piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
    uVar5 = ~(uint)*(byte *)(piVar1 + 3) & 1;
  }
  if (((param_3 & 2) != 0) || (uVar5 == 0)) {
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    if (param_3 == 0) {
      if (((*(byte *)((int)param_2 + 0x1e) & 0x20) == 0) ||
         (iVar6 = _pmap_is_modified(param_2[9]), iVar6 != 0)) {
        if ((*(byte *)((int)param_2 + 0x1e) & 2) != 0) {
          _vm_page_deactivate(param_2);
        }
      }
      else {
        _vm_page_remove(param_2);
        if ((*(byte *)((int)param_2 + 0x1e) & 8) == 0) {
          if ((*(byte *)((int)param_2 + 0x1e) & 2) != 0) {
            puVar2 = (undefined4 *)*param_2;
            puVar3 = (undefined4 *)param_2[1];
            puVar4 = puVar3;
            if ((undefined4 **)puVar2 != &_vm_page_queue_active) {
              puVar2[1] = puVar3;
              puVar4 = DAT_001f6e44;
            }
            DAT_001f6e44 = puVar4;
            if ((undefined4 **)puVar3 != &_vm_page_queue_active) {
              *puVar3 = puVar2;
              puVar2 = _vm_page_queue_active;
            }
            _vm_page_queue_active = puVar2;
            *(byte *)((int)param_2 + 0x1e) = *(byte *)((int)param_2 + 0x1e) & 0xfd;
            _vm_page_active_count = _vm_page_active_count + -1;
          }
          if ((*(byte *)((int)param_2 + 0x1e) & 1) != 0) {
            puVar2 = (undefined4 *)*param_2;
            puVar3 = (undefined4 *)param_2[1];
            puVar4 = puVar3;
            if ((undefined4 **)puVar2 != &_vm_page_queue_inactive) {
              puVar2[1] = puVar3;
              puVar4 = DAT_001f64e4;
            }
            DAT_001f64e4 = puVar4;
            if ((undefined4 **)puVar3 != &_vm_page_queue_inactive) {
              *puVar3 = puVar2;
              puVar2 = _vm_page_queue_inactive;
            }
            _vm_page_queue_inactive = puVar2;
            *(byte *)((int)param_2 + 0x1e) = *(byte *)((int)param_2 + 0x1e) & 0xfe;
            _vm_page_inactive_count = _vm_page_inactive_count + -1;
          }
          if ((*(byte *)(param_2 + 8) & 8) == 0) {
            uVar7 = _splimp();
            do {
            } while (_vm_page_queue_free_lock != 0);
            LOCK();
            UNLOCK();
            if ((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) {
              DAT_001f6e4c = param_2;
            }
            else {
              _vm_page_queue_free[1] = param_2;
            }
            *param_2 = _vm_page_queue_free;
            param_2[1] = &_vm_page_queue_free;
            _vm_page_queue_free = param_2;
            *(byte *)((int)param_2 + 0x1e) = *(byte *)((int)param_2 + 0x1e) | 8;
            _vm_page_free_count = _vm_page_free_count + 1;
            LOCK();
            _vm_page_queue_free_lock = 0;
            UNLOCK();
            _splx(uVar7);
          }
        }
      }
      _pmap_remove_all(param_2[9]);
    }
    else if ((param_3 == 1) && ((*(byte *)((int)param_2 + 0x1e) & 2) != 0)) {
      _vm_page_deactivate(param_2);
    }
    uVar5 = _vm_page_queue_lock;
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
  }
  return uVar5;
}

