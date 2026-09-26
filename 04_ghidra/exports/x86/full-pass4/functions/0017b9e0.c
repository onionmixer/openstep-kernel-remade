/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b9e0 */

undefined4 _vm_synchronize(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 5;
  }
  if (param_3 == 0) {
    param_3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
  }
  if (param_2 == 0) {
    param_2 = *(int *)(param_1 + 0x14);
  }
  uVar1 = FUN_0017ba1c(param_1,param_2,param_3 + param_2);
  return uVar1;
}

