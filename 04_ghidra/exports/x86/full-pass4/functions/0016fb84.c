/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016fb84 */

void FUN_0016fb84(int *param_1,int param_2)

{
  vm_map_t target_task;
  kern_return_t kVar1;
  
  if ((((param_1[1] == 0x30) && (-1 < *param_1)) && (param_1[6] == DAT_001e0398)) &&
     ((param_1[8] == DAT_001e039c && (param_1[10] == DAT_001e03a0)))) {
    target_task = _convert_port_to_map(param_1[2]);
    kVar1 = _vm_allocate(target_task,(vm_address_t *)(param_1 + 7),param_1[9],param_1[0xb]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _vm_map_deallocate(target_task);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e03a4;
      *(int *)(param_2 + 0x24) = param_1[7];
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

