/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9368 */

undefined4 _IOMapPhysicalIntoIOTask(uint param_1,vm_size_t param_2,uint *param_3)

{
  vm_map_t target_task;
  kern_return_t kVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *address;
  vm_size_t size;
  int flags;
  
  flags = 1;
  address = param_3;
  size = param_2;
  target_task = __io_vm_task_self();
  kVar1 = _vm_allocate(target_task,address,size,flags);
  if (kVar1 == 0) {
    uVar3 = ~_page_mask;
    uVar4 = *param_3 & uVar3;
    param_1 = param_1 & uVar3;
    for (uVar3 = _page_mask + param_2 & uVar3; uVar3 != 0; uVar3 = uVar3 - _page_size) {
      uVar2 = __io_vm_task_self(uVar4,param_1,3,1);
      uVar2 = __io_vm_task_pmap(uVar2);
      _pmap_enter(uVar2);
      uVar4 = uVar4 + _page_size;
      param_1 = param_1 + _page_size;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffd25;
  }
  return uVar2;
}

