/* GHIDRADEC_FUNCTION index=4800 start=0xf00dc6d8 */

/* WARNING: Removing unreachable block (ram,0xf00dc7d8) */
/* WARNING: Removing unreachable block (ram,0xf00dc754) */
/* WARNING: Removing unreachable block (ram,0xf00dc7c8) */
/* WARNING: Removing unreachable block (ram,0xf00dc768) */
/* WARNING: Removing unreachable block (ram,0xf00dc70c) */

undefined8
-[OutputStream initChannel:tag:user:owner:type:]
          (int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
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
  uint uVar6;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422f8;
  _objc_msgSendSuper(puVar1,paInitchannelTag,param_3,param_4,param_5,param_6,
                     *(undefined4 *)((int)register0x00000038 + 0x5c));
  if (puVar1 == (undefined *)0x0) {
    param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x7c) = 0x8000;
    *(undefined4 *)(param_1 + 0x78) = 0x8000;
    *(undefined4 *)(param_1 + 0x98) = 1;
    iVar2 = param_1 + 0x8c;
    *(int *)(param_1 + 0x90) = iVar2;
    *(int *)(param_1 + 0x8c) = iVar2;
    for (uVar6 = 0; uVar3 = param_3, _objc_msgSend(param_3,paDmacount), uVar6 < uVar3;
        uVar6 = uVar6 + 1) {
      puVar4 = (undefined4 *)0x1c;
      _IOMalloc();
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[4] = 0;
      if (iVar2 == *(int *)(param_1 + 0x8c)) {
        *(undefined4 **)(param_1 + 0x8c) = puVar4;
        *(undefined4 **)(param_1 + 0x90) = puVar4;
        puVar4[5] = iVar2;
        puVar4[6] = iVar2;
      }
      else {
        iVar5 = *(int *)(param_1 + 0x90);
        puVar4[6] = iVar5;
        puVar4[5] = iVar2;
        *(undefined4 **)(param_1 + 0x90) = puVar4;
        *(undefined4 **)(iVar5 + 0x14) = puVar4;
      }
    }
    iVar5 = _page_size << 3;
    _IOMalloc();
    iVar2 = _page_size;
    *(int *)(param_1 + 0x70) = iVar5;
    iVar2 = iVar2 << 2;
    _IOMalloc();
    *(int *)(param_1 + 0x74) = iVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4801 start=0xf00dc7ec */

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
/* GHIDRADEC_FUNCTION index=4802 start=0xf00dc9ec */

/* WARNING: Removing unreachable block (ram,0xf00dca18) */

undefined8
-[OutputStream canConvertRegion:rate:format:channelCount:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
          undefined4 param_6)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422f8;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _objc_msgSendSuper(puVar1,paCanconvertregi,param_3,param_4,param_5,param_6);
  if (((uint)puVar1 & 0xff) != 0) {
    uVar2 = 1;
    goto locret_F00DCA94;
  }
  if ((param_5 != 2) && (param_5 != 4)) {
    if ((param_4 == 0x5622) && (*(int *)(param_1 + 100) == 0xac44)) {
      uVar2 = 1;
      goto locret_F00DCA94;
    }
    if (param_4 != 0xac44) {
      uVar2 = 0;
      goto locret_F00DCA94;
    }
    uVar2 = 1;
    if (*(int *)(param_1 + 100) == 0x5622) goto locret_F00DCA94;
  }
  uVar2 = 0;
locret_F00DCA94:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4803 start=0xf00dca9c */

/* WARNING: Removing unreachable block (ram,0xf00dcb0c) */

undefined8
-[OutputStream clearForMix:size:format:]
          (undefined4 param_1,undefined4 param_2,undefined *param_3,int param_4,int param_5)

{
  undefined4 unaff_l0;
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
  if (param_5 == 3) {
    while (param_4 = param_4 + -1, param_4 != -1) {
      *param_3 = 0x80;
      param_3 = param_3 + 1;
    }
  }
  else if (param_5 == 1) {
    while (param_4 = param_4 + -1, param_4 != -1) {
      *param_3 = 0x7f;
      param_3 = param_3 + 1;
    }
  }
  else {
    _bzero();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4804 start=0xf00dcb1c */

/* WARNING: Removing unreachable block (ram,0xf00dd31c) */
/* WARNING: Removing unreachable block (ram,0xf00dd36c) */
/* WARNING: Removing unreachable block (ram,0xf00dd0ec) */
/* WARNING: Removing unreachable block (ram,0xf00dd2dc) */
/* WARNING: Removing unreachable block (ram,0xf00dd068) */
/* WARNING: Removing unreachable block (ram,0xf00dce9c) */
/* WARNING: Removing unreachable block (ram,0xf00dd130) */
/* WARNING: Removing unreachable block (ram,0xf00dd094) */
/* WARNING: Removing unreachable block (ram,0xf00dd16c) */
/* WARNING: Removing unreachable block (ram,0xf00dcf1c) */
/* WARNING: Removing unreachable block (ram,0xf00dd1a0) */
/* WARNING: Removing unreachable block (ram,0xf00dd0bc) */
/* WARNING: Removing unreachable block (ram,0xf00dd1ec) */
/* WARNING: Removing unreachable block (ram,0xf00dcfa8) */
/* WARNING: Removing unreachable block (ram,0xf00dcf54) */
/* WARNING: Removing unreachable block (ram,0xf00dd21c) */
/* WARNING: Removing unreachable block (ram,0xf00dd270) */
/* WARNING: Removing unreachable block (ram,0xf00dcffc) */
/* WARNING: Removing unreachable block (ram,0xf00dd2b0) */
/* WARNING: Removing unreachable block (ram,0xf00dcfc8) */
/* WARNING: Removing unreachable block (ram,0xf00dcfdc) */
/* WARNING: Removing unreachable block (ram,0xf00dd2c4) */
/* WARNING: Removing unreachable block (ram,0xf00dd014) */
/* WARNING: Removing unreachable block (ram,0xf00dd284) */
/* WARNING: Removing unreachable block (ram,0xf00dd234) */
/* WARNING: Removing unreachable block (ram,0xf00dcf90) */
/* WARNING: Removing unreachable block (ram,0xf00dd1d8) */
/* WARNING: Removing unreachable block (ram,0xf00dcecc) */
/* WARNING: Removing unreachable block (ram,0xf00dd0d4) */
/* WARNING: Removing unreachable block (ram,0xf00dd1b8) */
/* WARNING: Removing unreachable block (ram,0xf00dd158) */
/* WARNING: Removing unreachable block (ram,0xf00dd080) */
/* WARNING: Removing unreachable block (ram,0xf00dd204) */
/* WARNING: Removing unreachable block (ram,0xf00dd140) */
/* WARNING: Removing unreachable block (ram,0xf00dd040) */
/* WARNING: Removing unreachable block (ram,0xf00dd248) */
/* WARNING: Removing unreachable block (ram,0xf00dd028) */
/* WARNING: Removing unreachable block (ram,0xf00dd100) */
/* WARNING: Removing unreachable block (ram,0xf00dd344) */
/* WARNING: Removing unreachable block (ram,0xf00dd388) */
/* WARNING: Removing unreachable block (ram,0xf00dcf78) */

qword -[OutputStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:]
                (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                uint param_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  uint uVar8;
  undefined4 unaff_l1;
  uint uVar9;
  uint uVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  uint uVar12;
  undefined4 unaff_l5;
  uint uVar13;
  undefined4 unaff_l6;
  uint uVar14;
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
  iVar11 = *(int *)(param_1 + 0x68);
  uVar8 = *(uint *)(param_3 + 8);
  uVar14 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  iVar7 = *(int *)((int)register0x00000038 + 100);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  uVar13 = 0;
  cVar1 = *(char *)((int)register0x00000038 + 0x5f);
  bVar2 = true;
  uVar10 = *(uint *)(param_1 + 0x70);
  uVar6 = *(int *)(param_3 + 4) - uVar8;
  uVar12 = *(uint *)(param_1 + 0x74);
  if (uVar6 < param_6) {
    param_6 = uVar6;
  }
  uVar4 = (uint)(iVar11 == 0);
  if ((*(int *)(param_1 + 0x78) == 0x8000) && (*(int *)(param_1 + 0x7c) == 0x8000)) {
    iVar3 = *(int *)(param_1 + 0x6c);
  }
  else {
    uVar4 = uVar4 | 2;
    iVar3 = *(int *)(param_1 + 0x6c);
  }
  if (iVar3 == 1) {
    if (*(int *)((int)register0x00000038 + 0x68) != 2) {
      iVar3 = *(int *)(param_1 + 0x6c);
      goto loc_F00DCBCC;
    }
    uVar4 = uVar4 | 0x10;
loc_F00DCBE4:
    iVar3 = *(int *)(param_1 + 100);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x6c);
loc_F00DCBCC:
    if (iVar3 == 2) {
      if (*(int *)((int)register0x00000038 + 0x68) == 1) {
        uVar4 = uVar4 | 0x20;
      }
      goto loc_F00DCBE4;
    }
    iVar3 = *(int *)(param_1 + 100);
  }
  if (iVar3 == 0x5622) {
    if (*(int *)((int)register0x00000038 + 0x60) != 0xac44) {
      iVar3 = *(int *)(param_1 + 100);
      goto loc_F00DCC18;
    }
    uVar4 = uVar4 | 4;
  }
  else {
    iVar3 = *(int *)(param_1 + 100);
loc_F00DCC18:
    if ((iVar3 == 0xac44) && (*(int *)((int)register0x00000038 + 0x60) == 0x5622)) {
      uVar4 = uVar4 | 8;
    }
  }
  if ((iVar11 == 3) && (iVar7 == 0)) {
    uVar4 = uVar4 | 0x40;
  }
  else if ((iVar11 == 3) && (iVar7 == 1)) {
    uVar4 = uVar4 | 0x80;
  }
  else if ((iVar11 == 0) && (iVar7 == 3)) {
    uVar4 = uVar4 | 0x100;
  }
  else if ((iVar11 == 0) && (iVar7 == 1)) {
    uVar4 = uVar4 | 0x200;
  }
  else if ((iVar11 == 1) && (iVar7 == 0)) {
    uVar4 = uVar4 | 0x400;
  }
  else if ((iVar11 == 1) && (iVar7 == 3)) {
    uVar4 = uVar4 | 0x800;
  }
  if (uVar4 == 0x18) {
    _audio_convertMonoToStereo(uVar8,uVar10,param_6,iVar11);
    uVar6 = param_6 << 1;
    uVar8 = param_6;
loc_F00DCF8C:
    _audio_resample44To22(uVar10,uVar12,uVar6,iVar11,param_1 + 0x80);
    uVar9 = param_6;
    param_6 = uVar8;
    goto loc_F00DD2E8;
  }
  uVar9 = param_6;
  if (uVar4 < 0x19) {
    if (uVar4 == 5) {
      uVar6 = param_6 >> 1;
      _audio_swapSamples(uVar8,uVar10,param_6 >> 2);
      uVar9 = uVar6;
loc_F00DD100:
      _audio_resample22To44(uVar10,uVar12,uVar6,iVar11);
      goto loc_F00DD2E8;
    }
    if (uVar4 < 6) {
      if (uVar4 == 2) {
loc_F00DD050:
        _audio_scaleSamples(uVar8,uVar10,param_6,iVar11,*(undefined4 *)(param_1 + 0x6c),
                            *(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c));
        uVar12 = uVar10;
        uVar14 = uVar8;
        goto loc_F00DD2E8;
      }
      if (uVar4 < 3) {
        uVar12 = uVar8;
        if (uVar4 == 0) goto loc_F00DD2E8;
        if (uVar4 == 1) {
          _audio_swapSamples(uVar8,uVar10,param_6 >> 1);
          uVar12 = uVar10;
          goto loc_F00DD2E8;
        }
      }
      else {
        if (uVar4 == 3) {
          _audio_swapSamples(uVar8,uVar10,param_6 >> 1);
          uVar8 = uVar10;
          uVar10 = uVar12;
          goto loc_F00DD050;
        }
        if (uVar4 == 4) {
          uVar6 = param_6 >> 1;
          uVar12 = uVar8;
          uVar9 = uVar6;
loc_F00DD248:
          _audio_resample22To44(uVar12,uVar10,uVar6,iVar11);
          uVar12 = uVar10;
          goto loc_F00DD2E8;
        }
      }
    }
    else {
      if (uVar4 == 0x10) {
        _audio_convertMonoToStereo(uVar8,uVar10,param_6 >> 1,iVar11);
        uVar12 = uVar10;
        uVar9 = param_6 >> 1;
        goto loc_F00DD2E8;
      }
      if (uVar4 < 0x11) {
        if (uVar4 == 8) {
          uVar4 = param_6 * 2;
          if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
            uVar4 = uVar6;
          }
          uVar12 = uVar8;
          param_6 = uVar4;
          uVar8 = uVar4 >> 1;
          goto loc_F00DD200;
        }
        if (uVar4 == 9) {
          uVar9 = param_6 * 2;
          if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
            uVar9 = uVar6;
          }
          _audio_resample44To22(uVar8,uVar10,uVar9,iVar11,param_1 + 0x80);
          _audio_swapSamples(uVar10,uVar12,uVar9 >> 2);
          param_6 = uVar9 >> 1;
          goto loc_F00DD2E8;
        }
      }
      else {
        if (uVar4 == 0x14) {
          uVar9 = param_6 >> 2;
          _audio_convertMonoToStereo(uVar8,uVar10,uVar9,iVar11);
          uVar6 = uVar9 << 1;
          goto loc_F00DD100;
        }
        if (uVar4 < 0x15) {
          if (uVar4 == 0x11) {
            _audio_swapSamples(uVar8,uVar10,param_6 >> 2);
            _audio_convertMonoToStereo(uVar10,uVar12,param_6 >> 1,iVar11);
            uVar9 = param_6 >> 1;
            goto loc_F00DD2E8;
          }
        }
        else if (uVar4 == 0x15) {
          uVar9 = param_6 >> 2;
          _audio_swapSamples(uVar8,uVar10,param_6 >> 3);
          _audio_convertMonoToStereo(uVar10,uVar12,uVar9,iVar11);
          uVar6 = uVar9 << 1;
          goto loc_F00DD248;
        }
      }
    }
  }
  else {
    if (uVar4 == 0x29) {
      param_6 = param_6 * 4;
      if (uVar6 <= param_6 && param_6 - uVar6 != 0) {
        param_6 = uVar6;
      }
      uVar4 = param_6 >> 1;
      _audio_swapSamples(uVar8,uVar10,uVar4);
      _audio_convertStereoToMono(uVar10,uVar12,param_6,iVar11,param_1 + 0x84);
      uVar8 = param_6 >> 2;
loc_F00DD200:
      _audio_resample44To22(uVar12,uVar10,uVar4,iVar11,param_1 + 0x80);
      uVar12 = uVar10;
      uVar9 = param_6;
      param_6 = uVar8;
      goto loc_F00DD2E8;
    }
    if (uVar4 < 0x2a) {
      if (uVar4 == 0x21) {
        uVar9 = param_6 * 2;
        if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
          uVar9 = uVar6;
        }
        _audio_swapSamples(uVar8,uVar10,uVar9 >> 1);
        _audio_convertStereoToMono(uVar10,uVar12,uVar9,iVar11,param_1 + 0x84);
        param_6 = uVar9 >> 1;
        goto loc_F00DD2E8;
      }
      if (uVar4 < 0x22) {
        if (uVar4 == 0x19) {
          _audio_swapSamples(uVar8,uVar10,param_6 >> 1);
          _audio_convertMonoToStereo(uVar10,uVar12,param_6,iVar11);
          uVar4 = param_6 << 1;
          uVar8 = param_6;
          goto loc_F00DD200;
        }
        if (uVar4 == 0x20) {
          uVar9 = param_6 * 2;
          if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
            uVar9 = uVar6;
          }
          _audio_convertStereoToMono(uVar8,uVar10,uVar9,iVar11,param_1 + 0x84);
          uVar12 = uVar10;
          param_6 = uVar9 >> 1;
          goto loc_F00DD2E8;
        }
      }
      else {
        if (uVar4 == 0x25) {
          uVar6 = param_6 >> 1;
          _audio_swapSamples(uVar8,uVar10,uVar6);
          _audio_convertStereoToMono(uVar10,uVar12,param_6,iVar11,param_1 + 0x84);
          goto loc_F00DD248;
        }
        if (uVar4 < 0x26) {
          if (uVar4 == 0x24) {
            _audio_convertStereoToMono(uVar8,uVar10,param_6,iVar11,param_1 + 0x84);
            uVar6 = param_6 >> 1;
            goto loc_F00DD100;
          }
        }
        else if (uVar4 == 0x28) {
          param_6 = param_6 * 4;
          if (uVar6 <= param_6 && param_6 - uVar6 != 0) {
            param_6 = uVar6;
          }
          _audio_convertStereoToMono(uVar8,uVar10,param_6,iVar11,param_1 + 0x84);
          uVar6 = param_6 >> 1;
          uVar8 = param_6 >> 2;
          goto loc_F00DCF8C;
        }
      }
      goto loc_F00DD2D8;
    }
    if (uVar4 == 0x101) {
      uVar9 = param_6 * 2;
      if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
        uVar9 = uVar6;
      }
      param_6 = uVar9 >> 1;
      _audio_swapSamples(uVar8,uVar10,param_6);
      _audio_convertLinear16ToLinear8(uVar10,uVar12,param_6,param_1 + 0x88);
      iVar11 = 3;
      goto loc_F00DD2E8;
    }
    if (uVar4 < 0x102) {
      if (uVar4 == 0x40) {
        _audio_convertLinear8ToLinear16(uVar8,uVar10,param_6 >> 1);
loc_F00DD008:
        iVar11 = 0;
        uVar12 = uVar10;
        uVar9 = param_6 >> 1;
        goto loc_F00DD2E8;
      }
      if (uVar4 == 0x80) {
        _audio_convertLinear8ToMulaw8(uVar8,uVar10,param_6);
        iVar11 = 1;
        uVar12 = uVar10;
        goto loc_F00DD2E8;
      }
    }
    else {
      if (uVar4 == 0x400) {
        _audio_convertMulaw8ToLinear16(uVar8,uVar10,param_6 >> 1);
        goto loc_F00DD008;
      }
      if (uVar4 < 0x401) {
        if (uVar4 == 0x201) {
          uVar9 = param_6 * 2;
          if (uVar6 <= uVar9 && uVar9 - uVar6 != 0) {
            uVar9 = uVar6;
          }
          param_6 = uVar9 >> 1;
          _audio_swapSamples(uVar8,uVar10,param_6);
          _audio_convertLinear16ToMulaw8(uVar10,uVar12,param_6,param_1 + 0x88);
          iVar11 = 1;
          goto loc_F00DD2E8;
        }
      }
      else if (uVar4 == 0x800) {
        _audio_convertMulaw8ToLinear8(uVar8,uVar10,param_6);
        iVar11 = 3;
        uVar12 = uVar10;
        goto loc_F00DD2E8;
      }
    }
  }
