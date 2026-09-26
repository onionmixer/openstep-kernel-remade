
/* WARNING: Removing unreachable block (ram,0xf003d3d8) */
/* WARNING: Removing unreachable block (ram,0xf003d40c) */
/* WARNING: Removing unreachable block (ram,0xf003d394) */

undefined8 sub_F003D2E0(int param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = *(int *)(_rtable +
                  ((byte)(*(byte *)(param_1 + 0x1b) ^
                         *(byte *)(param_1 + 0x1a) ^
                         *(byte *)(param_1 + 0x19) ^
                         *(byte *)(param_1 + 0x18) ^
                         *(byte *)(param_1 + 0x17) ^
                         *(byte *)(param_1 + 0x16) ^
                         *(byte *)(param_1 + 0x15) ^
                         *(byte *)(param_1 + 0x14) ^
                         *(byte *)(param_1 + 0x11) ^
                         *(byte *)(param_1 + 0x10) ^
                         *(byte *)(param_1 + 0xf) ^
                         *(byte *)(param_1 + 0xe) ^
                         *(byte *)(param_1 + 0xd) ^
                         *(byte *)(param_1 + 0xc) ^
                         *(byte *)(param_1 + 10) ^ *(byte *)(param_1 + 0xb)) & 0x3f) * 4);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    do {
      iVar1 = iVar3 + 0x40;
      _bcmp(iVar1,param_1,0x20);
      if (iVar1 == 0) {
        if (param_2 == *(int *)(iVar3 + 0x30)) {
          sVar2 = *(sword *)(iVar3 + 0x12) + 1;
          *(sword *)(iVar3 + 0x12) = sVar2;
          if (sVar2 == 1) {
            sub_F003D214(iVar3);
            iVar1 = *(int *)(*(int *)(iVar3 + 0x30) + 0x128);
            _rreactive._0_4_ = _rreactive._0_4_ + 1;
            *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
          }
          else {
            _ractive._0_4_ = _ractive._0_4_ + 1;
          }
          sub_F003D214(iVar3);
          goto locret_F003D428;
        }
        iVar3 = *(int *)(iVar3 + 8);
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
    } while (iVar3 != 0);
    iVar3 = 0;
  }
locret_F003D428:
  return CONCAT44(param_2,iVar3);
}

