/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c380 */

void FUN_0012c380(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x30);
  _getthetime(&local_c);
  *(int *)(iVar1 + 0xc0) = local_c;
  *(undefined4 *)(iVar1 + 0xc4) = local_8;
  uVar3 = local_c - *(int *)(iVar1 + 0xa8) >> 4;
  if (*(int *)(param_1 + 0x28) == 2) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    uVar4 = *(uint *)(iVar2 + 0x68);
    if (uVar4 <= uVar3) {
      uVar4 = *(uint *)(iVar2 + 0x6c);
LAB_0012c3e7:
      if (uVar3 <= uVar4) goto LAB_0012c3ed;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    uVar4 = *(uint *)(iVar2 + 0x60);
    if (uVar4 <= uVar3) {
      uVar4 = *(uint *)(iVar2 + 100);
      goto LAB_0012c3e7;
    }
  }
  uVar3 = uVar4;
LAB_0012c3ed:
  *(int *)(iVar1 + 0xc0) = *(int *)(iVar1 + 0xc0) + uVar3;
  return;
}

