/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010765c */

void _leavepgrp(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _get_posix_proc((int)*(short *)(param_1 + 0x30));
  piVar1 = (int *)(*(int *)(iVar2 + 0x10) + 4);
  iVar3 = *(int *)(*(int *)(iVar2 + 0x10) + 4);
  while( true ) {
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_leavepgrp____can_t_find_p_in_pgr_001da8da);
    }
    if (*piVar1 == param_1) break;
    iVar3 = _get_posix_proc((int)*(short *)(*piVar1 + 0x30));
    piVar1 = (int *)(iVar3 + 0xc);
    iVar3 = *(int *)(iVar3 + 0xc);
  }
  *piVar1 = *(int *)(iVar2 + 0xc);
  if (*(int *)(*(int *)(iVar2 + 0x10) + 4) == 0) {
    _pgdelete(*(int *)(iVar2 + 0x10));
  }
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  return;
}

