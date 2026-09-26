/* GHIDRADEC_FUNCTION index=2100 start=0xf0095c6c */

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
/* GHIDRADEC_FUNCTION index=2101 start=0xf0095cc8 */

void _srmmu_mmu_wo(void)

{
  uint *puVar1;
  uint uVar2;
  
  segment(4);
  puVar1 = (uint *)segment(4);
  uVar2 = *puVar1;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2 | 2;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2 & 0xfffffffd;
  segment(4);
  segment(4);
  wo_chk_flt();
  return;
}
/* GHIDRADEC_FUNCTION index=2102 start=0xf0095d1c */

void _srmmu_mmu_wu(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined in_DECOMPILE_MODE;
  int in_CWP;
  int iVar7;
  undefined8 uStackX_0;
  undefined4 uStackX_c;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  undefined8 uStackX_28;
  undefined8 uStackX_30;
  undefined8 uStackX_38;
  
  segment(4);
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 | 2;
  if (!(bool)in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)uStackX_20 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)uStackX_20;
    *(int *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uStackX_28 >> 0x20);
    *(int *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = (int)uStackX_28;
    *(int *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uStackX_30 >> 0x20);
    *(int *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = (int)uStackX_30;
    *(int *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uStackX_38 >> 0x20);
    *(int *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = (int)uStackX_38;
    *(int *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uStackX_0 >> 0x20);
    *(int *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = (int)uStackX_0;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uStackX_c;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uStackX_c;
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uStackX_10 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)uStackX_10;
    *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uStackX_18 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = (int)uStackX_18;
  }
  uVar3 = 0;
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  iVar7 = in_CWP + 1;
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(iVar7 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar7 * 0x10 + 1) * 4 + 0x8000) = param_2;
    *(undefined4 *)((iVar7 * 0x10 + 2) * 4 + 0x8000) = param_3;
    *(undefined4 *)((iVar7 * 0x10 + 3) * 4 + 0x8000) = 0;
    *(undefined4 *)((iVar7 * 0x10 + 4) * 4 + 0x8000) = param_5;
    *(undefined4 *)((iVar7 * 0x10 + 5) * 4 + 0x8000) = 0;
    *(BADSPACEBASE **)((iVar7 * 0x10 + 6) * 4 + 0x8000) = register0x00000038;
    *(undefined4 *)((iVar7 * 0x10 + 7) * 4 + 0x8000) = 0;
    *(int *)((iVar7 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar3 >> 0x20);
    *(int *)((iVar7 * 0x10 + 9) * 4 + 0x8000) = (int)uVar3;
    *(undefined4 *)((iVar7 * 0x10 + 10) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar7 * 0x10 + 0xb) * 4 + 0x8000) = uVar4;
    *(int *)((iVar7 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar5 >> 0x20);
    *(int *)((iVar7 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar5;
    *(int *)((iVar7 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
    *(int *)((iVar7 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar6;
  }
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & 0xfffffffd;
  segment(4);
  segment(4);
  wu_chk_flt();
  return;
}
/* GHIDRADEC_FUNCTION index=2103 start=0xf0095d84 */

void _swift_vac_init_asm(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x4000;
  do {
    iVar2 = iVar2 + -0x10;
    iVar1 = segment(0xc);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar1 = segment(0xe);
    *(undefined4 *)(iVar2 + iVar1) = 0;
  } while (iVar2 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2104 start=0xf0095da0 */

void _swift_cache_on(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (_use_ic != 0) {
    uVar3 = 0x200;
  }
  if (_use_dc != 0) {
    uVar3 = uVar3 | 0x100;
  }
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & 0xfffffcff | uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2105 start=0xf0095de8 */

void _swift_vac_flushall(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x4000;
  do {
    iVar2 = iVar2 + -0x10;
    iVar1 = segment(0xc);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar1 = segment(0xe);
    *(undefined4 *)(iVar2 + iVar1) = 0;
  } while (iVar2 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2106 start=0xf0095e04 */

void _swift_vac_flush(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar2 = param_1 - (param_1 & 0xf);
  uVar3 = param_2 + (param_1 & 0xf);
  do {
    bVar4 = 0xf < uVar3;
    uVar3 = uVar3 - 0x10;
    iVar1 = segment(0x10);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar2 = iVar2 + 0x10;
  } while (bVar4);
  return;
}
/* GHIDRADEC_FUNCTION index=2107 start=0xf0095e28 */

void _swift_vac_usrflush(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x800;
  iVar2 = 0;
  do {
    iVar3 = iVar3 + -0x20;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x1000 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x1800 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x2010 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x2810 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x3010 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x3810 + iVar1) = 0;
    iVar2 = iVar2 + 0x20;
  } while (iVar3 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2108 start=0xf0095e84 */

void _swift_vac_ctxflush(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = segment(4);
  iVar3 = segment(0x20);
  iVar1 = segment(4);
  uVar2 = *(undefined4 *)(iVar1 + 0x200);
  if ((*(uint *)(*(int *)(iVar4 + 0x100) * 0x10 + param_3 * 4 + iVar3) & 3) == 1) {
    iVar4 = segment(4);
    *(int *)(iVar4 + 0x200) = param_3;
  }
  iVar4 = 0x800;
  iVar3 = 0;
  do {
    iVar4 = iVar4 + -0x20;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x1000 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x1800 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x2010 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x2810 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x3010 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x3810 + iVar1) = 0;
    iVar3 = iVar3 + 0x20;
  } while (iVar4 != 0);
  iVar4 = segment(4);
  *(undefined4 *)(iVar4 + 0x200) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=2109 start=0xf0095f38 */

void _swift_vac_rgnflush(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = segment(4);
  iVar1 = segment(0x20);
  iVar2 = segment(4);
  uVar3 = *(undefined4 *)(iVar2 + 0x200);
  if ((*(uint *)(*(int *)(iVar4 + 0x100) * 0x10 + param_3 * 4 + iVar1) & 3) == 1) {
    iVar4 = segment(4);
    *(int *)(iVar4 + 0x200) = param_3;
  }
  iVar4 = 0x800;
  do {
    iVar4 = iVar4 + -0x20;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x1000 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x1800 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x2010 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x2810 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x3010 + iVar1) = 0;
    iVar1 = segment(0x12);
    *(undefined4 *)(param_1 + 0x3810 + iVar1) = 0;
    param_1 = param_1 + 0x20;
  } while (iVar4 != 0);
  iVar4 = segment(4);
  *(undefined4 *)(iVar4 + 0x200) = uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2110 start=0xf0095fe8 */

void _swift_vac_segflush(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = segment(4);
  iVar1 = segment(0x20);
  iVar2 = segment(4);
  uVar3 = *(undefined4 *)(iVar2 + 0x200);
  if ((*(uint *)(*(int *)(iVar4 + 0x100) * 0x10 + param_3 * 4 + iVar1) & 3) == 1) {
    iVar4 = segment(4);
    *(int *)(iVar4 + 0x200) = param_3;
  }
  iVar4 = 0x800;
  do {
    iVar4 = iVar4 + -0x20;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x1000 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x1800 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x2010 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x2810 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x3010 + iVar1) = 0;
    iVar1 = segment(0x11);
    *(undefined4 *)(param_1 + 0x3810 + iVar1) = 0;
    param_1 = param_1 + 0x20;
  } while (iVar4 != 0);
  iVar4 = segment(4);
  *(undefined4 *)(iVar4 + 0x200) = uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2111 start=0xf0096098 */

void _swift_vac_pageflush(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x200;
  do {
    iVar2 = iVar2 + -0x10;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x200 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x400 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x600 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xa00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xc00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xe00 + iVar1) = 0;
    param_1 = param_1 + 0x10;
  } while (iVar2 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2112 start=0xf00960ec */

void _swift_vac_pagectxflush(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = segment(4);
  iVar1 = segment(0x20);
  iVar2 = segment(4);
  uVar3 = *(undefined4 *)(iVar2 + 0x200);
  if ((*(uint *)(*(int *)(iVar4 + 0x100) * 0x10 + param_3 * 4 + iVar1) & 3) == 1) {
    iVar4 = segment(4);
    *(int *)(iVar4 + 0x200) = param_3;
  }
  iVar4 = 0x200;
  do {
    iVar4 = iVar4 + -0x10;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x200 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x400 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x600 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xa00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xc00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xe00 + iVar1) = 0;
    param_1 = param_1 + 0x10;
  } while (iVar4 != 0);
  iVar4 = segment(4);
  *(undefined4 *)(iVar4 + 0x200) = uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2113 start=0xf0096198 */

void _swift_mmu_getsyncflt(void)

{
  uint unaff_l4;
  
  if ((unaff_l4 & 0xf) != 1) {
    segment(4);
  }
  segment(4);
  return;
}
/* GHIDRADEC_FUNCTION index=2114 start=0xf00961c0 */

uint _swift_mmu_chk_wdreset(void)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  return *(uint *)(iVar1 + 0x71f00000) & 0x10;
}
/* GHIDRADEC_FUNCTION index=2115 start=0xf00961d0 */

void _swift_mmu_getasyncflt(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}
/* GHIDRADEC_FUNCTION index=2116 start=0xf00961dc */

uint _swift_pte_rmw(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_1 & ~param_2 | param_3;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2117 start=0xf009621c */

undefined4 _swift_getversion(void)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  return *(undefined4 *)(iVar1 + 0x10003018);
}
/* GHIDRADEC_FUNCTION index=2118 start=0xf009622c */

void _vik_mmu_getasyncflt
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = segment(4);
  param_1[1] = *(undefined4 *)(iVar1 + 0x400);
  iVar1 = segment(4);
  *param_1 = *(undefined4 *)(iVar1 + 0x300);
  uVar2 = 0xffffffff;
  if (_mod_info != 0x40) {
    iVar1 = segment(2);
    param_1[3] = *(undefined4 *)(iVar1 + 0x1c00e00);
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00e00) = 0xffffffff;
    uVar2 = param_4;
  }
  param_1[2] = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=2119 start=0xf0096280 */

uint _vik_mmu_chk_wdreset(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(uint *)(iVar1 + 0x300) & 0x20000;
}
/* GHIDRADEC_FUNCTION index=2120 start=0xf0096294 */

undefined4 _probe_pte_0(uint param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  return *(undefined4 *)((param_1 & 0xfffff000) + iVar1);
}
/* GHIDRADEC_FUNCTION index=2121 start=0xf00962a4 */

undefined4 _probe_1(uint param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  return *(undefined4 *)((param_1 & 0xfffff000 | 0x100) + iVar1);
}
/* GHIDRADEC_FUNCTION index=2122 start=0xf00962bc */

undefined4 _probe_2(uint param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  return *(undefined4 *)((param_1 & 0xfffff000 | 0x200) + iVar1);
}
/* GHIDRADEC_FUNCTION index=2123 start=0xf00962d4 */

undefined4 _probe_3(uint param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  return *(undefined4 *)((param_1 & 0xfffff000 | 0x300) + iVar1);
}
/* GHIDRADEC_FUNCTION index=2124 start=0xf00962ec */

void _bpt_reg(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(0x4c);
  puVar2 = (uint *)segment(0x4c);
  *puVar2 = (param_1 | *puVar1) & ~param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2125 start=0xf0096300 */

uint _vik_pte_rmw(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_1 & ~param_2 | param_3;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2126 start=0xf0096338 */

void _vik_vac_init_asm(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & ~param_1 | param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2127 start=0xf0096354 */

void _vik_mxcc_init_asm(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(2);
  *(undefined4 *)(iVar1 + 0x1c00e00) = 0xffffffff;
  iVar1 = segment(2);
  iVar2 = segment(2);
  *(uint *)(iVar2 + 0x1c00a04) = *(uint *)(iVar1 + 0x1c00a04) & ~param_1 | param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2128 start=0xf0096388 */

void _vik_cache_on(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 0x4700;
  puVar1 = (uint *)segment(4);
  if ((*puVar1 & 0x800) == 0) {
    uVar3 = 0x54700;
  }
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 | uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2129 start=0xf00963bc */

undefined4 _mxcc_vac_parity_chk_dis(uint param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if ((((param_1 & 0x2000) == 0) && ((param_1 & 0x4000) == 0)) && ((param_2 & 0x8000000) == 0)) {
    return 0;
  }
  iVar1 = segment(2);
  puVar2 = (uint *)segment(4);
  uVar4 = *puVar2;
  iVar3 = segment(2);
  *(uint *)(iVar3 + 0x1c00a04) = ~*(uint *)(iVar1 + 0x1c00a04) & 8;
  puVar2 = (uint *)segment(4);
  *puVar2 = ~uVar4 & 0x1000;
  return 1;
}
/* GHIDRADEC_FUNCTION index=2130 start=0xf0096420 */

void _vik_mmu_flushctx(undefined4 param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = segment(4);
  iVar5 = *(int *)(iVar1 + 0x100);
  puVar2 = (uint *)segment(4);
  uVar4 = *puVar2;
  puVar2 = (uint *)segment(4);
  *puVar2 = uVar4 | 0x8000;
  iVar1 = segment(0x20);
  uVar6 = *(uint *)(iVar5 * 0x10 + param_2 * 4 + iVar1);
  puVar2 = (uint *)segment(4);
  *puVar2 = uVar4;
  iVar1 = segment(4);
  uVar3 = *(undefined4 *)(iVar1 + 0x200);
  if ((uVar6 & 3) == 1) {
    iVar1 = segment(4);
    *(int *)(iVar1 + 0x200) = param_2;
  }
  iVar1 = segment(3);
  *(undefined4 *)(iVar1 + 0x300) = 0;
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2131 start=0xf0096494 */

void _vik_mmu_flushrgn(uint param_1)

{
  func_0xf00964a8(param_1 | 0x200);
  return;
}
/* GHIDRADEC_FUNCTION index=2132 start=0xf009649c */

void _vik_mmu_flushseg(uint param_1)

{
  func_0xf00964a8(param_1 | 0x100);
  return;
}
/* GHIDRADEC_FUNCTION index=2133 start=0xf00964a4 */

void _vik_mmu_flushpage(int param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  *(undefined4 *)(param_1 + iVar1) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2134 start=0xf00964b4 */

void _vik_mmu_flushpagectx(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = segment(4);
  iVar5 = *(int *)(iVar1 + 0x100);
  puVar2 = (uint *)segment(4);
  uVar4 = *puVar2;
  puVar2 = (uint *)segment(4);
  *puVar2 = uVar4 | 0x8000;
  iVar1 = segment(0x20);
  uVar6 = *(uint *)(iVar5 * 0x10 + param_2 * 4 + iVar1);
  puVar2 = (uint *)segment(4);
  *puVar2 = uVar4;
  iVar1 = segment(4);
  uVar3 = *(undefined4 *)(iVar1 + 0x200);
  if ((uVar6 & 3) == 1) {
    iVar1 = segment(4);
    *(int *)(iVar1 + 0x200) = param_2;
  }
  iVar1 = segment(3);
  *(undefined4 *)(param_1 + iVar1) = 0;
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2135 start=0xf0096528 */

undefined8 _vik_1137125_wa(void)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  uint uVar5;
  undefined4 unaff_i2;
  uint uVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 0x20;
  } while (iVar2 < 0x8001);
  uVar6 = 0;
  uVar3 = 0x40000000;
  do {
    iVar2 = segment(0xe);
    *(undefined4 *)(uVar3 + iVar2) = 0;
    uVar4 = 0x4000000;
    uVar3 = 0x84000000;
    while( true ) {
      iVar2 = segment(0xe);
      *(undefined4 *)((uVar6 | uVar3) + iVar2) = 0;
      iVar2 = 0;
      uVar5 = uVar6 | uVar4;
      uVar3 = 0;
      do {
        iVar1 = segment(0xf);
        *(undefined4 *)((uVar5 | uVar3) + iVar1) = 0;
        iVar2 = iVar2 + 1;
        uVar3 = iVar2 * 8;
      } while (iVar2 < 4);
      uVar4 = uVar4 + 0x4000000;
      if (0xc000000 < (int)uVar4) break;
      uVar3 = uVar4 | 0x80000000;
    }
    uVar6 = uVar6 + 0x20;
    uVar3 = uVar6 | 0x40000000;
  } while ((int)uVar6 < 0xfe1);
  return CONCAT44(uVar5,uVar4);
}
/* GHIDRADEC_FUNCTION index=2136 start=0xf009660c */

uint _vik_pac_pageflush(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_o5;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    while( true ) {
      uVar2 = iVar4 << 0x1a | iVar3 << 5 | 0x80000000U;
      iVar1 = segment(0xe);
      if (((in_o5 != param_1) || (in_o5 = 0x1000000, (*(uint *)(uVar2 + iVar1) & 0x1000000) == 0))
         || (in_o5 = 0x10000, (*(uint *)(uVar2 + iVar1) & 0x10000) == 0)) break;
      uVar2 = uVar2 ^ iVar4 << 0x1a;
      for (iVar4 = 0; in_o5 = 0x1000, iVar4 != 7; iVar4 = iVar4 + 1) {
      }
loc_F00966AC:
      iVar4 = 0;
      if (iVar3 == 0x7f) {
        return uVar2;
      }
      iVar3 = iVar3 + 1;
    }
    if (iVar4 == 3) goto loc_F00966AC;
    iVar4 = iVar4 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2137 start=0xf00966c4 */

undefined4 _vik_mxcc_pageflush(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00100) = 0x10;
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00200) = 0x10;
    uVar2 = uVar2 + 0x20;
  } while ((uVar2 & 0xfff) != 0);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2138 start=0xf00966fc */

int _ocsum(word *param_1,int param_2)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  uVar5 = 0;
  if (param_2 < 0x1f) {
    bVar8 = false;
    bVar7 = param_2 == 0;
    bVar6 = param_2 < 0;
  }
  else {
    for (; ((uint)param_1 & 0x1f) != 0; param_1 = param_1 + 1) {
      uVar5 = uVar5 + *param_1;
      param_2 = param_2 + -1;
    }
    do {
      param_2 = param_2 + -0x10;
      uVar2 = (uint)((qword)*(undefined8 *)param_1 >> 0x20);
      uVar3 = uVar5 + uVar2;
      uVar4 = (uint)*(undefined8 *)param_1;
      bVar6 = CARRY4(uVar3,uVar4) || CARRY4(uVar3 + uVar4,(uint)CARRY4(uVar5,uVar2));
      uVar5 = uVar3 + uVar4 + (uint)CARRY4(uVar5,uVar2);
      uVar3 = (uint)((qword)*(undefined8 *)(param_1 + 4) >> 0x20);
      bVar7 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar6);
      uVar5 = uVar5 + uVar3 + (uint)bVar6;
      uVar3 = (uint)*(undefined8 *)(param_1 + 4);
      bVar6 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar7);
      uVar5 = uVar5 + uVar3 + (uint)bVar7;
      uVar3 = (uint)((qword)*(undefined8 *)(param_1 + 8) >> 0x20);
      bVar7 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar6);
      uVar5 = uVar5 + uVar3 + (uint)bVar6;
      uVar3 = (uint)*(undefined8 *)(param_1 + 8);
      bVar6 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar7);
      uVar5 = uVar5 + uVar3 + (uint)bVar7;
      uVar3 = (uint)((qword)*(undefined8 *)(param_1 + 0xc) >> 0x20);
      bVar7 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar6);
      uVar5 = uVar5 + uVar3 + (uint)bVar6;
      uVar3 = (uint)*(undefined8 *)(param_1 + 0xc);
      uVar5 = uVar5 + uVar3 + (uint)bVar7 +
              (uint)(CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar7));
      param_1 = param_1 + 0x10;
    } while (0xf < param_2);
    bVar8 = false;
    bVar7 = param_2 == 0;
    bVar6 = param_2 < 0;
  }
  while (!bVar7 && bVar6 == bVar8) {
    wVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar5 = uVar5 + wVar1 + (uint)CARRY4(uVar5,(uint)wVar1);
    bVar8 = SBORROW4(param_2,1);
    param_2 = param_2 + -1;
    bVar6 = param_2 < 0;
    bVar7 = param_2 == 0;
  }
  return (uVar5 * 0x10001 >> 0x10) + (uint)CARRY4(uVar5 * 0x10000,uVar5);
}
/* GHIDRADEC_FUNCTION index=2139 start=0xf00967ac */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void window_overflow(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_g1;
  uint uVar1;
  undefined4 unaff_g2;
  undefined4 unaff_g3;
  undefined4 in_o7;
  uint unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined *puVar13;
  undefined4 unaff_i7;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar10 = __nwindows + -1;
  uVar4 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  uVar1 = uVar4 << ((byte)iVar10 & 0x1f) | uVar4 >> 1;
  if ((unaff_l0 & 0x40) != 0) {
    uVar7 = *(uint *)(*_active_pcb + 0xc);
    if (uVar7 == 0) {
      if (!(bool)in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
        *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
        *(uint *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
        *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
        *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar4;
        *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar4;
        *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
        *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_g2;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar10;
        *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_g1;
      }
      uVar6 = 0;
      uVar2 = 0;
      uVar3 = 0;
      uVar5 = 0;
      uVar8 = 0;
      uVar9 = 0;
      uVar11 = 0;
      uVar12 = 0;
      puVar13 = (undefined *)register0x00000038;
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar1;
      *(qword *)register0x00000038 = CONCAT44(uVar6,uVar2);
      *(qword *)((int)register0x00000038 + 8) = CONCAT44(uVar3,uVar5);
      *(qword *)((int)register0x00000038 + 0x10) = CONCAT44(uVar8,uVar9);
      *(qword *)((int)register0x00000038 + 0x18) = CONCAT44(uVar11,uVar12);
      *(qword *)((int)register0x00000038 + 0x20) = CONCAT44(param_1,param_2);
      *(qword *)((int)register0x00000038 + 0x28) = CONCAT44(param_3,param_4);
      *(qword *)((int)register0x00000038 + 0x30) = CONCAT44(param_5,param_6);
      *(qword *)((int)register0x00000038 + 0x38) = CONCAT44(puVar13,in_o7);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    *(uint *)(*_active_pcb + 0xc) = uVar7 & ~uVar1;
  }
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(uint *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar4;
    *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_g3;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_g2;
    *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar10;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_g1;
  }
  uVar6 = 0;
  iVar10 = in_CWP + 1;
  *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008
           + (uint)(in_TL == 4) * 0x600c) = uVar1;
  if (((uint)register0x00000038 & 7) != 0) {
    if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                   (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x40) == 0) {
      if (!(bool)in_DECOMPILE_MODE) {
        uVar6 = *(undefined4 *)(((iVar10 + -1) * 0x10 + 0xb) * 4 + 0x8000);
      }
      *(undefined4 *)
       ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
       (uint)(in_TL == 4) * 0x600c) = uVar6;
      sys_trap(param_1,param_2,param_3,param_4,param_5,param_6);
      return;
    }
    return;
  }
  if (register0x00000038 < &dword_F0000000) {
                    /* WARNING: Could not recover jumptable at 0xf00968b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_mmu_wo)();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2140 start=0xf00968b8 */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf00969f0) */

void wo_chk_flt(void)

{
  uint unaff_g1;
  undefined8 *puVar1;
  undefined8 in_g4_5;
  undefined8 in_g6_7;
  int iVar2;
  int iVar3;
  uint unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l2;
  uint unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  undefined4 in_Y;
  bool in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar4;
  undefined auStackX_0 [92];
  
  iVar2 = _active_pcb;
  if ((unaff_g1 & 2) != 0) {
    if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                   (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x40) == 0) {
      *(BADSPACEBASE **)(_active_pcb + 0x210) = register0x00000038;
      *(qword *)(iVar2 + 0x10) = CONCAT44(unaff_l0,unaff_l1);
      *(qword *)(iVar2 + 0x18) = CONCAT44(unaff_l2,unaff_l3);
      *(qword *)(iVar2 + 0x20) = CONCAT44(unaff_l4,unaff_l5);
      *(qword *)(iVar2 + 0x28) = CONCAT44(unaff_l6,unaff_l7);
      *(qword *)(iVar2 + 0x30) = CONCAT44(unaff_i0,unaff_i1);
      *(qword *)(iVar2 + 0x38) = CONCAT44(unaff_i2,unaff_i3);
      *(qword *)(iVar2 + 0x40) = CONCAT44(unaff_i4,unaff_i5);
      *(qword *)(iVar2 + 0x48) = CONCAT44(unaff_fp,unaff_i7);
      iVar2 = _active_pcb;
      iVar4 = in_CWP + -1;
      if (!in_DECOMPILE_MODE) {
        unaff_i0 = *(undefined4 *)(iVar4 * 0x40 + 0x8000);
        unaff_i1 = *(undefined4 *)((iVar4 * 0x10 + 1) * 4 + 0x8000);
        unaff_i2 = *(undefined4 *)((iVar4 * 0x10 + 2) * 4 + 0x8000);
        unaff_i3 = *(undefined4 *)((iVar4 * 0x10 + 3) * 4 + 0x8000);
        unaff_i4 = *(undefined4 *)((iVar4 * 0x10 + 4) * 4 + 0x8000);
        unaff_i5 = *(undefined4 *)((iVar4 * 0x10 + 5) * 4 + 0x8000);
        unaff_fp = *(undefined4 *)((iVar4 * 0x10 + 6) * 4 + 0x8000);
        unaff_i7 = *(undefined4 *)((iVar4 * 0x10 + 7) * 4 + 0x8000);
        unaff_l0 = *(uint *)((iVar4 * 0x10 + 8) * 4 + 0x8000);
        unaff_l1 = *(undefined4 *)((iVar4 * 0x10 + 9) * 4 + 0x8000);
        unaff_l2 = *(undefined4 *)((iVar4 * 0x10 + 10) * 4 + 0x8000);
        unaff_l3 = *(uint *)((iVar4 * 0x10 + 0xb) * 4 + 0x8000);
        unaff_l4 = *(undefined4 *)((iVar4 * 0x10 + 0xc) * 4 + 0x8000);
        unaff_l5 = *(undefined4 *)((iVar4 * 0x10 + 0xd) * 4 + 0x8000);
        unaff_l6 = *(undefined4 *)((iVar4 * 0x10 + 0xe) * 4 + 0x8000);
        unaff_l7 = *(undefined4 *)((iVar4 * 0x10 + 0xe) * 4 + 0x8000);
      }
      *(uint *)(_active_pcb + 0xc) =
           ((*(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                       (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) | unaff_l3) ^
           0xffffffff) & ~(-2 << ((byte)unaff_l6 & 0x1f));
      *(undefined4 *)(iVar2 + 0x230) = 1;
      iVar3 = *(int *)(iVar2 + 0x2a0);
      if ((unaff_l0 & 0x40) == 0) {
        *(undefined4 *)(iVar2 + 0x244) = unaff_l7;
        *(qword *)(iVar2 + 0x248) = CONCAT44(unaff_l5,unaff_l4);
        *(undefined8 *)(iVar2 + 0x250) = in_g4_5;
        *(undefined8 *)(iVar2 + 600) = in_g6_7;
        *(undefined4 *)(iVar2 + 0x240) = in_Y;
        *(qword *)(iVar2 + 0x260) = CONCAT44(unaff_i0,unaff_i1);
        *(qword *)(iVar2 + 0x268) = CONCAT44(unaff_i2,unaff_i3);
        *(qword *)(iVar2 + 0x270) = CONCAT44(unaff_i4,unaff_i5);
        *(qword *)(iVar2 + 0x278) = CONCAT44(unaff_fp,unaff_i7);
        *(uint *)(iVar2 + 0x234) = unaff_l0;
        *(undefined4 *)(iVar2 + 0x238) = unaff_l1;
        *(undefined4 *)(iVar2 + 0x23c) = unaff_l2;
        *(uint *)(iVar3 + 0x5c) = unaff_l0;
        iVar2 = iVar2 + 0x234;
      }
      else {
        *(undefined4 *)(iVar3 + 0x6c) = unaff_l7;
        *(qword *)(iVar3 + 0x70) = CONCAT44(unaff_l5,unaff_l4);
        *(undefined8 *)(iVar3 + 0x78) = in_g4_5;
        *(undefined8 *)(iVar3 + 0x80) = in_g6_7;
        *(undefined4 *)(iVar3 + 0x68) = in_Y;
        *(qword *)(iVar3 + 0x88) = CONCAT44(unaff_i0,unaff_i1);
        *(qword *)(iVar3 + 0x90) = CONCAT44(unaff_i2,unaff_i3);
        *(qword *)(iVar3 + 0x98) = CONCAT44(unaff_i4,unaff_i5);
        *(qword *)(iVar3 + 0xa0) = CONCAT44(unaff_fp,unaff_i7);
        *(uint *)(iVar3 + 0x5c) = unaff_l0;
        *(undefined4 *)(iVar3 + 0x60) = unaff_l1;
        *(undefined4 *)(iVar3 + 100) = unaff_l2;
        iVar2 = iVar3 + 0x5c;
      }
      _trap(9,iVar2);
      sys_rtt();
      return;
    }
    iVar4 = *(int *)(_active_pcb + 0x230) * 4 + _active_pcb;
    *(BADSPACEBASE **)(iVar4 + 0x210) = register0x00000038;
    puVar1 = (undefined8 *)((iVar4 - iVar2) * 0x10 + iVar2 + 0x10);
    *puVar1 = CONCAT44(unaff_l0,unaff_l1);
    puVar1[1] = CONCAT44(unaff_l2,unaff_l3);
    puVar1[2] = CONCAT44(unaff_l4,unaff_l5);
    puVar1[3] = CONCAT44(unaff_l6,unaff_l7);
    puVar1[4] = CONCAT44(unaff_i0,unaff_i1);
    puVar1[5] = CONCAT44(unaff_i2,unaff_i3);
    puVar1[6] = CONCAT44(unaff_i4,unaff_i5);
    puVar1[7] = CONCAT44(unaff_fp,unaff_i7);
    *(uint *)(_active_pcb + 0x230) = ((uint)((int)puVar1 - (iVar2 + 0x10)) >> 6) + 1;
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  if ((*(uint *)(_active_pcb + 0x294) & 1) == 0) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=2141 start=0xf0096b20 */

undefined4 _spl8(void)

{
  int in_TL;
  
  return *(undefined4 *)
          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008 +
          (uint)(in_TL == 4) * 0x700c);
}
/* GHIDRADEC_FUNCTION index=2142 start=0xf0096b3c */

void _splaudio(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0xd00) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2143 start=0xf0096b6c */

undefined4 _splzs(void)

{
  int in_TL;
  
  return *(undefined4 *)
          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008 +
          (uint)(in_TL == 4) * 0x700c);
}
/* GHIDRADEC_FUNCTION index=2144 start=0xf0096b88 */

void _splusclock(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0xa00) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2145 start=0xf0096bb8 */

void _spltty(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0x900) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2146 start=0xf0096be8 */

void _spl4(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0x800) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2147 start=0xf0096c18 */

void _spl3(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0x600) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2148 start=0xf0096c48 */

void _spl2(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0x400) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2149 start=0xf0096c78 */

undefined4 _spl1(void)

{
  int in_TL;
  
  return *(undefined4 *)
          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008 +
          (uint)(in_TL == 4) * 0x700c);
}

