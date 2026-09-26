/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b8cc */

void _vm_page_activate(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(byte *)((int)param_1 + 0x1e) & 1) != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if ((undefined4 **)puVar1 != &_vm_page_queue_inactive) {
      puVar1[1] = puVar2;
      puVar3 = DAT_001f64e4;
    }
    DAT_001f64e4 = puVar3;
    if ((undefined4 **)puVar2 != &_vm_page_queue_inactive) {
      *puVar2 = puVar1;
      puVar1 = _vm_page_queue_inactive;
    }
    _vm_page_queue_inactive = puVar1;
    _vm_page_inactive_count = _vm_page_inactive_count + -1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xfe;
  }
  if ((*(byte *)((int)param_1 + 0x1e) & 8) != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if ((undefined4 **)puVar1 != &_vm_page_queue_free) {
      puVar1[1] = puVar2;
      puVar3 = DAT_001f6e4c;
    }
    DAT_001f6e4c = puVar3;
    if ((undefined4 **)puVar2 != &_vm_page_queue_free) {
      *puVar2 = puVar1;
      puVar1 = _vm_page_queue_free;
    }
    _vm_page_queue_free = puVar1;
    _vm_page_free_count = _vm_page_free_count + -1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xf7;
  }
  if (*(short *)(param_1 + 7) == 0) {
    if ((*(byte *)((int)param_1 + 0x1e) & 2) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_page_activate__already_active_001e0d93);
    }
    if ((undefined4 **)DAT_001f6e44 == &_vm_page_queue_active) {
      _vm_page_queue_active = param_1;
    }
    else {
      *DAT_001f6e44 = param_1;
    }
    param_1[1] = DAT_001f6e44;
    *param_1 = &_vm_page_queue_active;
    DAT_001f6e44 = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 2;
    _vm_page_active_count = _vm_page_active_count + 1;
  }
  return;
}

