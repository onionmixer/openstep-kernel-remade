
/* WARNING: Removing unreachable block (ram,0xf00d4ee8) */
/* WARNING: Removing unreachable block (ram,0xf00d4e0c) */
/* WARNING: Removing unreachable block (ram,0xf00d4ec0) */
/* WARNING: Removing unreachable block (ram,0xf00d4e34) */

undefined8
-[EventDriver _setButtonState:atTime:]
          (int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x168);
  if ((*(uint *)(iVar2 + 8) & 4) != (param_3 & 4)) {
    if ((param_3 & 4) == 0) {
      _objc_msgSend(param_1,paPosteventAtAtt,2,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) & 0xfffffffb;
    }
    else {
      _objc_msgSend(param_1,paPosteventAtAtt,1,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) | 4;
    }
    *(uint *)(iVar2 + 8) = uVar1;
    *(byte *)(iVar2 + 0x33) = *(byte *)(iVar2 + 0x33) & 0xfd | *(byte *)(iVar2 + 0x33) >> 1 & 2;
    if ((*(byte *)(iVar2 + 0x33) & 2) == 0) {
      uVar1 = *(uint *)(iVar2 + 0xc) & 0xfffffeff;
    }
    else {
      uVar1 = *(uint *)(iVar2 + 0xc) | 0x100;
    }
    *(uint *)(iVar2 + 0xc) = uVar1;
  }
  if ((*(uint *)(iVar2 + 8) & 1) != (param_3 & 1)) {
    if ((param_3 & 1) == 0) {
      _objc_msgSend(param_1,paPosteventAtAtt,4,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) & 0xfffffffe;
    }
    else {
      _objc_msgSend(param_1,paPosteventAtAtt,3,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) | 1;
    }
    *(uint *)(iVar2 + 8) = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
