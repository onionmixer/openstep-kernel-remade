
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

