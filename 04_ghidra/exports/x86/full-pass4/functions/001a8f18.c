/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8f18 */

int FUN_001a8f18(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  _lock_write(puVar1[1]);
  iVar2 = puVar1[2];
  while (iVar2 != param_3) {
    piVar3 = (int *)*puVar1;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar2 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    _lock_done(puVar1[1]);
    _thread_sleep(puVar1 + 2,*puVar1,0);
    _lock_write(puVar1[1]);
    iVar2 = puVar1[2];
  }
  return param_1;
}

