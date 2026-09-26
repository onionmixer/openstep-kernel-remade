
/* WARNING: Removing unreachable block (ram,0xf00693e0) */
/* WARNING: Removing unreachable block (ram,0xf0069380) */
/* WARNING: Removing unreachable block (ram,0xf00693c4) */
/* WARNING: Removing unreachable block (ram,0xf00692fc) */
/* WARNING: Removing unreachable block (ram,0xf0069268) */

undefined8 _lock_read_to_write(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  sword sVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
    piVar1 = param_1 + 2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + -1;
  if (*param_1 == _active_threads) {
    param_1[2] = 0;
    uVar6 = 0;
    param_1[1] = param_1[1] & 0xfffff000U | (param_1[1] & 0xfffU) + 1 & 0xfff;
  }
  else {
    uVar5 = param_1[1];
    if ((uVar5 & 0x8000) == 0) {
      param_1[1] = uVar5 | 0x8000;
      if (*(sword *)(param_1 + 1) != 0) {
        piVar1 = param_1 + 2;
        do {
          iVar2 = _lock_wait_time;
          if (_lock_wait_time < 1) {
            uVar5 = param_1[1];
          }
          else {
            param_1[2] = 0;
            iVar2 = iVar2 + -1;
            if (0 < iVar2) {
              do {
                iVar2 = iVar2 + -1;
                if (*(sword *)(param_1 + 1) == 0) break;
              } while (0 < iVar2);
            }
            do {
              do {
                piVar3 = param_1 + 2;
              } while (*piVar3 != 0);
              _simple_lock_try();
            } while (piVar3 == (int *)0x0);
            uVar5 = param_1[1];
          }
          sVar4 = *(sword *)(param_1 + 1);
          if ((uVar5 & 0x1000) == 0) {
loc_F00693F8:
            bVar7 = sVar4 == 0;
          }
          else {
            bVar7 = sVar4 == 0;
            if (!bVar7) {
              param_1[1] = uVar5 | 0x2000;
              _thread_sleep(param_1,piVar1,0);
              do {
                do {
                } while (*piVar1 != 0);
                piVar3 = piVar1;
                _simple_lock_try();
              } while (piVar3 == (int *)0x0);
              sVar4 = *(sword *)(param_1 + 1);
              goto loc_F00693F8;
            }
          }
        } while (!bVar7);
      }
      param_1[2] = 0;
      uVar6 = 0;
    }
    else {
      if ((uVar5 & 0xffff2000) == 0x2000) {
        param_1[1] = uVar5 & 0xffffdfff;
        _thread_wakeup_prim(param_1,0,0);
      }
      param_1[2] = 0;
      uVar6 = 1;
    }
  }
  return CONCAT44(param_2,uVar6);
}
