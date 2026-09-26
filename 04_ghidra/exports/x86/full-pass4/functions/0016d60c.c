/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d60c */

undefined4 _get_kern_port(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    *param_3 = 0;
    return 0;
  }
  iVar1 = _object_copyin(param_1,param_2,6,0,param_3);
  if (iVar1 != 0) {
    return 0;
  }
  return 4;
}

