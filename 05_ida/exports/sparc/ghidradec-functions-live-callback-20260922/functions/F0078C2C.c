
/* WARNING: Removing unreachable block (ram,0xf00790a4) */
/* WARNING: Removing unreachable block (ram,0xf0079014) */
/* WARNING: Removing unreachable block (ram,0xf0078ffc) */
/* WARNING: Removing unreachable block (ram,0xf0078f7c) */
/* WARNING: Removing unreachable block (ram,0xf0078f3c) */
/* WARNING: Removing unreachable block (ram,0xf0078f24) */
/* WARNING: Removing unreachable block (ram,0xf0078f00) */
/* WARNING: Removing unreachable block (ram,0xf0078e7c) */
/* WARNING: Removing unreachable block (ram,0xf0078ea0) */
/* WARNING: Removing unreachable block (ram,0xf0078e2c) */
/* WARNING: Removing unreachable block (ram,0xf0078d7c) */
/* WARNING: Removing unreachable block (ram,0xf0078d64) */
/* WARNING: Removing unreachable block (ram,0xf0078d30) */
/* WARNING: Removing unreachable block (ram,0xf0078d14) */
/* WARNING: Removing unreachable block (ram,0xf0078c58) */
/* WARNING: Removing unreachable block (ram,0xf0078c68) */
/* WARNING: Removing unreachable block (ram,0xf0078c84) */
/* WARNING: Removing unreachable block (ram,0xf0078d20) */
/* WARNING: Removing unreachable block (ram,0xf0078d3c) */
/* WARNING: Removing unreachable block (ram,0xf0078d5c) */
/* WARNING: Removing unreachable block (ram,0xf007907c) */
/* WARNING: Removing unreachable block (ram,0xf0078d98) */
/* WARNING: Removing unreachable block (ram,0xf0078e60) */
/* WARNING: Removing unreachable block (ram,0xf0078eac) */
/* WARNING: Removing unreachable block (ram,0xf0078ee0) */
/* WARNING: Removing unreachable block (ram,0xf0078f14) */
/* WARNING: Removing unreachable block (ram,0xf0078e8c) */
/* WARNING: Removing unreachable block (ram,0xf0078f58) */
/* WARNING: Removing unreachable block (ram,0xf0078fc4) */
/* WARNING: Removing unreachable block (ram,0xf0078fec) */
/* WARNING: Removing unreachable block (ram,0xf0079030) */
/* WARNING: Removing unreachable block (ram,0xf00790b8) */
/* WARNING: Removing unreachable block (ram,0xf0078c40) */

