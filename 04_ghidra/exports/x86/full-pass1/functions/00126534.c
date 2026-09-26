/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126534 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * _ip_reass(byte *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int *piVar9;
  uint uStack_24;
  uint uStack_20;
  int local_10;
  uint *puVar8;
  
  uVar5 = (uint)param_1 & 0xffffff80;
  iVar3 = (*param_1 & 0xf) * 4;
  *(int *)(uVar5 + 4) = *(int *)(uVar5 + 4) + iVar3;
  *(short *)(uVar5 + 8) = *(short *)(uVar5 + 8) - (short)iVar3;
  if (param_2 == (int *)0x0) {
    uStack_20 = 0xb;
    uStack_24 = 0;
    iVar3 = _m_get();
    puVar7 = &stack0xffffffe4;
    if (iVar3 == 0) {
LAB_001267a8:
      _DAT_001eaacc = _DAT_001eaacc + 1;
      uStack_24 = 0x1267b7;
      uStack_20 = uVar5;
      _m_freem();
      return (byte *)0x0;
    }
    piVar9 = (int *)(iVar3 + *(int *)(iVar3 + 4));
    *piVar9 = (int)_ipq;
    piVar9[1] = (int)&_ipq;
    _ipq[1] = (int)piVar9;
    _ipq = piVar9;
    *(undefined1 *)(piVar9 + 2) = 0x3c;
    *(byte *)((int)piVar9 + 9) = param_1[9];
    *(undefined2 *)((int)piVar9 + 10) = *(undefined2 *)(param_1 + 4);
    piVar9[4] = (int)piVar9;
    piVar9[3] = (int)piVar9;
    piVar9[5] = *(int *)(param_1 + 0xc);
    piVar9[6] = *(int *)(param_1 + 0x10);
    param_2 = piVar9;
  }
  else {
    piVar9 = (int *)param_2[3];
    if (piVar9 != param_2) {
      do {
        if (*(short *)(param_1 + 6) < *(short *)((int)piVar9 + 6)) break;
        piVar9 = (int *)piVar9[3];
      } while (piVar9 != param_2);
    }
    piVar1 = (int *)piVar9[4];
    puVar7 = &stack0xffffffe4;
    if (piVar1 == param_2) goto LAB_001266b4;
    iVar3 = ((int)*(short *)((int)piVar1 + 6) + (int)*(short *)((int)piVar1 + 2)) -
            (int)*(short *)(param_1 + 6);
    puVar7 = &stack0xffffffe4;
    if (iVar3 < 1) goto LAB_001266b4;
    if (*(short *)(param_1 + 2) <= iVar3) goto LAB_001267a8;
    uStack_24 = (uint)param_1 & 0xffffff80;
    puVar8 = &uStack_24;
    uStack_20 = iVar3;
    _m_adj();
    local_10._0_2_ = (short)iVar3;
    *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + (short)local_10;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) - (short)local_10;
    while( true ) {
      puVar7 = (undefined1 *)((int)puVar8 + 8);
LAB_001266b4:
      if (piVar9 == param_2) goto LAB_001266b8;
      if ((int)*(short *)(param_1 + 6) + (int)*(short *)(param_1 + 2) <=
          (int)*(short *)((int)piVar9 + 6)) goto LAB_001266b8;
      iVar3 = ((int)*(short *)(param_1 + 6) + (int)*(short *)(param_1 + 2)) -
              (int)*(short *)((int)piVar9 + 6);
      if (iVar3 < *(short *)((int)piVar9 + 2)) break;
      piVar9 = (int *)piVar9[3];
      *(uint *)(puVar7 + -4) = piVar9[4] & 0xffffff80;
      *(undefined4 *)(puVar7 + -8) = 0x1266a8;
      _m_freem();
      puVar8 = (uint *)(puVar7 + -8);
      *(int *)(puVar7 + -8) = piVar9[4];
      *(undefined4 *)(puVar7 + -0xc) = 0x1266b1;
      _ip_deq();
    }
    local_10._0_2_ = (short)iVar3;
    *(short *)((int)piVar9 + 2) = *(short *)((int)piVar9 + 2) - (short)local_10;
    *(short *)((int)piVar9 + 6) = *(short *)((int)piVar9 + 6) + (short)local_10;
    *(int *)(puVar7 + -4) = iVar3;
    *(uint *)(puVar7 + -8) = (uint)piVar9 & 0xffffff80;
    *(undefined4 *)(puVar7 + -0xc) = 0x1265f6;
    _m_adj();
  }
LAB_001266b8:
  *(int *)(puVar7 + -4) = piVar9[4];
  *(byte **)(puVar7 + -8) = param_1;
  *(undefined4 *)(puVar7 + -0xc) = 0x1266c5;
  _ip_enq();
  local_10 = 0;
  piVar9 = (int *)param_2[3];
  while( true ) {
    if (piVar9 == param_2) {
      if (*(char *)(piVar9[4] + 1) == '\0') {
        uVar5 = param_2[3];
        puVar6 = (undefined4 *)(uVar5 & 0xffffff80);
        uVar2 = *puVar6;
        *puVar6 = 0;
        *(undefined4 *)(puVar7 + -4) = uVar2;
        *(undefined4 **)(puVar7 + -8) = puVar6;
        *(undefined4 *)(puVar7 + -0xc) = 0x12671e;
        _m_cat();
        piVar9 = *(int **)(uVar5 + 0xc);
        while (piVar9 != param_2) {
          uVar5 = (uint)piVar9 & 0xffffff80;
          piVar9 = (int *)piVar9[3];
          *(uint *)(puVar7 + -4) = uVar5;
          *(undefined4 **)(puVar7 + -8) = puVar6;
          *(undefined4 *)(puVar7 + -0xc) = 0x126735;
          _m_cat();
        }
        pbVar4 = (byte *)param_2[3];
        *(short *)(pbVar4 + 2) = (short)local_10;
        *(int *)(pbVar4 + 0xc) = param_2[5];
        *(int *)(pbVar4 + 0x10) = param_2[6];
        *(int *)(*param_2 + 4) = param_2[1];
        *(int *)param_2[1] = *param_2;
        *(uint *)(puVar7 + -4) = (uint)param_2 & 0xffffff80;
        *(undefined4 *)(puVar7 + -8) = 0x12676f;
        _m_free();
        uVar5 = (uint)pbVar4 & 0xffffff80;
        *(ushort *)(uVar5 + 8) = *(short *)(uVar5 + 8) + (*pbVar4 & 0xf) * 4;
        *(uint *)(uVar5 + 4) = *(int *)(uVar5 + 4) + (*pbVar4 & 0xf) * -4;
      }
      else {
        pbVar4 = (byte *)0x0;
      }
      return pbVar4;
    }
    if (local_10 != *(short *)((int)piVar9 + 6)) break;
    local_10 = local_10 + *(short *)((int)piVar9 + 2);
    piVar9 = (int *)piVar9[3];
  }
  return (byte *)0x0;
}

