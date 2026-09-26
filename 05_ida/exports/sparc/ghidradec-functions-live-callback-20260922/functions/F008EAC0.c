
/* WARNING: Removing unreachable block (ram,0xf008eb1c) */
/* WARNING: Removing unreachable block (ram,0xf008eb00) */
/* WARNING: Removing unreachable block (ram,0xf008ead8) */
/* WARNING: Removing unreachable block (ram,0xf008eae8) */
/* WARNING: Removing unreachable block (ram,0xf008eb10) */
/* WARNING: Removing unreachable block (ram,0xf008eb4c) */
/* WARNING: Removing unreachable block (ram,0xf008eac8) */

undefined8 sub_F008EAC0(undefined4 param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  undefined4 *puVar2;
  undefined (*pauVar3) [9];
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
  puVar2 = (undefined4 *)0x68;
  _kalloc();
  _memset();
  _memset(puVar2,0,0x2c);
  pauVar3 = paKernlock;
  puVar1 = paAlloc;
  *puVar2 = 0;
  _objc_msgSend(pauVar3,puVar1);
  _objc_msgSend();
  puVar2[0xc] = pauVar3;
  _ipc_object_reference(param_1);
  puVar2[0xb] = param_1;
  puVar2[0x10] = sub_F008EDC4;
  puVar2[0x12] = puVar2;
  puVar2[0x16] = 0;
  puVar2[2] = 0xfffffffe;
  puVar2[3] = 0;
  puVar2[4] = 0;
  _ipc_object_reference(puVar2[0xb]);
  return CONCAT44(param_2,puVar2);
}

