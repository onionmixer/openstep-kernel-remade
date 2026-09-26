/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a93e8 */

undefined4 _IOUnmapPhysicalFromIOTask(vm_address_t param_1,vm_size_t param_2)

{
  vm_map_t target_task;
  
  target_task = __io_vm_task_self();
  _vm_deallocate(target_task,param_1,param_2);
  return 0;
}

