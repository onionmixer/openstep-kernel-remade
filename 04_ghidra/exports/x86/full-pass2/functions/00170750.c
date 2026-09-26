/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170750 */

void FUN_00170750(int *param_1,uint *param_2)

{
  thread_act_t thr_act;
  uint uVar1;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0480)) {
    thr_act = _convert_port_to_thread(param_1[2]);
    uVar1 = _thread_get_special_port(thr_act,param_1[7],param_2 + 9);
    param_2[7] = uVar1;
    _thread_deallocate(thr_act);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0484;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

