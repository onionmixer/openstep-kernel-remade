
/* WARNING: Removing unreachable block (ram,0xf00208fc) */
/* WARNING: Removing unreachable block (ram,0xf002097c) */
/* WARNING: Removing unreachable block (ram,0xf0020894) */

undefined8 _sbappendrights(word *param_1,int *param_2,int param_3)

{
  int *piVar1;
  sword sVar2;
  word wVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  iVar6 = 0;
  if (param_3 == 0) {
    _panic(aSbappendrights);
  }
  piVar5 = param_2;
  if (param_2 == (int *)0x0) {
    sVar2 = *(sword *)(param_3 + 8);
  }
  else {
    do {
      piVar1 = piVar5 + 2;
      piVar5 = (int *)*piVar5;
      iVar6 = iVar6 + *(sword *)piVar1;
    } while (piVar5 != (int *)0x0);
    sVar2 = *(sword *)(param_3 + 8);
  }
  iVar4 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar4 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (iVar4 < iVar6 + sVar2) {
    uVar7 = 0;
  }
  else {
    _m_copy(param_3,0,(int)sVar2);
    if (param_3 == 0) {
      uVar7 = 0;
    }
    else {
      wVar3 = param_1[2];
      *param_1 = *param_1 + *(sword *)(param_3 + 8);
      param_1[2] = wVar3 + 0x80;
      if (0x7c < *(uint *)(param_3 + 4)) {
        param_1[2] = wVar3 + 0x480;
      }
      iVar6 = *(int *)(param_1 + 6);
      if (iVar6 == 0) {
        *(int *)(param_1 + 6) = param_3;
      }
      else {
        iVar4 = *(int *)(iVar6 + 0x7c);
        while (iVar4 != 0) {
          iVar6 = *(int *)(iVar6 + 0x7c);
          iVar4 = *(int *)(iVar6 + 0x7c);
        }
        *(int *)(iVar6 + 0x7c) = param_3;
      }
      if (param_2 != (int *)0x0) {
        _sbcompress(param_1,param_2);
      }
      uVar7 = 1;
    }
  }
  return CONCAT44(param_2,uVar7);
}