loc_F00DD2D8:
  _IOLog(aAudioUnsupport,uVar4);
  bVar2 = false;
  uVar12 = uVar8;
loc_F00DD2E8:
  if (bVar2) {
    if (*(char *)(param_1 + 0x94) != '\0') {
      if (iVar11 == 0) {
        _audio_linear16_peak
                  (*(undefined4 *)(param_1 + 0x6c),uVar12,param_6,
                   (undefined *)((int)register0x00000038 + -0x14),
                   (undefined *)((int)register0x00000038 + -0x18));
      }
      else if (iVar11 == 3) {
        _audio_linear8_peak(*(undefined4 *)(param_1 + 0x6c),uVar12,param_6,
                            (undefined *)((int)register0x00000038 + -0x14),
                            (undefined *)((int)register0x00000038 + -0x18));
      }
      else if (iVar11 == 1) {
        _audio_mulaw8_peak(*(undefined4 *)(param_1 + 0x6c),uVar12,param_6,
                           (undefined *)((int)register0x00000038 + -0x14),
                           (undefined *)((int)register0x00000038 + -0x18));
      }
    }
    _audio_mix(uVar12,param_5,param_6,iVar11,(int)cVar1);
    uVar13 = uVar12;
  }
  *(uint *)(param_3 + 8) = *(int *)(param_3 + 8) + uVar9;
  if (uVar14 < uVar13) {
    uVar14 = uVar13;
  }
  piVar5 = *(int **)(param_1 + 0x8c);
  iVar11 = *(int *)((int)register0x00000038 + -0x14);
  iVar7 = *(int *)((int)register0x00000038 + -0x18);
  if ((int *)(param_1 + 0x8c) != piVar5) {
    iVar3 = *piVar5;
    while ((param_4 != iVar3 && (iVar3 != 0))) {
      piVar5 = (int *)piVar5[5];
      if ((int *)(param_1 + 0x8c) == piVar5) goto locret_F00DD40C;
      iVar3 = *piVar5;
    }
    *piVar5 = param_4;
    piVar5[1] = uVar9;
    piVar5[2] = iVar11;
    piVar5[3] = iVar7;
    piVar5[4] = uVar14;
  }
