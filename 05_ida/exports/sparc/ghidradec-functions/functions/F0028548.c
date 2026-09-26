
/* WARNING: Removing unreachable block (ram,0xf00285d8) */
/* WARNING: Removing unreachable block (ram,0xf0028570) */
/* WARNING: Removing unreachable block (ram,0xf0028578) */
/* WARNING: Removing unreachable block (ram,0xf0028620) */
/* WARNING: Removing unreachable block (ram,0xf0028564) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00285d8 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int __utime(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_o0;
  undefined8 in_o0_1;
  undefined8 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  _getthetime((undefined *)((int)register0x00000038 + -0x58));
  _vattr_null((undefined *)((int)register0x00000038 + -0x50));
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) || (puVar4[1] != 0)) {
    _copyin(iVar1,(int)in_o0_1,8);
    *(char *)(dword_F0133DDC + 0x38) = (char)((qword)in_o0_1 >> 0x20);
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
      return iVar1;
    }
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x30) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x28) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
    in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x58);
    uVar2 = (undefined4)((qword)in_o0_1 >> 0x20);
    *(undefined4 *)((int)register0x00000038 + -0x28) = uVar2;
    *(undefined4 *)((int)register0x00000038 + -0x30) = uVar2;
    *(int *)((int)register0x00000038 + -0x24) = (int)in_o0_1;
    *(int *)((int)register0x00000038 + -0x2c) = (int)in_o0_1;
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 0x80000000;
  }
  _namesetattr(*puVar4,(int)in_o0_1,(undefined *)((int)register0x00000038 + -0x50));
  extraout_o0 = (int)((qword)in_o0_1 >> 0x20);
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0x7fffffff;
  uVar3 = CONCAT44(extraout_o0,extraout_o0);
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) ||
     ((uVar3 = CONCAT44(extraout_o0,extraout_o0), extraout_o0 == 1 &&
      (uVar3 = 0xd00000001, puVar4[1] != 0)))) {
    uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  }
  *(char *)(dword_F0133DDC + 0x38) = (char)((qword)uVar3 >> 0x20);
  return iVar1;
}
