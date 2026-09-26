/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9918 */

void FUN_001a9918(int param_1)

{
  int iVar1;
  
  iVar1 = _if_collisions(*(undefined4 *)(param_1 + 4));
  _if_collisions_set(*(undefined4 *)(param_1 + 4),iVar1 + 1);
  return;
}

