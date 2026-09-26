/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001076d8 */

void _pgdelete(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = &_pgrphash + (param_1[3] & 0x3f);
  if ((*(int *)(param_1[2] + 8) != 0) &&
     (piVar2 = (int *)_ttynty(*(int *)(param_1[2] + 8)), (int *)piVar2[3] == param_1)) {
    piVar2[3] = 0;
    *(undefined2 *)(*piVar2 + 0x44) = 0;
  }
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pgdelete__can_t_find_pgrp_on_has_001da8fc);
    }
    piVar1 = (int *)*piVar2;
  } while ((int *)*piVar2 != param_1);
  *piVar2 = *param_1;
  iVar3 = *(int *)param_1[2];
  *(int *)param_1[2] = iVar3 + -1;
  if (iVar3 == 1) {
    if (*(int *)(param_1[2] + 8) != 0) {
      iVar3 = _ttynty(*(int *)(param_1[2] + 8));
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    _kfree(param_1[2],0x10);
  }
  _kfree(param_1,0x14);
  return;
}

