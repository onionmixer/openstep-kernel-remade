
/* WARNING: Removing unreachable block (ram,0xf0009a38) */
/* WARNING: Removing unreachable block (ram,0xf0009a04) */
/* WARNING: Removing unreachable block (ram,0xf0009998) */
/* WARNING: Removing unreachable block (ram,0xf00099e4) */
/* WARNING: Removing unreachable block (ram,0xf0009a28) */
/* WARNING: Removing unreachable block (ram,0xf0009984) */
/* WARNING: Removing unreachable block (ram,0xf0009934) */

undefined8 _sysacct(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  bool bVar4;
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
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    if (_savacctp != 0) {
      _acctp = _savacctp;
      _savacctp = 0;
    }
    iVar1 = *piVar3;
    if (iVar1 == 0) {
      *(int *)((int)register0x00000038 + -0xc) = _acctp;
      if (_acctp != 0) {
        _acctp = 0;
        _vn_rele();
      }
    }
    else {
      _lookupname(iVar1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
      *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        uVar2 = 0xd;
        if ((*(int *)(iVar1 + 0x28) == 1) &&
           (uVar2 = 0x1e, (*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0)) {
          bVar4 = _acctp != 0;
          _acctp = iVar1;
          if (bVar4) {
            _vn_rele();
          }
          if (_acctcred != 0) {
            _crfree();
          }
          iVar1 = *(int *)(_active_u + 0x1c);
          _crdup();
          _acctcred = iVar1;
        }
        else {
          *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
          _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
