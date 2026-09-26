/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d7d8 */

void _stat1(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_48;
  undefined1 local_44 [64];
  
  iVar1 = _lookupname(*param_1,0,param_2,0,&local_48);
  if (iVar1 == 0) {
    iVar1 = _vno_stat(local_48,local_44);
    _vn_rele(local_48);
    if (iVar1 == 0) {
      _copyout(local_44,param_1[1],0x40);
    }
  }
  return;
}

