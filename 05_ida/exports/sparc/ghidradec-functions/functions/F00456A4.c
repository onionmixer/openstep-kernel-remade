
/* WARNING: Removing unreachable block (ram,0xf0045738) */

undefined8 _xdr_bool(uint *param_1,uint *param_2)

{
  undefined *puVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  uVar2 = *param_1;
  if (uVar2 == 1) {
    (**(code **)param_1[1])(param_1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 != (uint *)0x0) {
      param_1 = (uint *)0x1;
      *param_2 = (uint)(*(int *)((int)register0x00000038 + -0xc) != 0);
      goto locret_F0045740;
    }
    puVar1 = aXdrBoolDecodeF;
  }
  else {
    if (uVar2 < 2) {
      pcVar3 = *(code **)(param_1[1] + 4);
      *(uint *)((int)register0x00000038 + -0xc) = (uint)(*param_2 != 0);
      (*pcVar3)(param_1,(undefined *)((int)register0x00000038 + -0xc));
      goto locret_F0045740;
    }
    param_1 = (uint *)0x1;
    if (uVar2 == 2) goto locret_F0045740;
    puVar1 = aXdrBoolBadOpFa;
  }
  param_1 = (uint *)0x0;
  _printf(puVar1);
locret_F0045740:
  return CONCAT44(param_2,param_1);
}
