
void _vm_page_addfree(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_active) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C2C14;
    }
    dword_40C2C14 = puVar3;
    *puVar2 = puVar1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xbf;
    _vm_page_active_count = _vm_page_active_count + -1;
  }
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
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0x7f;
    _vm_page_inactive_count = _vm_page_inactive_count + -1;
  }
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    *dword_40C2C1C = param_1;
    param_1[1] = dword_40C2C1C;
    *param_1 = &_vm_page_queue_free;
    dword_40C2C1C = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x10;
    _vm_page_free_count = _vm_page_free_count + 1;
  }
  return;
}

