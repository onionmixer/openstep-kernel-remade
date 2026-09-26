/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c4bc */

int _nextseg(int param_1)

{
  int iVar1;
  
  iVar1 = _nextsegfromheader(0x100000,param_1);
  if ((iVar1 == 0) && (param_1 != _fvm_seg)) {
    iVar1 = _fvm_seg;
  }
  return iVar1;
}

