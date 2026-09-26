
/* WARNING: Removing unreachable block (ram,0xf00ce374) */
/* WARNING: Removing unreachable block (ram,0xf00ce358) */
/* WARNING: Removing unreachable block (ram,0xf00ce344) */
/* WARNING: Removing unreachable block (ram,0xf00ce364) */
/* WARNING: Removing unreachable block (ram,0xf00ce3a4) */
/* WARNING: Removing unreachable block (ram,0xf00ce32c) */

undefined8 -[SCSIDisk initResources](int param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [16];
  undefined (*pauVar3) [16];
  code *pcVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  int iVar6;
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
  *(int *)(param_1 + 0x1ac) = param_1 + 0x1a8;
  *(int *)(param_1 + 0x1a8) = param_1 + 0x1a8;
  *(int *)(param_1 + 0x1b4) = param_1 + 0x1b0;
  *(int *)(param_1 + 0x1b0) = param_1 + 0x1b0;
  pauVar3 = paNxconditionloc;
  puVar1 = paAlloc;
  iVar6 = 0;
  pauVar2 = paNxconditionloc;
  _objc_msgSend(paNxconditionloc,paAlloc);
  *(undefined (**) [16])(param_1 + 0x1b8) = pauVar2;
  _objc_msgSend();
  _objc_msgSend(param_1,paSetlastreadyst,1);
  _objc_msgSend(pauVar3,puVar1);
  *(undefined (**) [16])(param_1 + 0x1c0) = pauVar3;
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) & 0xffff3fff;
  iVar5 = param_1;
  do {
    pcVar4 = _sdIoThread;
    _IOForkThread(_sdIoThread,param_1);
    *(code **)(iVar5 + 400) = pcVar4;
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 1;
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 1;
  } while (iVar6 < 1);
  return CONCAT44(param_2,param_1);
}

