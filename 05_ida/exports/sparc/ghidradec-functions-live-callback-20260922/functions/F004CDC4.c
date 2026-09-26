
/* WARNING: Removing unreachable block (ram,0xf004cdf8) */

undefined8 sub_F004CDC4(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  uVar5 = 0;
  if (*(int *)(param_1 + 0x70) != 0) {
    do {
      iVar2 = 0;
      _rdwri(0,param_1,(int *)((int)register0x00000038 + -0x20),0xc,uVar5,1,
             (undefined *)((int)register0x00000038 + -0x24));
      if (iVar2 != 0) {
        uVar6 = 0;
        goto locret_F004CEA4;
      }
      if (*(int *)((int)register0x00000038 + -0x24) != 0) {
        uVar6 = 0;
        goto locret_F004CEA4;
      }
      uVar3 = (uint)*(word *)((int)register0x00000038 + -0x1c);
      if (uVar3 == 0) {
        uVar6 = 0;
        goto locret_F004CEA4;
      }
      iVar2 = *(int *)((int)register0x00000038 + -0x20);
      if (iVar2 == 0) {
        uVar4 = *(uint *)(param_1 + 0x70);
      }
      else {
        if (2 < *(word *)((int)register0x00000038 + -0x1a)) {
          uVar6 = 0;
          goto locret_F004CEA4;
        }
        if (*(char *)((int)register0x00000038 + -0x18) != '.') {
          uVar6 = 0;
          goto locret_F004CEA4;
        }
        if (*(word *)((int)register0x00000038 + -0x1a) == 1) {
          wVar1 = *(word *)((int)register0x00000038 + -0x1c);
        }
        else {
          if (*(char *)((int)register0x00000038 + -0x17) != '.') {
            uVar6 = 0;
            goto locret_F004CEA4;
          }
          if (iVar2 != param_2) {
            uVar6 = 0;
            goto locret_F004CEA4;
          }
          wVar1 = *(word *)((int)register0x00000038 + -0x1c);
        }
        uVar3 = (uint)wVar1;
        uVar4 = *(uint *)(param_1 + 0x70);
      }
      uVar5 = uVar5 + uVar3;
    } while (uVar5 < uVar4);
  }
  uVar6 = 1;
locret_F004CEA4:
  return CONCAT44(param_2,uVar6);
}

