/* GHIDRADEC_FUNCTION index=350 start=0xf001a7dc */

undefined8 _ttydevstart(int param_1,undefined4 param_2)

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
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    (**(code **)(param_1 + 0x24))();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=351 start=0xf001a804 */

undefined8 _ttydevstop(int param_1,undefined4 param_2)

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
  (**(code **)(DAT_f011ca04 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))(param_1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=352 start=0xf001a848 */

/* WARNING: Removing unreachable block (ram,0xf001a890) */
/* WARNING: Removing unreachable block (ram,0xf001a870) */
/* WARNING: Removing unreachable block (ram,0xf001a8b0) */
/* WARNING: Removing unreachable block (ram,0xf001a84c) */

undefined8 _ttyselwait(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
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
  iVar1 = param_1;
  _spltty();
  if (param_2 == 1) {
    iVar2 = param_1 + 0x28;
    _selthreadcache();
    if (iVar2 == 0) goto loc_F001A8B0;
    uVar3 = *(uint *)(param_1 + 0x40) | 0x800;
  }
  else {
    if (param_2 != 2) goto loc_F001A8B0;
    iVar2 = param_1 + 0x2c;
    _selthreadcache();
    if (iVar2 == 0) goto loc_F001A8B0;
    uVar3 = *(uint *)(param_1 + 0x40) | 0x1000;
  }
  *(uint *)(param_1 + 0x40) = uVar3;
loc_F001A8B0:
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=353 start=0xf001a8c0 */

/* WARNING: Removing unreachable block (ram,0xf001a8f8) */
/* WARNING: Removing unreachable block (ram,0xf001a8e4) */
/* WARNING: Removing unreachable block (ram,0xf001a900) */
/* WARNING: Removing unreachable block (ram,0xf001a8c4) */

undefined8 _ttselwakeup(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _spltty();
  if (*(int *)(param_1 + 0x28) != 0) {
    _selwakeup(*(int *)(param_1 + 0x28),*(uint *)(param_1 + 0x40) & 0x800);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffff7ff;
    _selthreadclear(param_1 + 0x28);
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=354 start=0xf001a910 */

undefined8 _ttsettermios(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  uint uVar6;
  undefined4 unaff_i4;
  uint uVar7;
  undefined4 unaff_i5;
  int iVar8;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  iVar8 = *param_1;
  uVar6 = 0;
  uVar3 = *param_2;
  uVar5 = 0;
  uVar7 = param_2[3];
  uVar4 = param_2[1];
  uVar1 = param_2[2];
  if ((uVar3 & 0x23e2) == 0) {
    bVar9 = (uVar3 & 2) == 0;
    if ((((uVar4 & 1) != 0) || (bVar9 = (uVar3 & 2) == 0, (uVar7 & 0xe0) != 0)) ||
       (bVar9 = (uVar3 & 2) == 0, (uVar1 & 0x1300) != 0x300)) goto loc_F001A980;
    uVar6 = 0x20;
  }
  else {
    bVar9 = (uVar3 & 2) == 0;
loc_F001A980:
    if (!bVar9) {
      uVar5 = 0x40000;
    }
    if ((uVar3 & 0x20) != 0) {
      uVar5 = uVar5 | 0x400000;
    }
    if ((uVar3 & 0x40) != 0) {
      uVar5 = uVar5 | 0x800000;
    }
    if ((uVar3 & 0x80) != 0) {
      uVar5 = uVar5 | 0x1000000;
    }
    if ((uVar3 & 0x200) != 0) {
      uVar5 = uVar5 | 0x4000000;
    }
    if ((uVar3 & 0x2000) != 0) {
      uVar5 = uVar5 | 0x8000000;
    }
    if ((uVar4 & 1) != 0) {
      uVar5 = uVar5 | 0x10000000;
    }
    if (((uVar4 & 2) == 0) || ((uVar3 & 0x100) == 0)) {
      if ((uVar4 & 2) != 0) {
        uVar5 = uVar5 | 0x20000000;
      }
      if ((uVar3 & 0x100) != 0) {
        uVar5 = uVar5 | 0x2000000;
      }
    }
    else {
      uVar6 = 0x10;
    }
    if ((uVar7 & 0x20) == 0) {
      uVar6 = uVar6 | 2;
    }
    if ((uVar7 & 0x40) != 0) {
      uVar5 = uVar5 | 8;
    }
    if ((uVar7 & 0x80) != 0) {
      uVar5 = uVar5 | 0x10;
    }
    if ((uVar1 & 0x1000) != 0) {
      uVar5 = uVar5 | 0x1000;
    }
    uVar2 = uVar1 & 0x300;
    if (uVar2 == 0x100) {
      uVar5 = uVar5 | 0x100;
    }
    else if (0x100 < uVar2) {
      if (uVar2 == 0x200) {
        uVar5 = uVar5 | 0x200;
      }
      else if ((uVar2 == 0x300) && (uVar5 = uVar5 | 0x300, (uVar1 & 0x1000) == 0)) {
        uVar2 = 0x200000;
        if ((uVar4 & 1) != 0) {
          uVar2 = 0x2000000;
        }
        uVar6 = uVar6 | uVar2;
        if ((uVar3 & 0x20) == 0) {
          uVar6 = uVar6 | 0x8000000;
        }
      }
    }
  }
  if ((uVar1 & 0x2000) != 0) {
    uVar6 = uVar6 | 0x40;
    goto loc_F001AB0C;
  }
  if ((uVar7 & 0x80) != 0) {
    if ((uVar1 & 0x40000) != 0) {
      uVar6 = uVar6 | 0xc0;
      goto loc_F001AB0C;
    }
    if ((uVar1 & 0x20000) != 0) goto loc_F001AB0C;
  }
  uVar6 = uVar6 | 0x80;
loc_F001AB0C:
  if ((uVar1 & 0x400) != 0) {
    uVar5 = uVar5 | 0x400;
  }
  if ((uVar1 & 0x800) != 0) {
    uVar5 = uVar5 | 0x800;
  }
  if ((uVar1 & 0x4000) == 0) {
    uVar6 = uVar6 | 0x1000000;
  }
  if ((uVar1 & 0x8000) != 0) {
    uVar5 = uVar5 | 0x8000;
  }
  if ((uVar1 & 0x10000) != 0) {
    uVar5 = uVar5 | 0x10000;
  }
  if ((uVar3 & 1) != 0) {
    uVar5 = uVar5 | 0x20000;
  }
  if ((uVar3 & 4) != 0) {
    uVar5 = uVar5 | 0x80000;
  }
  if ((uVar3 & 8) != 0) {
    uVar5 = uVar5 | 0x100000;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar5 = uVar5 | 0x200000;
  }
  if ((uVar3 & 0x400) != 0) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar3 & 0x800) == 0) {
    uVar6 = uVar6 | 0x40000000;
  }
  uVar6 = uVar6 | uVar4 & 0xff00;
  if ((uVar7 & 2) != 0) {
    uVar6 = uVar6 | 0x10000;
  }
  if ((uVar7 & 4) != 0) {
    uVar5 = uVar5 | 4;
  }
  if ((uVar7 & 1) != 0) {
    uVar6 = uVar6 | 0x4000000;
  }
  if ((uVar7 & 0x100) != 0) {
    uVar6 = uVar6 | 0x40000;
  }
  if ((uVar7 & 0x200) != 0) {
    uVar6 = uVar6 | 0x20000;
  }
  if ((uVar7 & 0x400) != 0) {
    uVar6 = uVar6 | 0x10000000;
  }
  if ((uVar7 & 0x10) != 0) {
    uVar5 = uVar5 | 2;
  }
  if ((uVar7 & 0x800) != 0) {
    uVar5 = uVar5 | 0x20;
  }
  if ((uVar7 & 0x4000000) != 0) {
    uVar6 = uVar6 | 4;
  }
  if ((uVar7 & 0x8000000) != 0) {
    uVar6 = uVar6 | 0x80000;
  }
  *(uint *)(*param_1 + 0x3c) = uVar6 | uVar7 & 0x80500008;
  param_1[4] = uVar5;
  *(undefined *)(iVar8 + 0x49) = *(undefined *)((int)param_2 + 0x21);
  *(undefined *)(iVar8 + 0x4a) = *(undefined *)((int)param_2 + 0x22);
  *(undefined *)(iVar8 + 0x4d) = *(undefined *)((int)param_2 + 0x12);
  *(undefined *)(iVar8 + 0x4e) = *(undefined *)((int)param_2 + 0x13);
  *(undefined *)(iVar8 + 0x4f) = *(undefined *)(param_2 + 5);
  *(undefined *)(iVar8 + 0x50) = *(undefined *)((int)param_2 + 0x15);
  *(undefined *)(iVar8 + 0x51) = *(undefined *)((int)param_2 + 0x17);
  *(undefined *)(iVar8 + 0x52) = *(undefined *)(param_2 + 6);
  *(undefined *)(iVar8 + 0x53) = *(undefined *)(param_2 + 4);
  *(undefined *)(iVar8 + 0x54) = *(undefined *)((int)param_2 + 0x11);
  *(undefined *)(iVar8 + 0x55) = *(undefined *)((int)param_2 + 0x16);
  *(undefined *)(iVar8 + 0x56) = *(undefined *)((int)param_2 + 0x1f);
  *(undefined *)(iVar8 + 0x57) = *(undefined *)(param_2 + 7);
  *(undefined *)(iVar8 + 0x58) = *(undefined *)((int)param_2 + 0x1e);
  *(undefined *)(iVar8 + 0x59) = *(undefined *)((int)param_2 + 0x1b);
  *(undefined *)(iVar8 + 0x5a) = *(undefined *)((int)param_2 + 0x1d);
  *(undefined *)((int)param_1 + 0x15) = *(undefined *)((int)param_2 + 0x19);
  *(undefined *)((int)param_1 + 0x16) = *(undefined *)((int)param_2 + 0x1a);
  *(undefined *)(param_1 + 5) = *(undefined *)(param_2 + 8);
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=355 start=0xf001ad18 */

undefined8 _ttgettermios(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
  uint uVar6;
  undefined4 unaff_i3;
  uint uVar7;
  undefined4 unaff_i4;
  uint uVar8;
  undefined4 unaff_i5;
  uint uVar9;
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
  uVar4 = 0;
  uVar5 = 0;
  iVar1 = *param_1;
  uVar6 = 0;
  uVar9 = *(uint *)(iVar1 + 0x3c);
  uVar7 = 0;
  uVar8 = param_1[4];
  if ((uVar9 & 0x20) == 0) {
    if ((uVar8 & 0x40000) != 0) {
      uVar4 = 2;
    }
    if ((uVar8 & 0x400000) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar8 & 0x800000) != 0) {
      uVar4 = uVar4 | 0x40;
    }
    if ((uVar8 & 0x1000000) != 0) {
      uVar4 = uVar4 | 0x80;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar4 = uVar4 | 0x200;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    uVar5 = (uint)((uVar8 & 0x10000000) != 0);
    if ((uVar9 & 0x10) == 0) {
      if ((uVar8 & 0x2000000) != 0) {
        uVar4 = uVar4 | 0x100;
      }
      if ((uVar8 & 0x20000000) != 0) goto loc_F001ADF0;
    }
    else {
      uVar4 = uVar4 | 0x100;
loc_F001ADF0:
      uVar5 = uVar5 | 2;
    }
    if ((uVar9 & 2) == 0) {
      uVar6 = 0x20;
    }
    if ((uVar8 & 8) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x10) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar9 & 0xa200000) == 0) {
      if ((uVar8 & 0x1000) != 0) {
        uVar7 = 0x1000;
      }
      uVar2 = uVar8 & 0x300;
      if (uVar2 == 0x100) {
        uVar7 = uVar7 | 0x100;
      }
      else if (0x100 < uVar2) {
        if (uVar2 == 0x200) {
          uVar7 = uVar7 | 0x200;
        }
        else if (uVar2 == 0x300) {
          uVar7 = uVar7 | 0x300;
        }
      }
    }
    else {
      uVar7 = 0x300;
      if ((uVar9 & 0x8000000) != 0) {
        uVar4 = uVar4 & 0xffffffdf;
      }
      if ((uVar9 & 0x200000) != 0) {
        uVar5 = uVar5 & 0xfffffffe;
      }
    }
  }
  else {
    uVar7 = 0x300;
  }
  uVar2 = uVar9 & 0xc0;
  if (uVar2 == 0x40) {
    uVar3 = 0x2000;
loc_F001AED8:
    uVar7 = uVar7 | uVar3;
  }
  else {
    if (uVar2 < 0x41) {
      uVar3 = 0x20000;
      if (uVar2 != 0) {
        bVar10 = (uVar8 & 0x400) == 0;
        goto loc_F001AEE0;
      }
      goto loc_F001AED8;
    }
    if (uVar2 != 0x80) {
      uVar3 = 0x40000;
      if (uVar2 != 0xc0) {
        bVar10 = (uVar8 & 0x400) == 0;
        goto loc_F001AEE0;
      }
      goto loc_F001AED8;
    }
  }
  bVar10 = (uVar8 & 0x400) == 0;
loc_F001AEE0:
  if (!bVar10) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar8 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar9 & 0x1000000) == 0) {
    uVar7 = uVar7 | 0x4000;
  }
  if ((uVar8 & 0x8000) != 0) {
    uVar7 = uVar7 | 0x8000;
  }
  if ((uVar8 & 0x10000) != 0) {
    uVar7 = uVar7 | 0x10000;
  }
  if ((uVar8 & 0x20000) != 0) {
    uVar4 = uVar4 | 1;
  }
  if ((uVar8 & 0x80000) != 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar8 & 0x100000) != 0) {
    uVar4 = uVar4 | 8;
  }
  if ((uVar8 & 0x200000) != 0) {
    uVar4 = uVar4 | 0x10;
  }
  if ((uVar9 & 1) != 0) {
    uVar4 = uVar4 | 0x400;
  }
  if ((uVar9 & 0x40000000) == 0) {
    uVar4 = uVar4 | 0x800;
  }
  if ((uVar9 & 0x10000) != 0) {
    uVar6 = uVar6 | 2;
  }
  if ((uVar8 & 4) != 0) {
    uVar6 = uVar6 | 4;
  }
  if ((uVar9 & 0x4000000) != 0) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar9 & 0x40000) != 0) {
    uVar6 = uVar6 | 0x100;
  }
  if ((uVar9 & 0x20000) != 0) {
    uVar6 = uVar6 | 0x200;
  }
  if ((uVar9 & 0x10000000) != 0) {
    uVar6 = uVar6 | 0x400;
  }
  if ((uVar8 & 2) != 0) {
    uVar6 = uVar6 | 0x10;
  }
  if ((uVar8 & 0x20) != 0) {
    uVar6 = uVar6 | 0x800;
  }
  if ((uVar9 & 4) != 0) {
    uVar6 = uVar6 | 0x4000000;
  }
  if ((uVar9 & 0x80000) != 0) {
    uVar6 = uVar6 | 0x8000000;
  }
  *param_2 = uVar4;
  param_2[1] = uVar5 | uVar9 & 0xff00;
  param_2[3] = uVar6 | uVar9 & 0x80500008;
  param_2[2] = uVar7;
  *(undefined *)((int)param_2 + 0x21) = *(undefined *)(iVar1 + 0x49);
  *(undefined *)((int)param_2 + 0x22) = *(undefined *)(iVar1 + 0x4a);
  *(undefined *)((int)param_2 + 0x12) = *(undefined *)(iVar1 + 0x4d);
  *(undefined *)((int)param_2 + 0x13) = *(undefined *)(iVar1 + 0x4e);
  *(undefined *)(param_2 + 5) = *(undefined *)(iVar1 + 0x4f);
  *(undefined *)((int)param_2 + 0x15) = *(undefined *)(iVar1 + 0x50);
  *(undefined *)((int)param_2 + 0x17) = *(undefined *)(iVar1 + 0x51);
  *(undefined *)(param_2 + 6) = *(undefined *)(iVar1 + 0x52);
  *(undefined *)(param_2 + 4) = *(undefined *)(iVar1 + 0x53);
  *(undefined *)((int)param_2 + 0x11) = *(undefined *)(iVar1 + 0x54);
  *(undefined *)((int)param_2 + 0x16) = *(undefined *)(iVar1 + 0x55);
  *(undefined *)((int)param_2 + 0x1f) = *(undefined *)(iVar1 + 0x56);
  *(undefined *)(param_2 + 7) = *(undefined *)(iVar1 + 0x57);
  *(undefined *)((int)param_2 + 0x1e) = *(undefined *)(iVar1 + 0x58);
  *(undefined *)((int)param_2 + 0x1b) = *(undefined *)(iVar1 + 0x59);
  *(undefined *)((int)param_2 + 0x1d) = *(undefined *)(iVar1 + 0x5a);
  *(undefined *)((int)param_2 + 0x19) = *(undefined *)((int)param_1 + 0x15);
  *(undefined *)((int)param_2 + 0x1a) = *(undefined *)((int)param_1 + 0x16);
  *(undefined *)(param_2 + 8) = *(undefined *)(param_1 + 5);
  return CONCAT44(param_2,0x4000000);
}
/* GHIDRADEC_FUNCTION index=356 start=0xf001b0e8 */

