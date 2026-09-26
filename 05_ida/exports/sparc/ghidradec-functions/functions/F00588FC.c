
/* WARNING: Removing unreachable block (ram,0xf0058a14) */
/* WARNING: Removing unreachable block (ram,0xf00589a8) */
/* WARNING: Removing unreachable block (ram,0xf0058a44) */
/* WARNING: Removing unreachable block (ram,0xf0058938) */
/* WARNING: Removing unreachable block (ram,0xf0058970) */
/* WARNING: Removing unreachable block (ram,0xf00589e0) */
/* WARNING: Removing unreachable block (ram,0xf0058a90) */
/* WARNING: Removing unreachable block (ram,0xf0058914) */

undefined8 _ipc_mqueue_copyin(uint *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint *puVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
    } while (param_1[2] != 0);
    puVar1 = param_1 + 2;
    _simple_lock_try();
  } while (puVar1 == (uint *)0x0);
  if ((param_1[3] == 0) ||
     (puVar1 = param_1, _ipc_entry_lookup(param_1,param_2), puVar1 == (uint *)0x0)) {
loc_F0058A64:
    param_1[2] = 0;
    uVar4 = 0x10004002;
  }
  else {
    param_2 = (int *)puVar1[1];
    if ((*puVar1 & 0x20000) == 0) {
      if ((*puVar1 & 0x80000) == 0) goto loc_F0058A64;
      do {
        do {
        } while (*param_2 != 0);
        piVar3 = param_2;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[2] = 0;
      piVar3 = param_2 + 4;
    }
    else {
      do {
        do {
        } while (*param_2 != 0);
        piVar3 = param_2;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[2] = 0;
      piVar3 = (int *)param_2[0xc];
      if (piVar3 == (int *)0x0) {
        piVar3 = param_2 + 0x10;
      }
      else {
        do {
          do {
          } while (*piVar3 != 0);
          piVar2 = piVar3;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if (piVar3[2] < 0) {
          *piVar3 = 0;
          *param_2 = 0;
          uVar4 = 0x1000400a;
          goto locret_F0058AB0;
        }
        _ipc_pset_remove(piVar3,param_2);
        *piVar3 = 0;
        if (piVar3[1] == 0) {
          _zfree((&_ipc_object_zones)[(piVar3[2] & 0x7fffffffU) >> 0x10],piVar3);
        }
        piVar3 = param_2 + 0x10;
      }
    }
    param_2[1] = param_2[1] + 1;
    do {
      do {
      } while (*piVar3 != 0);
      piVar2 = piVar3;
      _simple_lock_try();
      uVar4 = 0;
    } while (piVar2 == (int *)0x0);
    *param_2 = 0;
    *param_4 = param_2;
    *param_3 = piVar3;
  }
locret_F0058AB0:
  return CONCAT44(param_2,uVar4);
}
