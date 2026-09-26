
/* WARNING: Removing unreachable block (ram,0xf000b75c) */
/* WARNING: Removing unreachable block (ram,0xf000b728) */

undefined8 _flock(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uVar2;
  int iVar3;
  uint *puVar4;
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
  puVar4 = *(uint **)(dword_F0133DDC + 0x24);
  if (((*puVar4 < *(uint *)(_active_u + 0x158)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x14c) + *puVar4 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (*(sword *)(iVar3 + 0xc) != 1) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x2d;
      goto locret_F000B770;
    }
    uVar1 = puVar4[1];
    if ((uVar1 & 8) != 0) {
      _vno_bsd_unlock(iVar3,0x180);
      goto locret_F000B770;
    }
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 1) == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        goto locret_F000B770;
      }
      uVar1 = puVar4[1];
    }
    else {
      puVar4[1] = uVar1 & 0xfffffffe;
      uVar1 = puVar4[1];
    }
    _vno_bsd_lock(iVar3,uVar1);
    uVar2 = (undefined)iVar3;
  }
  else {
    uVar2 = 9;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F000B770:
  return CONCAT44(param_2,param_1);
}

