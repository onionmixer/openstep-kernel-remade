
/* WARNING: Removing unreachable block (ram,0xf007a660) */
/* WARNING: Removing unreachable block (ram,0xf007a648) */
/* WARNING: Removing unreachable block (ram,0xf007a5dc) */
/* WARNING: Removing unreachable block (ram,0xf007a628) */

undefined8 _kern_serv_notify(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar3 = *param_1;
  if (iVar1 == _kernel_task) {
    _get_kern_port(iVar1,param_3,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      iVar1 = *(int *)(_active_threads + 0xc);
      _get_kern_port(iVar1,param_2,(undefined *)((int)register0x00000038 + -0x10));
      if (iVar1 == 0) {
        _port_request_notification
                  (*(undefined4 *)((int)register0x00000038 + -0xc),
                   *(undefined4 *)((int)register0x00000038 + -0x10));
        iVar1 = 0;
      }
    }
  }
  else if (param_2 == *(int *)(iVar3 + 0x1c)) {
    iVar1 = 0;
  }
  else {
    piVar2 = *(int **)(iVar3 + 0x4c0);
    if ((int *)(iVar3 + 0x4c0) != piVar2) {
      iVar1 = *piVar2;
      while( true ) {
        if (iVar1 == param_2) {
          if (piVar2[1] == param_3) {
            iVar1 = 5;
            goto locret_F007A66C;
          }
          piVar2 = (int *)piVar2[2];
        }
        else {
          piVar2 = (int *)piVar2[2];
        }
        if ((int *)(iVar3 + 0x4c0) == piVar2) break;
        iVar1 = *piVar2;
      }
    }
    piVar2 = (int *)0x10;
    _kalloc();
    *piVar2 = param_2;
    piVar2[1] = param_3;
    iVar1 = *(int *)(iVar3 + 0x4c4);
    if (iVar3 + 0x4c0 == iVar1) {
      *(int **)(iVar3 + 0x4c0) = piVar2;
    }
    else {
      *(int **)(iVar1 + 8) = piVar2;
    }
    piVar2[3] = iVar1;
    piVar2[2] = iVar3 + 0x4c0;
    *(int **)(iVar3 + 0x4c4) = piVar2;
    iVar1 = 0;
  }
locret_F007A66C:
  return CONCAT44(param_2,iVar1);
}
