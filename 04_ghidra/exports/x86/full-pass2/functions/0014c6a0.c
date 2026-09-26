/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c6a0 */

undefined4 _ipc_port_nsrequest(undefined4 *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[9];
  if (((param_1[7] == 0) && (param_2 <= (uint)param_1[6])) && (param_3 != 0)) {
    param_1[9] = 0;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    uVar2 = _ipc_notify_no_senders(param_3,param_1[6]);
  }
  else {
    param_1[9] = param_3;
    LOCK();
    uVar2 = *param_1;
    *param_1 = 0;
    UNLOCK();
  }
  *param_4 = uVar1;
  return uVar2;
}

