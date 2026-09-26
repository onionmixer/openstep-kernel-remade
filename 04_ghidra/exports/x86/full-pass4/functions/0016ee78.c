/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ee78 */

void FUN_0016ee78(int *param_1,int param_2)

{
  thread_act_t thread;
  kern_return_t kVar1;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    thread = _convert_port_to_thread(param_1[2]);
    kVar1 = _thread_depress_abort(thread);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _thread_deallocate(thread);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