locret_F00DD40C:
  return (qword)CONCAT14(cVar1,param_6);
}
/* GHIDRADEC_FUNCTION index=4805 start=0xf00dd414 */

/* WARNING: Removing unreachable block (ram,0xf00dd4b0) */
/* WARNING: Removing unreachable block (ram,0xf00dd4c4) */
/* WARNING: Removing unreachable block (ram,0xf00dd48c) */

undefined8
-[OutputStream completeRegion:descriptor:size:used:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined (*pauVar1) [20];
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
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
  piVar2 = *(int **)(param_1 + 0x8c);
  if ((int *)(param_1 + 0x8c) == piVar2) {
loc_F00DD470:
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2;
    while (param_4 != iVar3) {
      piVar2 = (int *)piVar2[5];
      if ((int *)(param_1 + 0x8c) == piVar2) goto loc_F00DD470;
      iVar3 = *piVar2;
    }
    iVar3 = piVar2[1];
    iVar4 = piVar2[3];
    piVar2[1] = 0;
    *(int *)((int)register0x00000038 + -0x14) = piVar2[2];
    *(int *)((int)register0x00000038 + -0x18) = iVar4;
    *(int *)((int)register0x00000038 + -0x1c) = piVar2[4];
  }
  pauVar1 = paIncrementclipc;
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar3;
  _objc_msgSend(*(undefined4 *)(param_1 + 4),pauVar1,uVar5);
  if (*(char *)(param_1 + 0x94) != '\0') {
    _audio_add_peak(*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)((int)register0x00000038 + -0x14)
                    ,param_1 + 0xa4,*(undefined4 *)(param_1 + 0x98));
    _audio_add_peak(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)((int)register0x00000038 + -0x18)
                    ,param_1 + 0xa4,*(undefined4 *)(param_1 + 0x98));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4806 start=0xf00dd4d4 */

undefined8 -[OutputStream gainLeft](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x78));
}
/* GHIDRADEC_FUNCTION index=4807 start=0xf00dd4e4 */

undefined8 -[OutputStream gainRight](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x7c));
}
/* GHIDRADEC_FUNCTION index=4808 start=0xf00dd4f4 */

undefined8 -[OutputStream setGainLeft:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x78) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4809 start=0xf00dd504 */

undefined8 -[OutputStream setGainRight:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x7c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4810 start=0xf00dd514 */

undefined8 -[OutputStream isDetectingPeaks](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x94));
}
/* GHIDRADEC_FUNCTION index=4811 start=0xf00dd524 */

/* WARNING: Removing unreachable block (ram,0xf00dd568) */
/* WARNING: Removing unreachable block (ram,0xf00dd558) */
/* WARNING: Removing unreachable block (ram,0xf00dd574) */
/* WARNING: Removing unreachable block (ram,0xf00dd54c) */

undefined8 -[OutputStream setDetectPeaks:](int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  *(char *)(param_1 + 0x94) = (char)param_3;
  if (((param_3 & 0xff) != 0) && (*(int *)(param_1 + 0x9c) == 0)) {
    uVar1 = 0x40;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0x9c) = uVar1;
    uVar1 = 0x40;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0xa0) = uVar1;
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0x9c),0x10);
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0xa0),0x10);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4812 start=0xf00dd584 */

/* WARNING: Removing unreachable block (ram,0xf00dd5ac) */
/* WARNING: Removing unreachable block (ram,0xf00dd59c) */

