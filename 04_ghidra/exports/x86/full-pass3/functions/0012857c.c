/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012857c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte _tcp_reass(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  int *piVar5;
  
  iVar1 = *(int *)(param_1[8] + 0x1c);
  if (param_2 != (int *)0x0) {
    piVar5 = (int *)*param_1;
    if (piVar5 != param_1) {
      do {
        if (piVar5[6] != param_2[6] && -1 < piVar5[6] - param_2[6]) break;
        piVar5 = (int *)*piVar5;
      } while (param_1 != piVar5);
    }
    piVar2 = (int *)piVar5[1];
    if (param_1 != piVar2) {
      iVar3 = ((int)*(short *)((int)piVar2 + 10) + piVar2[6]) - param_2[6];
      if (0 < iVar3) {
        if (*(short *)((int)param_2 + 10) <= iVar3) {
          _DAT_001eedec = _DAT_001eedec + 1;
          _DAT_001eedf0 = _DAT_001eedf0 + *(short *)((int)param_2 + 10);
          _m_freem(param_3);
          return 0;
        }
        _m_adj(param_3,iVar3);
        *(short *)((int)param_2 + 10) = *(short *)((int)param_2 + 10) - (short)iVar3;
        param_2[6] = param_2[6] + iVar3;
      }
      piVar5 = (int *)*piVar2;
    }
    _DAT_001eedfc = _DAT_001eedfc + 1;
    _DAT_001eee00 = _DAT_001eee00 + *(short *)((int)param_2 + 10);
    param_2[5] = param_3;
    while (param_1 != piVar5) {
      iVar3 = ((int)*(short *)((int)param_2 + 10) + param_2[6]) - piVar5[6];
      if (iVar3 < 1) break;
      if (iVar3 < *(short *)((int)piVar5 + 10)) {
        piVar5[6] = piVar5[6] + iVar3;
        *(short *)((int)piVar5 + 10) = *(short *)((int)piVar5 + 10) - (short)iVar3;
        _m_adj(piVar5[5],iVar3);
        break;
      }
      piVar5 = (int *)*piVar5;
      piVar2 = (int *)piVar5[1];
      iVar3 = piVar2[5];
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[1] = *piVar2;
      _m_freem(iVar3);
    }
    piVar5 = (int *)piVar5[1];
    *param_2 = *piVar5;
    param_2[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = param_2;
    *piVar5 = (int)param_2;
  }
  if (((((short)param_1[2] < 3) || (piVar5 = (int *)*param_1, piVar5 == param_1)) ||
      (piVar5[6] != param_1[0x10])) ||
     (((short)param_1[2] == 3 && (*(short *)((int)piVar5 + 10) != 0)))) {
    bVar4 = 0;
  }
  else {
    do {
      param_1[0x10] = param_1[0x10] + (int)*(short *)((int)piVar5 + 10);
      bVar4 = *(byte *)((int)piVar5 + 0x21) & 1;
      *(int *)(*piVar5 + 4) = piVar5[1];
      *(int *)piVar5[1] = *piVar5;
      piVar2 = piVar5 + 5;
      piVar5 = (int *)*piVar5;
      if ((*(byte *)(iVar1 + 6) & 0x20) == 0) {
        _sbappend(iVar1 + 0x24,*piVar2);
      }
      else {
        _m_freem(*piVar2);
      }
    } while ((param_1 != piVar5) && (piVar5[6] == param_1[0x10]));
    _sowakeup(iVar1,iVar1 + 0x24);
  }
  return bVar4;
}

