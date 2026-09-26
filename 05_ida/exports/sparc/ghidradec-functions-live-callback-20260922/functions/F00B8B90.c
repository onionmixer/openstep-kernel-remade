
/* WARNING: Removing unreachable block (ram,0xf00b8cd4) */
/* WARNING: Removing unreachable block (ram,0xf00b8ce4) */
/* WARNING: Removing unreachable block (ram,0xf00b8c98) */
/* WARNING: Removing unreachable block (ram,0xf00b8ccc) */
/* WARNING: Removing unreachable block (ram,0xf00b8c2c) */
/* WARNING: Removing unreachable block (ram,0xf00b8c3c) */

undefined8 _scsi_std_dmaget(int param_1,uint *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  word wVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
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
  *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) & 0xfff8;
  uVar4 = param_2[8];
  if ((((uVar4 < 0xfff00000) || (uVar5 = _dvmasize * 0x1000 - 0x100000, uVar5 <= uVar4)) ||
      (uVar4 + param_2[5] < 0xfff00000)) || (uVar5 <= (uVar4 + param_2[5]) - 1)) {
    if (param_3 != 1) {
      uVar1 = _scsi_spl;
      _splr(_scsi_spl);
      if ((dword_F01317E4 != 0) || (dword_F01317D4 == 0)) {
        if (param_3 == 0) {
          pcVar6 = (code *)0x0;
        }
        else {
          pcVar6 = sub_F00B8D20;
        }
        iVar2 = _dvmamap;
        _mb_mapalloc(_dvmamap,param_2,0x41,pcVar6,0);
        *(int *)(param_1 + 0x3c) = iVar2;
        if (iVar2 != 0) {
          _splx(uVar1);
          goto loc_F00B8CEC;
        }
      }
      if (param_3 != 0) {
        sub_F00B8E1C(&dword_F01317D4,param_3);
      }
      _splx(uVar1);
      param_1 = 0;
      goto locret_F00B8D18;
    }
    iVar2 = _dvmamap;
    _mb_mapalloc(_dvmamap,param_2,0x40,0,0);
    *(int *)(param_1 + 0x3c) = iVar2;
  }
  else {
    *(uint *)(param_1 + 0x3c) = uVar4 + 0x100000;
    *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) | 4;
  }
loc_F00B8CEC:
  *(uint *)(param_1 + 0x40) = param_2[5];
  wVar3 = *(word *)(param_1 + 0x5c);
  if ((*param_2 & 1) == 0) {
    *(word *)(param_1 + 0x5c) = wVar3 | 2;
    wVar3 = *(word *)(param_1 + 0x5c);
  }
  *(word *)(param_1 + 0x5c) = wVar3 | 1;
locret_F00B8D18:
  return CONCAT44(param_2,param_1);
}

