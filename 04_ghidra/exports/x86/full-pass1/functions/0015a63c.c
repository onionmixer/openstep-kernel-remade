/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a63c */

void _send_notification(task_t param_1,int param_2,undefined4 param_3)

{
  kern_return_t kVar1;
  mach_port_t local_8;
  
  if (param_2 == 0x42) {
    kVar1 = _task_get_special_port(param_1,2,&local_8);
    if (kVar1 == 0) {
      _ipc_notify_msg_accepted_compat(local_8,param_3);
    }
  }
  return;
}

