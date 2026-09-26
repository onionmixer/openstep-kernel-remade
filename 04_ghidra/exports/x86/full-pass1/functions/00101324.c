/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101324 */

int _memcmp(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  int *piVar11;
  int *piVar12;
  bool bVar13;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    bVar13 = param_3 == 0xf;
    if (0xf < (int)param_3) {
      sVar4 = param_3;
      if (((uint)param_2 & 3) != 0) {
        iVar3 = 4 - ((uint)param_2 & 3);
        bVar13 = iVar3 == 0;
        iVar1 = iVar3;
        pcVar5 = param_2;
        pcVar9 = param_1;
        do {
          pcVar6 = pcVar5;
          pcVar10 = pcVar9;
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          pcVar10 = pcVar9 + 1;
          pcVar6 = pcVar5 + 1;
          bVar13 = *pcVar5 == *pcVar9;
          pcVar5 = pcVar6;
          pcVar9 = pcVar10;
        } while (bVar13);
        cVar2 = (char)iVar1;
        if (!bVar13) {
          param_3 = CONCAT22((short)(param_3 >> 0x10),CONCAT11(pcVar6[-1],(char)param_3));
          cVar2 = pcVar10[-1] - pcVar6[-1];
        }
        if (cVar2 != 0) {
          return (int)cVar2;
        }
        sVar4 = param_3 - iVar3;
        param_1 = (void *)((int)param_1 + iVar3);
        param_2 = (void *)((int)param_2 + iVar3);
      }
      iVar1 = (int)sVar4 >> 2;
      bVar13 = iVar1 == 0;
      piVar7 = param_2;
      piVar11 = param_1;
      do {
        piVar8 = piVar7;
        piVar12 = piVar11;
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        piVar12 = piVar11 + 1;
        piVar8 = piVar7 + 1;
        bVar13 = *piVar7 == *piVar11;
        piVar7 = piVar8;
        piVar11 = piVar12;
      } while (bVar13);
      if (!bVar13) {
        iVar1 = piVar12[-1] - piVar8[-1];
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      param_3 = sVar4 & 3;
      if (param_3 == 0) {
        return 0;
      }
      param_2 = (void *)((int)param_2 + (sVar4 & 0xfffffffc));
      param_1 = (void *)((int)param_1 + (sVar4 & 0xfffffffc));
      bVar13 = param_1 == (char *)0x0;
    }
    do {
      pcVar5 = param_2;
      pcVar9 = param_1;
      if (param_3 == 0) break;
      param_3 = param_3 - 1;
      pcVar9 = (char *)((int)param_1 + 1);
      pcVar5 = (char *)((int)param_2 + 1);
      bVar13 = *(char *)param_2 == *(char *)param_1;
      param_2 = pcVar5;
      param_1 = pcVar9;
    } while (bVar13);
    cVar2 = (char)param_3;
    if (!bVar13) {
      cVar2 = pcVar9[-1] - pcVar5[-1];
    }
    iVar1 = (int)cVar2;
  }
  return iVar1;
}