/* WARNING: Removing unreachable block (ram,0xf001b15c) */
/* WARNING: Removing unreachable block (ram,0xf001b104) */
/* WARNING: Removing unreachable block (ram,0xf001b1a4) */
/* WARNING: Removing unreachable block (ram,0xf001b0ec) */

undefined8 _ttynty(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  _spltty();
  if (param_1 == 0) {
    _panic(aTtynty0);
  }
  bVar5 = dword_F012F200 == (int *)0x0;
  piVar3 = (int *)&dword_F012F200;
  piVar4 = dword_F012F200;
  if (!bVar5) {
    iVar2 = *dword_F012F200;
    while (bVar5 = piVar4 == (int *)0x0, iVar2 != param_1) {
      piVar3 = piVar4 + 1;
      piVar4 = (int *)piVar4[1];
      if (piVar4 == (int *)0x0) {
        bVar5 = true;
        break;
      }
      iVar2 = *piVar4;
    }
  }
  if (bVar5) {
    piVar4 = (int *)0x18;
    _kalloc();
    *piVar4 = param_1;
    piVar4[4] = 0x1c251a1c;
    *(undefined *)(piVar4 + 5) = 0x5c;
    *(undefined *)((int)piVar4 + 0x15) = 1;
    *(undefined *)((int)piVar4 + 0x16) = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
  }
  else {
    *piVar3 = piVar4[1];
  }
  piVar4[1] = (int)dword_F012F200;
  dword_F012F200 = piVar4;
  _splx(iVar1);
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=357 start=0xf001b1b4 */

undefined8 _nullioctl(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0xffffffff);
}
/* GHIDRADEC_FUNCTION index=358 start=0xf001b1c0 */

/* WARNING: Removing unreachable block (ram,0xf001b1cc) */

