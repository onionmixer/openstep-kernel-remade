/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001012fc */

int _bcmp(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 0;
  bVar4 = true;
  do {
    pcVar2 = param_1;
    pcVar3 = param_2;
    if (param_3 == 0) break;
    param_3 = param_3 - 1;
    pcVar3 = (char *)((int)param_2 + 1);
    pcVar2 = (char *)((int)param_1 + 1);
    bVar4 = *(char *)param_1 == *(char *)param_2;
    param_1 = pcVar2;
    param_2 = pcVar3;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = (uint)(byte)pcVar2[-1] - (uint)(byte)pcVar3[-1];
  }
  return iVar1;
}

