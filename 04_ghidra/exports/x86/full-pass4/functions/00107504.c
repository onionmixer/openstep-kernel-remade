/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107504 */

void _enterpgrp(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  for (puVar5 = (undefined4 *)(&_pgrphash)[param_2 & 0x3f]; puVar5 != (undefined4 *)0x0;
      puVar5 = (undefined4 *)*puVar5) {
    if (puVar5[3] == param_2) goto LAB_00107530;
  }
  puVar5 = (undefined4 *)0x0;
LAB_00107530:
  iVar1 = _get_posix_proc((int)*(short *)(param_1 + 0x30));
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)_kalloc(0x14);
    if (param_3 == 0) {
      puVar5[2] = *(undefined4 *)(*(int *)(iVar1 + 0x10) + 8);
      *(int *)puVar5[2] = *(int *)puVar5[2] + 1;
    }
    else {
      puVar2 = (undefined4 *)_kalloc(0x10);
      puVar2[1] = param_1;
      *puVar2 = 1;
      puVar2[2] = 0;
      *(undefined2 *)(puVar2 + 3) = 0;
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xbfffffff;
      puVar5[2] = puVar2;
    }
    puVar5[3] = param_2;
    *puVar5 = (&_pgrphash)[param_2 & 0x3f];
    (&_pgrphash)[param_2 & 0x3f] = puVar5;
    puVar5[4] = 0;
    puVar5[1] = 0;
  }
  else if (puVar5[3] == *(int *)(*(int *)(iVar1 + 0x10) + 0xc)) {
    return;
  }
  if ((*(byte *)(param_1 + 0x16) & 2) != 0) {
    _fixjobc(param_1,puVar5,1);
    _fixjobc(param_1,*(undefined4 *)(iVar1 + 0x10),0);
  }
  piVar3 = (int *)(*(int *)(iVar1 + 0x10) + 4);
  while( true ) {
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_enterpgrp__can_t_find_p_on_old_p_001da8b6);
    }
    if (*piVar3 == param_1) break;
    iVar4 = _get_posix_proc((int)*(short *)(*piVar3 + 0x30));
    piVar3 = (int *)(iVar4 + 0xc);
  }
  *piVar3 = *(int *)(iVar1 + 0xc);
  if (*(int *)(*(int *)(iVar1 + 0x10) + 4) == 0) {
    _pgdelete(*(int *)(iVar1 + 0x10));
  }
  *(undefined4 **)(iVar1 + 0x10) = puVar5;
  *(undefined4 *)(iVar1 + 0xc) = puVar5[1];
  puVar5[1] = param_1;
  *(undefined2 *)(param_1 + 0x2e) = *(undefined2 *)(*(int *)(iVar1 + 0x10) + 0xc);
  return;
}

