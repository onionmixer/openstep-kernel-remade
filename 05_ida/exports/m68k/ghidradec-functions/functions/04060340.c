
void _vm_object_page_remove(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    while (puVar2 = puVar1, puVar2 != param_1) {
      puVar1 = (undefined4 *)puVar2[2];
      if ((param_2 <= (uint)puVar2[6]) && ((uint)puVar2[6] < param_3)) {
        _pmap_remove_all(*(undefined4 *)((int)puVar2 + 0x22));
        _vm_page_free(puVar2);
      }
    }
  }
  return;
}
