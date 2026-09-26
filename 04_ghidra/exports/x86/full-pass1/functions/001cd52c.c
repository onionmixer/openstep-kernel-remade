/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd52c */

int _class_lookupMethodInMethodList(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 4);
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return 0;
    }
    if (*piVar2 == param_2) break;
    piVar2 = piVar2 + 3;
  }
  return piVar2[2];
}

