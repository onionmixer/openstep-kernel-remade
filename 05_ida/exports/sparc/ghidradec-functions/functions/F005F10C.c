
/* WARNING: Removing unreachable block (ram,0xf005f1a8) */
/* WARNING: Removing unreachable block (ram,0xf005f30c) */
/* WARNING: Removing unreachable block (ram,0xf005f298) */
/* WARNING: Removing unreachable block (ram,0xf005f238) */
/* WARNING: Removing unreachable block (ram,0xf005f5c4) */
/* WARNING: Removing unreachable block (ram,0xf005f624) */
/* WARNING: Removing unreachable block (ram,0xf005f504) */
/* WARNING: Removing unreachable block (ram,0xf005f560) */
/* WARNING: Removing unreachable block (ram,0xf005f4d0) */
/* WARNING: Removing unreachable block (ram,0xf005f3f4) */
/* WARNING: Removing unreachable block (ram,0xf005f4bc) */
/* WARNING: Removing unreachable block (ram,0xf005f548) */
/* WARNING: Removing unreachable block (ram,0xf005f584) */
/* WARNING: Removing unreachable block (ram,0xf005f60c) */
/* WARNING: Removing unreachable block (ram,0xf005f648) */
/* WARNING: Removing unreachable block (ram,0xf005f210) */
/* WARNING: Removing unreachable block (ram,0xf005f26c) */
/* WARNING: Removing unreachable block (ram,0xf005f2c8) */
/* WARNING: Removing unreachable block (ram,0xf005f2f4) */
/* WARNING: Removing unreachable block (ram,0xf005f1c4) */
/* WARNING: Removing unreachable block (ram,0xf005f168) */

