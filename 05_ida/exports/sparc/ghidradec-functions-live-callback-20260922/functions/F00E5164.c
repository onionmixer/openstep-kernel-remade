
/* WARNING: Removing unreachable block (ram,0xf00e538c) */
/* WARNING: Removing unreachable block (ram,0xf00e532c) */
/* WARNING: Removing unreachable block (ram,0xf00e52d8) */
/* WARNING: Removing unreachable block (ram,0xf00e5288) */
/* WARNING: Removing unreachable block (ram,0xf00e5228) */
/* WARNING: Removing unreachable block (ram,0xf00e51d0) */
/* WARNING: Removing unreachable block (ram,0xf00e51f8) */
/* WARNING: Removing unreachable block (ram,0xf00e519c) */
/* WARNING: Removing unreachable block (ram,0xf00e51b4) */
/* WARNING: Removing unreachable block (ram,0xf00e520c) */
/* WARNING: Removing unreachable block (ram,0xf00e5264) */
/* WARNING: Removing unreachable block (ram,0xf00e52b8) */
/* WARNING: Removing unreachable block (ram,0xf00e5308) */
/* WARNING: Removing unreachable block (ram,0xf00e535c) */
/* WARNING: Removing unreachable block (ram,0xf00e53b0) */
/* WARNING: Removing unreachable block (ram,0xf00e5194) */

sqword _s24ConfigDisplay(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar10 = 0;
  puVar9 = (undefined4 *)(_sparcfbs + param_1 * 0x44 + 8);
  _prom_getprop(param_2,&aReg,(undefined *)((int)register0x00000038 + -0x1e8));
  uVar1 = param_2;
  _prom_parentnode();
  if (uVar1 == 0) {
    _panic(aCanTGetParentN);
  }
  else {
    uVar2 = uVar1;
    _prom_getproplen();
    if (uVar2 != 0) {
      _prom_getprop(uVar1,&aRanges,(undefined *)((int)register0x00000038 + -0x378));
      iVar10 = *(int *)((undefined *)((int)register0x00000038 + -0x378) +
                       *(int *)((int)register0x00000038 + -0x1e8) * 0x14 + 0xc);
    }
  }
  iVar3 = 0x100000;
  iVar11 = 0;
  _map_alloc(0x100000,_page_size);
  iVar4 = 0x100000;
  iVar7 = *(int *)((int)register0x00000038 + -0x1e4) + iVar10;
  udiv(0x100000,_page_size);
  iVar8 = iVar3;
  if (0 < iVar4) {
    do {
      iVar11 = iVar11 + 1;
      _pmap_enter_dev(_kernel_pmap,iVar8,iVar7,0,3,0,1);
      iVar7 = iVar7 + _page_size;
      iVar8 = iVar8 + _page_size;
    } while (iVar11 < iVar4);
  }
  uVar5 = 0x2000;
  _map_alloc(0x2000,_page_size);
  _pmap_enter_dev(_kernel_pmap,uVar5,*(int *)((int)register0x00000038 + -0x184) + iVar10,0,3,0,1);
  *puVar9 = 3;
  puVar9[1] = 0;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aWidth);
  if (uVar1 == 0) {
    uVar6 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar6 = 0x480;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aWidth,(undefined *)((int)register0x00000038 + -0x37c));
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0x37c);
  }
  else {
    uVar6 = 0x480;
  }
  puVar9[8] = uVar6;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aHeight);
  if (uVar1 == 0) {
    uVar6 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar6 = 900;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aHeight,(undefined *)((int)register0x00000038 + -0x37c));
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0x37c);
  }
  else {
    uVar6 = 900;
  }
  puVar9[9] = uVar6;
  puVar9[5] = iVar3;
  puVar9[6] = 0;
  puVar9[2] = 0;
  puVar9[3] = uVar5;
  uVar5 = puVar9[8];
  umul(uVar5,puVar9[9]);
  puVar9[7] = uVar5;
  puVar9[0xc] = 8;
  puVar9[0xd] = 1;
  uVar5 = puVar9[8];
  umul(uVar5,puVar9[0xd]);
  puVar9[0xe] = uVar5;
  return (qword)param_2 << 0x20;
}

