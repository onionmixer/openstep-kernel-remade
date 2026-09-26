
byte sub_4060982(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  
  _vm_page_remove(param_1);
  bVar4 = *(byte *)((int)param_1 + 0x1e);
  if ((bVar4 & 0x10) == 0) {
    if ((bVar4 & 0x40) != 0) {
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
      if ((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) {
        dword_40C2C1C = param_1;
      }
      else {
        _vm_page_queue_free[1] = param_1;
      }
      *param_1 = _vm_page_queue_free;
      param_1[1] = &_vm_page_queue_free;
      _vm_page_queue_free = param_1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x10;
      bVar6 = 0xfffffffe < _vm_page_free_count;
      bVar5 = SCARRY4(_vm_page_free_count,1);
      _vm_page_free_count = _vm_page_free_count + 1;
      bVar4 = bVar6 << 4 | ((int)_vm_page_free_count < 0) << 3 | (_vm_page_free_count == 0) << 2 |
              bVar5 << 1 | bVar6;
    }
  }
  return bVar4;
}

