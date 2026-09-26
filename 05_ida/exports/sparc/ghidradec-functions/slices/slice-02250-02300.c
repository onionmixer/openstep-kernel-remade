/* GHIDRADEC_FUNCTION index=2250 start=0xf0097cdc */

undefined8 _lbcopytoz(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  uVar2 = 0;
  uVar3 = param_3;
  if (param_3 != 0) {
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = uVar2;
      if (cVar1 == '\0') break;
      *param_2 = cVar1;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      uVar3 = param_3;
    } while (uVar2 < param_3);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2251 start=0xf0097d24 */

/* WARNING: Removing unreachable block (ram,0xf0097da4) */
/* WARNING: Removing unreachable block (ram,0xf0097d44) */

undefined8 _copyinstr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _setjmp();
  if (puVar1 == (undefined *)0x0) {
    *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
    uVar4 = *(uint *)((int)register0x00000038 + -0x18);
    while( true ) {
      uVar6 = *(uint *)((int)register0x00000038 + 0x44);
      uVar3 = _page_size - (uVar6 & _page_size - 1U);
      *(uint *)((int)register0x00000038 + -0x14) = uVar4;
      if (uVar3 < uVar4) {
        *(uint *)((int)register0x00000038 + -0x14) = uVar3;
      }
      _lbcopytoz(uVar6,*(undefined4 *)((int)register0x00000038 + 0x48),
                 *(undefined4 *)((int)register0x00000038 + -0x14));
      iVar2 = *(int *)((int)register0x00000038 + -0x18);
      *(uint *)((int)register0x00000038 + -0x20) = uVar6;
      *(uint *)((int)register0x00000038 + -0x18) = iVar2 - uVar6;
      *(uint *)((int)register0x00000038 + 0x44) = *(int *)((int)register0x00000038 + 0x44) + uVar6;
      *(uint *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + uVar6;
      if ((uVar6 != *(uint *)((int)register0x00000038 + -0x14)) || (iVar2 - uVar6 == 0)) break;
      uVar4 = *(uint *)((int)register0x00000038 + -0x18);
    }
    *(undefined4 *)(_active_threads + 0x74) = 0;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 0xe;
  }
  iVar2 = *(int *)((int)register0x00000038 + -0x28);
  if (*(int *)((int)register0x00000038 + -0x18) == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 2;
    iVar2 = *(int *)((int)register0x00000038 + -0x28);
  }
  piVar5 = *(int **)((int)register0x00000038 + 0x50);
  if (iVar2 == 0) {
    **(undefined **)((int)register0x00000038 + 0x48) = 0;
    *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 1;
    piVar5 = *(int **)((int)register0x00000038 + 0x50);
  }
  if (piVar5 != (int *)0x0) {
    *piVar5 = *(int *)((int)register0x00000038 + 0x48) - *(int *)((int)register0x00000038 + -0x1c);
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x28));
}
/* GHIDRADEC_FUNCTION index=2252 start=0xf0097e5c */

/* WARNING: Removing unreachable block (ram,0xf0097e94) */
/* WARNING: Removing unreachable block (ram,0xf0097e84) */
/* WARNING: Removing unreachable block (ram,0xf0097ea0) */
/* WARNING: Removing unreachable block (ram,0xf0097eb4) */

