
/* WARNING: Removing unreachable block (ram,0xf00de4d0) */
/* WARNING: Removing unreachable block (ram,0xf00de478) */
/* WARNING: Removing unreachable block (ram,0xf00de44c) */
/* WARNING: Removing unreachable block (ram,0xf00de4a4) */
/* WARNING: Removing unreachable block (ram,0xf00de4fc) */
/* WARNING: Removing unreachable block (ram,0xf00de430) */

undefined8 __NXAudioGetSndoutOptions(int param_1,uint *param_2)

{
  undefined (*pauVar1) [33];
  undefined (*pauVar2) [12];
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  pauVar2 = paAudiodevice;
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
    uVar5 = 0xca;
  }
  else {
    *param_2 = 0;
    iVar3 = param_1;
    _objc_msgSend(param_1,pauVar2);
    pauVar1 = paIntvalueforpar;
    iVar4 = iVar3;
    _objc_msgSend();
    if (iVar4 != 0) {
      *param_2 = *param_2 | 1;
    }
    iVar4 = iVar3;
    _objc_msgSend(iVar3,pauVar1,3,param_1);
    if (iVar4 != 0) {
      *param_2 = *param_2 | 2;
    }
    iVar4 = iVar3;
    _objc_msgSend(iVar3,pauVar1,4,param_1);
    if (iVar4 != 0) {
      *param_2 = *param_2 | 4;
    }
    iVar4 = iVar3;
    _objc_msgSend(iVar3,pauVar1,6,param_1);
    if (iVar4 != 0) {
      *param_2 = *param_2 | 8;
    }
    _objc_msgSend(iVar3,pauVar1,7,param_1);
    uVar5 = 0;
    if (iVar3 == 0) {
      *param_2 = *param_2 | 0x10;
    }
  }
  return CONCAT44(param_2,uVar5);
}

