
/* WARNING: Removing unreachable block (ram,0xf0098acc) */
/* WARNING: Removing unreachable block (ram,0xf0098ab4) */

undefined8 _fpu_ctxalloc(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = (undefined4 *)0x110;
  _kalloc();
  if (puVar1 == (undefined4 *)0x0) {
    _panic(aCanTAllocateFp);
    uRam00000080 = 0;
  }
  else {
    puVar1[0x20] = 0;
  }
  *puVar1 = 0xffffffff;
  puVar1[1] = 0xffffffff;
  puVar1[2] = 0xffffffff;
  puVar1[3] = 0xffffffff;
  puVar1[4] = 0xffffffff;
  puVar1[5] = 0xffffffff;
  puVar1[6] = 0xffffffff;
  puVar1[7] = 0xffffffff;
  puVar1[8] = 0xffffffff;
  puVar1[9] = 0xffffffff;
  puVar1[10] = 0xffffffff;
  puVar1[0xb] = 0xffffffff;
  puVar1[0xc] = 0xffffffff;
  puVar1[0xd] = 0xffffffff;
  puVar1[0xe] = 0xffffffff;
  puVar1[0xf] = 0xffffffff;
  puVar1[0x10] = 0xffffffff;
  puVar1[0x11] = 0xffffffff;
  puVar1[0x12] = 0xffffffff;
  puVar1[0x13] = 0xffffffff;
  puVar1[0x14] = 0xffffffff;
  puVar1[0x15] = 0xffffffff;
  puVar1[0x16] = 0xffffffff;
  puVar1[0x17] = 0xffffffff;
  puVar1[0x18] = 0xffffffff;
  puVar1[0x19] = 0xffffffff;
  puVar1[0x1a] = 0xffffffff;
  puVar1[0x1b] = 0xffffffff;
  puVar1[0x1c] = 0xffffffff;
  puVar1[0x1d] = 0xffffffff;
  puVar1[0x1e] = 0xffffffff;
  puVar1[0x1f] = 0xffffffff;
  return CONCAT44(param_2,puVar1);
}
