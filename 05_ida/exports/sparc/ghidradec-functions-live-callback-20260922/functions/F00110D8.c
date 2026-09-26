
/* WARNING: Removing unreachable block (ram,0xf0011134) */
/* WARNING: Removing unreachable block (ram,0xf0011100) */

undefined8 _sigstack(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar2 = piVar3[1];
  if (iVar2 != 0) {
    iVar1 = _active_u + 0x144;
    _copyout(iVar1,iVar2,8);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0011168;
  }
  iVar2 = *piVar3;
  if (iVar2 != 0) {
    _copyin(iVar2,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    iVar2 = _active_u;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(undefined4 *)(_active_u + 0x144) = *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)(iVar2 + 0x148) = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
locret_F0011168:
  return CONCAT44(param_2,param_1);
}

