
/* WARNING: Removing unreachable block (ram,0xf0086034) */
/* WARNING: Removing unreachable block (ram,0xf0085fe4) */
/* WARNING: Removing unreachable block (ram,0xf0085f94) */
/* WARNING: Removing unreachable block (ram,0xf0085f58) */
/* WARNING: Removing unreachable block (ram,0xf0085f24) */
/* WARNING: Removing unreachable block (ram,0xf0085f00) */
/* WARNING: Removing unreachable block (ram,0xf0085e84) */
/* WARNING: Removing unreachable block (ram,0xf0085e00) */
/* WARNING: Removing unreachable block (ram,0xf0085e54) */
/* WARNING: Removing unreachable block (ram,0xf0085ea4) */
/* WARNING: Removing unreachable block (ram,0xf0085f10) */
/* WARNING: Removing unreachable block (ram,0xf0085f2c) */
/* WARNING: Removing unreachable block (ram,0xf0085f7c) */
/* WARNING: Removing unreachable block (ram,0xf0085fb4) */
/* WARNING: Removing unreachable block (ram,0xf0085ff4) */
/* WARNING: Removing unreachable block (ram,0xf0085fd0) */
/* WARNING: Removing unreachable block (ram,0xf0085de4) */

undefined8
_vm_map_lookup(int *param_1,uint param_2,uint param_3,int *param_4,undefined4 *param_5,int *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint *puVar9;
  undefined4 unaff_l7;
  uint *puVar10;
  undefined4 unaff_i0;
  undefined4 uVar11;
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
  puVar10 = *(uint **)((int)register0x00000038 + 0x5c);
  puVar9 = *(uint **)((int)register0x00000038 + 0x60);
  iVar3 = *param_1;
loc_F0085DE4:
  do {
    _lock_read(iVar3);
    do {
      do {
      } while (*(int *)(iVar3 + 0x3c) != 0);
      piVar1 = (int *)(iVar3 + 0x3c);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar5 = *(int *)(iVar3 + 0x38);
    *(undefined4 *)(iVar3 + 0x3c) = 0;
    *param_4 = iVar5;
    if (((iVar5 == iVar3 + 0xc) || (param_2 < *(uint *)(iVar5 + 8))) ||
       (*(uint *)(iVar5 + 0xc) <= param_2)) {
      iVar6 = iVar3;
      _vm_map_lookup_entry(iVar3,param_2,(undefined *)((int)register0x00000038 + -0xc));
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar6 != 0) {
        *param_4 = iVar5;
        uVar4 = *(uint *)(iVar5 + 0x18);
        goto loc_F0085E70;
      }
loc_F0085F2C:
      _lock_done(iVar3);
      uVar11 = 1;
      goto locret_F008606C;
    }
    uVar4 = *(uint *)(iVar5 + 0x18);
loc_F0085E70:
    if ((uVar4 & 0x20000000) == 0) {
      uVar4 = *(uint *)(iVar5 + 0x1c);
      if ((param_3 & uVar4) != param_3) {
        _lock_done(iVar3);
        uVar11 = 2;
        goto locret_F008606C;
      }
      uVar7 = (uint)(*(sword *)(iVar5 + 0x28) != 0);
      *puVar9 = uVar7;
      if (uVar7 != 0) {
        uVar4 = *(uint *)(iVar5 + 0x1c);
        param_3 = uVar4;
      }
      uVar7 = *(uint *)(iVar5 + 0x18) >> 0x1f ^ 1;
      iVar6 = iVar3;
      uVar8 = param_2;
      if (uVar7 == 0) {
        iVar6 = *(int *)(iVar5 + 0x10);
        uVar8 = (param_2 - *(int *)(iVar5 + 8)) + *(int *)(iVar5 + 0x14);
        _lock_read(iVar6);
        iVar2 = iVar6;
        _vm_map_lookup_entry(iVar6,uVar8,(undefined *)((int)register0x00000038 + -0x10));
        iVar5 = *(int *)((int)register0x00000038 + -0x10);
        if (iVar2 == 0) {
          _lock_done(iVar6);
          goto loc_F0085F2C;
        }
      }
      if ((*(uint *)(iVar5 + 0x18) & 0x2000000) == 0) {
loc_F0085FA4:
        iVar2 = *(int *)(iVar5 + 0x10);
loc_F0085FA8:
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar5 + 8);
          goto loc_F0086000;
        }
        iVar2 = iVar6;
        _lock_read_to_write();
        if (iVar2 == 0) {
          iVar3 = *(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8);
          _vm_object_allocate();
          *(int *)(iVar5 + 0x10) = iVar3;
          *(undefined4 *)(iVar5 + 0x14) = 0;
          _lock_write_to_read(iVar6);
          iVar3 = *(int *)(iVar5 + 8);
loc_F0086000:
          *param_6 = (uVar8 - iVar3) + *(int *)(iVar5 + 0x14);
          *param_5 = *(undefined4 *)(iVar5 + 0x10);
          if (uVar7 == 0) {
            do {
              do {
              } while (*(int *)(iVar6 + 0x34) != 0);
              piVar1 = (int *)(iVar6 + 0x34);
              _simple_lock_try();
            } while (piVar1 == (int *)0x0);
            *(undefined4 *)(iVar6 + 0x34) = 0;
            uVar7 = (uint)(*(int *)(iVar6 + 0x30) == 1);
          }
          *puVar10 = uVar4;
          uVar11 = 0;
          **(uint **)((int)register0x00000038 + 100) = uVar7;
locret_F008606C:
          return CONCAT44(param_2,uVar11);
        }
      }
      else {
        if ((param_3 & 2) == 0) {
          uVar4 = uVar4 & 0xfffffffd;
          goto loc_F0085FA4;
        }
        iVar2 = iVar6;
        _lock_read_to_write();
        if (iVar2 == 0) {
          _vm_object_shadow(iVar5 + 0x10,iVar5 + 0x14,*(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8));
          *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) & 0xfdffffff;
          _lock_write_to_read(iVar6);
          iVar2 = *(int *)(iVar5 + 0x10);
          goto loc_F0085FA8;
        }
      }
      if (iVar6 != iVar3) {
        _lock_done(iVar3);
      }
      goto loc_F0085DE4;
    }
    iVar5 = *(int *)(iVar5 + 0x10);
    *param_1 = iVar5;
    _lock_done(iVar3);
    iVar3 = iVar5;
  } while( true );
}

