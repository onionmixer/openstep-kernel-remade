
/* WARNING: Removing unreachable block (ram,0xf00dc9d8) */
/* WARNING: Removing unreachable block (ram,0xf00dc9ac) */
/* WARNING: Removing unreachable block (ram,0xf00dc934) */
/* WARNING: Removing unreachable block (ram,0xf00dc8d0) */
/* WARNING: Removing unreachable block (ram,0xf00dc8bc) */
/* WARNING: Removing unreachable block (ram,0xf00dc888) */
/* WARNING: Removing unreachable block (ram,0xf00dc860) */
/* WARNING: Removing unreachable block (ram,0xf00dc844) */
/* WARNING: Removing unreachable block (ram,0xf00dc84c) */
/* WARNING: Removing unreachable block (ram,0xf00dc874) */
/* WARNING: Removing unreachable block (ram,0xf00dc8a8) */
/* WARNING: Removing unreachable block (ram,0xf00dc8c4) */
/* WARNING: Removing unreachable block (ram,0xf00dc8e4) */
/* WARNING: Removing unreachable block (ram,0xf00dc974) */
/* WARNING: Removing unreachable block (ram,0xf00dc9c8) */
/* WARNING: Removing unreachable block (ram,0xf00dc910) */
/* WARNING: Removing unreachable block (ram,0xf00dc7fc) */

undefined8
-[OutputStream playBuffer:size:tag:replyTo:replyMsgs:]
          (int *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  bool bVar1;
  undefined5 *puVar2;
  undefined (*pauVar3) [24];
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l0;
  uint uVar9;
  undefined4 unaff_l1;
  uint uVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar13;
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
  iVar11 = *(int *)((int)register0x00000038 + 0x5c);
  _IOConvertPort(param_6,2,0);
  if (param_1[0x1a] == 0) {
    if (param_1[0x1b] == 1) {
      param_4 = param_4 & 0xfffffffe;
    }
    else {
      param_4 = param_4 & 0xfffffffc;
    }
  }
  uVar10 = param_3 & ~_page_mask;
  iVar13 = param_3 - uVar10;
  uVar4 = param_4 + iVar13 + _page_mask;
  uVar9 = uVar4 & ~_page_mask;
  _kern_serv_kernel_task_port();
  uVar5 = uVar4;
  _task_self();
  _vm_protect_EXTERNAL();
  if (uVar5 != 0) {
    _IOLog(aAudioVmProtect,uVar5);
  }
  uVar5 = uVar4;
  _vm_allocate_EXTERNAL(uVar4,(undefined *)((int)register0x00000038 + -0x14),uVar9,1);
  bVar1 = false;
  if (uVar5 == 0) {
    _vm_write_EXTERNAL(uVar4,*(undefined4 *)((int)register0x00000038 + -0x14),uVar10,uVar9);
    puVar6 = (undefined *)0xf00fc400;
    if (uVar4 != 0) {
      puVar6 = aAudioVmWriteRe;
      _IOLog(aAudioVmWriteRe,uVar4);
    }
    _task_self();
    _vm_deallocate_EXTERNAL();
    if (puVar6 != (undefined *)0x0) {
      _IOLog(aAudioVmDealloc_0,puVar6);
    }
    bVar1 = true;
    *(int *)((int)register0x00000038 + -0x14) = *(int *)((int)register0x00000038 + -0x14) + iVar13;
  }
  if (bVar1) {
    piVar7 = param_1;
    _objc_msgSend(param_1,paNewregion);
    piVar7[4] = param_4;
    piVar7[5] = param_5;
    piVar7[7] = param_6;
    piVar7[6] = iVar11;
    puVar2 = paLock;
    iVar13 = *(int *)((int)register0x00000038 + -0x14);
    piVar7[2] = iVar13;
    *piVar7 = iVar13;
    piVar7[1] = iVar13 + param_4;
    param_1[0x18] = iVar11;
    param_1[0x17] = param_6;
    _objc_msgSend(param_1[10],puVar2);
    piVar8 = param_1 + 0xb;
    if (piVar8 == (int *)param_1[0xb]) {
      param_1[0xb] = (int)piVar7;
      param_1[0xc] = (int)piVar7;
      piVar7[0xf] = (int)piVar8;
      piVar7[0x10] = (int)piVar8;
    }
    else {
      iVar11 = param_1[0xc];
      piVar7[0x10] = iVar11;
      piVar7[0xf] = (int)piVar8;
      param_1[0xc] = (int)piVar7;
      *(int **)(iVar11 + 0x3c) = piVar7;
    }
    _objc_msgSend(param_1[10],paUnlock);
    pauVar3 = paDatapendingfor;
    iVar11 = param_1[2];
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend(iVar11,pauVar3,param_1);
    uVar12 = 1;
  }
  else {
    _IOLog(aAudioPlaybackR,param_4);
    uVar12 = 0;
  }
  return CONCAT44(param_2,uVar12);
}
