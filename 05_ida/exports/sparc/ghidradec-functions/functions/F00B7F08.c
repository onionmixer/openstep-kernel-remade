
/* WARNING: Removing unreachable block (ram,0xf00b7f4c) */
/* WARNING: Removing unreachable block (ram,0xf00b7f30) */
/* WARNING: Removing unreachable block (ram,0xf00b7f68) */
/* WARNING: Removing unreachable block (ram,0xf00b7f10) */

undefined8 _esp_dump_datasegs(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  _printf(aMappedDmaSpace);
  puVar2 = (undefined4 *)(param_1 + 0x3c);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *puVar2;
    while( true ) {
      _printf(aBase0xXCount0x,uVar1,puVar2[1]);
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) break;
      uVar1 = *puVar2;
    }
  }
  _printf(aTransferHistor);
  puVar2 = (undefined4 *)(param_1 + 0x48);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *puVar2;
    while( true ) {
      _printf(aBase0xXCount0x_0,uVar1,puVar2[1]);
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) break;
      uVar1 = *puVar2;
    }
  }
  return CONCAT44(param_2,param_1);
}
