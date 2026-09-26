
/* WARNING: Removing unreachable block (ram,0xf00ee050) */
/* WARNING: Removing unreachable block (ram,0xf00ee0e8) */
/* WARNING: Removing unreachable block (ram,0xf00ee0a4) */
/* WARNING: Removing unreachable block (ram,0xf00ee07c) */
/* WARNING: Removing unreachable block (ram,0xf00ee0cc) */
/* WARNING: Removing unreachable block (ram,0xf00ee108) */
/* WARNING: Removing unreachable block (ram,0xf00ee060) */
/* WARNING: Removing unreachable block (ram,0xf00ee038) */

undefined8 sub_F00EE030(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
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
  iVar4 = param_1;
  _strlen();
  uVar6 = iVar4 + 1;
  if (uVar6 < 0xb5) {
    puVar2 = DAT_f012f000;
    piVar1 = dword_F012F094;
    if (dword_F012F094 == (int *)0x0) {
      _simple_lock_alloc();
      dword_F012F094 = (int *)puVar2;
      *(int *)puVar2 = 0;
      piVar1 = dword_F012F094;
    }
    do {
      do {
      } while (*piVar1 != 0);
      piVar3 = piVar1;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    iVar4 = iVar4 + 0x168;
    if (dword_F012F090 < uVar6) {
      udiv(iVar4,0x168);
      uVar5 = iVar4 * 0x168;
      dword_F012F090 = uVar5;
      _kalloc();
      dword_F012F08C = uVar5;
    }
    uVar5 = dword_F012F08C;
    _memmove(dword_F012F08C,param_1,uVar6);
    dword_F012F08C = uVar6 + dword_F012F08C;
    dword_F012F090 = dword_F012F090 - uVar6;
    *dword_F012F094 = 0;
  }
  else {
    _kalloc(uVar6);
    _memmove();
    uVar5 = uVar6;
  }
  return CONCAT44(param_2,uVar5);
}

