
/* WARNING: Removing unreachable block (ram,0xf0057c1c) */
/* WARNING: Removing unreachable block (ram,0xf0057c54) */
/* WARNING: Removing unreachable block (ram,0xf0057bbc) */
/* WARNING: Removing unreachable block (ram,0xf0057b48) */
/* WARNING: Removing unreachable block (ram,0xf0057adc) */
/* WARNING: Removing unreachable block (ram,0xf00579dc) */
/* WARNING: Removing unreachable block (ram,0xf0057960) */
/* WARNING: Removing unreachable block (ram,0xf00579a4) */
/* WARNING: Removing unreachable block (ram,0xf00579f0) */
/* WARNING: Removing unreachable block (ram,0xf0057b24) */
/* WARNING: Removing unreachable block (ram,0xf0057ba4) */
/* WARNING: Removing unreachable block (ram,0xf0057c40) */
/* WARNING: Removing unreachable block (ram,0xf0057c10) */
/* WARNING: Removing unreachable block (ram,0xf0057b38) */
/* WARNING: Removing unreachable block (ram,0xf0057930) */

sqword _ipc_kmsg_copyout_compat(int param_1,uint *param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  uint uVar7;
  undefined4 unaff_l1;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar13;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar14;
  undefined4 unaff_i1;
  uint *puVar15;
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
  uVar10 = *(uint *)(param_1 + 0x14);
  piVar6 = *(int **)(param_1 + 0x1c);
  iVar8 = *(int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar6 != 0);
    piVar2 = piVar6;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (piVar6[2] < 0) {
    _ipc_object_copyout_dest
              (param_2,piVar6,uVar10 & 0xff,(undefined *)((int)register0x00000038 + -0x24));
  }
  else {
    iVar3 = piVar6[1];
    piVar6[1] = iVar3 + -1;
    *piVar6 = 0;
    if (iVar3 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(piVar6[2] & 0x7fffffffU) >> 0x10],piVar6);
      *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    }
  }
  if ((iVar8 != 0) && (iVar8 != -1)) {
    uVar7 = (uVar10 & 0xff00) >> 8;
    puVar15 = param_2;
    _ipc_object_copyout_compat(param_2,iVar8,uVar7,(undefined *)((int)register0x00000038 + -0x28));
    if (puVar15 == (uint *)0x0) goto loc_F00579FC;
    _ipc_object_destroy(iVar8,uVar7);
  }
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
loc_F00579FC:
  *(uint *)((int)register0x00000038 + -0x20) = (uint)*(byte *)((int)register0x00000038 + -0x1d);
  *(byte *)((int)register0x00000038 + -0x1d) = (byte)(uVar10 >> 0x1f) ^ 1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x14) =
       *(undefined4 *)((int)register0x00000038 + -0x24);
  *(undefined4 *)((int)register0x00000038 + -0x10) =
       *(undefined4 *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((int)register0x00000038 + -0x20);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x14);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xc);
  puVar11 = (uint *)(param_1 + 0x2c);
  puVar15 = param_2;
  if ((*(char *)((int)register0x00000038 + -0x1d) == '\0') &&
     (puVar15 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14), puVar11 < puVar15)) {
    uVar10 = *puVar11;
    do {
      uVar7 = uVar10 >> 2 & 1;
      uVar14 = uVar10 >> 3 & 1;
      if (uVar7 == 0) {
        uVar13 = (uint)*(byte *)puVar11;
        uVar5 = uVar10 >> 0x10 & 0xff;
        uVar10 = uVar10 >> 4 & 0xfff;
        puVar12 = puVar11 + 1;
      }
      else {
        uVar13 = (uint)*(word *)(puVar11 + 1);
        uVar5 = (uint)*(word *)((int)puVar11 + 6);
        uVar10 = puVar11[2];
        puVar12 = puVar11 + 3;
      }
      uVar9 = uVar10;
      .umul(uVar10,uVar5);
      bVar1 = 5 < uVar13 - 0x10;
      uVar5 = uVar9 + 7 >> 3;
      if (bVar1) {
loc_F0057BDC:
        if (uVar14 == 0) {
          uVar10 = *puVar12;
          if (uVar5 == 0) {
loc_F0057C68:
            *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
            goto loc_F0057C6C;
          }
          if (bVar1) {
            iVar8 = _ipc_soft_map;
            _vm_move(_ipc_soft_map,uVar10,param_3,uVar5,0,
                     (undefined *)((int)register0x00000038 + -0x2c));
            _vm_deallocate(_ipc_soft_map,uVar10,uVar5);
            uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
            if (iVar8 != 0) goto loc_F0057C68;
          }
          else {
            _copyoutmap(param_3,uVar10,*(undefined4 *)((int)register0x00000038 + -0x2c),uVar5);
            _kfree(uVar10,uVar5);
            uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
          }
          goto loc_F0057C70;
        }
        puVar11 = (uint *)((int)puVar12 + (uVar5 + 3 & 0xfffffffc));
      }
      else {
        if (((uVar14 != 0) || (uVar5 == 0)) ||
           (iVar8 = param_3,
           _vm_allocate(param_3,(undefined *)((int)register0x00000038 + -0x2c),uVar5,1), iVar8 == 0)
           ) {
          uVar9 = uVar13;
          _ipc_object_copyout_type_compat();
          if (uVar7 == 0) {
            *(byte *)puVar11 = (byte)uVar9;
          }
          else {
            *(sword *)(puVar11 + 1) = (sword)uVar9;
          }
          puVar11 = puVar12;
          if (uVar14 == 0) {
            puVar11 = (uint *)*puVar12;
          }
          uVar7 = 0;
          if (uVar10 != 0) {
            do {
              uVar9 = *puVar11;
              if ((uVar9 == 0) || (uVar9 == 0xffffffff)) {
loc_F0057BC4:
                *puVar11 = 0;
              }
              else {
                puVar4 = param_2;
                _ipc_object_copyout_compat(param_2,uVar9,uVar13,puVar11);
                if (puVar4 != (uint *)0x0) {
                  _ipc_object_destroy(uVar9,uVar13);
                  goto loc_F0057BC4;
                }
              }
              uVar7 = uVar7 + 1;
              puVar11 = puVar11 + 1;
            } while (uVar7 < uVar10);
          }
          goto loc_F0057BDC;
        }
        _ipc_kmsg_clean_body(puVar11,puVar12);
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
loc_F0057C6C:
        uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
loc_F0057C70:
        *puVar12 = uVar10;
        puVar11 = puVar12 + 1;
      }
      if (puVar15 <= puVar11) break;
      uVar10 = *puVar11;
    } while( true );
  }
  return ZEXT48(puVar15) << 0x20;
}