undefined8
-[OutputStream getPeakLeft:right:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if (*(char *)(param_1 + 0x94) == '\0') {
    *param_4 = 0;
    *param_3 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
    _audio_max_peak(uVar1,*(undefined4 *)(param_1 + 0x98));
    *param_3 = uVar1;
    uVar1 = *(undefined4 *)(param_1 + 0xa0);
    _audio_max_peak(uVar1,*(undefined4 *)(param_1 + 0x98));
    *param_4 = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4813 start=0xf00dd5c8 */

/* WARNING: Removing unreachable block (ram,0xf00dd5ec) */
/* WARNING: Removing unreachable block (ram,0xf00dd5d8) */
/* WARNING: Removing unreachable block (ram,0xf00dd610) */
/* WARNING: Removing unreachable block (ram,0xf00dd5cc) */

undefined8 -[OutputStream freeRegion:](int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
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
  iVar1 = param_1;
  _kern_serv_kernel_task_port();
  _vm_deallocate_EXTERNAL();
  if (iVar1 != 0) {
    _IOLog(aAudioStreamVmD_0,iVar1);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422f8;
  _objc_msgSendSuper(puVar2,paFreeregion,param_3);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4814 start=0xf00dd620 */

/* WARNING: Removing unreachable block (ram,0xf00dd6f8) */
/* WARNING: Removing unreachable block (ram,0xf00dd6a8) */
/* WARNING: Removing unreachable block (ram,0xf00dd64c) */
/* WARNING: Removing unreachable block (ram,0xf00dd6d8) */
/* WARNING: Removing unreachable block (ram,0xf00dd718) */
/* WARNING: Removing unreachable block (ram,0xf00dd634) */

undefined8 -[OutputStream free](int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l0;
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
  if (*(int *)(param_1 + 0xa0) == 0) {
    iVar1 = *(int *)(param_1 + 0x9c);
  }
  else {
    _IOFree(*(int *)(param_1 + 0xa0),0x40);
    iVar1 = *(int *)(param_1 + 0x9c);
  }
  if (iVar1 == 0) {
    piVar2 = *(int **)(param_1 + 0x8c);
  }
  else {
    _IOFree(iVar1,0x40);
    piVar2 = *(int **)(param_1 + 0x8c);
  }
  piVar4 = (int *)(param_1 + 0x8c);
  if (piVar4 == piVar2) {
    iVar1 = *(int *)(param_1 + 0x70);
  }
  else {
    piVar2 = *(int **)(param_1 + 0x8c);
    piVar7 = (int *)piVar2[5];
    while( true ) {
      piVar6 = (int *)piVar2[6];
      piVar5 = piVar4;
      if (piVar4 != piVar7) {
        piVar5 = piVar7 + 5;
      }
      piVar5[1] = (int)piVar6;
      piVar5 = piVar4;
      if (piVar4 != piVar6) {
        piVar5 = piVar6 + 5;
      }
      *piVar5 = (int)piVar7;
      _IOFree(piVar2,0x1c);
      piVar2 = *(int **)(param_1 + 0x8c);
      if (piVar4 == piVar2) break;
      piVar7 = (int *)piVar2[5];
    }
    iVar1 = *(int *)(param_1 + 0x70);
  }
  if (iVar1 != 0) {
    _IOFree(iVar1,_page_size << 3);
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    _IOFree(*(int *)(param_1 + 0x74),_page_size << 2);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422f8;
  _objc_msgSendSuper(puVar3,paFree);
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4815 start=0xf00dd728 */

/* WARNING: Removing unreachable block (ram,0xf00dd758) */
/* WARNING: Removing unreachable block (ram,0xf00dd768) */
/* WARNING: Removing unreachable block (ram,0xf00dd744) */

undefined8 -[AudioCommand initPort:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [16];
  undefined4 unaff_l0;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142320;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  pauVar1 = paNxconditionloc;
  _objc_msgSend(paNxconditionloc,paAlloc);
  _objc_msgSend();
  *(undefined (**) [16])(param_1 + 8) = pauVar1;
  *(undefined4 *)(param_1 + 4) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4816 start=0xf00dd780 */

/* WARNING: Removing unreachable block (ram,0xf00dd7ac) */
/* WARNING: Removing unreachable block (ram,0xf00dd790) */

undefined8 -[AudioCommand free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
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
  undefined auStackX_0 [92];
  
  uVar1 = paFree;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paFree);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142320;
  _objc_msgSendSuper(puVar2,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4817 start=0xf00dd7bc */

undefined8 -[AudioCommand command](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0xc));
}
/* GHIDRADEC_FUNCTION index=4818 start=0xf00dd7cc */

/* WARNING: Removing unreachable block (ram,0xf00dd7f0) */
/* WARNING: Removing unreachable block (ram,0xf00dd808) */
/* WARNING: Removing unreachable block (ram,0xf00dd7d8) */

undefined8 -[AudioCommand done:](int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
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
  iVar1 = *(int *)(param_1 + 8);
  _objc_msgSend(iVar1,paCondition);
  if (iVar1 == 2) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),paLock);
    *(undefined4 *)(param_1 + 0x10) = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 8),paUnlockwith,1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4819 start=0xf00dd818 */

/* WARNING: Removing unreachable block (ram,0xf00dd8a0) */
/* WARNING: Removing unreachable block (ram,0xf00dd888) */
/* WARNING: Removing unreachable block (ram,0xf00dd848) */
/* WARNING: Removing unreachable block (ram,0xf00dd878) */
/* WARNING: Removing unreachable block (ram,0xf00dd8b4) */
/* WARNING: Removing unreachable block (ram,0xf00dd8c8) */
/* WARNING: Removing unreachable block (ram,0xf00dd828) */

undefined8 -[AudioCommand send:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [10];
  undefined4 unaff_l0;
  undefined *puVar2;
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
  puVar2 = (undefined *)((int)register0x00000038 + -0x28);
  _memset(puVar2,0,0x18);
  pauVar1 = paLockwhen;
  *(uint *)((int)register0x00000038 + -0x28) = (uint)*(byte *)((int)register0x00000038 + -0x25);
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paLockwhen,3);
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x18;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x386;
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paUnlockwith,2);
  _msg_send_from_kernel(puVar2,1,1000);
  if (puVar2 == (undefined *)0x0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),pauVar1,1);
    puVar2 = *(undefined **)(param_1 + 0x10);
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),paLock);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paUnlockwith,3);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4820 start=0xf00dda44 */

/* WARNING: Removing unreachable block (ram,0xf00dded8) */
/* WARNING: Removing unreachable block (ram,0xf00ddebc) */
/* WARNING: Removing unreachable block (ram,0xf00dde90) */
/* WARNING: Removing unreachable block (ram,0xf00dde6c) */
/* WARNING: Removing unreachable block (ram,0xf00dde20) */
/* WARNING: Removing unreachable block (ram,0xf00dddf0) */
/* WARNING: Removing unreachable block (ram,0xf00ddde0) */
/* WARNING: Removing unreachable block (ram,0xf00dddb0) */
/* WARNING: Removing unreachable block (ram,0xf00ddd94) */
/* WARNING: Removing unreachable block (ram,0xf00ddd78) */
/* WARNING: Removing unreachable block (ram,0xf00ddd3c) */
/* WARNING: Removing unreachable block (ram,0xf00ddd2c) */
/* WARNING: Removing unreachable block (ram,0xf00ddd10) */
/* WARNING: Removing unreachable block (ram,0xf00ddcec) */
/* WARNING: Removing unreachable block (ram,0xf00ddccc) */
/* WARNING: Removing unreachable block (ram,0xf00ddca4) */
/* WARNING: Removing unreachable block (ram,0xf00ddc84) */
/* WARNING: Removing unreachable block (ram,0xf00ddc30) */
/* WARNING: Removing unreachable block (ram,0xf00ddbcc) */
/* WARNING: Removing unreachable block (ram,0xf00ddb9c) */
/* WARNING: Removing unreachable block (ram,0xf00ddb80) */
/* WARNING: Removing unreachable block (ram,0xf00ddb64) */
/* WARNING: Removing unreachable block (ram,0xf00ddb34) */
/* WARNING: Removing unreachable block (ram,0xf00ddb24) */
/* WARNING: Removing unreachable block (ram,0xf00ddaec) */
/* WARNING: Removing unreachable block (ram,0xf00ddad0) */
/* WARNING: Removing unreachable block (ram,0xf00ddac8) */
/* WARNING: Removing unreachable block (ram,0xf00ddad8) */
/* WARNING: Removing unreachable block (ram,0xf00ddb10) */
/* WARNING: Removing unreachable block (ram,0xf00ddb2c) */
/* WARNING: Removing unreachable block (ram,0xf00ddb48) */
/* WARNING: Removing unreachable block (ram,0xf00ddb78) */
/* WARNING: Removing unreachable block (ram,0xf00ddb88) */
/* WARNING: Removing unreachable block (ram,0xf00ddbb8) */
/* WARNING: Removing unreachable block (ram,0xf00ddc18) */
/* WARNING: Removing unreachable block (ram,0xf00ddc7c) */
/* WARNING: Removing unreachable block (ram,0xf00ddc8c) */
/* WARNING: Removing unreachable block (ram,0xf00ddcc4) */
/* WARNING: Removing unreachable block (ram,0xf00ddcd4) */
/* WARNING: Removing unreachable block (ram,0xf00ddd08) */
/* WARNING: Removing unreachable block (ram,0xf00ddd18) */
/* WARNING: Removing unreachable block (ram,0xf00ddd34) */
/* WARNING: Removing unreachable block (ram,0xf00ddd50) */
/* WARNING: Removing unreachable block (ram,0xf00ddd8c) */
/* WARNING: Removing unreachable block (ram,0xf00ddd9c) */
/* WARNING: Removing unreachable block (ram,0xf00dddcc) */
/* WARNING: Removing unreachable block (ram,0xf00ddde8) */
/* WARNING: Removing unreachable block (ram,0xf00dde04) */
/* WARNING: Removing unreachable block (ram,0xf00dde34) */
/* WARNING: Removing unreachable block (ram,0xf00dde84) */
/* WARNING: Removing unreachable block (ram,0xf00ddea8) */
/* WARNING: Removing unreachable block (ram,0xf00ddecc) */
/* WARNING: Removing unreachable block (ram,0xf00ddee4) */
/* WARNING: Removing unreachable block (ram,0xf00dda54) */

undefined8 sub_F00DDA44(int param_1,int param_2)

