
/* WARNING: Removing unreachable block (ram,0xf00c94e8) */
/* WARNING: Removing unreachable block (ram,0xf00c94c0) */
/* WARNING: Removing unreachable block (ram,0xf00c943c) */
/* WARNING: Removing unreachable block (ram,0xf00c942c) */
/* WARNING: Removing unreachable block (ram,0xf00c9410) */
/* WARNING: Removing unreachable block (ram,0xf00c93fc) */
/* WARNING: Removing unreachable block (ram,0xf00c9420) */
/* WARNING: Removing unreachable block (ram,0xf00c9434) */
/* WARNING: Removing unreachable block (ram,0xf00c9494) */
/* WARNING: Removing unreachable block (ram,0xf00c94dc) */
/* WARNING: Removing unreachable block (ram,0xf00c9508) */
/* WARNING: Removing unreachable block (ram,0xf00c93bc) */

undefined8 -[IODirectDevice free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  undefined (*pauVar4) [10];
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
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
  piVar5 = *(int **)(param_1 + 0x11c);
  piVar6 = *(int **)(param_1 + 0x118);
  _memset((undefined *)((int)register0x00000038 + -0x28),0,0x18);
  *(uint *)((int)register0x00000038 + -0x28) = (uint)*(byte *)((int)register0x00000038 + -0x25);
  if (*(int *)(param_1 + 0x10c) != 0) {
    if (*(int *)(param_1 + 0x110) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 0x18;
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0x232336;
      uVar1 = *(undefined4 *)(param_1 + 0x10c);
      _IOGetKernPort();
      *(undefined4 *)((int)register0x00000038 + -0x18) = uVar1;
      _msg_send_from_kernel((undefined *)((int)register0x00000038 + -0x28),0,0);
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x114),paDevice_0);
    _objc_msgSend();
    _task_self();
    _port_deallocate_EXTERNAL();
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  if (piVar6 != (int *)0x0) {
    iVar2 = *piVar6;
    pauVar4 = (undefined (*) [10])paFreeeisa;
    if (((iVar2 == 1) || (pauVar4 = (undefined (*) [10])paFreehppa, iVar2 == 2)) ||
       (pauVar4 = paFreesparc, iVar2 == 3)) {
      _objc_msgSend(param_1,pauVar4);
    }
  }
  if (piVar5 == (int *)0x0) {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  else {
    if (*piVar5 == 0) {
      iVar2 = piVar5[1];
    }
    else {
      _objc_msgSend(*piVar5,paFree);
      iVar2 = piVar5[1];
    }
    if (iVar2 != 0) {
      _objc_msgSend(iVar2,paFree);
    }
    _IOFree(piVar5,8);
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f88;
  _objc_msgSendSuper(puVar3,paFree);
  return CONCAT44(param_2,puVar3);
}

