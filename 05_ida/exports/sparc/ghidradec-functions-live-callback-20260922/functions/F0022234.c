
/* WARNING: Removing unreachable block (ram,0xf0022348) */
/* WARNING: Removing unreachable block (ram,0xf00222a8) */
/* WARNING: Removing unreachable block (ram,0xf002227c) */
/* WARNING: Removing unreachable block (ram,0xf0022320) */
/* WARNING: Removing unreachable block (ram,0xf0022358) */
/* WARNING: Removing unreachable block (ram,0xf0022244) */

undefined8 _getpeername(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined *puVar5;
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
  if (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 0x18);
    iVar1 = 1;
    if ((*(word *)(iVar4 + 6) & 2) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x39;
    }
    else {
      _m_getclr(1,8);
      puVar5 = (undefined *)((int)register0x00000038 + -0xc);
      if (iVar1 == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x37;
      }
      else {
        iVar2 = piVar3[2];
        _copyin(iVar2,puVar5,4);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          (**(code **)(*(int *)(iVar4 + 0xc) + 0x1c))(iVar4,0x10,0,iVar1,0);
          *(char *)(dword_F0133DDC + 0x38) = (char)iVar4;
          if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
            if ((int)*(sword *)(iVar1 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
              *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar1 + 8);
            }
            iVar4 = iVar1 + *(int *)(iVar1 + 4);
            _copyout(iVar4,piVar3[1],*(undefined4 *)((int)register0x00000038 + -0xc));
            *(char *)(dword_F0133DDC + 0x38) = (char)iVar4;
            if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
              _copyout(puVar5,piVar3[2],4);
              *(char *)(dword_F0133DDC + 0x38) = (char)puVar5;
            }
          }
          _m_freem(iVar1);
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

