/* GHIDRADEC_FUNCTION index=300 start=0xf001552c */

/* WARNING: Removing unreachable block (ram,0xf0015560) */

undefined8 _read(undefined4 param_1,undefined4 param_2)

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
  iVar1 = *(int *)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(iVar1 + 8);
  *(undefined **)((int)register0x00000038 + -0x20) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  _rwuio((undefined *)((int)register0x00000038 + -0x20),0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=301 start=0xf0015570 */

/* WARNING: Removing unreachable block (ram,0xf00155d4) */
/* WARNING: Removing unreachable block (ram,0xf00155b0) */

undefined8 _readv(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  iVar2 = *(int *)(dword_F0133DDC + 0x24);
  if (*(uint *)(iVar2 + 8) < 0x11) {
    *(undefined **)((int)register0x00000038 + -0x20) =
         (undefined *)((int)register0x00000038 + -0xa0);
    *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(iVar2 + 8);
    uVar1 = *(undefined4 *)(iVar2 + 4);
    _copyin(uVar1,(undefined *)((int)register0x00000038 + -0xa0),*(int *)(iVar2 + 8) << 3);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _rwuio((undefined *)((int)register0x00000038 + -0x20),0);
    }
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=302 start=0xf00155e4 */

/* WARNING: Removing unreachable block (ram,0xf0015618) */

undefined8 _write(undefined4 param_1,undefined4 param_2)

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
  iVar1 = *(int *)(dword_F0133DDC + 0x24);
  *(undefined **)((int)register0x00000038 + -0x20) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(iVar1 + 8);
  _rwuio((undefined *)((int)register0x00000038 + -0x20),1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=303 start=0xf0015628 */

/* WARNING: Removing unreachable block (ram,0xf001568c) */
/* WARNING: Removing unreachable block (ram,0xf0015668) */

undefined8 _writev(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  iVar2 = *(int *)(dword_F0133DDC + 0x24);
  if (*(uint *)(iVar2 + 8) < 0x11) {
    *(undefined **)((int)register0x00000038 + -0x20) =
         (undefined *)((int)register0x00000038 + -0xa0);
    *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(iVar2 + 8);
    uVar1 = *(undefined4 *)(iVar2 + 4);
    _copyin(uVar1,(undefined *)((int)register0x00000038 + -0xa0),*(int *)(iVar2 + 8) << 3);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _rwuio((undefined *)((int)register0x00000038 + -0x20),1);
    }
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=304 start=0xf001569c */

/* WARNING: Removing unreachable block (ram,0xf00158bc) */
/* WARNING: Removing unreachable block (ram,0xf00157b4) */

undefined8 _rwuio(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined uVar4;
  undefined4 uVar3;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
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
  puVar5 = *(uint **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_1;
  uVar8 = *puVar5;
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  uVar1 = _active_u[0x56];
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if (uVar8 < uVar1) {
    iVar6 = *(int *)(_active_u[0x53] + uVar8 * 4);
    *(int *)((int)register0x00000038 + -0x24) = iVar6;
    if ((iVar6 != 0) && (iVar6 != -0x10000)) {
      if (param_2 == 0) {
        uVar1 = *(uint *)(*(int *)((int)register0x00000038 + -0x24) + 8) & 1;
      }
      else {
        uVar1 = *(uint *)(*(int *)((int)register0x00000038 + -0x24) + 8) & 2;
      }
      piVar9 = *(int **)((int)register0x00000038 + -0x1c);
      if (uVar1 != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
        piVar9[5] = 0;
        iVar6 = piVar9[1];
        piVar9[3] = 0;
        iVar7 = *piVar9;
        if (0 < iVar6) {
          do {
            if ((*(int *)(iVar7 + 4) < 0) ||
               (iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x14) +
                        *(int *)(iVar7 + 4),
               *(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x14) = iVar2, iVar2 < 0)) {
              *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
              goto locret_F00158D0;
            }
            iVar2 = *(int *)((int)register0x00000038 + -0x10);
            iVar7 = iVar7 + 8;
            *(int *)((int)register0x00000038 + -0x10) = iVar2 + 1;
          } while (iVar2 + 1 < iVar6);
        }
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)(*(int *)((int)register0x00000038 + -0x1c) + 0x14);
        iVar6 = *(int *)((int)register0x00000038 + -0x24);
        do {
          iVar7 = *(int *)((int)register0x00000038 + -0x1c);
          *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar6 + 0x1c);
          *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(iVar7 + 0x14);
          iVar6 = dword_F0133DDC + 0x28;
          _setjmp();
          iVar7 = *(int *)((int)register0x00000038 + -0x1c);
          if (iVar6 == 0) {
            *(int *)((int)register0x00000038 + -0xc) = *(int *)((int)register0x00000038 + -0xc) + 1;
            uVar3 = *(undefined4 *)((int)register0x00000038 + -0x24);
            (*(code *)**(undefined4 **)(*(int *)((int)register0x00000038 + -0x24) + 0x14))
                      (uVar3,*(undefined4 *)((int)register0x00000038 + 0x48),
                       *(undefined4 *)((int)register0x00000038 + -0x1c));
            uVar4 = (undefined)uVar3;
loc_F0015868:
            *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
loc_F001586C:
            iVar7 = *(int *)((int)register0x00000038 + -0x1c);
            iVar6 = *(int *)((int)register0x00000038 + -0x14);
            iVar2 = *(int *)(iVar7 + 0x14);
          }
          else {
            iVar6 = *(int *)((int)register0x00000038 + -0x14);
            if (*(int *)(iVar7 + 0x14) == iVar6) {
              if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) != 0) {
                uVar4 = 4;
                goto loc_F0015868;
              }
              *(undefined *)(dword_F0133DDC + 0x39) = 2;
              goto loc_F001586C;
            }
            iVar2 = *(int *)(iVar7 + 0x14);
          }
          *(int *)(dword_F0133DDC + 0x30) = iVar6 - iVar2;
          iVar6 = *(int *)((int)register0x00000038 + -0x24);
          *(int *)(iVar6 + 0x1c) =
               *(int *)(iVar6 + 0x1c) +
               (*(int *)((int)register0x00000038 + -0x18) - *(int *)(iVar7 + 0x14));
          if (*(char *)(dword_F0133DDC + 0x38) == '\0') break;
          uVar1 = *(uint *)(iVar6 + 8) & 0x1000;
          _fspause();
          iVar6 = *(int *)((int)register0x00000038 + -0x24);
        } while (uVar1 != 0);
        goto locret_F00158D0;
      }
    }
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 9;
locret_F00158D0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=305 start=0xf00158d8 */

/* WARNING: Removing unreachable block (ram,0xf0015b44) */
/* WARNING: Removing unreachable block (ram,0xf0015ae0) */
/* WARNING: Removing unreachable block (ram,0xf00159d4) */
/* WARNING: Removing unreachable block (ram,0xf0015aa0) */
/* WARNING: Removing unreachable block (ram,0xf0015acc) */
/* WARNING: Removing unreachable block (ram,0xf0015ab8) */
/* WARNING: Removing unreachable block (ram,0xf0015a10) */

undefined8 _ioctl(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  uint *puVar8;
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
  puVar8 = *(uint **)(dword_F0133DDC + 0x24);
  uVar3 = *puVar8;
  if (((uVar3 < *(uint *)(_active_u + 0x158)) &&
      (iVar6 = *(int *)(*(int *)(_active_u + 0x14c) + uVar3 * 4), iVar6 != 0)) &&
     (iVar6 != -0x10000)) {
    if ((*(uint *)(iVar6 + 8) & 3) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 9;
      goto locret_F0015B54;
    }
    uVar5 = puVar8[1];
    if (uVar5 == 0x20006601) {
      *(byte *)(*(int *)(_active_u + 0x150) + uVar3) =
           *(byte *)(*(int *)(_active_u + 0x150) + uVar3) | 1;
      goto locret_F0015B54;
    }
    if (uVar5 == 0x20006602) {
      *(byte *)(*(int *)(_active_u + 0x150) + uVar3) =
           *(byte *)(*(int *)(_active_u + 0x150) + uVar3) & 0xfe;
      goto locret_F0015B54;
    }
    uVar3 = (uVar5 & 0x1fffffff) >> 0x10;
    if (0x80 < uVar3) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
      goto locret_F0015B54;
    }
    if ((int)uVar5 < 0) {
      if (uVar3 == 0) {
loc_F0015A30:
        *(uint *)((int)register0x00000038 + -0x88) = puVar8[2];
      }
      else {
        uVar1 = puVar8[2];
        _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x88),uVar3);
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0015B54;
      }
    }
    else if (((uVar5 & 0x40000000) == 0) || (uVar3 == 0)) {
      if ((uVar5 & 0x20000000) != 0) goto loc_F0015A30;
    }
    else {
      _bzero((undefined *)((int)register0x00000038 + -0x88),uVar3);
    }
    if (uVar5 == 0x8004667d) {
      _fset(iVar6,0x40,*(undefined4 *)((int)register0x00000038 + -0x88));
      uVar2 = (undefined)iVar6;
    }
    else if ((int)uVar5 < -0x7ffb9982) {
      if (uVar5 == 0x8004667c) {
        _fsetown(iVar6,*(undefined4 *)((int)register0x00000038 + -0x88));
        uVar2 = (undefined)iVar6;
      }
      else {
        iVar4 = *(int *)(iVar6 + 0x14);
loc_F0015AF8:
        puVar7 = (undefined *)((int)register0x00000038 + -0x88);
        (**(code **)(iVar4 + 4))(iVar6,uVar5,puVar7);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar6;
        if (((*(char *)(dword_F0133DDC + 0x38) != '\0') || ((uVar5 & 0x40000000) == 0)) ||
           (uVar3 == 0)) goto locret_F0015B54;
        _copyout(puVar7,puVar8[2],uVar3);
        uVar2 = SUB41(puVar7,0);
      }
    }
    else if (uVar5 == 0x8004667e) {
      _fset(iVar6,4,*(undefined4 *)((int)register0x00000038 + -0x88));
      uVar2 = (undefined)iVar6;
    }
    else {
      if (uVar5 != 0x4004667b) {
        iVar4 = *(int *)(iVar6 + 0x14);
        goto loc_F0015AF8;
      }
      _fgetown(iVar6,(undefined *)((int)register0x00000038 + -0x88));
      uVar2 = (undefined)iVar6;
    }
  }
  else {
    uVar2 = 9;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F0015B54:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=306 start=0xf0015b5c */

/* WARNING: Removing unreachable block (ram,0xf0015c90) */
/* WARNING: Removing unreachable block (ram,0xf0015c3c) */
/* WARNING: Removing unreachable block (ram,0xf0015c00) */
/* WARNING: Removing unreachable block (ram,0xf0015bb8) */
/* WARNING: Removing unreachable block (ram,0xf0015bdc) */
/* WARNING: Removing unreachable block (ram,0xf0015c28) */
/* WARNING: Removing unreachable block (ram,0xf0015c84) */
/* WARNING: Removing unreachable block (ram,0xf0015c98) */
/* WARNING: Removing unreachable block (ram,0xf0015b7c) */

undefined8 _select(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  
  iVar1 = dword_F0133DDC;
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
  iVar5 = dword_F0133DDC + 0x58;
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  _memcpy(iVar5,unk_F00F4B98,0xd0);
  if (0x100 < *piVar3) {
    *piVar3 = 0x100;
  }
  iVar2 = piVar3[1];
  uVar4 = *piVar3 + 0x1fU >> 5;
  if (iVar2 != 0) {
    _copyin(iVar2,iVar5,uVar4 << 2);
    *(int *)(iVar1 + 0x124) = iVar2;
    if (iVar2 != 0) goto loc_F0015C98;
  }
  iVar5 = piVar3[2];
  if (iVar5 != 0) {
    _copyin(iVar5,iVar1 + 0x78,uVar4 << 2);
    *(int *)(iVar1 + 0x124) = iVar5;
    if (iVar5 != 0) goto loc_F0015C98;
  }
  iVar5 = piVar3[3];
  if (iVar5 != 0) {
    _copyin(iVar5,iVar1 + 0x98,uVar4 << 2);
    *(int *)(iVar1 + 0x124) = iVar5;
    if (iVar5 != 0) goto loc_F0015C98;
  }
  iVar5 = piVar3[4];
  iVar2 = iVar1 + 0x118;
  if (iVar5 != 0) {
    _copyin(iVar5,iVar2,8);
    *(int *)(iVar1 + 0x124) = iVar5;
    if (iVar5 == 0) {
      _itimerfix();
      if (iVar2 == 0) {
        if ((*(int *)(iVar1 + 0x118) == 0) && (*(int *)(iVar1 + 0x11c) == 0)) {
          *(undefined4 *)(iVar1 + 0x120) = 1;
        }
        else {
          _getthetime((undefined *)((int)register0x00000038 + -0x10));
          _timevaladd(iVar1 + 0x118,(undefined *)((int)register0x00000038 + -0x10));
        }
      }
      else {
        *(undefined4 *)(iVar1 + 0x124) = 0x16;
      }
    }
  }
loc_F0015C98:
  _selcont();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=307 start=0xf0015ca8 */

/* WARNING: Removing unreachable block (ram,0xf0015ec8) */
/* WARNING: Removing unreachable block (ram,0xf0015e90) */
/* WARNING: Removing unreachable block (ram,0xf0015e44) */
/* WARNING: Removing unreachable block (ram,0xf0015dc4) */
/* WARNING: Removing unreachable block (ram,0xf0015d74) */
/* WARNING: Removing unreachable block (ram,0xf0015d2c) */
/* WARNING: Removing unreachable block (ram,0xf0015d8c) */
/* WARNING: Removing unreachable block (ram,0xf0015e60) */
/* WARNING: Removing unreachable block (ram,0xf0015e04) */
/* WARNING: Removing unreachable block (ram,0xf0015eac) */
/* WARNING: Removing unreachable block (ram,0xf0015eec) */
/* WARNING: Removing unreachable block (ram,0xf0015cc8) */

undefined8 _selcont(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  int iVar8;
  int iVar9;
  undefined4 unaff_l3;
  int *piVar10;
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
  
  iVar2 = dword_F0133DDC;
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
  iVar3 = *(int *)(dword_F0133DDC + 0x124);
  iVar8 = dword_F0133DDC + 0x58;
  piVar10 = *(int **)(dword_F0133DDC + 0x24);
  if (iVar3 < 0) {
    _thread_wait_result();
    if (iVar3 - 2U < 2) {
      *(undefined4 *)(iVar2 + 0x124) = 4;
    }
    else {
      *(undefined4 *)(iVar2 + 0x124) = 0;
    }
  }
  if (*(int *)(iVar2 + 0x124) < 1) {
    while( true ) {
      iVar9 = *_active_u;
      *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) | 0x400000;
      iVar3 = _nselcoll;
      iVar4 = iVar8;
      _selscan(iVar8,iVar2 + 0xb8,*piVar10);
      *(int *)(dword_F0133DDC + 0x30) = iVar4;
      cVar1 = *(char *)(dword_F0133DDC + 0x38);
      *(int *)(iVar2 + 0x124) = (int)cVar1;
      if (cVar1 != 0) break;
      if (*(int *)(dword_F0133DDC + 0x30) != 0) {
        iVar3 = *(int *)(iVar2 + 0x124);
        goto loc_F0015E6C;
      }
      iVar4 = *(int *)(iVar2 + 0x120);
      if (iVar4 != 0) {
        iVar3 = *(int *)(iVar2 + 0x124);
        goto loc_F0015E6C;
      }
      _splusclock();
      if (piVar10[4] == 0) {
        uVar7 = *(uint *)(iVar9 + 0x28);
      }
      else {
        _getthetime((undefined *)((int)register0x00000038 + -0x10));
        iVar6 = *(int *)((int)register0x00000038 + -0x10);
        iVar5 = *(int *)(iVar2 + 0x118);
        if (iVar6 != iVar5 && iVar5 <= iVar6) {
loc_F0015DC4:
          _splx(iVar4);
          iVar3 = *(int *)(iVar2 + 0x124);
          goto loc_F0015E6C;
        }
        if (iVar6 == iVar5) {
          if (*(int *)(iVar2 + 0x11c) <= *(int *)((int)register0x00000038 + -0xc))
          goto loc_F0015DC4;
          uVar7 = *(uint *)(iVar9 + 0x28);
        }
        else {
          uVar7 = *(uint *)(iVar9 + 0x28);
        }
      }
      if (((uVar7 & 0x400000) != 0) && (_nselcoll == iVar3)) {
        *(uint *)(iVar9 + 0x28) = uVar7 & 0xffbfffff;
        *(undefined4 *)(iVar2 + 0x124) = 0xffffffff;
        if (piVar10[4] != 0) {
          _sleep_with_continuation_and_deadline(&_selwait,0x1a,_selcont,iVar2 + 0x118);
          iVar3 = *(int *)(iVar2 + 0x124);
          goto loc_F0015E6C;
        }
        _sleep_with_continuation(&_selwait,0x1a,_selcont);
        break;
      }
      *(uint *)(iVar9 + 0x28) = uVar7 & 0xffbfffff;
      _splx(iVar4);
    }
    iVar3 = *(int *)(iVar2 + 0x124);
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x124);
  }
loc_F0015E6C:
  uVar7 = *piVar10 + 0x1fU >> 5;
  if (iVar3 == 0) {
    iVar3 = iVar2 + 0xb8;
    if (piVar10[1] != 0) {
      _copyout(iVar3,piVar10[1],uVar7 << 2);
      *(int *)(iVar2 + 0x124) = iVar3;
    }
    iVar3 = iVar2 + 0xd8;
    if (piVar10[2] != 0) {
      _copyout(iVar3,piVar10[2],uVar7 << 2);
      *(int *)(iVar2 + 0x124) = iVar3;
    }
    iVar3 = iVar2 + 0xf8;
    if (piVar10[3] != 0) {
      _copyout(iVar3,piVar10[3],uVar7 << 2);
      *(int *)(iVar2 + 0x124) = iVar3;
    }
  }
  if (*(int *)(iVar2 + 0x124) != 0) {
    *(char *)(dword_F0133DDC + 0x38) = (char)*(int *)(iVar2 + 0x124);
  }
  _unix_syscall_return(*(undefined4 *)(iVar2 + 0x124));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=308 start=0xf0015efc */

undefined8 _selscan(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  undefined4 uVar11;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar12;
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
  iVar9 = 0;
  iVar12 = 0;
  uVar5 = 0x9f0133dd8;
  iVar10 = 0;
  do {
    uVar8 = 0;
    uVar11 = *(undefined4 *)(unk_F010B558 + iVar10);
    if (0 < param_3) {
      uVar2 = 0;
      do {
        uVar2 = *(uint *)(param_1 + uVar2 * 4);
        if (uVar2 != 0) {
          uVar7 = 0;
          do {
            uVar1 = uVar2 & 1;
            uVar6 = uVar8 + uVar7;
            uVar2 = (int)uVar2 >> 1;
            if (uVar1 != 0) {
              if ((param_3 <= (int)uVar6) || (*(int *)(_active_u + 0x158) <= (int)uVar6)) break;
              iVar3 = *(int *)(*(int *)(_active_u + 0x14c) + uVar6 * 4);
              if (iVar3 == 0) {
                *(char *)(*(int *)((int)uVar5 + 4) + 0x38) = (char)((qword)uVar5 >> 0x20);
                break;
              }
              pcVar4 = *(code **)(*(int *)(iVar3 + 0x14) + 8);
              *(undefined8 *)((int)register0x00000038 + -0x10) = uVar5;
              (*pcVar4)(iVar3,uVar11);
              uVar5 = *(undefined8 *)((int)register0x00000038 + -0x10);
              if (iVar3 != 0) {
                iVar9 = iVar9 + 1;
                iVar3 = (uVar6 >> 5) * 4;
                *(uint *)(param_2 + iVar3) = *(uint *)(param_2 + iVar3) | 1 << ((byte)uVar6 & 0x1f);
              }
              if (uVar2 == 0) break;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x20);
        }
        uVar8 = uVar8 + 0x20;
        uVar2 = uVar8 >> 5;
      } while ((int)uVar8 < param_3);
    }
    param_2 = param_2 + 0x20;
    param_1 = param_1 + 0x20;
    iVar12 = iVar12 + 1;
    iVar10 = iVar10 + 4;
    if (2 < iVar12) {
      return CONCAT44(param_2,iVar9);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=309 start=0xf0016034 */

undefined8 _seltrue(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=310 start=0xf0016040 */

/* WARNING: Removing unreachable block (ram,0xf001609c) */
/* WARNING: Removing unreachable block (ram,0xf0016084) */
/* WARNING: Removing unreachable block (ram,0xf00160ac) */
/* WARNING: Removing unreachable block (ram,0xf0016094) */
/* WARNING: Removing unreachable block (ram,0xf00160bc) */
/* WARNING: Removing unreachable block (ram,0xf0016044) */

undefined8 _selthreadcache(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  piVar1 = param_1;
  _splusclock();
  iVar2 = *param_1;
  if (iVar2 == 0) {
    _splx(piVar1);
  }
  else {
    if (*(int *)(iVar2 + 0x188) == 0) {
      *param_1 = 0;
    }
    else {
      if (*(undefined8 **)(iVar2 + 0x3c) == &_selwait) {
        _splx(piVar1);
        uVar3 = 1;
        goto locret_F00160CC;
      }
      *param_1 = 0;
    }
    _splx(piVar1);
    _thread_deallocate(iVar2);
  }
  iVar2 = _active_threads;
  _thread_reference(_active_threads);
  *param_1 = iVar2;
  uVar3 = 0;
locret_F00160CC:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=311 start=0xf00160d4 */

/* WARNING: Removing unreachable block (ram,0xf0016100) */
/* WARNING: Removing unreachable block (ram,0xf00160e8) */

undefined8 _selthreadclear(int *param_1,undefined4 param_2)

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
  if (param_1 == (int *)0x0) {
    _panic(aSelthreadclear);
    iVar1 = iRam00000000;
  }
  else {
    iVar1 = *param_1;
  }
  if (iVar1 == 0) {
    *param_1 = 0;
  }
  else {
    _thread_deallocate_interrupt();
    *param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=312 start=0xf0016114 */

/* WARNING: Removing unreachable block (ram,0xf0016180) */
/* WARNING: Removing unreachable block (ram,0xf0016158) */
/* WARNING: Removing unreachable block (ram,0xf00161a8) */
/* WARNING: Removing unreachable block (ram,0xf0016134) */

undefined8 _selwakeup(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if (param_2 != 0) {
    _nselcoll = _nselcoll + 1;
    _wakeup(&_selwait);
  }
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x188), iVar1 != 0)) {
    _splusclock();
    if (*(undefined8 **)(param_1 + 0x3c) == &_selwait) {
      _clear_wait(param_1,0,1);
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    if (iVar2 != 0) {
      *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & 0xffbfffff;
    }
    _splx(iVar1);
    param_2 = iVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=313 start=0xf00161b8 */

undefined8 _soo_rw(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  code *pcVar2;
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
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) && ((*(uint *)(param_1 + 8) & 0x2000) != 0)) {
    *(sword *)(param_3 + 0x10) = (sword)*(uint *)(param_1 + 8);
  }
  if (param_2 == 0) {
    pcVar2 = _soreceive;
  }
  else {
    pcVar2 = _sosend;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  (*pcVar2)(uVar1,0,param_3,0,0);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=314 start=0xf0016228 */

/* WARNING: Removing unreachable block (ram,0xf0016388) */
/* WARNING: Removing unreachable block (ram,0xf00163c0) */

undefined8 _soo_ioctl(int param_1,int param_2,uint *param_3)

{
  word wVar2;
  uint uVar1;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x18);
  if (param_2 == 0x200073ff) {
    iVar4 = 0;
    *(word *)(iVar3 + 6) = *(word *)(iVar3 + 6) | 0x80;
    goto locret_F00163CC;
  }
  if (param_2 < 0x20007400) {
    if (param_2 == -0x7ffb9982) {
      if (*param_3 == 0) {
        wVar2 = *(word *)(iVar3 + 6) & 0xfeff;
      }
      else {
        wVar2 = *(word *)(iVar3 + 6) | 0x100;
      }
loc_F0016338:
      *(word *)(iVar3 + 6) = wVar2;
      iVar4 = 0;
      goto locret_F00163CC;
    }
    if (param_2 < -0x7ffb9981) {
      if (param_2 == -0x7ffb9983) {
        if (*param_3 == 0) {
          wVar2 = *(word *)(iVar3 + 6) & 0xfdff;
        }
        else {
          wVar2 = *(word *)(iVar3 + 6) | 0x200;
        }
        goto loc_F0016338;
      }
    }
    else if (param_2 == -0x7ffb8cf8) {
      iVar4 = 0;
      *(sword *)(iVar3 + 0x5a) = (sword)*param_3;
      goto locret_F00163CC;
    }
  }
  else {
    if (param_2 == 0x40047307) {
      iVar4 = 0;
      *param_3 = *(word *)(iVar3 + 6) >> 6 & 1;
      goto locret_F00163CC;
    }
    if (param_2 < 0x40047308) {
      if (param_2 == 0x4004667f) {
        uVar1 = (uint)*(word *)(iVar3 + 0x24);
loc_F0016350:
        iVar4 = 0;
        *param_3 = uVar1;
        goto locret_F00163CC;
      }
    }
    else if (param_2 == 0x40047309) {
      uVar1 = (uint)*(sword *)(iVar3 + 0x5a);
      goto loc_F0016350;
    }
  }
  uVar1 = param_2 >> 8 & 0xff;
  if (uVar1 == 0x69) {
    _ifioctl(iVar3,param_2,param_3);
    iVar4 = iVar3;
  }
  else if (uVar1 == 0x72) {
    iVar4 = param_2;
    _rtioctl(param_2,param_3);
  }
  else {
    (**(code **)(*(int *)(iVar3 + 0xc) + 0x1c))(iVar3,0xb,param_2,param_3,0);
    iVar4 = iVar3;
  }
locret_F00163CC:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=315 start=0xf00163d4 */

/* WARNING: Removing unreachable block (ram,0xf00164fc) */
/* WARNING: Removing unreachable block (ram,0xf00164f4) */
/* WARNING: Removing unreachable block (ram,0xf00164e4) */
/* WARNING: Removing unreachable block (ram,0xf00163d8) */

undefined8 _soo_select(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 uVar5;
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
  iVar4 = *(int *)(param_1 + 0x18);
  _splnet();
  if (param_2 == 1) {
    if (((*(sword *)(iVar4 + 0x24) == 0) && ((*(word *)(iVar4 + 6) & 0x20) == 0)) &&
       (*(sword *)(iVar4 + 0x20) == 0)) {
      wVar1 = *(word *)(iVar4 + 0x56);
joined_r0xf001644c:
      iVar4 = iVar4 + 0x24;
joined_r0xf00164bc:
      if (wVar1 == 0) {
        _sbselqueue(iVar4);
        goto loc_F00164FC;
      }
    }
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
loc_F00164FC:
      _splx(param_1);
      uVar5 = 0;
      goto locret_F0016508;
    }
    if (*(sword *)(iVar4 + 0x58) == 0) {
      wVar1 = *(word *)(iVar4 + 6) & 0x40;
      goto joined_r0xf001644c;
    }
  }
  else {
    if (param_2 != 2) goto loc_F00164FC;
    iVar2 = (uint)*(word *)(iVar4 + 0x3e) - (uint)*(word *)(iVar4 + 0x3c);
    iVar3 = (uint)*(word *)(iVar4 + 0x42) - (uint)*(word *)(iVar4 + 0x40);
    if (iVar3 < iVar2) {
      iVar2 = iVar3;
    }
    wVar1 = *(word *)(iVar4 + 6);
    if (0 < iVar2) {
      if (((wVar1 & 2) != 0) || ((*(word *)(*(int *)(iVar4 + 0xc) + 10) & 4) == 0))
      goto loc_F00164E4;
      wVar1 = *(word *)(iVar4 + 6);
    }
    if ((wVar1 & 0x10) == 0) {
      wVar1 = *(word *)(iVar4 + 0x56);
      iVar4 = iVar4 + 0x3c;
      goto joined_r0xf00164bc;
    }
  }
loc_F00164E4:
  _splx(param_1);
  uVar5 = 1;
locret_F0016508:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=316 start=0xf0016510 */

/* WARNING: Removing unreachable block (ram,0xf0016518) */

undefined8 _soo_stat(int param_1,undefined4 param_2)

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
  _bzero(param_2,0x40);
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,0xc,param_2,0,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=317 start=0xf0016548 */

/* WARNING: Removing unreachable block (ram,0xf0016560) */

undefined8 _soo_close(int param_1,undefined4 param_2)

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
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = 0;
  if (iVar1 != 0) {
    _soclose();
    iVar2 = iVar1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=318 start=0xf0016578 */

undefined8 _ttysetspec(int *param_1)

{
  byte bVar1;
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
  uint uVar4;
  undefined4 unaff_i2;
  int iVar5;
  undefined4 unaff_i3;
  uint uVar6;
  undefined4 unaff_i4;
  uint uVar7;
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
  iVar5 = *param_1;
  uVar4 = 0;
  uVar7 = param_1[4];
  uVar6 = *(uint *)(iVar5 + 0x3c);
  iVar2 = iVar5;
  do {
    *(undefined4 *)(iVar2 + 100) = 0;
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar4 < 8);
  if ((uVar6 & 0x20) != 0) goto locret_F00168C4;
  if ((uVar7 & 0x10) != 0) {
    bVar1 = *(byte *)(iVar5 + 0x5a);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x58);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x58) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar7 & 8) != 0) {
    bVar1 = *(byte *)(iVar5 + 0x4f);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    bVar1 = *(byte *)(iVar5 + 0x50);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x55);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x55) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar7 & 0x4000000) != 0) {
    bVar1 = *(byte *)(iVar5 + 0x52);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x51);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x51) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar6 & 0x10) == 0) {
    if ((uVar7 & 0x3000000) != 0) {
      uVar3 = *(uint *)(iVar5 + 100);
      goto loc_F0016760;
    }
  }
  else {
    uVar3 = *(uint *)(iVar5 + 100);
loc_F0016760:
    *(uint *)(iVar5 + 100) = uVar3 | 0x2000;
  }
  if ((uVar7 & 0x800000) != 0) {
    *(uint *)(iVar5 + 100) = *(uint *)(iVar5 + 100) | 0x400;
  }
  if ((uVar6 & 2) == 0) {
    bVar1 = *(byte *)(iVar5 + 0x4d);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    bVar1 = *(byte *)(iVar5 + 0x4e);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    bVar1 = *(byte *)(iVar5 + 0x59);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x57);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x57) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar6 & 4) != 0) {
    uVar4 = 0;
    do {
      uVar6 = uVar4 >> 3;
      bVar1 = (byte)uVar4;
      uVar4 = uVar4 + 1;
      iVar2 = (uVar6 & 0x1c) + iVar5;
      param_1 = (int *)(1 << (bVar1 & 0x1f));
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | (uint)param_1;
    } while ((int)uVar4 < 0x80);
  }
  if ((uVar7 & 0x181000) == 0x101000) {
    *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) | 0x80000000;
  }
