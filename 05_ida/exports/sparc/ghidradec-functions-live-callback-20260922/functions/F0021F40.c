
/* WARNING: Removing unreachable block (ram,0xf0022108) */
/* WARNING: Removing unreachable block (ram,0xf002201c) */
/* WARNING: Removing unreachable block (ram,0xf0021f84) */
/* WARNING: Removing unreachable block (ram,0xf0021fa8) */
/* WARNING: Removing unreachable block (ram,0xf0022094) */
/* WARNING: Removing unreachable block (ram,0xf0022110) */
/* WARNING: Removing unreachable block (ram,0xf0021f50) */

undefined8 _pipe(undefined4 param_1,undefined4 param_2)

{
  undefined uVar5;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar6;
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
  uVar5 = 1;
  _socreate(1,(undefined *)((int)register0x00000038 + -0xc),1,0);
  *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    uVar5 = 1;
    _socreate(1,(undefined *)((int)register0x00000038 + -0x10),1,0);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
    iVar1 = (int)*(char *)(dword_F0133DDC + 0x38);
    if (iVar1 == 0) {
      _falloc();
      if (iVar1 != 0) {
        iVar6 = *(int *)(dword_F0133DDC + 0x30);
        *(undefined4 *)(iVar1 + 8) = 1;
        if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
          *(undefined4 *)(iVar1 + 8) = 0x2001;
        }
        *(undefined2 *)(iVar1 + 0xc) = 2;
        uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        *(undefined **)(iVar1 + 0x14) = _socketops;
        *(undefined4 *)(iVar1 + 0x18) = uVar2;
        iVar3 = *(int *)(dword_F0133DDC + 0x30) * 4;
        *(int *)(_active_u[0x53] + iVar3) = iVar1;
        _falloc();
        if (iVar3 == 0) {
          *(undefined2 *)(iVar1 + 0xe) = 0;
        }
        else {
          *(undefined4 *)(iVar3 + 8) = 2;
          if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
            *(undefined4 *)(iVar3 + 8) = 0x2002;
          }
          *(undefined2 *)(iVar3 + 0xc) = 2;
          uVar4 = *(uint *)((int)register0x00000038 + -0x10);
          *(undefined **)(iVar3 + 0x14) = _socketops;
          *(uint *)(iVar3 + 0x18) = uVar4;
          *(int *)(_active_u[0x53] + *(int *)(dword_F0133DDC + 0x30) * 4) = iVar3;
          *(undefined4 *)(dword_F0133DDC + 0x34) = *(undefined4 *)(dword_F0133DDC + 0x30);
          uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
          *(int *)(dword_F0133DDC + 0x30) = iVar6;
          _unp_connect2(uVar4,uVar2);
          *(char *)(dword_F0133DDC + 0x38) = (char)uVar4;
          if ((uVar4 & 0xff) == 0) {
            iVar1 = *(int *)((int)register0x00000038 + -0xc);
            *(word *)(*(int *)((int)register0x00000038 + -0x10) + 6) =
                 *(word *)(*(int *)((int)register0x00000038 + -0x10) + 6) | 0x20;
            *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x10;
            goto locret_F0022118;
          }
          *(undefined2 *)(iVar3 + 0xe) = 0;
          *(undefined4 *)(_active_u[0x53] + *(int *)(dword_F0133DDC + 0x34) * 4) = 0;
          *(undefined2 *)(iVar1 + 0xe) = 0;
        }
        *(undefined4 *)(_active_u[0x53] + iVar6 * 4) = 0;
      }
      _soclose(*(undefined4 *)((int)register0x00000038 + -0x10));
    }
    _soclose(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
locret_F0022118:
  return CONCAT44(param_2,param_1);
}

