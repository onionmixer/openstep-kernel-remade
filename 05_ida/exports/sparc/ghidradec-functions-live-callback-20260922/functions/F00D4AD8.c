
/* WARNING: Removing unreachable block (ram,0xf00d4cf4) */
/* WARNING: Removing unreachable block (ram,0xf00d4bf8) */
/* WARNING: Removing unreachable block (ram,0xf00d4c38) */
/* WARNING: Removing unreachable block (ram,0xf00d4ca4) */
/* WARNING: Removing unreachable block (ram,0xf00d4c94) */
/* WARNING: Removing unreachable block (ram,0xf00d4b7c) */
/* WARNING: Removing unreachable block (ram,0xf00d4b0c) */
/* WARNING: Removing unreachable block (ram,0xf00d4b2c) */
/* WARNING: Removing unreachable block (ram,0xf00d4ce4) */
/* WARNING: Removing unreachable block (ram,0xf00d4c68) */
/* WARNING: Removing unreachable block (ram,0xf00d4c28) */
/* WARNING: Removing unreachable block (ram,0xf00d4be8) */
/* WARNING: Removing unreachable block (ram,0xf00d4cb4) */
/* WARNING: Removing unreachable block (ram,0xf00d4d1c) */
/* WARNING: Removing unreachable block (ram,0xf00d4ae8) */

undefined8
-[EventDriver keyboardSpecialEvent:flags:keyCode:specialty:atTime:]
          (int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined (*pauVar1) [16];
  undefined (*pauVar2) [15];
  undefined4 uVar3;
  undefined (*pauVar4) [12];
  undefined4 unaff_l0;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l1;
  uint uVar7;
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
  uVar5 = *(uint *)((int)register0x00000038 + 0x5c);
  uVar7 = *(uint *)((int)register0x00000038 + 0x60);
  _bzero((undefined *)((int)register0x00000038 + -0x20),0xc);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,uVar5 >> 0x18);
  iVar6 = -1;
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
    goto locret_F00D4D24;
  }
  *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
       *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_4 & 0x7f007f;
  if (*(char *)(param_1 + 0x1d3) == '\x01') {
    _objc_msgSend(param_1,paForceautodimst,0);
  }
  pauVar2 = paSetbrightness;
  pauVar1 = paSetaudiovolume;
  if (param_3 != 10) {
    uVar3 = *(undefined4 *)(param_1 + 0x110);
    goto loc_F00D4CF0;
  }
  pauVar4 = paAudiovolume;
  switch(param_6) {
  case :
    if ((param_4 & 0x1c0000) == 0) {
      iVar6 = param_1;
      _objc_msgSend(param_1,paAudiovolume);
      _objc_msgSend(param_1,pauVar1,iVar6 + 1);
      pauVar4 = paAudiovolume;
    }
    break;
  case :
    if ((param_4 & 0x1c0000) == 0) {
      iVar6 = param_1;
      _objc_msgSend(param_1,paAudiovolume);
      _objc_msgSend(param_1,pauVar1,iVar6 + -1);
      pauVar4 = paAudiovolume;
    }
    break;
  case :
    pauVar4 = (undefined (*) [12])paBrightness;
    if ((param_4 & 0x1c0000) == 0) {
      iVar6 = param_1;
      _objc_msgSend(param_1,paBrightness);
      iVar6 = iVar6 + 1;
loc_F00D4CA0:
      _objc_msgSend(param_1,pauVar2,iVar6);
      pauVar4 = (undefined (*) [12])paBrightness;
    }
    break;
  case :
    pauVar4 = (undefined (*) [12])paBrightness;
    if ((param_4 & 0x1c0000) == 0) {
      iVar6 = param_1;
      _objc_msgSend(param_1,paBrightness);
      iVar6 = iVar6 + -1;
      goto loc_F00D4CA0;
    }
    break;
  :
    goto def_F00D4BA8;
  case :
    *(undefined2 *)((int)register0x00000038 + -0x1e) = 1;
    _objc_msgSend(param_1,paPosteventAtAtt,0xe,param_1 + 0x1a8,uVar5 << 8 | uVar7 >> 0x18,
                  (undefined *)((int)register0x00000038 + -0x20));
    goto def_F00D4BA8;
  }
  iVar6 = param_1;
  _objc_msgSend(param_1,pauVar4);
def_F00D4BA8:
  uVar3 = *(undefined4 *)(param_1 + 0x110);
loc_F00D4CF0:
  _objc_msgSend(uVar3,paUnlock);
  if (iVar6 != -1) {
    _objc_msgSend(param_1,paEvspecialkeyms,param_6,param_3,param_4,iVar6);
  }
locret_F00D4D24:
  return CONCAT44(param_2,param_1);
}

