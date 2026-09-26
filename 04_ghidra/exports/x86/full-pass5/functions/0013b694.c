/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b694 */

undefined4 FUN_0013b694(int param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x128);
  pcVar1 = (char *)(*(int *)(iVar2 + 0x30) + 0x78);
  *pcVar1 = *pcVar1 + '\x01';
  *param_2 = iVar2;
  *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 1;
  return 0;
}

