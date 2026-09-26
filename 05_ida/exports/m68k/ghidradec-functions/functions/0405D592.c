
void _kmem_alloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = _vm_object_allocate(param_3);
  sub_405D448(param_1,param_2,param_3,1,uVar1,1);
  return;
}
