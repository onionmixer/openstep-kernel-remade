/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c334 */

void _nfs_attrcache_va(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (((*(byte *)(param_1 + 4) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x10) == 0)) {
    puVar2 = param_2;
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x30) + 0x80);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(param_1 + 0x28) = *param_2;
    FUN_0012c380(param_1);
  }
  return;
}

