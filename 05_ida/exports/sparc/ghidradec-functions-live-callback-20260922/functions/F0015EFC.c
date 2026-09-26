
undefined8 _selscan(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  undefined4 uVar11;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar12;
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
  iVar9 = 0;
  iVar12 = 0;
  uVar5 = 0x9f0133dd8;
  iVar10 = 0;
  do {
    uVar8 = 0;
    uVar11 = *(undefined4 *)(unk_F010B558 + iVar10);
    if (0 < param_3) {
      uVar2 = 0;
      do {
        uVar2 = *(uint *)(param_1 + uVar2 * 4);
        if (uVar2 != 0) {
          uVar7 = 0;
          do {
            uVar1 = uVar2 & 1;
            uVar6 = uVar8 + uVar7;
            uVar2 = (int)uVar2 >> 1;
            if (uVar1 != 0) {
              if ((param_3 <= (int)uVar6) || (*(int *)(_active_u + 0x158) <= (int)uVar6)) break;
              iVar3 = *(int *)(*(int *)(_active_u + 0x14c) + uVar6 * 4);
              if (iVar3 == 0) {
                *(char *)(*(int *)((int)uVar5 + 4) + 0x38) = (char)((qword)uVar5 >> 0x20);
                break;
              }
              pcVar4 = *(code **)(*(int *)(iVar3 + 0x14) + 8);
              *(undefined8 *)((int)register0x00000038 + -0x10) = uVar5;
              (*pcVar4)(iVar3,uVar11);
              uVar5 = *(undefined8 *)((int)register0x00000038 + -0x10);
              if (iVar3 != 0) {
                iVar9 = iVar9 + 1;
                iVar3 = (uVar6 >> 5) * 4;
                *(uint *)(param_2 + iVar3) = *(uint *)(param_2 + iVar3) | 1 << ((byte)uVar6 & 0x1f);
              }
              if (uVar2 == 0) break;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x20);
        }
        uVar8 = uVar8 + 0x20;
        uVar2 = uVar8 >> 5;
      } while ((int)uVar8 < param_3);
    }
    param_2 = param_2 + 0x20;
    param_1 = param_1 + 0x20;
    iVar12 = iVar12 + 1;
    iVar10 = iVar10 + 4;
    if (2 < iVar12) {
      return CONCAT44(param_2,iVar9);
    }
  } while( true );
}

