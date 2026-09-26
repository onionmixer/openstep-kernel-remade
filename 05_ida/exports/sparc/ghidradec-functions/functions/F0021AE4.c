
/* WARNING: Removing unreachable block (ram,0xf0021cc4) */
/* WARNING: Removing unreachable block (ram,0xf0021c9c) */
/* WARNING: Removing unreachable block (ram,0xf0021c10) */
/* WARNING: Removing unreachable block (ram,0xf0021b48) */
/* WARNING: Removing unreachable block (ram,0xf0021b98) */
/* WARNING: Removing unreachable block (ram,0xf0021c20) */
/* WARNING: Removing unreachable block (ram,0xf0021cac) */
/* WARNING: Removing unreachable block (ram,0xf0021cdc) */
/* WARNING: Removing unreachable block (ram,0xf0021ae8) */

undefined8
_recvit(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = 0;
  if (piVar1 != (int *)0x0) {
    *(int *)((int)register0x00000038 + -0x20) = param_2[2];
    *(int *)((int)register0x00000038 + -0x1c) = param_2[3];
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    piVar4 = (int *)param_2[2];
    if (0 < param_2[3]) {
      param_1 = piVar4 + 1;
      do {
        iVar3 = *param_1;
        if (iVar3 < 0) {
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
          goto locret_F0021CE4;
        }
        if (iVar3 != 0) {
          iVar2 = *piVar4;
          _useracc(iVar2,iVar3,0);
          if (iVar2 == 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
            goto locret_F0021CE4;
          }
          *(int *)((int)register0x00000038 + -0xc) =
               *(int *)((int)register0x00000038 + -0xc) + *param_1;
        }
        iVar5 = iVar5 + 1;
        param_1 = param_1 + 2;
        piVar4 = piVar4 + 2;
      } while (iVar5 < param_2[3]);
    }
    iVar5 = piVar1[6];
    *(undefined4 *)((int)register0x00000038 + -0x2c) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    _soreceive(iVar5,(undefined *)((int)register0x00000038 + -0x24),
               (undefined *)((int)register0x00000038 + -0x20),param_3,
               (undefined *)((int)register0x00000038 + -0x28));
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar5;
    *(int *)(dword_F0133DDC + 0x30) =
         *(int *)((int)register0x00000038 + -0x2c) - *(int *)((int)register0x00000038 + -0xc);
    if (*param_2 == 0) {
      iVar5 = param_2[4];
    }
    else {
      iVar5 = param_2[1];
      *(int *)((int)register0x00000038 + -0x2c) = iVar5;
      if ((iVar5 < 1) || (iVar3 = *(int *)((int)register0x00000038 + -0x24), iVar3 == 0)) {
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      }
      else {
        if (*(sword *)(iVar3 + 8) < iVar5) {
          *(int *)((int)register0x00000038 + -0x2c) = (int)*(sword *)(iVar3 + 8);
        }
        _copyout(iVar3 + *(int *)(iVar3 + 4),*param_2,
                 *(undefined4 *)((int)register0x00000038 + -0x2c));
      }
      _copyout((undefined *)((int)register0x00000038 + -0x2c),param_4,4);
      iVar5 = param_2[4];
    }
    iVar3 = *(int *)((int)register0x00000038 + -0x28);
    if (iVar5 != 0) {
      iVar5 = param_2[5];
      *(int *)((int)register0x00000038 + -0x2c) = iVar5;
      if ((iVar5 < 1) || (iVar3 = *(int *)((int)register0x00000038 + -0x28), iVar3 == 0)) {
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      }
      else {
        if (*(sword *)(iVar3 + 8) < iVar5) {
          *(int *)((int)register0x00000038 + -0x2c) = (int)*(sword *)(iVar3 + 8);
        }
        _copyout(iVar3 + *(int *)(iVar3 + 4),param_2[4],
                 *(undefined4 *)((int)register0x00000038 + -0x2c));
      }
      _copyout((undefined *)((int)register0x00000038 + -0x2c),param_5,4);
      iVar3 = *(int *)((int)register0x00000038 + -0x28);
    }
    if (iVar3 == 0) {
      iVar5 = *(int *)((int)register0x00000038 + -0x24);
    }
    else {
      _m_freem();
      iVar5 = *(int *)((int)register0x00000038 + -0x24);
    }
    if (iVar5 != 0) {
      _m_freem();
    }
  }
locret_F0021CE4:
  return CONCAT44(param_2,param_1);
}
