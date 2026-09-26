/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d290 */

int _select(int param_1,fd_set *param_2,fd_set *param_3,fd_set *param_4,timeval *param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined1 local_c [8];
  
  iVar3 = DAT_001e875c;
  piVar2 = *(int **)(DAT_001e875c + 0x24);
  puVar1 = (undefined4 *)(DAT_001e875c + 0x88);
  puVar5 = &DAT_001d10dc;
  puVar7 = puVar1;
  for (iVar4 = 0x34; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  if (0x100 < *piVar2) {
    *piVar2 = 0x100;
  }
  uVar6 = *piVar2 + 0x1fU >> 5;
  if (piVar2[1] != 0) {
    iVar4 = _copyin(piVar2[1],puVar1,uVar6 * 4);
    *(int *)(iVar3 + 0x154) = iVar4;
    if (iVar4 != 0) goto LAB_0010d3df;
  }
  if (piVar2[2] != 0) {
    iVar4 = _copyin(piVar2[2],iVar3 + 0xa8,uVar6 * 4);
    *(int *)(iVar3 + 0x154) = iVar4;
    if (iVar4 != 0) goto LAB_0010d3df;
  }
  if (piVar2[3] != 0) {
    iVar4 = _copyin(piVar2[3],iVar3 + 200,uVar6 * 4);
    *(int *)(iVar3 + 0x154) = iVar4;
    if (iVar4 != 0) goto LAB_0010d3df;
  }
  if (piVar2[4] != 0) {
    iVar4 = _copyin(piVar2[4],iVar3 + 0x148,8);
    *(int *)(iVar3 + 0x154) = iVar4;
    if (iVar4 == 0) {
      iVar4 = _itimerfix(iVar3 + 0x148);
      if (iVar4 == 0) {
        if ((*(int *)(iVar3 + 0x148) == 0) && (*(int *)(iVar3 + 0x14c) == 0)) {
          *(undefined4 *)(iVar3 + 0x150) = 1;
        }
        else {
          _getthetime(local_c);
          _timevaladd(iVar3 + 0x148,local_c);
        }
      }
      else {
        *(undefined4 *)(iVar3 + 0x154) = 0x16;
      }
    }
  }
LAB_0010d3df:
  iVar3 = _selcont();
  return iVar3;
}

