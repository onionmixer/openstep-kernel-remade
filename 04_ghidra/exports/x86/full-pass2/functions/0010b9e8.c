/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b9e8 */

uint _thread_psignal(int param_1,uint param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_2 < 0x21) {
    uVar5 = 1 << ((char)param_2 - 1U & 0x1f);
    if ((uVar5 & 0x1ef8) == 0) {
      _printf(s_signal____d_001dabca);
                    /* WARNING: Subroutine does not return */
      _panic(s_thread_psignal__signal_is_not_an_001dabd7);
    }
    param_2 = *(uint *)(param_1 + 0xc);
    iVar4 = *(int *)(param_2 + 0x3c);
    if (((*(uint *)(iVar4 + 0x20) & uVar5) == 0) || ((*(byte *)(iVar4 + 0x28) & 0x10) != 0)) {
      piVar1 = (int *)(iVar4 + 0x70);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      puVar2 = (uint *)(*(int *)(param_1 + 0x84) + 0x7c);
      *puVar2 = *puVar2 | uVar5;
      LOCK();
      param_2 = *(uint *)(iVar4 + 0x70);
      *(uint *)(iVar4 + 0x70) = 0;
      UNLOCK();
    }
  }
  return param_2;
}

