
/* WARNING: Removing unreachable block (ram,0xf00b8910) */
/* WARNING: Removing unreachable block (ram,0xf00b88f4) */
/* WARNING: Removing unreachable block (ram,0xf00b8970) */
/* WARNING: Removing unreachable block (ram,0xf00b88e0) */

undefined8 _scsi_addcmds(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = param_1 * 0x70;
  _kalloc();
  if (iVar5 != 0) {
    _bzero();
    _scsi_ncmds = _scsi_ncmds + param_1;
    uVar1 = _scsi_spl;
    _splr(_scsi_spl);
    iVar3 = 0;
    if (0 < param_1 + -1) {
      iVar4 = 0x70;
      iVar2 = 0;
      do {
        *(int *)(iVar2 + iVar5) = iVar5 + iVar4;
        iVar4 = iVar4 + 0x70;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x70;
      } while (iVar3 < param_1 + -1);
    }
    *(int *)(param_1 * 0x70 + iVar5 + -0x70) = dword_F013179C;
    dword_F013179C = iVar5;
    _splx(uVar1);
  }
  return CONCAT44(param_2,param_1);
}

