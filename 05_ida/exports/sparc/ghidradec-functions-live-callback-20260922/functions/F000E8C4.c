
/* WARNING: Removing unreachable block (ram,0xf000e98c) */
/* WARNING: Removing unreachable block (ram,0xf000e948) */
/* WARNING: Removing unreachable block (ram,0xf000e97c) */
/* WARNING: Removing unreachable block (ram,0xf000e998) */
/* WARNING: Removing unreachable block (ram,0xf000e8f0) */

undefined8 _pgdelete(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
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
  piVar3 = *(int **)(param_1[2] + 8);
  piVar2 = &_pgrphash + (param_1[3] & 0x3f);
  if (piVar3 == (int *)0x0) goto loc_F000E934;
  _ttynty();
  if ((int *)piVar3[3] == param_1) {
    piVar3[3] = 0;
    *(undefined2 *)(*piVar3 + 0x44) = 0;
    goto loc_F000E934;
  }
  iVar1 = *piVar2;
  piVar3 = piVar2;
  do {
    if (iVar1 == 0) {
      _panic(aPgdeleteCanTFi);
loc_F000E950:
      iVar1 = *(int *)param_1[2] + -1;
      *(int *)param_1[2] = iVar1;
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1[2] + 8);
        if (iVar1 == 0) {
          iVar1 = param_1[2];
        }
        else {
          _ttynty();
          *(undefined4 *)(iVar1 + 8) = 0;
          iVar1 = param_1[2];
        }
        _kfree(iVar1,0x10);
      }
      _kfree(param_1,0x14);
      return CONCAT44(param_2,param_1);
    }
    piVar2 = (int *)*piVar3;
    if (piVar2 == param_1) {
      *piVar3 = *param_1;
      goto loc_F000E950;
    }
loc_F000E934:
    iVar1 = *piVar2;
    piVar3 = piVar2;
  } while( true );
}

