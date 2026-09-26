/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142544 */

undefined4 FUN_00142544(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_001425a4(param_1);
  if (iVar1 == 0) {
    *param_2 = 3;
  }
  else {
    *param_2 = *(undefined2 *)(iVar1 + 2);
    param_2[1] = 0;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(iVar1 + 4);
    if (*(int *)(iVar1 + 8) == -1) {
      *(undefined4 *)(param_2 + 4) = 0;
    }
    else {
      *(int *)(param_2 + 4) = (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4)) + 1;
    }
    *(undefined4 *)(param_2 + 6) = **(undefined4 **)(iVar1 + 0xc);
  }
  return 0;
}

