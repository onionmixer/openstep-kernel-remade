/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf1dc */

void FUN_001cf1dc(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar5 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      if (*(int *)(iVar1 + 0xc + uVar5 * 0x10) != 0) {
        iVar2 = *(int *)(iVar1 + 0xc + uVar5 * 0x10);
        uVar4 = (uint)*(ushort *)(iVar2 + 8);
        uVar3 = *(ushort *)(iVar2 + 10) + uVar4;
        if (uVar4 < uVar3) {
          do {
            FUN_001cf128(*(undefined4 *)(*(int *)(iVar1 + 0xc + uVar5 * 0x10) + 0xc + uVar4 * 4),
                         *(undefined4 *)(iVar1 + uVar5 * 0x10));
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar3);
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  return;
}

