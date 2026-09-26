
/* WARNING: Removing unreachable block (ram,0xf008722c) */
/* WARNING: Removing unreachable block (ram,0xf00871cc) */
/* WARNING: Removing unreachable block (ram,0xf008714c) */
/* WARNING: Removing unreachable block (ram,0xf0087108) */
/* WARNING: Removing unreachable block (ram,0xf0087120) */
/* WARNING: Removing unreachable block (ram,0xf00871b0) */
/* WARNING: Removing unreachable block (ram,0xf00871f0) */
/* WARNING: Removing unreachable block (ram,0xf0087064) */

undefined8
_vm_object_copy(int *param_1,uint param_2,int param_3,int *param_4,uint *param_5,undefined4 *param_6
               )

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 unaff_l0;
  int iVar6;
  int iVar7;
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
  if (param_1 == (int *)0x0) {
    *param_4 = 0;
    *param_5 = 0;
loc_F00872C8:
    *param_6 = 0;
  }
  else {
    do {
      do {
      } while (param_1[4] != 0);
      piVar5 = param_1 + 4;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    if (param_1[10] == 0) {
      sVar1 = *(sword *)(param_1 + 6);
    }
    else {
      if ((param_1[0x11] & 0x800U) == 0) {
        _vm_object_collapse(param_1);
        iVar6 = param_1[7];
        while (iVar6 != 0) {
          iVar7 = iVar6 + 0x10;
          _simple_lock_try();
          if (iVar7 != 0) {
            if ((*(sword *)(iVar6 + 0x1a) != 0) || (*(int *)(iVar6 + 0x28) != 0)) {
              *(undefined4 *)(iVar6 + 0x10) = 0;
              iVar6 = param_1[5];
              goto loc_F00871AC;
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
            *(sword *)(iVar6 + 0x18) = *(sword *)(iVar6 + 0x18) + 1;
            param_1[4] = 0;
            *param_4 = iVar6;
            *param_5 = param_2;
            goto loc_F00872C8;
          }
          param_1[4] = 0;
          do {
            do {
            } while (param_1[4] != 0);
            piVar5 = param_1 + 4;
            _simple_lock_try();
          } while (piVar5 == (int *)0x0);
          iVar6 = param_1[7];
        }
        iVar6 = param_1[5];
loc_F00871AC:
        param_1[4] = 0;
        _vm_object_allocate();
        while( true ) {
          do {
            do {
              piVar5 = param_1 + 4;
            } while (*piVar5 != 0);
            _simple_lock_try();
          } while (piVar5 == (int *)0x0);
          iVar7 = param_1[7];
          if (iVar7 == 0) {
            *(int **)(iVar6 + 0x20) = param_1;
            goto loc_F0087258;
          }
          iVar3 = iVar7 + 0x10;
          _simple_lock_try();
          if (iVar3 != 0) break;
          param_1[4] = 0;
        }
        if ((*(int **)(iVar7 + 0x20) != param_1) || (*(int *)(iVar7 + 0x24) != 0)) {
          _panic(aVmObjectCopyCo);
        }
        *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + -1;
        *(int *)(iVar7 + 0x20) = iVar6;
        *(sword *)(iVar6 + 0x18) = *(sword *)(iVar6 + 0x18) + 1;
        *(undefined4 *)(iVar7 + 0x10) = 0;
        *(int **)(iVar6 + 0x20) = param_1;
loc_F0087258:
        *(undefined4 *)(iVar6 + 0x24) = 0;
        piVar5 = (int *)*param_1;
        uVar2 = *(uint *)(iVar6 + 0x14);
        *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
        param_1[7] = iVar6;
        if (param_1 != piVar5) {
          uVar4 = piVar5[6];
          while( true ) {
            if (uVar4 < uVar2) {
              piVar5[8] = piVar5[8] | 0x200000;
              piVar5 = (int *)piVar5[2];
            }
            else {
              piVar5 = (int *)piVar5[2];
            }
            if (param_1 == piVar5) break;
            uVar4 = piVar5[6];
          }
        }
        param_1[4] = 0;
        *param_4 = iVar6;
        *param_5 = param_2;
        goto loc_F00872C8;
      }
      sVar1 = *(sword *)(param_1 + 6);
    }
    piVar5 = (int *)*param_1;
    *(sword *)(param_1 + 6) = sVar1 + 1;
    if (param_1 != piVar5) {
      uVar2 = piVar5[6];
      while( true ) {
        if (uVar2 < param_2) {
          piVar5 = (int *)piVar5[2];
        }
        else if (uVar2 < param_2 + param_3) {
          piVar5[8] = piVar5[8] | 0x200000;
          piVar5 = (int *)piVar5[2];
        }
        else {
          piVar5 = (int *)piVar5[2];
        }
        if (param_1 == piVar5) break;
        uVar2 = piVar5[6];
      }
    }
    param_1[4] = 0;
    *param_4 = (int)param_1;
    *param_5 = param_2;
    *param_6 = 1;
  }
  return CONCAT44(param_2,param_1);
}