{
  undefined (*pauVar1) [15];
  undefined (*pauVar2) [14];
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  puVar3 = paIoaudio;
  _objc_msgSend(paIoaudio,paInstance_0);
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x18;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x14) = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    if (puVar3 == (undefined8 *)0x0) {
      uVar7 = 1;
    }
    else {
      if (dword_F012EF4C == 0) {
        iVar4 = dword_F01330E0;
        _kern_serv_port_death_proc(dword_F01330E0,_audio_port_gone);
        _task_self();
        _port_allocate_EXTERNAL();
        if (iVar4 != 0) {
          _IOLog(aAudioPortAlloc);
        }
        _outPort = *(int *)((int)register0x00000038 + -0xc);
        iVar4 = dword_F01330E0;
        _kern_serv_port_serv(dword_F01330E0,_outPort,_audioMessages,_outPort);
        puVar6 = (undefined *)0xf00fc400;
        if (iVar4 != 0) {
          puVar6 = aAudioCreateaud;
          _IOLog(aAudioCreateaud,iVar4);
        }
        _task_self();
        _port_allocate_EXTERNAL();
        if (puVar6 != (undefined *)0x0) {
          _IOLog(aAudioPortAlloc);
        }
        _inPort = *(int *)((int)register0x00000038 + -0xc);
        iVar4 = dword_F01330E0;
        _kern_serv_port_serv(dword_F01330E0,_inPort,_audioMessages,_inPort);
        puVar6 = (undefined *)0xf00fc400;
        if (iVar4 != 0) {
          puVar6 = aAudioCreateaud;
          _IOLog(aAudioCreateaud,iVar4);
        }
        _task_self();
        _port_allocate_EXTERNAL();
        if (puVar6 != (undefined *)0x0) {
          _IOLog(aAudioPortAlloc);
        }
        _sndPort = *(int *)((int)register0x00000038 + -0xc);
        iVar4 = dword_F01330E0;
        _kern_serv_port_serv(dword_F01330E0,_sndPort,_audioMessages,_sndPort);
        if (iVar4 != 0) {
          _IOLog(aAudioCreateaud,iVar4);
        }
        dword_F012EF4C = 1;
        *(undefined *)(param_2 + 3) = 0;
      }
      else {
        *(undefined *)(param_2 + 3) = 0;
      }
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x14) = 1;
      *(undefined *)(param_2 + 0x18) = 6;
      *(undefined *)(param_2 + 0x19) = 0x20;
      uVar5 = *(uint *)(param_2 + 0x18) & 0xffff0008 | 0x38;
      *(uint *)(param_2 + 0x18) = uVar5;
      _IOHostPrivSelf();
      if (uVar5 == 0) {
        _IOLog(aAudioCannotGet);
        uVar7 = 1;
      }
      else {
        if (*(uint *)(param_1 + 0x1c) == uVar5) {
          if (*(int *)(param_1 + 0x24) != 0) {
            if (_inPort != 0) {
              iVar4 = dword_F01330E0;
              _kern_serv_port_gone();
              _task_self();
              _port_deallocate_EXTERNAL();
              if (iVar4 != 0) {
                _IOLog(aAudioPortDeall);
              }
            }
            if (_outPort != 0) {
              iVar4 = dword_F01330E0;
              _kern_serv_port_gone();
              _task_self();
              _port_deallocate_EXTERNAL();
              if (iVar4 != 0) {
                _IOLog(aAudioPortDeall);
              }
            }
            puVar6 = (undefined *)&DAT_f0133000;
            if (_sndPort != 0) {
              iVar4 = dword_F01330E0;
              _kern_serv_port_gone();
              _task_self();
              _port_deallocate_EXTERNAL();
              puVar6 = (undefined *)0xf00fc000;
              if (iVar4 != 0) {
                puVar6 = aAudioPortDeall;
                _IOLog();
              }
            }
            _task_self();
            _port_allocate_EXTERNAL();
            if ((undefined4 *)puVar6 != (undefined4 *)0x0) {
              _IOLog(aAudioPortAlloc);
            }
            _outPort = *(int *)((int)register0x00000038 + -0xc);
            iVar4 = dword_F01330E0;
            _kern_serv_port_serv(dword_F01330E0,_outPort,_audioMessages,_outPort);
            puVar6 = (undefined *)0xf00fc400;
            if (iVar4 != 0) {
              puVar6 = aAudioCreateaud;
              _IOLog(aAudioCreateaud,iVar4);
            }
            _task_self();
            _port_allocate_EXTERNAL();
            if (puVar6 != (undefined *)0x0) {
              _IOLog(aAudioPortAlloc);
            }
            _inPort = *(int *)((int)register0x00000038 + -0xc);
            iVar4 = dword_F01330E0;
            _kern_serv_port_serv(dword_F01330E0,_inPort,_audioMessages,_inPort);
            puVar6 = (undefined *)0xf00fc400;
            if (iVar4 != 0) {
              puVar6 = aAudioCreateaud;
              _IOLog(aAudioCreateaud,iVar4);
            }
            _task_self();
            _port_allocate_EXTERNAL();
            if (puVar6 != (undefined *)0x0) {
              _IOLog(aAudioPortAlloc);
            }
            _sndPort = *(int *)((int)register0x00000038 + -0xc);
            iVar4 = dword_F01330E0;
            _kern_serv_port_serv(dword_F01330E0,_sndPort,_audioMessages,_sndPort);
            if (iVar4 != 0) {
              _IOLog(aAudioCreateaud,iVar4);
            }
          }
          *(int *)(param_2 + 0x1c) = _inPort;
          iVar4 = _sndPort;
          *(int *)(param_2 + 0x20) = _outPort;
          *(int *)(param_2 + 0x24) = iVar4;
        }
        else {
          *(undefined4 *)(param_2 + 0x1c) = 0;
          *(undefined4 *)(param_2 + 0x20) = 0;
          *(undefined4 *)(param_2 + 0x24) = 0;
        }
        pauVar1 = paOutputchannel;
        _objc_msgSend(puVar3,paOutputchannel);
        _objc_msgSend();
        _objc_msgSend(puVar3,pauVar1);
        _objc_msgSend();
        pauVar2 = paInputchannel;
        _objc_msgSend(puVar3,paInputchannel);
        _objc_msgSend();
        _objc_msgSend(puVar3,pauVar2);
        _objc_msgSend();
        uVar7 = 1;
      }
    }
  }
  else {
    uVar7 = 0;
  }
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=4821 start=0xf00df2a4 */

/* WARNING: Removing unreachable block (ram,0xf00df328) */

