/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014cf28 */

int * _ipc_port_lookup_notify(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = _ipc_entry_lookup(param_1,param_2);
  if ((iVar2 != 0) && ((*(byte *)(iVar2 + 2) & 2) != 0)) {
    piVar1 = *(int **)(iVar2 + 4);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    piVar1[1] = piVar1[1] + 1;
    piVar1[8] = piVar1[8] + 1;
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    return piVar1;
  }
  return (int *)0x0;
}

