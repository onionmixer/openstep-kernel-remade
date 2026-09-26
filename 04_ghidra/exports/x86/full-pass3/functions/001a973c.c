/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a973c */

void FUN_001a973c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _if_ipackets(*(undefined4 *)(param_1 + 4));
  _if_ipackets_set(*(undefined4 *)(param_1 + 4),iVar1 + 1);
  _if_handle_input(*(undefined4 *)(param_1 + 4),param_3,param_4);
  return;
}

