/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192ee0 */

void _byte_swap_disktab_in(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_38;
  undefined4 local_34 [12];
  
  local_38 = 7;
  iVar3 = 0x10;
  iVar2 = 0x1e4;
  do {
    puVar4 = (undefined4 *)((param_1 + iVar2) - iVar3);
    puVar5 = local_34;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = local_34;
    puVar5 = (undefined4 *)(param_1 + iVar2);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar3 = iVar3 + -2;
    iVar2 = iVar2 + -0x30;
    local_38 = local_38 + -1;
  } while (-1 < local_38);
  FUN_00192e28(param_1);
  return;
}