sqword _copywithin(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if ((param_2 < 0xf0000000) || (_etext < param_2)) {
    _bcopy(param_1,param_2,param_3);
  }
  else {
    _pmap_change_prot(param_2,7);
    _bcopy(param_1,param_2,param_3);
    _pmap_change_prot(param_2,1);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2253 start=0xf0097ec4 */

undefined8 _copystr(char *param_1,char *param_2,uint param_3,uint *param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  uVar2 = 0;
  if (param_3 == 0) {
loc_F0097F1C:
    if (param_4 != (uint *)0x0) {
      *param_4 = param_3;
    }
    uVar3 = 2;
  }
  else {
    cVar1 = *param_1;
    while( true ) {
      *param_2 = cVar1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if (cVar1 == '\0') break;
      uVar2 = uVar2 + 1;
      if (param_3 <= uVar2) goto loc_F0097F1C;
      cVar1 = *param_1;
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar2 + 1;
    }
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2254 start=0xf0097f30 */

/* WARNING: Removing unreachable block (ram,0xf0097fb0) */
/* WARNING: Removing unreachable block (ram,0xf0097f50) */

undefined8 _copyoutstr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _setjmp();
  if (puVar1 == (undefined *)0x0) {
    *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
    uVar5 = *(uint *)((int)register0x00000038 + -0x18);
    while( true ) {
      uVar4 = _page_size - (*(uint *)((int)register0x00000038 + 0x48) & _page_size - 1U);
      *(uint *)((int)register0x00000038 + -0x14) = uVar5;
      if (uVar4 < uVar5) {
        *(uint *)((int)register0x00000038 + -0x14) = uVar4;
      }
      iVar2 = *(int *)((int)register0x00000038 + 0x44);
      _lbcopytoz(iVar2,*(uint *)((int)register0x00000038 + 0x48),
                 *(undefined4 *)((int)register0x00000038 + -0x14));
      iVar3 = *(int *)((int)register0x00000038 + -0x18);
      iVar7 = *(int *)((int)register0x00000038 + 0x48);
      *(int *)((int)register0x00000038 + -0x20) = iVar2;
      *(int *)((int)register0x00000038 + -0x18) = iVar3 - iVar2;
      *(int *)((int)register0x00000038 + 0x44) = *(int *)((int)register0x00000038 + 0x44) + iVar2;
      *(int *)((int)register0x00000038 + 0x48) = iVar7 + iVar2;
      if ((iVar2 != *(int *)((int)register0x00000038 + -0x14)) || (iVar3 - iVar2 == 0)) break;
      uVar5 = *(uint *)((int)register0x00000038 + -0x18);
    }
    *(undefined *)(iVar7 + iVar2) = 0;
    *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 1;
    *(undefined4 *)(_active_threads + 0x74) = 0;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 0xe;
  }
  piVar6 = *(int **)((int)register0x00000038 + 0x50);
  if (*(int *)((int)register0x00000038 + -0x18) == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 2;
    piVar6 = *(int **)((int)register0x00000038 + 0x50);
  }
  if (piVar6 != (int *)0x0) {
    *piVar6 = *(int *)((int)register0x00000038 + 0x48) - *(int *)((int)register0x00000038 + -0x1c);
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x28));
}
/* GHIDRADEC_FUNCTION index=2255 start=0xf0098058 */

/* WARNING: Removing unreachable block (ram,0xf0098094) */
/* WARNING: Removing unreachable block (ram,0xf0098068) */

undefined8 _copyin(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _setjmp();
  uVar4 = 0xe;
  if (puVar1 == (undefined *)0x0) {
    uVar4 = *(undefined4 *)((int)register0x00000038 + 0x44);
    uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
    uVar3 = *(undefined4 *)((int)register0x00000038 + 0x4c);
    *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
    _bcopy(uVar4,uVar2,uVar3);
    uVar4 = 0;
    *(undefined4 *)(_active_threads + 0x74) = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2256 start=0xf00980b0 */

/* WARNING: Removing unreachable block (ram,0xf00980bc) */

undefined8 _copyinmsg(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _copyin(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2257 start=0xf00980cc */

/* WARNING: Removing unreachable block (ram,0xf0098108) */
/* WARNING: Removing unreachable block (ram,0xf00980dc) */

undefined8 _copyout(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _setjmp();
  uVar4 = 0xe;
  if (puVar1 == (undefined *)0x0) {
    uVar4 = *(undefined4 *)((int)register0x00000038 + 0x44);
    uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
    uVar3 = *(undefined4 *)((int)register0x00000038 + 0x4c);
    *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
    _bcopy(uVar4,uVar2,uVar3);
    uVar4 = 0;
    *(undefined4 *)(_active_threads + 0x74) = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2258 start=0xf0098124 */

/* WARNING: Removing unreachable block (ram,0xf0098130) */

undefined8 _copyoutmsg(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _copyout(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2259 start=0xf0098140 */

/* WARNING: Removing unreachable block (ram,0xf009818c) */
/* WARNING: Removing unreachable block (ram,0xf0098154) */
/* WARNING: Removing unreachable block (ram,0xf00981b4) */
/* WARNING: Removing unreachable block (ram,0xf0098148) */

undefined8 _map_wellknown_devices(undefined4 param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  undefined4 unaff_l0;
  undefined6 **ppuVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
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
  iVar3 = 0;
  _prom_nextnode(0);
  sub_F00981D0();
  ppuVar2 = &off_F0112DF4;
  puVar1 = (undefined6 *)DAT_f0112dfc._0_4_;
  if (off_F0112DF4 != (undefined6 *)0x0) {
    while( true ) {
      if (((uint)puVar1 & 6) == 0) {
        iVar3 = iVar3 + 1;
        _prom_printf(aRequiredDevice,*ppuVar2);
      }
      if (ppuVar2[3] == (undefined6 *)0x0) break;
      puVar1 = ppuVar2[5];
      ppuVar2 = ppuVar2 + 3;
    }
  }
  if (iVar3 != 0) {
    _panic(aMapWellknownDe);
  }
  _utimersp = 0xfeff9000;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2260 start=0xf0098540 */

/* WARNING: Removing unreachable block (ram,0xf00985e4) */
/* WARNING: Removing unreachable block (ram,0xf00985ec) */
/* WARNING: Removing unreachable block (ram,0xf00985ac) */

undefined8 _fill_machinfo(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  DAT_f0112a3c = _sysname;
  _mach_info = 0x71;
  DAT_f0112a58._0_4_ = _mcname;
  _mcname[0] = 0;
  _mmc_info._0_4_ = 0xffffffff;
  uVar6 = 0;
  puVar4 = _modname;
  puVar2 = &_mod_info;
  do {
    puVar2[1] = puVar4;
    puVar4 = puVar4 + 0x28;
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 0x1d;
  } while (uVar6 < 4);
  uVar3 = 0;
  _prom_nextnode(0);
  puVar4 = _sysname;
  iVar5 = 0x27;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    bVar1 = 0 < iVar5;
    iVar5 = iVar5 + -1;
  } while (bVar1);
  _prom_getprop(uVar3,&_psname,DAT_f0112a3c);
  _fill_node(uVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2261 start=0xf00985fc */

/* WARNING: Removing unreachable block (ram,0xf0098604) */

undefined8 _fill_hostidinfo(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _prom_getidprom((undefined *)((int)register0x00000038 + -0x28),0x20);
  if (*(char *)((int)register0x00000038 + -0x28) == '\x01') {
    _hostid = (uint)*(byte *)((int)register0x00000038 + -0x27) << 0x18 |
              *(uint *)((int)register0x00000038 + -0x1c) >> 8;
  }
  else {
    _hostid = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2262 start=0xf0098648 */

/* WARNING: Removing unreachable block (ram,0xf009875c) */
/* WARNING: Removing unreachable block (ram,0xf009872c) */
/* WARNING: Removing unreachable block (ram,0xf00986d4) */
/* WARNING: Removing unreachable block (ram,0xf00986a0) */
/* WARNING: Removing unreachable block (ram,0xf009865c) */
/* WARNING: Removing unreachable block (ram,0xf0098664) */
/* WARNING: Removing unreachable block (ram,0xf00986ec) */
/* WARNING: Removing unreachable block (ram,0xf0098774) */
/* WARNING: Removing unreachable block (ram,0xf009864c) */

undefined8 _fill_node(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined auStack_30 [48];
  
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
  iVar2 = param_1;
  _prom_childnode();
  while (puVar3 = (undefined *)((int)register0x00000038 + -0x30), iVar2 != 0) {
    _fill_node(iVar2);
    _prom_nextnode();
  }
  iVar2 = 0x27;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  iVar2 = param_1;
  _prom_getprop(param_1,&_psname,(undefined *)((int)register0x00000038 + -0x30));
  if (iVar2 != -1) {
    puVar3 = unk_F01133F8;
    iVar2 = unk_F01133F8._0_4_;
    while( true ) {
      _strncmp(iVar2,(undefined *)((int)register0x00000038 + -0x30),*(int *)((int)puVar3 + 4));
      if (iVar2 == 0) goto loc_f00986e8;
      puVar3 = (undefined *)((int)puVar3 + 0x14);
      if (unk_F01133F8 + 0x4f < puVar3) break;
      iVar2 = *(int *)puVar3;
    }
    puVar3 = (undefined *)((int)register0x00000038 + -0x30);
    iVar2 = 0x27;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
      bVar1 = 0 < iVar2;
      iVar2 = iVar2 + -1;
    } while (bVar1);
    iVar2 = param_1;
    _prom_getprop(param_1,_psdevtype,(undefined *)((int)register0x00000038 + -0x30));
    if (iVar2 == -1) goto locret_F009878C;
    puVar3 = unk_F0113448;
    iVar2 = unk_F0113448._0_4_;
    while (_strncmp(iVar2,(undefined *)((int)register0x00000038 + -0x30),*(int *)((int)puVar3 + 4)),
          iVar2 != 0) {
      puVar3 = (undefined *)((int)puVar3 + 0x14);
      if (unk_F0113448 + 0x27 < puVar3) goto locret_F009878C;
      iVar2 = *(int *)puVar3;
    }
    _fill_modinfo(param_1,puVar3);
  }
locret_F009878C:
  return CONCAT44(param_2,param_1);
loc_f00986e8:
  _fill_nodeinfo(param_1,puVar3);
  goto locret_F009878C;
}
/* GHIDRADEC_FUNCTION index=2263 start=0xf0098794 */

/* WARNING: Removing unreachable block (ram,0xf00987f4) */
/* WARNING: Removing unreachable block (ram,0xf0098808) */

undefined8 _fill_nodeinfo(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  undefined4 *puVar7;
  undefined4 unaff_l3;
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
  piVar4 = *(int **)(param_2 + 0x10);
  if (piVar4 == (int *)0x0) {
    puVar7 = *(undefined4 **)(param_2 + 8);
  }
  else {
    *piVar4 = *piVar4 + 1;
    puVar7 = *(undefined4 **)(param_2 + 8);
  }
  if (puVar7 < *(undefined4 **)(param_2 + 0xc)) {
    puVar6 = puVar7 + 2;
    do {
      uVar1 = puVar6[-1];
      if (uVar1 == 1) {
        uVar5 = *puVar7;
loc_F00987F0:
        _prom_getprop(param_1,uVar5,*puVar6);
        puVar2 = *(undefined4 **)(param_2 + 0xc);
      }
      else if (uVar1 < 2) {
        iVar3 = param_1;
        _prom_getproplen(param_1,*puVar7);
        if (iVar3 == -1) {
          *(undefined4 *)*puVar6 = 0;
        }
        else {
          *(undefined4 *)*puVar6 = 1;
        }
        puVar2 = *(undefined4 **)(param_2 + 0xc);
      }
      else {
        if (uVar1 == 2) {
          uVar5 = *puVar7;
          goto loc_F00987F0;
        }
        puVar2 = *(undefined4 **)(param_2 + 0xc);
      }
      puVar7 = puVar7 + 3;
      puVar6 = puVar6 + 3;
    } while (puVar7 < puVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2264 start=0xf0098844 */

/* WARNING: Removing unreachable block (ram,0xf00988c8) */
/* WARNING: Removing unreachable block (ram,0xf00988bc) */
/* WARNING: Removing unreachable block (ram,0xf0098a0c) */
/* WARNING: Removing unreachable block (ram,0xf00988a4) */

undefined8 _fill_modinfo(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool bVar7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined auStack_30 [48];
  
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
  puVar6 = (undefined *)((int)register0x00000038 + -0x30);
  iVar5 = 0x27;
  iVar2 = dword_F0112A40 * 0x74;
  iVar1 = dword_F0112A40 * 0x1d;
  do {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    bVar7 = 0 < iVar5;
    iVar5 = iVar5 + -1;
  } while (bVar7);
  iVar5 = param_1;
  dword_F0112A40 = dword_F0112A40 + 1;
  _prom_getprop(param_1,&_psname,(undefined *)((int)register0x00000038 + -0x30));
  if (iVar5 != -1) {
    _strcpy(*(undefined4 *)(DAT_f0112a68 + iVar2),(undefined *)((int)register0x00000038 + -0x30));
    _fill_nodeinfo(param_1,param_2);
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x3c) = dword_F0112F5C;
    uVar4 = dword_F0112F60;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 4) = dword_F0112F2C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x40) = uVar4;
    uVar4 = dword_F0112F30;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x44) = dword_F0112F64;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0xc) = uVar4;
    uVar4 = dword_F0112F58;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x10) = dword_F0112F34;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x34) = uVar4;
    uVar4 = dword_F0112F3C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x14) = dword_F0112F38;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x18) = uVar4;
    uVar4 = dword_F0112F44;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x1c) = dword_F0112F40;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x20) = uVar4;
    uVar4 = dword_F0112F50;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x30) = dword_F0112F54;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x2c) = uVar4;
    uVar4 = dword_F0112F48;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x28) = dword_F0112F4C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x24) = uVar4;
    uVar4 = dword_F0112F6C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x48) = dword_F0112F68;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x4c) = uVar4;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x50) = dword_F0112F70;
    uVar4 = dword_F0112F78;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x54) = dword_F0112F74;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x58) = uVar4;
    uVar4 = dword_F0112F80;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x5c) = dword_F0112F7C;
    iVar5 = dword_F0112F84;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x60) = uVar4;
    uVar4 = dword_F0112F88;
    *(int *)(DAT_f0112a68 + iVar2 + 100) = iVar5;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x68) = uVar4;
    uVar3 = dword_F0112F90;
    bVar7 = dword_F0112F90 == 0;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x6c) = dword_F0112F8C;
    if (bVar7) {
      _getpsr();
      if (uVar3 >> 0x18 == 4) {
        (&_mod_info)[iVar1] = 4;
      }
      else {
        uVar4 = 0x41;
        if (dword_F0112F84 == 0) {
          uVar4 = 0x40;
        }
        (&_mod_info)[iVar1] = uVar4;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2265 start=0xf0098a44 */

undefined8 _sun4m_memerr_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if ((word_F0112E0A & 2) != 0) {
    if (_report_ce == 0) {
      _efervalue = _efervalue | 1;
    }
    else {
      _efervalue = _efervalue | 3;
    }
    param_1 = 0xfefef000;
    uRamfefef000 = uRamfefef000 | _efervalue;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2266 start=0xf0098aa4 */

undefined8 _sun4m_ebe_handler(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2267 start=0xf0098ab0 */

/* WARNING: Removing unreachable block (ram,0xf0098acc) */
/* WARNING: Removing unreachable block (ram,0xf0098ab4) */

undefined8 _fpu_ctxalloc(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  puVar1 = (undefined4 *)0x110;
  _kalloc();
  if (puVar1 == (undefined4 *)0x0) {
    _panic(aCanTAllocateFp);
    uRam00000080 = 0;
  }
  else {
    puVar1[0x20] = 0;
  }
  *puVar1 = 0xffffffff;
  puVar1[1] = 0xffffffff;
  puVar1[2] = 0xffffffff;
  puVar1[3] = 0xffffffff;
  puVar1[4] = 0xffffffff;
  puVar1[5] = 0xffffffff;
  puVar1[6] = 0xffffffff;
  puVar1[7] = 0xffffffff;
  puVar1[8] = 0xffffffff;
  puVar1[9] = 0xffffffff;
  puVar1[10] = 0xffffffff;
  puVar1[0xb] = 0xffffffff;
  puVar1[0xc] = 0xffffffff;
  puVar1[0xd] = 0xffffffff;
  puVar1[0xe] = 0xffffffff;
  puVar1[0xf] = 0xffffffff;
  puVar1[0x10] = 0xffffffff;
  puVar1[0x11] = 0xffffffff;
  puVar1[0x12] = 0xffffffff;
  puVar1[0x13] = 0xffffffff;
  puVar1[0x14] = 0xffffffff;
  puVar1[0x15] = 0xffffffff;
  puVar1[0x16] = 0xffffffff;
  puVar1[0x17] = 0xffffffff;
  puVar1[0x18] = 0xffffffff;
  puVar1[0x19] = 0xffffffff;
  puVar1[0x1a] = 0xffffffff;
  puVar1[0x1b] = 0xffffffff;
  puVar1[0x1c] = 0xffffffff;
  puVar1[0x1d] = 0xffffffff;
  puVar1[0x1e] = 0xffffffff;
  puVar1[0x1f] = 0xffffffff;
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2268 start=0xf0098b64 */

/* WARNING: Removing unreachable block (ram,0xf0098b8c) */

undefined8 _fpu_ctxfree(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (*(int *)(param_1 + 0x284) != 0) {
    if (_fp_ctxp == *(int *)(param_1 + 0x284)) {
      _fp_ctxp = 0;
    }
    _kfree(*(undefined4 *)(param_1 + 0x284),0x110);
    *(undefined4 *)(param_1 + 0x284) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2269 start=0xf0098ba0 */

/* WARNING: Removing unreachable block (ram,0xf0098bec) */
/* WARNING: Removing unreachable block (ram,0xf0098c00) */
/* WARNING: Removing unreachable block (ram,0xf0098be4) */

undefined8 _fpu_fork_context(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar2 = *(int *)(param_1 + 0x284);
  puVar3 = (uint *)(*(int *)(_active_threads + 0x28) + 0x234);
  if (iVar2 != 0) {
    iVar1 = 0x1000;
    if ((_fpu_exists != 0) && ((*(uint *)(*(int *)(_active_threads + 0x28) + 0x234) & 0x1000) != 0))
    {
      _fp_dumpregs();
      iVar1 = iVar2;
    }
    _fpu_ctxalloc();
    *(int *)(param_2 + 0x284) = iVar1;
    _bcopy(*(undefined4 *)(param_1 + 0x284),iVar1,0x110);
    _fp_ctxp = 0;
    *puVar3 = *puVar3 & 0xffffefff;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2270 start=0xf0098c28 */

/* WARNING: Removing unreachable block (ram,0xf0098cc4) */
/* WARNING: Removing unreachable block (ram,0xf0098cd4) */
/* WARNING: Removing unreachable block (ram,0xf0098ca0) */

undefined8 _fp_traps(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _fptraprp;
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
  if (_fptraprp != 0) {
    _fptraprp = 0;
    param_3 = iVar1;
  }
  if (param_2 == 3) {
    uVar2 = 2;
loc_F0098CBC:
    uVar3 = *(undefined4 *)(param_1 + 0x20);
    uVar4 = 0;
loc_F0098CC4:
    _trap(uVar2,param_3,uVar3,uVar4,0);
  }
  else {
    if (param_2 < 4) {
      if (param_2 == 1) {
        uVar3 = *(undefined4 *)(param_1 + 0x20);
        uVar2 = 8;
        uVar4 = *(undefined4 *)(param_1 + 0x1c);
        goto loc_F0098CC4;
      }
    }
    else {
      if (param_2 == 5) {
        uVar2 = 7;
        goto loc_F0098CBC;
      }
      if (param_2 == 6) {
        _trap(9,param_3,*(undefined4 *)(param_1 + 0x20),_beval,*(undefined4 *)(param_1 + 0x28));
        goto loc_F0098CE0;
      }
    }
    _panic(aFpTrapsBadFtt);
  }
loc_F0098CE0:
  _fptraprp = iVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2271 start=0xf0098cec */

/* WARNING: Removing unreachable block (ram,0xf0098d64) */
/* WARNING: Removing unreachable block (ram,0xf0098d8c) */
/* WARNING: Removing unreachable block (ram,0xf0098d70) */
/* WARNING: Removing unreachable block (ram,0xf0098da0) */
/* WARNING: Removing unreachable block (ram,0xf0098d54) */
/* WARNING: Removing unreachable block (ram,0xf0098d0c) */

undefined8 _fp_is_disabled(uint *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
  undefined4 unaff_l3;
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
  puVar2 = *(undefined **)(*(int *)(_active_threads + 0x28) + 0x284);
  puVar1 = DAT_f0113400;
  if (puVar2 == (undefined *)0x0) {
    _fpu_ctxalloc();
    *(undefined **)(*(int *)(_active_threads + 0x28) + 0x284) = puVar1;
    puVar2 = puVar1;
  }
  _fp_ctxp = puVar2;
  if (_fpu_exists == 0) {
    _flush_user_windows_to_stack();
    puVar3 = (undefined *)((int)register0x00000038 + -0x38);
    puVar1 = puVar3;
    _fp_emulator(puVar3,param_1[1],param_1,param_1[0x11],puVar2);
    if (puVar1 != (undefined *)0x0) {
      _fp_traps(puVar3,puVar1,param_1);
    }
  }
  else if ((*param_1 & 0x1000) == 0) {
    *param_1 = *param_1 | 0x1000;
    _fp_enable(puVar2);
  }
  else {
    _panic(aFpDisabledNoFp);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2272 start=0xf0098db0 */

/* WARNING: Removing unreachable block (ram,0xf0098e60) */
/* WARNING: Removing unreachable block (ram,0xf0098e0c) */
/* WARNING: Removing unreachable block (ram,0xf0098e1c) */
/* WARNING: Removing unreachable block (ram,0xf0098e78) */
/* WARNING: Removing unreachable block (ram,0xf0098dec) */

undefined8 _fp_runq(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  iVar4 = *(int *)(*(int *)(_active_threads + 0x28) + 0x284);
  puVar3 = (undefined4 *)(iVar4 + 0x90);
  if (*(int *)(iVar4 + 0x8c) != 0) {
    puVar5 = (undefined *)((int)register0x00000038 + -0x38);
    do {
      puVar1 = puVar5;
      _fpu_simulator(puVar5,*puVar3,iVar4 + 0x80,puVar3[1]);
      if (puVar1 != (undefined *)0x0) {
        if (_fpu_exists != 0) {
          __fp_write_pfsr(iVar4 + 0x80);
        }
        _fp_traps(puVar5,puVar1,param_1);
        break;
      }
      puVar3 = puVar3 + 2;
      iVar2 = *(int *)(iVar4 + 0x8c) + -1;
      *(int *)(iVar4 + 0x8c) = iVar2;
    } while (iVar2 != 0);
  }
  uVar6 = 0;
  iVar2 = iVar4;
  if (_fpu_exists != 0) {
    do {
      __fp_read_pfreg(iVar2,uVar6);
      uVar6 = uVar6 + 1;
      iVar2 = iVar2 + 4;
    } while (uVar6 < 0x20);
    __fp_write_pfsr(iVar4 + 0x80);
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=2273 start=0xf0098e88 */

/* WARNING: Removing unreachable block (ram,0xf0098f8c) */
/* WARNING: Removing unreachable block (ram,0xf0098f78) */
/* WARNING: Removing unreachable block (ram,0xf0098fec) */
/* WARNING: Removing unreachable block (ram,0xf0098f30) */
/* WARNING: Removing unreachable block (ram,0xf0098eb0) */
/* WARNING: Type propagation algorithm not settling */

qword _in_cksum(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 unaff_l3;
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
  pbVar6 = (byte *)0x0;
  if (((int)*(sword *)(param_1 + 2) < (int)param_2) || ((param_2 & 1) != 0)) {
    uVar2 = 0;
    iVar3 = param_1[1];
    while( true ) {
      pbVar5 = (byte *)((int)param_1 + iVar3);
      if (uVar2 == 0xffffffff) {
        pbVar5 = pbVar5 + 1;
        param_2 = param_2 - 1;
        pbVar6 = pbVar6 + *(byte *)((int)param_1 + iVar3);
        uVar2 = (int)*(sword *)(param_1 + 2) - 1;
      }
      else {
        uVar2 = (uint)*(sword *)(param_1 + 2);
      }
      param_1 = (undefined4 *)*param_1;
      if ((int)param_2 < (int)uVar2) {
        uVar2 = param_2;
      }
      param_2 = param_2 - uVar2;
      if (0 < (int)uVar2) {
        if (((uint)pbVar5 & 1) == 0) {
          iVar3 = (int)uVar2 >> 1;
          pbVar4 = pbVar5;
          _ocsum(pbVar5,iVar3);
          pbVar6 = pbVar6 + (int)pbVar4;
          if ((uVar2 & 1) != 0) {
            uVar2 = 0xffffffff;
            pbVar6 = pbVar6 + (uint)pbVar5[iVar3 * 2] * 0x100;
          }
        }
        else {
          uVar2 = uVar2 - 1;
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          pbVar4 = pbVar5;
          _ocsum(pbVar5,(int)uVar2 >> 1);
          *(sword *)((int)register0x00000038 + -10) = (sword)pbVar4;
          _swab((undefined *)((int)register0x00000038 + -10),
                (undefined *)((int)register0x00000038 + -10),2);
          pbVar6 = pbVar6 + (uint)*(word *)((int)register0x00000038 + -10) + (uint)bVar1 * 0x100;
          if ((uVar2 & 1) == 0) {
            uVar2 = 0xffffffff;
          }
          else {
            pbVar6 = pbVar6 + pbVar5[((int)uVar2 >> 1) * 2];
          }
        }
      }
      if (param_2 == 0) break;
      while( true ) {
        if (param_1 == (undefined4 *)0x0) {
          _printf(aCksumOutOfData);
          goto loc_F0098FF8;
        }
        if (*(sword *)(param_1 + 2) != 0) break;
        param_1 = (undefined4 *)*param_1;
      }
      iVar3 = param_1[1];
    }
loc_F0098FF8:
    uVar2 = ((uint)pbVar6 & 0xffff) + ((int)pbVar6 >> 0x10);
    uVar2 = (uVar2 & 0xffff) + ((int)uVar2 >> 0x10);
  }
  else {
    uVar2 = (int)param_1 + param_1[1];
    _ocsum(uVar2,(int)param_2 >> 1);
  }
  return CONCAT44(param_2,~uVar2) & 0xffffffff0000ffff;
}
/* GHIDRADEC_FUNCTION index=2274 start=0xf0099020 */

/* WARNING: Removing unreachable block (ram,0xf009904c) */
/* WARNING: Removing unreachable block (ram,0xf0099030) */

undefined8 _not_serviced(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar1 = *param_1;
  *param_1 = iVar1 + 1;
  .rem(iVar1,100);
  if (iVar1 == 1) {
    _printf(aLevelDSinterru,param_2,param_3);
  }
  return CONCAT44(param_2,0xffffffff);
}
/* GHIDRADEC_FUNCTION index=2275 start=0xf009905c */

/* WARNING: Removing unreachable block (ram,0xf0099104) */
/* WARNING: Removing unreachable block (ram,0xf00990b8) */
/* WARNING: Removing unreachable block (ram,0xf009909c) */
/* WARNING: Removing unreachable block (ram,0xf00990dc) */
/* WARNING: Removing unreachable block (ram,0xf0099124) */
/* WARNING: Removing unreachable block (ram,0xf0099074) */

undefined8
_addintr(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_2 != 0) {
    if ((int *)0x4f < param_1) {
      _panic(aAddintrVectorN);
    }
    param_1 = *(int **)(_vectorlist + (int)param_1 * 4);
    if (param_1 == (int *)0x0) {
      _panic(aAddintrSpecifi);
      iVar1 = iRam0000000c;
    }
    else {
      iVar1 = param_1[3];
    }
    if (iVar1 == -1) {
      _panic(aAddintrInterru);
    }
    iVar1 = 0;
    piVar2 = param_1 + 5;
    do {
      if (*param_1 == 0) {
        _bzero(param_1,0x18);
        *param_1 = param_2;
        piVar2[-1] = param_5;
        *piVar2 = param_6;
loc_F00990FC:
        sub_F009921C(param_1,param_3,param_4);
        goto locret_F009912C;
      }
      piVar2 = piVar2 + 6;
      if (*param_1 == param_2) goto loc_F00990FC;
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 6;
    } while (iVar1 < 10);
    _panic(aAddintrTooMany);
  }
locret_F009912C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2276 start=0xf0099134 */

/* WARNING: Removing unreachable block (ram,0xf0099174) */
/* WARNING: Removing unreachable block (ram,0xf0099208) */
/* WARNING: Removing unreachable block (ram,0xf009914c) */

undefined8 _remintr(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  if (param_2 != 0) {
    if (0x4f < param_1) {
      _panic(aRemintrVectorN);
    }
    piVar3 = *(int **)(_vectorlist + param_1 * 4);
    iVar2 = 0;
    if (piVar3 == (int *)0x0) {
      _panic(aRemintrSpecifi);
      iVar2 = 0;
    }
loc_F0099180:
    if (*piVar3 != 0) {
      iVar2 = iVar2 + 1;
      if (*piVar3 != param_2) goto loc_F00991F4;
      if (iVar2 < 10) {
        piVar1 = piVar3 + 5;
        do {
          iVar2 = iVar2 + 1;
          *piVar3 = piVar1[1];
          piVar3 = piVar3 + 6;
          piVar1[-4] = piVar1[2];
          piVar1[-3] = piVar1[3];
          piVar1[-2] = piVar1[4];
          piVar1[-1] = piVar1[5];
          *piVar1 = piVar1[6];
          piVar1 = piVar1 + 6;
        } while (iVar2 < 10);
        goto loc_F00991EC;
      }
      uVar4 = 0;
      goto locret_F0099214;
    }
    goto loc_F0099200;
  }
loc_F00991EC:
  uVar4 = 0;
locret_F0099214:
  return CONCAT44(param_2,uVar4);
loc_F00991F4:
  piVar3 = piVar3 + 6;
  if (9 < iVar2) goto loc_F0099200;
  goto loc_F0099180;
loc_F0099200:
  _printf(aRemintrDriverN,param_1);
  uVar4 = 0xffffffff;
  goto locret_F0099214;
}
/* GHIDRADEC_FUNCTION index=2277 start=0xf009927c */

/* WARNING: Removing unreachable block (ram,0xf0099358) */
/* WARNING: Removing unreachable block (ram,0xf009930c) */
/* WARNING: Removing unreachable block (ram,0xf00992e8) */

undefined8 _buscheck(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  uint *puVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar7;
  undefined4 unaff_l6;
  undefined4 uVar8;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar8 = _kernel_pmap;
  if ((*param_1 & 0x10) != 0) {
    uVar8 = *(undefined4 *)(*(int *)(*(int *)(param_1[0xb] + 0x68) + 0xc) + 0x24);
  }
  uVar7 = 0xffffffff;
  uVar3 = 0xffffffff;
  uVar4 = 0xffffffff;
  uVar1 = param_1[8];
  puVar5 = (uint *)((int)register0x00000038 + -0xc);
  uVar6 = param_1[5] + (uVar1 & 0xfff) + 0xfff >> 0xc;
  if (uVar6 != 0) {
    do {
      _pmap_getpte(uVar8,uVar1,puVar5);
      uVar2 = *puVar5;
      if (uVar4 == 0xffffffff) {
        uVar3 = uVar2 >> 8;
        if ((uVar2 & 3) != 2) {
loc_F0099340:
          uVar7 = 0xffffffff;
          break;
        }
        uVar4 = uVar3;
        _bustype();
        uVar7 = uVar3;
        if (uVar4 == 2) {
          uVar7 = 0;
        }
        uVar3 = uVar3 + 1;
      }
      else {
        if ((uVar2 & 3) != 2) {
          uVar7 = 0xffffffff;
          break;
        }
        uVar2 = uVar2 >> 8;
        _bustype();
        if (uVar4 != uVar2) {
          uVar7 = 0xffffffff;
          break;
        }
        if (uVar4 == 2) {
          uVar3 = uVar3 + 1;
        }
        else {
          bVar9 = *puVar5 >> 8 != uVar3;
          uVar3 = uVar3 + 1;
          if (bVar9) goto loc_F0099340;
        }
      }
      uVar6 = uVar6 - 1;
      uVar1 = uVar1 + 0x1000;
    } while (0 < (int)uVar6);
  }
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=2278 start=0xf0099394 */

/* WARNING: Removing unreachable block (ram,0xf00994a8) */
/* WARNING: Removing unreachable block (ram,0xf00993ec) */
/* WARNING: Removing unreachable block (ram,0xf0099494) */
/* WARNING: Removing unreachable block (ram,0xf00994b4) */
/* WARNING: Removing unreachable block (ram,0xf00993dc) */

undefined8
_bp_alloc(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  iVar4 = 0;
  uVar5 = 0xffffffff;
  uVar1 = 0;
  if (_vac != 0) {
    param_2 = *(uint *)(param_2 + 0x20);
    uVar1 = 0xf0119000;
    if (param_2 != 0) {
      uVar1 = param_2 & _shm_alignment - 1;
      uVar5 = uVar1 >> 0xc;
    }
  }
  if (uVar5 == 0xffffffff) {
    _splusclock();
    _rmalloc(param_1,param_3);
  }
  else {
    if (_vac != 0) {
      param_6 = (_shm_alignment >> 0xc) - 1;
    }
    puVar3 = (uint *)(param_1 + 8);
    if (*(int *)(param_1 + 8) != 0) {
      uVar1 = *puVar3;
      while( true ) {
        if (param_3 <= (int)uVar1) {
          uVar2 = puVar3[1];
          iVar4 = (uVar2 & ~param_6) + uVar5;
          if (iVar4 < (int)uVar2) {
            iVar4 = iVar4 + 1 + param_6;
          }
          if (iVar4 + param_3 <= (int)(uVar2 + uVar1)) {
            uVar1 = *puVar3;
            goto loc_F0099488;
          }
        }
        puVar3 = puVar3 + 2;
        if (*puVar3 == 0) break;
        uVar1 = *puVar3;
      }
    }
    uVar1 = *puVar3;
loc_F0099488:
    iVar6 = 0;
    if (uVar1 == 0) goto locret_F00994BC;
    _splusclock();
    _rmget(param_1,param_3,iVar4);
  }
  _splx(uVar1);
  iVar6 = param_1;
  param_2 = uVar1;
locret_F00994BC:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=2279 start=0xf00994c4 */

/* WARNING: Removing unreachable block (ram,0xf009955c) */
/* WARNING: Removing unreachable block (ram,0xf00994e4) */
/* WARNING: Removing unreachable block (ram,0xf00995c0) */
/* WARNING: Removing unreachable block (ram,0xf00994cc) */

undefined8 _bp_iom_map(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint *puVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
  _iom_ptefind(param_2,param_4);
  if (param_2 == (uint *)0x0) {
    _panic(aBpIomMapBadIop);
    uVar1 = *param_1;
  }
  else {
    uVar1 = *param_1;
  }
  uVar3 = _kernel_pmap;
  if ((uVar1 & 0x10) != 0) {
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_1[0xb] + 0x68) + 0xc) + 0x24);
  }
  uVar2 = param_1[8];
  puVar5 = (uint *)((int)register0x00000038 + -0xc);
  uVar4 = param_1[5] + (uVar2 & 0xfff) + 0xfff >> 0xc;
  uVar1 = 0;
  if (uVar4 != 0) {
    do {
      _pmap_getpte(uVar3,uVar2,puVar5);
      uVar1 = *puVar5;
      bVar6 = _cache == 0;
      *param_2 = uVar1;
      if (bVar6) {
        *param_2 = uVar1 & 0xffffff7f;
      }
      if ((_vac != 0) &&
         (((DAT_f0112a98._0_4_ == 0 || (_dvma_incoherent._0_4_ != 0)) && ((*param_2 & 0x80) != 0))))
      {
        _pmap_vacflush(*puVar5 >> 8);
        *param_2 = *param_2 & 0xffffff7f;
      }
      uVar1 = uVar4 - 1;
      param_2 = param_2 + 1;
      uVar2 = uVar2 + 0x1000;
      uVar4 = uVar1;
    } while (0 < (int)uVar1);
  }
  *param_2 = 0;
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2280 start=0xf00995f4 */

/* WARNING: Removing unreachable block (ram,0xf009974c) */
/* WARNING: Removing unreachable block (ram,0xf009973c) */
/* WARNING: Removing unreachable block (ram,0xf00996fc) */
/* WARNING: Removing unreachable block (ram,0xf00996c4) */
/* WARNING: Removing unreachable block (ram,0xf0099698) */
/* WARNING: Removing unreachable block (ram,0xf009967c) */
/* WARNING: Removing unreachable block (ram,0xf0099660) */
/* WARNING: Removing unreachable block (ram,0xf0099648) */
/* WARNING: Removing unreachable block (ram,0xf0099640) */
/* WARNING: Removing unreachable block (ram,0xf0099658) */
/* WARNING: Removing unreachable block (ram,0xf0099670) */
/* WARNING: Removing unreachable block (ram,0xf009968c) */
/* WARNING: Removing unreachable block (ram,0xf00996a8) */
/* WARNING: Removing unreachable block (ram,0xf00996e0) */
/* WARNING: Removing unreachable block (ram,0xf009971c) */
/* WARNING: Removing unreachable block (ram,0xf0099744) */
/* WARNING: Removing unreachable block (ram,0xf0099764) */
/* WARNING: Removing unreachable block (ram,0xf0099610) */

undefined8 _iom_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar2;
  undefined4 unaff_l7;
  int iVar3;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  uVar2 = 0;
  iVar3 = -0x100000;
  _bzero(_ioptes,0x4000);
  _pmap_enter_dev(_kernel_pmap,0xfff00000,_first_page,0,3,0,1);
  uVar1 = 0x200;
  _kalloc();
  _iopbmap = uVar1;
  _bzero();
  uVar1 = 0x7f0;
  _kalloc();
  _sbusmap = uVar1;
  _bzero();
  uVar1 = 0x3000;
  _kalloc();
  _bigsbusmap = uVar1;
  _bzero();
  uVar1 = 0x1000;
  _kalloc();
  _mbutlmap = uVar1;
  _bzero();
  _rminit(_iopbmap,0x2000,0xfff00000,aIopbSpace,0x40);
  _rminit(_sbusmap,0xfe,2,aSbusMapSpace,0x54);
  _rminit(_bigsbusmap,0x600,0xff000,aBigsbusMapSpac,0x200);
  _rminit(_mbutlmap,0x200,0xff600,aMbutlMapSpace,0xaa);
  _dvmamap = _sbusmap;
  _iommu_set_base((_phys_iopte >> 0xe) << 10);
  _iommu_set_ctl(1);
  _iommu_flush_all();
  do {
    _iom_dvma_pteload((_first_page >> 0xc) + uVar2,iVar3,1);
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 0x1000;
  } while (uVar2 < 2);
  return CONCAT44(param_2,DAT_f013d800);
}
/* GHIDRADEC_FUNCTION index=2281 start=0xf0099788 */

undefined8 _iom_dvma_pteload(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  undefined4 unaff_i1;
  int iVar3;
  undefined4 unaff_i2;
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
  uVar2 = param_1 << 8 | 2;
  iVar3 = (param_2 + 0x1000000U >> 0xc) * 4;
  puVar1 = (uint *)(_ioptes + iVar3);
  if ((param_3 & 1) != 0) {
    uVar2 = param_1 << 8 | 6;
  }
  if (_cache - 2U < 2) {
loc_F00997EC:
    uVar2 = uVar2 | 0x80;
  }
  else if (_vac != 0) {
    if ((param_3 & 2) == 0) {
      *puVar1 = uVar2;
      goto locret_F00997F4;
    }
    goto loc_F00997EC;
  }
  *puVar1 = uVar2;
locret_F00997F4:
  return CONCAT44(iVar3,uVar2);
}
/* GHIDRADEC_FUNCTION index=2282 start=0xf00997fc */

/* WARNING: Removing unreachable block (ram,0xf009981c) */
/* WARNING: Removing unreachable block (ram,0xf0099804) */

undefined8 _iom_pteload(int param_1,uint *param_2,uint param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  _iom_ptefind(param_2,param_4);
  if (param_2 == (uint *)0x0) {
    _panic(aIomPteloadBadM);
  }
  uVar1 = param_1 << 8 | 2;
  if ((param_3 & 1) != 0) {
    uVar1 = param_1 << 8 | 6;
  }
  if (_cache - 2U < 2) {
loc_F0099868:
    uVar1 = uVar1 | 0x80;
  }
  else if (_vac != 0) {
    if ((param_3 & 2) == 0) {
      *param_2 = uVar1;
      goto locret_F0099870;
    }
    goto loc_F0099868;
  }
  *param_2 = uVar1;
locret_F0099870:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2283 start=0xf0099878 */

/* WARNING: Removing unreachable block (ram,0xf0099898) */

undefined8 _iom_dvma_unload(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  iVar1 = (param_1 + 0x1000000 >> 0xc) * 4;
  *(undefined4 *)(_ioptes + iVar1) = 0;
  _iommu_addr_flush(param_1 & 0xfffff000);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2284 start=0xf00998a8 */

/* WARNING: Removing unreachable block (ram,0xf00998c8) */

undefined8 _iom_pteunload(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _ioptes;
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
  *param_1 = 0;
  iVar1 = ((int)param_1 - iVar1 >> 2) * 0x1000;
  _iommu_addr_flush(iVar1 + -0x1000000);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2285 start=0xf00998d8 */

/* WARNING: Removing unreachable block (ram,0xf00998e0) */

undefined8 _iom_ptefind(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _map_addr_to_dvma_pfn(param_1,param_2);
  return CONCAT44(param_2,_ioptes + param_1 * 4);
}
/* GHIDRADEC_FUNCTION index=2286 start=0xf00998fc */

/* WARNING: Removing unreachable block (ram,0xf009997c) */
/* WARNING: Removing unreachable block (ram,0xf0099970) */

undefined8 _map_addr_to_dvma_pfn(uint param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  if (((param_2 == _sbusmap) || (param_2 == _bigsbusmap)) || (uVar1 = param_1, param_2 == _mbutlmap)
     ) {
    uVar1 = param_1 + 0xf00;
    if (((param_1 - 2 < 0xfe) || (uVar1 = param_1 - 0xff000, uVar1 < 0x600)) ||
       (param_1 - 0xff600 < 0x200)) goto locret_F0099984;
    _panic(aMapAddrToDvmaP);
  }
  _panic(aMapAddrToDvmaP_0);
locret_F0099984:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2287 start=0xf009998c */

undefined8 _map_addr_to_map(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  if (((param_2 == _sbusmap) || (param_2 == _bigsbusmap)) || (param_2 == _mbutlmap)) {
    iVar1 = _sbusmap;
    if (((0xfd < param_1 - 2U) && (iVar1 = _bigsbusmap, 0x5ff < param_1 - 0xff000U)) &&
       (iVar1 = _mbutlmap, 0x1ff < param_1 - 0xff600U)) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2288 start=0xf0099a24 */

undefined8 _check_cpu_subtype(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  return CONCAT44(param_2,(uint)(param_1 == 0));
}
/* GHIDRADEC_FUNCTION index=2289 start=0xf0099a38 */

undefined8 _grade_cpu_subtype(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  return CONCAT44(param_2,(uint)(param_1 == 0));
}
/* GHIDRADEC_FUNCTION index=2290 start=0xf0099a4c */

/* WARNING: Removing unreachable block (ram,0xf0099b54) */
/* WARNING: Removing unreachable block (ram,0xf0099b78) */
/* WARNING: Removing unreachable block (ram,0xf0099a7c) */
/* WARNING: Removing unreachable block (ram,0xf0099b70) */
/* WARNING: Removing unreachable block (ram,0xf0099b0c) */
/* WARNING: Removing unreachable block (ram,0xf0099a50) */

undefined8 _softcall(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool bVar5;
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
  iVar1 = param_1;
  _splusclock();
  if (dword_F011708C != 0) {
    piVar2 = _softfree;
    piVar4 = (int *)_softcalls;
    do {
      _softfree = piVar4;
      _softfree[2] = (int)piVar2;
      piVar2 = _softfree;
      piVar4 = _softfree + 3;
    } while (_softfree + 3 < &_softfree);
    dword_F011708C = 0;
  }
  piVar2 = _softfree;
  if (_softhead != (int *)0x0) {
    iVar3 = *_softhead;
    piVar4 = _softhead;
    while( true ) {
      if (iVar3 == param_1) {
        if (piVar4[1] == param_2) goto loc_F0099B60;
        piVar4 = (int *)piVar4[2];
      }
      else {
        piVar4 = (int *)piVar4[2];
      }
      if (piVar4 == (int *)0x0) break;
      iVar3 = *piVar4;
    }
  }
  if (_softfree == (int *)0x0) {
    _panic(aTooManySoftcal);
    iRam00000000 = param_1;
  }
  else {
    *_softfree = param_1;
  }
  piVar2[1] = param_2;
  _softfree = (int *)piVar2[2];
  bVar5 = _softhead == (int *)0x0;
  piVar2[2] = 0;
  if (bVar5) {
    _softtail = piVar2;
    _softhead = piVar2;
    _siron();
  }
  else {
    _softtail[2] = (int)piVar2;
    _softtail = piVar2;
  }
loc_F0099B60:
  if (_limes_paranoia != 0) {
    _siron();
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2291 start=0xf0099b88 */

/* WARNING: Removing unreachable block (ram,0xf0099be4) */
/* WARNING: Removing unreachable block (ram,0xf0099bd4) */
/* WARNING: Removing unreachable block (ram,0xf0099bfc) */
/* WARNING: Removing unreachable block (ram,0xf0099ba0) */

undefined8 _softint(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  code *pcVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  uVar4 = 0;
  if (_softhead != (undefined4 *)0x0) {
    _splusclock();
    if (_softhead != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)_softhead[2];
      puVar2 = _softhead;
      while( true ) {
        pcVar3 = (code *)*puVar2;
        uVar4 = puVar2[1];
        _softhead = puVar1;
        puVar2[2] = _softfree;
        _softfree = puVar2;
        _splx();
        (*pcVar3)(uVar4);
        _splusclock();
        if (_softhead == (undefined4 *)0x0) break;
        puVar1 = (undefined4 *)_softhead[2];
        puVar2 = _softhead;
      }
    }
    uVar4 = 1;
    _splx();
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2292 start=0xf0099c0c */

/* WARNING: Removing unreachable block (ram,0xf0099c20) */

undefined8 _halt_thread(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _boot(1,_reboot_how,&unk_F01170A8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2293 start=0xf0099c30 */

/* WARNING: Removing unreachable block (ram,0xf0099c54) */
/* WARNING: Removing unreachable block (ram,0xf0099c6c) */

undefined8 _reboot_mach(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (_kernel_task == 0) {
    _boot(1,param_1 | 4,&unk_F01170B0);
  }
  else {
    _reboot_how = param_1;
    _calloutDispatch(_halt_thread,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2294 start=0xf0099c7c */

/* WARNING: Removing unreachable block (ram,0xf0099d94) */
/* WARNING: Removing unreachable block (ram,0xf0099d48) */
/* WARNING: Removing unreachable block (ram,0xf0099d1c) */
/* WARNING: Removing unreachable block (ram,0xf0099d08) */
/* WARNING: Removing unreachable block (ram,0xf0099cf4) */
/* WARNING: Removing unreachable block (ram,0xf0099cac) */
/* WARNING: Removing unreachable block (ram,0xf0099c98) */
/* WARNING: Removing unreachable block (ram,0xf0099cc4) */
/* WARNING: Removing unreachable block (ram,0xf0099ce0) */
/* WARNING: Removing unreachable block (ram,0xf0099d64) */
/* WARNING: Removing unreachable block (ram,0xf0099d34) */
/* WARNING: Removing unreachable block (ram,0xf0099da4) */
/* WARNING: Removing unreachable block (ram,0xf0099c90) */

undefined8 _mini_mon(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar4;
  undefined4 unaff_l3;
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
  bool bVar5;
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
  puVar4 = (undefined *)((int)register0x00000038 + -0x58);
  puVar1 = puVar4;
  _memcpy(puVar4,aRestartOrHaltT,0x4c);
  _splusclock();
  iVar2 = param_1;
  _strcmp(param_1,&aRestart);
  iVar3 = param_1;
  _strcmp(param_1,&aPanic_0);
  bVar5 = iVar3 == 0;
  if (iVar2 == 0) {
    _DoAlert(param_2,puVar4);
  }
  else {
    _DoAlert(param_2,unk_F0117118);
  }
  if (bVar5) {
    _kmdumplog();
  }
  iVar3 = param_1;
  if (iVar2 == 0) {
    do {
      param_1 = iVar3;
      _kmtrygetc();
      iVar3 = param_1;
      if (param_1 == 0x72) {
        iVar3 = 0;
        _reboot_mach();
      }
      if (param_1 == 0x68) {
        iVar3 = 8;
        _reboot_mach();
      }
    } while (param_1 == -1);
  }
  else {
    do {
      _miniMonLoop(param_1,bVar5,param_3);
    } while (bVar5);
  }
  if (_nmi_stay == 0) {
    _DoRestore();
  }
  _nmi_stay = 0;
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2295 start=0xf0099db4 */

/* WARNING: Removing unreachable block (ram,0xf0099dc8) */

undefined8 _nmi_prf(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  _prf(param_1,(undefined *)((int)register0x00000038 + 0x48),1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2296 start=0xf0099dd8 */

/* WARNING: Removing unreachable block (ram,0xf0099e88) */
/* WARNING: Removing unreachable block (ram,0xf0099e30) */
/* WARNING: Removing unreachable block (ram,0xf0099e44) */
/* WARNING: Removing unreachable block (ram,0xf0099eb4) */
/* WARNING: Removing unreachable block (ram,0xf0099df0) */

undefined8 _addupc(int param_1,undefined4 *param_2,sword param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l1;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 *puVar8;
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
  piVar4 = (int *)*param_2;
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_2 == (undefined4 *)0x0) {
loc_F0099ED0:
    puVar8 = (undefined4 *)*param_2;
loc_F0099ED4:
    *puVar8 = 0;
    return CONCAT44(param_2,param_1);
  }
  iVar5 = param_2[4];
  puVar8 = param_2;
  do {
    uVar7 = puVar8[5];
    uVar2 = (uint)(param_1 - iVar5) >> 0x10;
    .umul(uVar2,uVar7);
    uVar6 = param_1 - iVar5 & 0xffff;
    .umul(uVar6,uVar7);
    uVar3 = puVar8[2];
    uVar2 = uVar3 + (uVar2 + (uVar6 >> 0x10) & 0xfffffffe);
    if (uVar2 < uVar3) {
      puVar8 = (undefined4 *)puVar8[1];
    }
    else {
      if (uVar2 < puVar8[3] + uVar3) {
        uVar6 = uVar2;
        _copyin(uVar2,(undefined *)((int)register0x00000038 + -10),2);
        if (uVar6 == 0) {
          *(sword *)((int)register0x00000038 + -10) =
               *(sword *)((int)register0x00000038 + -10) + param_3;
          _copyout((undefined *)((int)register0x00000038 + -10),uVar2,2);
          puVar8 = (undefined4 *)*param_2;
          goto loc_F0099ED4;
        }
        param_2[5] = 0;
        goto loc_F0099ED0;
      }
      puVar8 = (undefined4 *)puVar8[1];
    }
    if (puVar8 == (undefined4 *)0x0) goto loc_F0099ED0;
    iVar5 = puVar8[4];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2297 start=0xf0099ee0 */

undefined8 _callout_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  dword_F0131498 = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2298 start=0xf0099ef8 */

/* WARNING: Removing unreachable block (ram,0xf0099f48) */
/* WARNING: Removing unreachable block (ram,0xf0099f64) */

undefined8 _callout_dispatch(undefined4 param_1,code *param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (dword_F0131498 != 0) {
    switch(param_1) {
    case :
    case :
    case :
      _calloutDispatchUnique(param_2,param_3);
      break;
    :
      _panic(aCalloutDispatc);
      break;
    case :
      (*param_2)(param_3);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2299 start=0xf0099f74 */

/* WARNING: Removing unreachable block (ram,0xf0099f8c) */

undefined8 _callout_remove(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (dword_F0131498 != 0) {
    _calloutRemove(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}

