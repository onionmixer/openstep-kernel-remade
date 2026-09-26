
/* WARNING: Removing unreachable block (ram,0xf00215dc) */
/* WARNING: Removing unreachable block (ram,0xf0021568) */
/* WARNING: Removing unreachable block (ram,0xf00214e4) */
/* WARNING: Removing unreachable block (ram,0xf002146c) */
/* WARNING: Removing unreachable block (ram,0xf002143c) */
/* WARNING: Removing unreachable block (ram,0xf0021490) */
/* WARNING: Removing unreachable block (ram,0xf0021530) */
/* WARNING: Removing unreachable block (ram,0xf002159c) */
/* WARNING: Removing unreachable block (ram,0xf00215e4) */
/* WARNING: Removing unreachable block (ram,0xf002140c) */

undefined8 _socketpair(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar5;
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
  puVar5 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = puVar5[3];
  _useracc(iVar1,8,0);
  if (iVar1 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
    goto locret_F00215EC;
  }
  uVar2 = *puVar5;
  _socreate(uVar2,(undefined *)((int)register0x00000038 + -0x14),puVar5[1],puVar5[2]);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00215EC;
  uVar2 = *puVar5;
  _socreate(uVar2,(undefined *)((int)register0x00000038 + -0x18),puVar5[1],puVar5[2]);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  iVar1 = (int)*(char *)(dword_F0133DDC + 0x38);
  if (iVar1 == 0) {
    _falloc();
    if (iVar1 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(dword_F0133DDC + 0x30);
      *(undefined4 *)(iVar1 + 8) = 3;
      *(undefined2 *)(iVar1 + 0xc) = 2;
      uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
      *(undefined **)(iVar1 + 0x14) = _socketops;
      *(undefined4 *)(iVar1 + 0x18) = uVar2;
      iVar3 = *(int *)(dword_F0133DDC + 0x30) * 4;
      *(int *)(*(int *)(_active_u + 0x14c) + iVar3) = iVar1;
      _falloc();
      if (iVar3 == 0) {
        *(undefined2 *)(iVar1 + 0xe) = 0;
      }
      else {
        *(undefined4 *)(iVar3 + 8) = 3;
        *(undefined2 *)(iVar3 + 0xc) = 2;
        uVar2 = *(undefined4 *)((int)register0x00000038 + -0x18);
        *(undefined **)(iVar3 + 0x14) = _socketops;
        *(undefined4 *)(iVar3 + 0x18) = uVar2;
        *(int *)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) = iVar3;
        uVar4 = (undefined)*(undefined4 *)((int)register0x00000038 + -0x14);
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(dword_F0133DDC + 0x30);
        _soconnect2();
        *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          if (puVar5[1] == 2) {
            uVar2 = *(undefined4 *)((int)register0x00000038 + -0x18);
            _soconnect2(uVar2,*(undefined4 *)((int)register0x00000038 + -0x14));
            *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
            if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
              *(undefined2 *)(iVar3 + 0xe) = 0;
              goto loc_F00215A8;
            }
          }
          *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
          _copyout((undefined *)((int)register0x00000038 + -0x10),puVar5[3],8);
          goto locret_F00215EC;
        }
        *(undefined2 *)(iVar3 + 0xe) = 0;
loc_F00215A8:
        *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)((int)register0x00000038 + -0xc) * 4)
             = 0;
        *(undefined2 *)(iVar1 + 0xe) = 0;
      }
      *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)((int)register0x00000038 + -0x10) * 4) =
           0;
    }
    _soclose(*(undefined4 *)((int)register0x00000038 + -0x18));
  }
  _soclose(*(undefined4 *)((int)register0x00000038 + -0x14));
locret_F00215EC:
  return CONCAT44(param_2,param_1);
}

