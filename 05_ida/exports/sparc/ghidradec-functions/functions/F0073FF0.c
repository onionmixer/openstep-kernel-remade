
/* WARNING: Removing unreachable block (ram,0xf00740cc) */
/* WARNING: Removing unreachable block (ram,0xf0074098) */
/* WARNING: Removing unreachable block (ram,0xf00740a0) */
/* WARNING: Removing unreachable block (ram,0xf00740f4) */
/* WARNING: Removing unreachable block (ram,0xf0074008) */

undefined8 _thread_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = 0x1a0;
  _zinit(0x1a0,0x34000,0x6800,0,&aThreads);
  DAT_f013c988._0_4_ = 0;
  DAT_f013c988._28_4_ = 2;
  DAT_f013c988._32_4_ = 0;
  DAT_f013c988._36_4_ = 0;
  DAT_f013c988._40_4_ = 0;
  DAT_f013c988._52_4_ = 0;
  DAT_f013c988._60_4_ = 0;
  DAT_f013c988._64_4_ = 0;
  DAT_f013c988._68_4_ = 0x102;
  DAT_f013c988._44_4_ = _thread_bootstrap_return;
  DAT_f013c988._48_4_ = 0;
  DAT_f013c988._76_4_ = 0x12;
  DAT_f013c988._84_4_ = 0;
  DAT_f013c988._88_4_ = 1;
  DAT_f013c988._92_4_ = 0xffffffff;
  DAT_f013c988._96_4_ = 0;
  DAT_f013c988._100_4_ = 0;
  DAT_f013c988._108_4_ = 0;
  DAT_f013c988._112_4_ = 0;
  DAT_f013c988._116_4_ = 0;
  DAT_f013c988._120_4_ = 0;
  DAT_f013c988._128_4_ = 0xffffffff;
  DAT_f013c988._132_4_ = 1;
  _thread_zone = uVar1;
  _timer_init(0xf013ca60);
  _timer_init(0xf013ca70);
  DAT_f013c988._248_4_ = 0;
  DAT_f013c988._252_4_ = 0;
  DAT_f013c988._256_4_ = 0;
  DAT_f013c988._260_4_ = 0;
  DAT_f013c988._264_4_ = 0;
  DAT_f013c988._268_4_ = 0;
  DAT_f013c988._384_4_ = 0;
  DAT_f013c988._388_4_ = 0;
  DAT_f013c988._396_4_ = 0;
  DAT_f013c988._400_4_ = 0;
  _initKernelStacks();
  DAT_f0135154 = &_reaper_queue;
  _reaper_queue._0_4_ = &_reaper_queue;
  _reaper_lock = 0;
  _stack_usage_lock = 0;
  _pcb_module_init();
  return CONCAT44(param_2,param_1);
}
