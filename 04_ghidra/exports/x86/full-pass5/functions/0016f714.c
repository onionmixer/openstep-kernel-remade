/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f714 */

void FUN_0016f714(int *param_1,int param_2)

{
  ipc_space_t task;
  kern_return_t kVar1;
  
  if ((param_1[1] == 0x28) && (param_1[6] == DAT_001e0314)) {
    if (((*(byte *)((int)param_1 + 0x23) & 0x30) == 0x10) &&
       (((5 < (byte)((char)param_1[8] - 0x10U) || (*param_1 < 0)) &&
        ((param_1[8] & 0xfffff00U) == 0x12000)))) {
      task = _convert_port_to_space(param_1[2]);
      kVar1 = _mach_port_insert_right(task,param_1[7],param_1[9],(uint)*(byte *)(param_1 + 8));
      *(kern_return_t *)(param_2 + 0x1c) = kVar1;
      _space_deallocate(task);
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

