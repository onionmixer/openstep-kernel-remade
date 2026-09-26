/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016fdfc */

void FUN_0016fdfc(int *param_1,int param_2)

{
  vm_map_t target_task;
  kern_return_t kVar1;
  
  if ((((param_1[1] == 0x30) && (*param_1 < 0)) && (param_1[6] == DAT_001e03e0)) &&
     (((*(byte *)((int)param_1 + 0x23) & 0x30) == 0x20 && (param_1[9] == 0x80009)))) {
    target_task = _convert_port_to_map(param_1[2]);
    kVar1 = _vm_write(target_task,param_1[7],param_1[0xb],param_1[10]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _vm_map_deallocate(target_task);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