undefined8
_mach_port_space_info
          (int param_1,uint *param_2,undefined4 param_3,undefined4 param_4,int *param_5,
          uint *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  uint uVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  uint uVar11;
  undefined4 unaff_l6;
  uint uVar12;
  undefined4 unaff_l7;
  uint uVar13;
  undefined4 unaff_i0;
  undefined4 uVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar15;
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
  *(uint **)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_4;
  uVar9 = 0;
  uVar13 = 0;
  if (param_1 == 0) {
loc_F005F12C:
    uVar14 = 0x10;
  }
  else {
    iVar15 = *param_5;
    uVar10 = *param_6;
    param_2 = (uint *)**(undefined4 **)((int)register0x00000038 + -0x24);
    uVar12 = **(uint **)((int)register0x00000038 + -0x2c);
loc_F005F158:
    do {
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar2 = (int *)(param_1 + 8);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      if (*(int *)(param_1 + 0xc) == 0) {
        piVar2 = *(int **)((int)register0x00000038 + -0x24);
        *(undefined4 *)(param_1 + 8) = 0;
        if (param_2 != (uint *)*piVar2) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
        }
        if (iVar15 == *param_5) goto loc_F005F12C;
        _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar13);
        uVar14 = 0x10;
        goto locret_F005F660;
      }
      uVar11 = *(uint *)(param_1 + 0x18);
      uVar8 = *(uint *)(param_1 + 0x38);
      if ((uVar11 <= uVar12) &&
         (puVar1 = *(undefined4 **)((int)register0x00000038 + -0x1c), uVar8 <= uVar10)) {
        *puVar1 = 0xff;
        puVar1[1] = *(undefined4 *)(param_1 + 0x18);
        puVar1[2] = **(undefined4 **)(param_1 + 0x1c);
        puVar1[3] = *(undefined4 *)(param_1 + 0x38);
        puVar1[4] = *(undefined4 *)(param_1 + 0x3c);
        puVar1[5] = *(undefined4 *)(param_1 + 0x40);
        uVar12 = *(uint *)(param_1 + 0x18);
        uVar10 = 0;
        puVar5 = *(uint **)(param_1 + 0x14);
        puVar4 = param_2;
        if (uVar12 != 0) {
          do {
            uVar6 = *puVar5;
            *puVar4 = uVar10 << 8 | uVar6 >> 0x18;
            puVar4[1] = uVar6 >> 0x17 & 1;
            puVar4[2] = uVar6 >> 0x16 & 1;
            puVar4[3] = uVar6 >> 0x15 & 1;
            puVar4[4] = uVar6 & 0x1f0000;
            puVar4[5] = uVar6 & 0xffff;
            puVar4[6] = puVar5[1];
            uVar10 = uVar10 + 1;
            puVar4[7] = puVar5[2];
            puVar4[8] = puVar5[3];
            puVar5 = puVar5 + 4;
            puVar4 = puVar4 + 9;
          } while (uVar10 < uVar12);
        }
        puVar4 = (uint *)(param_1 + 0x20);
        _ipc_splay_traverse_start();
        if (puVar4 != (uint *)0x0) {
          iVar7 = 0;
          uVar12 = *puVar4;
          iVar3 = iVar15;
          while( true ) {
            *(uint *)(iVar15 + iVar7) = puVar4[4];
            *(uint *)(iVar3 + 4) = uVar12 >> 0x17 & 1;
            *(uint *)(iVar3 + 8) = uVar12 >> 0x16 & 1;
            *(uint *)(iVar3 + 0xc) = uVar12 >> 0x15 & 1;
            *(uint *)(iVar3 + 0x10) = uVar12 & 0x1f0000;
            *(uint *)(iVar3 + 0x14) = uVar12 & 0xffff;
            *(uint *)(iVar3 + 0x18) = puVar4[1];
            *(uint *)(iVar3 + 0x1c) = puVar4[2];
            iVar7 = iVar7 + 0x2c;
            *(uint *)(iVar3 + 0x20) = puVar4[3];
            if (puVar4[6] == 0) {
              *(undefined4 *)(iVar3 + 0x24) = 0;
            }
            else {
              *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(puVar4[6] + 0x10);
            }
            if (puVar4[7] == 0) {
              *(undefined4 *)(iVar3 + 0x28) = 0;
            }
            else {
              *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(puVar4[7] + 0x10);
            }
            puVar4 = (uint *)(param_1 + 0x20);
            _ipc_splay_traverse_next(puVar4,0);
            if (puVar4 == (uint *)0x0) break;
            uVar12 = *puVar4;
            iVar3 = iVar3 + 0x2c;
          }
        }
        _ipc_splay_traverse_finish(param_1 + 0x20);
        piVar2 = *(int **)((int)register0x00000038 + -0x24);
        *(undefined4 *)(param_1 + 8) = 0;
        if (param_2 == (uint *)*piVar2) {
loc_F005F598:
          **(uint **)((int)register0x00000038 + -0x2c) = uVar11;
        }
        else {
          if (uVar11 != 0) {
            param_2 = (uint *)(uVar11 * 0x24);
            uVar12 = (int)param_2 + _page_mask & ~_page_mask;
            if (uVar12 != uVar9) {
              _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar12,
                         uVar9 - uVar12);
            }
            if ((int)param_2 - uVar12 != 0) {
              _bzero(*(int *)((int)register0x00000038 + -0xc) + (int)param_2,uVar12 + uVar11 * -0x24
                    );
            }
            _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,
                     uVar12,1,(undefined *)((int)register0x00000038 + -0x14));
            **(undefined4 **)((int)register0x00000038 + -0x24) =
                 *(undefined4 *)((int)register0x00000038 + -0x14);
            goto loc_F005F598;
          }
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
          **(undefined4 **)((int)register0x00000038 + -0x2c) = 0;
        }
        if (iVar15 == *param_5) {
loc_F005F658:
          *param_6 = uVar8;
        }
        else {
          if (uVar8 != 0) {
            param_2 = (uint *)(uVar8 * 0x2c);
            uVar9 = (int)param_2 + _page_mask & ~_page_mask;
            if (uVar9 != uVar13) {
              _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10) + uVar9,
                         uVar13 - uVar9);
            }
            if ((int)param_2 - uVar9 != 0) {
              _bzero(*(int *)((int)register0x00000038 + -0x10) + (int)param_2,uVar9 + uVar8 * -0x2c)
              ;
            }
            _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,
                     uVar9,1,(undefined *)((int)register0x00000038 + -0x18));
            *param_5 = *(int *)((int)register0x00000038 + -0x18);
            goto loc_F005F658;
          }
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar13);
          *param_6 = 0;
        }
        uVar14 = 0;
        goto locret_F005F660;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar12 < uVar11) {
        if (param_2 != (uint *)**(int **)((int)register0x00000038 + -0x24)) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
        }
        uVar9 = uVar11 * 0x24 + _page_mask & ~_page_mask;
        iVar3 = _ipc_kernel_map;
        _kmem_alloc(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar9);
        param_2 = *(uint **)((int)register0x00000038 + -0xc);
        if (iVar3 != 0) {
          if (iVar15 == *param_5) goto loc_F005F2FC;
          uVar14 = *(undefined4 *)((int)register0x00000038 + -0x10);
          uVar9 = uVar13;
          goto loc_F005F2F4;
        }
        uVar12 = uVar9;
        .udiv(uVar9,0x24);
      }
    } while (uVar8 <= uVar10);
    if (iVar15 != *param_5) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar13);
    }
    uVar13 = uVar8 * 0x2c + _page_mask & ~_page_mask;
    iVar15 = _ipc_kernel_map;
    _kmem_alloc(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar13);
    if (iVar15 == 0) {
      iVar15 = *(int *)((int)register0x00000038 + -0x10);
      uVar10 = uVar13;
      .udiv(uVar13,0x2c);
      goto loc_F005F158;
    }
    if (param_2 != (uint *)**(int **)((int)register0x00000038 + -0x24)) {
      uVar14 = *(undefined4 *)((int)register0x00000038 + -0xc);
loc_F005F2F4:
      _kmem_free(_ipc_kernel_map,uVar14,uVar9);
    }
loc_F005F2FC:
    uVar14 = 6;
  }
locret_F005F660:
  return CONCAT44(param_2,uVar14);
}
