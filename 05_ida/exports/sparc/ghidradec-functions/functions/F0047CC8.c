
/* WARNING: Removing unreachable block (ram,0xf0047dcc) */
/* WARNING: Removing unreachable block (ram,0xf0047d40) */
/* WARNING: Removing unreachable block (ram,0xf0047d18) */
/* WARNING: Removing unreachable block (ram,0xf0047e18) */
/* WARNING: Removing unreachable block (ram,0xf0047dd4) */
/* WARNING: Removing unreachable block (ram,0xf0047cec) */

undefined8 sub_F0047CC8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  int iVar7;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(int *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  if (param_3 < 2) {
    iVar2 = dword_F0133DDC + 0x28;
    _setjmp();
    if (iVar2 != 0) {
      *(word *)(*(int *)(*(int *)((int)register0x00000038 + 0x44) + 0x30) + 0x40) =
           *(word *)(*(int *)(*(int *)((int)register0x00000038 + 0x44) + 0x30) + 0x40) & 0xfff7;
      _wakeup();
      uVar6 = 4;
      goto locret_F0047E24;
    }
    iVar4 = *(int *)((int)register0x00000038 + 0x44);
    iVar7 = *(int *)(iVar4 + 0x30);
    iVar2 = (int)*(sword *)(iVar7 + 0x42);
    *(int *)(iVar7 + 100) = *(int *)(iVar7 + 100) + -1;
    _stillopen(iVar2,*(undefined4 *)(iVar4 + 0x28));
    if (iVar2 != 0) {
      uVar6 = 0;
      goto locret_F0047E24;
    }
    wVar1 = *(word *)(iVar7 + 0x42);
    uVar3 = *(uint *)(*(int *)((int)register0x00000038 + 0x44) + 0x28);
    *(word *)((int)register0x00000038 + -10) = wVar1;
    if (uVar3 == 4) {
      iVar2 = (uint)(wVar1 >> 8) * 0x2c;
      puVar5 = _cdevsw;
      uVar6 = *(undefined4 *)((int)register0x00000038 + 0x48);
    }
    else {
      if (4 < uVar3) {
        if (uVar3 != 8) {
          uVar6 = 0;
          goto locret_F0047E24;
        }
        _printf(aSpecCloseGotAV);
        goto loc_F0047E20;
      }
      if (uVar3 != 3) {
        uVar6 = 0;
        goto locret_F0047E24;
      }
      _bflush(*(undefined4 *)(iVar7 + 0x3c),0xffffffff,0xffffffff);
      _binval(*(undefined4 *)(iVar7 + 0x3c));
      wVar1 = *(word *)((int)register0x00000038 + -10);
      uVar6 = *(undefined4 *)((int)register0x00000038 + 0x48);
      iVar2 = (uint)(wVar1 >> 8) * 0x18;
      puVar5 = _bdevsw;
    }
    (**(code **)(puVar5 + iVar2 + 4))((int)(sword)wVar1,uVar6);
    uVar6 = 0;
  }
  else {
loc_F0047E20:
    uVar6 = 0;
  }
locret_F0047E24:
  return CONCAT44(param_2,uVar6);
}
