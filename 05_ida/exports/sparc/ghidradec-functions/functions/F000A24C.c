
/* WARNING: Removing unreachable block (ram,0xf000a72c) */
/* WARNING: Removing unreachable block (ram,0xf000a6b8) */
/* WARNING: Removing unreachable block (ram,0xf000a5f8) */
/* WARNING: Removing unreachable block (ram,0xf000a564) */
/* WARNING: Removing unreachable block (ram,0xf000a4b4) */
/* WARNING: Removing unreachable block (ram,0xf000a440) */
/* WARNING: Removing unreachable block (ram,0xf000a3a4) */
/* WARNING: Removing unreachable block (ram,0xf000a348) */
/* WARNING: Removing unreachable block (ram,0xf000a2ec) */
/* WARNING: Removing unreachable block (ram,0xf000a2d8) */
/* WARNING: Removing unreachable block (ram,0xf000a31c) */
/* WARNING: Removing unreachable block (ram,0xf000a370) */
/* WARNING: Removing unreachable block (ram,0xf000a3e0) */
/* WARNING: Removing unreachable block (ram,0xf000a454) */
/* WARNING: Removing unreachable block (ram,0xf000a4d4) */
/* WARNING: Removing unreachable block (ram,0xf000a5c8) */
/* WARNING: Removing unreachable block (ram,0xf000a634) */
/* WARNING: Removing unreachable block (ram,0xf000a714) */
/* WARNING: Removing unreachable block (ram,0xf000a734) */
/* WARNING: Removing unreachable block (ram,0xf000a2d0) */

undefined8 _core(undefined4 param_1,int param_2)

