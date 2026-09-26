
undefined8 _m_adj(int *param_1,int param_2)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar3;
  undefined4 unaff_i2;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_i3;
  int iVar6;
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
  iVar3 = param_2;
  if (param_1 != (int *)0x0) {
    piVar4 = param_1;
    if (param_2 < 0) {
      iVar3 = -param_2;
      iVar6 = (int)*(sword *)(param_1 + 2);
      iVar2 = *param_1;
      while (iVar2 != 0) {
        piVar4 = (int *)*piVar4;
        iVar6 = iVar6 + *(sword *)(piVar4 + 2);
        iVar2 = *piVar4;
      }
      if (*(sword *)(piVar4 + 2) < iVar3) {
        iVar6 = iVar6 + param_2;
        piVar5 = param_1;
        piVar4 = param_1;
        if (param_1 != (int *)0x0) {
          while (piVar4 = piVar5 + 2, *(sword *)piVar4 < iVar6) {
            piVar5 = (int *)*piVar5;
            iVar6 = iVar6 - *(sword *)piVar4;
            piVar4 = piRam00000000;
            if (piVar5 == (int *)0x0) goto loc_F001E0C0;
          }
          *(sword *)(piVar5 + 2) = (sword)iVar6;
          piVar4 = piVar5;
        }
        while( true ) {
          piVar4 = (int *)*piVar4;
loc_F001E0C0:
          if (piVar4 == (int *)0x0) break;
          *(undefined2 *)(piVar4 + 2) = 0;
        }
      }
      else {
        *(sword *)(piVar4 + 2) = *(sword *)(piVar4 + 2) - (sword)iVar3;
      }
    }
    else {
      do {
        if (iVar3 < 1) break;
        sVar1 = *(sword *)(piVar4 + 2);
        if (iVar3 < sVar1) {
          *(sword *)(piVar4 + 2) = sVar1 - (sword)iVar3;
          piVar4[1] = piVar4[1] + iVar3;
          break;
        }
        *(undefined2 *)(piVar4 + 2) = 0;
        piVar4 = (int *)*piVar4;
        iVar3 = iVar3 - sVar1;
      } while (piVar4 != (int *)0x0);
    }
  }
  return CONCAT44(iVar3,param_1);
}
