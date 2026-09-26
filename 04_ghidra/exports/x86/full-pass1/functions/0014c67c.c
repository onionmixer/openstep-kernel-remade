/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c67c */

void _ipc_port_pdrequest(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = param_1[10];
  param_1[10] = param_2;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  *param_3 = uVar1;
  return;
}

