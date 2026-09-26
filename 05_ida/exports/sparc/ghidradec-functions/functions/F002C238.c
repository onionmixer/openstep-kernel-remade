
/* WARNING: Removing unreachable block (ram,0xf002c288) */

undefined8 _mbuf_read(int *param_1,int param_2,uint param_3,uint param_4)

{
  sword sVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar3 = 0;
  do {
    if (param_1 == (int *)0x0) {
      uVar4 = 0xffffffff;
locret_F002C2C0:
      return CONCAT44(param_2,uVar4);
    }
    if (param_3 < uVar3) {
      sVar1 = *(sword *)(param_1 + 2);
    }
    else {
      if (param_3 < uVar3 + (int)*(sword *)(param_1 + 2)) {
        uVar2 = (int)*(sword *)(param_1 + 2) - (param_3 - uVar3);
        if (param_4 < uVar2) {
          uVar2 = param_4;
        }
        _bcopy((int)param_1 + (param_3 - uVar3) + param_1[1],param_2,uVar2);
        param_2 = param_2 + uVar2;
        param_4 = param_4 - uVar2;
        param_3 = param_3 + uVar2;
        if (param_4 == 0) {
          uVar4 = 0;
          goto locret_F002C2C0;
        }
      }
      sVar1 = *(sword *)(param_1 + 2);
    }
    param_1 = (int *)*param_1;
    uVar3 = uVar3 + (int)sVar1;
  } while( true );
}
