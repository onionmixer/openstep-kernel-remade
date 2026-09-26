
/* WARNING: Removing unreachable block (ram,0xf0041294) */
/* WARNING: Removing unreachable block (ram,0xf0041228) */
/* WARNING: Removing unreachable block (ram,0xf0041220) */
/* WARNING: Removing unreachable block (ram,0xf004119c) */
/* WARNING: Removing unreachable block (ram,0xf0041130) */
/* WARNING: Removing unreachable block (ram,0xf00410e8) */
/* WARNING: Removing unreachable block (ram,0xf00410a4) */
/* WARNING: Removing unreachable block (ram,0xf004102c) */
/* WARNING: Removing unreachable block (ram,0xf0040fe0) */
/* WARNING: Removing unreachable block (ram,0xf0040fac) */
/* WARNING: Removing unreachable block (ram,0xf0040f54) */
/* WARNING: Removing unreachable block (ram,0xf0040ee0) */
/* WARNING: Removing unreachable block (ram,0xf0040f4c) */
/* WARNING: Removing unreachable block (ram,0xf0040f74) */
/* WARNING: Removing unreachable block (ram,0xf0040fcc) */
/* WARNING: Removing unreachable block (ram,0xf0040ff0) */
/* WARNING: Removing unreachable block (ram,0xf004104c) */
/* WARNING: Removing unreachable block (ram,0xf00410c4) */
/* WARNING: Removing unreachable block (ram,0xf0041148) */
/* WARNING: Removing unreachable block (ram,0xf004117c) */
/* WARNING: Removing unreachable block (ram,0xf00411f8) */
/* WARNING: Removing unreachable block (ram,0xf0041210) */
/* WARNING: Removing unreachable block (ram,0xf0041248) */
/* WARNING: Removing unreachable block (ram,0xf00412b4) */
/* WARNING: Removing unreachable block (ram,0xf0040eb4) */

undefined8 sub_F0040E94(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l0;
  int *piVar7;
  sword *psVar8;
  undefined4 unaff_l1;
  uint uVar9;
  int iVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar14;
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
  iVar14 = 0;
  piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
  do {
    do {
    } while (*piVar7 != 0);
    piVar1 = piVar7;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100000;
  *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
  iVar10 = param_1[0xc];
  _rlock(iVar10);
  uVar5 = _page_size;
  psVar8 = *(sword **)(*param_1 + 0x30);
  uVar12 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24) & 0xfffffc00;
  if (psVar8 == (sword *)0x0) {
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) == 0) {
      psVar8 = *(sword **)(iVar10 + 0x70);
      if (psVar8 == (sword *)0x0) {
        _printf(aNfsFailureOnPa);
        _runlock(iVar10);
        piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
        do {
          do {
          } while (*piVar7 != 0);
          piVar1 = piVar7;
          _simple_lock_try();
          uVar13 = 2;
        } while (piVar1 == (int *)0x0);
        uVar5 = *(uint *)(param_2 + 0x20);
        goto loc_F00412D0;
      }
    }
    else {
      psVar8 = (sword *)_active_u[7];
    }
  }
  *psVar8 = *psVar8 + 1;
  if (*(int *)(iVar10 + 0x70) == 0) {
    *(sword **)(iVar10 + 0x70) = psVar8;
  }
  else {
    _crfree();
    *(sword **)(iVar10 + 0x70) = psVar8;
  }
  if (*(uint *)(iVar10 + 0x98) < param_3 + uVar5) {
    _vm_page_zero_fill(param_2);
  }
  while( true ) {
    uVar2 = param_3;
    .udiv(param_3,uVar12);
    uVar3 = param_3;
    .urem(param_3,uVar12);
    uVar9 = uVar5;
    if (uVar12 - uVar3 < uVar5) {
      uVar9 = uVar12 - uVar3;
    }
    uVar4 = *(uint *)(iVar10 + 0x98) - param_3;
    if (*(uint *)(iVar10 + 0x98) <= param_3) break;
    if (uVar4 < uVar9) {
      uVar9 = uVar4;
    }
    (**(code **)(param_1[7] + 0x50))
              (param_1,uVar2,(undefined *)((int)register0x00000038 + -0xc),
               (undefined *)((int)register0x00000038 + -0x10));
    if (*(int *)((int)register0x00000038 + -0x10) < 0) {
      _runlock(iVar10);
      piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      uVar5 = *(uint *)(param_2 + 0x20);
      uVar13 = 1;
      goto loc_F0041264;
    }
    _nfs_validate_caches
              (*(undefined4 *)((int)register0x00000038 + -0xc),*(undefined4 *)(iVar10 + 0x70),0);
    iVar11 = 0;
    if (*(int *)(iVar10 + 100) + 1U == uVar2) {
      (**(code **)(param_1[7] + 0x50))
                (param_1,*(int *)(iVar10 + 100) + 2,0,(undefined *)((int)register0x00000038 + -0x14)
                );
      puVar6 = *(uint **)((int)register0x00000038 + -0xc);
      _breada(puVar6,*(undefined4 *)((int)register0x00000038 + -0x10),uVar12,
              *(undefined4 *)((int)register0x00000038 + -0x14),uVar12);
    }
    else {
      puVar6 = *(uint **)((int)register0x00000038 + -0xc);
      _bread(puVar6,*(undefined4 *)((int)register0x00000038 + -0x10),uVar12);
    }
    *(uint *)(iVar10 + 100) = uVar2;
    if ((*puVar6 & 4) == 0) {
      _copy_to_phys(puVar6[8] + uVar3,*(int *)(param_2 + 0x24) + iVar14,uVar9);
      if ((*puVar6 & 0xfffffffc) == 0) {
        *puVar6 = *puVar6 | 0x400000;
      }
    }
    else {
      iVar11 = (int)*(sword *)(puVar6 + 7);
    }
    _brelse(puVar6);
    if (iVar11 != 0) {
      *(int *)(*param_1 + 0x34) = iVar11;
      if (*(sword *)(*param_1 + 4) == 0) {
        if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
          _printf(aSD_1,_active_u + 2,(int)*(sword *)(*_active_u + 0x30));
        }
        if (iVar11 == 0x46) {
          _printf(aNfsReadErrorOn);
        }
        else {
          _printf(aNfsReadErrorDO,iVar11);
        }
      }
      _runlock(iVar10);
      piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      uVar5 = *(uint *)(param_2 + 0x20);
      uVar13 = 2;
      goto loc_F0041264;
    }
    uVar5 = uVar5 - uVar9;
    iVar14 = iVar14 + uVar9;
    param_3 = param_3 + uVar9;
    if (((int)uVar5 < 1) || (uVar9 == 0)) goto loc_F0041294;
  }
  if (iVar14 == 0) {
    _runlock(iVar10);
    piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
    do {
      do {
      } while (*piVar7 != 0);
      piVar1 = piVar7;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    uVar5 = *(uint *)(param_2 + 0x20);
    uVar13 = 1;
loc_F0041264:
    *(uint *)(param_2 + 0x20) = uVar5 & 0xffefffff;
    *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
    goto locret_F00412E4;
  }
loc_F0041294:
  _runlock(iVar10);
  piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
  do {
    do {
    } while (*piVar7 != 0);
    piVar1 = piVar7;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar13 = 0;
  uVar5 = *(uint *)(param_2 + 0x20);
loc_F00412D0:
  *(uint *)(param_2 + 0x20) = uVar5 & 0xffefffff;
  *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
locret_F00412E4:
  return CONCAT44(param_2,uVar13);
}
