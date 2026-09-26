/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8d9c */

int FUN_001a8d9c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)**(undefined4 **)(param_1 + 4);
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  return param_1;
}

