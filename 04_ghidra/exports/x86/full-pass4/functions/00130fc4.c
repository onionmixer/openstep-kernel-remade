/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00130fc4 */

undefined4 FUN_00130fc4(int param_1,int *param_2)

{
  *param_2 = *(int *)(*(int *)(param_1 + 0x128) + 0x10);
  *(short *)(*param_2 + 6) = *(short *)(*param_2 + 6) + 1;
  return 0;
}

