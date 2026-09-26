
/* WARNING: Removing unreachable block (ram,0xf005b424) */
/* WARNING: Removing unreachable block (ram,0xf005b4f0) */
/* WARNING: Removing unreachable block (ram,0xf005b464) */
/* WARNING: Removing unreachable block (ram,0xf005b3d4) */
/* WARNING: Removing unreachable block (ram,0xf005b400) */
/* WARNING: Removing unreachable block (ram,0xf005b494) */
/* WARNING: Removing unreachable block (ram,0xf005b414) */
/* WARNING: Removing unreachable block (ram,0xf005b3ec) */
/* WARNING: Removing unreachable block (ram,0xf005b3b0) */

undefined8 _ipc_port_alloc_compat(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar10;
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
  piVar2 = _ipc_object_zones;
  _zalloc();
  puVar1 = _ipc_table_dnrequests;
  if (piVar2 == (int *)0x0) {
    uVar10 = 6;
  }
  else {
    puVar3 = (uint *)(*_ipc_table_dnrequests << 3);
    _ipc_table_alloc();
    if (puVar3 == (uint *)0x0) {
      _zfree(_ipc_object_zones,piVar2);
      uVar10 = 6;
    }
    else {
      uVar10 = param_1;
      _ipc_entry_alloc(param_1,(undefined *)((int)register0x00000038 + -0xc),
                       (undefined *)((int)register0x00000038 + -0x10));
      if (uVar10 == 0) {
        puVar6 = *(uint **)((int)register0x00000038 + -0x10);
        puVar6[2] = 1;
        puVar6[1] = (uint)piVar2;
        *puVar6 = *puVar6 | 0x420000;
        *piVar2 = 0;
        do {
          do {
          } while (*piVar2 != 0);
          piVar4 = piVar2;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        *(undefined4 *)(param_1 + 8) = 0;
        piVar2[1] = 1;
        piVar2[2] = -0x80000000;
        _ipc_port_init(piVar2,param_1,*(undefined4 *)((int)register0x00000038 + -0xc));
        uVar9 = *puVar1;
        uVar10 = 0;
        if (2 < uVar9) {
          iVar5 = 0x10;
          uVar7 = 2;
          uVar8 = uVar10;
          do {
            uVar10 = uVar7;
            *(undefined4 *)((int)puVar3 + iVar5 + 4) = 0;
            *(uint *)((int)puVar3 + iVar5) = uVar8;
            uVar7 = uVar10 + 1;
            iVar5 = uVar7 * 8;
            uVar8 = uVar10;
          } while (uVar7 < uVar9);
        }
        *puVar3 = uVar10;
        puVar3[1] = (uint)puVar1;
        piVar2[0xb] = (int)puVar3;
        puVar3[2] = param_1 | 1;
        puVar3[3] = *(uint *)((int)register0x00000038 + -0xc);
        _ipc_space_reference(param_1);
        uVar10 = 0;
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        *param_3 = piVar2;
      }
      else {
        _zfree(_ipc_object_zones,piVar2);
        _ipc_table_free(*puVar1 << 3,puVar3);
      }
    }
  }
  return CONCAT44(param_2,uVar10);
}