undefined8 sub_F00DF2A4(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x194;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x193;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x191;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 400;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x192;
  __NXAudioSetStreamParameters(param_2,(undefined *)((int)register0x00000038 + -0x20),5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4822 start=0xf00df338 */

/* WARNING: Removing unreachable block (ram,0xf00df3a4) */
/* WARNING: Removing unreachable block (ram,0xf00df5d8) */
/* WARNING: Removing unreachable block (ram,0xf00df830) */
/* WARNING: Removing unreachable block (ram,0xf00df890) */
/* WARNING: Removing unreachable block (ram,0xf00df8d8) */
/* WARNING: Removing unreachable block (ram,0xf00df900) */
/* WARNING: Removing unreachable block (ram,0xf00df694) */
/* WARNING: Removing unreachable block (ram,0xf00df544) */
/* WARNING: Removing unreachable block (ram,0xf00df4e4) */
/* WARNING: Removing unreachable block (ram,0xf00df530) */
/* WARNING: Removing unreachable block (ram,0xf00df518) */
/* WARNING: Removing unreachable block (ram,0xf00df524) */
/* WARNING: Removing unreachable block (ram,0xf00df4d8) */
/* WARNING: Removing unreachable block (ram,0xf00df4f0) */
/* WARNING: Removing unreachable block (ram,0xf00df66c) */
/* WARNING: Removing unreachable block (ram,0xf00df6bc) */
/* WARNING: Removing unreachable block (ram,0xf00df8c0) */
/* WARNING: Removing unreachable block (ram,0xf00df84c) */
/* WARNING: Removing unreachable block (ram,0xf00df814) */
/* WARNING: Removing unreachable block (ram,0xf00df934) */
/* WARNING: Removing unreachable block (ram,0xf00df5e8) */
/* WARNING: Removing unreachable block (ram,0xf00df3b8) */
/* WARNING: Removing unreachable block (ram,0xf00df384) */

undefined8 sub_F00DF338(undefined4 param_1,int param_2)

{
  undefined (*pauVar1) [13];
  undefined (*pauVar2) [13];
  undefined4 uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar5;
  undefined4 unaff_l4;
  int iVar6;
  undefined4 unaff_l5;
  undefined4 uVar7;
  undefined4 unaff_l6;
  undefined4 uVar8;
  undefined4 unaff_l7;
  undefined4 uVar9;
  undefined4 unaff_i0;
  int iVar10;
  int iVar11;
  undefined4 unaff_i1;
  int iVar12;
  undefined4 unaff_i2;
  int iVar13;
  undefined4 unaff_i3;
  undefined4 uVar14;
  undefined4 unaff_i4;
  uint uVar15;
  undefined4 unaff_i5;
  int iVar16;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar17;
  bool bVar18;
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  uVar15 = 0;
  uVar5 = 0;
  iVar16 = 0;
  iVar13 = -1;
  iVar10 = 0;
  uVar9 = 0;
  uVar7 = 0;
  iVar6 = *(int *)((int)register0x00000038 + -0x34);
  uVar8 = 0;
  uVar3 = *(undefined4 *)(iVar6 + 0xc);
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
  uVar14 = *(undefined4 *)(iVar6 + 0x1c);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
  pauVar1 = paAudiochannel;
  _objc_msgSend(paAudiochannel,paStreamforuserp,uVar3);
  uVar3 = paChannel;
  *(undefined4 *)((int)register0x00000038 + -0x54) = 0;
  if (*(int *)(iVar6 + 0x14) == 1) {
    __NXAudioStreamInfo();
    _audio_snd_reply_ret_samples
              (param_2,*(undefined4 *)(iVar6 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x14),
               *(undefined4 *)((int)register0x00000038 + -0x18));
  }
  else {
    iVar12 = *(int *)(iVar6 + 4) + -0x28;
    *(int *)((int)register0x00000038 + -0x1c) = iVar6 + 0x28;
    iVar11 = iVar10;
    if (0 < iVar12) {
      iVar10 = *(int *)((int)register0x00000038 + -0x1c);
      do {
        switch(*(undefined4 *)(iVar10 + 4)) {
        case :
          iVar12 = iVar12 + -0x28;
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x28;
          if ((iVar16 == 0) && (iVar13 == 1)) {
            iVar16 = 0x67;
          }
          iVar13 = 0;
          break;
        case :
          iVar10 = (*(uint *)(*(int *)((int)register0x00000038 + -0x1c) + 0x1c) >> 4 & 0xfff) + 0x20
          ;
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + iVar10;
          iVar12 = iVar12 - iVar10;
          break;
        case :
          iVar10 = *(int *)((int)register0x00000038 + -0x1c);
          iVar11 = *(int *)(iVar10 + 0xc);
          uVar9 = *(undefined4 *)(iVar10 + 0x10);
          *(int *)((int)register0x00000038 + -0x1c) = iVar10 + 0x18;
          _objc_msgSend(pauVar1,uVar3);
          __NXAudioGetBufferOptions();
          _objc_msgSend(pauVar1,uVar3);
          iVar12 = iVar12 + -0x18;
          goto loc_F00DF544;
        case :
          iVar12 = iVar12 + -0x10;
          uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0x1c) + 0xc);
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x10;
          uVar15 = uVar15 | uVar4;
          break;
        case :
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x10;
          _objc_msgSend(pauVar1,uVar3);
          __NXAudioGetBufferOptions();
          _objc_msgSend(pauVar1,uVar3);
          iVar12 = iVar12 + -0x10;
loc_F00DF544:
          __NXAudioSetBufferOptions();
          break;
        case :
          iVar10 = *(int *)((int)register0x00000038 + -0x1c);
          *(undefined4 *)((int)register0x00000038 + -0x44) = *(undefined4 *)(iVar10 + 0x10);
          *(undefined4 *)((int)register0x00000038 + -0x54) = 1;
          iVar12 = iVar12 + -0x18;
          uVar8 = *(undefined4 *)(iVar10 + 0xc);
          *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar10 + 0x14);
          *(int *)((int)register0x00000038 + -0x1c) = iVar10 + 0x18;
          break;
        :
          iVar16 = 0x66;
          iVar12 = 0;
        }
        iVar10 = *(int *)((int)register0x00000038 + -0x1c);
      } while (0 < iVar12);
    }
    iVar10 = iVar16;
    if (iVar10 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      if ((uVar15 & 2) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
        __NXAudioStreamControl(pauVar1,2,(undefined *)((int)register0x00000038 + -0x30));
      }
      if ((uVar15 & 1) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar1,3,(undefined *)((int)register0x00000038 + -0x30));
      }
      if ((uVar15 & 4) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar1,0,(undefined *)((int)register0x00000038 + -0x30));
      }
      param_2 = *(int *)(*(int *)((int)register0x00000038 + -0x34) + 4) + -0x28;
      *(int *)((int)register0x00000038 + -0x1c) = iVar6 + 0x28;
      if (0 < param_2) {
        iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        do {
          iVar6 = 0;
          switch(*(undefined4 *)(iVar16 + 4)) {
          case :
            iVar16 = *(int *)((int)register0x00000038 + -0x1c);
            uVar5 = *(uint *)(iVar16 + 0xc);
            iVar6 = *(int *)(iVar16 + 0x20);
            param_2 = param_2 + -0x28;
            uVar7 = *(undefined4 *)(iVar16 + 0x14);
            *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(iVar16 + 0x24);
            iVar16 = iVar16 + 0x28;
            break;
          case :
            iVar16 = *(int *)((int)register0x00000038 + -0x1c);
            uVar5 = *(uint *)(iVar16 + 0xc);
            iVar6 = *(int *)(iVar16 + 0x10);
            uVar7 = *(undefined4 *)(iVar16 + 0x18);
            param_2 = param_2 + -0x20;
            iVar16 = iVar16 + 0x20;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          case :
          case :
            param_2 = param_2 + -0x10;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x10;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          :
            goto def_F00DF704;
          }
          *(int *)((int)register0x00000038 + -0x1c) = iVar16;
def_F00DF704:
          if (iVar6 != 0) {
            uVar4 = uVar5 & 1;
            if ((iVar13 == 0) && ((uVar5 & 2) != 0)) {
              uVar4 = uVar4 | 2;
            }
            if ((uVar5 & 8) != 0) {
              uVar4 = uVar4 | 4;
            }
            if ((uVar5 & 0x10) != 0) {
              uVar4 = uVar4 | 8;
            }
            if ((uVar5 & 4) != 0) {
              uVar4 = uVar4 | 0x10;
            }
            if ((uVar5 & 0x20) != 0) {
              uVar4 = uVar4 | 0x20;
            }
            if (iVar13 == 0) {
              if (*(int *)((int)register0x00000038 + -0x54) == 0) {
                uVar8 = 2;
                pauVar2 = pauVar1;
                _objc_msgSend(pauVar1,paType);
                if (pauVar2 == (undefined (*) [13])0x3) {
                  uVar8 = 1;
                }
                __NXAudioPlayStream(pauVar1,*(undefined4 *)((int)register0x00000038 + -0x3c),iVar6,
                                    uVar14,2,uVar8,0x8000,0x8000,uVar9,iVar11,uVar7,uVar4);
              }
              else {
                sub_F00DF2A4(0,pauVar1,uVar8,*(undefined4 *)((int)register0x00000038 + -0x44),
                             *(undefined4 *)((int)register0x00000038 + -0x4c),uVar9,iVar11);
                __NXAudioPlayStreamData
                          (pauVar1,*(undefined4 *)((int)register0x00000038 + -0x3c),iVar6,uVar14,
                           uVar7,uVar4);
              }
            }
            else if (*(int *)((int)register0x00000038 + -0x54) == 0) {
              __NXAudioRecordStream(pauVar1,iVar6,uVar14,uVar9,iVar11,uVar7,uVar4);
            }
            else {
              sub_F00DF2A4(iVar13,pauVar1,uVar8,*(undefined4 *)((int)register0x00000038 + -0x44),
                           *(undefined4 *)((int)register0x00000038 + -0x4c),uVar9,iVar11);
              __NXAudioRecordStreamData(pauVar1,iVar6,uVar14,uVar7,uVar4);
            }
          }
          iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        } while (0 < param_2);
      }
      if ((uVar15 & 8) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar1,1,(undefined *)((int)register0x00000038 + -0x30));
      }
      iVar10 = 100;
    }
    else {
      param_2 = *(int *)(*(int *)((int)register0x00000038 + -0x34) + 4) + -0x28;
      *(int *)((int)register0x00000038 + -0x1c) = iVar6 + 0x28;
      if (0 < param_2) {
        iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        do {
          switch(*(undefined4 *)(iVar16 + 4)) {
          case :
            *(int *)((int)register0x00000038 + -0x1c) =
                 *(int *)((int)register0x00000038 + -0x1c) + 0x28;
            _IOVmTaskSelf();
            param_2 = param_2 + -0x28;
            _vm_deallocate_EXTERNAL();
            bVar18 = param_2 == 0;
            bVar17 = param_2 < 0;
            goto def_F00DF5B0;
          case :
            param_2 = param_2 + -0x20;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x20;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          case :
          case :
            param_2 = param_2 + -0x10;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x10;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          :
            bVar18 = param_2 == 0;
            bVar17 = param_2 < 0;
            goto def_F00DF5B0;
          }
          *(int *)((int)register0x00000038 + -0x1c) = iVar16;
          bVar18 = param_2 == 0;
          bVar17 = param_2 < 0;
def_F00DF5B0:
          iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        } while (!bVar18 && !bVar17);
      }
    }
  }
  return CONCAT44(param_2,iVar10);
}
/* GHIDRADEC_FUNCTION index=4823 start=0xf00df950 */

/* WARNING: Removing unreachable block (ram,0xf00dfa9c) */
/* WARNING: Removing unreachable block (ram,0xf00dfa04) */
/* WARNING: Removing unreachable block (ram,0xf00dfa60) */
/* WARNING: Removing unreachable block (ram,0xf00dfaec) */
/* WARNING: Removing unreachable block (ram,0xf00dfbb8) */
/* WARNING: Removing unreachable block (ram,0xf00dfb74) */
/* WARNING: Removing unreachable block (ram,0xf00dfc20) */
/* WARNING: Removing unreachable block (ram,0xf00dfc70) */
/* WARNING: Removing unreachable block (ram,0xf00e01d0) */
/* WARNING: Removing unreachable block (ram,0xf00e0274) */
/* WARNING: Removing unreachable block (ram,0xf00e025c) */
/* WARNING: Removing unreachable block (ram,0xf00e0220) */
/* WARNING: Removing unreachable block (ram,0xf00e0204) */
/* WARNING: Removing unreachable block (ram,0xf00e02a4) */
/* WARNING: Removing unreachable block (ram,0xf00e012c) */
/* WARNING: Removing unreachable block (ram,0xf00e00f0) */
/* WARNING: Removing unreachable block (ram,0xf00dfe38) */
/* WARNING: Removing unreachable block (ram,0xf00dfce4) */
/* WARNING: Removing unreachable block (ram,0xf00dff08) */
/* WARNING: Removing unreachable block (ram,0xf00e003c) */
/* WARNING: Removing unreachable block (ram,0xf00dfd04) */
/* WARNING: Removing unreachable block (ram,0xf00e00c8) */
/* WARNING: Removing unreachable block (ram,0xf00e0120) */
/* WARNING: Removing unreachable block (ram,0xf00e02e0) */
/* WARNING: Removing unreachable block (ram,0xf00e02f4) */
/* WARNING: Removing unreachable block (ram,0xf00e0218) */
/* WARNING: Removing unreachable block (ram,0xf00e0244) */
/* WARNING: Removing unreachable block (ram,0xf00e0264) */
/* WARNING: Removing unreachable block (ram,0xf00e01ac) */
/* WARNING: Removing unreachable block (ram,0xf00dfc64) */
/* WARNING: Removing unreachable block (ram,0xf00dfcb4) */
/* WARNING: Removing unreachable block (ram,0xf00dfc30) */
/* WARNING: Removing unreachable block (ram,0xf00dfb7c) */
/* WARNING: Removing unreachable block (ram,0xf00dfae0) */
/* WARNING: Removing unreachable block (ram,0xf00e017c) */
/* WARNING: Removing unreachable block (ram,0xf00dfa74) */
/* WARNING: Removing unreachable block (ram,0xf00dfa18) */
/* WARNING: Removing unreachable block (ram,0xf00dfab0) */
/* WARNING: Removing unreachable block (ram,0xf00dfee8) */

