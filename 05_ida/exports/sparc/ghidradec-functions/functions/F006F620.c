
/* WARNING: Removing unreachable block (ram,0xf006f6a0) */
/* WARNING: Removing unreachable block (ram,0xf006f8b8) */
/* WARNING: Removing unreachable block (ram,0xf006f838) */
/* WARNING: Removing unreachable block (ram,0xf006f818) */
/* WARNING: Removing unreachable block (ram,0xf006f7d0) */
/* WARNING: Removing unreachable block (ram,0xf006f72c) */
/* WARNING: Removing unreachable block (ram,0xf006f6f4) */
/* WARNING: Removing unreachable block (ram,0xf006f788) */
/* WARNING: Removing unreachable block (ram,0xf006f800) */
/* WARNING: Removing unreachable block (ram,0xf006f82c) */
/* WARNING: Removing unreachable block (ram,0xf006f87c) */
/* WARNING: Removing unreachable block (ram,0xf006f770) */
/* WARNING: Removing unreachable block (ram,0xf006f6ac) */
/* WARNING: Removing unreachable block (ram,0xf006f650) */

undefined8 _processor_set_things(int param_1,int *param_2,uint *param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  undefined4 *puVar7;
  undefined4 unaff_l5;
  undefined4 *puVar8;
  undefined4 unaff_l6;
  undefined4 *puVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
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
  if (param_1 == 0) {
    uVar10 = 4;
  }
  else {
    puVar7 = (undefined4 *)0x0;
    puVar8 = (undefined4 *)0x0;
    do {
      do {
        do {
        } while (*(int *)(param_1 + 0x158) != 0);
        piVar1 = (int *)(param_1 + 0x158);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(param_1 + 0x154) == 0) {
        *(undefined4 *)(param_1 + 0x158) = 0;
        uVar10 = 5;
        goto locret_F006F8D4;
      }
      if (param_4 == 0) {
        uVar6 = *(uint *)(param_1 + 0x134);
      }
      else {
        uVar6 = *(uint *)(param_1 + 0x140);
      }
      puVar9 = (undefined4 *)(uVar6 * 4);
      if (puVar9 < puVar8 || (int)puVar9 - (int)puVar8 == 0) {
        if (param_4 == 0) {
          uVar3 = 0;
          iVar4 = *(int *)(param_1 + 300);
          if (uVar6 != 0) {
            iVar5 = 0;
            do {
              _task_reference(iVar4);
              *(int *)(iVar5 + (int)puVar7) = iVar4;
              iVar5 = iVar5 + 4;
              uVar3 = uVar3 + 1;
              iVar4 = *(int *)(iVar4 + 0x10);
            } while (uVar3 < uVar6);
          }
        }
        else {
          uVar3 = 0;
          if ((param_4 == 1) && (iVar4 = *(int *)(param_1 + 0x138), uVar6 != 0)) {
            iVar5 = 0;
            do {
              _thread_reference(iVar4);
              *(int *)(iVar5 + (int)puVar7) = iVar4;
              iVar5 = iVar5 + 4;
              uVar3 = uVar3 + 1;
              iVar4 = *(int *)(iVar4 + 0x18);
            } while (uVar3 < uVar6);
          }
        }
        *(undefined4 *)(param_1 + 0x158) = 0;
        if (uVar6 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (puVar8 != (undefined4 *)0x0) {
            _kfree(puVar7,puVar8);
            uVar10 = 0;
            goto locret_F006F8D4;
          }
        }
        else {
          if (puVar9 < puVar8) {
            puVar2 = puVar9;
            _kalloc();
            if (puVar2 == (undefined4 *)0x0) {
              if (param_4 == 0) {
                uVar3 = 0;
                if (uVar6 != 0) {
                  iVar4 = 0;
                  do {
                    uVar3 = uVar3 + 1;
                    _task_deallocate(*(undefined4 *)(iVar4 + (int)puVar7));
                    iVar4 = iVar4 + 4;
                  } while (uVar3 < uVar6);
                }
              }
              else {
                uVar3 = 0;
                if ((param_4 == 1) && (uVar6 != 0)) {
                  iVar4 = 0;
                  do {
                    uVar3 = uVar3 + 1;
                    _thread_deallocate(*(undefined4 *)(iVar4 + (int)puVar7));
                    iVar4 = iVar4 + 4;
                  } while (uVar3 < uVar6);
                }
              }
              _kfree(puVar7,puVar8);
              uVar10 = 6;
              goto locret_F006F8D4;
            }
            _bcopy(puVar7,puVar2,puVar9);
            _kfree(puVar7,puVar8);
            *param_2 = (int)puVar2;
          }
          else {
            *param_2 = (int)puVar7;
            puVar2 = puVar7;
          }
          *param_3 = uVar6;
          if (param_4 == 0) {
            uVar3 = 0;
            if (uVar6 != 0) {
              do {
                uVar10 = *puVar2;
                uVar3 = uVar3 + 1;
                _convert_task_to_port();
                *puVar2 = uVar10;
                puVar2 = puVar2 + 1;
              } while (uVar3 < uVar6);
              uVar10 = 0;
              goto locret_F006F8D4;
            }
          }
          else {
            uVar3 = 0;
            if (param_4 != 1) {
              uVar10 = 0;
              goto locret_F006F8D4;
            }
            if (uVar6 != 0) {
              do {
                uVar10 = *puVar2;
                uVar3 = uVar3 + 1;
                _convert_thread_to_port();
                *puVar2 = uVar10;
                puVar2 = puVar2 + 1;
              } while (uVar3 < uVar6);
            }
          }
        }
        uVar10 = 0;
        goto locret_F006F8D4;
      }
      *(undefined4 *)(param_1 + 0x158) = 0;
      if (puVar8 != (undefined4 *)0x0) {
        _kfree(puVar7,puVar8);
      }
      puVar7 = puVar9;
      _kalloc();
      puVar8 = puVar9;
    } while (puVar7 != (undefined4 *)0x0);
    uVar10 = 6;
  }
locret_F006F8D4:
  return CONCAT44(param_2,uVar10);
}
