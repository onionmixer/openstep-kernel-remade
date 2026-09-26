/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011de44 */

undefined4 _getvnodefp(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _getf(param_1);
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else if (*(short *)(iVar1 + 0xc) == 1) {
    *param_2 = iVar1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}

