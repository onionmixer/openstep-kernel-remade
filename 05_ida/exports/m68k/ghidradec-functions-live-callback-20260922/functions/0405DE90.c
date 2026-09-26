
void __vm_map_entry_dispose(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = _vm_map_entry_zone;
  }
  _zfree(uVar1,param_2);
  return;
}

