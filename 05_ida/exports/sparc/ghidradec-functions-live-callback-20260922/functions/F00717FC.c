
/* WARNING: Removing unreachable block (ram,0xf0071930) */
/* WARNING: Removing unreachable block (ram,0xf0071840) */
/* WARNING: Removing unreachable block (ram,0xf0071908) */
/* WARNING: Removing unreachable block (ram,0xf0071914) */
/* WARNING: Removing unreachable block (ram,0xf0071814) */

undefined8 _thread_dispatch(int param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar1 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0x34) != 0) {
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
    _stack_free(param_1);
  }
  uVar2 = *(uint *)(param_1 + 0x4c) & 0xfffffcff;
  if (uVar2 == 0xc) {
loc_F0071914:
    _thread_setrun(param_1,0);
  }
  else {
    if ((int)uVar2 < 0xd) {
      if (uVar2 != 5) {
        if ((int)uVar2 < 6) {
          if (uVar2 == 4) goto loc_F0071914;
        }
        else if ((int)uVar2 < 8) {
          uVar2 = *(uint *)(param_1 + 0x4c);
loc_F00718E4:
          *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb;
          if (*(int *)(param_1 + 0x48) != 0) {
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(undefined4 *)(param_1 + 0x20) = 0;
            _thread_wakeup_prim(param_1 + 0x48,0,0);
            goto locret_F007193C;
          }
          goto loc_F0071938;
        }
        goto loc_F0071930;
      }
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    else {
      if (uVar2 != 0xf) {
        if ((int)uVar2 < 0x10) {
          if (uVar2 == 0xd) goto loc_F0071920;
          if (uVar2 == 0xe) goto loc_F0071914;
        }
        else {
          if (uVar2 == 0x16) {
            uVar2 = *(uint *)(param_1 + 0x4c);
            goto loc_F00718E4;
          }
          if (uVar2 == 0x84) goto loc_F0071938;
        }
loc_F0071930:
        _panic(aThreadDispatch);
        goto loc_F0071938;
      }
loc_F0071920:
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb;
  }
loc_F0071938:
  *(undefined4 *)(param_1 + 0x20) = 0;
locret_F007193C:
  return CONCAT44(param_2,param_1);
}

