
/* WARNING: Removing unreachable block (ram,0xf0022214) */
/* WARNING: Removing unreachable block (ram,0xf0022174) */
/* WARNING: Removing unreachable block (ram,0xf002214c) */
/* WARNING: Removing unreachable block (ram,0xf00221ec) */
/* WARNING: Removing unreachable block (ram,0xf0022224) */
/* WARNING: Removing unreachable block (ram,0xf0022130) */

undefined8 _getsockname(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int *piVar3;
  undefined4 unaff_l4;
  undefined *puVar4;
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
  iVar1 = *piVar3;
  _getsock();
  puVar4 = (undefined *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    iVar2 = piVar3[2];
    _copyin(iVar2,puVar4,4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    iVar2 = 1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      iVar1 = *(int *)(iVar1 + 0x18);
      _m_getclr(1,8);
      if (iVar2 == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x37;
      }
      else {
        (**(code **)(*(int *)(iVar1 + 0xc) + 0x1c))(iVar1,0xf,0,iVar2,0);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          if ((int)*(sword *)(iVar2 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
            *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar2 + 8);
          }
          iVar1 = iVar2 + *(int *)(iVar2 + 4);
          _copyout(iVar1,piVar3[1],*(undefined4 *)((int)register0x00000038 + -0xc));
          *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
          if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
            _copyout(puVar4,piVar3[2],4);
            *(char *)(dword_F0133DDC + 0x38) = (char)puVar4;
          }
        }
        _m_freem(iVar2);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
