
/* WARNING: Removing unreachable block (ram,0xf00de938) */
/* WARNING: Removing unreachable block (ram,0xf00de884) */
/* WARNING: Removing unreachable block (ram,0xf00de894) */
/* WARNING: Removing unreachable block (ram,0xf00de924) */
/* WARNING: Removing unreachable block (ram,0xf00de868) */

undefined8 __NXAudioStreamControl(uint param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
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
  if (param_1 == 0) {
    uVar3 = 0xca;
  }
  else {
    uVar1 = param_1;
    _objc_msgSend(param_1,paChannel);
    uVar3 = paCheckowner;
    uVar2 = param_1;
    _objc_msgSend(param_1,paOwnerport);
    _objc_msgSend(uVar1,uVar3,uVar2);
    if ((uVar1 & 0xff) == 0) {
      uVar3 = 200;
    }
    else {
      if (param_2 == 1) {
        uVar3 = 1;
      }
      else if (param_2 < 2) {
        if (param_2 != 0) {
          uVar3 = 0xce;
          goto locret_F00DE944;
        }
        uVar3 = 0;
      }
      else {
        if (param_2 != 2) {
          if (param_2 == 3) {
            _objc_msgSend(param_1,paReturnrecorded);
            uVar3 = 0;
          }
          else {
            uVar3 = 0xce;
          }
          goto locret_F00DE944;
        }
        uVar3 = 2;
      }
      *(undefined4 *)((int)register0x00000038 + -0x10) = *param_3;
      *(undefined4 *)((int)register0x00000038 + -0xc) = param_3[1];
      _objc_msgSend(param_1,paControlAttime,uVar3,(undefined *)((int)register0x00000038 + -0x10));
      uVar3 = 0;
    }
  }
locret_F00DE944:
  return CONCAT44(param_2,uVar3);
}
