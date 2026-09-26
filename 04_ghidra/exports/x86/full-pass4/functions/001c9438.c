/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9438 */

void FUN_001c9438(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_c;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x10);
  local_c = *(int **)(param_1 + 0x14);
  _NXPrintf(param_3,"Table [%s -> %s]: \tcount: %d\tcapacity: %d\n",*(undefined4 *)(param_1 + 8),
            *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 4),local_8);
  while (local_8 = local_8 + -1, local_8 != -1) {
    if (*local_c != 0) {
      iVar1 = *local_c;
      puVar2 = (undefined4 *)local_c[1];
      _NXPrintf(param_3,"%d\t",iVar1);
      while (iVar1 = iVar1 + -1, iVar1 != -1) {
        FUN_001c93c8(param_3,*(undefined4 *)(param_1 + 8),*puVar2);
        _NXPrintf(param_3,": ");
        FUN_001c93c8(param_3,*(undefined4 *)(param_1 + 0xc),puVar2[1]);
        _NXPrintf(param_3,"\t");
        puVar2 = puVar2 + 2;
      }
      _NXPrintf(param_3,"\n");
    }
    local_c = local_c + 2;
  }
  _NXPrintf(param_3,"\n");
  _NXFlush(param_3);
  return;
}

