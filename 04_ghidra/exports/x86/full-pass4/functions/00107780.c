/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107780 */

void _fixjobc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_2 + 8);
  iVar3 = _get_posix_proc((int)*(short *)(*(int *)(param_1 + 0x44) + 0x30));
  if ((*(int *)(iVar3 + 0x10) != param_2) && (*(int *)(*(int *)(iVar3 + 0x10) + 8) == iVar1)) {
    if (param_3 == 0) {
      iVar3 = *(int *)(param_2 + 0x10);
      *(int *)(param_2 + 0x10) = iVar3 + -1;
      if (iVar3 == 1) {
        FUN_0010782c(param_2);
      }
    }
    else {
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    }
  }
  for (iVar3 = *(int *)(param_1 + 0x48); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x4c)) {
    iVar4 = _get_posix_proc((int)*(short *)(iVar3 + 0x30));
    iVar4 = *(int *)(iVar4 + 0x10);
    if (((iVar4 != param_2) && (*(int *)(iVar4 + 8) == iVar1)) &&
       (*(char *)(iVar3 + 0x13) != '\x05')) {
      if (param_3 == 0) {
        iVar2 = *(int *)(iVar4 + 0x10);
        *(int *)(iVar4 + 0x10) = iVar2 + -1;
        if (iVar2 == 1) {
          FUN_0010782c(iVar4);
        }
      }
      else {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      }
    }
  }
  return;
}

