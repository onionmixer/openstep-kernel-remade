
/* WARNING: Removing unreachable block (ram,0xf00102e0) */
/* WARNING: Removing unreachable block (ram,0xf00101f4) */
/* WARNING: Removing unreachable block (ram,0xf0010280) */
/* WARNING: Removing unreachable block (ram,0xf00101b4) */

undefined8 _setrlimit(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  int *piVar8;
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
  puVar7 = *(uint **)(dword_F0133DDC + 0x24);
  if (*puVar7 < 6) {
    uVar1 = puVar7[1];
    piVar8 = _active_u + *puVar7 * 2 + 0x98;
    _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0010310;
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if ((piVar8[1] < *(int *)((int)register0x00000038 + -0x10)) || (piVar8[1] < iVar2)) {
      _suser();
      if (iVar2 == 0) goto locret_F0010310;
      uVar1 = *puVar7;
    }
    else {
      uVar1 = *puVar7;
    }
    if (uVar1 == 3) {
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      if (*piVar8 < iVar2) {
        iVar6 = *piVar8;
        uVar1 = ~_page_mask;
        iVar3 = *(int *)(_active_threads + 0xc);
        *(uint *)((int)register0x00000038 + -0x14) = *(int *)(*_active_u + 0x84) - iVar2 & uVar1;
        iVar4 = *(int *)(iVar3 + 0xc);
        _vm_allocate(iVar4,(undefined *)((int)register0x00000038 + -0x14),
                     (iVar2 + _page_mask & uVar1) - (iVar6 + _page_mask & uVar1),0);
      }
      else {
        iVar3 = *piVar8;
        uVar1 = ~_page_mask;
        uVar5 = *(int *)(*_active_u + 0x84) - *piVar8 & uVar1;
        iVar4 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
        *(uint *)((int)register0x00000038 + -0x14) = uVar5;
        _vm_deallocate(iVar4,uVar5,(iVar3 + _page_mask & uVar1) - (iVar2 + _page_mask & uVar1));
      }
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      if (iVar4 != 0) goto loc_F00102F8;
    }
    else {
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
    }
    *piVar8 = iVar2;
    piVar8[1] = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F00102F8:
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
locret_F0010310:
  return CONCAT44(param_2,param_1);
}
