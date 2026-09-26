/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001385cc */

int _xdrmbuf_inline(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 <= *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - param_2;
    iVar1 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = param_2 + iVar1;
  }
  return iVar1;
}

