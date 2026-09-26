/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9a44 */

void FUN_001a9a44(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < *(uint *)(param_1 + 0x10)) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    if (uVar1 == 0) {
      *(undefined4 **)(param_1 + 8) = param_3;
      *(undefined4 **)(param_1 + 4) = param_3;
    }
    else {
      **(undefined4 **)(param_1 + 8) = param_3;
      *(undefined4 **)(param_1 + 8) = param_3;
    }
    *param_3 = 0;
  }
  else {
    _nb_free(param_3);
  }
  return;
}

