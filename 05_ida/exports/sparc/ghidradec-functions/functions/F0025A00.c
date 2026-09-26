
/* WARNING: Removing unreachable block (ram,0xf0025a74) */
/* WARNING: Removing unreachable block (ram,0xf0025a54) */
/* WARNING: Removing unreachable block (ram,0xf0025a6c) */
/* WARNING: Removing unreachable block (ram,0xf0025a9c) */
/* WARNING: Removing unreachable block (ram,0xf0025a18) */

undefined8 _dnlc_enterSymLink(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar4 = param_3[2];
  if ((iVar4 != 0) && (_dnlc_lookupSymLink(param_1,param_2), param_1 != 0)) {
    if (*(char *)(param_1 + 0x44) != '\0') {
      if ((int)*(sword *)(param_1 + 0x46) == param_3[2]) {
        iVar2 = *param_3;
        _bcmp(iVar2,*(undefined4 *)(param_1 + 0x40));
        if (iVar2 == 0) goto locret_F0025AD8;
        uVar1 = *(undefined4 *)(param_1 + 0x40);
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x40);
      }
      _kfree(uVar1,(int)*(sword *)(param_1 + 0x46));
    }
    iVar2 = iVar4;
    _kalloc();
    *(int *)(param_1 + 0x40) = iVar2;
    if (iVar2 != 0) {
      *(undefined *)(param_1 + 0x44) = 1;
      *(sword *)(param_1 + 0x46) = (sword)iVar4;
      _bcopy(*param_3,*(undefined4 *)(param_1 + 0x40),iVar4);
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_1 + 0xc);
      iVar2 = dword_F01355DC;
      iVar3 = *(int *)(dword_F01355DC + 8);
      *(int *)(dword_F01355DC + 8) = param_1;
      *(int *)(param_1 + 8) = iVar3;
      *(int *)(iVar3 + 0xc) = param_1;
      *(int *)(param_1 + 0xc) = iVar2;
    }
  }
locret_F0025AD8:
  return CONCAT44(iVar4,param_1);
}
