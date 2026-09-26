/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123478 */

bool _inet_netmatch(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _in_netof(*(undefined4 *)(param_1 + 4));
  iVar2 = _in_netof(*(undefined4 *)(param_2 + 4));
  return iVar1 == iVar2;
}

