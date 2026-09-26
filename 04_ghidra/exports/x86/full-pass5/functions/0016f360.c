/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f360 */

void FUN_0016f360(int *param_1,int param_2)

{
  ipc_space_t task;
  kern_return_t kVar1;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e02bc)) &&
     (param_1[8] == DAT_001e02c0)) {
    task = _convert_port_to_space(param_1[2]);
    kVar1 = _mach_port_get_refs(task,param_1[7],param_1[9],(mach_port_urefs_t *)(param_2 + 0x24));
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _space_deallocate(task);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e02c4;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

