
/* WARNING: Removing unreachable block (ram,0xf00b92c0) */
/* WARNING: Removing unreachable block (ram,0xf00b9280) */
/* WARNING: Removing unreachable block (ram,0xf00b92dc) */
/* WARNING: Removing unreachable block (ram,0xf00b9268) */

undefined8
_get_pktiopb(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  int iVar3;
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
  iVar3 = *(int *)((int)register0x00000038 + 0x5c);
  iVar1 = 0;
  if (((iVar3 == 1) || (iVar3 == 0)) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    _bzero((undefined *)((int)register0x00000038 + -0x50),0x44);
    uVar2 = param_5 + 3U & 0xfffffffc;
    iVar1 = _iopbmap;
    _rmalloc(_iopbmap,uVar2);
    *(int *)((int)register0x00000038 + -0x30) = iVar1;
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      if (param_6 != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x50) = 1;
      }
      *(int *)((int)register0x00000038 + -0x3c) = param_5;
      _scsi_resalloc(param_1,param_3,param_4,(undefined *)((int)register0x00000038 + -0x50),iVar3);
      iVar1 = param_1;
      if (param_1 == 0) {
        _rmfree(_iopbmap,uVar2,*(undefined4 *)((int)register0x00000038 + -0x30));
      }
      else {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0x30);
      }
    }
  }
  return CONCAT44(param_2,iVar1);
}
