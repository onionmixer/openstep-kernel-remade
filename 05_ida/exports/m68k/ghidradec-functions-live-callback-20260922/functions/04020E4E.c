
byte * _ip_reass(byte *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined *puVar8;
  uint uStack_2c;
  uint uStack_28;
  uint *puVar9;
  
  puVar8 = &stack0xffffffdc;
  uVar4 = (uint)param_1 & 0xffffff80;
  iVar6 = (*param_1 & 0xf) * 4;
  *(int *)(uVar4 + 4) = iVar6 + *(int *)(uVar4 + 4);
  *(sword *)(uVar4 + 8) = *(sword *)(uVar4 + 8) - (sword)iVar6;
  if (param_2 == (int *)0x0) {
    uStack_28 = 0xb;
    uStack_2c = 0;
    iVar6 = _m_get();
    puVar8 = &stack0xffffffdc;
    if (iVar6 == 0) {
loc_4021082:
      dword_40B68BC = dword_40B68BC + 1;
      uStack_2c = 0x4021090;
      uStack_28 = uVar4;
      _m_freem();
      return (byte *)0x0;
    }
    piVar7 = (int *)(*(int *)(iVar6 + 4) + iVar6);
    *piVar7 = (int)_ipq;
    piVar7[1] = (int)&_ipq;
    _ipq[1] = (int)piVar7;
    _ipq = piVar7;
    *(undefined *)(piVar7 + 2) = 0x3c;
    *(byte *)((int)piVar7 + 9) = param_1[9];
    *(undefined2 *)((int)piVar7 + 10) = *(undefined2 *)(param_1 + 4);
    piVar7[4] = (int)piVar7;
    piVar7[3] = (int)piVar7;
    piVar7[5] = *(int *)(param_1 + 0xc);
    piVar7[6] = *(int *)(param_1 + 0x10);
    param_2 = piVar7;
  }
  else {
    piVar7 = (int *)param_2[3];
    if (param_2 != piVar7) {
      do {
        if (*(sword *)(param_1 + 6) < *(sword *)((int)piVar7 + 6)) break;
        piVar7 = (int *)piVar7[3];
      } while (param_2 != piVar7);
    }
    piVar2 = (int *)piVar7[4];
    if (param_2 == piVar2) goto loc_4020FAA;
    iVar6 = ((int)(sword)*piVar2 + (int)*(sword *)((int)piVar2 + 6)) - (int)*(sword *)(param_1 + 6);
    if (iVar6 < 1) goto loc_4020FAA;
    if (*(sword *)(param_1 + 2) <= iVar6) goto loc_4021082;
    uStack_2c = (uint)param_1 & 0xffffff80;
    puVar9 = &uStack_2c;
    uStack_28 = iVar6;
    _m_adj();
    *(sword *)(param_1 + 6) = (sword)iVar6 + *(sword *)(param_1 + 6);
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar6;
    while( true ) {
      puVar8 = (undefined *)((int)puVar9 + 8);
loc_4020FAA:
      if (param_2 == piVar7) goto loc_4020FAE;
      if ((int)*(sword *)(param_1 + 2) + (int)*(sword *)(param_1 + 6) <=
          (int)*(sword *)((int)piVar7 + 6)) goto loc_4020FAE;
      iVar6 = ((int)*(sword *)(param_1 + 2) + (int)*(sword *)(param_1 + 6)) -
              (int)*(sword *)((int)piVar7 + 6);
      if (iVar6 < (sword)*piVar7) break;
      piVar7 = (int *)piVar7[3];
      *(uint *)(puVar8 + -4) = piVar7[4] & 0xffffff80;
      *(undefined4 *)(puVar8 + -8) = 0x4020f9e;
      _m_freem();
      puVar9 = (uint *)(puVar8 + -8);
      *(int *)(puVar8 + -8) = piVar7[4];
      *(undefined4 *)(puVar8 + -0xc) = 0x4020fa8;
      _ip_deq();
    }
    *(sword *)((int)piVar7 + 2) = (sword)*piVar7 - (sword)iVar6;
    *(sword *)((int)piVar7 + 6) = (sword)iVar6 + *(sword *)((int)piVar7 + 6);
    *(int *)(puVar8 + -4) = iVar6;
    *(uint *)(puVar8 + -8) = (uint)piVar7 & 0xffffff80;
    *(undefined4 *)(puVar8 + -0xc) = 0x4020f08;
    _m_adj();
  }
loc_4020FAE:
  *(int *)(puVar8 + -4) = piVar7[4];
  *(byte **)(puVar8 + -8) = param_1;
  *(undefined4 *)(puVar8 + -0xc) = 0x4020fba;
  _ip_enq();
  iVar6 = 0;
  for (piVar7 = (int *)param_2[3]; param_2 != piVar7; piVar7 = (int *)piVar7[3]) {
    if (iVar6 != *(sword *)((int)piVar7 + 6)) {
      return (byte *)0x0;
    }
    iVar6 = (sword)*piVar7 + iVar6;
  }
  if (*(char *)(piVar7[4] + 1) != '\0') {
    return (byte *)0x0;
  }
  uVar4 = param_2[3];
  puVar5 = (undefined4 *)(uVar4 & 0xffffff80);
  uVar1 = *puVar5;
  *puVar5 = 0;
  *(undefined4 *)(puVar8 + -4) = uVar1;
  *(undefined4 **)(puVar8 + -8) = puVar5;
  *(undefined4 *)(puVar8 + -0xc) = 0x4021004;
  _m_cat();
  piVar7 = *(int **)(uVar4 + 0xc);
  while (param_2 != piVar7) {
    uVar4 = (uint)piVar7 & 0xffffff80;
    piVar7 = (int *)piVar7[3];
    *(uint *)(puVar8 + -4) = uVar4;
    *(undefined4 **)(puVar8 + -8) = puVar5;
    *(undefined4 *)(puVar8 + -0xc) = 0x402101e;
    _m_cat();
  }
  pbVar3 = (byte *)param_2[3];
  *(sword *)(pbVar3 + 2) = (sword)iVar6;
  *(int *)(pbVar3 + 0xc) = param_2[5];
  *(int *)(pbVar3 + 0x10) = param_2[6];
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)param_2[1] = *param_2;
  *(uint *)(puVar8 + -4) = (uint)param_2 & 0xffffff80;
  *(undefined4 *)(puVar8 + -8) = 0x4021054;
  _m_free();
  uVar4 = (uint)pbVar3 & 0xffffff80;
  *(word *)(uVar4 + 8) = (*pbVar3 & 0xf) * 4 + *(sword *)(uVar4 + 8);
  *(uint *)(uVar4 + 4) = *(int *)(uVar4 + 4) + (*pbVar3 & 0xf) * -4;
  return pbVar3;
}

