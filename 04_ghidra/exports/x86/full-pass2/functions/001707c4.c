/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001707c4 */

void FUN_001707c4(int *param_1,int param_2)

{
  thread_act_t thr_act;
  kern_return_t kVar1;
  
  if ((((param_1[1] == 0x28) && (*param_1 < 0)) && (param_1[6] == DAT_001e0488)) &&
     ((param_1[8] & 0x3fffffffU) == 0x10012011)) {
    thr_act = _convert_port_to_thread(param_1[2]);
    kVar1 = _thread_set_special_port(thr_act,param_1[7],param_1[9]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _thread_deallocate(thr_act);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

