
/* WARNING: Removing unreachable block (ram,0xf00a7738) */
/* WARNING: Removing unreachable block (ram,0xf00a7714) */
/* WARNING: Removing unreachable block (ram,0xf00a76d0) */
/* WARNING: Removing unreachable block (ram,0xf00a7698) */
/* WARNING: Removing unreachable block (ram,0xf00a7664) */
/* WARNING: Removing unreachable block (ram,0xf00a764c) */
/* WARNING: Removing unreachable block (ram,0xf00a7654) */
/* WARNING: Removing unreachable block (ram,0xf00a767c) */
/* WARNING: Removing unreachable block (ram,0xf00a76b4) */
/* WARNING: Removing unreachable block (ram,0xf00a76ec) */
/* WARNING: Removing unreachable block (ram,0xf00a771c) */
/* WARNING: Removing unreachable block (ram,0xf00a7744) */
/* WARNING: Removing unreachable block (ram,0xf00a7624) */

undefined8
_badtrap(uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
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
  _splaudio();
  _printf(aBadTrapCpuDTyp,_cpuid,param_1,param_2,param_3,param_4,param_5);
  _mmu_print_sfsr(param_4);
  _printf(aRegsAtX,param_2);
  _printf(aPsrXPcXNpcX,*param_2,param_2[1],param_2[2]);
  _printf(aYXG1XG2XG3X,param_2[3],param_2[4],param_2[5],param_2[6]);
  _printf(aG4XG5XG6XG7X,param_2[7],param_2[8],param_2[9],param_2[10]);
  _printf(aO0XO1XO2XO3X,param_2[0xb],param_2[0xc],param_2[0xd],param_2[0xe]);
  _printf(aO4XO5XSpXRaX,param_2[0xf],param_2[0x10],param_2[0x11],param_2[0x12]);
  if (_active_threads != 0) {
    _showregs(param_1,param_2,param_3,param_4,param_5);
  }
  _traceback(param_2[0x11]);
  if (param_1 < 0x2c) {
    _panic(*(undefined4 *)(_trap_type + param_1 * 4));
  }
  _panic(&aTrap);
  return CONCAT44(param_2,param_1);
}
