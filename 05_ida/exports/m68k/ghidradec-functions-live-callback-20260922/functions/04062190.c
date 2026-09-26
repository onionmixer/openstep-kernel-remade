
void _device_dealloc(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar1 = (undefined4 *)*puVar2;
  while (puVar2 != puVar1) {
    _vm_page_remove(*puVar2);
    puVar1 = (undefined4 *)*puVar2;
  }
  _kfree(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  return;
}

