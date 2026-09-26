
/* WARNING: Removing unreachable block (ram,0xf00d9670) */
/* WARNING: Removing unreachable block (ram,0xf00d963c) */
/* WARNING: Removing unreachable block (ram,0xf00d96c0) */
/* WARNING: Removing unreachable block (ram,0xf00d9624) */
/* WARNING: Removing unreachable block (ram,0xf00d9654) */
/* WARNING: Removing unreachable block (ram,0xf00d968c) */
/* WARNING: Removing unreachable block (ram,0xf00d96ac) */

undefined8 -[IOAudio _runExclusiveInputDMA:](int param_1,undefined4 param_2,char param_3)

{
  undefined (*pauVar1) [24];
  undefined (*pauVar2) [56];
  undefined4 uVar3;
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
  
  pauVar1 = paStopdmaforchan;
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
      _objc_msgSend(param_1,pauVar1,uVar3,1);
      unk_F012EEFC._0_1_ = param_3;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x128);
      dword_F012EF00 = 0;
      _objc_msgSend(uVar3,paDescriptorsize);
      iVar4 = param_1;
      dword_F012EF04 = uVar3;
      _objc_msgSend(param_1,paInterruptclear);
      uVar3 = *(undefined4 *)(param_1 + 0x128);
      dword_F012EF08 = iVar4;
      _objc_msgSend(uVar3,paChannelbuffer);
      pauVar2 = paStartdmaforcha;
      uVar5 = *(undefined4 *)(param_1 + 0x128);
      _objc_msgSend(uVar5,paLocalchannel);
      _objc_msgSend(param_1,pauVar2,uVar5,1,uVar3,dword_F012EF04);
      unk_F012EEFC._0_1_ = param_3;
    }
  }
  return CONCAT44(param_2,param_1);
}

