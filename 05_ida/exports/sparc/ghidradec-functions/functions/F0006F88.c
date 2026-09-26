
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf0007008) */
/* WARNING: Removing unreachable block (ram,0xf000702c) */
/* WARNING: Removing unreachable block (ram,0xf0007050) */
/* WARNING: Removing unreachable block (ram,0xf000709c) */
/* WARNING: Removing unreachable block (ram,0xf0006fec) */
/* WARNING: Removing unreachable block (ram,0xf00070ac) */
/* WARNING: Removing unreachable block (ram,0xf0007060) */
/* WARNING: Removing unreachable block (ram,0xf000703c) */
/* WARNING: Removing unreachable block (ram,0xf0007018) */
/* WARNING: Removing unreachable block (ram,0xf0006fdc) */

void multiply_check(void)

{
  undefined4 unaff_g1;
  undefined8 in_g2_3;
  uint uVar1;
  byte unaff_l0;
  uint *unaff_l1;
  uint uVar2;
  int in_TL;
  
  if ((1 << (unaff_l0 & 0x1f) &
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c)) != 0) {
    return;
  }
  uVar2 = *unaff_l1;
  if (uVar2 >> 0x1e != 2) {
    sys_trap();
    return;
  }
  unk_F010A7C0._0_8_ = in_g2_3;
  unk_F010A7C0._8_4_ = unaff_g1;
  if ((uVar2 >> 0xd & 1) == 0) {
    uVar1 = uVar2 & 0x1f;
    sub_F0007114(uVar1,uVar2 << 0x13);
  }
  else {
    uVar1 = (int)(uVar2 << 0x13) >> 0x13;
  }
  sub_F0007114(uVar2 >> 0xe & 0x1f,uVar1);
  uVar2 = uVar2 >> 0x13 & 0x3f;
  if (uVar2 == 10) {
    .umul();
    sub_F00071D8();
  }
  else if (uVar2 == 0xb) {
    .mul();
    sub_F00071D8();
  }
  else if (uVar2 == 0x1a) {
    .umul();
    sub_F00071D8();
  }
  else {
    if (uVar2 != 0x1b) {
      sys_trap();
      return;
    }
    .mul();
    sub_F00071D8();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
