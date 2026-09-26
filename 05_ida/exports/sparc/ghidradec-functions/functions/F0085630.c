
/* WARNING: Removing unreachable block (ram,0xf0085a30) */
/* WARNING: Removing unreachable block (ram,0xf0085a38) */
/* WARNING: Removing unreachable block (ram,0xf00859cc) */
/* WARNING: Removing unreachable block (ram,0xf00859dc) */
/* WARNING: Removing unreachable block (ram,0xf00859ec) */
/* WARNING: Removing unreachable block (ram,0xf00859f0) */
/* WARNING: Removing unreachable block (ram,0xf0085998) */
/* WARNING: Removing unreachable block (ram,0xf0085950) */
/* WARNING: Removing unreachable block (ram,0xf0085930) */
/* WARNING: Removing unreachable block (ram,0xf0085964) */
/* WARNING: Removing unreachable block (ram,0xf00858b0) */
/* WARNING: Removing unreachable block (ram,0xf0085850) */
/* WARNING: Removing unreachable block (ram,0xf0085808) */
/* WARNING: Removing unreachable block (ram,0xf00857b8) */
/* WARNING: Removing unreachable block (ram,0xf0085788) */
/* WARNING: Removing unreachable block (ram,0xf008571c) */
/* WARNING: Removing unreachable block (ram,0xf00856f8) */
/* WARNING: Removing unreachable block (ram,0xf0085690) */
/* WARNING: Removing unreachable block (ram,0xf008567c) */
/* WARNING: Removing unreachable block (ram,0xf00856bc) */
/* WARNING: Removing unreachable block (ram,0xf0085748) */
/* WARNING: Removing unreachable block (ram,0xf0085768) */
/* WARNING: Removing unreachable block (ram,0xf0085798) */
/* WARNING: Removing unreachable block (ram,0xf00857d0) */
/* WARNING: Removing unreachable block (ram,0xf0085824) */
/* WARNING: Removing unreachable block (ram,0xf008587c) */
/* WARNING: Removing unreachable block (ram,0xf00858e8) */
/* WARNING: Removing unreachable block (ram,0xf0085914) */
/* WARNING: Removing unreachable block (ram,0xf0085948) */
/* WARNING: Removing unreachable block (ram,0xf0085984) */
/* WARNING: Removing unreachable block (ram,0xf00859ac) */
/* WARNING: Removing unreachable block (ram,0xf00856a8) */
/* WARNING: Removing unreachable block (ram,0xf0085a60) */
/* WARNING: Removing unreachable block (ram,0xf0085a74) */
/* WARNING: Removing unreachable block (ram,0xf0085a58) */

