/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d6c0 */

undefined4 _ipc_pset_add(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(int *)(param_2 + 0x30) = param_1;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  piVar1 = (int *)(param_2 + 0x40);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  piVar1 = (int *)(param_1 + 0x10);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  _ipc_mqueue_move(param_1 + 0x10,param_2 + 0x40,param_2);
  LOCK();
  *(undefined4 *)(param_1 + 0x10) = 0;
  UNLOCK();
  _ipc_mqueue_changed(param_2 + 0x40,0x10004006);
  LOCK();
  uVar3 = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_2 + 0x40) = 0;
  UNLOCK();
  return uVar3;
}

