/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc9d4 */

undefined4 _NXNextMapState(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  do {
    *param_2 = *param_2 + -1;
    if (*param_2 == -1) {
      return 0;
    }
    piVar2 = (int *)(*param_2 * 8 + iVar1);
  } while (*piVar2 == -1);
  *param_3 = *piVar2;
  *param_4 = piVar2[1];
  return 1;
}

