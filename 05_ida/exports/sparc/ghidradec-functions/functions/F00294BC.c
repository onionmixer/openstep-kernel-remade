
/* WARNING: Removing unreachable block (ram,0xf002953c) */
/* WARNING: Removing unreachable block (ram,0xf0029530) */
/* WARNING: Removing unreachable block (ram,0xf002956c) */
/* WARNING: Removing unreachable block (ram,0xf00294dc) */

undefined8 _ustat(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  uint *puVar5;
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
  puVar5 = *(uint **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar5 & 0xffff;
  _vafsidtovfs(uVar1,(undefined *)((int)register0x00000038 + -100));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  iVar2 = *(int *)((int)register0x00000038 + -100);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    (**(code **)(*(int *)(iVar2 + 4) + 0xc))(iVar2,(undefined *)((int)register0x00000038 + -0x48));
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    puVar4 = (undefined *)((int)register0x00000038 + -0x60);
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _bzero(puVar4,0x14);
      iVar3 = *(int *)((int)register0x00000038 + -0x38);
      .umul(iVar3,*(undefined4 *)((int)register0x00000038 + -0x44));
      iVar2 = iVar3 + 0x1ff;
      if (iVar2 < 0) {
        iVar2 = iVar3 + 0x3fe;
      }
      *(int *)((int)register0x00000038 + -0x60) = iVar2 >> 9;
      *(undefined4 *)((int)register0x00000038 + -0x5c) =
           *(undefined4 *)((int)register0x00000038 + -0x30);
      _copyout(puVar4,puVar5[1],0x14);
      *(char *)(dword_F0133DDC + 0x38) = (char)puVar4;
    }
  }
  return CONCAT44(param_2,param_1);
}
