
/* WARNING: Removing unreachable block (ram,0xf00f283c) */
/* WARNING: Removing unreachable block (ram,0xf00f28dc) */
/* WARNING: Removing unreachable block (ram,0xf00f27fc) */
/* WARNING: Removing unreachable block (ram,0xf00f28f0) */
/* WARNING: Removing unreachable block (ram,0xf00f2898) */
/* WARNING: Removing unreachable block (ram,0xf00f27e4) */

undefined8 sub_F00F27CC(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
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
  uVar1 = param_1;
  _getsectdatafromheaderinfo(param_1,&aObjc,aProtocol,(undefined *)((int)register0x00000038 + -0xc))
  ;
  uVar5 = 0;
  if (uVar1 != 0) {
    while( true ) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      udiv(uVar2,0x14);
      if (uVar2 <= uVar5) break;
      puVar3 = *(uint **)(uVar1 + uVar5 * 0x14 + 0xc);
      if (puVar3 != (uint *)0x0) {
        for (param_1 = 0; param_1 < *puVar3; param_1 = param_1 + 1) {
          uVar2 = puVar3[param_1 * 2 + 1];
          __sel_registerName();
          if (puVar3[param_1 * 2 + 1] != uVar2) {
            puVar3[param_1 * 2 + 1] = uVar2;
          }
        }
      }
      puVar3 = *(uint **)(uVar1 + uVar5 * 0x14 + 0x10);
      if (puVar3 != (uint *)0x0) {
        for (param_1 = 0; param_1 < *puVar3; param_1 = param_1 + 1) {
          uVar2 = puVar3[param_1 * 2 + 1];
          __sel_registerName();
          if (puVar3[param_1 * 2 + 1] != uVar2) {
            puVar3[param_1 * 2 + 1] = uVar2;
          }
        }
      }
      uVar5 = uVar5 + 1;
    }
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
    udiv(uVar4,0x14);
    _objc_msgSend(paProtocol_0,paFixupNumelemen,uVar1,uVar4);
  }
  return CONCAT44(param_2,param_1);
}

