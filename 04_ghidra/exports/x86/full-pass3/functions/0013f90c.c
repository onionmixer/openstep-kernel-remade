/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f90c */

void _disksort(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == 0) {
    *(int *)(param_1 + 0xc) = param_2;
    *(int *)(param_1 + 0x10) = param_2;
    *(undefined4 *)(param_2 + 0xc) = 0;
    return;
  }
  if (*(int *)(param_2 + 0x38) < *(int *)(iVar2 + 0x38)) {
    iVar1 = *(int *)(iVar2 + 0xc);
    while (iVar3 = iVar2, iVar1 != 0) {
      iVar3 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar3 + 0x38) < *(int *)(iVar2 + 0x38)) {
        goto LAB_0013f950;
      }
      iVar2 = iVar3;
      iVar1 = *(int *)(iVar3 + 0xc);
    }
  }
  else {
    while (iVar3 = iVar2, *(int *)(iVar2 + 0xc) != 0) {
      iVar1 = *(int *)(*(int *)(iVar2 + 0xc) + 0x38);
      if ((iVar1 < *(int *)(iVar2 + 0x38)) ||
         (iVar2 = *(int *)(iVar2 + 0xc), *(int *)(param_2 + 0x38) < iVar1)) break;
    }
  }
  goto LAB_0013f988;
  while (iVar2 = iVar1, iVar3 = iVar1, *(int *)(iVar1 + 0xc) != 0) {
LAB_0013f950:
    iVar1 = *(int *)(iVar2 + 0xc);
    iVar3 = iVar2;
    if (*(int *)(param_2 + 0x38) < *(int *)(iVar1 + 0x38)) break;
  }
LAB_0013f988:
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = param_2;
  if (*(int *)(param_1 + 0x10) == iVar3) {
    *(int *)(param_1 + 0x10) = param_2;
  }
  return;
}

