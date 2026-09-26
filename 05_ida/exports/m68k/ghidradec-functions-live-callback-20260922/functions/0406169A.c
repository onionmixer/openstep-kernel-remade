
void _vm_page_unwire(undefined4 *param_1)

{
  sword sVar1;
  
  sVar1 = *(sword *)(param_1 + 7);
  *(sword *)(param_1 + 7) = sVar1 + -1;
  if (sVar1 == 1) {
    *dword_40C2C14 = param_1;
    param_1[1] = dword_40C2C14;
    *param_1 = &_vm_page_queue_active;
    dword_40C2C14 = param_1;
    _vm_page_active_count = _vm_page_active_count + 1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x40;
    _vm_page_wire_count = _vm_page_wire_count + -1;
  }
  return;
}

