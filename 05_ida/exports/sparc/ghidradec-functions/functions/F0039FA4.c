
/* WARNING: Removing unreachable block (ram,0xf003a138) */
/* WARNING: Removing unreachable block (ram,0xf003a104) */
/* WARNING: Removing unreachable block (ram,0xf0039fe4) */
/* WARNING: Removing unreachable block (ram,0xf003a068) */
/* WARNING: Removing unreachable block (ram,0xf003a034) */
/* WARNING: Removing unreachable block (ram,0xf003a0b0) */
/* WARNING: Removing unreachable block (ram,0xf003a0e4) */
/* WARNING: Removing unreachable block (ram,0xf003a120) */
/* WARNING: Removing unreachable block (ram,0xf003a150) */
/* WARNING: Removing unreachable block (ram,0xf0039fb4) */

undefined8 _nfs_getfh(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
  uint *puVar7;
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
  puVar7 = *(uint **)(dword_F0133DDC + 0x24);
  bVar1 = false;
  iVar2 = dword_F0133DDC;
  _suser();
  if (iVar2 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
  }
  else {
    uVar3 = *puVar7;
    if (uVar3 < 0x100) {
      bVar1 = true;
      _getf();
      if ((uVar3 == 0) || (*(undefined **)(uVar3 + 0x14) != _vnodefops)) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        goto locret_F003A164;
      }
      uVar4 = *(undefined4 *)(uVar3 + 0x18);
      *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x30) = uVar4;
    }
    else {
      _lookupname(uVar3,0,1,(undefined *)((int)register0x00000038 + -0x2c),
                  (undefined *)((int)register0x00000038 + -0x30));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
      if (*(char *)(dword_F0133DDC + 0x38) == '\x11') {
        uVar3 = *puVar7;
        _lookupname(uVar3,0,1,0,(undefined *)((int)register0x00000038 + -0x30));
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      }
      if ((*(char *)(dword_F0133DDC + 0x38) == '\0') &&
         (*(int *)((int)register0x00000038 + -0x30) == 0)) {
        if (*(int *)((int)register0x00000038 + -0x2c) != 0) {
          _vn_rele();
        }
        *(undefined *)(dword_F0133DDC + 0x38) = 2;
      }
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F003A164;
    }
    puVar5 = (undefined *)((int)register0x00000038 + -0x34);
    _findexivp(puVar5,*(undefined4 *)((int)register0x00000038 + -0x2c),
               *(undefined4 *)((int)register0x00000038 + -0x30));
    if (puVar5 == (undefined *)0x0) {
      puVar6 = (undefined *)((int)register0x00000038 + -0x28);
      puVar5 = puVar6;
      _makefh(puVar6,*(undefined4 *)((int)register0x00000038 + -0x30),
              *(undefined4 *)((int)register0x00000038 + -0x34));
      if (puVar5 == (undefined *)0x0) {
        _copyout(puVar6,puVar7[1],0x20);
        puVar5 = puVar6;
      }
    }
    if ((!bVar1) &&
       (_vn_rele(*(undefined4 *)((int)register0x00000038 + -0x30)),
       *(int *)((int)register0x00000038 + -0x2c) != 0)) {
      _vn_rele();
    }
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar5;
  }
locret_F003A164:
  return CONCAT44(param_2,param_1);
}
