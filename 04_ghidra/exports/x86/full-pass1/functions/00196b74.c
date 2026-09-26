/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196b74 */

undefined4 FUN_00196b74(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10c);
  if (iVar1 != 0) {
    (**(code **)(iVar1 + 0x18))(iVar1,param_3);
    return 0;
  }
  return 0x16;
}

