
/* WARNING: Removing unreachable block (ram,0xf00676dc) */
/* WARNING: Removing unreachable block (ram,0xf0067690) */

undefined8 _thread_set_special_port(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
    uVar4 = 4;
    goto locret_F00676E8;
  }
  if (param_2 == (int *)0x2) {
    piVar3 = (int *)(param_1 + 0xb8);
  }
  else if ((int)param_2 < 3) {
    piVar3 = (int *)(param_1 + 0xb0);
    if (param_2 != (int *)0x1) {
      uVar4 = 4;
      goto locret_F00676E8;
    }
  }
  else {
    piVar3 = (int *)(param_1 + 0xb4);
    if (param_2 != (int *)0x3) {
      uVar4 = 4;
      goto locret_F00676E8;
    }
  }
  param_2 = (int *)(param_1 + 0xa8);
  do {
    do {
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0xac) == 0) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    uVar4 = 5;
  }
  else {
    iVar2 = *piVar3;
    *piVar3 = param_3;
    *(undefined4 *)(param_1 + 0xa8) = 0;
    if (iVar2 != 0) {
      uVar4 = 0;
      if (iVar2 == -1) goto locret_F00676E8;
      _ipc_port_release_send();
    }
    uVar4 = 0;
  }
locret_F00676E8:
  return CONCAT44(param_2,uVar4);
}
