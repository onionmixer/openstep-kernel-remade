
/* WARNING: Removing unreachable block (ram,0xf003bca8) */

undefined8 sub_F003BBE8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  if (_rfssize == 0) {
    iVar1 = 0;
    puVar3 = &_nfs_portmon;
    do {
      puVar2 = (undefined4 *)(_rfsdisptab + iVar1);
      if (puVar2 < puVar3) {
        piVar4 = (int *)(_rfsdisptab + iVar1 + 0x10);
        do {
          if (_rfssize < piVar4[-2]) {
            _rfssize = piVar4[-2];
          }
          if (_rfssize < *piVar4) {
            _rfssize = *piVar4;
          }
          puVar2 = puVar2 + 6;
          piVar4 = piVar4 + 6;
        } while (puVar2 < (undefined4 *)((int)&_nfs_portmon + iVar1));
      }
      puVar3 = puVar3 + 0x6c;
      iVar1 = iVar1 + 0x1b0;
    } while ((int)puVar3 < -0xfef33bb);
  }
  if (_rfsfreesp == (int *)0x0) {
    iVar1 = _rfssize + 4;
    _kalloc(iVar1);
    piVar4 = (int *)(iVar1 + 4);
  }
  else {
    piVar4 = _rfsfreesp;
    _rfsfreesp = (int *)*_rfsfreesp;
  }
  return CONCAT44(param_2,piVar4);
}

