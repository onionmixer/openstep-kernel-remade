/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016fc70 */

void FUN_0016fc70(int *param_1,int param_2)

{
  vm_map_t target_task;
  kern_return_t kVar1;
  
  if ((((param_1[1] == 0x38) && (-1 < *param_1)) && (param_1[6] == DAT_001e03b0)) &&
     (((param_1[8] == DAT_001e03b4 && (param_1[10] == DAT_001e03b8)) &&
      (param_1[0xc] == DAT_001e03bc)))) {
    target_task = _convert_port_to_map(param_1[2]);
    kVar1 = _vm_protect(target_task,param_1[7],param_1[9],param_1[0xb],param_1[0xd]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _vm_map_deallocate(target_task);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

