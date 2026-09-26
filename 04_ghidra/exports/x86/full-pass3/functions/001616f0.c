/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001616f0 */

undefined4 __regparm1 _pset_deallocate(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != 0) {
    piVar1 = (int *)(param_2 + 0x148);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(param_2 + 0x144);
    *(int *)(param_2 + 0x144) = iVar2 + -1;
    if (iVar2 == 1 || iVar2 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pset_deallocate__default_pset_de_001df24a);
    }
    LOCK();
    param_1 = *(undefined4 *)(param_2 + 0x148);
    *(undefined4 *)(param_2 + 0x148) = 0;
    UNLOCK();
  }
  return param_1;
}