undefined8 _vm_map_copy(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar9;
  undefined4 unaff_l7;
  uint uVar10;
  undefined4 unaff_i0;
  undefined4 uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar12;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  *(int *)((int)register0x00000038 + -0x14) = param_4;
  uVar10 = param_3 + param_4;
  uVar9 = param_5 + param_4;
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)((int)register0x00000038 + 0x5c)
  ;
  if ((uVar10 < param_3) || (uVar9 < param_5)) {
    uVar11 = 3;
    goto locret_F0085A80;
  }
  if (param_2 == param_1) {
loc_F0085690:
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  }
  else {
    if (param_2 < param_1) {
      _lock_write(param_2);
      *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
      goto loc_F0085690;
    }
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    _lock_write(param_2);
    *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
  }
  iVar2 = *(int *)(param_2 + 0x2c);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  if ((iVar2 == 0) || (*(int *)(param_1 + 0x2c) == 0)) goto loc_F0085760;
  iVar2 = param_2;
  _vm_map_check_protection(param_2,param_5,uVar9,1);
  if (iVar2 == 0) {
loc_F0085730:
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 2;
  }
  else if (param_6 == 0) {
    iVar2 = param_1;
    _vm_map_check_protection(param_1,param_3,uVar10,2);
    if (iVar2 == 0) goto loc_F0085730;
loc_F0085760:
    puVar5 = (undefined *)((int)register0x00000038 + -0xc);
    _vm_map_lookup_entry(param_2,param_5,puVar5);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (*(uint *)(iVar2 + 8) < param_5) {
      __vm_map_clip_start(param_2 + 0xc,iVar2,param_5);
    }
    _vm_map_lookup_entry(param_1,param_3,puVar5);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    if (*(uint *)(iVar1 + 8) < param_3) {
      __vm_map_clip_start(param_1 + 0xc,iVar1,param_3);
    }
    bVar13 = false;
    if (iVar2 == iVar1) {
      _vm_map_lookup_entry(param_2,param_5,puVar5);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      bVar13 = iVar2 == iVar1;
    }
    if (!bVar13) {
      if (param_5 < uVar9) {
        uVar3 = *(uint *)(iVar2 + 0xc);
        do {
          if (uVar9 < uVar3) {
            __vm_map_clip_end(param_2 + 0xc,iVar2,uVar9);
          }
          if (uVar10 < *(uint *)(iVar1 + 0xc)) {
            __vm_map_clip_end(param_1 + 0xc,iVar1,uVar10);
          }
          if ((uint)(*(int *)(iVar2 + 8) + (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8))) <
              *(uint *)(iVar2 + 0xc)) {
            __vm_map_clip_end(param_2 + 0xc,iVar2);
          }
          if ((uint)(*(int *)(iVar1 + 8) + (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8))) <
              *(uint *)(iVar1 + 0xc)) {
            __vm_map_clip_end(param_1 + 0xc,iVar1);
          }
          if ((*(uint *)(iVar2 + 0x18) & 0x80000000) == 0) {
            if ((*(uint *)(iVar1 + 0x18) & 0x80000000) != 0) {
              iVar4 = *(int *)(iVar1 + 0xc);
              goto loc_F00858C0;
            }
            _vm_map_copy_entry(param_2,param_1,iVar2,iVar1);
            uVar3 = *(uint *)(iVar2 + 0xc);
          }
          else {
            iVar4 = *(int *)(iVar1 + 0xc);
loc_F00858C0:
            iVar4 = iVar4 - *(int *)(iVar1 + 8);
            if ((*(uint *)(iVar2 + 0x18) & 0x80000000) == 0) {
              uVar11 = *(undefined4 *)(iVar2 + 8);
              _lock_set_recursive(param_2);
              iVar8 = param_2;
            }
            else {
              uVar11 = *(undefined4 *)(iVar2 + 0x14);
              iVar8 = *(int *)(iVar2 + 0x10);
            }
            if ((*(uint *)(iVar1 + 0x18) & 0x80000000) == 0) {
              iVar6 = *(int *)(iVar1 + 8);
              _lock_set_recursive(param_1);
              iVar12 = param_1;
            }
            else {
              iVar12 = *(int *)(iVar1 + 0x10);
              iVar6 = *(int *)(iVar1 + 0x14);
              iVar7 = iVar6 + iVar4;
              if (iVar12 != iVar8) {
                _lock_write(iVar12);
                *(int *)(iVar12 + 0x4c) = *(int *)(iVar12 + 0x4c) + 1;
                _vm_map_delete(iVar12,iVar6,iVar7);
                _vm_map_insert(iVar12,0,0,iVar6,iVar7);
                _lock_done(iVar12);
              }
            }
            _vm_map_copy(iVar12,iVar8,iVar6,iVar4,uVar11,0,0);
            if (param_1 == iVar12) {
              _lock_clear_recursive(param_1);
            }
            if (param_2 == iVar8) {
              _lock_clear_recursive(param_2);
              uVar3 = *(uint *)(iVar2 + 0xc);
            }
            else {
              uVar3 = *(uint *)(iVar2 + 0xc);
            }
          }
          iVar1 = *(int *)(iVar1 + 4);
          iVar2 = *(int *)(iVar2 + 4);
          if (uVar9 <= uVar3) goto loc_f0085a04;
          uVar3 = *(uint *)(iVar2 + 0xc);
        } while( true );
      }
      iVar2 = *(int *)(param_2 + 0x2c);
      goto loc_F0085A08;
    }
  }
  else {
    iVar2 = param_1;
    _vm_map_insert(param_1,0,0,param_3,uVar10);
    *(int *)((int)register0x00000038 + -0x1c) = iVar2;
    if (iVar2 == 0) goto loc_F0085760;
  }
loc_F0085A40:
  iVar1 = *(int *)((int)register0x00000038 + -0x24);
loc_F0085A44:
  if (iVar1 != 0) {
    _vm_map_delete(param_2,param_5,param_5 + *(int *)((int)register0x00000038 + -0x14));
  }
  _lock_done(param_2);
  if (param_2 == param_1) {
    uVar11 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  }
  else {
    _lock_done(param_1);
    uVar11 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  }
locret_F0085A80:
  return CONCAT44(param_2,uVar11);
loc_f0085a04:
  iVar2 = *(int *)(param_2 + 0x2c);
loc_F0085A08:
  iVar1 = *(int *)((int)register0x00000038 + -0x24);
  if (iVar2 != 0) goto loc_F0085A40;
  goto loc_F0085A44;
}
