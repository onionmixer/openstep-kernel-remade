/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010f22c */

int _nullmodem(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _ttynty(param_1);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffef;
    if (-1 < *(short *)(iVar1 + 0x10)) {
      param_2 = 0;
    }
  }
  else {
    *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) | 0x10;
  }
  return param_2;
}