undefined8 sub_F00DF950(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
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
  int aiStack_438 [270];
  
  iVar3 = paIoaudio;
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
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  uVar7 = 0;
  iVar4 = paAudiochannel;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      uVar9 = 0x67;
      break;
    }
    iVar3 = paIoaudio;
    if (*(int *)(param_1 + 0x1c) == 0x82) {
      _objc_msgSend(paIoaudio,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
      iVar4 = iVar3;
      _objc_msgSend();
      *(int *)((int)register0x00000038 + -0x14) = iVar4;
      if (iVar4 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x24);
        uVar9 = 1;
loc_F00DFA9C:
        __NXAudioAddStream(iVar3,(undefined *)((int)register0x00000038 + -0x14),uVar2,0,uVar9);
      }
    }
    else {
      uVar9 = 4;
      if (*(int *)(param_1 + 0x1c) == 0x81) {
        uVar9 = 3;
      }
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      iVar4 = iVar3;
      _objc_msgSend();
      *(int *)((int)register0x00000038 + -0x14) = iVar4;
      if (iVar4 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x24);
        goto loc_F00DFA9C;
      }
    }
    _audio_snd_reply_ret_stream
              (param_2,*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x14));
    uVar9 = 0;
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    __NXAudioGetSndoutOptions();
    if ((*(uint *)(param_1 + 0x1c) & 4) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffe;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 1;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if ((*(uint *)(param_1 + 0x1c) & 2) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xffffffef;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 0x10;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffff7;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 8;
    }
    goto loc_F00E0170;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSndoutOptions();
      uVar6 = *(uint *)((int)register0x00000038 + -0x18);
      if ((uVar6 & 1) != 0) {
        uVar7 = 4;
      }
      if ((uVar6 & 0x10) != 0) {
        uVar7 = uVar7 | 2;
      }
      if ((uVar6 & 8) != 0) {
        uVar7 = uVar7 | 1;
      }
      _audio_snd_reply_ret_parms(param_2,*(undefined4 *)(param_1 + 0x10),uVar7);
      uVar9 = 0;
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      uVar6 = *(uint *)(param_1 + 0x1c);
      uVar9 = *(undefined4 *)(param_1 + 0xc);
      uVar7 = (uVar6 & 0xff00) >> 8;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar7;
      uVar6 = uVar6 & 0xff;
      *(uint *)((int)register0x00000038 + -0x20) = uVar6;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar7 * 2 + -0x56;
      *(uint *)((int)register0x00000038 + -0x20) = uVar6 * 2 + -0x56;
      _objc_msgSend(paIoaudio,paOutputchannelf,uVar9);
      __NXAudioSetSpeaker();
      uVar9 = 100;
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSpeaker();
      iVar4 = *(int *)((int)register0x00000038 + -0x1c);
      uVar9 = *(undefined4 *)(param_1 + 0x10);
      *(int *)((int)register0x00000038 + -0x1c) = iVar4 / 2 + 0x2b;
      iVar3 = *(int *)((int)register0x00000038 + -0x20);
      *(uint *)((int)register0x00000038 + -0x20) = iVar3 / 2 + 0x2bU;
      _audio_snd_reply_ret_volume(param_2,uVar9,(iVar4 / 2 + 0x2b) * 0x100 | iVar3 / 2 + 0x2bU);
      uVar9 = 0;
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
  case :
  case :
  case :
    uVar9 = 0x6c;
    break;
  case :
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      uVar9 = 0x67;
      break;
    }
    iVar3 = paAudiochannel;
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x24));
    if (iVar3 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x440) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x43c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      __NXAudioStreamControl();
      uVar9 = 100;
      break;
    }
  :
    uVar9 = 100;
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      iVar4 = paIoaudio;
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      iVar1 = iVar4;
      _objc_msgSend(iVar4,paAudiodevice);
      _audio_reset_snd_dev_port();
      if (iVar1 == 0) {
        uVar9 = 0x70;
      }
      else {
        _objc_msgSend(iVar4,paRemovesndstrea);
        _objc_msgSend(iVar3,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
        _objc_msgSend();
        _audio_snd_reply_ret_device(param_2,*(undefined4 *)(param_1 + 0x10),iVar1);
        uVar9 = 0;
      }
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x1c));
    goto joined_r0xf00e02ec;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x1c));
joined_r0xf00e02ec:
    uVar9 = 0x6a;
    if (iVar4 != 0) {
      uVar9 = 100;
      __NXAudioRemoveStream();
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    __NXAudioGetSndoutOptions();
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffd;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 2;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if ((*(uint *)(param_1 + 0x1c) & 2) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffb;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 4;
    }
loc_F00E0170:
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    __NXAudioSetSndoutOptions(iVar3,0,*(undefined4 *)((int)register0x00000038 + -0x18));
    uVar9 = 100;
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x18) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    puVar8 = (undefined *)((int)register0x00000038 + -0x38);
    __NXAudioGetSamplingRates();
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    if (*(int *)((int)register0x00000038 + -0x43c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    }
    iVar4 = 0;
    puVar5 = puVar8;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar5 + -0x400);
        uVar7 = *(uint *)((int)register0x00000038 + -0x24);
        if (iVar1 - 8000U < 0xe) {
          uVar7 = uVar7 | 2;
loc_F00DFE1C:
          *(uint *)((int)register0x00000038 + -0x24) = uVar7;
        }
        else {
          if (iVar1 == 0x5622) {
            uVar7 = uVar7 | 0x10;
            goto loc_F00DFE1C;
          }
          if (iVar1 < 0x5623) {
            if (iVar1 == 0x2b11) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 4;
            }
            else {
              uVar7 = uVar7 | 8;
              if (iVar1 != 16000) goto loc_F00DFE24;
            }
            goto loc_F00DFE1C;
          }
          if (iVar1 == 0xac44) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x40;
            goto loc_F00DFE1C;
          }
          if (iVar1 < 0xac45) {
            if (iVar1 == 32000) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x20;
              goto loc_F00DFE1C;
            }
          }
          else if (iVar1 == 48000) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x80;
            goto loc_F00DFE1C;
          }
        }
loc_F00DFE24:
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
    __NXAudioGetDataEncodings
              (iVar3,(undefined *)((int)register0x00000038 + -0x438),
               (undefined *)((int)register0x00000038 + -0x440));
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    iVar4 = 0;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar8 + -0x400);
        if (iVar1 == 0x259) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 2;
loc_F00DFEAC:
          *(uint *)((int)register0x00000038 + -0x30) = uVar7;
        }
        else if (iVar1 < 0x25a) {
          if (iVar1 == 600) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 4;
            goto loc_F00DFEAC;
          }
        }
        else if (iVar1 == 0x25a) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 1;
          goto loc_F00DFEAC;
        }
        iVar4 = iVar4 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
    goto loc_F00E00C8;
  case :
    if (*(int *)(param_1 + 4) != 0x18) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
    puVar8 = (undefined *)((int)register0x00000038 + -0x38);
    __NXAudioGetSamplingRates();
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    if (*(int *)((int)register0x00000038 + -0x43c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    }
    iVar4 = 0;
    puVar5 = puVar8;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar5 + -0x400);
        uVar7 = *(uint *)((int)register0x00000038 + -0x24);
        if (iVar1 - 8000U < 0xe) {
          uVar7 = uVar7 | 2;
loc_F00E0020:
          *(uint *)((int)register0x00000038 + -0x24) = uVar7;
        }
        else {
          if (iVar1 == 0x5622) {
            uVar7 = uVar7 | 0x10;
            goto loc_F00E0020;
          }
          if (iVar1 < 0x5623) {
            if (iVar1 == 0x2b11) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 4;
            }
            else {
              uVar7 = uVar7 | 8;
              if (iVar1 != 16000) goto loc_F00E0028;
            }
            goto loc_F00E0020;
          }
          if (iVar1 == 0xac44) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x40;
            goto loc_F00E0020;
          }
          if (iVar1 < 0xac45) {
            if (iVar1 == 32000) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x20;
              goto loc_F00E0020;
            }
          }
          else if (iVar1 == 48000) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x80;
            goto loc_F00E0020;
          }
        }
