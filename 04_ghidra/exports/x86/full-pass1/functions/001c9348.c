/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9348 */

undefined4
FUN_001c9348(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar3 = param_3[1];
  while( true ) {
    if (iVar3 != 0) {
      param_3[1] = param_3[1] + -1;
      puVar1 = (undefined4 *)(*(int *)(iVar2 + 4 + *param_3 * 8) + param_3[1] * 8);
      uVar4 = puVar1[1];
      *param_4 = *puVar1;
      *param_5 = uVar4;
      return 1;
    }
    if (*param_3 == 0) break;
    *param_3 = *param_3 + -1;
    iVar3 = *(int *)(iVar2 + *param_3 * 8);
    param_3[1] = iVar3;
  }
  *param_4 = 0;
  *param_5 = 0;
  return 0;
}

