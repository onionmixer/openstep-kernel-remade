
undefined4 _vm_object_allocate(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_vm_object_zone);
  __vm_object_allocate(param_1,uVar1);
  return uVar1;
}
