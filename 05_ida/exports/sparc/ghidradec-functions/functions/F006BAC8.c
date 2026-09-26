
undefined8 _find_listener(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  word wVar1;
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
  undefined4 unaff_i4;
  int iVar3;
  undefined4 unaff_i5;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
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
  iVar3 = (param_5 & 0xf) * 8;
  puVar4 = *(undefined4 **)(DAT_f013c124 + iVar3);
  if (puVar4 != (undefined4 *)0x0) {
    wVar1 = *(word *)((int)puVar4 + 0xe);
    puVar5 = puVar4;
    while( true ) {
      if (((((wVar1 == 0) || ((uint)wVar1 == (param_4 & 0xffff))) &&
           ((*(word *)(puVar5 + 3) == 0 || ((uint)*(word *)(puVar5 + 3) == (param_2 & 0xffff))))) &&
          ((puVar5[1] == 0 || (puVar5[1] == param_1)))) &&
         ((puVar5[2] == 0 || (puVar5[2] == param_3)))) {
        if (puVar5 == *(undefined4 **)(DAT_f013c124 + iVar3)) {
          uVar2 = puVar5[4];
        }
        else {
          *puVar4 = *puVar5;
          *puVar5 = *(undefined4 *)(DAT_f013c124 + iVar3);
          *(undefined4 **)(DAT_f013c124 + iVar3) = puVar5;
          uVar2 = puVar5[4];
        }
        goto locret_F006BBA0;
      }
      puVar6 = (undefined4 *)*puVar5;
      if (puVar6 == (undefined4 *)0x0) break;
      wVar1 = *(word *)((int)puVar6 + 0xe);
      puVar4 = puVar5;
      puVar5 = puVar6;
    }
  }
  uVar2 = 0;
locret_F006BBA0:
  return CONCAT44(param_2,uVar2);
}
