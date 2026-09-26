/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014db08 */

undefined4 _ipc_right_lookup_write(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  if (*(int *)(param_1 + 0xc) == 0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    uVar2 = 0x10;
  }
  else {
    iVar3 = _ipc_entry_lookup(param_1,param_2);
    if (iVar3 == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      uVar2 = 0xf;
    }
    else {
      *param_3 = iVar3;
      uVar2 = 0;
    }
  }
  return uVar2;
}

