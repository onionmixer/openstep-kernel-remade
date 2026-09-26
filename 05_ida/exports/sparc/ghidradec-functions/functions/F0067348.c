
/* WARNING: Removing unreachable block (ram,0xf0067410) */
/* WARNING: Removing unreachable block (ram,0xf00673e4) */
/* WARNING: Removing unreachable block (ram,0xf0067434) */
/* WARNING: Removing unreachable block (ram,0xf00673b4) */

undefined8 _task_get_special_port(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  int iVar4;
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
    uVar3 = 4;
  }
  else {
    if (param_2 == (int *)0x2) {
      iVar4 = *(int *)(param_1 + 0x88);
      param_2 = (int *)(iVar4 + 8);
      do {
        do {
        } while (*param_2 != 0);
        piVar1 = param_2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(iVar4 + 0xc) == 0) {
        *(undefined4 *)(iVar4 + 8) = 0;
        uVar3 = 5;
        goto locret_F0067454;
      }
      uVar3 = *(undefined4 *)(iVar4 + 0x44);
      _ipc_port_copy_send();
      *(undefined4 *)(iVar4 + 8) = 0;
      *param_3 = uVar3;
    }
    else {
      if ((int)param_2 < 3) {
        puVar2 = (undefined4 *)(param_1 + 0x6c);
        if (param_2 != (int *)0x1) {
          uVar3 = 4;
          goto locret_F0067454;
        }
      }
      else if (param_2 == (int *)0x3) {
        puVar2 = (undefined4 *)(param_1 + 0x70);
      }
      else {
        puVar2 = (undefined4 *)(param_1 + 0x74);
        if (param_2 != (int *)0x4) {
          uVar3 = 4;
          goto locret_F0067454;
        }
      }
      param_2 = (int *)(param_1 + 100);
      do {
        do {
        } while (*param_2 != 0);
        piVar1 = param_2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(param_1 + 0x68) == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        uVar3 = 5;
        goto locret_F0067454;
      }
      uVar3 = *puVar2;
      _ipc_port_copy_send();
      *(undefined4 *)(param_1 + 100) = 0;
      *param_3 = uVar3;
    }
    uVar3 = 0;
  }
locret_F0067454:
  return CONCAT44(param_2,uVar3);
}
