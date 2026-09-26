
/* WARNING: Removing unreachable block (ram,0xf00d7e40) */
/* WARNING: Removing unreachable block (ram,0xf00d7e08) */
/* WARNING: Removing unreachable block (ram,0xf00d7dd0) */
/* WARNING: Removing unreachable block (ram,0xf00d7da0) */
/* WARNING: Removing unreachable block (ram,0xf00d7db8) */
/* WARNING: Removing unreachable block (ram,0xf00d7dec) */
/* WARNING: Removing unreachable block (ram,0xf00d7e28) */
/* WARNING: Removing unreachable block (ram,0xf00d7e58) */
/* WARNING: Removing unreachable block (ram,0xf00d7d84) */

undefined8 -[IOAudio _attemptToStopDMAForChannel:](int param_1,undefined4 param_2,uint param_3)

{
  undefined (*pauVar1) [13];
  int iVar2;
  uint uVar3;
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
  iVar2 = param_1;
  _objc_msgSend(param_1,paSamplerate_0);
  *(int *)((int)register0x00000038 + -0x14) = iVar2;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x148);
  iVar2 = param_1;
  _objc_msgSend(param_1,paChannelcount_0);
  pauVar1 = paEnqueuecount;
  *(int *)((int)register0x00000038 + -0x1c) = iVar2;
  uVar3 = param_3;
  _objc_msgSend(param_3,paEnqueuecount);
  if (uVar3 != 0) {
    _objc_msgSend(param_3,paDequeuedescrip);
  }
  uVar3 = param_3;
  _objc_msgSend(param_3,paEnqueuedescrip,(undefined *)((int)register0x00000038 + -0x14),
                (undefined *)((int)register0x00000038 + -0x18),
                (undefined *)((int)register0x00000038 + -0x1c));
  if ((uVar3 & 0xff) == 0) {
    uVar3 = param_3;
    _objc_msgSend(param_3,pauVar1);
    if (uVar3 == 0) {
      _objc_msgSend(param_1,paStopdmaforchan_0,param_3);
      _objc_msgSend(param_1,paSetoutputstart,0,0);
      _objc_msgSend(param_1,paSetlastinterru,0,0);
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}

