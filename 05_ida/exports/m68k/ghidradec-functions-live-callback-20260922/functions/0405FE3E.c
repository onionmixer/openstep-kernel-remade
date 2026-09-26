
void _vm_object_pmap_remove(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
      if ((param_2 <= (uint)puVar1[6]) && ((uint)puVar1[6] < param_3)) {
        _pmap_remove_all(*(undefined4 *)((int)puVar1 + 0x22));
      }
    }
  }
  return;
}

