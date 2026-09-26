
uint _odstrategy(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  word wVar4;
  uint *puVar5;
  uint uVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  byte bVar15;
  
  uVar6 = *(uint *)((int)param_1 + 0x1f) >> 0x1b;
  bVar7 = false;
  uVar8 = uVar6 * 0xda;
  puVar10 = _od_vol + uVar8;
  uVar9 = uVar8;
  if (uVar6 < 0x1f) {
    wVar4 = *(word *)(unk_40C3FA0 + uVar8);
    uVar9 = (uint)wVar4;
    if (wVar4 == 0) goto loc_4075462;
    if (((*param_1 & 1) == 0) && ((wVar4 & 4) != 0)) {
      *(undefined2 *)(param_1 + 7) = 0x1e;
    }
    else {
      iVar3 = *(int *)(_od_vol + uVar8 + 0xae);
      piVar1 = (int *)(iVar3 + (sword)(*(word *)((int)param_1 + 0x1e) & 7) * 0x2e + 0xbe);
      uVar6 = param_1[9];
      param_1[0xe] = uVar6;
      uVar9 = (int)param_1[5] % *(int *)(iVar3 + 0x5c);
      if (uVar9 == 0) {
        if ((uint *)(_od_vol + uVar8 + 0x6a) != param_1) {
          if ((unk_40C3FA0[uVar8] & 0x40) == 0) goto loc_4075462;
          uVar9 = piVar1[1];
          if (((uVar9 == 0) || ((int)uVar6 < 0)) || ((int)uVar9 < (int)uVar6)) goto loc_407547A;
          if (uVar9 == uVar6) {
            param_1[10] = param_1[5];
            goto loc_40755B2;
          }
          param_1[0xe] = *piVar1 + uVar6;
          if (_od_idle_time == 0) {
            _od_idle_time = 1;
          }
          if (0 < _od_idle_time) {
            _od_idle_time = 1;
          }
          if (_od_idle_time == -1) {
            _od_idle_time = -3;
          }
        }
        param_1[0xe] = (int)param_1[0xe] / *(int *)(iVar3 + 100);
        while (((*(word *)(unk_40C3FA0 + uVar8) & 0x400) != 0 && ((int)param_1[0xf] < 2))) {
          *(word *)(unk_40C3FA0 + uVar8) = *(word *)(unk_40C3FA0 + uVar8) | 0x200;
          _sleep(puVar10,0x14);
        }
        cVar14 = _od_vol + uVar8 + 0x6a < param_1;
        if ((uint *)(_od_vol + uVar8 + 0x6a) == param_1) {
          if (((unk_40C3FA0[uVar8 + 1] & 0x40) == 0) ||
             (cVar14 = *(word *)(_od_vol + uVar8 + 0xd4) < 0xf1,
             *(word *)(_od_vol + uVar8 + 0xd4) == 0xf1)) {
            cVar14 = _od_vol + uVar8 + 0x6a < param_1;
            if ((uint *)(_od_vol + uVar8 + 0x6a) == param_1) {
              wVar4 = *(word *)(_od_vol + uVar8 + 0xd4);
              cVar14 = wVar4 < 0xf6;
              if ((wVar4 == 0xf6) || (cVar14 = wVar4 < 0xf1, wVar4 == 0xf1)) {
                _disksort_enter_tail(puVar10,param_1);
                goto loc_4075564;
              }
            }
            goto loc_407555A;
          }
          _disksort_enter_head(puVar10,param_1);
          bVar7 = true;
        }
        else {
loc_407555A:
          _disksort_enter(puVar10,param_1);
        }
loc_4075564:
        if ((_od_vol[uVar8 + 0xc] & 0x60) != 0) {
          cVar13 = '\0';
          cVar11 = '\0';
          cVar12 = '\x01';
          bVar15 = 0;
          if (!bVar7) goto loc_40755A8;
        }
        _od_drive_start(puVar10);
        iVar3 = *(int *)(&DAT_40c3e28 + (uint)*(word *)(_od_vol + uVar8 + 0xd2) * 4);
        puVar5 = (uint *)(iVar3 + 0x18);
        puVar2 = (uint *)*puVar5;
        cVar14 = puVar5 < puVar2;
        cVar13 = SBORROW4((int)puVar5,(int)puVar2);
        cVar11 = (int)puVar5 - (int)puVar2 < 0;
        cVar12 = puVar5 == puVar2;
        bVar15 = cVar14;
        if (!(bool)cVar12) {
          cVar13 = '\0';
          bVar15 = 0;
          cVar11 = *(int *)(iVar3 + 0x20) < 0;
          cVar12 = '\0';
          if (*(int *)(iVar3 + 0x20) == 0) {
            cVar11 = iVar3 < 0;
            cVar12 = iVar3 == 0;
            cVar13 = '\0';
            bVar15 = 0;
            _od_ctrl_start(iVar3);
          }
        }
loc_40755A8:
        return (uint)(byte)(cVar14 << 4 | cVar11 << 3 | cVar12 << 2 | cVar13 << 1 | bVar15);
      }
loc_407547A:
      *(undefined2 *)(param_1 + 7) = 0x16;
    }
  }
  else {
loc_4075462:
    *(undefined2 *)(param_1 + 7) = 6;
  }
  *param_1 = *param_1 | 4;
loc_40755B2:
  if ((*param_1 & 2) == 0) {
    uVar9 = _biodone(param_1);
  }
  return uVar9;
}
