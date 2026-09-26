
/* WARNING: Removing unreachable block (ram,0xf00bd960) */
/* WARNING: Removing unreachable block (ram,0xf00bd8f4) */

undefined8 sub_F00BD8B0(sword *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined *puVar2;
  undefined (*pauVar3) [3744];
  int iVar4;
  byte bVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
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
  iVar8 = 0;
  if (0 < param_1[1]) {
    sVar1 = *param_1;
    while( true ) {
      for (iVar7 = 0; iVar7 < sVar1; iVar7 = iVar7 + 1) {
        iVar4 = (param_1[1] - iVar8) + -1;
        umul(iVar4,(int)*param_1);
        iVar4 = *(int *)(param_1 + 6) + iVar4 + iVar7;
        if (((int)(uint)*(byte *)(*(int *)(*off_F012054C + 0x610) + (iVar4 >> 3)) >>
             (~(byte)iVar4 & 7) & 1U) == 0) {
          sVar1 = *param_1;
        }
        else {
          iVar6 = dword_F0132F30 + param_1[2];
          iVar4 = (dword_F0132F34 - param_1[3]) - iVar8;
          umul(iVar4,dword_F0132F20);
          pauVar3 = off_F0120548;
          iVar6 = (iVar4 + iVar6 + iVar7) * 2;
          iVar4 = iVar6 >> 3;
          puVar2 = *off_F0120548;
          if (puVar2 + iVar4 != dword_F0132F38) {
            if (dword_F0132F38 != (byte *)0x0) {
              *dword_F0132F38 = unk_F0132F3C[0];
            }
            unk_F0132F3C[0] = (*pauVar3)[iVar4];
            dword_F0132F38 = puVar2 + iVar4;
          }
          bVar5 = ~(byte)iVar6 & 6;
          unk_F0132F3C[0] = unk_F0132F3C[0] & ~(byte)(3 << bVar5) | (byte)(3 << bVar5);
          sVar1 = *param_1;
        }
      }
      iVar8 = iVar8 + 1;
      if (param_1[1] <= iVar8) break;
      sVar1 = *param_1;
    }
  }
  if (dword_F0132F38 != (byte *)0x0) {
    *dword_F0132F38 = unk_F0132F3C[0];
  }
  dword_F0132F38 = (byte *)0x0;
  dword_F0132F30 = dword_F0132F30 + param_1[4];
  return CONCAT44(param_2,param_1);
}

