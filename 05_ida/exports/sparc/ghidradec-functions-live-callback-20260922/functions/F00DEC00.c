
/* WARNING: Removing unreachable block (ram,0xf00decbc) */
/* WARNING: Removing unreachable block (ram,0xf00dec94) */
/* WARNING: Removing unreachable block (ram,0xf00dec3c) */
/* WARNING: Removing unreachable block (ram,0xf00dec4c) */
/* WARNING: Removing unreachable block (ram,0xf00deca0) */
/* WARNING: Removing unreachable block (ram,0xf00decdc) */
/* WARNING: Removing unreachable block (ram,0xf00dec20) */

undefined8
__NXAudioRecordStream
          (uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined (*pauVar1) [12];
  undefined8 *puVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
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
  
  puVar2 = paChannel;
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
  if (param_1 == 0) {
    uVar4 = 0xca;
  }
  else {
    uVar4 = param_1;
    _objc_msgSend(param_1,paChannel);
    pauVar1 = paCheckowner;
    uVar3 = param_1;
    _objc_msgSend(param_1,paOwnerport);
    _objc_msgSend(uVar4,pauVar1,uVar3);
    if ((uVar4 & 0xff) == 0) {
      uVar4 = 200;
    }
    else if (param_2 == 0) {
      uVar4 = 0xcc;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x408) = 0x194;
      *(undefined4 *)((int)register0x00000038 + -0x808) = param_4;
      *(undefined4 *)((int)register0x00000038 + -0x404) = 0x193;
      *(undefined4 *)((int)register0x00000038 + -0x804) = param_5;
      _objc_msgSend(param_1,puVar2);
      _objc_msgSend();
      _objc_msgSend();
      _objc_msgSend(param_1,paRecordsizeTagR,param_2,param_3,param_6,
                    *(undefined4 *)((int)register0x00000038 + 0x5c));
      uVar4 = ((param_1 & 0xff) != 0) - 1 & 0xcc;
    }
  }
  return CONCAT44(param_2,uVar4);
}

