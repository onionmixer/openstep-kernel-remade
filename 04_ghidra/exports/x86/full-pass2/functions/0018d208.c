/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d208 */

void _stack_attach(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  *(int *)(param_1 + 0x2c) = param_2;
  iVar1 = **(int **)(param_1 + 0x28);
  *(int *)(iVar1 + 0x3c) = param_2 + 0xff4;
  *(int *)(iVar1 + 0x38) = param_2 + 0xff4;
  *(code **)(iVar1 + 0x20) = __stack_attach;
  *(undefined4 *)(iVar1 + 0x34) = param_3;
  return;
}

