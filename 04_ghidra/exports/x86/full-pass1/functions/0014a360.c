/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a360 */

int _ipc_marequest_cancel(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  piVar1 = (int *)(_ipc_marequest_table +
                  ((param_1 >> 4) + (param_2 >> 8) + (param_2 & 0xff) & _ipc_marequest_mask) * 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  puVar4 = (uint *)(piVar1 + 1);
  for (puVar3 = (uint *)piVar1[1];
      (puVar3 != (uint *)0x0 && ((*puVar3 != param_1 || (puVar3[1] != param_2))));
      puVar3 = (uint *)puVar3[3]) {
    puVar4 = puVar3 + 3;
  }
  *puVar4 = puVar3[3];
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = 0;
  UNLOCK();
  puVar3[1] = 0;
  return iVar2;
}

