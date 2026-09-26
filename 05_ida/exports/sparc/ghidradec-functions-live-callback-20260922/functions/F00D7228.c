
/* WARNING: Removing unreachable block (ram,0xf00d733c) */
/* WARNING: Removing unreachable block (ram,0xf00d72e0) */
/* WARNING: Removing unreachable block (ram,0xf00d7304) */
/* WARNING: Removing unreachable block (ram,0xf00d739c) */
/* WARNING: Removing unreachable block (ram,0xf00d7370) */
/* WARNING: Removing unreachable block (ram,0xf00d7260) */
/* WARNING: Removing unreachable block (ram,0xf00d7270) */
/* WARNING: Removing unreachable block (ram,0xf00d7384) */
/* WARNING: Removing unreachable block (ram,0xf00d73a4) */
/* WARNING: Removing unreachable block (ram,0xf00d72d0) */
/* WARNING: Removing unreachable block (ram,0xf00d731c) */
/* WARNING: Removing unreachable block (ram,0xf00d735c) */
/* WARNING: Removing unreachable block (ram,0xf00d724c) */

void sub_F00D7228(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined (*pauVar5) [15];
  undefined (*pauVar6) [19];
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
loc_F00D7240:
  while( true ) {
    while( true ) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
      uVar1 = param_1;
      _objc_msgSend(param_1,paDeviceportset);
      *(uint *)((int)register0x00000038 + -0x14) = uVar1;
      uVar1 = param_1;
      _objc_msgSend(param_1,paTimeout);
      puVar2 = (undefined *)((int)register0x00000038 + -0x20);
      _msg_receive((undefined *)((int)register0x00000038 + -0x20),0x100,uVar1);
      if (puVar2 == (undefined *)0xffffff35) goto loc_F00D7314;
      if (puVar2 == (undefined *)0x0) break;
      uVar1 = param_1;
      _objc_msgSend(param_1,paName);
      uVar3 = param_1;
      _objc_msgSend(param_1,paDevicekind_0);
      _IOLog(aSSThreadMsgRec,uVar1,uVar3,puVar2);
      _IOExitThread();
    }
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    pauVar6 = paInterruptoccur_2;
    if (iVar4 == 0x232325) break;
    pauVar5 = (undefined (*) [15])paInputchannel;
    if ((iVar4 == 0x385) || (pauVar5 = paOutputchannel, iVar4 == 900)) {
      uVar1 = param_1;
      _objc_msgSend(param_1,pauVar5);
      _objc_msgSend(param_1,paDatapendingocc,uVar1);
    }
    else {
      pauVar6 = (undefined (*) [19])paCommandoccurre;
      if (iVar4 == 0x386) break;
      _IOLog(aAudioUnknownMe);
    }
  }
loc_F00D735C:
  _objc_msgSend(param_1,pauVar6);
  goto loc_F00D7240;
loc_F00D7314:
  uVar1 = param_1;
  _objc_msgSend(param_1,paIsinputactive_0);
  pauVar6 = (undefined (*) [19])paTimeoutoccurre;
  if (((uVar1 & 0xff) == 0) &&
     (uVar1 = param_1, _objc_msgSend(param_1,paIsoutputactive_0),
     pauVar6 = (undefined (*) [19])paTimeoutoccurre, (uVar1 & 0xff) == 0)) goto loc_F00D7240;
  goto loc_F00D735C;
}

