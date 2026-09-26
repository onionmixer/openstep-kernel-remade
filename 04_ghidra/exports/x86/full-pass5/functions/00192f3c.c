/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192f3c */

void _byte_swap_disktab_out(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_34 [12];
  
  FUN_00192e28(param_1);
  iVar2 = 0;
  do {
    puVar5 = (undefined4 *)(param_1 + 0x94 + iVar2 * 0x30);
    puVar3 = puVar5;
    puVar4 = local_34;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar2 = iVar2 + 1;
    puVar3 = local_34;
    puVar5 = (undefined4 *)((int)puVar5 + iVar2 * -2);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
  } while (iVar2 < 8);
  return;
}

