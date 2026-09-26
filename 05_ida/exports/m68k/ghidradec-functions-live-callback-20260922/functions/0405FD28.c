
void _vm_object_deactivate_pages(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)*param_1;
  while (puVar2 = puVar1, puVar2 != param_1) {
    puVar1 = (undefined4 *)puVar2[2];
    if (-1 < *(char *)((int)puVar2 + 0x1e)) {
      _vm_page_deactivate(puVar2);
    }
  }
  return;
}

