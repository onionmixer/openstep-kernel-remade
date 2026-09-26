/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a557c */

undefined4 _IOFindValueForName(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_2[1] != 0) {
    piVar2 = param_2 + 1;
    do {
      iVar1 = _strcmp((char *)*piVar2,param_1);
      if (iVar1 == 0) {
        *param_3 = *param_2;
        return 0;
      }
      piVar2 = piVar2 + 2;
      param_2 = param_2 + 2;
    } while (*piVar2 != 0);
  }
  return 0xfffffd3e;
}

