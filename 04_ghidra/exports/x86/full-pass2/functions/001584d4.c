/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001584d4 */

undefined4 _mach_msg_abort_rpc(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar1 = (int *)(param_1 + 0xa8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(int *)(param_1 + 0xac) != 0) {
    iVar4 = *(int *)(param_1 + 0xc0);
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  LOCK();
  uVar3 = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xa8) = 0;
  UNLOCK();
  if (iVar4 != 0) {
    uVar3 = _ipc_port_dealloc_special(iVar4,_ipc_space_reply);
  }
  return uVar3;
}

