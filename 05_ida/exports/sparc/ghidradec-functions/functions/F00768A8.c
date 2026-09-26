
undefined8 sub_F00768A8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 *puVar3;
  undefined4 *puVar4;
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
  uVar2 = 0;
  if ((undefined4 **)dword_F0130F34 != &dword_F0130F34) {
    iVar1 = dword_F0130F34[2];
    puVar3 = dword_F0130F34;
    do {
      if (iVar1 == param_1) {
        if (puVar3[3] == param_2) {
          puVar4 = (undefined4 *)*puVar3;
          puVar4[1] = puVar3[1];
          *(undefined4 *)puVar3[1] = *puVar3;
          puVar3[8] = 0;
          if ((unk_F0130520 <= puVar3) && (puVar3 < &dword_F0130F20)) {
            *puVar3 = &dword_F0130F24;
            puVar3[1] = DAT_f0130f28;
            *DAT_f0130f28 = puVar3;
            DAT_f0130f28 = puVar3;
          }
          uVar2 = 1;
          if (param_3 == 0) break;
        }
        else {
          puVar4 = (undefined4 *)*puVar3;
        }
      }
      else {
        puVar4 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar4 == &dword_F0130F34) break;
      iVar1 = puVar4[2];
      puVar3 = puVar4;
    } while( true );
  }
  return CONCAT44(param_2,uVar2);
}
