/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c9a0 */

int _pn_get(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _kalloc(0x400);
  *param_3 = uVar1;
  param_3[1] = uVar1;
  param_3[2] = 0;
  if (param_2 == 0) {
    iVar2 = _copyinstr(param_1,param_3[1],0x400,param_3 + 2);
  }
  else {
    iVar2 = _copystr(param_1,param_3[1],0x400,param_3 + 2);
  }
  if (((iVar2 == 0) && (param_3[2] == 0x400)) && (*(char *)(param_3[1] + 0x3ff) != '\0')) {
    iVar2 = 0x3f;
  }
  param_3[2] = param_3[2] + -1;
  if (iVar2 != 0) {
    _pn_free(param_3);
  }
  return iVar2;
}

