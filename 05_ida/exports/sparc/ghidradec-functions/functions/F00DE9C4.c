
/* WARNING: Removing unreachable block (ram,0xf00deb04) */
/* WARNING: Removing unreachable block (ram,0xf00deadc) */
/* WARNING: Removing unreachable block (ram,0xf00dea9c) */
/* WARNING: Removing unreachable block (ram,0xf00dea18) */
/* WARNING: Removing unreachable block (ram,0xf00dea08) */
/* WARNING: Removing unreachable block (ram,0xf00dea90) */
/* WARNING: Removing unreachable block (ram,0xf00deab8) */
/* WARNING: Removing unreachable block (ram,0xf00deaf8) */
/* WARNING: Removing unreachable block (ram,0xf00deb20) */
/* WARNING: Removing unreachable block (ram,0xf00de9ec) */

undefined8
__NXAudioPlayStream(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,
                   undefined4 param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 uVar6;
  undefined4 unaff_l4;
  undefined4 uVar7;
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
  uVar5 = *(undefined4 *)((int)register0x00000038 + 100);
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x70);
  if (param_1 == 0) {
    uVar5 = 0xca;
  }
  else {
    uVar1 = param_1;
    _objc_msgSend(param_1,paChannel);
    uVar4 = paCheckowner;
    uVar2 = param_1;
    _objc_msgSend(param_1,paOwnerport);
    _objc_msgSend(uVar1,uVar4,uVar2);
    if ((uVar1 & 0xff) == 0) {
      uVar5 = 200;
      iVar3 = 0;
    }
    else {
      iVar3 = 0x192;
      if (param_3 != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x408) = 0x192;
        *(undefined4 *)((int)register0x00000038 + -0x808) = param_5;
        *(undefined4 *)((int)register0x00000038 + -0x404) = 0x191;
        if (param_6 == 1) {
          uVar4 = 0x5622;
        }
        else {
          uVar4 = 0xac44;
        }
        *(undefined4 *)((int)register0x00000038 + -0x804) = uVar4;
        *(undefined4 *)((int)register0x00000038 + -0x400) = 0x194;
        *(undefined4 *)((int)register0x00000038 + -0x800) = uVar5;
        *(undefined4 *)((int)register0x00000038 + -0x3fc) = 0x193;
        *(undefined4 *)((int)register0x00000038 + -0x7fc) = uVar6;
        _objc_msgSend(param_1,paChannel);
        _objc_msgSend();
        _objc_msgSend();
        _objc_msgSend(param_1,paPlaybufferSize,param_2,param_3,param_4,
                      *(undefined4 *)((int)register0x00000038 + 0x6c),uVar7);
        uVar5 = 0;
        iVar3 = 0;
        if ((param_1 & 0xff) != 0) goto locret_F00DEB28;
      }
      uVar5 = 0xcc;
    }
    _task_self();
    _vm_deallocate_EXTERNAL();
    if (iVar3 != 0) {
      _IOLog(aAudioAudioServ,aMachErr,iVar3);
    }
  }
locret_F00DEB28:
  return CONCAT44(param_2,uVar5);
}
