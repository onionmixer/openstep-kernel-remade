/* GHIDRADEC_FUNCTION index=4650 start=0xf00d7a8c */

undefined8
-[IOAudio _setOutputStartTime:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  **(undefined8 **)(param_1 + 0x174) = CONCAT44(param_3,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4651 start=0xf00d7aa0 */

undefined8 -[IOAudio _outputStartTime](int param_1)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  return CONCAT44((int)**(undefined8 **)(param_1 + 0x174),
                  (int)((qword)**(undefined8 **)(param_1 + 0x174) >> 0x20));
}
/* GHIDRADEC_FUNCTION index=4652 start=0xf00d7ab4 */

/* WARNING: Removing unreachable block (ram,0xf00d7d60) */
/* WARNING: Removing unreachable block (ram,0xf00d7d38) */
/* WARNING: Removing unreachable block (ram,0xf00d7d0c) */
/* WARNING: Removing unreachable block (ram,0xf00d7cb8) */
/* WARNING: Removing unreachable block (ram,0xf00d7c84) */
/* WARNING: Removing unreachable block (ram,0xf00d7c48) */
/* WARNING: Removing unreachable block (ram,0xf00d7c18) */
/* WARNING: Removing unreachable block (ram,0xf00d7be4) */
/* WARNING: Removing unreachable block (ram,0xf00d7bb0) */
/* WARNING: Removing unreachable block (ram,0xf00d7b8c) */
/* WARNING: Removing unreachable block (ram,0xf00d7b5c) */
/* WARNING: Removing unreachable block (ram,0xf00d7b18) */
/* WARNING: Removing unreachable block (ram,0xf00d7afc) */
/* WARNING: Removing unreachable block (ram,0xf00d7b3c) */
/* WARNING: Removing unreachable block (ram,0xf00d7b78) */
/* WARNING: Removing unreachable block (ram,0xf00d7ba0) */
/* WARNING: Removing unreachable block (ram,0xf00d7bcc) */
/* WARNING: Removing unreachable block (ram,0xf00d7bfc) */
/* WARNING: Removing unreachable block (ram,0xf00d7c34) */
/* WARNING: Removing unreachable block (ram,0xf00d7c54) */
/* WARNING: Removing unreachable block (ram,0xf00d7c94) */
/* WARNING: Removing unreachable block (ram,0xf00d7cd8) */
/* WARNING: Removing unreachable block (ram,0xf00d7d20) */
/* WARNING: Removing unreachable block (ram,0xf00d7d48) */
/* WARNING: Removing unreachable block (ram,0xf00d7cec) */
/* WARNING: Removing unreachable block (ram,0xf00d7ae0) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00d7b3c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[IOAudio _attemptToStartDMAForChannel:channelStatus:](uint param_1,undefined4 param_2)

{
  undefined (*pauVar1) [24];
  undefined (*pauVar2) [56];
  undefined7 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined (*pauVar8) [18];
  undefined (*pauVar9) [13];
  uint uVar10;
  qword in_o2_3;
  undefined4 unaff_l0;
  uint uVar11;
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
  char cVar7;
  
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
  uVar10 = (uint)(in_o2_3 >> 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  cVar7 = '\0';
  if ((in_o2_3 & 0xff) != 0) {
    uVar11 = param_1;
    _objc_msgSend(param_1,paSamplerate_0);
    *(uint *)((int)register0x00000038 + -0x14) = uVar11;
    *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x148);
    uVar11 = param_1;
    _objc_msgSend(param_1,paChannelcount_0);
    *(uint *)((int)register0x00000038 + -0x1c) = uVar11;
  }
  uVar11 = 0;
  do {
    uVar4 = uVar10;
    _objc_msgSend(uVar10,paDmacount);
    if (uVar4 >> 1 <= uVar11) break;
    uVar4 = uVar10;
    _objc_msgSend(uVar10,paEnqueuedescrip,(undefined *)((int)register0x00000038 + -0x14),
                  (int)in_o2_3,(undefined *)((int)register0x00000038 + -0x1c));
    uVar11 = uVar11 + 1;
  } while ((uVar4 & 0xff) != 0);
  uVar11 = uVar10;
  _objc_msgSend(uVar10,paEnqueuecount);
  if (uVar11 != 0) {
    _objc_msgSend(param_1,paSetsamplerate,*(undefined4 *)((int)register0x00000038 + -0x14));
    _objc_msgSend(param_1,paSetdataencodin,*(undefined4 *)((int)register0x00000038 + -0x18));
    _objc_msgSend(param_1,paSetchannelcoun,*(undefined4 *)((int)register0x00000038 + -0x1c));
    uVar11 = uVar10;
    _objc_msgSend(uVar10,paChannelbuffer);
    pauVar2 = paStartdmaforcha;
    uVar4 = uVar10;
    _objc_msgSend(uVar10,paLocalchannel);
    puVar3 = paIsread;
    _objc_msgSend(uVar10,paIsread);
    uVar5 = uVar10;
    _objc_msgSend(uVar10,paDescriptorsize);
    uVar6 = param_1;
    _objc_msgSend(param_1,pauVar2,uVar4,(int)in_o2_3,uVar11,uVar5);
    cVar7 = (char)uVar6;
    if ((uVar6 & 0xff) == 0) {
      while (uVar11 = uVar10, _objc_msgSend(uVar10,paEnqueuecount), pauVar1 = paStopdmaforchan,
            uVar11 != 0) {
        _objc_msgSend(uVar10,paDequeuedescrip);
      }
      uVar11 = uVar10;
      _objc_msgSend(uVar10,paLocalchannel);
      _objc_msgSend(uVar10,paIsread);
      _objc_msgSend(param_1,pauVar1,uVar11);
      _objc_msgSend(uVar10,paFreedescriptor);
      pauVar9 = paSettimeout;
    }
    else {
      _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x28));
      _objc_msgSend(param_1,paSetoutputstart,
                    (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x28) >> 0x20));
      uVar11 = uVar10;
      _objc_msgSend(uVar10,puVar3);
      pauVar8 = paSetoutputactiv;
      if ((uVar11 & 0xff) != 0) {
        pauVar8 = (undefined (*) [18])paSetinputactive;
      }
      _objc_msgSend(param_1,pauVar8,1);
      uVar11 = param_1;
      _objc_msgSend(param_1,paTimeout);
      pauVar9 = paSettimeout;
      if (uVar11 != 0xffffffff) goto loc_F00D7D6C;
      _objc_msgSend(uVar10,paDescriptorsize);
    }
    _objc_msgSend(param_1,pauVar9);
  }
loc_F00D7D6C:
  return CONCAT44(param_2,(int)cVar7);
}
/* GHIDRADEC_FUNCTION index=4653 start=0xf00d7d78 */

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
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  _objc_msgSend(param_1,paSamplerate_0);
  *(int *)((int)register0x00000038 + -0x14) = iVar1;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x148);
  iVar1 = param_1;
  _objc_msgSend(param_1,paChannelcount_0);
  uVar3 = paEnqueuecount;
  *(int *)((int)register0x00000038 + -0x1c) = iVar1;
  uVar2 = param_3;
  _objc_msgSend(param_3,paEnqueuecount);
  if (uVar2 != 0) {
    _objc_msgSend(param_3,paDequeuedescrip);
  }
  uVar2 = param_3;
  _objc_msgSend(param_3,paEnqueuedescrip,(undefined *)((int)register0x00000038 + -0x14),
                (undefined *)((int)register0x00000038 + -0x18),
                (undefined *)((int)register0x00000038 + -0x1c));
  if ((uVar2 & 0xff) == 0) {
    uVar2 = param_3;
    _objc_msgSend(param_3,uVar3);
    if (uVar2 == 0) {
      _objc_msgSend(param_1,paStopdmaforchan_0,param_3);
      _objc_msgSend(param_1,paSetoutputstart,0,0);
      _objc_msgSend(param_1,paSetlastinterru,0,0);
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4654 start=0xf00d7e6c */

/* WARNING: Removing unreachable block (ram,0xf00d7f28) */
/* WARNING: Removing unreachable block (ram,0xf00d7efc) */
/* WARNING: Removing unreachable block (ram,0xf00d7ec0) */
/* WARNING: Removing unreachable block (ram,0xf00d7e98) */
/* WARNING: Removing unreachable block (ram,0xf00d7eb0) */
/* WARNING: Removing unreachable block (ram,0xf00d7ecc) */
/* WARNING: Removing unreachable block (ram,0xf00d7f0c) */
/* WARNING: Removing unreachable block (ram,0xf00d7f48) */
/* WARNING: Removing unreachable block (ram,0xf00d7e80) */

undefined8 -[IOAudio _stopDMAForChannel:](uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
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
  
  uVar4 = paStopdmaforchan;
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
  uVar2 = param_3;
  _objc_msgSend(param_3,paLocalchannel);
  uVar1 = paIsread;
  uVar3 = param_3;
  _objc_msgSend(param_3,paIsread);
  _objc_msgSend(param_1,uVar4,uVar2,(int)(char)uVar3);
  _objc_msgSend(param_3,paFreedescriptor);
  _objc_msgSend(param_3,uVar1);
  uVar4 = paSetoutputactiv;
  if ((param_3 & 0xff) != 0) {
    uVar4 = paSetinputactive;
  }
  _objc_msgSend(param_1,uVar4,0);
  uVar2 = param_1;
  _objc_msgSend(param_1,paIsinputactive_0);
  if (((uVar2 & 0xff) == 0) &&
     (uVar2 = param_1, _objc_msgSend(param_1,paIsoutputactive_0), (uVar2 & 0xff) == 0)) {
    _objc_msgSend(param_1,paSettimeout,0xffffffff);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4655 start=0xf00d7f58 */

/* WARNING: Removing unreachable block (ram,0xf00d8134) */
/* WARNING: Removing unreachable block (ram,0xf00d80a4) */
/* WARNING: Removing unreachable block (ram,0xf00d8014) */
/* WARNING: Removing unreachable block (ram,0xf00d8088) */
/* WARNING: Removing unreachable block (ram,0xf00d80b8) */
/* WARNING: Removing unreachable block (ram,0xf00d814c) */
/* WARNING: Removing unreachable block (ram,0xf00d7fdc) */
/* WARNING: Removing unreachable block (ram,0xf00d8000) */

undefined8
-[IOAudio _keyOccurred:event:flags:]
          (uint param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  bool bVar1;
  bool bVar2;
  undefined (*pauVar3) [28];
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  pauVar3 = (undefined (*) [28])paSetoutputmute;
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
  bVar6 = false;
  bVar2 = false;
  bVar1 = false;
  if (param_4 == 10) {
    if (param_3 == 0) {
      bVar6 = (param_5 & 0x100000) == 0;
    }
    else if (param_3 == 1) {
      if ((param_5 & 0x100000) == 0) {
        bVar2 = true;
      }
      else {
        bVar1 = true;
      }
    }
    uVar5 = param_1;
    if ((param_5 & 0x20000) == 0) {
      if (bVar1) {
        _objc_msgSend(param_1,paIsoutputmuted_0);
        uVar5 = (uint)((uVar5 & 0xff) == 0);
      }
      else {
        uVar4 = param_1;
        _objc_msgSend(param_1,paOutputattenuat_2);
        _objc_msgSend(param_1,paOutputattenuat_1);
        if (bVar6) {
          uVar4 = uVar4 + 1;
          if (0 < (int)uVar4) {
            uVar4 = 0;
          }
          uVar5 = uVar5 + 1;
          if (0 < (int)uVar5) {
            uVar5 = 0;
          }
        }
        else if (bVar2) {
          uVar4 = uVar4 - 1;
          if ((int)uVar4 < -0x54) {
            uVar4 = 0xffffffac;
          }
          uVar5 = uVar5 - 1;
          if ((int)uVar5 < -0x54) {
            uVar5 = 0xffffffac;
          }
        }
        _objc_msgSend(param_1,paSetoutputatten_0,uVar4);
        pauVar3 = paSetoutputatten;
      }
    }
    else {
      uVar4 = param_1;
      _objc_msgSend(param_1,paInputgainleft_0);
      _objc_msgSend(param_1,paInputgainright_0);
      if (bVar6) {
        uVar4 = uVar4 + 0x666;
        if (0x7fff < (int)uVar4) {
          uVar4 = 0x8000;
        }
        uVar5 = uVar5 + 0x666;
        if (0x7fff < (int)uVar5) {
          uVar5 = 0x8000;
        }
      }
      else if (bVar2) {
        uVar4 = uVar4 - 0x666;
        if ((int)uVar4 < 1) {
          uVar4 = 0;
        }
        uVar5 = uVar5 - 0x666;
        if ((int)uVar5 < 1) {
          uVar5 = 0;
        }
      }
      _objc_msgSend(param_1,paSetinputgainle,uVar4);
      pauVar3 = (undefined (*) [28])paSetinputgainri;
    }
    _objc_msgSend(param_1,pauVar3,uVar5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4656 start=0xf00d815c */

/* WARNING: Removing unreachable block (ram,0xf00d817c) */
/* WARNING: Removing unreachable block (ram,0xf00d816c) */

undefined8 -[IOAudio _setInputGainLeft:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [14];
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
  
  pauVar1 = paAudiocommand_0;
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
  *(undefined4 *)(param_1 + 0x150) = param_3;
  _objc_msgSend(param_1,pauVar1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4657 start=0xf00d818c */

/* WARNING: Removing unreachable block (ram,0xf00d81ac) */
/* WARNING: Removing unreachable block (ram,0xf00d819c) */

undefined8 -[IOAudio _setInputGainRight:](int param_1,undefined4 param_2,undefined4 param_3)

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
  
  uVar1 = paAudiocommand_0;
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
  *(undefined4 *)(param_1 + 0x154) = param_3;
  _objc_msgSend(param_1,uVar1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4658 start=0xf00d81bc */

/* WARNING: Removing unreachable block (ram,0xf00d81dc) */
/* WARNING: Removing unreachable block (ram,0xf00d81cc) */

undefined8 -[IOAudio _setOutputMute:](int param_1,undefined4 param_2,undefined param_3)

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
  
  uVar1 = paAudiocommand_0;
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
  *(undefined *)(param_1 + 0x16b) = param_3;
  _objc_msgSend(param_1,uVar1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4659 start=0xf00d81ec */

/* WARNING: Removing unreachable block (ram,0xf00d820c) */
/* WARNING: Removing unreachable block (ram,0xf00d81fc) */

undefined8 -[IOAudio _setLoudnessEnhanced:](int param_1,undefined4 param_2,undefined param_3)

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
  
  uVar1 = paAudiocommand_0;
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
  *(undefined *)(param_1 + 0x16c) = param_3;
  _objc_msgSend(param_1,uVar1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4660 start=0xf00d821c */

/* WARNING: Removing unreachable block (ram,0xf00d823c) */
/* WARNING: Removing unreachable block (ram,0xf00d822c) */

undefined8 -[IOAudio _setOutputAttenuationLeft:](int param_1,undefined4 param_2,undefined4 param_3)

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
  
  uVar1 = paAudiocommand_0;
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
  *(undefined4 *)(param_1 + 0x158) = param_3;
  _objc_msgSend(param_1,uVar1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4661 start=0xf00d824c */

/* WARNING: Removing unreachable block (ram,0xf00d826c) */
/* WARNING: Removing unreachable block (ram,0xf00d825c) */

undefined8 -[IOAudio _setOutputAttenuationRight:](int param_1,undefined4 param_2,undefined4 param_3)

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
  
  uVar1 = paAudiocommand_0;
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
  *(undefined4 *)(param_1 + 0x15c) = param_3;
  _objc_msgSend(param_1,uVar1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4662 start=0xf00d827c */

undefined8 -[IOAudio _setInputActive:](int param_1,undefined4 param_2,undefined param_3)

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
  *(undefined *)(param_1 + 0x168) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4663 start=0xf00d828c */

undefined8 -[IOAudio _setOutputActive:](int param_1,undefined4 param_2,undefined param_3)

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
  *(undefined *)(param_1 + 0x169) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4664 start=0xf00d829c */

/* WARNING: Removing unreachable block (ram,0xf00d8328) */
/* WARNING: Removing unreachable block (ram,0xf00d8398) */
/* WARNING: Removing unreachable block (ram,0xf00d8360) */
/* WARNING: Removing unreachable block (ram,0xf00d82f0) */
/* WARNING: Removing unreachable block (ram,0xf00d83fc) */
/* WARNING: Removing unreachable block (ram,0xf00d83d0) */

undefined8
-[IOAudio _setInputFor:to:](int param_1,undefined4 param_2,undefined4 param_3,undefined param_4)

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
  
  uVar1 = paAudiocommand_0;
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
  switch(param_3) {
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x10) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x11) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x12) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x13) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x14) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  :
    _IOLog(aAudioUnknownIn);
    return CONCAT44(param_2,param_1);
  }
  uVar1 = paSend;
  _objc_msgSend();
  return CONCAT44(uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=4665 start=0xf00d840c */

/* WARNING: Removing unreachable block (ram,0xf00d8460) */
/* WARNING: Removing unreachable block (ram,0xf00d8508) */
/* WARNING: Removing unreachable block (ram,0xf00d84d0) */
/* WARNING: Removing unreachable block (ram,0xf00d8498) */
/* WARNING: Removing unreachable block (ram,0xf00d856c) */
/* WARNING: Removing unreachable block (ram,0xf00d8540) */

undefined8
-[IOAudio _setOutputFor:to:](int param_1,undefined4 param_2,undefined4 param_3,undefined param_4)

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
  
  uVar1 = paAudiocommand_0;
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
  switch(param_3) {
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x16) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x15) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x17) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x18) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x19) = param_4;
    _objc_msgSend(param_1,uVar1);
    break;
  :
    _IOLog(aAudioUnknownOu);
    return CONCAT44(param_2,param_1);
  }
  uVar1 = paSend;
  _objc_msgSend();
  return CONCAT44(uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=4666 start=0xf00d857c */

undefined8 -[IOAudio _analogInputSource](int param_1,undefined4 param_2)

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
  uint uVar2;
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
  iVar1 = *(int *)(param_1 + 0x174);
  uVar2 = 0x1e;
  if ((((*(char *)(iVar1 + 0x10) == '\0') && (uVar2 = 0x21, *(char *)(iVar1 + 0x11) == '\0')) &&
      (*(char *)(iVar1 + 0x12) == '\0')) && (*(char *)(iVar1 + 0x13) == '\0')) {
    uVar2 = -(uint)(*(char *)(iVar1 + 0x14) != '\0') & 0x22;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4667 start=0xf00d85dc */

/* WARNING: Removing unreachable block (ram,0xf00d8644) */
/* WARNING: Removing unreachable block (ram,0xf00d861c) */
/* WARNING: Removing unreachable block (ram,0xf00d8608) */
/* WARNING: Removing unreachable block (ram,0xf00d8630) */
/* WARNING: Removing unreachable block (ram,0xf00d8658) */
/* WARNING: Removing unreachable block (ram,0xf00d85f4) */

undefined8
-[IOAudio _setAnalogInputSource:](undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [17];
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
  
  pauVar1 = paSetinputforTo;
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
  _objc_msgSend(param_1,paSetinputforTo,0x1e,0);
  _objc_msgSend(param_1,pauVar1,0x1f,0);
  _objc_msgSend(param_1,pauVar1,0x20,0);
  _objc_msgSend(param_1,pauVar1,0x21,0);
  _objc_msgSend(param_1,pauVar1,0x22,0);
  _objc_msgSend(param_1,pauVar1,param_3,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4668 start=0xf00d8668 */

/* WARNING: Removing unreachable block (ram,0xf00d8b14) */
/* WARNING: Removing unreachable block (ram,0xf00d8784) */
/* WARNING: Removing unreachable block (ram,0xf00d8900) */
/* WARNING: Removing unreachable block (ram,0xf00d8b88) */
/* WARNING: Removing unreachable block (ram,0xf00d8a50) */
/* WARNING: Removing unreachable block (ram,0xf00d89a4) */
/* WARNING: Removing unreachable block (ram,0xf00d8804) */
/* WARNING: Removing unreachable block (ram,0xf00d8694) */
/* WARNING: Removing unreachable block (ram,0xf00d8814) */
/* WARNING: Removing unreachable block (ram,0xf00d89b4) */
/* WARNING: Removing unreachable block (ram,0xf00d8a60) */
/* WARNING: Removing unreachable block (ram,0xf00d8b30) */
/* WARNING: Removing unreachable block (ram,0xf00d8914) */
/* WARNING: Removing unreachable block (ram,0xf00d8b48) */
/* WARNING: Removing unreachable block (ram,0xf00d8b74) */
/* WARNING: Removing unreachable block (ram,0xf00d8684) */

undefined8
-[IOAudio _intValueForParameter:forObject:]
          (uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [10];
  undefined (*pauVar3) [9];
  uint uVar4;
  uint uVar5;
  undefined (*pauVar6) [12];
  undefined (*pauVar7) [13];
  undefined (*pauVar8) [19];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  pauVar3 = paIsequal;
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
  uVar9 = 0;
  uVar4 = param_1;
  _objc_msgSend(param_1,paInputchannel);
  uVar5 = param_4;
  _objc_msgSend(param_4,pauVar3,uVar4);
  if ((uVar5 & 0xff) == 0) {
    uVar4 = param_1;
    _objc_msgSend(param_1,paOutputchannel);
    uVar5 = param_4;
    _objc_msgSend(param_4,pauVar3,uVar4);
    pauVar2 = paIskindof;
    puVar1 = paClass;
    if ((uVar5 & 0xff) == 0) {
      pauVar6 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar4 = param_4;
      _objc_msgSend(param_4,pauVar2,pauVar6);
      if ((uVar4 & 0xff) == 0) {
        pauVar7 = paOutputstream;
        _objc_msgSend(paOutputstream,puVar1);
        uVar4 = param_4;
        _objc_msgSend(param_4,pauVar2,pauVar7);
        if ((uVar4 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
          goto loc_F00D8B90;
        }
        switch(param_3) {
        case :
          pauVar8 = (undefined (*) [19])paDataencoding_0;
          break;
        case :
          pauVar8 = (undefined (*) [19])paSamplingrate;
          break;
        case :
          pauVar8 = paChannelcount_0;
          break;
        case :
          pauVar8 = (undefined (*) [19])paHighwatermark;
          break;
        case :
          pauVar8 = (undefined (*) [19])paLowwatermark;
          break;
        :
          goto def_F00D86C0;
        case :
          uVar9 = 0x25f;
          goto def_F00D86C0;
        case :
          goto loc_F00D8B08;
        case :
          uVar4 = param_4;
          _objc_msgSend(param_4,paGainleft);
          pauVar8 = (undefined (*) [19])paGainright;
          goto loc_F00D8B48;
        case :
          pauVar8 = (undefined (*) [19])paGainleft;
          break;
        case :
          pauVar8 = (undefined (*) [19])paGainright;
        }
        goto loc_F00D8B74;
      }
      switch(param_3) {
      case :
        pauVar8 = (undefined (*) [19])paDataencoding_0;
        break;
      case :
        pauVar8 = (undefined (*) [19])paSamplingrate;
        break;
      case :
        pauVar8 = paChannelcount_0;
        break;
      case :
        pauVar8 = (undefined (*) [19])paHighwatermark;
        break;
      case :
        pauVar8 = (undefined (*) [19])paLowwatermark;
        break;
      case :
        uVar9 = 0x25d;
      :
        goto def_F00D86C0;
      }
      goto loc_F00D8B74;
    }
    switch(param_3) {
    case :
      pauVar8 = paDescriptorsize;
      goto loc_F00D8B74;
    case :
      pauVar8 = paDmacount;
      goto loc_F00D8B74;
    case :
      goto loc_F00D8B08;
    case :
    case :
    case :
    case :
loc_F00D8B90:
      uVar9 = 0;
      break;
    case :
    case :
    case :
      pauVar8 = paIsoutputmuted_0;
      goto loc_F00D8B14;
    case :
      pauVar8 = paIsloudnessenha_0;
loc_F00D8B14:
      _objc_msgSend(param_1,pauVar8);
      uVar9 = (uint)(char)param_1;
      break;
    case :
      uVar4 = param_1;
      _objc_msgSend(param_1,paOutputattenuat_2);
      _objc_msgSend(param_1,paOutputattenuat_1);
      uVar9 = (int)(uVar4 + param_1) / 2;
      break;
    case :
      param_4 = param_1;
      pauVar8 = paOutputattenuat_2;
      goto loc_F00D8B74;
    case :
      param_4 = param_1;
      pauVar8 = paOutputattenuat_1;
      goto loc_F00D8B74;
    case :
      uVar9 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x16);
      break;
    case :
      uVar9 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x15);
      break;
    case :
      uVar9 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x17);
      break;
    case :
      uVar9 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x18);
      break;
    case :
      uVar9 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x19);
    }
    goto def_F00D86C0;
  }
  switch(param_3) {
  case :
    pauVar8 = paDescriptorsize;
    goto loc_F00D8B74;
  case :
    pauVar8 = paDmacount;
    goto loc_F00D8B74;
  case :
loc_F00D8B08:
    param_1 = param_4;
    pauVar8 = (undefined (*) [19])paIsdetectingpea;
    goto loc_F00D8B14;
  case :
    param_4 = param_1;
    pauVar8 = paAnaloginputsou;
    goto loc_F00D8B74;
  case :
    uVar4 = param_1;
    _objc_msgSend(param_1,paInputgainleft_0);
    param_4 = param_1;
    pauVar8 = paInputgainright_0;
loc_F00D8B48:
    _objc_msgSend(param_4,pauVar8);
    uVar9 = uVar4 + param_4 >> 1;
    break;
  case :
    param_4 = param_1;
    pauVar8 = paInputgainleft_0;
    goto loc_F00D8B74;
  case :
    param_4 = param_1;
    pauVar8 = paInputgainright_0;
loc_F00D8B74:
    _objc_msgSend(param_4,pauVar8);
    uVar9 = param_4;
    break;
  case :
    uVar9 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x10);
    break;
  case :
    uVar9 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x11);
    break;
  case :
    uVar9 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x12);
    break;
  case :
    uVar9 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x13);
    break;
  case :
    uVar9 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x14);
  }
def_F00D86C0:
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=4669 start=0xf00d8b9c */

/* WARNING: Removing unreachable block (ram,0xf00d9030) */
/* WARNING: Removing unreachable block (ram,0xf00d8e14) */
/* WARNING: Removing unreachable block (ram,0xf00d9040) */
/* WARNING: Removing unreachable block (ram,0xf00d8f04) */
/* WARNING: Removing unreachable block (ram,0xf00d8e38) */
/* WARNING: Removing unreachable block (ram,0xf00d8ce0) */
/* WARNING: Removing unreachable block (ram,0xf00d8bc4) */
/* WARNING: Removing unreachable block (ram,0xf00d8c90) */
/* WARNING: Removing unreachable block (ram,0xf00d8cf0) */
/* WARNING: Removing unreachable block (ram,0xf00d8e48) */
/* WARNING: Removing unreachable block (ram,0xf00d8f14) */
/* WARNING: Removing unreachable block (ram,0xf00d9004) */
/* WARNING: Removing unreachable block (ram,0xf00d8dc8) */
/* WARNING: Removing unreachable block (ram,0xf00d8fec) */
/* WARNING: Removing unreachable block (ram,0xf00d8bb4) */

undefined8
-[IOAudio _setParameter:toInt:forObject:]
          (uint param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined (*pauVar6) [18];
  undefined (*pauVar7) [22];
  undefined (*pauVar8) [23];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar9;
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
  
  uVar1 = paIsequal;
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
  uVar9 = 1;
  uVar3 = param_1;
  _objc_msgSend(param_1,paInputchannel);
  uVar4 = param_5;
  _objc_msgSend(param_5,uVar1,uVar3);
  if ((uVar4 & 0xff) != 0) {
    switch(param_3) {
    case :
    case :
      goto locret_F00D904C;
    case :
loc_F00D8FDC:
      param_1 = param_5;
      pauVar7 = (undefined (*) [22])paSetdetectpeaks;
      goto loc_F00D8FE8;
    :
      goto def_F00D8BF0;
    case :
      param_5 = param_1;
      pauVar8 = paSetanaloginput;
      break;
    case :
      _objc_msgSend(param_1,paSetinputgainle,param_4);
      param_5 = param_1;
      pauVar8 = paSetinputgainri;
      break;
    case :
      param_5 = param_1;
      pauVar8 = paSetinputgainle;
      break;
    case :
    case :
    case :
    case :
    case :
      pauVar6 = paSetinputforTo;
loc_F00D8E0C:
      _objc_msgSend(param_1,pauVar6,param_3,(int)(char)param_4);
      goto locret_F00D904C;
    }
    goto loc_F00D9030;
  }
  uVar3 = param_1;
  _objc_msgSend(param_1,paOutputchannel);
  uVar4 = param_5;
  _objc_msgSend(param_5,uVar1,uVar3);
  uVar2 = paIskindof;
  uVar1 = paClass;
  if ((uVar4 & 0xff) == 0) {
    uVar5 = paInputstream;
    _objc_msgSend(paInputstream,paClass);
    uVar3 = param_5;
    _objc_msgSend(param_5,uVar2,uVar5);
    if ((uVar3 & 0xff) != 0) {
      switch(param_3) {
      case :
        pauVar8 = (undefined (*) [23])paSetdataencodin_0;
        break;
      case :
        pauVar8 = (undefined (*) [23])paSetsamplingrat;
        break;
      case :
        pauVar8 = (undefined (*) [23])paSetchannelcoun_0;
        break;
      case :
        pauVar8 = (undefined (*) [23])paSethighwaterma;
        break;
      case :
        pauVar8 = (undefined (*) [23])paSetlowwatermar;
        break;
      case :
        if (param_4 != 0x25d) {
          uVar9 = 0;
        }
        goto locret_F00D904C;
      :
        goto def_F00D8BF0;
      }
      goto loc_F00D9030;
    }
    uVar5 = paOutputstream;
    _objc_msgSend(paOutputstream,uVar1);
    uVar3 = param_5;
    _objc_msgSend(param_5,uVar2,uVar5);
    if ((uVar3 & 0xff) == 0) {
      _IOLog(aAudioUnknownPa);
def_F00D8BF0:
      uVar9 = 0;
      goto locret_F00D904C;
    }
    switch(param_3) {
    case :
      pauVar8 = (undefined (*) [23])paSetdataencodin_0;
      break;
    case :
      pauVar8 = (undefined (*) [23])paSetsamplingrat;
      break;
    case :
      pauVar8 = (undefined (*) [23])paSetchannelcoun_0;
      break;
    case :
      pauVar8 = (undefined (*) [23])paSethighwaterma;
      break;
    case :
      pauVar8 = (undefined (*) [23])paSetlowwatermar;
      break;
    :
      goto def_F00D8BF0;
    case :
      if (param_4 != 0x25f) {
        uVar9 = 0;
      }
      goto locret_F00D904C;
    case :
      goto loc_F00D8FDC;
    case :
      _objc_msgSend(param_5,paSetgainleft,param_4);
      pauVar8 = (undefined (*) [23])paSetgainright;
      break;
    case :
      pauVar8 = (undefined (*) [23])paSetgainleft;
      break;
    case :
      pauVar8 = (undefined (*) [23])paSetgainright;
    }
    goto loc_F00D9030;
  }
  switch(param_3) {
  case :
  case :
  case :
  case :
  case :
  case :
    goto locret_F00D904C;
  case :
    goto loc_F00D8FDC;
  case :
  case :
  case :
    pauVar7 = paSetoutputmute;
    goto loc_F00D8FE8;
  case :
    pauVar7 = paSetloudnessenh;
loc_F00D8FE8:
    _objc_msgSend(param_1,pauVar7,(int)(char)param_4);
    goto locret_F00D904C;
  case :
    _objc_msgSend(param_1,paSetoutputatten_0,param_4);
    param_5 = param_1;
    pauVar8 = paSetoutputatten;
    break;
  case :
    param_5 = param_1;
    pauVar8 = paSetoutputatten_0;
    break;
  case :
    param_5 = param_1;
    pauVar8 = paSetoutputatten;
    break;
  :
    goto def_F00D8BF0;
  case :
  case :
  case :
  case :
  case :
    pauVar6 = paSetoutputforTo;
    goto loc_F00D8E0C;
  }
loc_F00D9030:
  _objc_msgSend(param_5,pauVar8,param_4);
locret_F00D904C:
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=4670 start=0xf00d9054 */

/* WARNING: Removing unreachable block (ram,0xf00d9084) */

undefined8
-[IOAudio _setParameters:toValues:count:forObject:]
          (uint param_1,undefined4 param_2,int param_3,int param_4,uint param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar3 = 0;
  uVar4 = 1;
  if (param_5 != 0) {
    iVar2 = 0;
    do {
      uVar1 = param_1;
      _objc_msgSend(param_1,paSetparameterTo,*(undefined4 *)(iVar2 + param_3),
                    *(undefined4 *)(iVar2 + param_4),param_6);
      if ((uVar1 & 0xff) == 0) {
        uVar4 = 0;
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (uVar3 < param_5);
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4671 start=0xf00d90b4 */

/* WARNING: Removing unreachable block (ram,0xf00d90dc) */

undefined8
-[IOAudio _getParameters:values:count:forObject:]
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
          undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar3 = 0;
  if (param_5 != 0) {
    iVar2 = 0;
    do {
      uVar3 = uVar3 + 1;
      uVar1 = param_1;
      _objc_msgSend(param_1,paIntvalueforpar,*(undefined4 *)(iVar2 + param_3),param_6);
      *(undefined4 *)(iVar2 + param_4) = uVar1;
      iVar2 = iVar2 + 4;
    } while (uVar3 < param_5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4672 start=0xf00d90fc */

/* WARNING: Removing unreachable block (ram,0xf00d91f8) */
/* WARNING: Removing unreachable block (ram,0xf00d91b8) */
/* WARNING: Removing unreachable block (ram,0xf00d9168) */
/* WARNING: Removing unreachable block (ram,0xf00d9128) */
/* WARNING: Removing unreachable block (ram,0xf00d9158) */
/* WARNING: Removing unreachable block (ram,0xf00d91a8) */
/* WARNING: Removing unreachable block (ram,0xf00d91e8) */
/* WARNING: Removing unreachable block (ram,0xf00d9224) */
/* WARNING: Removing unreachable block (ram,0xf00d9118) */

undefined8
-[IOAudio _getSupportedParameters:count:forObject:]
          (undefined4 param_1,undefined4 param_2,int param_3,uint *param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar2 = paInputchannel;
  uVar6 = paIsequal;
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
  puVar5 = (undefined *)0x0;
  *param_4 = 0;
  uVar1 = param_1;
  _objc_msgSend(param_1,uVar2);
  uVar4 = param_5;
  _objc_msgSend(param_5,uVar6,uVar1);
  if ((uVar4 & 0xff) == 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paOutputchannel);
    uVar4 = param_5;
    _objc_msgSend(param_5,uVar6,uVar2);
    uVar2 = paIskindof;
    uVar6 = paClass;
    if ((uVar4 & 0xff) == 0) {
      uVar1 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar4 = param_5;
      _objc_msgSend(param_5,uVar2,uVar1);
      if ((uVar4 & 0xff) == 0) {
        uVar1 = paOutputstream;
        _objc_msgSend(paOutputstream,uVar6);
        _objc_msgSend(param_5,uVar2,uVar1);
        if ((param_5 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
        }
        else {
          puVar5 = unk_F00F9724;
          *param_4 = 10;
        }
      }
      else {
        puVar5 = unk_F00F974C;
        *param_4 = 6;
      }
    }
    else {
      puVar5 = unk_F00F96D0;
      *param_4 = 0xe;
      uVar6 = param_1;
    }
  }
  else {
    puVar5 = unk_F00F9708;
    *param_4 = 7;
    uVar6 = param_1;
  }
  uVar4 = 0;
  iVar3 = 0;
  if (*param_4 != 0) {
    do {
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar3 + param_3) = *(undefined4 *)(puVar5 + iVar3);
      iVar3 = iVar3 + 4;
    } while (uVar4 < *param_4);
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=4673 start=0xf00d9264 */

/* WARNING: Removing unreachable block (ram,0xf00d9378) */
/* WARNING: Removing unreachable block (ram,0xf00d9324) */
/* WARNING: Removing unreachable block (ram,0xf00d92e4) */
/* WARNING: Removing unreachable block (ram,0xf00d9290) */
/* WARNING: Removing unreachable block (ram,0xf00d92d4) */
/* WARNING: Removing unreachable block (ram,0xf00d9314) */
/* WARNING: Removing unreachable block (ram,0xf00d9368) */
/* WARNING: Removing unreachable block (ram,0xf00d93e8) */
/* WARNING: Removing unreachable block (ram,0xf00d9280) */

undefined8
-[IOAudio _getValues:count:forParameter:forObject:]
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,int param_5
          ,uint param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char cVar5;
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
  
  uVar2 = paInputchannel;
  uVar1 = paIsequal;
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
  cVar5 = '\x01';
  *param_4 = 0;
  uVar3 = param_1;
  _objc_msgSend(param_1,uVar2);
  uVar4 = param_6;
  _objc_msgSend(param_6,uVar1,uVar3);
  if ((uVar4 & 0xff) == 0) {
    _objc_msgSend(param_1,paOutputchannel);
    uVar4 = param_6;
    _objc_msgSend(param_6,uVar1,param_1);
    uVar2 = paIskindof;
    uVar1 = paClass;
    if ((uVar4 & 0xff) == 0) {
      uVar3 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar4 = param_6;
      _objc_msgSend(param_6,uVar2,uVar3);
      if ((uVar4 & 0xff) == 0) {
        uVar3 = paOutputstream;
        _objc_msgSend(paOutputstream,uVar1);
        _objc_msgSend(param_6,uVar2,uVar3);
        if ((param_6 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
          cVar5 = '\0';
          goto loc_F00D93F4;
        }
        if (param_5 != 400) {
          if (param_5 == 0x196) {
            *param_4 = 1;
            *param_3 = 0x25f;
          }
          else {
            cVar5 = '\0';
          }
          goto loc_F00D93F4;
        }
      }
      else if (param_5 != 400) {
        if (param_5 == 0x195) {
          *param_4 = 1;
          *param_3 = 0x25d;
        }
        else {
          cVar5 = '\0';
        }
        goto loc_F00D93F4;
      }
      *param_4 = 4;
      *param_3 = 600;
      param_3[1] = 0x259;
      param_3[2] = 0x25a;
      param_3[3] = 0x25b;
    }
    else {
      cVar5 = '\0';
    }
  }
  else if (param_5 == 0xe) {
    *param_4 = 2;
    *param_3 = 200;
    param_3[1] = 0xc9;
  }
  else {
    cVar5 = -0x2e;
  }
loc_F00D93F4:
  return CONCAT44(param_2,(int)cVar5);
}
/* GHIDRADEC_FUNCTION index=4674 start=0xf00d9404 */

/* WARNING: Removing unreachable block (ram,0xf00d9440) */
/* WARNING: Removing unreachable block (ram,0xf00d9428) */
/* WARNING: Removing unreachable block (ram,0xf00d9450) */
/* WARNING: Removing unreachable block (ram,0xf00d9418) */

undefined8 -[IOAudio _initAudioHardwareSettings](undefined4 param_1,undefined4 param_2)

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
  
  uVar1 = paSetinputgainri;
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
  _objc_msgSend(param_1,paSetinputgainri,0x4000);
  _objc_msgSend(param_1,uVar1,0x4000);
  uVar1 = paSetoutputatten_0;
  _objc_msgSend(param_1,paSetoutputatten_0,0xffffffd6);
  _objc_msgSend(param_1,uVar1,0xffffffd6);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4675 start=0xf00d9460 */

/* WARNING: Removing unreachable block (ram,0xf00d9494) */
/* WARNING: Removing unreachable block (ram,0xf00d9480) */
/* WARNING: Removing unreachable block (ram,0xf00d94a0) */
/* WARNING: Removing unreachable block (ram,0xf00d946c) */

undefined8
-[IOAudio _getOutputChannelBuffer:size:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
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
  uVar1 = *(undefined4 *)(param_1 + 300);
  _objc_msgSend(uVar1,paChannelbuffera);
  *param_3 = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 300);
  _objc_msgSend(uVar2,paDescriptorsize);
  uVar1 = *(undefined4 *)(param_1 + 300);
  _objc_msgSend(uVar1,paDmacount);
  .umul(uVar2,uVar1);
  *param_4 = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4676 start=0xf00d94b4 */

/* WARNING: Removing unreachable block (ram,0xf00d94e8) */
/* WARNING: Removing unreachable block (ram,0xf00d94d4) */
/* WARNING: Removing unreachable block (ram,0xf00d94f4) */
/* WARNING: Removing unreachable block (ram,0xf00d94c0) */

undefined8
-[IOAudio _getInputChannelBuffer:size:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
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
  uVar1 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar1,paChannelbuffera);
  *param_3 = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar2,paDescriptorsize);
  uVar1 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar1,paDmacount);
  .umul(uVar2,uVar1);
  *param_4 = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4677 start=0xf00d9508 */

/* WARNING: Removing unreachable block (ram,0xf00d9588) */
/* WARNING: Removing unreachable block (ram,0xf00d9554) */
/* WARNING: Removing unreachable block (ram,0xf00d95d8) */
/* WARNING: Removing unreachable block (ram,0xf00d953c) */
/* WARNING: Removing unreachable block (ram,0xf00d956c) */
/* WARNING: Removing unreachable block (ram,0xf00d95a4) */
/* WARNING: Removing unreachable block (ram,0xf00d95c4) */

undefined8 -[IOAudio _runExclusiveOutputDMA:](int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
  
  uVar1 = paStopdmaforchan;
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
  if (param_3 != unk_F012EEFC._0_1_) {
    if (param_3 == '\0') {
      uVar3 = *(undefined4 *)(param_1 + 300);
      _objc_msgSend(uVar3,paLocalchannel);
      _objc_msgSend(param_1,uVar1,uVar3,0);
      unk_F012EEFC._0_1_ = param_3;
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 300);
      dword_F012EF00 = 0;
      _objc_msgSend(uVar1,paDescriptorsize);
      iVar2 = param_1;
      dword_F012EF04 = uVar1;
      _objc_msgSend(param_1,paInterruptclear);
      uVar3 = *(undefined4 *)(param_1 + 300);
      dword_F012EF08 = iVar2;
      _objc_msgSend(uVar3,paChannelbuffer);
      uVar1 = paStartdmaforcha;
      uVar4 = *(undefined4 *)(param_1 + 300);
      _objc_msgSend(uVar4,paLocalchannel);
      _objc_msgSend(param_1,uVar1,uVar4,0,uVar3,dword_F012EF04);
      unk_F012EEFC._0_1_ = param_3;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4678 start=0xf00d95f0 */

/* WARNING: Removing unreachable block (ram,0xf00d9670) */
/* WARNING: Removing unreachable block (ram,0xf00d963c) */
/* WARNING: Removing unreachable block (ram,0xf00d96c0) */
/* WARNING: Removing unreachable block (ram,0xf00d9624) */
/* WARNING: Removing unreachable block (ram,0xf00d9654) */
/* WARNING: Removing unreachable block (ram,0xf00d968c) */
/* WARNING: Removing unreachable block (ram,0xf00d96ac) */

undefined8 -[IOAudio _runExclusiveInputDMA:](int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
  
  uVar1 = paStopdmaforchan;
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
  if (param_3 != unk_F012EEFC._0_1_) {
    if (param_3 == '\0') {
      uVar3 = *(undefined4 *)(param_1 + 0x128);
      _objc_msgSend(uVar3,paLocalchannel);
      _objc_msgSend(param_1,uVar1,uVar3,1);
      unk_F012EEFC._0_1_ = param_3;
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x128);
      dword_F012EF00 = 0;
      _objc_msgSend(uVar1,paDescriptorsize);
      iVar2 = param_1;
      dword_F012EF04 = uVar1;
      _objc_msgSend(param_1,paInterruptclear);
      uVar3 = *(undefined4 *)(param_1 + 0x128);
      dword_F012EF08 = iVar2;
      _objc_msgSend(uVar3,paChannelbuffer);
      uVar1 = paStartdmaforcha;
      uVar4 = *(undefined4 *)(param_1 + 0x128);
      _objc_msgSend(uVar4,paLocalchannel);
      _objc_msgSend(param_1,uVar1,uVar4,1,uVar3,dword_F012EF04);
      unk_F012EEFC._0_1_ = param_3;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4679 start=0xf00d96d8 */

undefined8 -[IOAudio _exclusiveProgress](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,dword_F012EF00);
}
/* GHIDRADEC_FUNCTION index=4680 start=0xf00d96ec */

sqword -[IOAudio interruptClearFunc](undefined4 param_1,uint param_2)

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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4681 start=0xf00d96f8 */

/* WARNING: Removing unreachable block (ram,0xf00d9ab4) */
/* WARNING: Removing unreachable block (ram,0xf00d9a94) */
/* WARNING: Removing unreachable block (ram,0xf00d9a7c) */
/* WARNING: Removing unreachable block (ram,0xf00d9a54) */
/* WARNING: Removing unreachable block (ram,0xf00d9a30) */
/* WARNING: Removing unreachable block (ram,0xf00d9a08) */
/* WARNING: Removing unreachable block (ram,0xf00d99ec) */
/* WARNING: Removing unreachable block (ram,0xf00d99d0) */
/* WARNING: Removing unreachable block (ram,0xf00d99b4) */
/* WARNING: Removing unreachable block (ram,0xf00d999c) */
/* WARNING: Removing unreachable block (ram,0xf00d9974) */
/* WARNING: Removing unreachable block (ram,0xf00d9964) */
/* WARNING: Removing unreachable block (ram,0xf00d993c) */
/* WARNING: Removing unreachable block (ram,0xf00d9918) */
/* WARNING: Removing unreachable block (ram,0xf00d98f0) */
/* WARNING: Removing unreachable block (ram,0xf00d98bc) */
/* WARNING: Removing unreachable block (ram,0xf00d9894) */
/* WARNING: Removing unreachable block (ram,0xf00d9870) */
/* WARNING: Removing unreachable block (ram,0xf00d9840) */
/* WARNING: Removing unreachable block (ram,0xf00d9810) */
/* WARNING: Removing unreachable block (ram,0xf00d97fc) */
/* WARNING: Removing unreachable block (ram,0xf00d97d8) */
/* WARNING: Removing unreachable block (ram,0xf00d97a0) */
/* WARNING: Removing unreachable block (ram,0xf00d9774) */
/* WARNING: Removing unreachable block (ram,0xf00d974c) */
/* WARNING: Removing unreachable block (ram,0xf00d9738) */
/* WARNING: Removing unreachable block (ram,0xf00d9764) */
/* WARNING: Removing unreachable block (ram,0xf00d9784) */
/* WARNING: Removing unreachable block (ram,0xf00d97b0) */
/* WARNING: Removing unreachable block (ram,0xf00d97e8) */
/* WARNING: Removing unreachable block (ram,0xf00d9808) */
/* WARNING: Removing unreachable block (ram,0xf00d982c) */
/* WARNING: Removing unreachable block (ram,0xf00d9868) */
/* WARNING: Removing unreachable block (ram,0xf00d9878) */
/* WARNING: Removing unreachable block (ram,0xf00d98a8) */
/* WARNING: Removing unreachable block (ram,0xf00d98d8) */
/* WARNING: Removing unreachable block (ram,0xf00d990c) */
/* WARNING: Removing unreachable block (ram,0xf00d9928) */
/* WARNING: Removing unreachable block (ram,0xf00d9954) */
/* WARNING: Removing unreachable block (ram,0xf00d996c) */
/* WARNING: Removing unreachable block (ram,0xf00d9988) */
/* WARNING: Removing unreachable block (ram,0xf00d99a8) */
/* WARNING: Removing unreachable block (ram,0xf00d99c8) */
/* WARNING: Removing unreachable block (ram,0xf00d99d8) */
/* WARNING: Removing unreachable block (ram,0xf00d99fc) */
/* WARNING: Removing unreachable block (ram,0xf00d9a20) */
/* WARNING: Removing unreachable block (ram,0xf00d9a44) */
/* WARNING: Removing unreachable block (ram,0xf00d9a6c) */
/* WARNING: Removing unreachable block (ram,0xf00d9a88) */
/* WARNING: Removing unreachable block (ram,0xf00d9aa4) */
/* WARNING: Removing unreachable block (ram,0xf00d985c) */
/* WARNING: Removing unreachable block (ram,0xf00d9720) */

undefined8 -[IOAudio initFromDeviceDescription:](uint param_1,undefined4 param_2,int param_3)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [14];
  undefined (*pauVar3) [17];
  undefined8 *puVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  undefined (*pauVar10) [13];
  undefined (*pauVar11) [13];
  int iVar12;
  code *pcVar13;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar14;
  undefined *puVar15;
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
  *(uint *)((int)register0x00000038 + -0x10) = param_1;
  puVar5 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142258;
  puVar15 = aKernelserverin;
  _objc_msgSendSuper(puVar5,paInitfromdevice,param_3);
  if (puVar5 != (undefined *)0x0) {
    uVar6 = param_1;
    _objc_msgSend(param_1,paAttachinterrup_0);
    if (uVar6 != 0) {
      param_1 = 0;
      goto locret_F00D9ABC;
    }
    _task_self();
    pauVar2 = paInterruptport_0;
    uVar7 = param_1;
    _objc_msgSend(param_1,paInterruptport_0);
    _port_set_backlog_EXTERNAL(uVar6,uVar7,0x10);
    uVar6 = param_1;
    _objc_msgSend(param_1,paReset);
    if ((uVar6 & 0xff) != 0) {
      _objc_msgSend(param_1,paInitaudiohardw);
      _objc_msgSend(param_3,paConfigtable_0);
      if (param_3 == 0) {
        puVar5 = aAudioNoConfigt;
      }
      else {
        _objc_msgSend();
        puVar14 = (undefined *)((int)register0x00000038 + -0x118);
        _strlen(aKernelserverin);
        _strncpy(puVar14,param_3,0x100 - (int)puVar15);
        _strcat(puVar14,aKernelserverin);
        puVar5 = puVar14;
        _objc_lookUpClass();
        if (puVar5 == (undefined *)0x0) {
          _IOLog(aAudioNoKernelS,puVar14);
          goto loc_F00D9834;
        }
        _objc_msgSend(puVar5,paKernelserverin_0);
        if (puVar5 != (undefined *)0x0) {
          _audioKernServInit();
          _audio_makeIMuLawTab();
          uVar8 = 0x20;
          _IOMalloc();
          *(undefined4 *)(param_1 + 0x174) = uVar8;
          puVar4 = paIoaudio;
          puVar9 = paIoaudio;
          _objc_msgSend(paIoaudio,paInstance_0);
          if (puVar9 != (undefined8 *)0x0) {
            _IOLog(aAudioReplacing);
          }
          _objc_msgSend(puVar4,paSetinstance,param_1);
          pauVar11 = paAudiochannel;
          puVar1 = paAlloc;
          pauVar10 = paAudiochannel;
          _objc_msgSend(paAudiochannel,paAlloc);
          _objc_msgSend();
          *(undefined (**) [13])(param_1 + 0x128) = pauVar10;
          pauVar10 = paAddchannel;
          _objc_msgSend(puVar4,paAddchannel);
          _objc_msgSend(pauVar11,puVar1);
          _objc_msgSend();
          *(undefined (**) [13])(param_1 + 300) = pauVar11;
          _objc_msgSend(puVar4,pauVar10);
          pauVar3 = paSetlocalchanne;
          _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paSetlocalchanne,0);
          iVar12 = *(int *)(param_1 + 300);
          _objc_msgSend(iVar12,pauVar3,0);
          _task_self();
          _port_set_allocate_EXTERNAL();
          if (iVar12 != 0) {
            _IOLog(aAudioPortSetAl,iVar12);
          }
          *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)((int)register0x00000038 + -0x11c);
          uVar6 = param_1;
          _objc_msgSend(param_1,pauVar2);
          _task_self();
          _port_set_add_EXTERNAL();
          puVar5 = (undefined *)0xf00fc000;
          if (uVar6 != 0) {
            puVar5 = aAudioPortSetAd;
            _IOLog();
          }
          _task_self();
          _port_allocate_EXTERNAL();
          puVar15 = (undefined *)0xf00fc000;
          if (puVar5 != (undefined *)0x0) {
            puVar15 = aAudioPortAlloc;
            _IOLog();
          }
          *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)((int)register0x00000038 + -0x11c);
          _task_self();
          _port_set_add_EXTERNAL();
          if (puVar15 != (undefined *)0x0) {
            _IOLog(aAudioPortSetAd);
          }
          uVar8 = *(undefined4 *)(param_1 + 0x134);
          _IOConvertPort(uVar8,1,0);
          *(undefined4 *)(param_1 + 0x134) = uVar8;
          pauVar10 = paAudiocommand;
          _objc_msgSend(paAudiocommand,puVar1);
          _objc_msgSend();
          *(undefined (**) [13])(param_1 + 0x130) = pauVar10;
          _objc_msgSend(param_1,paSettimeout,0xffffffff);
          pcVar13 = sub_F00D7228;
          _IOForkThread(sub_F00D7228,param_1);
          _IOSetThreadPolicy();
          _IOSetThreadPriority(pcVar13,0x1e);
          _IOForkThread(sub_F00D73BC,param_1);
          _objc_msgSend(param_1,paRegisterdevice);
          goto locret_F00D9ABC;
        }
        puVar5 = aAudioNoKernelS_0;
      }
      param_1 = 0;
      _IOLog(puVar5);
      goto locret_F00D9ABC;
    }
  }
loc_F00D9834:
  param_1 = 0;
locret_F00D9ABC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4682 start=0xf00d9ac4 */

/* WARNING: Removing unreachable block (ram,0xf00d9ad4) */

sqword -[IOAudio reset](undefined4 param_1,uint param_2)

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
  _objc_msgSend(param_1,paSubclassrespon,param_2);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4683 start=0xf00d9ae4 */

/* WARNING: Removing unreachable block (ram,0xf00d9b04) */
/* WARNING: Removing unreachable block (ram,0xf00d9b24) */
/* WARNING: Removing unreachable block (ram,0xf00d9af8) */

undefined8 -[IOAudio free](int param_1,undefined4 param_2)

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
  _objc_msgSend(paIoaudio,paSetinstance,0);
  _IOFree(*(undefined4 *)(param_1 + 0x174),0x20);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142258;
  _objc_msgSendSuper(puVar1,paFree);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4684 start=0xf00d9b34 */

undefined8 -[IOAudio sampleRate](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x144));
}
/* GHIDRADEC_FUNCTION index=4685 start=0xf00d9b44 */

undefined8 -[IOAudio dataEncoding](int param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = *(uint *)(param_1 + 0x148);
  if (uVar1 == 1) {
    param_1 = 0x25a;
  }
  else if (uVar1 < 2) {
    param_1 = 600;
  }
  else if (uVar1 == 2) {
    param_1 = 0x25b;
  }
  else if (uVar1 == 3) {
    param_1 = 0x259;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4686 start=0xf00d9b88 */

undefined8 -[IOAudio channelCount](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x14c));
}
/* GHIDRADEC_FUNCTION index=4687 start=0xf00d9b98 */

undefined8 -[IOAudio isInputActive](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x168));
}
/* GHIDRADEC_FUNCTION index=4688 start=0xf00d9ba8 */

undefined8 -[IOAudio isOutputActive](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x169));
}
/* GHIDRADEC_FUNCTION index=4689 start=0xf00d9bb8 */

/* WARNING: Removing unreachable block (ram,0xf00d9bc8) */

undefined8 -[IOAudio interruptOccurredForInput:forOutput:](undefined4 param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paSubclassrespon,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4690 start=0xf00d9bd8 */

undefined8 -[IOAudio timeoutOccurred](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4691 start=0xf00d9be4 */

/* WARNING: Removing unreachable block (ram,0xf00d9bf4) */

sqword -[IOAudio startDMAForChannel:read:buffer:bufferSizeForInterrupts:]
                 (undefined4 param_1,uint param_2)

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
  _objc_msgSend(param_1,paSubclassrespon,param_2);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4692 start=0xf00d9c04 */

/* WARNING: Removing unreachable block (ram,0xf00d9c14) */

undefined8 -[IOAudio stopDMAForChannel:read:](undefined4 param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paSubclassrespon,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4693 start=0xf00d9c24 */

/* WARNING: Removing unreachable block (ram,0xf00d9c58) */
/* WARNING: Removing unreachable block (ram,0xf00d9c44) */
/* WARNING: Removing unreachable block (ram,0xf00d9c64) */
/* WARNING: Removing unreachable block (ram,0xf00d9c30) */

undefined8
-[IOAudio getInputChannelBuffer:size:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
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
  uVar1 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar1,paChannelbuffera);
  *param_3 = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar2,paDescriptorsize);
  uVar1 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar1,paDmacount);
  .umul(uVar2,uVar1);
  *param_4 = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4694 start=0xf00d9c78 */

/* WARNING: Removing unreachable block (ram,0xf00d9cac) */
/* WARNING: Removing unreachable block (ram,0xf00d9c98) */
/* WARNING: Removing unreachable block (ram,0xf00d9cb8) */
/* WARNING: Removing unreachable block (ram,0xf00d9c84) */

undefined8
-[IOAudio getOutputChannelBuffer:size:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
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
  uVar1 = *(undefined4 *)(param_1 + 300);
  _objc_msgSend(uVar1,paChannelbuffera);
  *param_3 = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 300);
  _objc_msgSend(uVar2,paDescriptorsize);
  uVar1 = *(undefined4 *)(param_1 + 300);
  _objc_msgSend(uVar1,paDmacount);
  .umul(uVar2,uVar1);
  *param_4 = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4695 start=0xf00d9ccc */

undefined8 -[IOAudio inputGainLeft](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x150));
}
/* GHIDRADEC_FUNCTION index=4696 start=0xf00d9cdc */

undefined8 -[IOAudio inputGainRight](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x154));
}
/* GHIDRADEC_FUNCTION index=4697 start=0xf00d9cec */

undefined8 -[IOAudio outputAttenuationLeft](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x158));
}
/* GHIDRADEC_FUNCTION index=4698 start=0xf00d9cfc */

undefined8 -[IOAudio outputAttenuationRight](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x15c));
}
/* GHIDRADEC_FUNCTION index=4699 start=0xf00d9d0c */

undefined8 -[IOAudio isOutputMuted](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x16b));
}