locret_F00168C4:
  return CONCAT44(uVar4,param_1);
}
/* GHIDRADEC_FUNCTION index=319 start=0xf00168cc */

/* WARNING: Removing unreachable block (ram,0xf0016960) */
/* WARNING: Removing unreachable block (ram,0xf00168d0) */

undefined8 _ttychars(int param_1,undefined4 param_2)

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
  _ttynty();
  *(undefined *)(param_1 + 0x4d) = _ttydefaults[0];
  *(undefined *)(param_1 + 0x4e) = _ttydefaults[1];
  *(undefined *)(param_1 + 0x4f) = _ttydefaults[2];
  *(undefined *)(param_1 + 0x50) = _ttydefaults[3];
  *(undefined *)(param_1 + 0x51) = _ttydefaults[4];
  *(undefined *)(param_1 + 0x52) = _ttydefaults[5];
  *(undefined *)(param_1 + 0x53) = _ttydefaults[6];
  *(undefined *)(param_1 + 0x54) = _ttydefaults[7];
  *(undefined *)(param_1 + 0x55) = _ttydefaults[8];
  *(undefined *)(param_1 + 0x56) = _ttydefaults[9];
  *(undefined *)(param_1 + 0x57) = _ttydefaults[10];
  *(undefined *)(param_1 + 0x58) = _ttydefaults[0xb];
  *(undefined *)(param_1 + 0x59) = _ttydefaults[0xc];
  *(undefined *)(param_1 + 0x5a) = _ttydefaults[0xd];
  *(undefined *)(iVar1 + 0x14) = 0x5c;
  *(undefined *)(iVar1 + 0x15) = 1;
  *(undefined *)(iVar1 + 0x16) = 0;
  _ttysetspec();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=320 start=0xf0016970 */

/* WARNING: Removing unreachable block (ram,0xf0016980) */
/* WARNING: Removing unreachable block (ram,0xf0016974) */

