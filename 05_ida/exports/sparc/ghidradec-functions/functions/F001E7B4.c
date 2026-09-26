
/* WARNING: Removing unreachable block (ram,0xf001e82c) */
/* WARNING: Removing unreachable block (ram,0xf001e818) */
/* WARNING: Removing unreachable block (ram,0xf001e800) */
/* WARNING: Removing unreachable block (ram,0xf001e824) */
/* WARNING: Removing unreachable block (ram,0xf001e834) */
/* WARNING: Removing unreachable block (ram,0xf001e7e8) */

undefined8 _sofree(uint param_1,undefined4 param_2)

{
  uint uVar1;
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
  if ((*(int *)(param_1 + 8) == 0) && ((*(word *)(param_1 + 6) & 1) != 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      uVar1 = param_1;
      _soqremque(param_1,0);
      if (uVar1 == 0) {
        uVar1 = param_1;
        _soqremque(param_1,1);
        if (uVar1 == 0) {
          _panic(aSofreeDq);
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
    }
    _sbrelease(param_1 + 0x3c);
    _sorflush(param_1);
    _m_free(param_1 & 0xffffff80);
  }
  return CONCAT44(param_2,param_1);
}
