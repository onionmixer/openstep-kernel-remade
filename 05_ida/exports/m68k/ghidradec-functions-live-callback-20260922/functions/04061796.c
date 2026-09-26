
void _vm_page_activate(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(char *)((int)param_1 + 0x1e) < '\0') {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_inactive) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C23DC;
    }
    dword_40C23DC = puVar3;
    *puVar2 = puVar1;
    _vm_page_inactive_count = _vm_page_inactive_count + -1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0x7f;
  }
  if ((*(byte *)((int)param_1 + 0x1e) & 0x10) != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_free) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C2C1C;
    }
    dword_40C2C1C = puVar3;
    *puVar2 = puVar1;
    _vm_page_free_count = _vm_page_free_count + -1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xef;
  }
  if (*(sword *)(param_1 + 7) == 0) {
    if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmPageActivate);
    }
    *dword_40C2C14 = param_1;
    param_1[1] = dword_40C2C14;
    *param_1 = &_vm_page_queue_active;
    dword_40C2C14 = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x40;
    _vm_page_active_count = _vm_page_active_count + 1;
  }
  return;
}

