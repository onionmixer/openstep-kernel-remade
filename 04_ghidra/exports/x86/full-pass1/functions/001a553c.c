/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a553c */

undefined * _IOFindNameForValue(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_2[1];
  while( true ) {
    if (iVar1 == 0) {
      _sprintf(&DAT_001e8688,"%d(d) (UNDEFINED)",param_1);
      return &DAT_001e8688;
    }
    if (*param_2 == param_1) break;
    iVar1 = param_2[3];
    param_2 = param_2 + 2;
  }
  return (undefined *)param_2[1];
}

