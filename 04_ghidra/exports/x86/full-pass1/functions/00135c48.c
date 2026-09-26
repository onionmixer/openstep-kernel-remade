/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135c48 */

void _clntkudp_freeres(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + 0x34) = 2;
  (*param_2)(iVar1 + 0x34,param_3);
  return;
}

