
byte _tcp_reass(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = *(int *)(param_1[8] + 0x18);
  if (param_2 != (int *)0x0) {
    piVar5 = (int *)*param_1;
    if (param_1 != piVar5) {
      do {
        if (piVar5[6] != param_2[6] && -1 < piVar5[6] - param_2[6]) break;
        piVar5 = (int *)*piVar5;
      } while (param_1 != piVar5);
    }
    piVar2 = (int *)piVar5[1];
    if (param_1 != piVar2) {
      iVar4 = (piVar2[6] + (int)*(sword *)((int)piVar2 + 10)) - param_2[6];
      if (0 < iVar4) {
        if (*(sword *)((int)param_2 + 10) <= iVar4) {
          dword_40BBDA8 = dword_40BBDA8 + 1;
          dword_40BBDAC = *(sword *)((int)param_2 + 10) + dword_40BBDAC;
          _m_freem(param_3);
          return 0;
        }
        _m_adj(param_3,iVar4);
        *(sword *)((int)param_2 + 10) = *(sword *)((int)param_2 + 10) - (sword)iVar4;
        param_2[6] = iVar4 + param_2[6];
      }
      piVar5 = (int *)*piVar2;
    }
    dword_40BBDB8 = dword_40BBDB8 + 1;
    dword_40BBDBC = *(sword *)((int)param_2 + 10) + dword_40BBDBC;
    param_2[5] = param_3;
    while (param_1 != piVar5) {
      iVar4 = (param_2[6] + (int)*(sword *)((int)param_2 + 10)) - piVar5[6];
      if (iVar4 < 1) break;
      if (iVar4 < *(sword *)((int)piVar5 + 10)) {
        piVar5[6] = iVar4 + piVar5[6];
        *(sword *)((int)piVar5 + 10) = *(sword *)((int)piVar5 + 10) - (sword)iVar4;
        _m_adj(piVar5[5],iVar4);
        break;
      }
      piVar5 = (int *)*piVar5;
      piVar2 = (int *)piVar5[1];
      iVar4 = piVar2[5];
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[1] = *piVar2;
      _m_freem(iVar4);
    }
    piVar5 = (int *)piVar5[1];
    *param_2 = *piVar5;
    param_2[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = param_2;
    *piVar5 = (int)param_2;
  }
  if ((((2 < *(sword *)(param_1 + 2)) && (piVar5 = (int *)*param_1, param_1 != piVar5)) &&
      (piVar5[6] == param_1[0x10])) &&
     ((*(sword *)(param_1 + 2) != 3 || (*(sword *)((int)piVar5 + 10) == 0)))) {
    do {
      param_1[0x10] = (int)*(sword *)((int)piVar5 + 10) + param_1[0x10];
      bVar3 = *(byte *)((int)piVar5 + 0x21);
      *(int *)(*piVar5 + 4) = piVar5[1];
      *(int *)piVar5[1] = *piVar5;
      piVar2 = piVar5 + 5;
      piVar5 = (int *)*piVar5;
      if ((*(byte *)(iVar1 + 7) & 0x20) == 0) {
        _sbappend(iVar1 + 0x22,*piVar2);
      }
      else {
        _m_freem(*piVar2);
      }
    } while ((param_1 != piVar5) && (piVar5[6] == param_1[0x10]));
    _sowakeup(iVar1,iVar1 + 0x22);
    return bVar3 & 1;
  }
  return 0;
}

