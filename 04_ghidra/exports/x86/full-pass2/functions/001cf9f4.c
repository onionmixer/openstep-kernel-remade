/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf9f4 */

void FUN_001cf9f4(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_1[3] != 0) {
    iVar1 = _getsectdatafromheaderinfo(param_1,"__OBJC","__meth_var_names",&local_8);
    if (iVar1 == 0) {
      iVar1 = _getsectdatafromheaderinfo(param_1,"__OBJC","__selector_strs",&local_8);
    }
    __sel_init(*param_1,iVar1,local_8,param_1[3]);
  }
  return;
}

