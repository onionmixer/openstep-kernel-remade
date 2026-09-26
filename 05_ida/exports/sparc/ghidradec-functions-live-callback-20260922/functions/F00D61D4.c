
/* WARNING: Removing unreachable block (ram,0xf00d62c4) */
/* WARNING: Removing unreachable block (ram,0xf00d62a0) */
/* WARNING: Removing unreachable block (ram,0xf00d6244) */
/* WARNING: Removing unreachable block (ram,0xf00d62d4) */
/* WARNING: Removing unreachable block (ram,0xf00d61e0) */

undefined8
-[KeyMap doKeyboardEvent:direction:keyBits:]
          (int param_1,undefined4 param_2,uint param_3,char param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  undefined (*pauVar3) [22];
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),paLock);
  if (*(int *)(param_1 + 0x4ec) != 0) {
    bVar1 = *(byte *)(param_1 + param_3 + 6);
    if (param_4 == 1) {
      iVar2 = (param_3 >> 5) * 4;
      *(uint *)(param_5 + iVar2) = *(uint *)(param_5 + iVar2) | 1 << ((byte)param_3 & 0x1f);
      if ((bVar1 & 0x10) != 0) {
        _objc_msgSend(param_1,paDomodcalcKeybi,param_3,param_5);
      }
      if ((bVar1 & 0x20) == 0) goto loc_F00D62CC;
      param_5 = 1;
      pauVar3 = paDochargenDirec;
    }
    else {
      iVar2 = (param_3 >> 5) * 4;
      *(uint *)(param_5 + iVar2) = *(uint *)(param_5 + iVar2) & ~(1 << ((byte)param_3 & 0x1f));
      if ((bVar1 & 0x20) != 0) {
        _objc_msgSend(param_1,paDochargenDirec,param_3,(int)param_4);
      }
      pauVar3 = (undefined (*) [22])paDomodcalcKeybi;
      if ((bVar1 & 0x10) == 0) goto loc_F00D62CC;
    }
    _objc_msgSend(param_1,pauVar3,param_3,param_5);
  }
loc_F00D62CC:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),paUnlock);
  return CONCAT44(param_2,param_1);
}

