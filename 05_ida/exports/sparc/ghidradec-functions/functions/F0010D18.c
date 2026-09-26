
/* WARNING: Removing unreachable block (ram,0xf0010e7c) */
/* WARNING: Removing unreachable block (ram,0xf0010d4c) */
/* WARNING: Removing unreachable block (ram,0xf0010f44) */
/* WARNING: Removing unreachable block (ram,0xf0010d30) */

undefined8 _setsigvec(int *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  uint uVar6;
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
  iVar5 = *_active_u;
  uVar6 = 1 << ((char)param_1 - 1U & 0x1f);
  _splusclock();
  do {
    do {
    } while (*(int *)(iVar5 + 0x70) != 0);
    piVar2 = (int *)(iVar5 + 0x70);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  _active_u[(int)(param_1 + 3)] = *param_2;
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
    uVar1 = 0xfffafeff;
  }
  else {
    uVar1 = 0xfffefeff;
  }
  _active_u[(int)param_1 + 0x2d] = param_2[1] & uVar1;
  if ((param_2[2] & 2U) == 0) {
    uVar1 = _active_u[0x4f] & ~uVar6;
  }
  else {
    uVar1 = _active_u[0x4f] | uVar6;
  }
  _active_u[0x4f] = uVar1;
  if ((param_2[2] & 1U) == 0) {
    uVar1 = _active_u[0x4e] & ~uVar6;
  }
  else {
    uVar1 = _active_u[0x4e] | uVar6;
  }
  _active_u[0x4e] = uVar1;
  if (*param_2 == 1) {
loc_F0010E44:
    *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) & ~uVar6;
    if ((uVar6 & 0x1ef8) != 0) {
      piVar2 = *(int **)(iVar5 + 0x68);
      param_1 = piVar2 + 7;
      do {
        do {
        } while (*piVar2 != 0);
        piVar3 = piVar2;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      piVar2 = (int *)*param_1;
      if (param_1 != piVar2) {
        iVar4 = piVar2[0x21];
        while( true ) {
          *(uint *)(iVar4 + 0x4c) = *(uint *)(iVar4 + 0x4c) & ~uVar6;
          piVar2 = (int *)piVar2[4];
          if (param_1 == piVar2) break;
          iVar4 = piVar2[0x21];
        }
      }
      **(undefined4 **)(iVar5 + 0x68) = 0;
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | uVar6;
    *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) & ~uVar6;
  }
  else {
    if ((*(uint *)(iVar5 + 0x14) & 0x4000) == 0) {
      uVar1 = *(uint *)(iVar5 + 0x20);
    }
    else if (*param_2 == 0) {
      if (param_1 == (int *)0x14) goto loc_F0010E44;
      uVar1 = *(uint *)(iVar5 + 0x20);
    }
    else {
      uVar1 = *(uint *)(iVar5 + 0x20);
    }
    *(uint *)(iVar5 + 0x20) = uVar1 & ~uVar6;
    if (*param_2 == 0) {
      if ((*(uint *)(iVar5 + 0x14) & 0x4000) == 0) {
        uVar1 = *(uint *)(iVar5 + 0x24);
      }
      else {
        _active_u[(int)(param_1 + 3)] = 0;
        uVar1 = *(uint *)(iVar5 + 0x24);
      }
      uVar6 = uVar1 & ~uVar6;
    }
    else {
      uVar6 = *(uint *)(iVar5 + 0x24) | uVar6;
    }
    *(uint *)(iVar5 + 0x24) = uVar6;
  }
  *(undefined4 *)(iVar5 + 0x70) = 0;
  _spl0();
  return CONCAT44(param_2,param_1);
}
