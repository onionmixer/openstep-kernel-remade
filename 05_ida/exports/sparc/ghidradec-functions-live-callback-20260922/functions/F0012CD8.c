
/* WARNING: Removing unreachable block (ram,0xf0012d88) */
/* WARNING: Removing unreachable block (ram,0xf0012d40) */
/* WARNING: Removing unreachable block (ram,0xf0012d4c) */
/* WARNING: Removing unreachable block (ram,0xf0012da4) */
/* WARNING: Removing unreachable block (ram,0xf0012d2c) */

undefined8
_rpsleep(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
        undefined4 param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
  if (((int)(char)*(byte *)(dword_F0133DDC + 0x40) & 0x80U) == 0) {
    *(byte *)(dword_F0133DDC + 0x40) = *(byte *)(dword_F0133DDC + 0x40) | 0x80;
    _uprintf(aSSSPausing,_active_u + 8,*(undefined4 *)((int)register0x00000038 + 0x50),
             *(undefined4 *)((int)register0x00000038 + 0x54));
  }
  _bcopy(dword_F0133DDC + 0x28,(undefined *)((int)register0x00000038 + -0x10),8);
  iVar1 = dword_F0133DDC + 0x28;
  _setjmp();
  if (iVar1 == 0) {
    (**(code **)((int)register0x00000038 + 0x44))
              (*(undefined4 *)((int)register0x00000038 + 0x48),
               *(undefined4 *)((int)register0x00000038 + 0x4c));
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  }
  _bcopy((undefined *)((int)register0x00000038 + -0x10),dword_F0133DDC + 0x28,8);
  uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
  if (((int)*(char *)(dword_F0133DDC + 0x40) & 0x80U) == 0) {
    _rpcont();
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
  }
  return CONCAT44(param_2,uVar2);
}

