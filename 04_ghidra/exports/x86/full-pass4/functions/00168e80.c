/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168e80 */

void _thread_stats(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  for (puVar1 = DAT_001e9748; (undefined4 **)puVar1 != &DAT_001e9748;
      puVar1 = (undefined4 *)puVar1[6]) {
    iVar2 = iVar2 + 1;
    if (puVar1[0x30] != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  _printf(s__d_total_threads__001dfc84,iVar2);
  _printf(s__d_using_rpc_reply__001dfc97,iVar3);
  return;
}

