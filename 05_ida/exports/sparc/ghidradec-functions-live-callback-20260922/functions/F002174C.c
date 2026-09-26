
/* WARNING: Removing unreachable block (ram,0xf00218e4) */
/* WARNING: Removing unreachable block (ram,0xf0021848) */
/* WARNING: Removing unreachable block (ram,0xf00217b4) */
/* WARNING: Removing unreachable block (ram,0xf0021800) */
/* WARNING: Removing unreachable block (ram,0xf00218b4) */
/* WARNING: Removing unreachable block (ram,0xf00218fc) */
/* WARNING: Removing unreachable block (ram,0xf0021750) */

undefined8 _sendit(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  piVar1 = param_1;
  _getsock();
  iVar6 = 0;
  if (piVar1 == (int *)0x0) goto locret_F0021904;
  *(int *)((int)register0x00000038 + -0x20) = param_2[2];
  *(int *)((int)register0x00000038 + -0x1c) = param_2[3];
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined2 *)((int)register0x00000038 + -0x10) = 0;
  param_1 = (int *)param_2[2];
  if (0 < param_2[3]) {
    piVar5 = param_1 + 1;
    do {
      iVar4 = *piVar5;
      if (iVar4 < 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        goto locret_F0021904;
      }
      if (iVar4 != 0) {
        iVar2 = *param_1;
        _useracc(iVar2,iVar4,1);
        if (iVar2 == 0) {
          *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
          goto locret_F0021904;
        }
        *(int *)((int)register0x00000038 + -0xc) =
             *(int *)((int)register0x00000038 + -0xc) + *piVar5;
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 2;
      param_1 = param_1 + 2;
    } while (iVar6 < param_2[3]);
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x24);
  if (*param_2 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    iVar6 = param_2[4];
  }
  else {
    _sockargs(puVar3,*param_2,param_2[1],8);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0021904;
    iVar6 = param_2[4];
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x28);
  if (iVar6 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
    iVar6 = piVar1[6];
loc_F00218A4:
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    _sosend(iVar6,*(undefined4 *)((int)register0x00000038 + -0x24),
            (undefined *)((int)register0x00000038 + -0x20),param_3,
            *(undefined4 *)((int)register0x00000038 + -0x28));
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar6;
    iVar6 = *(int *)((int)register0x00000038 + -0x28);
    *(int *)(dword_F0133DDC + 0x30) = iVar4 - *(int *)((int)register0x00000038 + -0xc);
    if (iVar6 != 0) {
      _m_freem();
    }
    iVar6 = *(int *)((int)register0x00000038 + -0x24);
  }
  else {
    _sockargs(puVar3,iVar6,param_2[5],0xc);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
    iVar6 = *(int *)((int)register0x00000038 + -0x24);
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      iVar6 = piVar1[6];
      goto loc_F00218A4;
    }
  }
  if (iVar6 != 0) {
    _m_freem();
  }
locret_F0021904:
  return CONCAT44(param_2,param_1);
}

