/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c0f8 */

int _lookupname(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined1 local_10 [12];
  
  iVar1 = _pn_get(param_1,param_2,local_10);
  if (iVar1 == 0) {
    iVar1 = _lookuppn(local_10,param_3,param_4,param_5);
    _pn_free(local_10);
  }
  return iVar1;
}

