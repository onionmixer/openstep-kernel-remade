
/* WARNING: Removing unreachable block (ram,0xf0027ce4) */
/* WARNING: Removing unreachable block (ram,0xf0027d18) */
/* WARNING: Removing unreachable block (ram,0xf0027c14) */

undefined8 _getdirentries(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
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
  uVar1 = *puVar4;
  _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0x2c));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if ((*(uint *)(*(int *)((int)register0x00000038 + -0x2c) + 8) & 1) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 9;
    }
    else {
      uVar1 = puVar4[1];
      while( true ) {
        *(undefined4 *)((int)register0x00000038 + -0x28) = uVar1;
        iVar3 = *(int *)((int)register0x00000038 + -0x2c);
        *(undefined4 *)((int)register0x00000038 + -0x24) = puVar4[2];
        *(undefined **)((int)register0x00000038 + -0x20) =
             (undefined *)((int)register0x00000038 + -0x28);
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
        iVar2 = *(int *)(iVar3 + 0x1c);
        *(int *)((int)register0x00000038 + -0x18) = iVar2;
        *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
        *(undefined4 *)((int)register0x00000038 + -0xc) = puVar4[2];
        if (iVar2 < 0) break;
        iVar2 = *(int *)(iVar3 + 0x18);
        (**(code **)(*(int *)(iVar2 + 0x1c) + 0x3c))
                  (iVar2,(undefined *)((int)register0x00000038 + -0x20),
                   *(undefined4 *)(iVar3 + 0x20));
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        if (puVar4[2] != *(int *)((int)register0x00000038 + -0xc)) goto loc_F0027CFC;
        *(undefined4 *)(*(int *)((int)register0x00000038 + -0x2c) + 0x1c) = 0xfffffc00;
        uVar1 = puVar4[1];
      }
      uVar1 = *(undefined4 *)(iVar3 + 0x18);
      _getfakedirentries(uVar1,(undefined *)((int)register0x00000038 + -0x20),
                         *(undefined4 *)(iVar3 + 0x20));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
loc_F0027CFC:
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        iVar2 = *(int *)((int)register0x00000038 + -0x2c) + 0x1c;
        _copyout(iVar2,puVar4[3],4);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        iVar2 = *(int *)((int)register0x00000038 + -0x2c);
        *(int *)(dword_F0133DDC + 0x30) = puVar4[2] - *(int *)((int)register0x00000038 + -0xc);
        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)((int)register0x00000038 + -0x18);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

