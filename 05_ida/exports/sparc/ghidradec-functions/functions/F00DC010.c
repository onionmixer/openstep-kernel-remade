
/* WARNING: Removing unreachable block (ram,0xf00dc14c) */
/* WARNING: Removing unreachable block (ram,0xf00dc120) */
/* WARNING: Removing unreachable block (ram,0xf00dc0a0) */
/* WARNING: Removing unreachable block (ram,0xf00dc028) */
/* WARNING: Removing unreachable block (ram,0xf00dc060) */
/* WARNING: Removing unreachable block (ram,0xf00dc0e8) */
/* WARNING: Removing unreachable block (ram,0xf00dc13c) */
/* WARNING: Removing unreachable block (ram,0xf00dc07c) */
/* WARNING: Removing unreachable block (ram,0xf00dc014) */

undefined8
-[InputStream recordSize:tag:replyTo:replyMsgs:]
          (int *param_1,undefined4 param_2,uint param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  piVar1 = param_1;
  _kern_serv_kernel_task_port();
  _IOConvertPort(param_5,2,0);
  if (param_1[0x1a] == 0) {
    if (param_1[0x1b] == 1) {
      param_3 = param_3 & 0xfffffffe;
    }
    else {
      param_3 = param_3 & 0xfffffffc;
    }
  }
  _vm_allocate_EXTERNAL(piVar1,(undefined *)((int)register0x00000038 + -0x14),param_3,1);
  if (piVar1 == (int *)0x0) {
    piVar1 = param_1;
    _objc_msgSend(param_1,paNewregion);
    piVar1[4] = param_3;
    piVar1[5] = param_4;
    piVar1[7] = param_5;
    piVar1[6] = param_6;
    uVar4 = paLock;
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
    *piVar1 = iVar3;
    piVar1[3] = iVar3;
    piVar1[2] = iVar3;
    piVar1[1] = *piVar1 + param_3;
    param_1[0x18] = param_6;
    param_1[0x17] = param_5;
    _objc_msgSend(param_1[10],uVar4);
    piVar2 = param_1 + 0xb;
    if (piVar2 == (int *)param_1[0xb]) {
      param_1[0xb] = (int)piVar1;
      param_1[0xc] = (int)piVar1;
      piVar1[0xf] = (int)piVar2;
      piVar1[0x10] = (int)piVar2;
    }
    else {
      iVar3 = param_1[0xc];
      piVar1[0x10] = iVar3;
      piVar1[0xf] = (int)piVar2;
      param_1[0xc] = (int)piVar1;
      *(int **)(iVar3 + 0x3c) = piVar1;
    }
    _objc_msgSend(param_1[10],paUnlock);
    uVar4 = paDatapendingfor;
    iVar3 = param_1[2];
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend(iVar3,uVar4,param_1);
    uVar4 = 1;
  }
  else {
    _IOLog(aAudioRecordReq,param_3);
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
