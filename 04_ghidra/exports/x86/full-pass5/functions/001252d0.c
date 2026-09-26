/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001252d0 */

void _in_setsockaddr(int param_1,int param_2)

{
  undefined2 *puVar1;
  
  *(undefined2 *)(param_2 + 8) = 0x10;
  puVar1 = (undefined2 *)(param_2 + *(int *)(param_2 + 4));
  _bzero(puVar1,0x10);
  *puVar1 = 2;
  puVar1[1] = *(undefined2 *)(param_1 + 0x18);
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 0x14);
  return;
}

