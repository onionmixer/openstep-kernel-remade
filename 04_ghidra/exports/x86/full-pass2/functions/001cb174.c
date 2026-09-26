/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb174 */

void FUN_001cb174(int *param_1,int param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)param_1[3];
  iVar3 = param_1[2];
  while (iVar3 = iVar3 + -1, iVar3 != -1) {
    if (*piVar2 != 0) {
      if (param_2 == 0) {
        pcVar1 = _NXNoEffectFree;
      }
      else {
        pcVar1 = *(code **)(*param_1 + 8);
      }
      FUN_001cb124(pcVar1,*piVar2,piVar2[1],param_1[4]);
      *piVar2 = 0;
      piVar2[1] = 0;
    }
    piVar2 = piVar2 + 2;
  }
  return;
}

