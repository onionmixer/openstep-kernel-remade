
undefined4 _vm_object_cache_object(int param_1,byte param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x42) = *(uint *)(param_1 + 0x42) & 0xefffffff | (param_2 & 1) << 0x1c;
    _vm_object_deallocate(param_1);
    uVar1 = 0;
  }
  return uVar1;
}
