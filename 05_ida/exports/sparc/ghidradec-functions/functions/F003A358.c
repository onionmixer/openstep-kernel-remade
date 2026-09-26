
/* WARNING: Removing unreachable block (ram,0xf003a3ac) */
/* WARNING: Removing unreachable block (ram,0xf003a37c) */

undefined8 _findexport(undefined4 param_1,sword *param_2)

{
  int iVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = _exported;
  if (_exported == 0) {
    iVar3 = 0;
  }
  else {
    do {
      iVar1 = iVar3 + 0x20;
      _bcmp(iVar1,param_1,8);
      if (iVar1 == 0) {
        if (**(sword **)(iVar3 + 0x28) == *param_2) {
          psVar2 = *(sword **)(iVar3 + 0x28) + 1;
          _bcmp(psVar2,param_2 + 1);
          if (psVar2 == (sword *)0x0) goto locret_F003A3D4;
          iVar3 = *(int *)(iVar3 + 0x2c);
        }
        else {
          iVar3 = *(int *)(iVar3 + 0x2c);
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x2c);
      }
    } while (iVar3 != 0);
    iVar3 = 0;
  }
locret_F003A3D4:
  return CONCAT44(param_2,iVar3);
}
