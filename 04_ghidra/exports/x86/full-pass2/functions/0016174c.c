/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016174c */

undefined4 _pset_reference(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(param_1 + 0x148);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) + 1;
  LOCK();
  uVar3 = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x148) = 0;
  UNLOCK();
  return uVar3;
}

