/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e738 */

void FUN_0016e738(int *param_1,uint *param_2)

{
  thread_act_t thread;
  uint uVar1;
  processor_set_name_t local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    thread = _convert_port_to_thread(param_1[2]);
    uVar1 = _thread_get_assignment(thread,&local_8);
    param_2[7] = uVar1;
    _thread_deallocate(thread);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e014c;
      uVar1 = _convert_pset_name_to_port(local_8);
      param_2[9] = uVar1;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

