/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001706d0 */

void FUN_001706d0(int *param_1,int param_2)

{
  thread_act_t target_act;
  kern_return_t kVar1;
  
  if (((((uint)param_1[1] < 0x2c) || (*param_1 < 0)) || (param_1[6] != DAT_001e047c)) ||
     ((((*(byte *)((int)param_1 + 0x23) & 0x30) != 0x30 || ((char *)param_1[9] != s__62I__00200002))
      || (param_1[1] != param_1[10] * 4 + 0x2cU)))) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  else {
    target_act = _convert_port_to_thread(param_1[2]);
    kVar1 = _thread_set_state(target_act,param_1[7],(thread_state_t)(param_1 + 0xb),param_1[10]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _thread_deallocate(target_act);
  }
  return;
}

