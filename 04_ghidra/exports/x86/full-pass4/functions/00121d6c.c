/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121d6c */

int _rtioctl(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 + 0x7fcf8df6U < 2) {
    iVar1 = _suser();
    if (iVar1 == 0) {
      iVar1 = (int)*(char *)(DAT_001e875c + 0x68);
    }
    else {
      iVar1 = _rtrequest(param_1,param_2);
    }
  }
  else {
    iVar1 = 0x16;
  }
  return iVar1;
}

