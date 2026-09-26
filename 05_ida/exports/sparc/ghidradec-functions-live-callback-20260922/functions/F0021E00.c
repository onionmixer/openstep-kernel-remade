
/* WARNING: Removing unreachable block (ram,0xf0021f10) */
/* WARNING: Removing unreachable block (ram,0xf0021e78) */
/* WARNING: Removing unreachable block (ram,0xf0021e3c) */
/* WARNING: Removing unreachable block (ram,0xf0021ee4) */
/* WARNING: Removing unreachable block (ram,0xf0021f30) */
/* WARNING: Removing unreachable block (ram,0xf0021e14) */

undefined8 _getsockopt(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar5;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  _getsock();
  if (iVar1 == 0) goto locret_F0021F38;
  if (piVar5[3] == 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    uVar3 = *(undefined4 *)(iVar1 + 0x18);
  }
  else {
    iVar2 = piVar5[4];
    _copyin(iVar2,(undefined *)((int)register0x00000038 + -0xc),4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0021F38;
    uVar3 = *(undefined4 *)(iVar1 + 0x18);
  }
  _sogetopt(uVar3,piVar5[1],piVar5[2],(undefined *)((int)register0x00000038 + -0x10));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
  iVar1 = *(int *)((int)register0x00000038 + -0x10);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if ((piVar5[3] == 0) ||
       (iVar2 = *(int *)((int)register0x00000038 + -0x10),
       *(int *)((int)register0x00000038 + -0xc) == 0)) {
loc_F0021F20:
      iVar1 = *(int *)((int)register0x00000038 + -0x10);
    }
    else {
      iVar1 = *(int *)((int)register0x00000038 + -0x10);
      if (iVar2 != 0) {
        if ((int)*(sword *)(iVar2 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
          *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar2 + 8);
        }
        iVar2 = iVar2 + *(int *)(iVar2 + 4);
        _copyout(iVar2,piVar5[3],*(undefined4 *)((int)register0x00000038 + -0xc));
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        iVar1 = *(int *)((int)register0x00000038 + -0x10);
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          puVar4 = (undefined *)((int)register0x00000038 + -0xc);
          _copyout(puVar4,piVar5[4],4);
          *(char *)(dword_F0133DDC + 0x38) = (char)puVar4;
          goto loc_F0021F20;
        }
      }
    }
  }
  if (iVar1 != 0) {
    _m_free();
  }
locret_F0021F38:
  return CONCAT44(param_2,param_1);
}

