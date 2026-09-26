/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163f84 */

undefined4 _run_queue_enqueue(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2[0x16];
  if (0x1f < uVar4) {
    _printf(s_run_queue_enqueue__pri_too_high___001df684,uVar4);
    uVar4 = 0x1f;
  }
  piVar1 = (int *)(param_1 + 0x100);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  iVar2 = param_1 + uVar4 * 8;
  *param_2 = iVar2;
  param_2[1] = *(int *)(iVar2 + 4);
  *(int **)param_2[1] = param_2;
  *(int **)(iVar2 + 4) = param_2;
  if ((*(uint *)(param_1 + 0x104) < uVar4) || (*(int *)(param_1 + 0x108) == 0)) {
    *(uint *)(param_1 + 0x104) = uVar4;
  }
  *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
  param_2[2] = param_1;
  LOCK();
  uVar3 = *(undefined4 *)(param_1 + 0x100);
  *(undefined4 *)(param_1 + 0x100) = 0;
  UNLOCK();
  return uVar3;
}

