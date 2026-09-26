
/* WARNING: Removing unreachable block (ram,0xf00ed12c) */
/* WARNING: Removing unreachable block (ram,0xf00ed0fc) */
/* WARNING: Removing unreachable block (ram,0xf00ed0f4) */
/* WARNING: Removing unreachable block (ram,0xf00ed104) */
/* WARNING: Removing unreachable block (ram,0xf00ed138) */
/* WARNING: Removing unreachable block (ram,0xf00ed0ec) */

undefined8 sub_F00ED0E8(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  puVar1 = (undefined4 *)0x8;
  _malloc();
  _free();
  _NXDefaultMallocZone();
  puVar2 = puVar1;
  _NXDefaultMallocZone();
  (*(code *)puVar1[1])();
  dword_F012F080 = puVar2;
  *puVar2 = unk_F012F070;
  puVar2[1] = 1;
  puVar2[2] = 1;
  _NXDefaultMallocZone();
  _NXZoneCalloc();
  puVar1 = dword_F012F080;
  dword_F012F080[3] = puVar2;
  puVar1[4] = 0;
  *(undefined4 *)puVar1[3] = 1;
  *(undefined **)(puVar1[3] + 4) = unk_F012F070;
  return CONCAT44(param_2,param_1);
}