loc_F00E0028:
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
    __NXAudioGetDataEncodings
              (iVar3,(undefined *)((int)register0x00000038 + -0x438),
               (undefined *)((int)register0x00000038 + -0x440));
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    iVar4 = 0;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar8 + -0x400);
        if (iVar1 == 0x259) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 2;
loc_F00E00B0:
          *(uint *)((int)register0x00000038 + -0x30) = uVar7;
        }
        else if (iVar1 < 0x25a) {
          if (iVar1 == 600) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 4;
            goto loc_F00E00B0;
          }
        }
        else if (iVar1 == 0x25a) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 1;
          goto loc_F00E00B0;
        }
        iVar4 = iVar4 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
loc_F00E00C8:
    __NXAudioGetChannelCountLimit(iVar3,(undefined *)((int)register0x00000038 + -0x34));
    _audio_snd_reply_ret_formats
              (param_2,*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x24),
               *(undefined4 *)((int)register0x00000038 + -0x28),
               *(undefined4 *)((int)register0x00000038 + -0x2c),
               *(undefined4 *)((int)register0x00000038 + -0x30),
               *(undefined4 *)((int)register0x00000038 + -0x34));
    uVar9 = 0;
  }
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=4824 start=0xf00e2890 */

undefined8 sub_F00E2890(int *param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = 1;
  if (*(sword *)(*param_1 + 2) <= *(sword *)(*param_2 + 2)) {
    iVar1 = -(uint)(*(sword *)(*param_1 + 2) != *(sword *)(*param_2 + 2));
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4825 start=0xf00e2e04 */

/* WARNING: Removing unreachable block (ram,0xf00e2e48) */

undefined8 sub_F00E2E04(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvOpen(uVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4826 start=0xf00e2e78 */

/* WARNING: Removing unreachable block (ram,0xf00e2ebc) */

undefined8 sub_F00E2E78(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvClose(uVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4827 start=0xf00e2eec */

/* WARNING: Removing unreachable block (ram,0xf00e2f6c) */

undefined8 sub_F00E2EEC(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x6200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvMapEventShmem(uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                       *(undefined4 *)(param_1 + 0x2c),param_2 + 0x24);
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4828 start=0xf00e2fa8 */

/* WARNING: Removing unreachable block (ram,0xf00e3028) */

undefined8 sub_F00E2FA8(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0xa8) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x8080408)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 100) == 0x8080408)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvFrameBufferDevicePort
                (uVar1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,param_1 + 0x68,param_2 + 0x24)
      ;
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 0;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x6200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4829 start=0xf00e3060 */

/* WARNING: Removing unreachable block (ram,0xf00e30c0) */

undefined8 sub_F00E3060(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x6200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvSetSpecialKeyPort(uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4830 start=0xf00e30f0 */

/* WARNING: Removing unreachable block (ram,0xf00e317c) */

undefined8 sub_F00E30F0(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x6c) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x2200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x8080408)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 100) == 0x2200018)) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0x40;
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvGetParameterInt(uVar1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,
                         *(undefined4 *)(param_1 + 0x68),param_2 + 0x24,
                         (undefined *)((int)register0x00000038 + -0xc));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2200408;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4831 start=0xf00e31dc */

/* WARNING: Removing unreachable block (ram,0xf00e3268) */

undefined8 sub_F00E31DC(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x6c) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x2200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x8080408)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 100) == 0x2200018)) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0x1000;
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvGetParameterChar(uVar1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,
                          *(undefined4 *)(param_1 + 0x68),param_2 + 0x2c,
                          (undefined *)((int)register0x00000038 + -0xc));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0xc;
      *(undefined4 *)(param_2 + 0x24) = 0x80008;
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x28) = 0x1000;
      *(int *)(param_2 + 0x28) = iVar2;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = (iVar2 + 3U & 0xfffffffc) + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4832 start=0xf00e32c8 */

/* WARNING: Removing unreachable block (ram,0xf00e3370) */

undefined8 sub_F00E32C8(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) - 0x68U < 0x101) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x8080408)) {
      uVar1 = 0xfffffed0;
      if (((*(uint *)(param_1 + 100) & 0xffff000c) == 0x2200008) &&
         (uVar1 = 0xfffffed0,
         *(int *)(param_1 + 4) == (*(uint *)(param_1 + 100) >> 4 & 0xfff) * 4 + 0x68)) {
        uVar1 = *(undefined4 *)(param_1 + 0xc);
        _EvSetParameterInt(uVar1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,param_1 + 0x68);
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4833 start=0xf00e33a0 */

/* WARNING: Removing unreachable block (ram,0xf00e3454) */

undefined8 sub_F00E33A0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) - 0x70U < 0x1001) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((((*(int *)(param_1 + 0x18) == 0x2200018) &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x8080408)) &&
        (uVar1 = 0xfffffed0, (*(uint *)(param_1 + 100) & 0xc) == 0xc)) &&
       ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x68) == 0x80008 &&
        (uVar1 = 0xfffffed0,
        *(int *)(param_1 + 4) == (*(int *)(param_1 + 0x6c) + 3U & 0xfffffffc) + 0x70)))) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvSetParameterChar(uVar1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,param_1 + 0x70);
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4834 start=0xf00e3514 */

/* WARNING: Removing unreachable block (ram,0xf00e3548) */
/* WARNING: Removing unreachable block (ram,0xf00e3540) */

undefined8 sub_F00E3514(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetExclusiveUser();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 0;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x6200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4835 start=0xf00e357c */

/* WARNING: Removing unreachable block (ram,0xf00e35c4) */
/* WARNING: Removing unreachable block (ram,0xf00e35bc) */

undefined8 sub_F00E357C(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioSetExclusiveUser();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4836 start=0xf00e35f4 */

/* WARNING: Removing unreachable block (ram,0xf00e362c) */
/* WARNING: Removing unreachable block (ram,0xf00e3620) */

undefined8 sub_F00E35F4(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetBufferOptions();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4837 start=0xf00e3670 */

/* WARNING: Removing unreachable block (ram,0xf00e36f0) */
/* WARNING: Removing unreachable block (ram,0xf00e36e0) */

undefined8 sub_F00E3670(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioSetBufferOptions();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4838 start=0xf00e3720 */

/* WARNING: Removing unreachable block (ram,0xf00e3784) */
/* WARNING: Removing unreachable block (ram,0xf00e3778) */

undefined8 sub_F00E3720(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x6200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioControlStreams();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4839 start=0xf00e37b4 */

/* WARNING: Removing unreachable block (ram,0xf00e3838) */
/* WARNING: Removing unreachable block (ram,0xf00e3824) */

undefined8 sub_F00E37B4(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioAddStream();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 0;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x6200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4840 start=0xf00e3870 */

/* WARNING: Removing unreachable block (ram,0xf00e38a8) */
/* WARNING: Removing unreachable block (ram,0xf00e389c) */

undefined8 sub_F00E3870(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetDevicePeakOptions();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4841 start=0xf00e38ec */

/* WARNING: Removing unreachable block (ram,0xf00e396c) */
/* WARNING: Removing unreachable block (ram,0xf00e395c) */

undefined8 sub_F00E38EC(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioSetDevicePeakOptions();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4842 start=0xf00e399c */

/* WARNING: Removing unreachable block (ram,0xf00e39d4) */
/* WARNING: Removing unreachable block (ram,0xf00e39c8) */

undefined8 sub_F00E399C(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetDevicePeak();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4843 start=0xf00e3a18 */

/* WARNING: Removing unreachable block (ram,0xf00e3a4c) */
/* WARNING: Removing unreachable block (ram,0xf00e3a44) */

undefined8 sub_F00E3A18(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetClipCount();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4844 start=0xf00e3a84 */

/* WARNING: Removing unreachable block (ram,0xf00e3ab8) */
/* WARNING: Removing unreachable block (ram,0xf00e3ab0) */

undefined8 sub_F00E3A84(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetSndoutOptions();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4845 start=0xf00e3af0 */

/* WARNING: Removing unreachable block (ram,0xf00e3b54) */
/* WARNING: Removing unreachable block (ram,0xf00e3b48) */

undefined8 sub_F00E3AF0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x6200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioSetSndoutOptions();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4846 start=0xf00e3b84 */

/* WARNING: Removing unreachable block (ram,0xf00e3bbc) */
/* WARNING: Removing unreachable block (ram,0xf00e3bb0) */

undefined8 sub_F00E3B84(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetSpeaker();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4847 start=0xf00e3c00 */

/* WARNING: Removing unreachable block (ram,0xf00e3c80) */
/* WARNING: Removing unreachable block (ram,0xf00e3c70) */

undefined8 sub_F00E3C00(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioSetSpeaker();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4848 start=0xf00e3cb0 */

/* WARNING: Removing unreachable block (ram,0xf00e3d14) */
/* WARNING: Removing unreachable block (ram,0xf00e3d08) */

undefined8 sub_F00E3CB0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioSetStreamGain();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4849 start=0xf00e3d44 */

/* WARNING: Removing unreachable block (ram,0xf00e3d8c) */
/* WARNING: Removing unreachable block (ram,0xf00e3d84) */

undefined8 sub_F00E3D44(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioChangeStreamOwner();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}

