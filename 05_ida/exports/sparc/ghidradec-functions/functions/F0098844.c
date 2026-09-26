
/* WARNING: Removing unreachable block (ram,0xf00988c8) */
/* WARNING: Removing unreachable block (ram,0xf00988bc) */
/* WARNING: Removing unreachable block (ram,0xf0098a0c) */
/* WARNING: Removing unreachable block (ram,0xf00988a4) */

undefined8 _fill_modinfo(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
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
  bool bVar7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined auStack_30 [48];
  
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
  puVar6 = (undefined *)((int)register0x00000038 + -0x30);
  iVar5 = 0x27;
  iVar2 = dword_F0112A40 * 0x74;
  iVar1 = dword_F0112A40 * 0x1d;
  do {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    bVar7 = 0 < iVar5;
    iVar5 = iVar5 + -1;
  } while (bVar7);
  iVar5 = param_1;
  dword_F0112A40 = dword_F0112A40 + 1;
  _prom_getprop(param_1,&_psname,(undefined *)((int)register0x00000038 + -0x30));
  if (iVar5 != -1) {
    _strcpy(*(undefined4 *)(DAT_f0112a68 + iVar2),(undefined *)((int)register0x00000038 + -0x30));
    _fill_nodeinfo(param_1,param_2);
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x3c) = dword_F0112F5C;
    uVar4 = dword_F0112F60;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 4) = dword_F0112F2C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x40) = uVar4;
    uVar4 = dword_F0112F30;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x44) = dword_F0112F64;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0xc) = uVar4;
    uVar4 = dword_F0112F58;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x10) = dword_F0112F34;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x34) = uVar4;
    uVar4 = dword_F0112F3C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x14) = dword_F0112F38;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x18) = uVar4;
    uVar4 = dword_F0112F44;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x1c) = dword_F0112F40;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x20) = uVar4;
    uVar4 = dword_F0112F50;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x30) = dword_F0112F54;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x2c) = uVar4;
    uVar4 = dword_F0112F48;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x28) = dword_F0112F4C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x24) = uVar4;
    uVar4 = dword_F0112F6C;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x48) = dword_F0112F68;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x4c) = uVar4;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x50) = dword_F0112F70;
    uVar4 = dword_F0112F78;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x54) = dword_F0112F74;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x58) = uVar4;
    uVar4 = dword_F0112F80;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x5c) = dword_F0112F7C;
    iVar5 = dword_F0112F84;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x60) = uVar4;
    uVar4 = dword_F0112F88;
    *(int *)(DAT_f0112a68 + iVar2 + 100) = iVar5;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x68) = uVar4;
    uVar3 = dword_F0112F90;
    bVar7 = dword_F0112F90 == 0;
    *(undefined4 *)(DAT_f0112a68 + iVar2 + 0x6c) = dword_F0112F8C;
    if (bVar7) {
      _getpsr();
      if (uVar3 >> 0x18 == 4) {
        (&_mod_info)[iVar1] = 4;
      }
      else {
        uVar4 = 0x41;
        if (dword_F0112F84 == 0) {
          uVar4 = 0x40;
        }
        (&_mod_info)[iVar1] = uVar4;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
