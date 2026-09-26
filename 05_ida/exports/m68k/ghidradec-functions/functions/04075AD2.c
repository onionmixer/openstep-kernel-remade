
undefined4 _od_done(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int *piVar6;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  byte bVar16;
  
  piVar6 = (int *)(param_1 + 0x18);
  if (piVar6 == (int *)*piVar6) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdEmptyQ);
  }
  puVar2 = (undefined4 *)*piVar6;
  puVar8 = (uint *)_disksort_first(puVar2);
  iVar9 = *(sword *)(param_1 + 4) * 0x28c;
  iVar10 = (sword)(word)((uint)*(undefined4 *)((int)puVar8 + 0x1f) >> 0x1b) * 0xda;
  if (-1 < *(sword *)((&DAT_40c3e2c)[(uint)*(word *)(_od_vol + iVar10 + 0xd2) * 8] + 0xc)) {
    uVar1 = (int)*(sword *)((&DAT_40c3e2c)[(uint)*(word *)(_od_vol + iVar10 + 0xd2) * 8] + 0xc) &
            0x3f;
    _dk_busy = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & _dk_busy;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _disksort_remove(puVar2,puVar8);
  iVar11 = _disksort_first(puVar2);
  if (iVar11 == 0) {
    piVar3 = (int *)*puVar2;
    puVar4 = (undefined4 *)puVar2[1];
    if (piVar3 == piVar6) {
      *(undefined4 **)(param_1 + 0x1c) = puVar4;
    }
    else {
      piVar3[1] = (int)puVar4;
    }
    *puVar4 = piVar3;
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0x9f;
  }
  _sfa_relinquish(*(undefined4 *)(DAT_40c3dfc + iVar9),iVar9 + 0x40c3e00,0);
  if (((DAT_40c3fa1[iVar10] & 8) == 0) && ((*puVar8 & 2) == 0)) {
    if (((*puVar8 & 4) != 0) && ((uint *)(_od_vol + iVar10 + 0x6a) != puVar8)) {
      *(undefined2 *)(puVar8 + 7) = 5;
    }
    _biodone(puVar8);
  }
  iVar9 = _disksort_first(puVar2);
  uVar7 = 0;
  if (iVar9 != 0) {
    _od_drive_start(_od_vol + iVar10);
    uVar7 = extraout_D0u;
  }
  puVar5 = (uint *)(param_1 + 0x18);
  puVar8 = (uint *)*puVar5;
  cVar15 = puVar5 < puVar8;
  cVar14 = SBORROW4((int)puVar5,(int)puVar8);
  cVar12 = (int)puVar5 - (int)puVar8 < 0;
  cVar13 = puVar5 == puVar8;
  bVar16 = cVar15;
  if (!(bool)cVar13) {
    cVar14 = '\0';
    bVar16 = 0;
    cVar12 = *(int *)(param_1 + 0x20) < 0;
    cVar13 = '\0';
    if (*(int *)(param_1 + 0x20) == 0) {
      cVar12 = param_1 < 0;
      cVar13 = param_1 == 0;
      cVar14 = '\0';
      bVar16 = 0;
      _od_ctrl_start(param_1);
      uVar7 = extraout_D0u_00;
    }
  }
  return CONCAT22(uVar7,(word)(byte)(cVar15 << 4 | cVar12 << 3 | cVar13 << 2 | cVar14 << 1 | bVar16)
                 );
}
