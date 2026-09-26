
void _vm_page_deactivate(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
    _pmap_clear_reference(*(undefined4 *)((int)param_1 + 0x22));
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_active) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C2C14;
    }
    dword_40C2C14 = puVar3;
    *puVar2 = puVar1;
    *dword_40C23DC = param_1;
    param_1[1] = dword_40C23DC;
    *param_1 = &_vm_page_queue_inactive;
    dword_40C23DC = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xbf | 0x80;
    _vm_page_active_count = _vm_page_active_count + -1;
    _vm_page_inactive_count = _vm_page_inactive_count + 1;
    if (((*(byte *)((int)param_1 + 0x1e) & 4) != 0) &&
       (iVar4 = _pmap_is_modified(*(undefined4 *)((int)param_1 + 0x22)), iVar4 != 0)) {
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xfb;
    }
    *(byte *)((int)param_1 + 0x1e) =
         *(byte *)((int)param_1 + 0x1e) & 0xdf |
         (byte)((((word)(*(byte *)((int)param_1 + 0x1e) ^ 4) & 7) >> 2) << 5);
  }
  return;
}
