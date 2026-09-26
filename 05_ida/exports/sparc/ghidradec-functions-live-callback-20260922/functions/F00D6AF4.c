
/* WARNING: Removing unreachable block (ram,0xf00d6bc8) */
/* WARNING: Removing unreachable block (ram,0xf00d6bf8) */
/* WARNING: Removing unreachable block (ram,0xf00d6c28) */
/* WARNING: Removing unreachable block (ram,0xf00d6c58) */
/* WARNING: Removing unreachable block (ram,0xf00d6c88) */
/* WARNING: Removing unreachable block (ram,0xf00d6cb8) */
/* WARNING: Removing unreachable block (ram,0xf00d6d20) */
/* WARNING: Removing unreachable block (ram,0xf00d6d00) */
/* WARNING: Removing unreachable block (ram,0xf00d6d88) */
/* WARNING: Removing unreachable block (ram,0xf00d6d68) */
/* WARNING: Removing unreachable block (ram,0xf00d6dc0) */
/* WARNING: Removing unreachable block (ram,0xf00d6df8) */
/* WARNING: Removing unreachable block (ram,0xf00d6e30) */
/* WARNING: Removing unreachable block (ram,0xf00d6e68) */
/* WARNING: Removing unreachable block (ram,0xf00d6ea0) */
/* WARNING: Removing unreachable block (ram,0xf00d6ed8) */
/* WARNING: Removing unreachable block (ram,0xf00d6f10) */
/* WARNING: Removing unreachable block (ram,0xf00d6f48) */
/* WARNING: Removing unreachable block (ram,0xf00d6f80) */
/* WARNING: Removing unreachable block (ram,0xf00d6fb8) */
/* WARNING: Removing unreachable block (ram,0xf00d6ff0) */
/* WARNING: Removing unreachable block (ram,0xf00d7028) */
/* WARNING: Removing unreachable block (ram,0xf00d7060) */
/* WARNING: Removing unreachable block (ram,0xf00d7098) */
/* WARNING: Removing unreachable block (ram,0xf00d70d0) */
/* WARNING: Removing unreachable block (ram,0xf00d7108) */
/* WARNING: Removing unreachable block (ram,0xf00d7140) */
/* WARNING: Removing unreachable block (ram,0xf00d7178) */
/* WARNING: Removing unreachable block (ram,0xf00d71b0) */
/* WARNING: Removing unreachable block (ram,0xf00d71e8) */
/* WARNING: Removing unreachable block (ram,0xf00d7204) */
/* WARNING: Removing unreachable block (ram,0xf00d6b10) */
/* WARNING: Removing unreachable block (ram,0xf00d71d8) */
/* WARNING: Removing unreachable block (ram,0xf00d71a0) */
/* WARNING: Removing unreachable block (ram,0xf00d7168) */
/* WARNING: Removing unreachable block (ram,0xf00d7130) */
/* WARNING: Removing unreachable block (ram,0xf00d70f8) */
/* WARNING: Removing unreachable block (ram,0xf00d70c0) */
/* WARNING: Removing unreachable block (ram,0xf00d7088) */
/* WARNING: Removing unreachable block (ram,0xf00d7050) */
/* WARNING: Removing unreachable block (ram,0xf00d7018) */
/* WARNING: Removing unreachable block (ram,0xf00d6fe0) */
/* WARNING: Removing unreachable block (ram,0xf00d6fa8) */
/* WARNING: Removing unreachable block (ram,0xf00d6f70) */
/* WARNING: Removing unreachable block (ram,0xf00d6f38) */
/* WARNING: Removing unreachable block (ram,0xf00d6f00) */
/* WARNING: Removing unreachable block (ram,0xf00d6ec8) */
/* WARNING: Removing unreachable block (ram,0xf00d6e90) */
/* WARNING: Removing unreachable block (ram,0xf00d6e58) */
/* WARNING: Removing unreachable block (ram,0xf00d6e20) */
/* WARNING: Removing unreachable block (ram,0xf00d6de8) */
/* WARNING: Removing unreachable block (ram,0xf00d6db0) */
/* WARNING: Removing unreachable block (ram,0xf00d6d40) */
/* WARNING: Removing unreachable block (ram,0xf00d6d78) */
/* WARNING: Removing unreachable block (ram,0xf00d6cd8) */
/* WARNING: Removing unreachable block (ram,0xf00d6d10) */
/* WARNING: Removing unreachable block (ram,0xf00d6ca8) */
/* WARNING: Removing unreachable block (ram,0xf00d6c78) */
/* WARNING: Removing unreachable block (ram,0xf00d6c48) */
/* WARNING: Removing unreachable block (ram,0xf00d6c18) */
/* WARNING: Removing unreachable block (ram,0xf00d6be8) */
/* WARNING: Removing unreachable block (ram,0xf00d6bb8) */
/* WARNING: Removing unreachable block (ram,0xf00d7218) */
/* WARNING: Removing unreachable block (ram,0xf00d6b04) */

undefined8 -[IOAudio _commandOccurred](uint param_1,undefined4 param_2)

{
  undefined (*pauVar1) [20];
  undefined (*pauVar2) [14];
  uint uVar3;
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
  
  pauVar2 = paAudiocommand_0;
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
  uVar3 = param_1;
  _objc_msgSend(param_1,paAudiocommand_0);
  _objc_msgSend();
  switch(uVar3) {
  case :
    _objc_msgSend(param_1,paUpdateinputgai_0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateinputgai);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateoutputmu);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateoutputat_0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateoutputat);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateloudness);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    uVar3 = param_1;
    _objc_msgSend(param_1,paIsinputactive_0);
    pauVar1 = paStopdmaforchan_0;
    if ((uVar3 & 0xff) != 0) {
      uVar3 = param_1;
      _objc_msgSend(param_1,paInputchannel);
      _objc_msgSend(param_1,pauVar1,uVar3);
    }
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    uVar3 = param_1;
    _objc_msgSend(param_1,paIsoutputactive_0);
    pauVar1 = paStopdmaforchan_0;
    if ((uVar3 & 0xff) != 0) {
      uVar3 = param_1;
      _objc_msgSend(param_1,paOutputchannel);
      _objc_msgSend(param_1,pauVar1,uVar3);
    }
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1e,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1e,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1f,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1f,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x20,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x20,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x21,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x21,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x22,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x22,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x19,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x19,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1a,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1a,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1b,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1b,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1c,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1c,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1d,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1d,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  :
    _objc_msgSend(param_1,pauVar2);
  }
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}

