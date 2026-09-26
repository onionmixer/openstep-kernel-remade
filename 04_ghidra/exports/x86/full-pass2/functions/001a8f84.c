/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8f84 */

int FUN_001a8f84(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  piVar3 = (int *)*puVar2;
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar1 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  puVar2[2] = param_3;
  LOCK();
  *(undefined4 *)*puVar2 = 0;
  UNLOCK();
  _thread_wakeup_prim(puVar2 + 2,1,0);
  _lock_done(puVar2[1]);
  return param_1;
}

