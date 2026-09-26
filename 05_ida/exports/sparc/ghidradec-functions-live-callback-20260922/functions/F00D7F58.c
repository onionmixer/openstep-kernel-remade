
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

