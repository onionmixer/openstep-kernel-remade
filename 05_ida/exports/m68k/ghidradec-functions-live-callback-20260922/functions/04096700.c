
void __m68k_dbginit(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 in_A1;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  undefined4 in_stack_00000000;
  
  dword_40C9714 = &stack0x00000004;
  word_40C971A = (word)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF);
  word_40C9720 = 0;
  dword_40C96D8 = in_D0;
  DAT_40c96dc._0_4_ = in_D1;
  DAT_40c96dc._4_4_ = unaff_D2;
  DAT_40c96dc._8_4_ = unaff_D3;
  DAT_40c96dc._12_4_ = unaff_D4;
  DAT_40c96dc._16_4_ = unaff_D5;
  DAT_40c96dc._20_4_ = unaff_D6;
  DAT_40c96dc._24_4_ = unaff_D7;
  DAT_40c96dc._28_4_ = in_stack_00000000;
  DAT_40c96dc._32_4_ = in_A1;
  DAT_40c96dc._36_4_ = unaff_A2;
  DAT_40c96dc._40_4_ = unaff_A3;
  DAT_40c96dc._44_4_ = unaff_A4;
  DAT_40c96dc._48_4_ = unaff_A5;
  DAT_40c96dc._52_4_ = unaff_A6;
  dword_40C971C = in_stack_00000000;
  *(code **)(_dbgstack + 0x3fc) = __dbg_trap;
  _m68k_dbginit();
  return;
}

