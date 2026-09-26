
void _vm_object_destroy(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _vm_object_lookup(param_1);
  if (iVar1 != 0) {
    _vm_object_deallocate(iVar1);
  }
  return;
}

