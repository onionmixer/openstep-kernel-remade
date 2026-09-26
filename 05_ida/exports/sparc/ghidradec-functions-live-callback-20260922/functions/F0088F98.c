
/* WARNING: Removing unreachable block (ram,0xf0088fe4) */
/* WARNING: Removing unreachable block (ram,0xf008903c) */
/* WARNING: Removing unreachable block (ram,0xf0088fc8) */

undefined8 _vm_page_lookup(int param_1,uint param_2)

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
  iVar1 = (param_1 + (param_2 >> ((byte)_page_shift & 0x1f)) & _vm_page_hash_mask) * 8;
  piVar4 = (int *)(_vm_page_buckets + iVar1);
  _spltty();
  do {
    do {
    } while (*piVar4 != 0);
    piVar2 = piVar4;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  iVar5 = piVar4[1];
  if (iVar5 == 0) {
loc_F0089038:
    *piVar4 = 0;
    _splx(iVar1);
    return CONCAT44(param_2,iVar5);
  }
  iVar3 = *(int *)(iVar5 + 0x14);
  do {
    if (iVar3 == param_1) {
      if (*(uint *)(iVar5 + 0x18) == param_2) goto loc_F0089038;
      iVar5 = *(int *)(iVar5 + 0x10);
    }
    else {
      iVar5 = *(int *)(iVar5 + 0x10);
    }
    if (iVar5 == 0) goto loc_F0089038;
    iVar3 = *(int *)(iVar5 + 0x14);
  } while( true );
}