{
  sword sVar1;
  undefined uVar4;
  int iVar2;
  int *piVar3;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 unaff_l0;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  undefined4 unaff_l1;
  undefined *puVar11;
  int iVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar13;
  undefined4 unaff_l5;
  int *piVar14;
  undefined4 unaff_l6;
  int iVar15;
  undefined4 unaff_l7;
  int iVar16;
  undefined4 unaff_i0;
  uint uVar17;
  uint uVar18;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar19;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  int aiStack_b8 [46];
  
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
  if ((*(uint *)(*_active_u + 0x28) & 0x2000000) == 0) {
    *(undefined2 *)(_active_u[7] + 2) = *(undefined2 *)(_active_u[7] + 6);
    *(undefined2 *)(*_active_u + 0x2c) = *(undefined2 *)(_active_u[7] + 6);
    *(undefined2 *)(_active_u[7] + 4) = *(undefined2 *)(_active_u[7] + 8);
    *(undefined *)(_active_u + 0x97) = 0;
    piVar14 = *(int **)(_active_threads + 0xc);
    iVar16 = piVar14[3];
    uVar17 = 0;
    if ((uint)_active_u[0xa0] <= *(uint *)(iVar16 + 0x28)) goto locret_F000A750;
    _task_halt(piVar14);
    _pcb_synch(_active_threads);
    puVar11 = (undefined *)((int)register0x00000038 + -0x48);
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    _vattr_null(puVar11);
    *(undefined4 *)((int)register0x00000038 + -0x48) = 1;
    *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1a4;
    puVar8 = (undefined *)((int)register0x00000038 + -0x68);
    _sprintf(puVar8,aCoresCoreD,(int)*(sword *)(*_active_u + 0x30));
    _vn_create(puVar8,1,puVar11,0,0x80,(undefined *)((int)register0x00000038 + -0xbc),_active_u[7]);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar8;
    sVar1 = *(sword *)((int)register0x00000038 + -0x34);
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      _vattr_null(puVar11);
      *(undefined4 *)((int)register0x00000038 + -0x48) = 1;
      *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1a4;
      uVar4 = 0x18;
      _vn_create(&aCore,1,puVar11,0,0x80,(undefined *)((int)register0x00000038 + -0xbc),_active_u[7]
                );
      *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
      sVar1 = *(sword *)((int)register0x00000038 + -0x34);
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F000A3C8;
    }
    iVar9 = 0xe;
    if (sVar1 == 1) {
      _vattr_null((undefined *)((int)register0x00000038 + -0x48));
      *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
      (**(code **)(*(int *)(*(int *)((int)register0x00000038 + -0xbc) + 0x1c) + 0x18))
                (*(int *)((int)register0x00000038 + -0xbc),
                 (undefined *)((int)register0x00000038 + -0x48),_active_u[7]);
      *(undefined4 *)((int)register0x00000038 + -0xc0) = 0x14;
      puVar8 = (undefined *)((int)register0x00000038 + -0xb8);
      *(word *)(_active_u + 0x90) = *(word *)(_active_u + 0x90) | 8;
      iVar13 = piVar14[9];
      iVar9 = *(int *)(iVar16 + 0x1c);
      iVar15 = _active_threads;
      _thread_getstatus(_active_threads,0,puVar8,(undefined *)((int)register0x00000038 + -0xc0));
      if (iVar15 != 0) {
        _panic(aCoreFlavorList);
      }
      iVar15 = 0;
      uVar18 = 0;
      uVar17 = *(uint *)((int)register0x00000038 + -0xc0) >> 1;
      *(uint *)((int)register0x00000038 + -0xc0) = uVar17;
      if (uVar17 != 0) {
        do {
          uVar18 = uVar18 + 1;
          iVar15 = iVar15 + 8 + *(int *)(puVar8 + 4) * 4;
          puVar8 = puVar8 + 8;
        } while (uVar18 < uVar17);
      }
      iVar10 = iVar15;
      .umul(iVar15,iVar13);
      iVar10 = (iVar13 + iVar9 * 7) * 8 + iVar10;
      iVar19 = iVar10 + 0x1c;
      iVar12 = 0x1c;
      _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc4),iVar19);
      *(undefined4 *)((int)register0x00000038 + -200) = 0;
      puVar5 = *(undefined4 **)((int)register0x00000038 + -0xc4);
      *puVar5 = 0xfeedface;
      uVar17 = _page_mask;
      puVar5[1] = dword_F0134764;
      uVar17 = iVar19 + uVar17 & ~uVar17;
      puVar5[2] = dword_F0134768;
      puVar5[3] = 4;
      puVar5[4] = iVar9 + iVar13;
      puVar5[5] = iVar10;
      for (; 0 < iVar9; iVar9 = iVar9 + -1) {
        iVar10 = iVar16;
        _vm_region(iVar16,(undefined *)((int)register0x00000038 + -200),
                   (undefined *)((int)register0x00000038 + -0xcc),
                   (undefined *)((int)register0x00000038 + -0xd0),
                   (undefined *)((int)register0x00000038 + -0xd4),
                   (undefined *)((int)register0x00000038 + -0xd8),
                   (undefined *)((int)register0x00000038 + -0xdc),
                   (undefined *)((int)register0x00000038 + -0xe0),
                   (undefined *)((int)register0x00000038 + -0xe4));
        iVar2 = *(int *)((int)register0x00000038 + -0xc4);
        if (iVar10 == 3) break;
        uVar7 = *(undefined4 *)((int)register0x00000038 + -200);
        uVar6 = *(undefined4 *)((int)register0x00000038 + -0xcc);
        uVar18 = *(uint *)((int)register0x00000038 + -0xd0);
        *(undefined4 *)(iVar2 + iVar12) = 1;
        iVar2 = iVar2 + iVar12;
        *(undefined4 *)(iVar2 + 4) = 0x38;
        *(undefined4 *)(iVar2 + 0x18) = uVar7;
        *(undefined4 *)(iVar2 + 0x1c) = uVar6;
        *(uint *)(iVar2 + 0x20) = uVar17;
        *(undefined4 *)(iVar2 + 0x24) = uVar6;
        *(uint *)(iVar2 + 0x2c) = uVar18;
        *(undefined4 *)(iVar2 + 0x30) = 0;
        *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xd4);
        if ((uVar18 & 1) == 0) {
          _vm_protect(iVar16,uVar7,uVar6,0,uVar18 | 1);
        }
        if ((*(uint *)((int)register0x00000038 + -0xd4) & 1) != 0) {
          _vn_rdwr(1,*(undefined4 *)((int)register0x00000038 + -0xbc),
                   *(undefined4 *)((int)register0x00000038 + -200),
                   *(undefined4 *)((int)register0x00000038 + -0xcc),uVar17,0,1,0);
        }
        iVar12 = iVar12 + 0x38;
        uVar17 = uVar17 + *(int *)((int)register0x00000038 + -0xcc);
        *(int *)((int)register0x00000038 + -200) =
             *(int *)((int)register0x00000038 + -200) + *(int *)((int)register0x00000038 + -0xcc);
      }
      do {
        do {
        } while (*piVar14 != 0);
        piVar3 = piVar14;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      iVar16 = piVar14[7];
      if (0 < iVar13) {
        param_2 = iVar15 + 8;
        do {
          iVar9 = *(int *)((int)register0x00000038 + -0xc4);
          uVar17 = 0;
          *(undefined4 *)(iVar9 + iVar12) = 4;
          *(int *)(iVar9 + iVar12 + 4) = param_2;
          iVar12 = iVar12 + 8;
          puVar5 = (undefined4 *)((int)register0x00000038 + -0xb8);
          puVar8 = (undefined *)((int)register0x00000038 + -8);
          if (*(int *)((int)register0x00000038 + -0xc0) != 0) {
            do {
              iVar9 = *(int *)((int)register0x00000038 + -0xc4);
              uVar17 = uVar17 + 1;
              *(undefined4 *)(iVar9 + iVar12) = *(undefined4 *)(puVar8 + -0xb0);
              *(undefined4 *)(iVar9 + iVar12 + 4) = *(undefined4 *)(puVar8 + -0xac);
              _thread_getstatus(iVar16,*puVar5,iVar9 + iVar12 + 8,puVar5 + 1);
              iVar12 = iVar12 + 8 + puVar5[1] * 4;
              puVar5 = puVar5 + 2;
              puVar8 = puVar8 + 8;
            } while (uVar17 < *(uint *)((int)register0x00000038 + -0xc0));
          }
          iVar13 = iVar13 + -1;
          iVar16 = *(int *)(iVar16 + 0x10);
        } while (0 < iVar13);
      }
      *piVar14 = 0;
      iVar9 = 1;
      _vn_rdwr(1,*(undefined4 *)((int)register0x00000038 + -0xbc),
               *(undefined4 *)((int)register0x00000038 + -0xc4),iVar19,0,1,1,0);
      _kmem_free(_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc4),iVar19);
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xbc));
    uVar17 = (uint)(iVar9 == 0);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar9;
  }
  else {
loc_F000A3C8:
    uVar17 = 0;
  }
locret_F000A750:
  return CONCAT44(param_2,uVar17);
}

