
void _srmmu_mmu_sys_unf(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 in_fp_7;
  undefined8 uVar12;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  int iVar13;
  
  segment(4);
  iVar3 = 0;
  puVar1 = (uint *)segment(4);
  uVar2 = *puVar1 | 2;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2;
  iVar13 = in_CWP + -1;
  puVar11 = (undefined8 *)((qword)in_fp_7 >> 0x20);
  uVar4 = *puVar11;
  uVar5 = (undefined4)puVar11[1];
  uVar6 = puVar11[2];
  uVar7 = puVar11[3];
  uVar8 = puVar11[4];
  uVar9 = puVar11[5];
  uVar10 = puVar11[6];
  uVar12 = puVar11[7];
  if (!in_DECOMPILE_MODE) {
    *(int *)(iVar13 * 0x40 + 0x8000) = (int)((qword)uVar8 >> 0x20);
    *(int *)((iVar13 * 0x10 + 1) * 4 + 0x8000) = (int)uVar8;
    *(int *)((iVar13 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uVar9 >> 0x20);
    *(int *)((iVar13 * 0x10 + 3) * 4 + 0x8000) = (int)uVar9;
    *(int *)((iVar13 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uVar10 >> 0x20);
    *(int *)((iVar13 * 0x10 + 5) * 4 + 0x8000) = (int)uVar10;
    *(int *)((iVar13 * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uVar12 >> 0x20);
    *(int *)((iVar13 * 0x10 + 7) * 4 + 0x8000) = (int)uVar12;
    *(int *)((iVar13 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar4 >> 0x20);
    *(int *)((iVar13 * 0x10 + 9) * 4 + 0x8000) = (int)uVar4;
    *(undefined4 *)((iVar13 * 0x10 + 10) * 4 + 0x8000) = uVar5;
    *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000) = uVar5;
    *(int *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
    *(int *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar6;
    *(int *)((iVar13 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar7 >> 0x20);
    *(int *)((iVar13 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar7;
  }
  iVar13 = segment(4);
  *(uint *)(iVar3 + iVar13) = uVar2 & 0xfffffffd;
  segment(4);
  segment(4);
  sr_chk_flt();
  return;
}
