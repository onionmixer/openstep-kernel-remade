
/* WARNING: Removing unreachable block (ram,0xf0048630) */
/* WARNING: Removing unreachable block (ram,0xf004856c) */
/* WARNING: Removing unreachable block (ram,0xf0048574) */
/* WARNING: Removing unreachable block (ram,0xf004863c) */
/* WARNING: Removing unreachable block (ram,0xf004853c) */

sqword _spec_fsync(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  iVar6 = *(int *)(param_1 + 0x30);
  if ((*(word *)(iVar6 + 0x40) & 0x46) == 0) {
    if (*(int *)(param_1 + 0x28) != 3) goto locret_F0048658;
    iVar7 = *(int *)(iVar6 + 0x38);
  }
  else {
    iVar7 = *(int *)(iVar6 + 0x38);
  }
  if (iVar7 == 0) goto locret_F0048658;
  iVar1 = 0x40;
  _kalloc();
  iVar2 = *(int *)(iVar6 + 0x38);
  (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))(iVar2,iVar1,param_2);
  if (iVar2 == 0) {
    iVar2 = 0x40;
    _kalloc();
    _vattr_null();
    iVar5 = *(int *)(iVar1 + 0x20);
    iVar3 = *(int *)(iVar6 + 0x4c);
    if (iVar3 < iVar5) {
      *(int *)(iVar2 + 0x20) = iVar5;
loc_F00485B4:
      uVar4 = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      if (iVar5 == iVar3) {
        if (*(int *)(iVar6 + 0x50) < *(int *)(iVar1 + 0x24)) {
          *(int *)(iVar2 + 0x20) = iVar5;
          goto loc_F00485B4;
        }
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 0x4c);
      }
      else {
        *(int *)(iVar2 + 0x20) = iVar3;
      }
      uVar4 = *(undefined4 *)(iVar6 + 0x50);
    }
    *(undefined4 *)(iVar2 + 0x24) = uVar4;
    iVar5 = *(int *)(iVar1 + 0x28);
    iVar3 = *(int *)(iVar6 + 0x54);
    if (iVar3 < iVar5) {
      *(int *)(iVar2 + 0x28) = iVar5;
loc_F0048600:
      uVar4 = *(undefined4 *)(iVar1 + 0x2c);
    }
    else {
      if (iVar5 == iVar3) {
        if (*(int *)(iVar6 + 0x58) < *(int *)(iVar1 + 0x2c)) {
          *(int *)(iVar2 + 0x28) = iVar5;
          goto loc_F0048600;
        }
        *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar6 + 0x54);
      }
      else {
        *(int *)(iVar2 + 0x28) = iVar3;
      }
      uVar4 = *(undefined4 *)(iVar6 + 0x58);
    }
    *(undefined4 *)(iVar2 + 0x2c) = uVar4;
    (**(code **)(*(int *)(iVar7 + 0x1c) + 0x18))(iVar7,iVar2,param_2);
    _kfree(iVar2,0x40);
  }
  _kfree(iVar1,0x40);
  (**(code **)(*(int *)(iVar7 + 0x1c) + 0x48))(iVar7,param_2);
locret_F0048658:
  return (qword)param_2 << 0x20;
}

