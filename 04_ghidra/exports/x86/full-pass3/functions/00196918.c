/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196918 */

undefined4 FUN_00196918(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x114) != 3) {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x10c) + 0x10))(*(int *)(param_1 + 0x10c),param_3);
    return uVar1;
  }
  return 0x10;
}

