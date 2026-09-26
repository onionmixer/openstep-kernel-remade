
byte sub_405497E(void)

{
  int ****ppppiVar1;
  int ****ppppiVar2;
  int *****pppppiVar3;
  int iVar4;
  int *****pppppiVar5;
  int ****ppppiVar6;
  int ****ppppiVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  undefined8 uVar11;
  int ****appppiStack_c [2];
  
  uVar11 = _clock_value(1);
  ppppiVar6 = (int ****)((qword)uVar11 >> 0x20);
  ppppiVar7 = (int ****)uVar11;
  appppiStack_c[0] = (int ****)appppiStack_c;
  appppiStack_c[1] = appppiStack_c[0];
  if ((int ******)dword_40B4DC8 != &dword_40B4DC8) {
    do {
      pppppiVar3 = dword_40B4DC8;
      ppppiVar1 = dword_40B4DC8[5];
      ppppiVar2 = dword_40B4DC8[6];
      if ((ppppiVar6 <= ppppiVar1 && (ppppiVar2 >= ppppiVar7 || ppppiVar1 != ppppiVar6)) &&
          (ppppiVar1 != (int ****)((uint)(ppppiVar2 < ppppiVar7) + (int)ppppiVar6) ||
          ppppiVar2 != ppppiVar7)) break;
      (*dword_40B4DC8)[1] = (int ***)dword_40B4DC8[1];
      *pppppiVar3[1] = (int ***)*pppppiVar3;
      pppppiVar3[7] = (int ****)0x0;
      *pppppiVar3 = (int ****)appppiStack_c;
      pppppiVar3[1] = appppiStack_c[1];
      *pppppiVar3[1] = (int ***)pppppiVar3;
      appppiStack_c[1] = (int ****)pppppiVar3;
    } while ((int ******)dword_40B4DC8 != &dword_40B4DC8);
    if ((int ******)dword_40B4DC8 != &dword_40B4DC8) {
      sub_4053F9C(dword_40B4DC8);
    }
  }
  pppppiVar3 = appppiStack_c;
  while( true ) {
    ppppiVar6 = appppiStack_c[0];
    bVar9 = SBORROW4((int)pppppiVar3,(int)appppiStack_c[0]);
    iVar4 = (int)pppppiVar3 - (int)appppiStack_c[0];
    bVar10 = pppppiVar3 < appppiStack_c[0];
    if (pppppiVar3 == (int *****)appppiStack_c[0]) break;
    (*appppiStack_c[0])[1] = (int **)pppppiVar3;
    bVar9 = false;
    bVar10 = false;
    iVar4 = 0;
    if ((int *****)appppiStack_c[0] == (int *****)0x0) break;
    pppppiVar5 = (int *****)*appppiStack_c[0];
    *appppiStack_c[0] = (int ***)&dword_40B4DC0;
    appppiStack_c[0] = (int ****)pppppiVar5;
    ppppiVar6[1] = (int ***)dword_40B4DC4;
    *ppppiVar6[1] = (int **)ppppiVar6;
    iVar4 = dword_40B4DD8;
    dword_40B4DC4 = (int *****)ppppiVar6;
    ppppiVar6[7] = (int ***)0x1;
    iVar8 = dword_40B4DD4 + dword_40B4DD0 + 1;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    _thread_wakeup_prim(&dword_40B4DD0,1,0);
    if (iVar4 < iVar8) {
      _thread_wakeup_prim(&dword_40B4DD8,1,0);
    }
  }
  return (pppppiVar3 < appppiStack_c[0]) << 4 | (iVar4 < 0) << 3 | 4U | bVar9 << 1 | bVar10;
}