undefined8 _ttywflush(undefined4 param_1,undefined4 param_2)

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
  _ttywait(param_1);
  _ttyflush(param_1,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=321 start=0xf0016990 */

/* WARNING: Removing unreachable block (ram,0xf0016a20) */
/* WARNING: Removing unreachable block (ram,0xf00169b8) */
/* WARNING: Removing unreachable block (ram,0xf00169f0) */
/* WARNING: Removing unreachable block (ram,0xf0016994) */

undefined8 _ttywait(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
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
  iVar3 = *(int *)(param_1 + 0x18);
  do {
    if (iVar3 == 0) {
      if ((*(uint *)(param_1 + 0x40) & 0x2000020) == 0) {
loc_F0016A20:
        _splx(iVar1);
        return CONCAT44(param_2,param_1);
      }
      uVar2 = *(uint *)(param_1 + 0x40);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x40);
    }
    if ((uVar2 & 0x10) == 0) {
      iVar3 = param_1;
      _ttynty();
      if ((*(uint *)(iVar3 + 0x10) & 0x8000) == 0) goto loc_F0016A20;
      pcVar4 = *(code **)(param_1 + 0x24);
    }
    else {
      pcVar4 = *(code **)(param_1 + 0x24);
    }
    (*pcVar4)(param_1);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
    _sleep(param_1 + 0x18,0x1d);
    iVar3 = *(int *)(param_1 + 0x18);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=322 start=0xf0016a30 */

/* WARNING: Removing unreachable block (ram,0xf0016ad8) */
/* WARNING: Removing unreachable block (ram,0xf0016a70) */
/* WARNING: Removing unreachable block (ram,0xf0016a48) */
/* WARNING: Removing unreachable block (ram,0xf0016a5c) */
/* WARNING: Removing unreachable block (ram,0xf0016abc) */
/* WARNING: Removing unreachable block (ram,0xf0016b00) */
/* WARNING: Removing unreachable block (ram,0xf0016a34) */

undefined8 _ttyflush(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
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
  if ((param_2 & 1) != 0) {
    do {
      iVar2 = param_1 + 0xc;
      _getc();
    } while (-1 < iVar2);
    _wakeup(param_1);
  }
  if ((param_2 & 2) != 0) {
    _wakeup(param_1 + 0x18);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffeff;
    (**(code **)(DAT_f011ca04 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))(param_1,param_2);
    do {
      iVar2 = param_1 + 0x18;
      _getc();
    } while (-1 < iVar2);
  }
  if ((param_2 & 1) != 0) {
    do {
      iVar2 = param_1;
      _getc();
    } while (-1 < iVar2);
    *(undefined *)(param_1 + 0x4b) = 0;
    *(undefined *)(param_1 + 0x4c) = 0;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xff40ffff;
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=323 start=0xf0016b10 */

/* WARNING: Removing unreachable block (ram,0xf0016b2c) */
/* WARNING: Removing unreachable block (ram,0xf0016b68) */
/* WARNING: Removing unreachable block (ram,0xf0016b14) */

undefined8 _ttrstrt(int param_1,undefined4 param_2)

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
  if (param_1 == 0) {
    _panic(&aTtrstrt);
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  (**(code **)(DAT_f010b8ec + *(char *)(param_1 + 0x47) * 0x30))(param_1);
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=324 start=0xf0016b78 */

/* WARNING: Removing unreachable block (ram,0xf0016bb4) */
/* WARNING: Removing unreachable block (ram,0xf0016b7c) */

undefined8 _ttstart(int param_1,undefined4 param_2)

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
  if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) && (*(code **)(param_1 + 0x24) != (code *)0x0))
  {
    (**(code **)(param_1 + 0x24))(param_1);
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=325 start=0xf0016bc4 */

/* WARNING: Removing unreachable block (ram,0xf0017370) */
/* WARNING: Removing unreachable block (ram,0xf0017570) */
/* WARNING: Removing unreachable block (ram,0xf001723c) */
/* WARNING: Removing unreachable block (ram,0xf001768c) */
/* WARNING: Removing unreachable block (ram,0xf0017160) */
/* WARNING: Removing unreachable block (ram,0xf0017a1c) */
/* WARNING: Removing unreachable block (ram,0xf001797c) */
/* WARNING: Removing unreachable block (ram,0xf001792c) */
/* WARNING: Removing unreachable block (ram,0xf00178bc) */
/* WARNING: Removing unreachable block (ram,0xf00175c0) */
/* WARNING: Removing unreachable block (ram,0xf00177d8) */
/* WARNING: Removing unreachable block (ram,0xf0017500) */
/* WARNING: Removing unreachable block (ram,0xf0017454) */
/* WARNING: Removing unreachable block (ram,0xf0017428) */
/* WARNING: Removing unreachable block (ram,0xf00173e4) */
/* WARNING: Removing unreachable block (ram,0xf00172cc) */
/* WARNING: Removing unreachable block (ram,0xf001724c) */
/* WARNING: Removing unreachable block (ram,0xf001721c) */
/* WARNING: Removing unreachable block (ram,0xf0017a3c) */
/* WARNING: Removing unreachable block (ram,0xf001774c) */
/* WARNING: Removing unreachable block (ram,0xf0017874) */
/* WARNING: Removing unreachable block (ram,0xf0016d78) */
/* WARNING: Removing unreachable block (ram,0xf0016d6c) */
/* WARNING: Removing unreachable block (ram,0xf001720c) */
/* WARNING: Removing unreachable block (ram,0xf00175d4) */
/* WARNING: Removing unreachable block (ram,0xf00171f8) */
/* WARNING: Removing unreachable block (ram,0xf00171e4) */
/* WARNING: Removing unreachable block (ram,0xf0017270) */
/* WARNING: Removing unreachable block (ram,0xf0017258) */
/* WARNING: Removing unreachable block (ram,0xf0017310) */
/* WARNING: Removing unreachable block (ram,0xf001741c) */
/* WARNING: Removing unreachable block (ram,0xf00174b4) */
/* WARNING: Removing unreachable block (ram,0xf00174e0) */
/* WARNING: Removing unreachable block (ram,0xf00177a4) */
/* WARNING: Removing unreachable block (ram,0xf00175b8) */
/* WARNING: Removing unreachable block (ram,0xf0017884) */
/* WARNING: Removing unreachable block (ram,0xf00178dc) */
/* WARNING: Removing unreachable block (ram,0xf0017990) */
/* WARNING: Removing unreachable block (ram,0xf0017a10) */
/* WARNING: Removing unreachable block (ram,0xf0017a24) */
/* WARNING: Removing unreachable block (ram,0xf00171cc) */
/* WARNING: Removing unreachable block (ram,0xf0017698) */
/* WARNING: Removing unreachable block (ram,0xf0017658) */
/* WARNING: Removing unreachable block (ram,0xf0017534) */
/* WARNING: Removing unreachable block (ram,0xf0017a2c) */
/* WARNING: Removing unreachable block (ram,0xf0016bc8) */

undefined8 _ttioctl(undefined4 *param_1,uint param_2,uint *param_3,uint param_4)

{
  sword sVar1;
  sword sVar2;
  word wVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 *puVar10;
  uint uVar11;
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
  puVar10 = param_1;
  _ttynty();
  iVar8 = (int)*(sword *)(param_1 + 0xe);
  if (param_2 == 0x80067411) {
loc_F0016D34:
    sVar1 = *(sword *)(param_1 + 0x11);
    uVar7 = *_active_u;
    sVar2 = *(sword *)(uVar7 + 0x2e);
    while (((((int)sVar2 != (int)sVar1 && (param_1 == (undefined4 *)_active_u[0x59])) &&
            ((*(uint *)(uVar7 + 0x28) & 0x1000) == 0)) &&
           (((*(uint *)(uVar7 + 0x20) & 0x200000) == 0 &&
            ((*(uint *)(uVar7 + 0x1c) & 0x200000) == 0))))) {
      _gsignal((int)sVar2,0x16);
      _sleep(_lbolt,0x1d);
      sVar1 = *(sword *)(param_1 + 0x11);
      uVar7 = *_active_u;
      sVar2 = *(sword *)(uVar7 + 0x2e);
    }
  }
  else {
    if ((int)param_2 < -0x7ff98bee) {
      if (param_2 != 0x80047476) {
        if (-0x7ffb8b8a < (int)param_2) {
          if (-0x7ffb8b84 < (int)param_2) {
            if ((int)param_2 < -0x7ffb8b80) goto loc_F0016D34;
            if ((int)param_2 < -0x7ff98bf5) {
              iVar9 = -0x7ff98bf7;
              goto loc_F0016D20;
            }
          }
          goto loc_F0016DC0;
        }
        if (param_2 != 0x80047401) {
          if ((int)param_2 < -0x7ffb8bfe) {
            uVar7 = 0x80017472;
          }
          else {
            uVar7 = 0x80047410;
          }
loc_F0016CB8:
          if (param_2 != uVar7) goto loc_F0016DC0;
        }
      }
      goto loc_F0016D34;
    }
    if (param_2 == 0x2000745e) goto loc_F0016D34;
    if ((int)param_2 < 0x2000745f) {
      if (param_2 == 0x80087467) goto loc_F0016D34;
      if ((int)param_2 < -0x7ff78b98) {
        uVar7 = 0x80067475;
        goto loc_F0016CB8;
      }
      if ((int)param_2 < -0x7fdb8be9) {
        iVar9 = -0x7fdb8bec;
        goto loc_F0016D20;
      }
    }
    else if (0x2000746d < (int)param_2) {
      if ((int)param_2 < 0x20007470) goto loc_F0016D34;
      if ((int)param_2 < 0x2000747c) {
        iVar9 = 0x2000747a;
loc_F0016D20:
        if (iVar9 <= (int)param_2) goto loc_F0016D34;
      }
    }
  }
loc_F0016DC0:
  if (param_2 == 0x20007402) {
    _spltty();
    uVar7 = param_1[0x10] | 0x200;
loc_F001721C:
    param_1[0x10] = uVar7;
    _splx();
    iVar9 = 0;
    goto locret_F0017A50;
  }
  if ((int)param_2 < 0x20007403) {
    if (param_2 == 0x8004747e) {
      param_1[0xf] = param_1[0xf] & ~(*param_3 << 0x10);
loc_F001763C:
      puVar10[4] = 0x1c251a1c;
      *(undefined *)(puVar10 + 5) = 0x5c;
      *(undefined *)((int)puVar10 + 0x15) = 1;
      *(undefined *)((int)puVar10 + 0x16) = 0;
      _ttysetspec();
      iVar9 = 0;
      goto locret_F0017A50;
    }
    if ((int)param_2 < -0x7ffb8b81) {
      if (param_2 == 0x80047401) {
        puVar10 = (undefined4 *)*param_3;
        if ((_nldisp <= puVar10) || (*(code **)(_linesw + (int)puVar10 * 0x30) == _nodev)) {
          iVar9 = 6;
          goto locret_F0017A50;
        }
        puVar5 = (undefined4 *)(int)*(char *)((int)param_1 + 0x47);
        if (puVar10 == puVar5) {
          iVar9 = 0;
          goto locret_F0017A50;
        }
        _spltty();
        (**(code **)(_linesw + *(char *)((int)param_1 + 0x47) * 0x30 + 4))(param_1);
        param_1[0x21] = 0;
        iVar9 = iVar8;
        (**(code **)(_linesw + (int)puVar10 * 0x30))(iVar8,param_1);
        if (iVar9 != 0) {
          param_1[0x21] = 0;
          (**(code **)(_linesw + *(char *)((int)param_1 + 0x47) * 0x30))(iVar8,param_1);
          _splx(puVar5);
          goto locret_F0017A50;
        }
        *(char *)((int)param_1 + 0x47) = (char)puVar10;
      }
      else {
        if (-0x7ffb8bff < (int)param_2) {
          if (param_2 == 0x80047476) {
            uVar7 = *_active_u;
            uVar11 = *param_3;
            if ((*(uint *)(uVar7 + 0x14) & 0x4000) == 0) {
              if (*(sword *)(_active_u[7] + 2) == 0) {
                *(sword *)(param_1 + 0x11) = (sword)uVar11;
                puVar10 = _cons_tp;
              }
              else {
                if ((param_4 & 1) == 0) {
                  iVar9 = 1;
                  goto locret_F0017A50;
                }
                *(sword *)(param_1 + 0x11) = (sword)uVar11;
                puVar10 = _cons_tp;
              }
            }
            else {
              param_2 = uVar11;
              _pgfind();
              iVar8 = (int)*(sword *)(uVar7 + 0x30);
              _get_posix_proc();
              if (((int)uVar11 < 1) || (param_2 == 0)) {
                iVar9 = 0x16;
                goto locret_F0017A50;
              }
              iVar8 = *(int *)(*(int *)(iVar8 + 0x10) + 8);
              if (iVar8 != puVar10[2]) {
                iVar9 = 0x19;
                goto locret_F0017A50;
              }
              if ((*(uint *)(uVar7 + 0x28) & 0x40000000) == 0) {
                iVar9 = 0x19;
                goto locret_F0017A50;
              }
              if (*(int *)(param_2 + 8) != iVar8) {
                iVar9 = 1;
                goto locret_F0017A50;
              }
              puVar10[3] = param_2;
              *(sword *)(param_1 + 0x11) = (sword)*(undefined4 *)(param_2 + 0xc);
              puVar10 = _cons_tp;
            }
            goto loc_F0017A4C;
          }
          if ((int)param_2 < -0x7ffb8b89) {
            if (param_2 == 0x80047410) {
              uVar7 = *param_3 & 3;
              if (*param_3 == 0) {
                uVar7 = 3;
              }
              _ttyflush(param_1,uVar7);
              iVar9 = 0;
            }
            else {
              iVar9 = -1;
            }
            goto locret_F0017A50;
          }
          if (param_2 != 0x8004747d) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          uVar7 = param_1[0xf];
          param_1[0xf] = uVar7 & 0xffff;
          param_1[0xf] = uVar7 & 0xffff | *param_3 << 0x10;
          goto loc_F001763C;
        }
        puVar5 = (undefined4 *)0x8004667d;
        if (param_2 == 0x8004667d) {
          _spltty();
          if (*param_3 == 0) {
            uVar7 = param_1[0x10] & 0xffffbfff;
          }
          else {
            uVar7 = param_1[0x10] | 0x4000;
          }
          param_1[0x10] = uVar7;
        }
        else if ((int)param_2 < -0x7ffb9982) {
          if (param_2 != 0x80017472) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          if ((*(sword *)(_active_u[7] + 2) != 0) && ((param_4 & 1) == 0)) {
            iVar9 = 1;
            goto locret_F0017A50;
          }
          puVar5 = (undefined4 *)0x0;
          if ((*(sword *)(_active_u[7] + 2) != 0) &&
             (puVar5 = (undefined4 *)_active_u[0x59], puVar5 != param_1)) {
            iVar9 = 0xd;
            goto locret_F0017A50;
          }
          _spltty();
          (**(code **)(_linesw + *(char *)((int)param_1 + 0x47) * 0x30 + 0x14))
                    (*(undefined *)param_3,param_1);
        }
        else {
          puVar5 = (undefined4 *)0x8004667e;
          if (param_2 != 0x8004667e) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          _spltty();
          if (*param_3 == 0) {
            uVar7 = param_1[0x10] & 0xffffdfff;
          }
          else {
            uVar7 = param_1[0x10] | 0x2000;
          }
          param_1[0x10] = uVar7;
        }
      }
    }
    else {
      if (param_2 == 0x80067411) {
        puVar6 = (undefined *)((int)param_1 + 0x4f);
loc_F00175B8:
        _bcopy(param_3,puVar6,6);
        _ttysetspec(puVar10);
        iVar9 = 0;
        goto locret_F0017A50;
      }
      if ((int)param_2 < -0x7ff98bee) {
        if (param_2 == 0x8004747f) {
          param_1[0xf] = param_1[0xf] | *param_3 << 0x10;
          goto loc_F001763C;
        }
        if (-0x7ff98bf6 < (int)param_2) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        if ((int)param_2 < -0x7ff98bf7) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        *(undefined *)((int)param_1 + 0x4d) = *(undefined *)((int)param_3 + 2);
        *(char *)((int)param_1 + 0x4e) = (char)*param_3;
        *(undefined *)((int)param_1 + 0x49) = *(undefined *)param_3;
        *(undefined *)((int)param_1 + 0x4a) = *(undefined *)((int)param_3 + 1);
        wVar3 = *(word *)(param_3 + 1);
        puVar5 = (undefined4 *)0xffff;
        uVar11 = param_1[0xf] & 0xffff0000 | (uint)wVar3;
        _spltty();
        uVar7 = param_1[0xf];
        if ((((uVar7 & 0x20) == 0) && (((int)(sword)wVar3 & 0x20U) == 0)) && (param_2 != 0x80067409)
           ) {
          uVar4 = (int)(sword)wVar3 & 2;
          if ((uVar7 & 2) != uVar4) {
            if (uVar4 == 0) {
              param_1[0xf] = uVar7 | 0x20000000;
              uVar11 = uVar11 | 0x20000000;
              _ttwakeup(param_1);
            }
            else {
              _catq(param_1,param_1 + 3);
              *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
              *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
              *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
              *param_1 = param_1[3];
              param_1[1] = param_1[4];
              param_1[2] = param_1[5];
              param_1[3] = *(undefined4 *)((int)register0x00000038 + -0x18);
              param_1[4] = *(undefined4 *)((int)register0x00000038 + -0x14);
              param_1[5] = *(undefined4 *)((int)register0x00000038 + -0x10);
            }
          }
          param_1[0xf] = uVar11;
        }
        else {
          _ttywait(param_1);
          _ttyflush(param_1,1);
          param_1[0xf] = uVar11;
        }
        puVar10[4] = 0x1c251a1c;
        *(undefined *)(puVar10 + 5) = 0x5c;
        *(undefined *)((int)puVar10 + 0x15) = 1;
        *(undefined *)((int)puVar10 + 0x16) = 0;
        _ttysetspec(puVar10);
        if ((param_1[0xf] & 0x20) != 0) {
          param_1[0x10] = param_1[0x10] & 0xfffffeff;
          _ttstart();
        }
      }
      else {
        if (param_2 == 0x80087467) {
          puVar5 = param_1 + 0x17;
          _bcmp(puVar5,param_3,8);
          puVar10 = _cons_tp;
          if (puVar5 != (undefined4 *)0x0) {
            *(undefined2 *)(param_1 + 0x17) = *(undefined2 *)param_3;
            *(sword *)((int)param_1 + 0x5e) = (sword)*param_3;
            *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_3 + 1);
            *(undefined2 *)((int)param_1 + 0x62) = *(undefined2 *)((int)param_3 + 6);
            _gsignal((int)*(sword *)(param_1 + 0x11),0x1c);
            iVar9 = 0;
            goto locret_F0017A50;
          }
          goto loc_F0017A4C;
        }
        if ((int)param_2 < -0x7ff78b98) {
          if (param_2 != 0x80067475) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          puVar6 = (undefined *)((int)param_1 + 0x55);
          goto loc_F00175B8;
        }
        if (-0x7fdb8bea < (int)param_2) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        puVar5 = (undefined4 *)0x80247414;
        if ((int)param_2 < -0x7fdb8bec) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        _spltty();
        if (*(char *)((int)param_3 + 0x21) == '\0') {
          *(undefined *)((int)param_3 + 0x21) = *(undefined *)((int)param_3 + 0x22);
        }
        if (param_2 == 0x80247415 || param_2 == 0x80247416) {
          _ttywait(param_1);
          if (param_2 == 0x80247416) {
            _ttyflush(param_1,1);
            uVar7 = param_3[2];
          }
          else {
            uVar7 = param_3[2];
          }
        }
        else {
          uVar7 = param_3[2];
        }
        if ((uVar7 & 1) == 0) {
          if ((param_1[0x10] & 0x10) == 0) {
            if ((puVar10[4] & 0x8000) != 0) {
              if ((uVar7 & 0x8000) != 0) {
                uVar7 = param_1[0xf];
                goto loc_F0017938;
              }
              param_1[0x10] = param_1[0x10] & 0xfffffffb | 2;
              _ttwakeup(param_1);
            }
            uVar7 = param_1[0xf];
          }
          else {
            uVar7 = param_1[0xf];
          }
        }
        else {
          uVar7 = param_1[0xf];
        }
loc_F0017938:
        uVar11 = param_3[3] >> 5 & 1;
        if ((param_2 != 0x80247416) && (uVar11 != ((uVar7 & 0x22) == 0))) {
          if (uVar11 == 0) {
            _catq(param_1,param_1 + 3);
            *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
            *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
            *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
            *param_1 = param_1[3];
            param_1[1] = param_1[4];
            param_1[2] = param_1[5];
            param_1[3] = *(undefined4 *)((int)register0x00000038 + -0x18);
            param_1[4] = *(undefined4 *)((int)register0x00000038 + -0x14);
            param_1[5] = *(undefined4 *)((int)register0x00000038 + -0x10);
          }
          else {
            param_1[0xf] = uVar7 | 0x20000000;
            _ttwakeup(param_1);
          }
        }
        if ((uVar11 == 0) && ((puVar10[5] & 0xffff00) != (param_3[6] & 0xffff00))) {
          _ttwakeup(param_1);
        }
        _ttsettermios(puVar10,param_3);
        _ttysetspec(puVar10);
      }
    }
loc_F0017A2C:
    _splx(puVar5);
    iVar9 = 0;
    goto locret_F0017A50;
  }
  if (param_2 == 0x40047460) {
    *param_3 = param_1[0x10];
    puVar10 = _cons_tp;
  }
  else if ((int)param_2 < 0x40047461) {
    if (param_2 != 0x20007468) {
      if ((int)param_2 < 0x20007469) {
        if (param_2 == 0x2000740e) {
          _spltty();
          uVar7 = param_1[0x10] & 0xffffff7f;
        }
        else {
          if (0x2000740e < (int)param_2) {
            if (param_2 == 0x2000745e) {
              _ttywait(param_1);
              iVar9 = 0;
            }
            else {
              iVar9 = -1;
            }
            goto locret_F0017A50;
          }
          if (param_2 != 0x2000740d) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          _spltty();
          uVar7 = param_1[0x10] | 0x80;
        }
        goto loc_F001721C;
      }
      puVar5 = (undefined4 *)0x2000746f;
      if (param_2 == 0x2000746f) {
        _spltty();
        if ((param_1[0x10] & 0x100) == 0) {
          param_1[0x10] = param_1[0x10] | 0x100;
          (**(code **)(DAT_f011ca00 + (uint)(*(word *)(param_1 + 0xe) >> 8) * 0x2c + 4))(param_1,0);
        }
      }
      else if ((int)param_2 < 0x20007470) {
        puVar5 = (undefined4 *)0x2000746e;
        if (param_2 != 0x2000746e) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
        _spltty();
        if (((param_1[0x10] & 0x100) != 0) || ((param_1[0xf] & 0x800000) != 0)) {
          param_1[0x10] = param_1[0x10] & 0xfffffeff;
          param_1[0xf] = param_1[0xf] & 0xff7fffff;
          _ttstart();
        }
      }
      else {
        puVar5 = (undefined4 *)0x40047400;
        if (param_2 != 0x4004667f) {
          if (param_2 != 0x40047400) {
            iVar9 = -1;
            goto locret_F0017A50;
          }
          *param_3 = (int)*(char *)((int)param_1 + 0x47);
          puVar10 = _cons_tp;
          goto loc_F0017A4C;
        }
        _spltty();
        _ttnread();
        *param_3 = (uint)puVar10;
      }
      goto loc_F0017A2C;
    }
    puVar10 = param_1;
    if (param_1 != (undefined4 *)_cons) {
      (**(code **)(DAT_f011ca00 + (uint)(*(word *)(_cons_tp + 0xe) >> 8) * 0x2c))
                ((int)(sword)*(word *)(_cons_tp + 0xe),0x20006b08,0,0);
      puVar10 = param_1;
    }
  }
  else if (param_2 == 0x40067408) {
    *(undefined *)param_3 = *(undefined *)((int)param_1 + 0x49);
    *(undefined *)((int)param_3 + 1) = *(undefined *)((int)param_1 + 0x4a);
    *(undefined *)((int)param_3 + 2) = *(undefined *)((int)param_1 + 0x4d);
    *(undefined *)((int)param_3 + 3) = *(undefined *)((int)param_1 + 0x4e);
    *(sword *)(param_3 + 1) = (sword)param_1[0xf];
    puVar10 = _cons_tp;
  }
  else {
    if (0x40067408 < (int)param_2) {
      if (param_2 == 0x40067474) {
        puVar6 = (undefined *)((int)param_1 + 0x55);
      }
      else {
        if (0x40067474 < (int)param_2) {
          if (param_2 != 0x40087468) {
            if (param_2 == 0x40247413) {
              _ttgettermios(puVar10,param_3);
              iVar9 = 0;
            }
            else {
              iVar9 = -1;
            }
            goto locret_F0017A50;
          }
          *(undefined2 *)param_3 = *(undefined2 *)(param_1 + 0x17);
          *(undefined2 *)((int)param_3 + 2) = *(undefined2 *)((int)param_1 + 0x5e);
          *(undefined2 *)(param_3 + 1) = *(undefined2 *)(param_1 + 0x18);
          *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)param_1 + 0x62);
          puVar10 = _cons_tp;
          goto loc_F0017A4C;
        }
        puVar6 = (undefined *)((int)param_1 + 0x4f);
        if (param_2 != 0x40067412) {
          iVar9 = -1;
          goto locret_F0017A50;
        }
      }
      _bcopy(puVar6,param_3,6);
      iVar9 = 0;
      goto locret_F0017A50;
    }
    if (param_2 == 0x40047477) {
      param_2 = *_active_u;
      if ((*(uint *)(param_2 + 0x14) & 0x4000) == 0) {
        sVar1 = *(sword *)(param_1 + 0x11);
      }
      else {
        iVar8 = (int)*(sword *)(param_2 + 0x30);
        _get_posix_proc();
        iVar8 = *(int *)(*(int *)(iVar8 + 0x10) + 8);
        if (iVar8 != puVar10[2]) {
          iVar9 = 0x19;
          goto locret_F0017A50;
        }
        if ((*(uint *)(param_2 + 0x28) & 0x40000000) == 0) {
          iVar9 = 0x19;
          goto locret_F0017A50;
        }
        if (*(int *)(iVar8 + 8) == 0) {
          iVar9 = 0x19;
          goto locret_F0017A50;
        }
        sVar1 = *(sword *)(param_1 + 0x11);
      }
      *param_3 = (int)sVar1;
      puVar10 = _cons_tp;
    }
    else if ((int)param_2 < 0x40047478) {
      if (param_2 != 0x40047473) {
        iVar9 = -1;
        goto locret_F0017A50;
      }
      *param_3 = param_1[6];
      puVar10 = _cons_tp;
    }
    else {
      if (param_2 != 0x4004747c) {
        iVar9 = -1;
        goto locret_F0017A50;
      }
      *param_3 = (uint)*(word *)(param_1 + 0xf);
      puVar10 = _cons_tp;
    }
  }
loc_F0017A4C:
  _cons_tp = puVar10;
  iVar9 = 0;
locret_F0017A50:
  return CONCAT44(param_2,iVar9);
}
/* GHIDRADEC_FUNCTION index=326 start=0xf0017a58 */

/* WARNING: Removing unreachable block (ram,0xf0017a78) */

undefined8 _ttnread(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  piVar2 = (int *)*param_1;
  if ((piVar2[0xf] & 0x20000000U) == 0) {
    uVar1 = piVar2[0xf];
  }
  else {
    _ttypend(piVar2);
    uVar1 = piVar2[0xf];
  }
  iVar3 = piVar2[3];
  if (((uVar1 & 0x22) != 0) &&
     (iVar3 = iVar3 + *piVar2, iVar3 < (int)(uint)*(byte *)((int)param_1 + 0x15))) {
    iVar3 = 0;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=327 start=0xf0017ab0 */

/* WARNING: Removing unreachable block (ram,0xf0017b58) */
/* WARNING: Removing unreachable block (ram,0xf0017b14) */
/* WARNING: Removing unreachable block (ram,0xf0017abc) */
/* WARNING: Removing unreachable block (ram,0xf0017ae0) */
/* WARNING: Removing unreachable block (ram,0xf0017b88) */
/* WARNING: Removing unreachable block (ram,0xf0017b78) */
/* WARNING: Removing unreachable block (ram,0xf0017ab4) */

undefined8 _ttselect(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar3 = param_1;
  _ttynty();
  iVar1 = iVar3;
  _spltty();
  if (param_2 == 1) {
    iVar2 = iVar3;
    _ttnread();
    if ((0 < iVar2) ||
       (((*(uint *)(iVar3 + 0x10) & 0x8000) == 0 && ((*(uint *)(param_1 + 0x40) & 0x10) == 0)))) {
loc_F0017B88:
      _splx(iVar1);
      uVar5 = 1;
      goto locret_F0017B94;
    }
    iVar3 = param_1 + 0x28;
    _selthreadcache();
    if (iVar3 != 0) {
      uVar4 = *(uint *)(param_1 + 0x40) | 0x800;
loc_F0017B74:
      *(uint *)(param_1 + 0x40) = uVar4;
    }
  }
  else if (param_2 == 2) {
    if (*(int *)(param_1 + 0x18) <=
        (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) goto loc_F0017B88;
    iVar3 = param_1 + 0x2c;
    _selthreadcache();
    if (iVar3 != 0) {
      uVar4 = *(uint *)(param_1 + 0x40) | 0x1000;
      goto loc_F0017B74;
    }
  }
  _splx(iVar1);
  uVar5 = 0;
locret_F0017B94:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=328 start=0xf0017b9c */

/* WARNING: Removing unreachable block (ram,0xf0017d60) */
/* WARNING: Removing unreachable block (ram,0xf0017d1c) */
/* WARNING: Removing unreachable block (ram,0xf0017cf4) */
/* WARNING: Removing unreachable block (ram,0xf0017cb0) */
/* WARNING: Removing unreachable block (ram,0xf0017bb8) */
/* WARNING: Removing unreachable block (ram,0xf0017cdc) */
/* WARNING: Removing unreachable block (ram,0xf0017d6c) */
/* WARNING: Removing unreachable block (ram,0xf0017d48) */
/* WARNING: Removing unreachable block (ram,0xf0017d74) */
/* WARNING: Removing unreachable block (ram,0xf0017ba0) */

sqword _ttyopen(undefined2 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
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
  uVar1 = param_2;
  _ttynty();
  puVar7 = (uint *)*_active_u;
  iVar2 = (int)*(sword *)(puVar7 + 0xc);
  _get_posix_proc();
  if ((puVar7[5] & 0x4000) == 0) {
    puVar3 = _active_u;
    if ((puVar7[10] & 0x40000000) != 0) goto loc_F0017CF4;
    _active_u[0x59] = param_2;
    *(undefined2 *)(_active_u + 0x5a) = param_1;
    *(undefined4 *)(uVar1 + 8) = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 8);
    *(uint *)(*(int *)(*(int *)(iVar2 + 0x10) + 8) + 8) = param_2;
    iVar5 = (int)*(sword *)(param_2 + 0x44);
    if (iVar5 == 0) {
      _enterpgrp(puVar7,(int)*(sword *)(puVar7 + 0xc),1);
      *(undefined4 *)(uVar1 + 0xc) = *(undefined4 *)(iVar2 + 0x10);
      *(sword *)(param_2 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0xc);
    }
    else if (iVar5 != *(sword *)((int)puVar7 + 0x2e)) {
      _enterpgrp(puVar7,iVar5,0);
    }
    uVar4 = puVar7[10];
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar2 + 0x10) + 8);
    puVar3 = *(uint **)(iVar5 + 4);
    if ((((puVar3 != puVar7) || (puVar3 = *(uint **)(iVar5 + 8), puVar3 != (uint *)0x0)) ||
        (puVar3 = *(uint **)(uVar1 + 8), *(uint **)(uVar1 + 8) != (uint *)0x0)) ||
       (puVar3 = _active_u, (*(uint *)(iVar2 + 0x18) & 0x40000000) != 0)) goto loc_F0017CF4;
    _active_u[0x59] = param_2;
    *(undefined2 *)(_active_u + 0x5a) = param_1;
    *(undefined4 *)(uVar1 + 8) = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 8);
    *(uint *)(*(int *)(*(int *)(iVar2 + 0x10) + 8) + 8) = param_2;
    *(undefined4 *)(uVar1 + 0xc) = *(undefined4 *)(iVar2 + 0x10);
    *(sword *)(param_2 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0xc);
    uVar4 = puVar7[10];
  }
  puVar7[10] = uVar4 | 0x40000000;
  puVar3 = (uint *)(uVar4 | 0x40000000);
loc_F0017CF4:
  *(undefined2 *)(param_2 + 0x38) = param_1;
  _spltty();
  uVar4 = *(uint *)(param_2 + 0x40);
  uVar6 = uVar4 & 0xfffffffd;
  *(uint *)(param_2 + 0x40) = uVar6;
  if ((uVar4 & 4) == 0) {
    *(uint *)(param_2 + 0x40) = uVar6 | 4;
    _splx(puVar3);
    *(undefined4 *)(uVar1 + 0x10) = 0x1c251a1c;
    *(undefined *)(uVar1 + 0x14) = 0x5c;
    *(undefined *)(uVar1 + 0x15) = 1;
    *(undefined *)(uVar1 + 0x16) = 0;
    _bzero(param_2 + 0x5c,8);
    if (*(char *)(param_2 + 0x47) != '\x02') {
      _ttywflush(param_2);
    }
  }
  else {
    _splx(puVar3);
  }
  _ttysetspec(uVar1);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=329 start=0xf0017d84 */

/* WARNING: Removing unreachable block (ram,0xf0017d88) */

undefined8 _ttylclose(int param_1,undefined4 param_2)

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
  _ttywflush(param_1);
  *(undefined *)(param_1 + 0x47) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=330 start=0xf0017d9c */

/* WARNING: Removing unreachable block (ram,0xf0017e8c) */
/* WARNING: Removing unreachable block (ram,0xf0017e78) */
/* WARNING: Removing unreachable block (ram,0xf0017e14) */
/* WARNING: Removing unreachable block (ram,0xf0017e84) */
/* WARNING: Removing unreachable block (ram,0xf0017e94) */
/* WARNING: Removing unreachable block (ram,0xf0017da0) */

undefined8 _ttyclose(undefined *param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  puVar1 = param_1;
  _ttynty();
  if (param_1 == _cons_tp) {
    _cons_tp = _cons;
    (**(code **)(DAT_f011ca00 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))
              ((int)(sword)*(word *)(param_1 + 0x38),0x20006b08,0,0);
  }
  _ttyflush(param_1,3);
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  puVar1 = (undefined *)_active_u[0x59];
  if (puVar1 == param_1) {
    puVar1 = (undefined *)(*(uint *)(*_active_u + 0x28) & 0xbfffffff);
    *(undefined **)(*_active_u + 0x28) = puVar1;
    *(undefined2 *)(param_1 + 0x44) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x44) = 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  param_1[0x47] = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  _spltty();
  _selthreadclear(param_1 + 0x2c);
  _selthreadclear(param_1 + 0x28);
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=331 start=0xf0017ea4 */

/* WARNING: Removing unreachable block (ram,0xf0017fa0) */
/* WARNING: Removing unreachable block (ram,0xf0017f74) */
/* WARNING: Removing unreachable block (ram,0xf0017ee0) */
/* WARNING: Removing unreachable block (ram,0xf0017fc4) */
/* WARNING: Removing unreachable block (ram,0xf0017f94) */
/* WARNING: Removing unreachable block (ram,0xf0017fac) */
/* WARNING: Removing unreachable block (ram,0xf0017ea8) */

undefined8 _ttymodem(int param_1,int param_2)

{
  int iVar1;
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
  iVar1 = param_1;
  _ttynty();
  uVar2 = *(uint *)(param_1 + 0x40);
  if (((uVar2 & 2) == 0) && ((*(uint *)(param_1 + 0x3c) & 0x100000) != 0)) {
    if (param_2 == 0) {
      if ((uVar2 & 0x100) == 0) {
        *(uint *)(param_1 + 0x40) = uVar2 | 0x100;
        (**(code **)(DAT_f011ca04 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))(param_1,0);
        uVar3 = 1;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      *(uint *)(param_1 + 0x40) = uVar2 & 0xfffffeff;
      _ttstart(param_1);
      uVar3 = 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x40);
    if (param_2 == 0) {
      *(uint *)(param_1 + 0x40) = uVar2 & 0xffffffef;
      if ((uVar2 & 4) != 0) {
        if ((*(uint *)(iVar1 + 0x10) & 0x8000) == 0) {
          _ttwakeup(param_1);
          if ((*(uint *)(param_1 + 0x3c) & 0x1000000) == 0) {
            _gsignal((int)*(sword *)(param_1 + 0x44),1);
            _gsignal((int)*(sword *)(param_1 + 0x44),0x13);
            _ttyflush(param_1,3);
            uVar3 = 0;
          }
          else {
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 1;
        }
        goto locret_F0017FD0;
      }
    }
    else {
      *(uint *)(param_1 + 0x40) = uVar2 | 0x10;
      _wakeup();
    }
    uVar3 = 1;
  }
locret_F0017FD0:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=332 start=0xf0017fd8 */

/* WARNING: Removing unreachable block (ram,0xf0017fdc) */

undefined8 _nullmodem(int param_1,int param_2)

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
  iVar1 = param_1;
  _ttynty();
  iVar2 = param_2;
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffef;
    if ((*(uint *)(iVar1 + 0x10) & 0x8000) == 0) {
      iVar2 = 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x10;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=333 start=0xf0018030 */

/* WARNING: Removing unreachable block (ram,0xf001808c) */
/* WARNING: Removing unreachable block (ram,0xf0018078) */

undefined8 _ttypend(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  param_1[0xf] = param_1[0xf] & 0xdfffffff;
  param_1[0x10] = param_1[0x10] | 0x100000;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  while( true ) {
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    _getc();
    if ((int)puVar1 < 0) break;
    _ttyinput();
  }
  param_1[0x10] = param_1[0x10] & 0xffefffff;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=334 start=0xf00180ac */

/* WARNING: Removing unreachable block (ram,0xf001825c) */
/* WARNING: Removing unreachable block (ram,0xf0018130) */
/* WARNING: Removing unreachable block (ram,0xf0018178) */
/* WARNING: Removing unreachable block (ram,0xf0018158) */
/* WARNING: Removing unreachable block (ram,0xf00181e0) */
/* WARNING: Removing unreachable block (ram,0xf00180dc) */
/* WARNING: Removing unreachable block (ram,0xf0018144) */
/* WARNING: Removing unreachable block (ram,0xf001816c) */
/* WARNING: Removing unreachable block (ram,0xf0018128) */
/* WARNING: Removing unreachable block (ram,0xf001823c) */
/* WARNING: Removing unreachable block (ram,0xf0018274) */
/* WARNING: Removing unreachable block (ram,0xf00180b0) */

undefined8 _ttyinput(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
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
  piVar1 = param_2;
  _ttynty();
  if ((piVar1[4] & 0x800U) == 0) goto locret_F001827C;
  if ((param_2[0xf] & 0x20000000U) != 0) {
    _ttypend(param_2);
  }
  _tk_nin = _tk_nin + 1;
  if (((param_1 & 0xff000000) == 0) && ((param_2[0xf] & 0x20U) != 0)) {
    if (*param_2 < 0x401) {
      uVar2 = param_1;
      _putc(param_1,param_2);
      if ((int)uVar2 < 0) {
        uVar2 = param_2[0xf];
      }
      else {
        piVar3 = piVar1;
        _ttcheckwakeup();
        if (piVar3 != (int *)0x0) {
          _ttwakeup(param_2);
        }
        _ttyecho(param_1,piVar1);
        uVar2 = param_2[0xf];
      }
    }
    else {
      _log(4,aTtyDRawInputOv,(int)*(sword *)(param_2 + 0xe));
      _ttwakeup(param_2);
      uVar2 = param_2[0xf];
    }
    param_2[0xf] = uVar2 & 0xff7fffff;
    if ((piVar1[4] & 0x10U) == 0) goto loc_F00181E8;
    if ((uVar2 & 0x40000000) == 0) {
      uVar2 = param_2[0x10];
loc_F00181D0:
      param_2[0x10] = uVar2 & 0xfffffeff;
      goto loc_F00181E8;
    }
    if (*(char *)((int)param_2 + 0x52) == -1) {
      iVar4 = *param_2;
    }
    else {
      if (*(char *)((int)param_2 + 0x52) == *(char *)((int)param_2 + 0x51)) {
        uVar2 = param_2[0x10];
        goto loc_F00181D0;
      }
      iVar4 = *param_2;
    }
  }
  else {
    _ttcooked(param_1,piVar1);
loc_F00181E8:
    iVar4 = *param_2;
  }
  if ((0x1ff < iVar4 + param_2[3]) && (((param_2[0xf] & 0x22U) != 0 || (0 < param_2[3])))) {
    if ((param_2[0xf] & 1U) == 0) {
      uVar2 = param_2[0x10];
    }
    else if (*(char *)((int)param_2 + 0x52) == -1) {
      uVar2 = param_2[0x10];
    }
    else {
      iVar4 = (int)*(char *)((int)param_2 + 0x52);
      _putc(iVar4,param_2 + 6);
      if (iVar4 == 0) {
        param_2[0x10] = param_2[0x10] | 0x400;
        _ttstart(param_2);
        uVar2 = param_2[0x10];
      }
      else {
        uVar2 = param_2[0x10];
      }
    }
    param_2[0x10] = uVar2 | 0x800000;
  }
  _ttstart(param_2);
locret_F001827C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=335 start=0xf0018284 */

/* WARNING: Removing unreachable block (ram,0xf001846c) */
/* WARNING: Removing unreachable block (ram,0xf0018368) */
/* WARNING: Removing unreachable block (ram,0xf001832c) */
/* WARNING: Removing unreachable block (ram,0xf0018304) */
/* WARNING: Removing unreachable block (ram,0xf00182b4) */
/* WARNING: Removing unreachable block (ram,0xf00183e4) */
/* WARNING: Removing unreachable block (ram,0xf0018314) */
/* WARNING: Removing unreachable block (ram,0xf0018340) */
/* WARNING: Removing unreachable block (ram,0xf001844c) */
/* WARNING: Removing unreachable block (ram,0xf0018484) */
/* WARNING: Removing unreachable block (ram,0xf0018288) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _ttyblkin(undefined *param_1,undefined *param_2,int *param_3)

{
  undefined uVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
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
  piVar2 = param_3;
  _ttynty();
  if ((piVar2[4] & 0x800U) == 0) goto locret_F001848C;
  if ((param_3[0xf] & 0x20000000U) != 0) {
    _ttypend(param_3);
  }
  _tk_nin = _tk_nin + (int)param_2;
  if ((param_3[0xf] & 0x20U) == 0) {
    param_2 = param_2 + -1;
    if ((int)param_2 < 0) {
      iVar5 = *param_3;
      goto loc_F00183FC;
    }
    uVar1 = *param_1;
    while( true ) {
      param_1 = param_1 + 1;
      _ttcooked(uVar1,piVar2);
      param_2 = param_2 + -1;
      if ((int)param_2 < 0) break;
      uVar1 = *param_1;
    }
loc_F00183F8:
    iVar5 = *param_3;
  }
  else {
    if (0x400 < (int)(param_2 + *param_3)) {
      param_2 = (undefined *)(0x400 - *param_3);
      if ((int)param_2 < 0) {
        param_2 = (undefined *)0x0;
      }
      _log(4,aTtyDRawInputOv_0,(int)*(sword *)(param_3 + 0xe));
    }
    puVar3 = param_1;
    _b_to_q(param_1,param_2,param_3);
    if (param_2 == puVar3 || (int)param_2 - (int)puVar3 < 0) {
      uVar6 = param_3[0xf];
    }
    else {
      piVar4 = piVar2;
      _ttcheckwakeup();
      if (piVar4 == (int *)0x0) {
        uVar6 = param_3[0xf];
      }
      else {
        _ttwakeup(param_3);
        uVar6 = param_3[0xf];
      }
    }
    param_3[0xf] = uVar6 & 0xff7fffff;
    if ((uVar6 & 8) != 0) {
      puVar3 = param_1;
      _b_to_q(param_1,param_2,param_3 + 6);
      _tk_nout = _tk_nout + (int)puVar3;
    }
    if ((piVar2[4] & 0x10U) == 0) goto loc_F00183F8;
    if ((param_3[0xf] & 0x40000000U) == 0) {
      uVar6 = param_3[0x10];
loc_F00183C4:
      param_3[0x10] = uVar6 & 0xfffffeff;
      goto loc_F00183F8;
    }
    if (*(char *)((int)param_3 + 0x52) == -1) {
      iVar5 = *param_3;
    }
    else {
      if (*(char *)((int)param_3 + 0x52) == *(char *)((int)param_3 + 0x51)) {
        uVar6 = param_3[0x10];
        goto loc_F00183C4;
      }
      iVar5 = *param_3;
    }
  }
loc_F00183FC:
  if ((0x1ff < iVar5 + param_3[3]) && (((param_3[0xf] & 0x22U) != 0 || (0 < param_3[3])))) {
    if ((param_3[0xf] & 1U) == 0) {
      uVar6 = param_3[0x10];
    }
    else if (*(char *)((int)param_3 + 0x52) == -1) {
      uVar6 = param_3[0x10];
    }
    else {
      iVar5 = (int)*(char *)((int)param_3 + 0x52);
      _putc(iVar5,param_3 + 6);
      if (iVar5 == 0) {
        param_3[0x10] = param_3[0x10] | 0x400;
        _ttstart(param_3);
        uVar6 = param_3[0x10];
      }
      else {
        uVar6 = param_3[0x10];
      }
    }
    param_3[0x10] = uVar6 | 0x800000;
  }
  _ttstart(param_3);
locret_F001848C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=336 start=0xf0018494 */

/* WARNING: Removing unreachable block (ram,0xf0018714) */
/* WARNING: Removing unreachable block (ram,0xf0018b44) */
/* WARNING: Removing unreachable block (ram,0xf0018af8) */
/* WARNING: Removing unreachable block (ram,0xf0018bb0) */
/* WARNING: Removing unreachable block (ram,0xf0018bf0) */
/* WARNING: Removing unreachable block (ram,0xf0018bd4) */
/* WARNING: Removing unreachable block (ram,0xf0018d98) */
/* WARNING: Removing unreachable block (ram,0xf0018eb4) */
/* WARNING: Removing unreachable block (ram,0xf0018e18) */
/* WARNING: Removing unreachable block (ram,0xf0018dc0) */
/* WARNING: Removing unreachable block (ram,0xf0018c60) */
/* WARNING: Removing unreachable block (ram,0xf0018ce4) */
/* WARNING: Removing unreachable block (ram,0xf0018c7c) */
/* WARNING: Removing unreachable block (ram,0xf0018c3c) */
/* WARNING: Removing unreachable block (ram,0xf0018aa8) */
/* WARNING: Removing unreachable block (ram,0xf0018a00) */
/* WARNING: Removing unreachable block (ram,0xf0018a50) */
/* WARNING: Removing unreachable block (ram,0xf0018a28) */
/* WARNING: Removing unreachable block (ram,0xf0018940) */
/* WARNING: Removing unreachable block (ram,0xf0018798) */
/* WARNING: Removing unreachable block (ram,0xf0018808) */
/* WARNING: Removing unreachable block (ram,0xf00187f0) */
/* WARNING: Removing unreachable block (ram,0xf00186bc) */
/* WARNING: Removing unreachable block (ram,0xf0018574) */
/* WARNING: Removing unreachable block (ram,0xf00184f8) */
/* WARNING: Removing unreachable block (ram,0xf0018658) */
/* WARNING: Removing unreachable block (ram,0xf00186a8) */
/* WARNING: Removing unreachable block (ram,0xf00187fc) */
/* WARNING: Removing unreachable block (ram,0xf001878c) */
/* WARNING: Removing unreachable block (ram,0xf00187b8) */
/* WARNING: Removing unreachable block (ram,0xf0018948) */
/* WARNING: Removing unreachable block (ram,0xf0018a3c) */
/* WARNING: Removing unreachable block (ram,0xf0018a5c) */
/* WARNING: Removing unreachable block (ram,0xf0018a14) */
/* WARNING: Removing unreachable block (ram,0xf0018ab0) */
/* WARNING: Removing unreachable block (ram,0xf0018c74) */
/* WARNING: Removing unreachable block (ram,0xf0018cdc) */
/* WARNING: Removing unreachable block (ram,0xf0018d10) */
/* WARNING: Removing unreachable block (ram,0xf0018d3c) */
/* WARNING: Removing unreachable block (ram,0xf0018e10) */
/* WARNING: Removing unreachable block (ram,0xf0018ea4) */
/* WARNING: Removing unreachable block (ram,0xf0018f10) */
/* WARNING: Removing unreachable block (ram,0xf0018dac) */
/* WARNING: Removing unreachable block (ram,0xf0018be8) */
/* WARNING: Removing unreachable block (ram,0xf0018ba8) */
/* WARNING: Removing unreachable block (ram,0xf0018aec) */
/* WARNING: Removing unreachable block (ram,0xf0018b28) */
/* WARNING: Removing unreachable block (ram,0xf0018708) */
/* WARNING: Removing unreachable block (ram,0xf0018734) */
/* WARNING: Removing unreachable block (ram,0xf0018568) */
/* WARNING: Removing unreachable block (ram,0xf00184ec) */

undefined8 _ttcooked(int *param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar9;
  uint uVar10;
  undefined4 unaff_l3;
  uint uVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  piVar9 = (int *)*param_2;
  uVar10 = param_2[4];
  uVar11 = piVar9[0xf];
  piVar12 = param_1;
  if (((uint)param_1 & 0xff000000) != 0) {
    piVar12 = (int *)((uint)param_1 & 0xffffff);
    if ((((uint)param_1 & 0x1000000) == 0) || (piVar12 != (int *)0x0)) {
      if (((((uint)param_1 & 0x2000000) != 0) && ((uVar10 & 0x200000) != 0)) ||
         (((uint)param_1 & 0x1000000) != 0)) {
        bVar13 = (uVar10 & 0x10) == 0;
        if ((uVar10 & 0x80000) != 0) goto loc_F0018F2C;
        if ((uVar10 & 0x100000) != 0) goto loc_F0018568;
        piVar12 = (int *)0x100;
      }
      goto loc_F0018588;
    }
    bVar13 = (uVar10 & 0x10) == 0;
    if ((uVar10 & 0x20000) == 0) {
      if ((uVar10 & 0x40000) != 0) {
        _ttyflush(piVar9,3);
        _gsignal((int)*(sword *)(piVar9 + 0x11),2);
        bVar13 = (uVar10 & 0x10) == 0;
        goto loc_F0018F2C;
      }
      if ((uVar10 & 0x100000) != 0) {
loc_F0018568:
        _putc(0x1ff,piVar9);
        _putc(0x100,piVar9);
        piVar12 = (int *)((uint)piVar12 | 0x100);
        goto loc_F0018588;
      }
      uVar6 = piVar9[0x10];
      goto loc_F001858C;
    }
    goto loc_F0018F2C;
  }
loc_F0018588:
  uVar6 = piVar9[0x10];
loc_F001858C:
  if ((uVar6 & 0x100000) == 0) {
    if ((uVar11 & 0x8000020) == 0) {
      if ((uVar10 & 0x400000) != 0) {
        piVar12 = (int *)((uint)piVar12 & 0xffffff7f);
      }
      uVar6 = piVar9[0x10];
    }
    else {
      uVar6 = piVar9[0x10];
    }
  }
  else {
    uVar6 = piVar9[0x10];
  }
  if ((uVar6 & 0x80000) != 0) {
    piVar12 = (int *)((uint)piVar12 | 0x100);
    piVar9[0x10] = uVar6 & 0xfff7ffff;
  }
  bVar13 = (uVar11 & 0x22) == 0;
  if ((((uint)piVar12 & 0x100) == 0) &&
     (bVar13 = (uVar11 & 0x22) == 0, (piVar9[0x10] & 0x400000U) == 0)) {
    if ((piVar9[((int)piVar12 >> 5) + 0x19] >> ((byte)piVar12 & 0x1f) & 1U) == 0) {
      bVar13 = (uVar11 & 0x22) == 0;
      goto loc_F0018624;
    }
    bVar13 = (uVar10 & 0x10) == 0;
    if (((uVar10 & 0x181000) == 0x101000) && (bVar13 = (uVar10 & 0x10) == 0, piVar12 == (int *)0xff)
       ) {
      _putc(0x1ff,piVar9);
      piVar12 = (int *)0x1ff;
      bVar13 = (uVar10 & 0x10) == 0;
    }
    uVar6 = (uint)piVar12 & 0xff;
    if (bVar13) {
      bVar13 = (uVar10 & 8) == 0;
loc_F001874C:
      uVar6 = (uint)piVar12 & 0xff;
      if (!bVar13) {
        if ((uVar6 == 0xff) ||
           ((uVar6 != *(byte *)((int)piVar9 + 0x4f) && (uVar6 != *(byte *)(piVar9 + 0x14))))) {
          if ((((uint)piVar12 & 0xff) == 0xff) ||
             (((uint)piVar12 & 0xff) != (uint)*(byte *)((int)piVar9 + 0x55))) goto loc_F001881C;
          if (-1 < (int)uVar11) {
            _ttyflush(piVar9,1);
          }
          _ttyecho(piVar12,param_2);
          _gsignal((int)*(sword *)(piVar9 + 0x11),0x12);
          bVar13 = (uVar10 & 0x10) == 0;
        }
        else {
          if (-1 < (int)uVar11) {
            _ttyflush(piVar9,3);
          }
          _ttyecho(piVar12,param_2);
          uVar8 = 3;
          if (uVar6 == *(byte *)((int)piVar9 + 0x4f)) {
            uVar8 = 2;
          }
          _gsignal((int)*(sword *)(piVar9 + 0x11),uVar8);
          bVar13 = (uVar10 & 0x10) == 0;
        }
        goto loc_F0018F2C;
      }
loc_F001881C:
      uVar6 = (uint)piVar12 & 0xff;
      if (((uVar10 & 0x4000000) == 0) || (uVar6 == 0xff)) {
loc_F00188C4:
        if (piVar12 == (int *)0xd) {
          bVar13 = (uVar10 & 0x10) == 0;
          if ((uVar10 & 0x1000000) != 0) goto loc_F0018F2C;
          if ((uVar11 & 0x10) != 0) {
            piVar12 = (int *)0xa;
            goto loc_F0018918;
          }
          bVar13 = (uVar11 & 4) == 0;
          if ((uVar10 & 0x2000000) != 0) {
            piVar12 = (int *)0xa;
          }
        }
        else {
          bVar13 = (uVar11 & 4) == 0;
          if (piVar12 == (int *)0xa) {
            if ((uVar10 & 0x800000) != 0) {
              piVar12 = (int *)0xd;
            }
loc_F0018918:
            bVar13 = (uVar11 & 4) == 0;
          }
        }
        if (!bVar13) {
          bVar13 = (uVar11 & 0x22) == 0;
          if (0x7f < (int)piVar12) goto loc_F00189B4;
          if ((piVar9[0x10] & 0x10000U) == 0) {
            if ((int)piVar12 - 0x41U < 0x1a) {
              piVar12 = piVar12 + 8;
            }
            else {
              bVar13 = (uVar11 & 0x22) == 0;
              if (piVar12 != (int *)0x5c) goto loc_F00189B4;
              piVar9[0x10] = piVar9[0x10] | 0x10000;
            }
            goto loc_F00189B0;
          }
          _unputc(piVar9);
          _ttyrub();
          if ((int *)(int)*(char *)(piVar12 + -0x3fbd258) != (int *)0x0) {
            piVar12 = (int *)(int)*(char *)(piVar12 + -0x3fbd258);
          }
          piVar12 = (int *)((uint)piVar12 | 0x100);
          piVar9[0x10] = piVar9[0x10] & 0xfffcffff;
          if ((uVar11 & 0x22) != 0) goto loc_F00189BC;
          iVar3 = *piVar9;
          goto loc_F0018D50;
        }
loc_F00189B0:
        bVar13 = (uVar11 & 0x22) == 0;
loc_F00189B4:
        if (bVar13) {
          uVar6 = (uint)piVar12 & 0xff;
          if ((piVar9[0x10] & 0x20000U) == 0) {
loc_F0018AC4:
            if ((uVar6 == 0xff) || (uVar6 != *(byte *)((int)piVar9 + 0x4d))) goto loc_F0018B54;
            bVar13 = (uVar10 & 0x10) == 0;
            if (*piVar9 == 0) goto loc_F0018F2C;
            piVar12 = piVar9;
            _unputc();
            _ttyrub();
            if ((uVar11 & 0x80000) != 0) {
              bVar13 = (uVar10 & 0x10) == 0;
              if ((((uint)piVar12 & 0x80) != 0) && (bVar13 = (uVar10 & 0x10) == 0, *piVar9 != 0)) {
                piVar12 = piVar9;
                _unputc();
                if (((uint)piVar12 & 0xff) == 0x8e) goto loc_F0018F28;
                _ttyrub(piVar12,param_2);
                bVar13 = (uVar10 & 0x10) == 0;
              }
              goto loc_F0018F2C;
            }
            goto loc_F0018F28;
          }
          if (uVar6 != 0xff) {
            if ((uVar6 == *(byte *)((int)piVar9 + 0x4d)) || (uVar6 == *(byte *)((int)piVar9 + 0x4e))
               ) {
              _unputc(piVar9);
              _ttyrub();
              piVar12 = (int *)((uint)piVar12 | 0x100);
              iVar3 = *piVar9;
              goto loc_F0018D50;
            }
            goto loc_F0018AC4;
          }
loc_F0018B54:
          if ((((uint)piVar12 & 0xff) != 0xff) &&
             (((uint)piVar12 & 0xff) == (uint)*(byte *)((int)piVar9 + 0x4e))) {
            if (((uVar10 & 4) == 0) ||
               (((uVar11 & 0x4000000) == 0 || (*piVar9 != (int)*(char *)((int)piVar9 + 0x4b))))) {
              _ttyecho(piVar12,param_2);
              if ((uVar10 & 4) != 0) {
                _ttyecho(10,param_2);
              }
              do {
                piVar5 = piVar9;
                _getc();
              } while (0 < (int)piVar5);
              *(undefined *)((int)piVar9 + 0x4b) = 0;
              uVar6 = piVar9[0x10];
            }
            else if (*piVar9 == 0) {
              uVar6 = piVar9[0x10];
            }
            else {
              do {
                _unputc(piVar9);
                _ttyrub();
              } while (*piVar9 != 0);
              uVar6 = piVar9[0x10];
            }
            piVar9[0x10] = uVar6 & 0xffc0ffff;
            goto loc_F0018F28;
          }
          if ((((uint)piVar12 & 0xff) != 0xff) &&
             (((uint)piVar12 & 0xff) == (uint)*(byte *)((int)piVar9 + 0x59))) {
            while( true ) {
              piVar12 = piVar9;
              _unputc();
              if ((piVar12 != (int *)0x20) && (piVar12 != (int *)0x9)) break;
              _ttyrub(piVar12,param_2);
            }
            if (piVar12 != (int *)0xffffffff) {
              _ttyrub(piVar12,param_2);
              piVar12 = piVar9;
              _unputc();
              if (piVar12 != (int *)0xffffffff) {
                bVar2 = _partab[(uint)piVar12 & 0xff];
                if ((piVar12 != (int *)0x20) && (piVar12 != (int *)0x9)) {
                  while (((uVar10 & 0x20) == 0 ||
                         ((_partab[(uint)piVar12 & 0xff] & 0x40) == (bVar2 & 0x40)))) {
                    _ttyrub(piVar12,param_2);
                    piVar12 = piVar9;
                    _unputc();
                    if (piVar12 == (int *)0xffffffff) goto loc_F0018F28;
                    if ((piVar12 == (int *)0x20) || (piVar12 == (int *)0x9)) break;
                  }
                }
                _putc(piVar12,piVar9);
                bVar13 = (uVar10 & 0x10) == 0;
                goto loc_F0018F2C;
              }
            }
            goto loc_F0018F28;
          }
          if (((uint)piVar12 & 0xff) == 0xff) {
            iVar3 = *piVar9;
loc_F0018D50:
            iVar7 = piVar9[3];
            goto loc_F0018D54;
          }
          if (((uint)piVar12 & 0xff) != (uint)*(byte *)((int)piVar9 + 0x57)) {
            iVar3 = *piVar9;
            goto loc_F0018D50;
          }
          _ttyretype(param_2);
          bVar13 = (uVar10 & 0x10) == 0;
          goto loc_F0018F2C;
        }
loc_F00189BC:
        iVar3 = *piVar9;
        goto loc_F00189C0;
      }
      if (uVar6 == *(byte *)((int)piVar9 + 0x52)) {
        if ((piVar9[0x10] & 0x100U) == 0) {
          piVar9[0x10] = piVar9[0x10] | 0x100;
          (**(code **)(DAT_f011ca04 + (uint)(*(word *)(piVar9 + 0xe) >> 8) * 0x2c))(piVar9,0);
          goto locret_F0018F88;
        }
        bVar13 = (uVar10 & 0x10) == 0;
        if (uVar6 != *(byte *)((int)piVar9 + 0x51)) goto locret_F0018F88;
        goto loc_F0018F2C;
      }
      if ((uVar6 == 0xff) || (uVar6 != *(byte *)((int)piVar9 + 0x51))) goto loc_F00188C4;
      uVar10 = piVar9[0x10];
      goto loc_F0018F70;
    }
    bVar13 = (uVar10 & 8) == 0;
    if (uVar6 == 0xff) goto loc_F001874C;
    if (uVar6 == *(byte *)((int)piVar9 + 0x5a)) {
      if ((uVar11 & 8) == 0) {
loc_F00186C4:
        uVar6 = piVar9[0x10];
      }
      else {
        if ((uVar11 & 0x40000) == 0) {
          _ttyecho(piVar12,param_2);
          goto loc_F00186C4;
        }
        _ttyoutstr(&asc_F010B838,piVar9);
        uVar6 = piVar9[0x10];
      }
      piVar9[0x10] = uVar6 | 0x80000;
      goto loc_F0018F28;
    }
    bVar13 = (uVar10 & 8) == 0;
    if ((uVar6 == 0xff) || (bVar13 = (uVar10 & 8) == 0, uVar6 != *(byte *)(piVar9 + 0x16)))
    goto loc_F001874C;
    if ((uVar11 & 0x800000) != 0) {
      uVar11 = piVar9[0xf];
      goto loc_F0018F7C;
    }
    _ttyflush(piVar9,2);
    _ttyecho(piVar12,param_2);
    if (*piVar9 + piVar9[3] == 0) {
      uVar11 = piVar9[0xf];
    }
    else {
      _ttyretype(param_2);
      uVar11 = piVar9[0xf];
    }
    uVar11 = uVar11 | 0x800000;
  }
  else {
loc_F0018624:
    iVar3 = *piVar9;
    if (bVar13) {
      iVar7 = piVar9[3];
loc_F0018D54:
      if (iVar3 + iVar7 < 0x400) {
        piVar5 = piVar12;
        _putc(piVar12,piVar9);
        if (-1 < (int)piVar5) {
          if (piVar12 == (int *)0xa) {
            *(undefined *)((int)piVar9 + 0x4b) = 0;
loc_F0018E0C:
            _catq(piVar9,piVar9 + 3);
            _ttwakeup(piVar9);
            uVar6 = piVar9[0x10];
          }
          else {
            if ((piVar12 == (int *)(uint)*(byte *)((int)piVar9 + 0x53)) ||
               (piVar12 == (int *)(uint)*(byte *)(piVar9 + 0x15))) {
              if (piVar12 != (int *)0xff) {
                *(undefined *)((int)piVar9 + 0x4b) = 0;
                goto loc_F0018E0C;
              }
              cVar1 = *(char *)((int)piVar9 + 0x4b);
            }
            else {
              cVar1 = *(char *)((int)piVar9 + 0x4b);
            }
            *(char *)((int)piVar9 + 0x4b) = cVar1 + '\x01';
            if (cVar1 == '\0') {
              *(undefined *)(piVar9 + 0x13) = *(undefined *)(piVar9 + 0x12);
            }
            uVar6 = piVar9[0x10];
          }
          piVar9[0x10] = uVar6 & 0xfffdffff;
          if ((uVar6 & 0x400000) == 0) {
            if (((uint)piVar12 & 0xff) == 0xff) {
              uVar6 = piVar9[0x10];
            }
            else if (((uint)piVar12 & 0xff) == (uint)*(byte *)(param_2 + 5)) {
              piVar9[0x10] = uVar6 & 0xfffdffff | 0x20000;
              uVar6 = piVar9[0x10];
            }
            else {
              uVar6 = piVar9[0x10];
            }
            if ((uVar6 & 0x40000) != 0) {
              piVar9[0x10] = uVar6 & 0xfffbffff;
              _ttyoutput(0x2f,piVar9);
            }
            cVar1 = *(char *)(piVar9 + 0x12);
            _ttyecho(piVar12,param_2);
            bVar13 = (uVar10 & 0x10) == 0;
            if (((((uint)piVar12 & 0xff) != 0xff) &&
                (bVar13 = (uVar10 & 0x10) == 0,
                ((uint)piVar12 & 0xff) == (uint)*(byte *)((int)piVar9 + 0x53))) &&
               (bVar13 = (uVar10 & 0x10) == 0, (uVar11 & 8) != 0)) {
              iVar3 = 2;
              if ((int)*(char *)(piVar9 + 0x12) - (int)cVar1 < 3) {
                iVar3 = (int)*(char *)(piVar9 + 0x12) - (int)cVar1;
              }
              bVar13 = (uVar10 & 0x10) == 0;
              if (0 < iVar3) {
                do {
                  _ttyoutput(8,piVar9);
                  iVar3 = iVar3 + -1;
                } while (0 < iVar3);
                goto loc_F0018F28;
              }
            }
            goto loc_F0018F2C;
          }
        }
loc_F0018F28:
        bVar13 = (uVar10 & 0x10) == 0;
      }
      else {
        if (((uVar10 & 0x8000000) != 0) &&
           (piVar9[6] < (int)*(sword *)(_tthiwat + (*(byte *)((int)piVar9 + 0x4a) & 0x1f) * 2))) {
          _ttyoutput(7,piVar9);
        }
        _log(4,aTtyDCanonInput,(int)*(sword *)(piVar9 + 0xe));
        bVar13 = (uVar10 & 0x10) == 0;
      }
    }
    else {
loc_F00189C0:
      if (iVar3 < 0x401) {
        piVar5 = piVar12;
        _putc(piVar12,piVar9);
        bVar13 = (uVar10 & 0x10) == 0;
        if (-1 < (int)piVar5) {
          puVar4 = param_2;
          _ttcheckwakeup();
          if (puVar4 != (undefined4 *)0x0) {
            _ttwakeup(piVar9);
          }
          _ttyecho(piVar12,param_2);
          bVar13 = (uVar10 & 0x10) == 0;
        }
      }
      else {
        if ((piVar9[6] < (int)*(sword *)(_tthiwat + (*(byte *)((int)piVar9 + 0x4a) & 0x1f) * 2)) &&
           ((uVar10 & 0x8000000) != 0)) {
          _ttyoutput(7,piVar9);
        }
        _log(4,aTtyDCbreakInpu,(int)*(sword *)(piVar9 + 0xe));
        bVar13 = (uVar10 & 0x10) == 0;
      }
    }
loc_F0018F2C:
    if (bVar13) goto locret_F0018F88;
    uVar10 = piVar9[0x10];
    if ((uVar11 & 0x40000000) == 0) {
loc_F0018F70:
      uVar11 = piVar9[0xf];
    }
    else {
      if ((uVar10 & 0x100) != 0) {
        if ((*(char *)((int)piVar9 + 0x52) == -1) ||
           (*(char *)((int)piVar9 + 0x52) != *(char *)((int)piVar9 + 0x51))) goto locret_F0018F88;
        uVar10 = piVar9[0x10];
        goto loc_F0018F70;
      }
      uVar11 = piVar9[0xf];
    }
    piVar9[0x10] = uVar10 & 0xfffffeff;
loc_F0018F7C:
    uVar11 = uVar11 & 0xff7fffff;
  }
  piVar9[0xf] = uVar11;
locret_F0018F88:
  return CONCAT44(param_2,piVar12);
}
/* GHIDRADEC_FUNCTION index=337 start=0xf0018f90 */

/* WARNING: Removing unreachable block (ram,0xf00193b0) */
/* WARNING: Removing unreachable block (ram,0xf00191ac) */
/* WARNING: Removing unreachable block (ram,0xf001911c) */
/* WARNING: Removing unreachable block (ram,0xf001909c) */
/* WARNING: Removing unreachable block (ram,0xf0018fdc) */
/* WARNING: Removing unreachable block (ram,0xf0019084) */
/* WARNING: Removing unreachable block (ram,0xf00190b8) */
/* WARNING: Removing unreachable block (ram,0xf0019158) */
/* WARNING: Removing unreachable block (ram,0xf00191dc) */
/* WARNING: Removing unreachable block (ram,0xf0019404) */
/* WARNING: Removing unreachable block (ram,0xf0018f94) */

undefined8 _ttyoutput(uint param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  byte bVar5;
  undefined4 unaff_l0;
  char *pcVar6;
  uint uVar7;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
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
  iVar9 = param_2;
  _ttynty();
  uVar8 = *(uint *)(param_2 + 0x3c);
  if (((uVar8 & 0x200020) != 0) || ((*(uint *)(iVar9 + 0x10) & 0x10000000) == 0)) {
    if ((uVar8 & 0x800000) == 0) {
      uVar8 = param_1;
      _putc(param_1,param_2 + 0x18);
      if (uVar8 == 0) {
        param_1 = 0xffffffff;
        _tk_nout = _tk_nout + 1;
      }
    }
    else {
      param_1 = 0xffffffff;
    }
    goto locret_F0019410;
  }
  if ((uVar8 & 0x2000000) == 0) {
    if ((*(uint *)(iVar9 + 0x10) & 0x300) == 0x300) {
      param_1 = param_1 & 0xff;
    }
    else {
      param_1 = param_1 & 0x7f;
    }
  }
  else {
    param_1 = param_1 & 0xff;
  }
  if ((param_1 != 4) || ((uVar8 & 2) != 0)) {
    if ((param_1 == 9) &&
       (((uVar8 & 0xc00) == 0xc00 && ((*(uint *)(param_2 + 0x40) & 0x400000) == 0)))) {
      uVar2 = *(byte *)(param_2 + 0x48) & 7;
      iVar9 = 8 - uVar2;
      if ((uVar8 & 0x800000) == 0) {
        _spltty();
        puVar3 = asc_F010B880;
        _b_to_q(asc_F010B880,iVar9,param_2 + 0x18);
        iVar9 = iVar9 - (int)puVar3;
        _tk_nout = _tk_nout + iVar9;
        _splx(uVar2);
      }
      param_1 = 9;
      *(char *)(param_2 + 0x48) = *(char *)(param_2 + 0x48) + (char)iVar9;
      if (iVar9 != 0) {
        param_1 = 0xffffffff;
      }
      goto locret_F0019410;
    }
    _tk_nout = _tk_nout + 1;
    if ((uVar8 & 4) != 0) {
      pcVar6 = asc_F010B890;
      cVar1 = asc_F010B890[0];
      while (cVar1 != '\0') {
        if (param_1 == (int)pcVar6[1]) {
          iVar4 = 0x5c;
          _ttyoutput(0x5c,param_2);
          if (-1 < iVar4) goto locret_F0019410;
          param_1 = (uint)*pcVar6;
          break;
        }
        cVar1 = pcVar6[2];
        pcVar6 = pcVar6 + 2;
      }
      iVar4 = 0x5c;
      if (param_1 - 0x41 < 0x1a) {
        _ttyoutput(0x5c,param_2);
        if (-1 < iVar4) goto locret_F0019410;
      }
      else if (param_1 - 0x61 < 0x1a) {
        param_1 = param_1 - 0x20;
      }
    }
    if ((param_1 == 10) && (((uVar8 & 0x10) != 0 || ((*(uint *)(iVar9 + 0x10) & 0x20000000) != 0))))
    {
      iVar4 = 0xd;
      _ttyoutput(0xd,param_2);
      if (-1 < iVar4) {
        param_1 = 10;
        goto locret_F0019410;
      }
    }
    if (((uVar8 & 0x800000) == 0) && (uVar2 = param_1, _putc(param_1,param_2 + 0x18), uVar2 != 0))
    goto locret_F0019410;
    uVar7 = 0;
    bVar5 = *(byte *)(param_2 + 0x48);
    uVar2 = (uint)(char)bVar5;
    switch(_partab[param_1] & 0x3f) {
    case :
      bVar5 = bVar5 + 1;
      break;
    case :
      if (0 < (int)uVar2) {
        bVar5 = bVar5 - 1;
        break;
      }
      bVar10 = true;
      goto loc_F00193D4;
    case :
      uVar8 = (int)uVar8 >> 8 & 3;
      if (uVar8 == 1) {
        if (0 < (int)uVar2) {
          uVar7 = (uVar2 >> 4) + 3;
          if (uVar7 < 7) {
            bVar5 = 0;
            break;
          }
          uVar7 = 6;
        }
      }
      else {
        if (uVar8 != 2) {
          bVar5 = 0;
          break;
        }
        uVar7 = _hz * 100 >> 10;
      }
loc_F00193CC:
      bVar5 = 0;
      break;
    case :
      if (((uVar8 & 0xc00) == 0x400) && (uVar7 = 1 - (uVar2 | 0xfffffff8), (int)uVar7 < 5)) {
        uVar7 = 0;
      }
      bVar5 = bVar5 + 8 & 0xf8;
      break;
    case :
      if ((uVar8 & 0x4000) == 0) {
        bVar10 = true;
        goto loc_F00193D4;
      }
      uVar7 = 0x7f;
      break;
    case :
      uVar8 = *(int *)(param_2 + 0x3c) >> 0xc & 3;
      if (uVar8 == 2) {
        uVar7 = _hz * 0xa6 >> 10;
        goto loc_F00193CC;
      }
      if (uVar8 < 3) {
        if (uVar8 == 1) {
          uVar7 = _hz * 0x53 >> 10;
          goto loc_F00193CC;
        }
        bVar5 = 0;
      }
      else {
        if (uVar8 == 3) {
          if (-1 < (int)uVar2) {
            if (8 < (int)uVar2) {
              uVar7 = 0;
              goto loc_F00193CC;
            }
            do {
              _putc(0x7f,param_2 + 0x18);
              uVar2 = uVar2 + 1;
            } while ((int)uVar2 < 9);
          }
          uVar7 = 0;
          goto loc_F00193CC;
        }
        bVar5 = 0;
      }
    }
    bVar10 = uVar7 == 0;
loc_F00193D4:
    *(byte *)(param_2 + 0x48) = bVar5;
    if (!bVar10) {
      param_1 = 0xffffffff;
      if (((*(uint *)(param_2 + 0x3c) & 0x2800000) != 0) ||
         ((*(uint *)(iVar9 + 0x10) & 0x300) == 0x300)) goto locret_F0019410;
      _putc(uVar7 | 0x80,param_2 + 0x18);
    }
  }
  param_1 = 0xffffffff;
locret_F0019410:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=338 start=0xf0019418 */

/* WARNING: Removing unreachable block (ram,0xf001985c) */
/* WARNING: Removing unreachable block (ram,0xf001980c) */
/* WARNING: Removing unreachable block (ram,0xf00199f4) */
/* WARNING: Removing unreachable block (ram,0xf00199d0) */
/* WARNING: Removing unreachable block (ram,0xf0019984) */
/* WARNING: Removing unreachable block (ram,0xf00198e0) */
/* WARNING: Removing unreachable block (ram,0xf001987c) */
/* WARNING: Removing unreachable block (ram,0xf00197a8) */
/* WARNING: Removing unreachable block (ram,0xf0019780) */
/* WARNING: Removing unreachable block (ram,0xf001968c) */
/* WARNING: Removing unreachable block (ram,0xf0019704) */
/* WARNING: Removing unreachable block (ram,0xf00195f4) */
/* WARNING: Removing unreachable block (ram,0xf00195d8) */
/* WARNING: Removing unreachable block (ram,0xf00194b8) */
/* WARNING: Removing unreachable block (ram,0xf001944c) */
/* WARNING: Removing unreachable block (ram,0xf0019430) */
/* WARNING: Removing unreachable block (ram,0xf0019454) */
/* WARNING: Removing unreachable block (ram,0xf0019500) */
/* WARNING: Removing unreachable block (ram,0xf00195e8) */
/* WARNING: Removing unreachable block (ram,0xf0019714) */
/* WARNING: Removing unreachable block (ram,0xf001969c) */
/* WARNING: Removing unreachable block (ram,0xf0019768) */
/* WARNING: Removing unreachable block (ram,0xf0019798) */
/* WARNING: Removing unreachable block (ram,0xf0019870) */
/* WARNING: Removing unreachable block (ram,0xf00198cc) */
/* WARNING: Removing unreachable block (ram,0xf0019914) */
/* WARNING: Removing unreachable block (ram,0xf0019998) */
/* WARNING: Removing unreachable block (ram,0xf00199e4) */
/* WARNING: Removing unreachable block (ram,0xf00199fc) */
/* WARNING: Removing unreachable block (ram,0xf001982c) */
/* WARNING: Removing unreachable block (ram,0xf0019864) */
/* WARNING: Removing unreachable block (ram,0xf001941c) */

undefined8 _ttread(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  int *piVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int *piVar12;
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
  piVar3 = param_1;
  _ttynty();
  piVar12 = (int *)0x0;
  bVar1 = false;
  puVar5 = (undefined *)piVar3;
loc_F0019430:
  do {
    uVar10 = param_1[0xf];
    _spltty();
    if ((uVar10 & 0x20000000) != 0) {
      _ttypend(param_1);
    }
    _splx(puVar5);
    uVar7 = param_1[0x10];
    if ((uVar7 & 0x10) == 0) {
      uVar4 = piVar3[4];
      while ((uVar4 & 0x8000) == 0) {
        if ((uVar7 & 0x8000) == 0) goto loc_F00195D0;
        if ((uVar7 & 0x2000) != 0) {
          uVar10 = *(uint *)(*_active_u + 0x14);
          goto loc_F0019850;
        }
        _sleep(param_1,0x1c);
        uVar7 = param_1[0x10];
        if ((uVar7 & 0x10) != 0) break;
        uVar4 = piVar3[4];
      }
    }
    iVar9 = *_active_u;
    if ((*(uint *)(iVar9 + 0x14) & 0x4000) != 0) {
      puVar5 = (undefined *)(int)*(sword *)(iVar9 + 0x30);
      _get_posix_proc();
      if (param_1 == (int *)_active_u[0x59]) {
        piVar11 = (int *)((int)puVar5 + 0x10);
        puVar5 = (undefined *)(int)*(sword *)(param_1 + 0x11);
        piVar8 = *(int **)(*piVar11 + 0xc);
        if (piVar8 != (int *)puVar5) {
          if ((*(uint *)(iVar9 + 0x20) & 0x100000) != 0) {
            piVar12 = (int *)0x5;
            goto locret_F0019A08;
          }
          if ((*(uint *)(iVar9 + 0x1c) & 0x100000) != 0) {
            piVar12 = (int *)0x5;
            goto locret_F0019A08;
          }
          if (*(int *)(*piVar11 + 0x10) != 0) {
            if ((*(uint *)(iVar9 + 0x28) & 0x1000) == 0) goto loc_F00195D8;
            piVar12 = (int *)0x5;
            goto locret_F0019A08;
          }
loc_F00195D0:
          piVar12 = (int *)0x5;
locret_F0019A08:
          return CONCAT44(param_2,piVar12);
        }
      }
loc_F00195F4:
      _spltty();
      if ((uVar10 & 0x22) == 0) {
        piVar11 = param_1 + 3;
        if (0 < param_1[3]) goto loc_F0019870;
loc_F00197C8:
        uVar10 = param_1[0x10];
      }
      else {
        uVar7 = (uint)*(byte *)((int)piVar3 + 0x15);
        piVar11 = param_1;
        if (*(byte *)((int)piVar3 + 0x16) == 0) {
          if ((int)uVar7 <= *param_1) goto loc_F0019870;
          uVar10 = param_1[0x10];
        }
        else {
          iVar9 = (uint)*(byte *)((int)piVar3 + 0x16) * 100000;
          if (uVar7 == 0) {
            if (0 < *param_1) goto loc_F0019870;
            if (bVar1) {
              _getthetime((undefined *)((int)register0x00000038 + -0x18));
              iVar9 = iVar9 - ((*(int *)((int)register0x00000038 + -0x18) -
                               *(int *)((int)register0x00000038 + -0x10)) * 1000000 +
                              (*(int *)((int)register0x00000038 + -0x14) -
                              *(int *)((int)register0x00000038 + -0xc)));
            }
            else {
              bVar1 = true;
              _getthetime((undefined *)((int)register0x00000038 + -0x10));
            }
          }
          else {
            iVar6 = *param_1;
            if (iVar6 < 1) goto loc_F00197C8;
            if ((int)uVar7 <= iVar6) goto loc_F0019870;
            if (bVar1) {
              if (param_3 < iVar6) goto loc_F001968C;
              _getthetime((undefined *)((int)register0x00000038 + -0x18));
              iVar9 = iVar9 - ((*(int *)((int)register0x00000038 + -0x18) -
                               *(int *)((int)register0x00000038 + -0x10)) * 1000000 +
                              (*(int *)((int)register0x00000038 + -0x14) -
                              *(int *)((int)register0x00000038 + -0xc)));
            }
            else {
              bVar1 = true;
loc_F001968C:
              _getthetime((undefined *)((int)register0x00000038 + -0x10));
            }
            param_3 = *param_1;
          }
          if (iVar9 < 1) {
loc_F0019870:
            _splx(puVar5);
            bVar1 = true;
loc_F001987C:
            piVar8 = piVar11;
            _getc();
            uVar7 = (uint)piVar8 & 0xff;
            if ((int)piVar8 < 0) goto loc_F0019974;
            if (uVar7 != 0xff) {
              if (((uVar7 == *(byte *)((int)param_1 + 0x56)) && ((uVar10 & 0x20) == 0)) &&
                 ((piVar3[4] & 8U) != 0)) break;
              if (((uVar7 != 0xff) && (uVar7 == *(byte *)((int)param_1 + 0x53))) &&
                 ((uVar10 & 0x22) == 0)) {
                iVar9 = *param_1;
                goto loc_F0019978;
              }
            }
            piVar12 = piVar8;
            _ureadc(piVar8,param_2);
            if (piVar12 != (int *)0x0) {
              iVar9 = *param_1;
              goto loc_F0019978;
            }
            if (*(int *)(param_2 + 0x14) == 0) goto loc_F0019974;
            bVar1 = false;
            if ((uVar10 & 0x22) == 0) {
              if (piVar8 == (int *)0xa) {
                iVar9 = *param_1;
                goto loc_F0019978;
              }
              if (((piVar8 == (int *)(uint)*(byte *)((int)param_1 + 0x53)) ||
                  (piVar8 == (int *)(uint)*(byte *)(param_1 + 0x15))) &&
                 (bVar1 = false, piVar8 != (int *)0xff)) goto loc_F0019974;
            }
            goto loc_F001987C;
          }
          .umul(iVar9,_hz);
          iVar9 = iVar9 + 999999;
          .div(iVar9,1000000);
          _untimeout(_wakeup,param_1);
          _timeout(_wakeup,param_1,iVar9);
          uVar10 = param_1[0x10];
        }
      }
      if (((uVar10 & 0x10) != 0) || (bVar2 = false, (piVar3[4] & 0x8000U) != 0)) {
        bVar2 = true;
      }
      if (bVar2) {
        uVar10 = param_1[0x10];
      }
      else {
        if ((param_1[0x10] & 4U) != 0) {
          _splx(puVar5);
          piVar12 = (int *)0x0;
          goto locret_F0019A08;
        }
        uVar10 = param_1[0x10];
      }
      if ((uVar10 & 0x2000) != 0) {
        _splx(puVar5);
        uVar10 = *(uint *)(*_active_u + 0x14);
loc_F0019850:
        piVar12 = (int *)0x23;
        if ((uVar10 & 0x4000) != 0) {
          piVar12 = (int *)0xb;
        }
        goto locret_F0019A08;
      }
      _sleep(param_1,0x1c);
      _splx(puVar5);
      goto loc_F0019430;
    }
    puVar5 = (undefined *)_active_u[0x59];
    if (param_1 != (int *)puVar5) goto loc_F00195F4;
    piVar8 = (int *)(int)*(sword *)(iVar9 + 0x2e);
    puVar5 = (undefined *)(int)*(sword *)(param_1 + 0x11);
    if (piVar8 == (int *)puVar5) goto loc_F00195F4;
    if ((*(uint *)(iVar9 + 0x20) & 0x100000) != 0) {
      piVar12 = (int *)0x5;
      goto locret_F0019A08;
    }
    if ((*(uint *)(iVar9 + 0x1c) & 0x100000) != 0) {
      piVar12 = (int *)0x5;
      goto locret_F0019A08;
    }
    if ((*(uint *)(iVar9 + 0x28) & 0x1000) != 0) goto loc_F00195D0;
loc_F00195D8:
    _gsignal(piVar8,0x15);
    puVar5 = _lbolt;
    _sleep(_lbolt,0x1c);
  } while( true );
  _gsignal((int)*(sword *)(param_1 + 0x11),0x12);
  if (!bVar1) {
loc_F0019974:
    iVar9 = *param_1;
loc_F0019978:
    if (iVar9 < 0xcc) {
      _spltty();
      param_1[0x10] = param_1[0x10] & 0xff7fffff;
      _splx();
      if (((param_1[0x10] & 0x1000400U) == 0x400) && (*(char *)((int)param_1 + 0x51) != -1)) {
        iVar9 = (int)*(char *)((int)param_1 + 0x51);
        _putc(iVar9,param_1 + 6);
        if (iVar9 == 0) {
          _spltty();
          param_1[0x10] = param_1[0x10] & 0xfffffbff;
          _splx();
          _ttstart(param_1);
        }
      }
    }
    goto locret_F0019A08;
  }
  puVar5 = (undefined *)param_1;
  _sleep(param_1,0x1c);
  bVar1 = false;
  goto loc_F0019430;
}
/* GHIDRADEC_FUNCTION index=339 start=0xf0019a10 */

/* WARNING: Removing unreachable block (ram,0xf0019a80) */
/* WARNING: Removing unreachable block (ram,0xf0019a50) */
/* WARNING: Removing unreachable block (ram,0xf0019a64) */
/* WARNING: Removing unreachable block (ram,0xf0019a98) */
/* WARNING: Removing unreachable block (ram,0xf0019a28) */

undefined8 _ttycheckoutq(int param_1,int param_2)

{
  sword sVar1;
  int iVar2;
  int iVar3;
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
  iVar2 = (*(byte *)(param_1 + 0x4a) & 0x1f) * 2;
  sVar1 = *(sword *)(_tthiwat + iVar2);
  _spltty();
  iVar3 = *(int *)(param_1 + 0x18);
  if (sVar1 + 200 < iVar3) {
    while (sVar1 < iVar3) {
      _ttstart(param_1);
      if (param_2 == 0) {
        _splx(iVar2);
        uVar4 = 0;
        goto locret_F0019AA4;
      }
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
      _sleep(param_1 + 0x18,0x1d);
      iVar3 = *(int *)(param_1 + 0x18);
    }
  }
  _splx(iVar2);
  uVar4 = 1;
locret_F0019AA4:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=340 start=0xf0019aac */

/* WARNING: Removing unreachable block (ram,0xf0019c8c) */
/* WARNING: Removing unreachable block (ram,0xf0019d14) */
/* WARNING: Removing unreachable block (ram,0xf001a068) */
/* WARNING: Removing unreachable block (ram,0xf0019ff4) */
/* WARNING: Removing unreachable block (ram,0xf0019ec0) */
/* WARNING: Removing unreachable block (ram,0xf0019ea0) */
/* WARNING: Removing unreachable block (ram,0xf0019c00) */
/* WARNING: Removing unreachable block (ram,0xf0019e88) */
/* WARNING: Removing unreachable block (ram,0xf0019db8) */
/* WARNING: Removing unreachable block (ram,0xf0019d3c) */
/* WARNING: Removing unreachable block (ram,0xf0019b3c) */
/* WARNING: Removing unreachable block (ram,0xf0019b84) */
/* WARNING: Removing unreachable block (ram,0xf0019da4) */
/* WARNING: Removing unreachable block (ram,0xf0019dc4) */
/* WARNING: Removing unreachable block (ram,0xf0019f28) */
/* WARNING: Removing unreachable block (ram,0xf0019c10) */
/* WARNING: Removing unreachable block (ram,0xf0019eb4) */
/* WARNING: Removing unreachable block (ram,0xf0019fa8) */
/* WARNING: Removing unreachable block (ram,0xf001a01c) */
/* WARNING: Removing unreachable block (ram,0xf001a070) */
/* WARNING: Removing unreachable block (ram,0xf0019f98) */
/* WARNING: Removing unreachable block (ram,0xf0019c9c) */
/* WARNING: Removing unreachable block (ram,0xf0019ab0) */

undefined8 _ttwrite(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  byte *pbVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  byte *pbVar12;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
  bool bVar14;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  byte abStack_70 [112];
  
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
  _ttynty();
  pbVar12 = (byte *)0x0;
  bVar1 = *(byte *)(param_1 + 0x4a);
  *(int *)((int)register0x00000038 + -0x74) = param_2[5];
  iVar11 = (int)*(sword *)(_tthiwat + (bVar1 & 0x1f) * 2);
loc_F0019AE0:
  uVar7 = *(uint *)(param_1 + 0x40);
loc_F0019AE4:
  if ((uVar7 & 0x10) == 0) {
    uVar3 = *(uint *)(iVar2 + 0x10);
    while ((uVar3 & 0x8000) == 0) {
      if ((uVar7 & 0x8000) == 0) goto loc_F0019BF8;
      if ((uVar7 & 0x2000) != 0) {
        uVar7 = *(uint *)(*_active_u + 0x14);
        goto loc_F001A054;
      }
      _sleep(param_1,0x1c);
      uVar7 = *(uint *)(param_1 + 0x40);
      if ((uVar7 & 0x10) != 0) break;
      uVar3 = *(uint *)(iVar2 + 0x10);
    }
  }
  iVar9 = *_active_u;
  if ((*(uint *)(iVar9 + 0x14) & 0x4000) == 0) {
    iVar8 = (int)*(sword *)(iVar9 + 0x2e);
    if (iVar8 == *(sword *)(param_1 + 0x44)) {
      iVar9 = param_2[5];
    }
    else if (param_1 == _active_u[0x59]) {
      if ((*(uint *)(param_1 + 0x3c) & 0x400000) == 0) goto loc_F0019CAC;
      if ((*(uint *)(iVar9 + 0x28) & 0x1000) == 0) {
        if ((*(uint *)(iVar9 + 0x20) & 0x200000) == 0) {
          if ((*(uint *)(iVar9 + 0x1c) & 0x200000) == 0) goto loc_F0019C8C;
          iVar9 = param_2[5];
        }
        else {
          iVar9 = param_2[5];
        }
      }
      else {
        iVar9 = param_2[5];
      }
    }
    else {
      iVar9 = param_2[5];
    }
  }
  else {
    iVar4 = (int)*(sword *)(iVar9 + 0x30);
    _get_posix_proc();
    iVar8 = *(int *)(*(int *)(iVar4 + 0x10) + 0xc);
    if (iVar8 == *(sword *)(param_1 + 0x44)) {
loc_F0019CAC:
      iVar9 = param_2[5];
    }
    else if (param_1 == _active_u[0x59]) {
      if ((*(uint *)(param_1 + 0x3c) & 0x400000) == 0) goto loc_F0019CAC;
      if ((*(uint *)(iVar9 + 0x20) & 0x200000) == 0) {
        if ((*(uint *)(iVar9 + 0x1c) & 0x200000) == 0) {
          if (*(int *)(*(int *)(iVar4 + 0x10) + 0x10) == 0) {
loc_F0019BF8:
            pbVar12 = (byte *)0x5;
            goto locret_F001A080;
          }
loc_F0019C8C:
          _gsignal(iVar8,0x16);
          _sleep(_lbolt,0x1c);
          uVar7 = *(uint *)(param_1 + 0x40);
          goto loc_F0019AE4;
        }
        iVar9 = param_2[5];
      }
      else {
        iVar9 = param_2[5];
      }
    }
    else {
      iVar9 = param_2[5];
    }
  }
  if (0 < iVar9) {
    iVar9 = *param_2;
    do {
      iVar9 = *(int *)(iVar9 + 4);
      if (iVar9 == 0) {
        param_2[1] = param_2[1] + -1;
        *param_2 = *param_2 + 8;
        if (param_2[1] < 1) {
          _panic(&aTtwrite);
          iVar9 = param_2[5];
        }
        else {
loc_F0019F88:
          iVar9 = param_2[5];
        }
      }
      else {
        if (100 < iVar9) {
          iVar9 = 100;
        }
        pbVar10 = (byte *)((int)register0x00000038 + -0x70);
        pbVar12 = pbVar10;
        _uiomove(pbVar10,iVar9,1,param_2);
        if (pbVar12 != (byte *)0x0) break;
        uVar7 = *(uint *)(param_1 + 0x18);
        if (iVar11 < (int)uVar7) goto loc_F0019FA8;
        if ((*(uint *)(param_1 + 0x3c) & 0x800000) == 0) {
          if ((*(uint *)(param_1 + 0x3c) & 0x200024) == 4) {
            if ((*(uint *)(iVar2 + 0x10) & 0x10000000) != 0) {
              if (iVar9 < 1) {
                iVar9 = param_2[5];
              }
              else {
                bVar1 = *pbVar10;
                while( true ) {
                  iVar8 = (int)(char)bVar1;
                  pbVar10 = pbVar10 + 1;
                  *(undefined *)(param_1 + 0x4b) = 0;
                  _ttyoutput(iVar8,param_1);
                  if (-1 < iVar8) {
                    _ttstart(param_1);
                    _sleep(_lbolt,0x1d);
                    *(undefined *)(param_1 + 0x4b) = 0;
                    goto loc_F0019EC8;
                  }
                  uVar7 = *(uint *)(param_1 + 0x18);
                  iVar9 = iVar9 + -1;
                  if (iVar11 < (int)uVar7) goto loc_F0019FA8;
                  if (iVar9 < 1) break;
                  bVar1 = *pbVar10;
                }
                iVar9 = param_2[5];
              }
              goto loc_F0019F8C;
            }
            uVar7 = *(uint *)(param_1 + 0x3c);
          }
          else {
            uVar7 = *(uint *)(param_1 + 0x3c);
          }
          bVar14 = iVar9 == 0;
          bVar13 = iVar9 < 0;
          if ((uVar7 & 0x2200020) == 0) {
            bVar14 = iVar9 == 0;
            bVar13 = iVar9 < 0;
            if ((*(uint *)(iVar2 + 0x10) & 0x10000000) != 0) {
              bVar14 = iVar9 == 0;
              bVar13 = iVar9 < 0;
              if ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300) {
                iVar8 = iVar9 + -1;
                pbVar6 = pbVar10;
                if (iVar8 < 0) goto loc_F0019F7C;
                do {
                  iVar8 = iVar8 + -1;
                  *pbVar6 = *pbVar6 & 0x7f;
                  pbVar6 = pbVar6 + 1;
                } while (-1 < iVar8);
                bVar14 = iVar9 == 0;
                bVar13 = iVar9 < 0;
              }
            }
          }
loc_F0019F80:
          if (bVar14 || bVar13) goto loc_F0019F88;
          iVar8 = iVar9;
          if ((*(uint *)(param_1 + 0x3c) & 0x200020) == 0) {
            if ((*(uint *)(iVar2 + 0x10) & 0x10000000) == 0) {
              *(undefined *)(param_1 + 0x4b) = 0;
              goto loc_F0019F20;
            }
            iVar4 = iVar9;
            _scanc(iVar9,pbVar10,_partab,0x3f);
            *(undefined *)(param_1 + 0x4b) = 0;
            iVar8 = iVar9 - iVar4;
            if (iVar9 - iVar4 != 0) goto loc_F0019F20;
            iVar8 = (int)(char)*pbVar10;
            _ttyoutput(iVar8,param_1);
            if (-1 < iVar8) {
              _ttstart(param_1);
              _sleep(_lbolt,0x1d);
loc_F0019EC8:
              if (iVar9 == 0) {
                uVar7 = *(uint *)(param_1 + 0x40);
                goto loc_F0019AE4;
              }
              piVar5 = (int *)*param_2;
loc_F0019ED8:
              *piVar5 = *piVar5 - iVar9;
              *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar9;
              param_2[5] = param_2[5] + iVar9;
              param_2[2] = param_2[2] - iVar9;
              goto loc_F0019AE0;
            }
            pbVar10 = pbVar10 + 1;
            uVar7 = *(uint *)(param_1 + 0x3c);
            iVar9 = iVar9 + -1;
          }
          else {
            *(undefined *)(param_1 + 0x4b) = 0;
loc_F0019F20:
            pbVar6 = pbVar10;
            _b_to_q(pbVar10,iVar8,param_1 + 0x18);
            iVar8 = iVar8 - (int)pbVar6;
            pbVar10 = pbVar10 + iVar8;
            iVar9 = iVar9 - iVar8;
            *(char *)(param_1 + 0x48) = *(char *)(param_1 + 0x48) + (char)iVar8;
            _tk_nout = _tk_nout + iVar8;
            if (0 < (int)pbVar6) {
              _ttstart(param_1);
              _sleep(_lbolt,0x1d);
              piVar5 = (int *)*param_2;
              goto loc_F0019ED8;
            }
            uVar7 = *(uint *)(param_1 + 0x3c);
          }
          if (((uVar7 & 0x800000) != 0) || (uVar7 = *(uint *)(param_1 + 0x18), iVar11 < (int)uVar7))
          goto loc_F0019FA8;
loc_F0019F7C:
          bVar14 = iVar9 == 0;
          bVar13 = iVar9 < 0;
          goto loc_F0019F80;
        }
        iVar9 = param_2[5];
      }
loc_F0019F8C:
      if (iVar9 < 1) break;
      iVar9 = *param_2;
    } while( true );
  }
  _ttstart(param_1);
  goto locret_F001A080;
loc_F0019FA8:
  _spltty();
  if (iVar9 != 0) {
    *(int *)*param_2 = *(int *)*param_2 - iVar9;
    *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar9;
    param_2[5] = param_2[5] + iVar9;
    param_2[2] = param_2[2] - iVar9;
  }
  _ttstart(param_1);
  if (iVar11 < *(int *)(param_1 + 0x18)) {
    if ((*(uint *)(param_1 + 0x40) & 0x2000) != 0) {
      _splx(uVar7);
      pbVar12 = (byte *)0x0;
      if (param_2[5] == *(int *)((int)register0x00000038 + -0x74)) {
        uVar7 = *(uint *)(*_active_u + 0x14);
loc_F001A054:
        pbVar12 = (byte *)0x23;
        if ((uVar7 & 0x4000) != 0) {
          pbVar12 = (byte *)0xb;
        }
      }
locret_F001A080:
      return CONCAT44(param_2,pbVar12);
    }
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
    _sleep(param_1 + 0x18,0x1d);
  }
  _splx(uVar7);
  uVar7 = *(uint *)(param_1 + 0x40);
  goto loc_F0019AE4;
}
/* GHIDRADEC_FUNCTION index=341 start=0xf001a088 */

/* WARNING: Removing unreachable block (ram,0xf001a158) */
/* WARNING: Removing unreachable block (ram,0xf001a248) */
/* WARNING: Removing unreachable block (ram,0xf001a1d0) */
/* WARNING: Removing unreachable block (ram,0xf001a17c) */
/* WARNING: Removing unreachable block (ram,0xf001a2bc) */
/* WARNING: Removing unreachable block (ram,0xf001a268) */
/* WARNING: Removing unreachable block (ram,0xf001a188) */
/* WARNING: Removing unreachable block (ram,0xf001a214) */
/* WARNING: Removing unreachable block (ram,0xf001a1e4) */
/* WARNING: Removing unreachable block (ram,0xf001a130) */
/* WARNING: Removing unreachable block (ram,0xf001a29c) */

undefined8 _ttyrub(uint param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  piVar5 = (int *)*param_2;
  uVar4 = piVar5[0xf];
  if (((uVar4 & 8) == 0) || ((piVar5[0x10] & 0x400000U) != 0)) goto locret_F001A2D0;
  piVar5[0xf] = uVar4 & 0xff7fffff;
  if ((uVar4 & 0x10000) == 0) {
    if ((uVar4 & 0x20000) == 0) {
      uVar4 = (uint)*(byte *)((int)piVar5 + 0x4d);
    }
    else {
      uVar4 = param_1;
      if ((piVar5[0x10] & 0x40000U) == 0) {
        _ttyoutput(0x5c,piVar5);
        piVar5[0x10] = piVar5[0x10] | 0x40000;
      }
    }
    _ttyecho(uVar4,param_2);
    cVar3 = *(char *)((int)piVar5 + 0x4b);
    goto loc_F001A2C8;
  }
  uVar4 = param_1 - 0x109;
  if (*(char *)((int)piVar5 + 0x4b) == '\0') {
loc_F001A17C:
    _ttyretype(param_2);
    goto locret_F001A2D0;
  }
  param_1 = param_1 & 0xff;
  if (uVar4 < 2) {
loc_F001A154:
    _ttyrubo(piVar5,2);
    cVar3 = *(char *)((int)piVar5 + 0x4b);
  }
  else {
    switch(_partab[param_1] & 0x3f) {
    case :
      _ttyrubo(piVar5,1);
      cVar3 = *(char *)((int)piVar5 + 0x4b);
      break;
    case :
    case :
    case :
    case :
    case :
      if ((piVar5[0xf] & 0x10000000U) != 0) goto loc_F001A154;
      cVar3 = *(char *)((int)piVar5 + 0x4b);
      break;
    case :
      iVar1 = *piVar5;
      if (*(char *)((int)piVar5 + 0x4b) < iVar1) goto loc_F001A17C;
      _spltty();
      cVar3 = *(char *)(piVar5 + 0x12);
      piVar5[0x10] = piVar5[0x10] | 0x200000;
      piVar5[0xf] = piVar5[0xf] | 0x800000;
      *(undefined *)(piVar5 + 0x12) = *(undefined *)(piVar5 + 0x13);
      piVar6 = (int *)(piVar5[1] + -1);
      while( true ) {
        piVar2 = piVar5;
        _nextc3(piVar5,piVar6,(undefined *)((int)register0x00000038 + -0xc));
        if (piVar2 == (int *)0x0) break;
        _ttyecho(*(undefined4 *)((int)register0x00000038 + -0xc),param_2);
        piVar6 = piVar2;
      }
      piVar5[0xf] = piVar5[0xf] & 0xff7fffff;
      piVar5[0x10] = piVar5[0x10] & 0xffdfffff;
      _splx(iVar1);
      iVar1 = (int)cVar3 - (int)*(char *)(piVar5 + 0x12);
      *(char *)(piVar5 + 0x12) = *(char *)(piVar5 + 0x12) + (char)iVar1;
      if (8 < iVar1) {
        iVar1 = 8;
      }
      iVar1 = iVar1 + -1;
      param_1 = 0;
      if (iVar1 < 0) {
        cVar3 = *(char *)((int)piVar5 + 0x4b);
      }
      else {
        do {
          _ttyoutput(8,piVar5);
          iVar1 = iVar1 + -1;
        } while (-1 < iVar1);
        cVar3 = *(char *)((int)piVar5 + 0x4b);
      }
      break;
    :
      _panic(&aTtyrub);
      cVar3 = *(char *)((int)piVar5 + 0x4b);
    }
  }
loc_F001A2C8:
  *(char *)((int)piVar5 + 0x4b) = cVar3 + -1;
locret_F001A2D0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=342 start=0xf001a2d8 */

/* WARNING: Removing unreachable block (ram,0xf001a30c) */

undefined8 _ttyrubo(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 *puVar1;
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
  if ((*(uint *)(param_1 + 0x3c) & 0x40000) == 0) {
    puVar1 = (undefined4 *)&asc_F010B8B8;
  }
  else {
    puVar1 = &asc_F010B8B0;
  }
  while (param_2 = param_2 + -1, -1 < param_2) {
    _ttyoutstr(puVar1,param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=343 start=0xf001a328 */

/* WARNING: Removing unreachable block (ram,0xf001a3b8) */
/* WARNING: Removing unreachable block (ram,0xf001a3a4) */
/* WARNING: Removing unreachable block (ram,0xf001a354) */
/* WARNING: Removing unreachable block (ram,0xf001a34c) */
/* WARNING: Removing unreachable block (ram,0xf001a370) */
/* WARNING: Removing unreachable block (ram,0xf001a3d8) */
/* WARNING: Removing unreachable block (ram,0xf001a384) */
/* WARNING: Removing unreachable block (ram,0xf001a340) */

undefined8 _ttyretype(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  puVar4 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar4 + 0x57) != -1) {
    _ttyecho(*(char *)((int)puVar4 + 0x57),param_1);
  }
  uVar1 = 10;
  _ttyoutput(10,puVar4);
  _spltty();
  puVar3 = (undefined4 *)(puVar4[4] + -1);
  while( true ) {
    puVar2 = puVar4 + 3;
    _nextc3(puVar2,puVar3,(undefined *)((int)register0x00000038 + -0xc));
    if (puVar2 == (undefined4 *)0x0) break;
    _ttyecho(*(undefined4 *)((int)register0x00000038 + -0xc),param_1);
    puVar3 = puVar2;
  }
  puVar3 = (undefined4 *)(puVar4[1] + -1);
  while( true ) {
    puVar2 = puVar4;
    _nextc3(puVar4,puVar3,(undefined *)((int)register0x00000038 + -0xc));
    if (puVar2 == (undefined4 *)0x0) break;
    _ttyecho(*(undefined4 *)((int)register0x00000038 + -0xc),param_1);
    puVar3 = puVar2;
  }
  puVar4[0x10] = puVar4[0x10] & 0xfffbffff;
  _splx(uVar1);
  *(undefined *)(puVar4 + 0x13) = 0;
  *(char *)((int)puVar4 + 0x4b) = (char)*puVar4;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=344 start=0xf001a3f4 */

/* WARNING: Removing unreachable block (ram,0xf001a51c) */
/* WARNING: Removing unreachable block (ram,0xf001a490) */

undefined8 _ttyecho(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
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
  iVar3 = *param_2;
  if ((*(uint *)(iVar3 + 0x40) & 0x200000) == 0) {
    *(uint *)(iVar3 + 0x3c) = *(uint *)(iVar3 + 0x3c) & 0xff7fffff;
    uVar2 = *(uint *)(iVar3 + 0x3c);
  }
  else {
    uVar2 = *(uint *)(iVar3 + 0x3c);
  }
  if ((uVar2 & 8) == 0) {
    if (((param_2[4] & 2U) == 0) || (param_1 != 10)) goto locret_F001A524;
    uVar1 = *(uint *)(iVar3 + 0x40);
  }
  else {
    uVar1 = *(uint *)(iVar3 + 0x40);
  }
  if ((uVar1 & 0x400000) == 0) {
    if (((uVar2 & 0x10000000) != 0) &&
       ((((param_1 & 0xff) < 0x20 && (1 < param_1 - 9)) || ((param_1 & 0xff) == 0x7f)))) {
      _ttyoutput(0x5e,iVar3);
      param_1 = param_1 & 0xff;
      if (param_1 == 0x7f) {
        param_1 = 0x3f;
      }
      else if ((*(uint *)(iVar3 + 0x3c) & 4) == 0) {
        param_1 = param_1 + 0x40;
      }
      else {
        param_1 = param_1 + 0x60;
      }
    }
    param_1 = param_1 & 0xff;
    if (((0x1f < param_1) &&
        ((((*(uint *)(iVar3 + 0x3c) & 0x8000000) != 0 || ((param_2[4] & 0x400000U) != 0)) ||
         (param_1 < 0x7f)))) || ((param_1 - 7 < 4 || (param_1 == 0xd)))) {
      _ttyoutput(param_1,iVar3);
    }
  }
locret_F001A524:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=345 start=0xf001a52c */

/* WARNING: Removing unreachable block (ram,0xf001a53c) */

undefined8 _ttyoutstr(byte *param_1,undefined4 param_2)

{
  byte bVar1;
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
  bVar1 = *param_1;
  while( true ) {
    param_1 = param_1 + 1;
    if (bVar1 == 0) break;
    _ttyoutput((int)((uint)bVar1 * 0x1000000) >> 0x18,param_2);
    bVar1 = *param_1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=346 start=0xf001a560 */

undefined8 _ttcheckwakeup(undefined4 *param_1)

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
  uVar1 = 1;
  if (((((int *)*param_1)[0xf] & 0x22U) != 0) &&
     (*(int *)*param_1 < (int)(uint)*(byte *)((int)param_1 + 0x15))) {
    uVar1 = (uint)(*(char *)((int)param_1 + 0x16) != '\0');
  }
  return CONCAT44(param_1,uVar1);
}
/* GHIDRADEC_FUNCTION index=347 start=0xf001a5a4 */

/* WARNING: Removing unreachable block (ram,0xf001a604) */
/* WARNING: Removing unreachable block (ram,0xf001a5d0) */
/* WARNING: Removing unreachable block (ram,0xf001a5c8) */
/* WARNING: Removing unreachable block (ram,0xf001a5e4) */
/* WARNING: Removing unreachable block (ram,0xf001a60c) */
/* WARNING: Removing unreachable block (ram,0xf001a5a8) */

undefined8 _ttwakeup(int param_1,undefined4 param_2)

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
    _selthreadclear(param_1 + 0x28);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffff7ff;
  }
  _splx(iVar1);
  if ((*(uint *)(param_1 + 0x40) & 0x4000) != 0) {
    _gsignal((int)*(sword *)(param_1 + 0x44),0x17);
  }
  _wakeup(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=348 start=0xf001a61c */

/* WARNING: Removing unreachable block (ram,0xf001a74c) */
/* WARNING: Removing unreachable block (ram,0xf001a71c) */

undefined8
_tty_ld_install(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar1;
  undefined4 unaff_l3;
  undefined4 uVar2;
  undefined4 unaff_l4;
  undefined4 uVar3;
  undefined4 unaff_l5;
  undefined4 uVar4;
  undefined4 unaff_l6;
  undefined4 uVar5;
  undefined4 unaff_l7;
  undefined4 uVar6;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x60);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 100);
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x70);
  if (-1 < param_1) {
    if (_nldisp <= param_1) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    param_1 = param_1 * 0x30;
    uVar7 = 0xffffffff;
    if (*(code **)(_linesw + param_1) != _nodev) goto locret_F001A758;
    if (*(code **)(_linesw + param_1 + 4) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 8) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0xc) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x10) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x14) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x18) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x20) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x24) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x28) == _nodev) {
      _spltty();
      *(undefined4 *)(_linesw + param_1 + 0x2c) = param_2;
      *(undefined4 *)(_linesw + param_1) = param_3;
      *(undefined4 *)(_linesw + param_1 + 4) = param_4;
      *(undefined4 *)(_linesw + param_1 + 8) = param_5;
      *(undefined4 *)(_linesw + param_1 + 0xc) = param_6;
      *(undefined4 *)(_linesw + param_1 + 0x10) = uVar1;
      *(undefined4 *)(_linesw + param_1 + 0x14) = uVar2;
      *(undefined4 *)(_linesw + param_1 + 0x18) = uVar3;
      *(undefined4 *)(_linesw + param_1 + 0x20) = uVar4;
      *(undefined4 *)(_linesw + param_1 + 0x24) = uVar5;
      *(undefined4 *)(_linesw + param_1 + 0x28) = uVar6;
      _splx();
      uVar7 = 0;
      goto locret_F001A758;
    }
  }
  uVar7 = 0xffffffff;
locret_F001A758:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=349 start=0xf001a760 */

/* WARNING: Removing unreachable block (ram,0xf001a7cc) */
/* WARNING: Removing unreachable block (ram,0xf001a780) */

undefined8 _tty_ld_remove(int param_1,undefined4 param_2)

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
  if ((-1 < param_1) && (param_1 < _nldisp)) {
    _spltty();
    iVar1 = param_1 * 0x30;
    *(code **)(_linesw + iVar1) = _nodev;
    *(code **)(_linesw + iVar1 + 4) = _nodev;
    *(code **)(_linesw + iVar1 + 8) = _nodev;
    *(code **)(_linesw + iVar1 + 0xc) = _nodev;
    *(code **)(_linesw + iVar1 + 0x10) = _nodev;
    *(code **)(_linesw + iVar1 + 0x14) = _nodev;
    *(code **)(_linesw + iVar1 + 0x18) = _nodev;
    *(code **)(_linesw + iVar1 + 0x20) = _nodev;
    *(code **)(_linesw + iVar1 + 0x24) = _nodev;
    *(code **)(_linesw + iVar1 + 0x28) = _nodev;
    _splx();
  }
  return CONCAT44(param_2,param_1);
}

