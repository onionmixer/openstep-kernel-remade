/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017408c */

void _kmem_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  uVar1 = _pmap_kernel(0,param_2,0);
  _kernel_map = _vm_map_create(uVar1);
  local_8 = 0;
  _vm_map_find(_kernel_map,0,0,&local_8,param_1,0);
  return;
}

