
/* WARNING: Removing unreachable block (ram,0xf0032770) */
/* WARNING: Removing unreachable block (ram,0xf00326e8) */
/* WARNING: Removing unreachable block (ram,0xf0032564) */
/* WARNING: Removing unreachable block (ram,0xf00326c8) */
/* WARNING: Removing unreachable block (ram,0xf00325e8) */
/* WARNING: Removing unreachable block (ram,0xf00326d0) */
/* WARNING: Removing unreachable block (ram,0xf0032808) */
/* WARNING: Removing unreachable block (ram,0xf003274c) */
/* WARNING: Removing unreachable block (ram,0xf00327b4) */
/* WARNING: Removing unreachable block (ram,0xf0032670) */

undefined8 _ip_reass(byte *param_1,int *param_2)

{
  sword sVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar8;
  undefined4 unaff_i1;
  int *piVar9;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  bVar2 = *param_1;
  uVar6 = (uint)param_1 & 0xffffff80;
  *(uint *)(uVar6 + 4) = *(int *)(uVar6 + 4) + (bVar2 & 0xf) * 4;
  *(sword *)(uVar6 + 8) = *(sword *)(uVar6 + 8) + (sword)(bVar2 & 0xf) * -4;
  if (param_2 == (int *)0x0) {
    iVar3 = 0;
    _m_get(0,0xb);
    if (iVar3 == 0) {
loc_F00327F8:
      iRamf01364ec = iRamf01364ec + 1;
      _m_freem(uVar6);
      pbVar8 = (byte *)0x0;
      goto locret_F0032814;
    }
    piVar9 = (int *)(iVar3 + *(int *)(iVar3 + 4));
    *(int **)(iVar3 + *(int *)(iVar3 + 4)) = _ipq;
    piVar9[1] = (int)&_ipq;
    _ipq[1] = (int)piVar9;
    _ipq = piVar9;
    *(undefined *)(piVar9 + 2) = 0x3c;
    *(byte *)((int)piVar9 + 9) = param_1[9];
    *(undefined2 *)((int)piVar9 + 10) = *(undefined2 *)(param_1 + 4);
    piVar9[4] = (int)piVar9;
    piVar9[3] = (int)piVar9;
    piVar9[5] = *(int *)(param_1 + 0xc);
    piVar9[6] = *(int *)(param_1 + 0x10);
    param_2 = piVar9;
loc_F00326E4:
    iVar3 = piVar9[4];
  }
  else {
    piVar9 = (int *)param_2[3];
    if (piVar9 == param_2) {
      piVar4 = (int *)piVar9[4];
    }
    else {
      sVar1 = *(sword *)((int)piVar9 + 6);
      while (sVar1 <= *(sword *)(param_1 + 6)) {
        piVar9 = (int *)piVar9[3];
        if (piVar9 == param_2) {
          piVar4 = (int *)piVar9[4];
          goto loc_F0032630;
        }
        sVar1 = *(sword *)((int)piVar9 + 6);
      }
      piVar4 = (int *)piVar9[4];
    }
loc_F0032630:
    bVar10 = piVar9 == param_2;
    if (piVar4 == param_2) goto loc_F00326DC;
    iVar3 = ((int)*(sword *)((int)piVar4 + 6) + (int)(sword)*piVar4) - (int)*(sword *)(param_1 + 6);
    bVar10 = piVar9 == param_2;
    if (iVar3 < 1) goto loc_F00326DC;
    if (*(sword *)(param_1 + 2) <= iVar3) goto loc_F00327F8;
    _m_adj((uint)param_1 & 0xffffff80,iVar3);
    *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + (sword)iVar3;
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar3;
    while( true ) {
      bVar10 = piVar9 == param_2;
loc_F00326DC:
      if (bVar10) goto loc_F00326E4;
      if ((int)*(sword *)(param_1 + 6) + (int)*(sword *)(param_1 + 2) <=
          (int)*(sword *)((int)piVar9 + 6)) {
        iVar3 = piVar9[4];
        goto loc_F00326E8;
      }
      iVar3 = ((int)*(sword *)(param_1 + 6) + (int)*(sword *)(param_1 + 2)) -
              (int)*(sword *)((int)piVar9 + 6);
      if (iVar3 < (sword)*piVar9) break;
      piVar9 = (int *)piVar9[3];
      _m_freem(piVar9[4] & 0xffffff80);
      _ip_deq(piVar9[4]);
    }
    sVar1 = (sword)iVar3;
    *(sword *)((int)piVar9 + 2) = (sword)*piVar9 - sVar1;
    *(sword *)((int)piVar9 + 6) = *(sword *)((int)piVar9 + 6) + sVar1;
    _m_adj((uint)piVar9 & 0xffffff80);
    iVar3 = piVar9[4];
  }
loc_F00326E8:
  _ip_enq(param_1,iVar3);
  iVar3 = 0;
  for (piVar9 = (int *)param_2[3]; piVar9 != param_2; piVar9 = (int *)piVar9[3]) {
    if (*(sword *)((int)piVar9 + 6) != iVar3) {
      pbVar8 = (byte *)0x0;
      goto locret_F0032814;
    }
    iVar3 = iVar3 + (sword)*piVar9;
  }
  if (*(char *)(piVar9[4] + 1) == '\0') {
    uVar6 = param_2[3];
    puVar7 = (undefined4 *)(uVar6 & 0xffffff80);
    uVar5 = *puVar7;
    *puVar7 = 0;
    _m_cat(puVar7,uVar5);
    piVar9 = *(int **)(uVar6 + 0xc);
    if (piVar9 == param_2) {
      pbVar8 = (byte *)param_2[3];
    }
    else {
      do {
        uVar6 = (uint)piVar9 & 0xffffff80;
        piVar9 = (int *)piVar9[3];
        _m_cat(puVar7,uVar6);
      } while (piVar9 != param_2);
      pbVar8 = (byte *)param_2[3];
    }
    *(sword *)(pbVar8 + 2) = (sword)iVar3;
    *(int *)(pbVar8 + 0xc) = param_2[5];
    *(int *)(pbVar8 + 0x10) = param_2[6];
    *(int *)(*param_2 + 4) = param_2[1];
    *(int *)param_2[1] = *param_2;
    _m_free((uint)param_2 & 0xffffff80);
    uVar6 = (uint)pbVar8 & 0xffffff80;
    *(word *)(uVar6 + 8) = *(sword *)(uVar6 + 8) + (*pbVar8 & 0xf) * 4;
    *(uint *)(uVar6 + 4) = *(int *)(uVar6 + 4) + (*pbVar8 & 0xf) * -4;
  }
  else {
    pbVar8 = (byte *)0x0;
  }
locret_F0032814:
  return CONCAT44(param_2,pbVar8);
}
