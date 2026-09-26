
void _kmem_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  
  uVar1 = _pmap_kernel(0x10000000,param_2,0);
  _kernel_map = _vm_map_create(uVar1);
  uStack_8 = 0x10000000;
  _vm_map_find(_kernel_map,0,0,&uStack_8,param_1 + -0x10000000,0);
  return;
}

