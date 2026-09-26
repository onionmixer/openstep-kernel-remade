
/* WARNING: Removing unreachable block (ram,0xf004462c) */
/* WARNING: Removing unreachable block (ram,0xf00445b8) */
/* WARNING: Removing unreachable block (ram,0xf0044594) */

undefined8 _ku_recvfrom(int param_1,undefined4 *param_2)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar8;
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
  piVar4 = *(int **)(param_1 + 0x30);
  iVar6 = 0;
  psVar8 = (sword *)(param_1 + 0x24);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    iVar3 = piVar4[1];
    iVar7 = piVar4[0x1f];
    *param_2 = *(undefined4 *)((int)piVar4 + iVar3);
    param_2[1] = *(undefined4 *)((int)piVar4 + iVar3 + 4);
    param_2[2] = *(undefined4 *)((int)piVar4 + iVar3 + 8);
    param_2[3] = *(undefined4 *)((int)piVar4 + iVar3 + 0xc);
    sVar2 = *(sword *)((int)piVar4 + 10);
    while (sVar2 != 1) {
      sVar2 = *(sword *)(param_1 + 0x28);
      *psVar8 = *psVar8 - *(sword *)(piVar4 + 2);
      *(sword *)(param_1 + 0x28) = sVar2 + -0x80;
      if (0x7c < (uint)piVar4[1]) {
        *(sword *)(param_1 + 0x28) = sVar2 + -0x480;
      }
      _m_free();
      if (piVar4 == (int *)0x0) break;
      sVar2 = *(sword *)((int)piVar4 + 10);
    }
    piVar5 = piVar4;
    if (piVar4 == (int *)0x0) {
      _printf(aKuRecvfromNoBo);
      *(int *)(param_1 + 0x30) = iVar7;
      piVar4 = (int *)0x0;
    }
    else {
      do {
        sVar2 = *(sword *)(param_1 + 0x28);
        *psVar8 = *psVar8 - *(sword *)(piVar5 + 2);
        *(sword *)(param_1 + 0x28) = sVar2 + -0x80;
        if (0x7c < (uint)piVar5[1]) {
          *(sword *)(param_1 + 0x28) = sVar2 + -0x480;
        }
        piVar1 = piVar5 + 2;
        piVar5 = (int *)*piVar5;
        iVar6 = iVar6 + *(sword *)piVar1;
      } while (piVar5 != (int *)0x0);
      *(int *)(param_1 + 0x30) = iVar7;
      if (0x2260 < iVar6) {
        _printf(aKuRecvfromLenD,iVar6);
      }
    }
  }
  return CONCAT44(param_2,piVar4);
}

