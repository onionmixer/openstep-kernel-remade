
/* WARNING: Removing unreachable block (ram,0xf0073d14) */
/* WARNING: Removing unreachable block (ram,0xf0073ce0) */
/* WARNING: Removing unreachable block (ram,0xf0073c30) */
/* WARNING: Removing unreachable block (ram,0xf0073cb0) */
/* WARNING: Removing unreachable block (ram,0xf0073cfc) */
/* WARNING: Removing unreachable block (ram,0xf0073d20) */
/* WARNING: Removing unreachable block (ram,0xf0073c14) */

undefined8 _task_info(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
loc_F0073DCC:
    uVar5 = 4;
  }
  else {
    if (param_2 == (int *)0x1) {
      if (*param_4 < 8) goto loc_F0073DCC;
      iVar1 = _kernel_map;
      if (param_1 != _kernel_task) {
        iVar1 = param_1[3];
      }
      param_3[2] = *(int *)(iVar1 + 0x28);
      iVar1 = *(int *)(*(int *)(iVar1 + 0x24) + 0x20);
      umul(iVar1,_page_size);
      param_3[3] = iVar1;
      do {
        do {
        } while (*param_1 != 0);
        piVar4 = param_1;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      param_3[1] = param_1[0x12];
      *param_3 = param_1[0x11];
      param_3[4] = param_1[0x15];
      param_3[5] = param_1[0x16];
      param_3[6] = param_1[0x17];
      param_3[7] = param_1[0x18];
      *param_1 = 0;
      *param_4 = 8;
    }
    else {
      if (param_2 != (int *)0x3) {
        uVar5 = 4;
        goto locret_F0073DD8;
      }
      if (*param_4 < 4) {
        uVar5 = 4;
        goto locret_F0073DD8;
      }
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      do {
        do {
        } while (*param_1 != 0);
        piVar4 = param_1;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      piVar4 = (int *)param_1[7];
      if (param_1 + 7 != piVar4) {
        piVar2 = (int *)0xfff0bc00;
        do {
          param_2 = piVar4 + 8;
          _splusclock();
          do {
            do {
            } while (*param_2 != 0);
            piVar3 = param_2;
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          _thread_read_times(piVar4,(undefined *)((int)register0x00000038 + -0x10),
                             (undefined *)((int)register0x00000038 + -0x18));
          piVar4[8] = 0;
          _splx(piVar2);
          param_3[1] = param_3[1] + *(int *)((int)register0x00000038 + -0xc);
          *param_3 = *param_3 + *(int *)((int)register0x00000038 + -0x10);
          if (999999 < param_3[1]) {
            param_3[1] = param_3[1] + -1000000;
            *param_3 = *param_3 + 1;
          }
          param_3[3] = param_3[3] + *(int *)((int)register0x00000038 + -0x14);
          param_3[2] = param_3[2] + *(int *)((int)register0x00000038 + -0x18);
          if (999999 < param_3[3]) {
            param_3[3] = param_3[3] + -1000000;
            param_3[2] = param_3[2] + 1;
          }
          piVar4 = (int *)piVar4[4];
          piVar2 = param_1 + 7;
        } while (piVar2 != piVar4);
      }
      *param_1 = 0;
      *param_4 = 4;
    }
    uVar5 = 0;
  }
locret_F0073DD8:
  return CONCAT44(param_2,uVar5);
}