undefined8 sub_F0078C2C(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_1 == (int *)0x0) {
    _panic(aZallocNullZone);
    iVar1 = iRam0000002c;
  }
  else {
    iVar1 = param_1[0xb];
  }
  if (iVar1 < 0) {
    _lock_write(param_1 + 0xc);
    piVar3 = (int *)param_1[4];
  }
  else {
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar3 = param_1;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_1[1] = iVar1;
    piVar3 = (int *)param_1[4];
  }
  *(int **)((int)register0x00000038 + -0xc) = piVar3;
  if (piVar3 != (int *)0x0) {
    param_1[2] = param_1[2] + 1;
    param_1[4] = *piVar3;
    if ((int *)param_1[3] == piVar3) {
      param_1[3] = 0;
    }
  }
  if (*(int *)((int)register0x00000038 + -0xc) == 0) {
    iVar1 = param_1[9];
loc_F0078CE8:
    if (iVar1 != 0) {
      if (param_2 == 0) {
        if ((param_1[0xb] & 0x80000000U) == 0) {
          *param_1 = 0;
          uVar4 = 0;
          _splx(param_1[1]);
        }
        else {
          _lock_done(param_1 + 0xc);
          uVar4 = 0;
        }
        goto locret_F00790C4;
      }
      _assert_wait(param_1 + 9,1);
      if ((param_1[0xb] & 0x80000000U) == 0) {
        *param_1 = 0;
        _splx(param_1[1]);
      }
      else {
        _lock_done(param_1 + 0xc);
      }
      _thread_block_with_continuation(0);
      uVar2 = param_1[0xb];
      if ((uVar2 & 0x80000000) == 0) {
        _splusclock();
        do {
          do {
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        param_1[1] = uVar2;
      }
      else {
        _lock_write(param_1 + 0xc);
      }
loc_F0079084:
      if (*(int *)((int)register0x00000038 + -0xc) == 0) goto loc_f007908c;
      goto loc_F0079094;
    }
    if ((param_1[0xb] & 0x80000000U) == 0) {
      if ((uint)param_1[6] < (uint)(param_1[5] + param_1[7])) {
        uVar2 = param_1[0xb];
        goto loc_F0078DFC;
      }
      uVar2 = param_1[0xb];
    }
    else if ((uint)param_1[6] < (uint)(param_1[5] + param_1[8])) {
      uVar2 = param_1[0xb];
loc_F0078DFC:
      if ((uVar2 & 0x20000000) != 0) goto loc_F0079094;
      if ((uVar2 & 0x10000000) == 0) {
        if (_zone_ignore_overflow != 0) {
          uVar2 = param_1[0xb];
          goto loc_F0078EB8;
        }
        if ((uVar2 & 0x80000000) == 0) {
          *param_1 = 0;
          _splx(param_1[1]);
        }
        else {
          _lock_done(param_1 + 0xc);
        }
        if (param_2 == 0) {
          uVar4 = 0;
          goto locret_F00790C4;
        }
        _printf(aZoneSEmpty,param_1[10]);
        _panic(&aZalloc);
      }
      else {
        param_1[6] = param_1[6] + ((uint)param_1[6] >> 1);
      }
      uVar2 = param_1[0xb];
    }
    else {
      uVar2 = param_1[0xb];
    }
loc_F0078EB8:
    if ((uVar2 & 0x80000000) != 0) {
      param_1[9] = 1;
    }
    if ((param_1[0xb] & 0x80000000U) == 0) {
      *param_1 = 0;
      _splx(param_1[1]);
      uVar2 = param_1[0xb];
    }
    else {
      _lock_done(param_1 + 0xc);
      uVar2 = param_1[0xb];
    }
    if ((uVar2 & 0x80000000) != 0) {
      iVar1 = _zone_map;
      _kmem_alloc_pageable(_zone_map,(undefined *)((int)register0x00000038 + -0xc),param_1[8]);
      if (iVar1 != 0) {
        _panic(&aZalloc_0);
      }
      _zcram(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),param_1[8]);
      uVar2 = param_1[0xb];
      if ((uVar2 & 0x80000000) == 0) {
        _splusclock();
        do {
          do {
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        param_1[1] = uVar2;
        param_1[9] = 0;
      }
      else {
        _lock_write(param_1 + 0xc);
        param_1[9] = 0;
      }
      _thread_wakeup_prim(param_1 + 9,0,0);
      piVar3 = (int *)param_1[4];
      *(int **)((int)register0x00000038 + -0xc) = piVar3;
      if (piVar3 != (int *)0x0) {
        param_1[2] = param_1[2] + 1;
        param_1[4] = *piVar3;
        if ((int *)param_1[3] == piVar3) {
          param_1[3] = 0;
        }
      }
      goto loc_F0079084;
    }
    iVar1 = param_1[0xf];
    _zget_space(iVar1,param_1[7],param_2);
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    if (iVar1 == 0) {
      if (param_2 == 0) {
        uVar4 = 0;
        goto locret_F00790C4;
      }
      _panic(&aZalloc_1);
    }
    uVar2 = param_1[0xb];
    if ((uVar2 & 0x80000000) == 0) {
      _splusclock();
      do {
        do {
        } while (*param_1 != 0);
        piVar3 = param_1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[1] = uVar2;
      iVar1 = param_1[2];
    }
    else {
      _lock_write(param_1 + 0xc);
      iVar1 = param_1[2];
    }
    param_1[2] = iVar1 + 1;
    param_1[5] = param_1[5] + param_1[7];
    if ((param_1[0xb] & 0x80000000U) != 0) goto loc_F00790A4;
    iVar1 = param_1[1];
    goto loc_F00790B4;
  }
  iVar1 = param_1[0xb];
loc_F0079098:
  if (iVar1 < 0) {
loc_F00790A4:
    _lock_done(param_1 + 0xc);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
    iVar1 = param_1[1];
loc_F00790B4:
    *param_1 = 0;
    _splx(iVar1);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
locret_F00790C4:
  return CONCAT44(param_2,uVar4);
loc_f007908c:
  iVar1 = param_1[9];
  goto loc_F0078CE8;
loc_F0079094:
  iVar1 = param_1[0xb];
  goto loc_F0079098;
}