undefined8 _pty_init(undefined4 param_1,undefined4 param_2)

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
  _lock_init(_pty_alloc_lock,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=359 start=0xf001b1dc */

/* WARNING: Removing unreachable block (ram,0xf001b240) */
/* WARNING: Removing unreachable block (ram,0xf001b22c) */
/* WARNING: Removing unreachable block (ram,0xf001b220) */
/* WARNING: Removing unreachable block (ram,0xf001b234) */
/* WARNING: Removing unreachable block (ram,0xf001b248) */
/* WARNING: Removing unreachable block (ram,0xf001b208) */

undefined8 _pty_alloc(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = (param_1 & 0xff) * 0x10;
  if (*(int *)(unk_F012F204 + iVar2 + 8) == 0) {
    _lock_write(_pty_alloc_lock);
    if (*(int *)(unk_F012F204 + iVar2 + 8) == 0) {
      uVar1 = 0x88;
      _kalloc();
      *(undefined4 *)(unk_F012F204 + iVar2 + 8) = uVar1;
      _bzero();
      uVar1 = 0x10;
      _kalloc();
      *(undefined4 *)(unk_F012F204 + iVar2 + 0xc) = uVar1;
      _bzero();
    }
    _lock_done(_pty_alloc_lock);
  }
  return CONCAT44(param_2,unk_F012F204 + iVar2);
}
/* GHIDRADEC_FUNCTION index=360 start=0xf001b258 */

/* WARNING: Removing unreachable block (ram,0xf001b314) */
/* WARNING: Removing unreachable block (ram,0xf001b2c0) */
/* WARNING: Removing unreachable block (ram,0xf001b374) */
/* WARNING: Removing unreachable block (ram,0xf001b278) */

undefined8 _ptsopen(uint param_1,uint param_2)

{
  sword sVar3;
  sword *psVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  if ((param_1 & 0xff) < 0x20) {
    sVar3 = (sword)param_1;
    psVar1 = (sword *)(int)sVar3;
    _pty_alloc();
    iVar4 = *(int *)(psVar1 + 4);
    *psVar1 = sVar3;
    if ((*(uint *)(iVar4 + 0x40) & 4) == 0) {
      _ttychars(iVar4);
      *(undefined *)(iVar4 + 0x4a) = 0xf;
      *(undefined *)(iVar4 + 0x49) = 0xf;
      *(undefined4 *)(iVar4 + 0x3c) = 0;
    }
    else if (((*(uint *)(iVar4 + 0x40) & 0x80) != 0) &&
            (iVar5 = 0x10, *(sword *)(*(int *)(_active_u + 0x1c) + 2) != 0)) goto locret_F001B37C;
    if (*(int *)(iVar4 + 0x24) != 0) {
      *(uint *)(iVar4 + 0x40) = *(uint *)(iVar4 + 0x40) | 0x10;
    }
    uVar2 = *(uint *)(iVar4 + 0x40);
    if ((param_2 & 4) == 0) {
      while ((uVar2 & 0x10) == 0) {
        *(uint *)(iVar4 + 0x40) = uVar2 | 2;
        _sleep(iVar4,0x1c);
        uVar2 = *(uint *)(iVar4 + 0x40);
      }
    }
    else {
      *(uint *)(iVar4 + 0x40) = uVar2 | 0x8000;
    }
    iVar5 = (int)sVar3;
    (**(code **)(_linesw + *(char *)(iVar4 + 0x47) * 0x30))(iVar5,iVar4);
    if (iVar5 == 0) {
      *(uint *)(psVar1 + 2) = *(uint *)(psVar1 + 2) | 1;
    }
    _ptcwakeup(iVar4,3);
  }
  else {
    iVar5 = 6;
  }
locret_F001B37C:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=361 start=0xf001b384 */

/* WARNING: Removing unreachable block (ram,0xf001b3e4) */
/* WARNING: Removing unreachable block (ram,0xf001b3d4) */

undefined8 _ptsclose(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = (param_1 & 0xff) * 0x10;
  iVar1 = *(int *)(unk_F012F204 + iVar2 + 8);
  if ((*(uint *)(unk_F012F204 + iVar2 + 4) & 1) != 0) {
    (**(code **)(DAT_f010b8d0 + *(char *)(iVar1 + 0x47) * 0x30))(iVar1);
    _ttyclose(iVar1);
    *(undefined4 *)(unk_F012F204 + iVar2 + 4) = 0;
  }
  _ptcwakeup(iVar1,3);
  return CONCAT44(param_2,unk_F012F204 + iVar2);
}
/* GHIDRADEC_FUNCTION index=362 start=0xf001b3f4 */

/* WARNING: Removing unreachable block (ram,0xf001b56c) */
/* WARNING: Removing unreachable block (ram,0xf001b590) */
/* WARNING: Removing unreachable block (ram,0xf001b504) */
/* WARNING: Removing unreachable block (ram,0xf001b4f4) */
/* WARNING: Removing unreachable block (ram,0xf001b588) */
/* WARNING: Removing unreachable block (ram,0xf001b5c4) */
/* WARNING: Removing unreachable block (ram,0xf001b624) */
/* WARNING: Removing unreachable block (ram,0xf001b470) */

undefined8 _ptsread(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  uint *puVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar6 = (param_1 & 0xff) * 0x10;
  iVar3 = *(int *)(DAT_f012f20c + iVar6);
  iVar4 = 0;
  puVar5 = *(uint **)(DAT_f012f20c + iVar6 + 4);
  uVar1 = *puVar5;
  while ((uVar1 & 0x20) != 0) {
    if (iVar3 == _active_u[0x59]) {
      do {
        iVar6 = *_active_u;
        if (*(sword *)(iVar6 + 0x2e) == *(sword *)(iVar3 + 0x44)) break;
        if ((*(uint *)(iVar6 + 0x14) & 0x4000) == 0) {
          if ((*(uint *)(iVar6 + 0x20) & 0x100000) != 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
          if ((*(uint *)(iVar6 + 0x1c) & 0x100000) != 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
          if ((*(uint *)(iVar6 + 0x28) & 0x1000) != 0) goto loc_F001B4E4;
        }
        else {
          iVar2 = (int)*(sword *)(iVar6 + 0x30);
          _get_posix_proc();
          if ((*(uint *)(iVar6 + 0x20) & 0x100000) != 0) {
loc_F001B4E4:
            iVar4 = 5;
            goto locret_F001B630;
          }
          if ((*(uint *)(iVar6 + 0x1c) & 0x100000) != 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
          if (*(int *)(*(int *)(iVar2 + 0x10) + 0x10) == 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
        }
        _gsignal((int)*(sword *)(*_active_u + 0x2e),0x15);
        _sleep(_lbolt,0x1c);
      } while (iVar3 == _active_u[0x59]);
      iVar6 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar6 = *(int *)(iVar3 + 0xc);
    }
    if (iVar6 != 0) goto loc_F001B5AC;
    if ((*(uint *)(iVar3 + 0x40) & 0x2000) != 0) {
      iVar4 = 0x23;
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
        iVar4 = 0xb;
      }
      goto locret_F001B630;
    }
    _sleep(iVar3 + 0xc,0x1c);
    uVar1 = *puVar5;
  }
  if (*(int *)(iVar3 + 0x24) != 0) {
    iVar4 = iVar3;
    (**(code **)(DAT_f010b8d4 + *(char *)(iVar3 + 0x47) * 0x30))(iVar3,param_2);
  }
  goto loc_F001B624;
loc_F001B5AC:
  if (iVar6 < 2) goto loc_F001B5B4;
  if (*(int *)(param_2 + 0x14) < 1) {
    iVar6 = *(int *)(iVar3 + 0xc);
    goto loc_F001B5B8;
  }
  iVar6 = iVar3 + 0xc;
  _getc();
  _ureadc();
  if (iVar6 < 0) {
    iVar4 = 0xe;
    goto loc_F001B5B4;
  }
  iVar6 = *(int *)(iVar3 + 0xc);
  goto loc_F001B5AC;
loc_F001B5B4:
  iVar6 = *(int *)(iVar3 + 0xc);
loc_F001B5B8:
  if (iVar6 == 1) {
    _getc(iVar3 + 0xc);
    iVar6 = *(int *)(iVar3 + 0xc);
  }
  else {
    iVar6 = *(int *)(iVar3 + 0xc);
  }
  if (iVar6 != 0) goto locret_F001B630;
loc_F001B624:
  _ptcwakeup(iVar3,2);
locret_F001B630:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=363 start=0xf001b638 */

undefined8 _ptswrite(uint param_1,undefined4 param_2)

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
  iVar1 = *(int *)(DAT_f012f20c + (param_1 & 0xff) * 0x10);
  if (*(int *)(iVar1 + 0x24) == 0) {
    iVar1 = 5;
  }
  else {
    (**(code **)(DAT_f010b8d8 + *(char *)(iVar1 + 0x47) * 0x30))(iVar1,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=364 start=0xf001b6a0 */

undefined8 _ptsselect(uint param_1,undefined4 param_2)

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
  iVar1 = *(int *)(DAT_f012f20c + (param_1 & 0xff) * 0x10);
  (**(code **)(DAT_f010b8f4 + *(char *)(iVar1 + 0x47) * 0x30))(iVar1,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=365 start=0xf001b6ec */

/* WARNING: Removing unreachable block (ram,0xf001b744) */

undefined8 _ptsstart(int param_1,undefined4 param_2)

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
  puVar1 = *(uint **)(DAT_f012f210 + (*(word *)(param_1 + 0x38) & 0xff) * 0x10);
  if ((*(word *)(param_1 + 0x38) != 0) && ((*(uint *)(param_1 + 0x40) & 0x100) == 0)) {
    if ((*puVar1 & 0x10) != 0) {
      *puVar1 = *puVar1 & 0xffffffef;
      *(undefined *)(puVar1 + 3) = 8;
    }
    _ptcwakeup(param_1,1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=366 start=0xf001b754 */

/* WARNING: Removing unreachable block (ram,0xf001b81c) */
/* WARNING: Removing unreachable block (ram,0xf001b800) */
/* WARNING: Removing unreachable block (ram,0xf001b7cc) */
/* WARNING: Removing unreachable block (ram,0xf001b7b0) */
/* WARNING: Removing unreachable block (ram,0xf001b7a8) */
/* WARNING: Removing unreachable block (ram,0xf001b7c4) */
/* WARNING: Removing unreachable block (ram,0xf001b7e0) */
/* WARNING: Removing unreachable block (ram,0xf001b808) */
/* WARNING: Removing unreachable block (ram,0xf001b824) */
/* WARNING: Removing unreachable block (ram,0xf001b788) */

undefined8 _ptcwakeup(int param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  uint *puVar2;
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
  puVar1 = unk_F012F204;
  puVar2 = *(uint **)(unk_F012F204 + (*(word *)(param_1 + 0x38) & 0xff) * 0x10 + 0xc);
  if (*(word *)(param_1 + 0x38) != 0) {
    if ((param_2 & 1) != 0) {
      _spltty();
      if (puVar2[1] != 0) {
        _selwakeup(puVar2[1],*puVar2 & 1);
        _selthreadclear(puVar2 + 1);
        *puVar2 = *puVar2 & 0xfffffffe;
      }
      _splx(puVar1);
      puVar1 = (undefined *)(param_1 + 0x1c);
      _wakeup(puVar1);
    }
    if ((param_2 & 2) != 0) {
      _spltty();
      if (puVar2[2] != 0) {
        _selwakeup(puVar2[2],*puVar2 & 2);
        _selthreadclear(puVar2 + 2);
        *puVar2 = *puVar2 & 0xfffffffd;
      }
      _splx(puVar1);
      _wakeup(param_1 + 4);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=367 start=0xf001b834 */

/* WARNING: Removing unreachable block (ram,0xf001b850) */

undefined8 _ptcopen(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  if ((param_1 & 0xff) < 0x20) {
    iVar1 = (int)(sword)param_1;
    _pty_alloc();
    iVar1 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar1 + 0x24) == 0) {
      *(code **)(iVar1 + 0x24) = _ptsstart;
      (**(code **)(DAT_f010b8f0 + *(char *)(iVar1 + 0x47) * 0x30))(iVar1,1);
      *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffbfffff | 0x10;
      puVar2 = *(undefined4 **)(DAT_f012f210 + (param_1 & 0xff) * 0x10);
      uVar3 = 0;
      *puVar2 = 0;
      *(undefined *)(puVar2 + 3) = 0;
      *(undefined *)((int)puVar2 + 0xd) = 0;
      puVar2[2] = 0;
      puVar2[1] = 0;
    }
    else {
      uVar3 = 5;
    }
  }
  else {
    uVar3 = 6;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=368 start=0xf001b8ec */

/* WARNING: Removing unreachable block (ram,0xf001b990) */
/* WARNING: Removing unreachable block (ram,0xf001b970) */
/* WARNING: Removing unreachable block (ram,0xf001b950) */
/* WARNING: Removing unreachable block (ram,0xf001b958) */
/* WARNING: Removing unreachable block (ram,0xf001b988) */
/* WARNING: Removing unreachable block (ram,0xf001b99c) */
/* WARNING: Removing unreachable block (ram,0xf001b948) */

undefined8 _ptcclose(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar4 = (param_1 & 0xff) * 0x10;
  iVar3 = *(int *)(unk_F012F204 + iVar4 + 8);
  iVar2 = *(int *)(unk_F012F204 + iVar4 + 0xc);
  (**(code **)(DAT_f010b8f0 + *(char *)(iVar3 + 0x47) * 0x30))(iVar3,0);
  uVar1 = *(uint *)(unk_F012F204 + iVar4 + 4);
  if ((uVar1 & 1) != 0) {
    _forceclose((int)*(sword *)(unk_F012F204 + iVar4));
    uVar1 = (uint)*(sword *)(unk_F012F204 + iVar4);
    _ptsclose(uVar1);
  }
  _spltty();
  if (*(int *)(iVar2 + 4) != 0) {
    _selthreadclear(iVar2 + 4);
  }
  if (*(int *)(iVar2 + 8) != 0) {
    _selthreadclear(iVar2 + 8);
  }
  _splx(uVar1);
  *(undefined4 *)(iVar3 + 0x24) = 0;
  _ttynty();
  *(undefined4 *)(iVar3 + 8) = 0;
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=369 start=0xf001b9b0 */

/* WARNING: Removing unreachable block (ram,0xf001bc44) */
/* WARNING: Removing unreachable block (ram,0xf001bc20) */
/* WARNING: Removing unreachable block (ram,0xf001bba8) */
/* WARNING: Removing unreachable block (ram,0xf001bad0) */
/* WARNING: Removing unreachable block (ram,0xf001ba6c) */
/* WARNING: Removing unreachable block (ram,0xf001ba5c) */
/* WARNING: Removing unreachable block (ram,0xf001baa0) */
/* WARNING: Removing unreachable block (ram,0xf001bb6c) */
/* WARNING: Removing unreachable block (ram,0xf001bbc0) */
/* WARNING: Removing unreachable block (ram,0xf001bc3c) */
/* WARNING: Removing unreachable block (ram,0xf001bb50) */
/* WARNING: Removing unreachable block (ram,0xf001ba08) */

undefined8 _ptcread(uint param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  uint *puVar7;
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
  iVar6 = (param_1 & 0xff) * 0x10;
  iVar5 = *(int *)(DAT_f012f20c + iVar6);
  puVar7 = *(uint **)(DAT_f012f20c + iVar6 + 4);
  uVar1 = *(uint *)(iVar5 + 0x40);
  while( true ) {
    if ((uVar1 & 4) != 0) {
      uVar1 = *puVar7;
      if ((uVar1 & 8) != 0) {
        puVar2 = (undefined *)(uint)*(byte *)(puVar7 + 3);
        if (puVar2 != (undefined *)0x0) {
          _ureadc(puVar2,param_2);
          if (puVar2 == (undefined *)0x0) {
            if ((puVar7[3] & 0x40000000) == 0) {
              *(undefined *)(puVar7 + 3) = 0;
            }
            else {
              *(undefined *)((int)register0x00000038 + -0x90) = *(undefined *)(iVar5 + 0x49);
              *(undefined *)((int)register0x00000038 + -0x8f) = *(undefined *)(iVar5 + 0x4a);
              *(undefined *)((int)register0x00000038 + -0x8e) = *(undefined *)(iVar5 + 0x4d);
              *(undefined *)((int)register0x00000038 + -0x8d) = *(undefined *)(iVar5 + 0x4e);
              *(sword *)((int)register0x00000038 + -0x8c) = (sword)*(undefined4 *)(iVar5 + 0x3c);
              _bcopy(iVar5 + 0x4f,(undefined *)((int)register0x00000038 + -0x8a),6);
              _bcopy(iVar5 + 0x55,(undefined *)((int)register0x00000038 + -0x84),6);
              *(undefined4 *)((int)register0x00000038 + -0x7c) = *(undefined4 *)(iVar5 + 0x40);
              *(uint *)((int)register0x00000038 + -0x78) = (uint)*(word *)(iVar5 + 0x3c);
              uVar1 = 0x1c;
              if (*(uint *)(param_2 + 0x14) < 0x1c) {
                uVar1 = *(uint *)(param_2 + 0x14);
              }
              _uiomove((undefined *)((int)register0x00000038 + -0x90),uVar1,0,param_2);
              *(undefined *)(puVar7 + 3) = 0;
            }
            puVar2 = (undefined *)0x0;
          }
          goto locret_F001BC64;
        }
        uVar1 = *puVar7;
      }
      if ((uVar1 & 0x80) == 0) {
        iVar6 = *(int *)(iVar5 + 0x18);
      }
      else {
        puVar2 = (undefined *)(uint)*(byte *)((int)puVar7 + 0xd);
        if (puVar2 != (undefined *)0x0) {
          _ureadc(puVar2,param_2);
          if (puVar2 == (undefined *)0x0) {
            *(undefined *)((int)puVar7 + 0xd) = 0;
            puVar2 = (undefined *)0x0;
          }
          goto locret_F001BC64;
        }
        iVar6 = *(int *)(iVar5 + 0x18);
      }
      uVar1 = *(uint *)(iVar5 + 0x40);
      if ((iVar6 != 0) && ((uVar1 & 0x100) == 0)) {
        puVar3 = (undefined *)0x0;
        puVar2 = (undefined *)0x0;
        if ((*puVar7 & 0x88) != 0) {
          _ureadc(0,param_2);
          puVar2 = puVar3;
        }
        iVar6 = *(int *)(param_2 + 0x14);
        if ((iVar6 < 1) || (puVar2 != (undefined *)0x0)) goto loc_F001BBE8;
        puVar3 = (undefined *)((int)register0x00000038 + -0x70);
        goto loc_F001BB9C;
      }
    }
    if ((uVar1 & 0x10) == 0) {
      puVar2 = (undefined *)0x5;
      goto locret_F001BC64;
    }
    if ((*puVar7 & 4) != 0) break;
    _sleep(iVar5 + 0x1c,0x1c);
    uVar1 = *(uint *)(iVar5 + 0x40);
  }
  puVar2 = (undefined *)0x23;
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
    puVar2 = (undefined *)0xb;
  }
locret_F001BC64:
  return CONCAT44(param_2,puVar2);
loc_F001BB9C:
  if (100 < iVar6) {
    iVar6 = 100;
  }
  iVar4 = iVar5 + 0x18;
  _q_to_b(iVar5 + 0x18,puVar3,iVar6);
  if (iVar4 < 1) goto loc_F001BBE8;
  puVar2 = puVar3;
  _uiomove(puVar3,iVar4,0,param_2);
  iVar6 = *(int *)(param_2 + 0x14);
  if ((iVar6 < 1) || (puVar2 != (undefined *)0x0)) goto loc_F001BBE8;
  goto loc_F001BB9C;
loc_F001BBE8:
  if (*(int *)(iVar5 + 0x18) <= (int)*(sword *)(_ttlowat + (*(byte *)(iVar5 + 0x4a) & 0x1f) * 2)) {
    if ((*(uint *)(iVar5 + 0x40) & 0x40) != 0) {
      *(uint *)(iVar5 + 0x40) = *(uint *)(iVar5 + 0x40) & 0xffffffbf;
      _wakeup(iVar5 + 0x18);
    }
    if (*(int *)(iVar5 + 0x2c) != 0) {
      _selwakeup(*(int *)(iVar5 + 0x2c),*(uint *)(iVar5 + 0x40) & 0x1000);
      _thread_deallocate(*(undefined4 *)(iVar5 + 0x2c));
      *(undefined4 *)(iVar5 + 0x2c) = 0;
      *(uint *)(iVar5 + 0x40) = *(uint *)(iVar5 + 0x40) & 0xffffefff;
    }
  }
  goto locret_F001BC64;
}
/* GHIDRADEC_FUNCTION index=370 start=0xf001bc6c */

/* WARNING: Removing unreachable block (ram,0xf001bcd4) */

undefined8 _ptsstop(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
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
  puVar2 = *(uint **)(DAT_f012f210 + (*(word *)(param_1 + 0x38) & 0xff) * 0x10);
  if (*(word *)(param_1 + 0x38) != 0) {
    if (param_2 == 0) {
      param_2 = 4;
      uVar1 = *puVar2 | 0x10;
    }
    else {
      uVar1 = *puVar2 & 0xffffffef;
    }
    *puVar2 = uVar1;
    uVar1 = (param_2 & 1) << 1;
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | (byte)param_2;
    if ((param_2 & 2) != 0) {
      uVar1 = uVar1 | 1;
    }
    _ptcwakeup(param_1,uVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=371 start=0xf001bce4 */

/* WARNING: Removing unreachable block (ram,0xf001bddc) */
/* WARNING: Removing unreachable block (ram,0xf001bd78) */
/* WARNING: Removing unreachable block (ram,0xf001bd88) */
/* WARNING: Removing unreachable block (ram,0xf001be4c) */
/* WARNING: Removing unreachable block (ram,0xf001bd48) */

undefined8 _ptcselect(uint param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
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
  iVar4 = (param_1 & 0xff) * 0x10;
  piVar3 = *(int **)(DAT_f012f20c + iVar4);
  uVar1 = piVar3[0x10];
  puVar5 = *(uint **)(DAT_f012f20c + iVar4 + 4);
  if ((uVar1 & 0x10) == 0) {
loc_F001BD80:
    uVar6 = 1;
  }
  else {
    if (param_2 == 1) {
      _spltty();
      if ((((piVar3[0x10] & 4U) != 0) && (piVar3[6] != 0)) && ((piVar3[0x10] & 0x100U) == 0)) {
        _splx(uVar1);
        goto loc_F001BD80;
      }
      _splx(uVar1);
      uVar1 = piVar3[0x10];
loc_F001BD98:
      if ((uVar1 & 4) != 0) {
        if (((*puVar5 & 8) != 0) && (*(char *)(puVar5 + 3) != '\0')) {
          uVar6 = 1;
          goto locret_F001BE70;
        }
        if (((*puVar5 & 0x80) != 0) && (*(char *)((int)puVar5 + 0xd) != '\0')) {
          uVar6 = 1;
          goto locret_F001BE70;
        }
      }
      puVar2 = puVar5 + 1;
      _selthreadcache();
      if (puVar2 == (uint *)0x0) {
        uVar6 = 0;
        goto locret_F001BE70;
      }
      uVar1 = *puVar5 | 1;
    }
    else {
      if (param_2 < 2) {
        if (param_2 != 0) {
          uVar6 = 0;
          goto locret_F001BE70;
        }
        goto loc_F001BD98;
      }
      if (param_2 != 2) {
        uVar6 = 0;
        goto locret_F001BE70;
      }
      if ((uVar1 & 4) != 0) {
        if ((*puVar5 & 0x20) == 0) {
          if (*piVar3 + piVar3[3] < 0x3fe) goto loc_F001BD80;
          if (piVar3[3] != 0) goto loc_F001BE4C;
          uVar1 = piVar3[0xf] & 0x22;
        }
        else {
          uVar1 = piVar3[3];
        }
        if (uVar1 == 0) {
          uVar6 = 1;
          goto locret_F001BE70;
        }
      }
loc_F001BE4C:
      puVar2 = puVar5 + 2;
      _selthreadcache();
      if (puVar2 == (uint *)0x0) {
        uVar6 = 0;
        goto locret_F001BE70;
      }
      uVar1 = *puVar5 | 2;
    }
    *puVar5 = uVar1;
    uVar6 = 0;
  }
locret_F001BE70:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=372 start=0xf001be78 */

/* WARNING: Removing unreachable block (ram,0xf001bfc0) */
/* WARNING: Removing unreachable block (ram,0xf001bfb0) */
/* WARNING: Removing unreachable block (ram,0xf001c088) */
/* WARNING: Removing unreachable block (ram,0xf001bf8c) */
/* WARNING: Removing unreachable block (ram,0xf001bfb8) */
/* WARNING: Removing unreachable block (ram,0xf001c170) */
/* WARNING: Removing unreachable block (ram,0xf001bf5c) */
/* WARNING: Removing unreachable block (ram,0xf001c030) */

undefined8 _ptcwrite(uint param_1,int *param_2)

{
  undefined uVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int *piVar5;
  undefined *puVar6;
  undefined4 unaff_l3;
  int *piVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  uint *puVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined *puVar11;
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
  puVar6 = (undefined *)0x0;
  iVar10 = (param_1 & 0xff) * 0x10;
  piVar5 = *(int **)(DAT_f012f20c + iVar10);
  iVar4 = 0;
  piVar7 = (int *)*param_2;
  iVar8 = 0;
  puVar9 = *(uint **)(DAT_f012f20c + iVar10 + 4);
  uVar2 = piVar5[0x10];
  do {
    if ((uVar2 & 4) != 0) {
      if ((*puVar9 & 0x20) == 0) {
        iVar10 = param_2[1];
        if (0 < iVar10) {
          do {
            piVar7 = (int *)*param_2;
            if (iVar4 == 0) {
              iVar3 = piVar7[1];
              if (iVar3 != 0) {
                if (100 < iVar3) {
                  iVar3 = 100;
                }
                puVar6 = (undefined *)((int)register0x00000038 + -0x70);
                puVar11 = puVar6;
                _uiomove(puVar6,iVar3,1,param_2);
                if (puVar11 == (undefined *)0x0) {
                  iVar4 = iVar3;
                  if ((piVar5[0x10] & 4U) != 0) goto loc_F001C0CC;
                  puVar11 = (undefined *)0x5;
                }
                goto locret_F001C180;
              }
              param_2[1] = iVar10 + -1;
              *param_2 = *param_2 + 8;
            }
            else {
loc_F001C0CC:
              for (; 0 < iVar4; iVar4 = iVar4 + -1) {
                if ((0x3fd < *piVar5 + piVar5[3]) &&
                   ((0 < piVar5[3] || ((piVar5[0xf] & 0x22U) != 0)))) {
                  _wakeup(piVar5);
                  uVar2 = piVar5[0x10];
                  goto loc_F001C0F4;
                }
                iVar8 = iVar8 + 1;
                uVar1 = *puVar6;
                puVar6 = puVar6 + 1;
                (**(code **)(DAT_f010b8e0 + *(char *)((int)piVar5 + 0x47) * 0x30))(uVar1,piVar5);
              }
              iVar4 = 0;
            }
            iVar10 = param_2[1];
          } while (0 < iVar10);
          puVar11 = (undefined *)0x0;
          goto locret_F001C180;
        }
        goto loc_F001BFC8;
      }
      if (piVar5[3] == 0) {
        iVar8 = param_2[1];
        if (iVar8 < 1) goto loc_F001BFAC;
        iVar10 = piVar5[3];
        break;
      }
      uVar2 = piVar5[0x10];
    }
loc_F001C0F4:
    if ((uVar2 & 0x10) == 0) goto loc_F001C0FC;
    if ((*puVar9 & 4) != 0) goto loc_f001c110;
    _sleep(piVar5 + 1,0x1d);
    uVar2 = piVar5[0x10];
  } while( true );
loc_F001BEEC:
  if (0x3fe < iVar10) goto loc_F001BFAC;
  iVar3 = *(int *)(*param_2 + 4);
  if (iVar3 == 0) {
    param_2[1] = iVar8 + -1;
    *param_2 = *param_2 + 8;
  }
  else {
    if (iVar4 == 0) {
      if (100 < iVar3) {
        iVar3 = 100;
      }
      iVar4 = iVar3;
      if (0x3ff - iVar10 < iVar3) {
        iVar4 = 0x3ff - iVar10;
      }
      puVar6 = (undefined *)((int)register0x00000038 + -0x70);
      puVar11 = puVar6;
      _uiomove(puVar6,iVar4,1,param_2);
      if (puVar11 != (undefined *)0x0) goto locret_F001C180;
      if ((piVar5[0x10] & 4U) == 0) goto loc_F001C0FC;
    }
    if (iVar4 != 0) {
      _b_to_q(puVar6,iVar4,piVar5 + 3);
    }
    iVar4 = 0;
  }
  iVar8 = param_2[1];
  if (iVar8 < 1) goto loc_F001BFAC;
  iVar10 = piVar5[3];
  goto loc_F001BEEC;
loc_F001BFAC:
  _putc(0,piVar5 + 3);
  _ttwakeup(piVar5);
  _wakeup(piVar5 + 3);
  goto loc_F001BFC8;
loc_F001C0FC:
  puVar11 = (undefined *)0x5;
  goto locret_F001C180;
loc_f001c110:
  *piVar7 = *piVar7 - iVar4;
  piVar7[1] = piVar7[1] + iVar4;
  param_2[5] = param_2[5] + iVar4;
  param_2[2] = param_2[2] - iVar4;
  if (iVar8 == 0) {
    puVar11 = (undefined *)0x23;
    if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
      puVar11 = (undefined *)0xb;
    }
    goto locret_F001C180;
  }
loc_F001BFC8:
  puVar11 = (undefined *)0x0;
locret_F001C180:
  return CONCAT44(param_2,puVar11);
}
/* GHIDRADEC_FUNCTION index=373 start=0xf001c188 */

/* WARNING: Removing unreachable block (ram,0xf001c1e8) */
/* WARNING: Removing unreachable block (ram,0xf001c620) */
/* WARNING: Removing unreachable block (ram,0xf001c49c) */
/* WARNING: Removing unreachable block (ram,0xf001c408) */
/* WARNING: Removing unreachable block (ram,0xf001c448) */
/* WARNING: Removing unreachable block (ram,0xf001c3d8) */
/* WARNING: Removing unreachable block (ram,0xf001c530) */
/* WARNING: Removing unreachable block (ram,0xf001c6b8) */
/* WARNING: Removing unreachable block (ram,0xf001c228) */
/* WARNING: Removing unreachable block (ram,0xf001c43c) */

undefined8 _ptyioctl(uint param_1,uint param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar1 = (param_1 & 0xff) * 0x10;
  iVar6 = *(int *)(DAT_f012f20c + iVar1);
  puVar5 = *(uint **)(DAT_f012f20c + iVar1 + 4);
  if (param_2 == 0x80047461) {
    if (*param_3 == 0) {
      if ((*(uint *)(iVar6 + 0x40) & 0x400000) == 0) {
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      else {
        if ((*puVar5 & 8) != 0) {
          *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) | 0x40;
          _ptcwakeup(iVar6);
        }
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      uVar3 = uVar3 & 0xffbfffff;
    }
    else {
      if ((*puVar5 & 8) == 0) {
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      else {
        *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) | 0x40;
        _ptcwakeup(iVar6);
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      uVar3 = uVar3 | 0x400000;
    }
    *(uint *)(iVar6 + 0x40) = uVar3;
loc_F001C240:
    iVar1 = 0;
    goto locret_F001C6C0;
  }
  if (*(code **)(_cdevsw + ((param_1 & 0xffff) >> 8) * 0x2c) == _ptcopen) {
    if (param_2 == 0x80047470) {
      uVar3 = *puVar5;
      if (*param_3 == 0) {
        uVar3 = uVar3 & 0xfffffff7;
      }
      else {
        iVar1 = 0x16;
        if ((uVar3 & 0x80) != 0) goto locret_F001C6C0;
        uVar3 = uVar3 | 8;
      }
      goto loc_F001C400;
    }
    if ((int)param_2 < -0x7ffb8b8f) {
      if (param_2 == 0x80047401) {
loc_F001C408:
        do {
          iVar1 = iVar6 + 0x18;
          _getc();
        } while (-1 < iVar1);
      }
      else if ((int)param_2 < -0x7ffb8bfe) {
        if (param_2 == 0x8004667e) {
          if (*param_3 == 0) {
            uVar3 = *puVar5 & 0xfffffffb;
          }
          else {
            uVar3 = *puVar5 | 4;
          }
loc_F001C400:
          *puVar5 = uVar3;
          goto loc_F001C240;
        }
      }
      else {
        if (param_2 == 0x80047466) {
          uVar3 = *puVar5;
          if (*param_3 == 0) {
            uVar3 = uVar3 & 0xffffff7f;
          }
          else {
            iVar1 = 0x16;
            if ((uVar3 & 8) != 0) goto locret_F001C6C0;
            uVar3 = uVar3 | 0x80;
          }
          goto loc_F001C400;
        }
        if (param_2 == 0x80047469) {
          if (*param_3 == 0) {
            uVar3 = *puVar5 & 0xffffffdf;
          }
          else {
            uVar3 = *puVar5 | 0x20;
          }
          *puVar5 = uVar3;
          _ttyflush(iVar6,3);
          iVar1 = 0;
          goto locret_F001C6C0;
        }
      }
    }
    else if ((int)param_2 < -0x7fdb8be9) {
      if ((-0x7fdb8bed < (int)param_2) ||
         (((int)param_2 < -0x7ff98bf5 && (-0x7ff98bf8 < (int)param_2)))) goto loc_F001C408;
    }
    else if (param_2 == 0x2000745f) {
      iVar1 = 0x16;
      if (*param_3 < 0x20) {
        if (-1 < *(int *)(iVar6 + 0x3c)) {
          _ttyflush(iVar6,3);
        }
        _gsignal((int)*(sword *)(iVar6 + 0x44),*param_3);
        iVar1 = 0;
      }
      goto locret_F001C6C0;
    }
  }
  iVar1 = iVar6;
  (**(code **)(_linesw + *(char *)(iVar6 + 0x47) * 0x30 + 0x10))(iVar6,param_2,param_3,param_4);
  if (-1 < iVar1) goto locret_F001C6C0;
  iVar1 = iVar6;
  _ttioctl(iVar6,param_2,param_3,param_4);
  iVar4 = *(char *)(iVar6 + 0x47) * 0x30;
  if (*(int *)(_linesw + iVar4 + 0x2c) != 0) {
    iVar1 = 0x19;
    (**(code **)(_linesw + iVar4 + 4))(iVar6);
    *(undefined *)(iVar6 + 0x47) = 0;
    (*(code *)_linesw._0_4_)((int)(sword)param_1,iVar6);
  }
  if (iVar1 < 0) {
    if (((*puVar5 & 0x80) != 0) && ((param_2 & 0xffffff00) == 0x20007500)) {
      if ((param_2 & 0xff) != 0) {
        *(char *)((int)puVar5 + 0xd) = (char)param_2;
        _ptcwakeup(iVar6,1);
        iVar1 = 0;
        goto locret_F001C6C0;
      }
      goto loc_F001C240;
    }
    iVar1 = 0x19;
    uVar3 = *(uint *)(iVar6 + 0x40);
  }
  else {
    uVar3 = *(uint *)(iVar6 + 0x40);
  }
  if ((uVar3 & 0x400000) == 0) {
    uVar3 = *(uint *)(iVar6 + 0x3c);
    goto loc_F001C614;
  }
  if ((*puVar5 & 8) == 0) {
loc_F001C610:
    uVar3 = *(uint *)(iVar6 + 0x3c);
  }
  else {
    if (-0x7ff98bf6 < (int)param_2) {
      if (param_2 != 0x80067475) {
        if ((int)param_2 < -0x7ff98b8a) {
          if (param_2 == 0x80067411) {
            bVar2 = *(byte *)(puVar5 + 3);
            goto loc_F001C608;
          }
          uVar3 = *(uint *)(iVar6 + 0x3c);
        }
        else {
          if ((int)param_2 < -0x7fdb8be9) {
            iVar4 = -0x7fdb8bec;
            goto loc_F001C5F8;
          }
          uVar3 = *(uint *)(iVar6 + 0x3c);
        }
        goto loc_F001C614;
      }
      bVar2 = *(byte *)(puVar5 + 3);
loc_F001C608:
      *(byte *)(puVar5 + 3) = bVar2 | 0x40;
      goto loc_F001C610;
    }
    if (-0x7ff98bf8 < (int)param_2) {
      bVar2 = *(byte *)(puVar5 + 3);
      goto loc_F001C608;
    }
    if ((int)param_2 < -0x7ffb8b80) {
      iVar4 = -0x7ffb8b83;
loc_F001C5F8:
      if (iVar4 <= (int)param_2) {
        bVar2 = *(byte *)(puVar5 + 3);
        goto loc_F001C608;
      }
      uVar3 = *(uint *)(iVar6 + 0x3c);
    }
    else {
      uVar3 = *(uint *)(iVar6 + 0x3c);
    }
  }
loc_F001C614:
  param_2 = 0;
  if (((uVar3 & 0x20) == 0) &&
     (iVar4 = iVar6, _ttynty(), (*(uint *)(iVar4 + 0x10) & 0x4000000) != 0)) {
    param_2 = (uint)((*(uint *)(iVar6 + 0x50) & 0xffff00) == 0x111300);
  }
  if ((*puVar5 & 0x40) == 0) {
    if (param_2 != 0) goto locret_F001C6C0;
    *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) & 0xdf | 0x10;
    uVar3 = *puVar5 | 0x40;
  }
  else {
    if (param_2 == 0) goto locret_F001C6C0;
    *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) & 0xef | 0x20;
    uVar3 = *puVar5 & 0xffffffbf;
  }
  *puVar5 = uVar3;
  _ptcwakeup(iVar6,1);
locret_F001C6C0:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=374 start=0xf001c6c8 */

/* WARNING: Removing unreachable block (ram,0xf001c7f0) */
/* WARNING: Removing unreachable block (ram,0xf001c710) */
/* WARNING: Removing unreachable block (ram,0xf001c7e4) */
/* WARNING: Removing unreachable block (ram,0xf001c6cc) */

undefined8 _getc(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
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
  piVar1 = param_1;
  _spltty();
  if (*param_1 < 1) {
    uVar6 = 0xffffffff;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  else {
    pbVar3 = (byte *)param_1[1];
    uVar6 = (uint)*pbVar3;
    iVar2 = (int)((uint)pbVar3 & 0x3f) >> 3;
    if (((int)*(char *)(iVar2 + ((uint)pbVar3 & 0xffffffc0) + 4) >>
         ((char)((uint)pbVar3 & 0x3f) + (char)iVar2 * -8 & 0x1fU) & 1U) != 0) {
      uVar6 = uVar6 | 0x100;
    }
    iVar2 = *param_1;
    param_1[1] = (int)(pbVar3 + 1);
    *param_1 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      param_1[2] = 0;
      puVar5 = (undefined4 *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      *puVar5 = _cfreelist;
      _cfreelist = puVar5;
    }
    else {
      uVar4 = param_1[1];
      if ((uVar4 & 0x3f) != 0) goto loc_F001C7F0;
      param_1[1] = *(int *)(uVar4 - 0x40) + 0xc;
      *(undefined4 **)(uVar4 - 0x40) = _cfreelist;
      _cfreelist = (undefined4 *)(uVar4 - 0x40);
    }
    _cfreecount = _cfreecount + 0x34;
    if (_cwaiting._0_1_ != '\0') {
      _wakeup(&_cwaiting);
      _cwaiting._0_1_ = '\0';
    }
  }
loc_F001C7F0:
  _splx(piVar1);
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=375 start=0xf001c800 */

/* WARNING: Removing unreachable block (ram,0xf001c960) */
/* WARNING: Removing unreachable block (ram,0xf001c8f4) */
/* WARNING: Removing unreachable block (ram,0xf001c88c) */
/* WARNING: Removing unreachable block (ram,0xf001c948) */
/* WARNING: Removing unreachable block (ram,0xf001c838) */
/* WARNING: Removing unreachable block (ram,0xf001c818) */

undefined8 _q_to_b(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar7;
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
  iVar7 = param_2;
  if (param_3 < 1) {
    param_2 = 0;
  }
  else {
    piVar2 = param_1;
    _spltty();
    if (*param_1 < 1) {
      *param_1 = 0;
      param_1[2] = 0;
      param_1[1] = 0;
      _splx();
      param_2 = 0;
    }
    else {
      uVar4 = param_1[1];
      while( true ) {
        iVar6 = 0x40 - (uVar4 & 0x3f);
        if (param_3 < iVar6) {
          iVar6 = param_3;
        }
        if (*param_1 < iVar6) {
          iVar6 = *param_1;
        }
        _bcopy(uVar4,iVar7,iVar6);
        param_3 = param_3 - iVar6;
        iVar7 = iVar7 + iVar6;
        iVar3 = *param_1;
        param_1[1] = param_1[1] + iVar6;
        *param_1 = iVar3 - iVar6;
        if (iVar3 - iVar6 < 1) break;
        uVar4 = param_1[1];
        if ((uVar4 & 0x3f) == 0) {
          param_1[1] = *(int *)(uVar4 - 0x40) + 0xc;
          *(undefined4 **)(uVar4 - 0x40) = _cfreelist;
          _cfreecount = _cfreecount + 0x34;
          _cfreelist = (undefined4 *)(uVar4 - 0x40);
          if (_cwaiting._0_1_ != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting._0_1_ = '\0';
          }
        }
        if (param_3 == 0) goto loc_F001C960;
        uVar4 = param_1[1];
      }
      param_1[2] = 0;
      cVar1 = _cwaiting._0_1_;
      puVar5 = (undefined4 *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      *puVar5 = _cfreelist;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = puVar5;
      if (cVar1 != '\0') {
        _wakeup(&_cwaiting);
        _cwaiting._0_1_ = '\0';
      }
loc_F001C960:
      _splx(piVar2);
      param_2 = iVar7 - param_2;
    }
  }
  return CONCAT44(iVar7,param_2);
}
/* GHIDRADEC_FUNCTION index=376 start=0xf001c974 */

/* WARNING: Removing unreachable block (ram,0xf001c9f8) */
/* WARNING: Removing unreachable block (ram,0xf001c978) */

undefined8 _ndqb(int *param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  piVar2 = param_1;
  _spltty();
  iVar3 = *param_1;
  if (iVar3 < 1) {
    iVar6 = -iVar3;
  }
  else {
    pcVar4 = (char *)param_1[1];
    iVar6 = ((uint)(pcVar4 + 0x34) & 0xffffffc0) - (int)pcVar4;
    if (iVar3 < iVar6) {
      iVar6 = iVar3;
    }
    if ((param_2 != 0) && (pcVar5 = pcVar4 + iVar6, pcVar4 < pcVar5)) {
      cVar1 = *pcVar4;
      while (((int)cVar1 & param_2) == 0) {
        pcVar4 = pcVar4 + 1;
        if (pcVar5 <= pcVar4) goto loc_F001C9F8;
        cVar1 = *pcVar4;
      }
      iVar6 = (int)pcVar4 - param_1[1];
    }
  }
loc_F001C9F8:
  _splx(piVar2);
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=377 start=0xf001ca08 */

/* WARNING: Removing unreachable block (ram,0xf001cb0c) */
/* WARNING: Removing unreachable block (ram,0xf001cac0) */
/* WARNING: Removing unreachable block (ram,0xf001cb40) */
/* WARNING: Removing unreachable block (ram,0xf001ca0c) */

undefined8 _ndflush(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
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
  bool bVar8;
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
  piVar3 = param_1;
  _spltty();
  if (0 < *param_1) {
    iVar4 = *param_1;
    if (param_2 < 1) {
loc_F001CB28:
      bVar8 = iVar4 == 0;
    }
    else {
      while( true ) {
        piVar1 = _cfreelist;
        bVar7 = iVar4 == 0;
        iVar4 = 0;
        bVar8 = true;
        if (bVar7) break;
        piVar5 = (int *)param_1[2];
        piVar6 = (int *)(param_1[1] & 0xffffffc0);
        if (piVar6 != (int *)((int)piVar5 - 1U & 0xffffffc0)) {
          piVar5 = piVar6 + 0x10;
        }
        iVar4 = (int)piVar5 - param_1[1];
        if (param_2 < iVar4) {
          *param_1 = *param_1 - param_2;
          param_1[1] = param_1[1] + param_2;
          cVar2 = _cwaiting._0_1_;
          if (*param_1 < 1) {
            *piVar6 = (int)_cfreelist;
            _cfreecount = _cfreecount + 0x34;
            _cfreelist = piVar6;
            if (cVar2 != '\0') {
              _wakeup(&_cwaiting);
              _cwaiting._0_1_ = '\0';
            }
          }
loc_F001CB24:
          iVar4 = *param_1;
          goto loc_F001CB28;
        }
        param_2 = param_2 - iVar4;
        *param_1 = *param_1 - iVar4;
        _cfreecount = _cfreecount + 0x34;
        bVar8 = _cwaiting._0_1_ != '\0';
        _cfreelist = piVar6;
        param_1[1] = *piVar6 + 0xc;
        *piVar6 = (int)piVar1;
        if (bVar8) {
          _wakeup(&_cwaiting);
          _cwaiting._0_1_ = '\0';
        }
        if (param_2 < 1) goto loc_F001CB24;
        iVar4 = *param_1;
      }
    }
    if (bVar8 || iVar4 < 0) {
      param_1[2] = 0;
      param_1[1] = 0;
      *param_1 = 0;
    }
  }
  _splx(piVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=378 start=0xf001cb50 */

/* WARNING: Removing unreachable block (ram,0xf001cc68) */
/* WARNING: Removing unreachable block (ram,0xf001cc28) */
/* WARNING: Removing unreachable block (ram,0xf001cbac) */
/* WARNING: Removing unreachable block (ram,0xf001cbdc) */
/* WARNING: Removing unreachable block (ram,0xf001cb54) */

undefined8 _putc(uint param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar8;
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
  uVar3 = param_1;
  _spltty();
  puVar1 = _cfreelist;
  puVar6 = (undefined4 *)param_2[2];
  if ((puVar6 == (undefined4 *)0x0) || (*param_2 < 0)) {
    puVar6 = _cfreelist + 1;
    if (_cfreelist == (undefined4 *)0x0) {
loc_F001CBDC:
      _splx(uVar3);
      uVar7 = 0xffffffff;
      goto locret_F001CC74;
    }
    _cfreecount = _cfreecount + -0x34;
    puVar2 = (undefined4 *)*_cfreelist;
    *_cfreelist = 0;
    _cfreelist = puVar2;
    _bzero(puVar6,8);
    param_2[1] = (int)(puVar1 + 3);
loc_F001CC10:
    puVar6 = puVar1 + 3;
  }
  else if (((uint)puVar6 & 0x3f) == 0) {
    bVar8 = _cfreelist == (undefined4 *)0x0;
    puVar6[-0x10] = _cfreelist;
    if (bVar8) goto loc_F001CBDC;
    _cfreelist = (undefined4 *)*puVar1;
    _cfreecount = _cfreecount + -0x34;
    *puVar1 = 0;
    goto loc_F001CC10;
  }
  if ((param_1 & 0x100) != 0) {
    iVar4 = (int)((uint)puVar6 & 0x3f) >> 3;
    iVar5 = iVar4 + ((uint)puVar6 & 0xffffffc0);
    *(byte *)(iVar5 + 4) =
         *(byte *)(iVar5 + 4) |
         (byte)(1 << ((char)((uint)puVar6 & 0x3f) + (char)iVar4 * -8 & 0x1fU));
  }
  *(char *)puVar6 = (char)param_1;
  param_2[2] = (int)puVar6 + 1;
  *param_2 = *param_2 + 1;
  _splx(uVar3);
  uVar7 = 0;
locret_F001CC74:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=379 start=0xf001cc7c */

/* WARNING: Removing unreachable block (ram,0xf001cd80) */
/* WARNING: Removing unreachable block (ram,0xf001ccf0) */
/* WARNING: Removing unreachable block (ram,0xf001cd54) */
/* WARNING: Removing unreachable block (ram,0xf001cdac) */
/* WARNING: Removing unreachable block (ram,0xf001cc98) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _b_to_q(int param_1,undefined *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar7;
  undefined4 unaff_i1;
  undefined *puVar8;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  puVar8 = param_2;
  if ((int)param_2 < 1) {
    puVar7 = (undefined *)0x0;
    goto locret_F001CDB4;
  }
  iVar2 = param_1;
  _spltty();
  puVar1 = _cfreelist;
  puVar6 = (undefined4 *)param_3[2];
  puVar7 = param_2;
  if ((puVar6 == (undefined4 *)0x0) || (*param_3 < 0)) {
    puVar3 = _cfreelist + 1;
    if (_cfreelist != (undefined4 *)0x0) {
      puVar6 = _cfreelist + 3;
      _cfreelist = (undefined4 *)*_cfreelist;
      _cfreecount = _cfreecount + -0x34;
      _bzero(puVar3,8);
      *puVar1 = 0;
      param_3[1] = (int)puVar6;
      goto loc_F001CD04;
    }
loc_F001CD98:
    param_3[2] = (int)puVar6;
  }
  else {
loc_F001CD04:
    if (param_2 != (undefined *)0x0) {
      puVar8 = DAT_f010f000;
      do {
        puVar1 = _cfreelist;
        if (((uint)puVar6 & 0x3f) == 0) {
          bVar9 = _cfreelist == (undefined4 *)0x0;
          puVar6[-0x10] = _cfreelist;
          if (bVar9) break;
          _cfreelist = (undefined4 *)*puVar1;
          puVar6 = puVar1 + 3;
          _cfreecount = _cfreecount + -0x34;
          _bzero(puVar1 + 1,8);
          *puVar1 = 0;
        }
        puVar4 = (undefined *)(0x40 - ((uint)puVar6 & 0x3f));
        puVar5 = puVar7;
        if (puVar4 <= puVar7) {
          puVar5 = puVar4;
        }
        _bcopy(param_1,puVar6,puVar5);
        param_1 = param_1 + (int)puVar5;
        puVar7 = puVar7 + -(int)puVar5;
        puVar6 = (undefined4 *)((int)puVar6 + (int)puVar5);
      } while (puVar7 != (undefined *)0x0);
      goto loc_F001CD98;
    }
    param_3[2] = (int)puVar6;
  }
  *param_3 = (int)(param_2 + (*param_3 - (int)puVar7));
  _splx(iVar2);
locret_F001CDB4:
  return CONCAT44(puVar8,puVar7);
}
/* GHIDRADEC_FUNCTION index=380 start=0xf001cdbc */

undefined8 _nextc(int *param_1,int param_2)

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
  if (*param_1 != 0) {
    uVar1 = param_2 + 1;
    if (uVar1 != param_1[2]) {
      if ((uVar1 & 0x3f) == 0) {
        uVar1 = *(int *)(param_2 + -0x3f) + 0xc;
      }
      goto locret_F001CE00;
    }
  }
  uVar1 = 0;
locret_F001CE00:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=381 start=0xf001ce08 */

/* WARNING: Removing unreachable block (ram,0xf001ce60) */

undefined8 _nextc3(int *param_1,uint param_2,uint *param_3)

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
  char *pcVar2;
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
  if (*param_1 != 0) {
    pcVar2 = (char *)(param_2 + 1);
    if (pcVar2 != (char *)param_1[2]) {
      if (((uint)pcVar2 & 0x3f) == 0) {
        pcVar2 = (char *)(*(int *)(param_2 - 0x3f) + 0xc);
      }
      param_2 = (uint)pcVar2 & 0x3f;
      cVar1 = *pcVar2;
      *param_3 = (int)cVar1;
      if (((int)*(char *)(((int)param_2 >> 3) + ((uint)pcVar2 & 0xffffffc0) + 4) >>
           ((char)param_2 + (char)((int)param_2 >> 3) * -8 & 0x1fU) & 1U) != 0) {
        *param_3 = (int)cVar1 | 0x100;
      }
      goto locret_F001CE94;
    }
  }
  pcVar2 = (char *)0x0;
locret_F001CE94:
  return CONCAT44(param_2,pcVar2);
}
/* GHIDRADEC_FUNCTION index=382 start=0xf001ce9c */

/* WARNING: Removing unreachable block (ram,0xf001cfc8) */
/* WARNING: Removing unreachable block (ram,0xf001cee4) */
/* WARNING: Removing unreachable block (ram,0xf001cea0) */

undefined8 _unputc(int *param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
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
  piVar1 = param_1;
  _spltty();
  if (*param_1 < 1) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar3 = param_1[2];
    uVar2 = iVar3 - 1;
    param_1[2] = uVar2;
    uVar6 = (uint)*(char *)(iVar3 + -1);
    iVar3 = (int)(uVar2 & 0x3f) >> 3;
    if (((int)*(char *)(iVar3 + (uVar2 & 0xffffffc0) + 4) >>
         ((char)(uVar2 & 0x3f) + (char)iVar3 * -8 & 0x1fU) & 1U) != 0) {
      uVar6 = uVar6 | 0x100;
    }
    iVar3 = *param_1;
    *param_1 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      param_1[1] = 0;
      uVar2 = param_1[2];
      param_1[2] = 0;
      *(undefined4 *)(uVar2 & 0xffffffc0) = _cfreelist;
      _cfreelist = (undefined4 *)(uVar2 & 0xffffffc0);
    }
    else {
      uVar2 = param_1[2] & 0xffffffc0;
      if (param_1[2] != uVar2 + 0xc) goto loc_F001CFC8;
      param_1[2] = uVar2;
      puVar4 = (uint *)(param_1[1] & 0xffffffc0);
      if (*puVar4 != uVar2) {
        for (puVar4 = (uint *)*puVar4; *puVar4 != uVar2; puVar4 = (uint *)*puVar4) {
        }
      }
      param_1[2] = (int)(puVar4 + 0x10);
      puVar5 = (undefined4 *)*puVar4;
      *puVar5 = _cfreelist;
      _cfreelist = puVar5;
      *puVar4 = 0;
    }
    _cfreecount = _cfreecount + 0x34;
  }
loc_F001CFC8:
  _splx(piVar1);
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=383 start=0xf001cfd8 */

/* WARNING: Removing unreachable block (ram,0xf001d040) */
/* WARNING: Removing unreachable block (ram,0xf001d024) */
/* WARNING: Removing unreachable block (ram,0xf001d02c) */
/* WARNING: Removing unreachable block (ram,0xf001d018) */
/* WARNING: Removing unreachable block (ram,0xf001cfdc) */

undefined8 _catq(int *param_1,int *param_2)

{
  int *piVar1;
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
  piVar1 = param_1;
  _spltty();
  if (*param_2 == 0) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    _splx(piVar1);
  }
  else {
    _splx(piVar1);
    while (piVar1 = param_1, _getc(), -1 < (int)piVar1) {
      _putc();
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=384 start=0xf001d054 */

undefined8 _syopen(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 6;
  if (*(int *)(_active_u + 0x164) != 0) {
    iVar1 = (int)(sword)*(word *)(_active_u + 0x168);
    (**(code **)(_cdevsw + (uint)(*(word *)(_active_u + 0x168) >> 8) * 0x2c))(iVar1,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=385 start=0xf001d0b4 */

undefined8 _syread(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 6;
  if (*(int *)(_active_u + 0x164) != 0) {
    iVar1 = (int)(sword)*(word *)(_active_u + 0x168);
    (**(code **)(DAT_f011c9f8 + (uint)(*(word *)(_active_u + 0x168) >> 8) * 0x2c))(iVar1,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=386 start=0xf001d118 */

undefined8 _sywrite(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 6;
  if (*(int *)(_active_u + 0x164) != 0) {
    iVar1 = (int)(sword)*(word *)(_active_u + 0x168);
    (**(code **)(DAT_f011c9fc + (uint)(*(word *)(_active_u + 0x168) >> 8) * 0x2c))(iVar1,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=387 start=0xf001d17c */

/* WARNING: Removing unreachable block (ram,0xf001d1a0) */

undefined8 _syioctl(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  if (param_2 == (undefined *)0x20007471) {
    param_2 = DAT_f0133c00;
    iVar4 = *_active_u;
    iVar1 = (int)*(sword *)(iVar4 + 0x30);
    _get_posix_proc();
    iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
    if (*(int *)(iVar2 + 4) == iVar4) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar1 + 0x10) + 8) + 0xc) = 0;
      uVar3 = *(uint *)(iVar4 + 0x28);
    }
    else {
      uVar3 = *(uint *)(iVar4 + 0x28);
    }
    *(uint *)(iVar4 + 0x28) = uVar3 & 0xbfffffff;
    _active_u[0x59] = 0;
    iVar1 = 0;
    *(undefined2 *)(_active_u + 0x5a) = 0;
  }
  else {
    iVar1 = 6;
    if (_active_u[0x59] != 0) {
      iVar1 = (int)(sword)*(word *)(_active_u + 0x5a);
      (**(code **)(DAT_f011ca00 + (uint)(*(word *)(_active_u + 0x5a) >> 8) * 0x2c))
                (iVar1,param_2,param_3,param_4);
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=388 start=0xf001d260 */

undefined8 _syselect(undefined4 param_1,undefined4 param_2)

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
  if (*(int *)(_active_u + 0x164) == 0) {
    iVar1 = 0;
    *(undefined *)(dword_F0133DDC + 0x38) = 6;
  }
  else {
    iVar1 = (int)(sword)*(word *)(_active_u + 0x168);
    (**(code **)(DAT_f011ca0c + (uint)(*(word *)(_active_u + 0x168) >> 8) * 0x2c))(iVar1,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=389 start=0xf001d2d8 */

/* WARNING: Removing unreachable block (ram,0xf001d380) */
/* WARNING: Removing unreachable block (ram,0xf001d388) */
/* WARNING: Removing unreachable block (ram,0xf001d378) */

undefined8 _domaininit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  uint uVar4;
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
  puVar1 = _inetdomain;
  DAT_f010c70c._0_4_ = _unixdomain;
  DAT_f010bbd4._0_4_ = _domains;
  _domains = _inetdomain;
  pcVar3 = (code *)DAT_f010c6f8._0_4_;
  while( true ) {
    if (pcVar3 == (code *)0x0) {
      uVar4 = *(uint *)(puVar1 + 0x14);
    }
    else {
      (*pcVar3)();
      uVar4 = *(uint *)(puVar1 + 0x14);
    }
    if (uVar4 < *(uint *)(puVar1 + 0x18)) {
      pcVar3 = *(code **)(uVar4 + 0x20);
      while( true ) {
        if (pcVar3 == (code *)0x0) {
          uVar2 = *(uint *)(puVar1 + 0x18);
        }
        else {
          (*pcVar3)();
          uVar2 = *(uint *)(puVar1 + 0x18);
        }
        if (uVar2 <= uVar4 + 0x30) break;
        pcVar3 = *(code **)(uVar4 + 0x50);
        uVar4 = uVar4 + 0x30;
      }
      puVar1 = *(undefined **)(puVar1 + 0x1c);
    }
    else {
      puVar1 = *(undefined **)(puVar1 + 0x1c);
    }
    if (puVar1 == (undefined *)0x0) break;
    pcVar3 = *(code **)(puVar1 + 8);
  }
  _null_init();
  _pffasttimo();
  _pfslowtimo();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=390 start=0xf001d398 */

undefined8 _pffindtype(int param_1,int param_2)

{
  sword sVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar4;
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
  if (_domains == (int *)0x0) {
    psVar4 = (sword *)0x0;
  }
  else {
    iVar2 = *_domains;
    piVar3 = _domains;
    while (iVar2 != param_1) {
      piVar3 = (int *)piVar3[7];
      if (piVar3 == (int *)0x0) {
        psVar4 = (sword *)0x0;
        goto locret_F001D418;
      }
      iVar2 = *piVar3;
    }
    psVar4 = (sword *)piVar3[5];
    if (psVar4 < (sword *)piVar3[6]) {
      sVar1 = *psVar4;
      while( true ) {
        if ((sVar1 != 0) && (sVar1 == param_2)) goto locret_F001D418;
        psVar4 = psVar4 + 0x18;
        if ((sword *)piVar3[6] <= psVar4) break;
        sVar1 = *psVar4;
      }
      psVar4 = (sword *)0x0;
    }
    else {
      psVar4 = (sword *)0x0;
    }
  }
locret_F001D418:
  return CONCAT44(param_2,psVar4);
}
/* GHIDRADEC_FUNCTION index=391 start=0xf001d420 */

undefined8 _pffindproto(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar4;
  sword *psVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  sword *psVar6;
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
  if (param_1 == 0) {
loc_F001D464:
    psVar5 = (sword *)0x0;
  }
  else if (_domains == (int *)0x0) {
    psVar5 = (sword *)0x0;
  }
  else {
    iVar2 = *_domains;
    piVar3 = _domains;
    while (iVar2 != param_1) {
      piVar3 = (int *)piVar3[7];
      if (piVar3 == (int *)0x0) goto loc_F001D464;
      iVar2 = *piVar3;
    }
    psVar4 = (sword *)piVar3[5];
    if (psVar4 < (sword *)piVar3[6]) {
      sVar1 = psVar4[4];
      psVar6 = (sword *)0x0;
      while ((sVar1 != param_2 || (psVar5 = psVar4, *psVar4 != param_3))) {
        psVar5 = psVar6;
        if ((param_3 == 3) && (((*psVar4 == 3 && (sVar1 == 0)) && (psVar6 == (sword *)0x0)))) {
          psVar5 = psVar4;
        }
        if ((sword *)piVar3[6] <= psVar4 + 0x18) break;
        sVar1 = psVar4[0x1c];
        psVar4 = psVar4 + 0x18;
        psVar6 = psVar5;
      }
    }
    else {
      psVar5 = (sword *)0x0;
    }
  }
  return CONCAT44(param_2,psVar5);
}
/* GHIDRADEC_FUNCTION index=392 start=0xf001d4ec */

undefined8 _pfctlinput(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  if (_domains != 0) {
    uVar3 = *(uint *)(_domains + 0x14);
    iVar4 = _domains;
    while( true ) {
      if (uVar3 < *(uint *)(iVar4 + 0x18)) {
        pcVar2 = *(code **)(uVar3 + 0x14);
        while( true ) {
          if (pcVar2 == (code *)0x0) {
            uVar1 = *(uint *)(iVar4 + 0x18);
          }
          else {
            (*pcVar2)(param_1,param_2,0);
            uVar1 = *(uint *)(iVar4 + 0x18);
          }
          if (uVar1 <= uVar3 + 0x30) break;
          pcVar2 = *(code **)(uVar3 + 0x44);
          uVar3 = uVar3 + 0x30;
        }
        iVar4 = *(int *)(iVar4 + 0x1c);
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x1c);
      }
      if (iVar4 == 0) break;
      uVar3 = *(uint *)(iVar4 + 0x14);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=393 start=0xf001d564 */

/* WARNING: Removing unreachable block (ram,0xf001d5e8) */

undefined8 _pfslowtimo(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  if (_domains != 0) {
    uVar3 = *(uint *)(_domains + 0x14);
    iVar4 = _domains;
    while( true ) {
      if (uVar3 < *(uint *)(iVar4 + 0x18)) {
        pcVar1 = *(code **)(uVar3 + 0x28);
        while( true ) {
          if (pcVar1 == (code *)0x0) {
            uVar2 = *(uint *)(iVar4 + 0x18);
          }
          else {
            (*pcVar1)();
            uVar2 = *(uint *)(iVar4 + 0x18);
          }
          if (uVar2 <= uVar3 + 0x30) break;
          pcVar1 = *(code **)(uVar3 + 0x58);
          uVar3 = uVar3 + 0x30;
        }
        iVar4 = *(int *)(iVar4 + 0x1c);
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x1c);
      }
      if (iVar4 == 0) break;
      uVar3 = *(uint *)(iVar4 + 0x14);
    }
  }
  _timeout(_pfslowtimo,0,_hz / 2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=394 start=0xf001d5f8 */

/* WARNING: Removing unreachable block (ram,0xf001d680) */
/* WARNING: Removing unreachable block (ram,0xf001d670) */

undefined8 _pffasttimo(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  if (_domains != 0) {
    uVar4 = *(uint *)(_domains + 0x14);
    iVar5 = _domains;
    while( true ) {
      if (uVar4 < *(uint *)(iVar5 + 0x18)) {
        pcVar1 = *(code **)(uVar4 + 0x24);
        while( true ) {
          if (pcVar1 == (code *)0x0) {
            uVar2 = *(uint *)(iVar5 + 0x18);
          }
          else {
            (*pcVar1)();
            uVar2 = *(uint *)(iVar5 + 0x18);
          }
          if (uVar2 <= uVar4 + 0x30) break;
          pcVar1 = *(code **)(uVar4 + 0x54);
          uVar4 = uVar4 + 0x30;
        }
        iVar5 = *(int *)(iVar5 + 0x1c);
      }
      else {
        iVar5 = *(int *)(iVar5 + 0x1c);
      }
      if (iVar5 == 0) break;
      uVar4 = *(uint *)(iVar5 + 0x14);
    }
  }
  uVar3 = _hz;
  .div(_hz,5);
  _timeout(_pffasttimo,0,uVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=395 start=0xf001d690 */

/* WARNING: Removing unreachable block (ram,0xf001d700) */
/* WARNING: Removing unreachable block (ram,0xf001d6d4) */
/* WARNING: Removing unreachable block (ram,0xf001d6b4) */
/* WARNING: Removing unreachable block (ram,0xf001d6ec) */
/* WARNING: Removing unreachable block (ram,0xf001d710) */
/* WARNING: Removing unreachable block (ram,0xf001d6a8) */

undefined8 _mbinit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar1 = -0xfeee400;
  iVar3 = 1;
  if (_page_size < 0x1000) {
    iVar1 = 0x1000;
    .udiv();
    iVar3 = iVar1;
  }
  _spltty();
  iVar3 = iVar3 * 10;
  iVar2 = iVar3;
  _m_clalloc(iVar3,0,0);
  if ((iVar2 == 0) || (_m_clalloc(iVar3,1,0), iVar3 == 0)) {
    _panic(&aMbinit);
  }
  else {
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=396 start=0xf001d720 */

/* WARNING: Removing unreachable block (ram,0xf001d808) */
/* WARNING: Removing unreachable block (ram,0xf001d750) */
/* WARNING: Removing unreachable block (ram,0xf001d7a0) */
/* WARNING: Removing unreachable block (ram,0xf001d858) */
/* WARNING: Removing unreachable block (ram,0xf001d730) */

undefined8 _m_clalloc(uint param_1,undefined2 *param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 unaff_i1;
  undefined2 *puVar5;
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
  uVar1 = param_1;
  .umul(param_1,_page_size);
  puVar3 = _mb_map;
  _kmem_mb_alloc(_mb_map,uVar1 + _page_mask & ~_page_mask);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else if (param_2 == (undefined2 *)0x1) {
    iVar2 = 0;
    .umul(param_1,_page_size);
    param_1 = param_1 >> 10;
    if (param_1 != 0) {
      do {
        puVar4 = puVar3;
        puVar4[1] = 0;
        iVar2 = iVar2 + 1;
        *puVar4 = _mclfree;
        puVar3 = puVar4 + 0x100;
        DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + 1;
        _mclfree = puVar4;
      } while (iVar2 < (int)param_1);
    }
    DAT_f0134af4._0_4_ = DAT_f0134af4._0_4_ + param_1;
  }
  else if ((int)param_2 < 2) {
    if (param_2 == (undefined2 *)0x0) {
      .umul(param_1,_page_size);
      param_1 = param_1 >> 7;
      if (param_1 != 0) {
        puVar3[1] = 0;
        puVar4 = puVar3;
        puVar5 = (undefined2 *)((int)puVar3 + 10);
        while( true ) {
          *puVar5 = 1;
          param_2 = puVar5 + 0x40;
          puVar3 = puVar4 + 0x20;
          param_1 = param_1 - 1;
          DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
          _mbstat._0_4_ = _mbstat._0_4_ + 1;
          _m_free(puVar4);
          if ((int)param_1 < 1) break;
          *(undefined4 *)(puVar5 + 0x3d) = 0;
          puVar4 = puVar3;
          puVar5 = param_2;
        }
      }
    }
  }
  else if (param_2 == (undefined2 *)0x2) {
    DAT_f0134af4._4_4_ = DAT_f0134af4._4_4_ + param_1;
  }
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=397 start=0xf001d888 */

undefined8 _m_pgfree(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=398 start=0xf001d894 */

/* WARNING: Removing unreachable block (ram,0xf001d8b0) */

undefined8 _m_expand(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  bVar1 = false;
  do {
    iVar2 = 1;
    _m_clalloc(1,0,param_1);
    if (iVar2 != 0) {
      uVar6 = 1;
locret_F001D954:
      return CONCAT44(param_2,uVar6);
    }
    if ((param_1 == 0) || (bVar1)) {
      uVar6 = 0;
      goto locret_F001D954;
    }
    if (_domains != 0) {
      uVar5 = *(uint *)(_domains + 0x14);
      iVar2 = _domains;
      while( true ) {
        if (uVar5 < *(uint *)(iVar2 + 0x18)) {
          pcVar3 = *(code **)(uVar5 + 0x2c);
          while( true ) {
            if (pcVar3 == (code *)0x0) {
              uVar4 = *(uint *)(iVar2 + 0x18);
            }
            else {
              (*pcVar3)();
              uVar4 = *(uint *)(iVar2 + 0x18);
            }
            if (uVar4 <= uVar5 + 0x30) break;
            pcVar3 = *(code **)(uVar5 + 0x5c);
            uVar5 = uVar5 + 0x30;
          }
          iVar2 = *(int *)(iVar2 + 0x1c);
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x1c);
        }
        if (iVar2 == 0) break;
        uVar5 = *(uint *)(iVar2 + 0x14);
      }
    }
    DAT_f0134b08 = DAT_f0134b08 + 1;
    bVar1 = true;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=399 start=0xf001d95c */

/* WARNING: Removing unreachable block (ram,0xf001d98c) */
/* WARNING: Removing unreachable block (ram,0xf001d9dc) */
/* WARNING: Removing unreachable block (ram,0xf001d9e8) */
/* WARNING: Removing unreachable block (ram,0xf001d960) */

undefined8 _m_get(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  puVar2 = param_1;
  _spltty();
  puVar1 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    _m_more(param_1,param_2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget);
    }
    *(sword *)((int)puVar1 + 10) = (sword)param_2;
    word_F0134B0C = word_F0134B0C + -1;
    (&word_F0134B0C)[param_2] = (&word_F0134B0C)[param_2] + 1;
    _mfree = (undefined4 *)*puVar1;
    puVar1[1] = 0xc;
    *puVar1 = 0;
    param_1 = puVar1;
  }
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}

