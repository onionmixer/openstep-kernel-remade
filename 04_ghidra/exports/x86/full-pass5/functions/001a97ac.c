/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a97ac */

void FUN_001a97ac(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = _if_ipackets(*(undefined4 *)(param_1 + 4));
  _if_ipackets_set(*(undefined4 *)(param_1 + 4),param_3 + iVar1);
  return;
}

