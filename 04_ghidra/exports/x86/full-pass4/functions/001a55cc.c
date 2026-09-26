/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a55cc */

int _IOSizeToAlignment(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    if (param_1 < 0) {
      return 0x20 - iVar1;
    }
    param_1 = param_1 * 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return 0;
}

