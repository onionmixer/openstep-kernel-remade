/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8d18 */

int FUN_001c8d18(int param_1,undefined4 param_2,code *param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x10);
  while (iVar1 = iVar1 + -1, iVar1 != -1) {
    if (*piVar4 != 0) {
      puVar3 = (undefined4 *)piVar4[1];
      iVar2 = *piVar4;
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        (*param_3)(*puVar3);
        (*param_4)(puVar3[1]);
        puVar3 = puVar3 + 2;
      }
      _free((void *)piVar4[1]);
      *piVar4 = 0;
      piVar4[1] = 0;
    }
    piVar4 = piVar4 + 2;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}

