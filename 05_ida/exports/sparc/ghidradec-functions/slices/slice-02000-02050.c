/* GHIDRADEC_FUNCTION index=2000 start=0xf0094620 */

/* WARNING: Removing unreachable block (ram,0xf0094644) */

undefined8 _kdp_machine_write_regs(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_2 == 1) {
    uVar1 = 0;
    sub_F009450C(param_3);
  }
  else {
    uVar1 = 0;
    if (param_2 != 2) {
      uVar1 = 3;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2001 start=0xf0094654 */

undefined8 _kdp_machine_hostinfo(uint *param_1,int *param_2)

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
  int iVar1;
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
  *param_1 = 0;
  iVar1 = 0;
  if (0 < dword_F013C048) {
    param_2 = &_machine_slot;
    do {
      if ((*param_2 != 0) && (*param_1 = *param_1 | 1 << ((byte)iVar1 & 0x1f), param_1[1] == 0)) {
        param_1[1] = param_2[1];
        param_1[2] = param_2[2];
      }
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 8;
    } while (iVar1 < dword_F013C048);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2002 start=0xf00946d8 */

/* WARNING: Removing unreachable block (ram,0xf00946f8) */
/* WARNING: Removing unreachable block (ram,0xf00946e4) */

undefined8 _kdp_panic(undefined4 param_1,undefined4 param_2)

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
  _safe_prf(aKdpPanicS,param_1);
  _boot(1,0xc,&unk_F0112890);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2003 start=0xf0094708 */

/* WARNING: Removing unreachable block (ram,0xf0094718) */

undefined8 _kdp_reboot(undefined4 param_1,undefined4 param_2)

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
  _boot(1,4,&unk_F0112898);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2004 start=0xf0094728 */

/* WARNING: Removing unreachable block (ram,0xf0094734) */
/* WARNING: Removing unreachable block (ram,0xf009472c) */

undefined8 _kdp_intr_disbl(undefined4 param_1,undefined4 param_2)

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
  _splusclock();
  _vac_flushall();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2005 start=0xf0094744 */

/* WARNING: Removing unreachable block (ram,0xf0094758) */
/* WARNING: Removing unreachable block (ram,0xf0094750) */
/* WARNING: Removing unreachable block (ram,0xf0094760) */
/* WARNING: Removing unreachable block (ram,0xf0094748) */

undefined8 _kdp_intr_enbl(undefined4 param_1,undefined4 param_2)

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
  _en_reset(1);
  _debugger_le_init();
  _vac_flushall();
  _splx(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2006 start=0xf0094770 */

/* WARNING: Removing unreachable block (ram,0xf0094778) */

undefined8 _kdp_en_send_pkt(undefined4 param_1,undefined4 param_2)

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
  _en_send_pkt(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2007 start=0xf0094788 */

/* WARNING: Removing unreachable block (ram,0xf0094794) */

undefined8 _kdp_en_recv_pkt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  _en_recv_pkt(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2008 start=0xf00947a4 */

/* WARNING: Removing unreachable block (ram,0xf00947a8) */

undefined8 _kdp_us_spin(undefined4 param_1,undefined4 param_2)

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
  _us_spin(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2009 start=0xf00947b8 */

/* WARNING: Removing unreachable block (ram,0xf00947bc) */

undefined8 _kdp_flush_cache(undefined4 param_1,undefined4 param_2)

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
  _vac_flushall();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2010 start=0xf00947cc */

/* WARNING: Removing unreachable block (ram,0xf00947dc) */

sqword _miniMonReboot(undefined4 param_1,uint param_2)

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
  _boot(1,4,unk_F01128B0);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2011 start=0xf00947ec */

/* WARNING: Removing unreachable block (ram,0xf00947f0) */

sqword _miniMonHalt(undefined4 param_1,uint param_2)

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
  _reboot_mach(8);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2012 start=0xf0094800 */

sqword _miniMonGdb(undefined4 param_1,uint param_2)

{
  code *pcVar1;
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
  pcVar1 = (code *)sw_trap(8);
  (*pcVar1)();
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2013 start=0xf0094814 */

/* WARNING: Removing unreachable block (ram,0xf0094818) */

undefined8 _miniMonTryGetchar(undefined4 param_1,undefined4 param_2)

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
  _kmtrygetc();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2014 start=0xf0094828 */

/* WARNING: Removing unreachable block (ram,0xf0094874) */
/* WARNING: Removing unreachable block (ram,0xf0094884) */
/* WARNING: Removing unreachable block (ram,0xf009482c) */

undefined8 _miniMonGetchar(int param_1,undefined4 param_2)

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
  do {
    _kmtrygetc();
  } while (param_1 == -1);
  if (param_1 != 0x15) {
    if (param_1 < 0x16) {
      if (param_1 == 0xd) {
        _kmputc(0,0xd);
        param_1 = 10;
      }
    }
    else if (param_1 == 0x7f) {
      param_1 = 8;
    }
  }
  _kmputc(0,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2015 start=0xf0094894 */

/* WARNING: Removing unreachable block (ram,0xf009489c) */

undefined8 _miniMonPutchar(undefined4 param_1,undefined4 param_2)

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
  _kmputc(0,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2016 start=0xf00948ac */

undefined8 _PMConnect(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0x3e80100);
}
/* GHIDRADEC_FUNCTION index=2017 start=0xf00948c0 */

sqword _PMDisconnect(undefined4 param_1,uint param_2)

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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2018 start=0xf00948cc */

sqword _PMSetCpuState(undefined4 param_1,uint param_2)

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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2019 start=0xf00948d8 */

undefined8 _PMSetPowerState(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0x3e80060);
}
/* GHIDRADEC_FUNCTION index=2020 start=0xf00948ec */

undefined8 _PMGetPowerEvent(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0x3e80080);
}
/* GHIDRADEC_FUNCTION index=2021 start=0xf0094900 */

sqword _PMGetPowerStatus(undefined4 *param_1,uint param_2)

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
  *param_1 = 0xff;
  param_1[1] = 0xff;
  param_1[2] = 0;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2022 start=0xf009491c */

sqword _PMSetPowerManagement(undefined4 param_1,uint param_2)

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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2023 start=0xf0094928 */

sqword _PMRestoreDefaults(undefined4 param_1,uint param_2)

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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2024 start=0xf0094934 */

undefined8 _PMUpdateClock(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2025 start=0xf0094940 */

/* WARNING: Removing unreachable block (ram,0xf0094948) */

sqword _save_context(int param_1,uint param_2)

{
  undefined4 in_o7;
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined8 *puVar2;
  undefined4 unaff_l3;
  undefined4 *puVar3;
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
  undefined4 uVar4;
  undefined4 extraout_fs1;
  undefined8 in_fd2;
  undefined8 in_fd4;
  undefined8 in_fd6;
  undefined8 in_fd8;
  undefined8 in_fd10;
  undefined8 in_fd12;
  undefined8 in_fd14;
  undefined8 in_fd16;
  undefined8 in_fd18;
  undefined8 in_fd20;
  undefined8 in_fd22;
  undefined8 in_fd24;
  undefined8 in_fd26;
  undefined8 in_fd28;
  undefined8 in_fd30;
  undefined4 in_fsr;
  bool in_DECOMPILE_MODE;
  int in_TL;
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
  uVar1 = *(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c);
  uVar4 = _flush_windows();
  puVar3 = *(undefined4 **)(param_1 + 0x28);
  puVar3[2] = uVar1;
  *puVar3 = in_o7;
  puVar3[1] = register0x00000038;
  if ((uVar1 & 0x1000) != 0) {
    puVar2 = (undefined8 *)puVar3[0xa1];
    *(undefined4 *)(puVar2 + 0x10) = in_fsr;
    *puVar2 = CONCAT44(uVar4,extraout_fs1);
    puVar2[1] = in_fd2;
    puVar2[2] = in_fd4;
    puVar2[3] = in_fd6;
    puVar2[4] = in_fd8;
    puVar2[5] = in_fd10;
    puVar2[6] = in_fd12;
    puVar2[7] = in_fd14;
    puVar2[8] = in_fd16;
    puVar2[9] = in_fd18;
    puVar2[10] = in_fd20;
    puVar2[0xb] = in_fd22;
    puVar2[0xc] = in_fd24;
    puVar2[0xd] = in_fd26;
    puVar2[0xe] = in_fd28;
    puVar2[0xf] = in_fd30;
    puVar3[0x8d] = puVar3[0x8d] & 0xffffefff;
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2026 start=0xf00949e8 */

undefined8 _save_fpu_context(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined8 *puVar1;
  undefined4 unaff_l3;
  int iVar2;
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
  undefined8 in_fd0;
  undefined8 in_fd2;
  undefined8 in_fd4;
  undefined8 in_fd6;
  undefined8 in_fd8;
  undefined8 in_fd10;
  undefined8 in_fd12;
  undefined8 in_fd14;
  undefined8 in_fd16;
  undefined8 in_fd18;
  undefined8 in_fd20;
  undefined8 in_fd22;
  undefined8 in_fd24;
  undefined8 in_fd26;
  undefined8 in_fd28;
  undefined8 in_fd30;
  undefined4 in_fsr;
  bool in_DECOMPILE_MODE;
  int in_TL;
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
  iVar2 = *(int *)(param_1 + 0x28);
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1000) != 0) {
    puVar1 = *(undefined8 **)(iVar2 + 0x284);
    *(undefined4 *)(puVar1 + 0x10) = in_fsr;
    *puVar1 = in_fd0;
    puVar1[1] = in_fd2;
    puVar1[2] = in_fd4;
    puVar1[3] = in_fd6;
    puVar1[4] = in_fd8;
    puVar1[5] = in_fd10;
    puVar1[6] = in_fd12;
    puVar1[7] = in_fd14;
    puVar1[8] = in_fd16;
    puVar1[9] = in_fd18;
    puVar1[10] = in_fd20;
    puVar1[0xb] = in_fd22;
    puVar1[0xc] = in_fd24;
    puVar1[0xd] = in_fd26;
    puVar1[0xe] = in_fd28;
    puVar1[0xf] = in_fd30;
    *(uint *)(iVar2 + 0x234) = *(uint *)(iVar2 + 0x234) & 0xffffefff;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2027 start=0xf0094a78 */

/* WARNING: Removing unreachable block (ram,0xf0094a94) */

undefined8 _load_context(undefined4 param_1,undefined4 param_2)

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
  _reset_windows();
  return CONCAT44(param_2,param_2);
}
/* GHIDRADEC_FUNCTION index=2028 start=0xf0094ae4 */

/* WARNING: Removing unreachable block (ram,0xf0094aec) */
/* WARNING: Removing unreachable block (ram,0xf0094ae4) */

void _call_continuation(code *param_1)

{
  code *pcVar1;
  
  _flush_user_windows();
  _reset_windows();
  (*param_1)();
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=2029 start=0xf0094b10 */

undefined4 _bcopy(uint *param_1,uint *param_2,uint param_3)

{
  undefined uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  undefined *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined8 in_l0_1;
  undefined4 unaff_l3;
  undefined8 uVar10;
  undefined8 in_l4_5;
  undefined8 uVar11;
  undefined8 in_l6_7;
  undefined8 uVar12;
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
  
  uVar9 = (uint)param_1 & 3;
  if ((int)param_3 < 10) {
    puVar5 = (undefined *)((int)param_1 - (int)param_2);
    goto loc_F0094CAC;
  }
  if (uVar9 != 0) {
    if (uVar9 != 2) {
      uVar1 = *(undefined *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      *(undefined *)param_2 = uVar1;
      param_2 = (uint *)((int)param_2 + 1);
      param_3 = param_3 - 1;
      if (uVar9 == 3) goto loc_F0094B6C;
    }
    uVar2 = *(undefined2 *)param_1;
    param_1 = (uint *)((int)param_1 + 2);
    *(char *)param_2 = (char)((word)uVar2 >> 8);
    *(char *)((int)param_2 + 1) = (char)uVar2;
    param_2 = (uint *)((int)param_2 + 2);
    param_3 = param_3 - 2;
  }
loc_F0094B6C:
  uVar9 = (uint)param_2 & 3;
  if (uVar9 == 0) {
    if ((((int)param_3 < 0x200) || (((uint)param_1 & 7) != 0)) || (((uint)param_2 & 7) != 0)) {
      puVar5 = (undefined *)((int)param_1 - (int)param_2);
      uVar9 = param_3 & 0xfffffffc;
    }
    else {
      iVar7 = 0x100;
      if (!in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
        *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
        *(int *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = (int)((qword)in_l0_1 >> 0x20);
        *(int *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
        *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
        *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
        *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
        *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)in_l6_7 >> 0x20);
        *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = (int)in_l6_7;
      }
      do {
        uVar10 = *(undefined8 *)(param_1 + 0x3c);
        uVar11 = *(undefined8 *)(param_1 + 0x3a);
        uVar12 = *(undefined8 *)(param_1 + 0x38);
        *(undefined8 *)(param_2 + 0x3e) = *(undefined8 *)(param_1 + 0x3e);
        *(undefined8 *)(param_2 + 0x3c) = uVar10;
        *(undefined8 *)(param_2 + 0x3a) = uVar11;
        *(undefined8 *)(param_2 + 0x38) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x34);
        uVar11 = *(undefined8 *)(param_1 + 0x32);
        uVar12 = *(undefined8 *)(param_1 + 0x30);
        *(undefined8 *)(param_2 + 0x36) = *(undefined8 *)(param_1 + 0x36);
        *(undefined8 *)(param_2 + 0x34) = uVar10;
        *(undefined8 *)(param_2 + 0x32) = uVar11;
        *(undefined8 *)(param_2 + 0x30) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x2c);
        uVar11 = *(undefined8 *)(param_1 + 0x2a);
        uVar12 = *(undefined8 *)(param_1 + 0x28);
        *(undefined8 *)(param_2 + 0x2e) = *(undefined8 *)(param_1 + 0x2e);
        *(undefined8 *)(param_2 + 0x2c) = uVar10;
        *(undefined8 *)(param_2 + 0x2a) = uVar11;
        *(undefined8 *)(param_2 + 0x28) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x24);
        uVar11 = *(undefined8 *)(param_1 + 0x22);
        uVar12 = *(undefined8 *)(param_1 + 0x20);
        *(undefined8 *)(param_2 + 0x26) = *(undefined8 *)(param_1 + 0x26);
        *(undefined8 *)(param_2 + 0x24) = uVar10;
        *(undefined8 *)(param_2 + 0x22) = uVar11;
        *(undefined8 *)(param_2 + 0x20) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x1c);
        uVar11 = *(undefined8 *)(param_1 + 0x1a);
        uVar12 = *(undefined8 *)(param_1 + 0x18);
        *(undefined8 *)(param_2 + 0x1e) = *(undefined8 *)(param_1 + 0x1e);
        *(undefined8 *)(param_2 + 0x1c) = uVar10;
        *(undefined8 *)(param_2 + 0x1a) = uVar11;
        *(undefined8 *)(param_2 + 0x18) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x14);
        uVar11 = *(undefined8 *)(param_1 + 0x12);
        uVar12 = *(undefined8 *)(param_1 + 0x10);
        *(undefined8 *)(param_2 + 0x16) = *(undefined8 *)(param_1 + 0x16);
        *(undefined8 *)(param_2 + 0x14) = uVar10;
        *(undefined8 *)(param_2 + 0x12) = uVar11;
        *(undefined8 *)(param_2 + 0x10) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0xc);
        uVar11 = *(undefined8 *)(param_1 + 10);
        uVar12 = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(param_2 + 0xe) = *(undefined8 *)(param_1 + 0xe);
        *(undefined8 *)(param_2 + 0xc) = uVar10;
        *(undefined8 *)(param_2 + 10) = uVar11;
        *(undefined8 *)(param_2 + 8) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 4);
        uVar11 = *(undefined8 *)(param_1 + 2);
        uVar12 = *(undefined8 *)param_1;
        *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 6);
        *(undefined8 *)(param_2 + 4) = uVar10;
        *(undefined8 *)(param_2 + 2) = uVar11;
        *(undefined8 *)param_2 = uVar12;
        param_3 = param_3 - iVar7;
        param_1 = (uint *)((int)param_1 + iVar7);
        param_2 = (uint *)((int)param_2 + iVar7);
      } while (0xff < (int)param_3);
      puVar5 = (undefined *)((int)param_1 - (int)param_2);
      if ((int)param_3 < 10) goto loc_F0094CAC;
      uVar9 = param_3 & 0xfffffffc;
    }
    do {
      uVar8 = uVar9 - 4;
      *param_2 = *(uint *)(puVar5 + (int)param_2);
      bVar3 = 3 < (int)uVar9;
      param_2 = param_2 + 1;
      uVar9 = uVar8;
    } while (uVar8 != 0 && bVar3);
    param_3 = param_3 & 3;
  }
  else if (uVar9 == 2) {
    uVar8 = *param_1;
    *(sword *)param_2 = (sword)(uVar8 >> 0x10);
    param_2 = (uint *)((int)param_2 + 2);
    uVar9 = param_3 - 2 & 0xfffffffc;
    puVar5 = (undefined *)((int)param_1 + (4 - (int)param_2));
    do {
      uVar4 = uVar8 << 0x10;
      uVar8 = *(uint *)(puVar5 + (int)param_2);
      uVar9 = uVar9 - 4;
      *param_2 = uVar8 >> 0x10 | uVar4;
      param_2 = param_2 + 1;
    } while (uVar9 != 0);
    puVar5 = puVar5 + -2;
    param_3 = param_3 - 2 & 3;
  }
  else {
    uVar8 = *param_1;
    *(char *)param_2 = (char)(uVar8 >> 0x18);
    puVar6 = (uint *)((int)param_2 + 1);
    if (uVar9 == 3) {
      uVar9 = param_3 - 1 & 0xfffffffc;
      puVar5 = (undefined *)((int)param_1 + (4 - (int)puVar6));
      param_2 = puVar6;
      do {
        uVar4 = uVar8 << 8;
        uVar8 = *(uint *)(puVar5 + (int)param_2);
        uVar9 = uVar9 - 4;
        *param_2 = uVar8 >> 0x18 | uVar4;
        param_2 = param_2 + 1;
      } while (uVar9 != 0);
      puVar5 = puVar5 + -3;
      param_3 = param_3 - 1 & 3;
    }
    else {
      *(sword *)puVar6 = (sword)(uVar8 >> 8);
      param_2 = (uint *)((int)param_2 + 3);
      uVar9 = param_3 - 3 & 0xfffffffc;
      puVar5 = (undefined *)((int)param_1 + (4 - (int)param_2));
      do {
        uVar4 = uVar8 << 0x18;
        uVar8 = *(uint *)(puVar5 + (int)param_2);
        uVar9 = uVar9 - 4;
        *param_2 = uVar8 >> 8 | uVar4;
        param_2 = param_2 + 1;
      } while (uVar9 != 0);
      puVar5 = puVar5 + -1;
      param_3 = param_3 - 3 & 3;
    }
  }
loc_F0094CAC:
  while (0 < (int)param_3) {
    *(undefined *)param_2 = puVar5[(int)param_2];
    param_2 = (uint *)((int)param_2 + 1);
    param_3 = param_3 - 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2030 start=0xf0094df0 */

void _ovbcopy(undefined *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  bool bVar2;
  int iVar3;
  
  if (param_3 < 1) {
    return;
  }
  iVar3 = (int)param_1 - (int)param_2;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar3 < param_3) {
    if (param_2 <= param_1) {
      do {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        *param_2 = uVar1;
        iVar3 = param_3 + -1;
        bVar2 = 0 < param_3;
        param_2 = param_2 + 1;
        param_3 = iVar3;
      } while (iVar3 != 0 && bVar2);
      return;
    }
    do {
      iVar3 = param_3 + -1;
      bVar2 = 0 < param_3;
      param_2[iVar3] = param_1[iVar3];
      param_3 = iVar3;
    } while (iVar3 != 0 && bVar2);
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2031 start=0xf0094e58 */

undefined8 _bzero(undefined8 *param_1,uint param_2)

{
  undefined4 unaff_g1;
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
  uint uVar1;
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
  if ((int)param_2 < 0xf) {
loc_F0094F60:
    while (0 < (int)param_2) {
      *(undefined *)param_1 = 0;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_2 = param_2 - 1;
    }
    return CONCAT44(param_2 - 1,unaff_g1);
  }
  uVar1 = 0x100;
  for (; ((uint)param_1 & 3) != 0; param_1 = (undefined8 *)((int)param_1 + 1)) {
    *(undefined *)param_1 = 0;
    param_2 = param_2 - 1;
  }
  unaff_g1 = 0;
  if (((uint)param_1 & 7) != 0) {
    *(undefined4 *)param_1 = 0;
    param_2 = param_2 - 4;
    param_1 = (undefined8 *)((int)param_1 + 4);
  }
  do {
    if (0xff < (int)param_2) {
      param_1[0x1f] = 0;
loc_F0094EA8:
      param_1[0x1e] = 0;
      goto loc_f0094eac;
    }
    uVar1 = param_2 & 0xfffffff8;
    switch(param_2) {
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
loc_f0094eac:
      param_1[0x1d] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x1c] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x1b] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x1a] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x19] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x18] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x17] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x16] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x15] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x14] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x13] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x12] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x11] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x10] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xf] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xe] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xd] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xc] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xb] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[10] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[9] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[8] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[7] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[6] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[5] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[4] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[3] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[2] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[1] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      *param_1 = 0;
      param_1 = (undefined8 *)((int)param_1 + uVar1);
      param_2 = param_2 - uVar1;
      break;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      goto loc_F0094EA8;
    :
      goto loc_F0094F60;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2032 start=0xf0094f74 */

/* WARNING: Removing unreachable block (ram,0xf0094ff4) */

undefined4 _hwbcopy(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = _bcopy_res._0_1_;
  _bcopy_res = CONCAT13(0xff,_bcopy_res._1_3_);
  iVar3 = _page_size;
  if (cVar2 == '\0') {
    do {
      iVar1 = segment(2);
      *(undefined4 *)(iVar1 + 0x1c00100) = param_1;
      iVar1 = segment(2);
      *(undefined4 *)(iVar1 + 0x1c00200) = param_3;
      param_2 = param_2 + 0x20;
      iVar3 = iVar3 + -0x20;
      param_4 = param_4 + 0x20;
    } while (iVar3 != 0);
    iVar3 = segment(2);
    if (((*(uint *)(iVar3 + 0x1c00e00) & 0x4000000) == 0) ||
       ((*(uint *)(iVar3 + 0x1c00e00) & 0x2000000) == 0)) {
      _bcopy_res = 0;
      return 0;
    }
    _panic(aHwBcopyStreamO,param_2,0x2000000,param_4);
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2033 start=0xf0095040 */

/* WARNING: Removing unreachable block (ram,0xf00950bc) */

undefined4 _hwbzero(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = _page_size;
  cVar2 = _bcopy_res._0_1_;
  _bcopy_res = CONCAT13(0xff,_bcopy_res._1_3_);
  if (cVar2 == '\0') {
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00100) = param_3;
    do {
      iVar1 = segment(2);
      *(undefined4 *)(iVar1 + 0x1c00200) = param_1;
      iVar3 = iVar3 + -0x20;
      param_2 = param_2 + 0x20;
    } while (iVar3 != 0);
    iVar3 = segment(2);
    if (((*(uint *)(iVar3 + 0x1c00e00) & 0x4000000) == 0) ||
       ((*(uint *)(iVar3 + 0x1c00e00) & 0x2000000) == 0)) {
      _bcopy_res = 0;
      return 0;
    }
    _panic(aHwBzeroStreamO,param_2);
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2034 start=0xf0095100 */

void _syncfpu(void)

{
  undefined4 in_fsr;
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1000) != 0) {
    dword_F01128CC = in_fsr;
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2035 start=0xf0095130 */

/* WARNING: Control flow encountered bad instruction data */

void _fpu_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
/* GHIDRADEC_FUNCTION index=2036 start=0xf009518c */

/* WARNING: Removing unreachable block (ram,0xf0095208) */
/* WARNING: Removing unreachable block (ram,0xf00951f8) */

void _fp_exception(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined in_fq0 [16];
  undefined4 in_fsr;
  
  iVar1 = _fp_ctxp;
  *(undefined4 *)(_fp_ctxp + 0x80) = in_fsr;
  uVar3 = (*(uint *)(iVar1 + 0x80) & 0x1c000) >> 0xe;
  uVar2 = 0;
  while ((*(uint *)(iVar1 + 0x80) & 0x2000) != 0) {
    *(undefined (*) [16])(iVar1 + 0x90 + uVar2) = in_fq0;
    uVar2 = uVar2 + 8;
    *(undefined4 *)(iVar1 + 0x80) = in_fsr;
  }
  if (3 < uVar3) {
    _panic(aUnexpectedFloa,uVar3);
  }
  *(uint *)(iVar1 + 0x8c) = uVar2 >> 3;
  _fp_runq(&stack0x0000005c);
  *(uint *)(iVar1 + 0x80) = *(uint *)(iVar1 + 0x80) & 0xfffe1fff;
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=2037 start=0xf0095228 */

undefined4 _fp_enable(undefined8 *param_1)

{
  return (int)((qword)*param_1 >> 0x20);
}
/* GHIDRADEC_FUNCTION index=2038 start=0xf009528c */

void _fp_dumpregs(undefined8 *param_1)

{
  undefined8 in_fd0;
  undefined8 in_fd2;
  undefined8 in_fd4;
  undefined8 in_fd6;
  undefined8 in_fd8;
  undefined8 in_fd10;
  undefined8 in_fd12;
  undefined8 in_fd14;
  undefined8 in_fd16;
  undefined8 in_fd18;
  undefined8 in_fd20;
  undefined8 in_fd22;
  undefined8 in_fd24;
  undefined8 in_fd26;
  undefined8 in_fd28;
  undefined8 in_fd30;
  undefined4 in_fsr;
  
  *(undefined4 *)(param_1 + 0x10) = in_fsr;
  *param_1 = in_fd0;
  param_1[1] = in_fd2;
  param_1[2] = in_fd4;
  param_1[3] = in_fd6;
  param_1[4] = in_fd8;
  param_1[5] = in_fd10;
  param_1[6] = in_fd12;
  param_1[7] = in_fd14;
  param_1[8] = in_fd16;
  param_1[9] = in_fd18;
  param_1[10] = in_fd20;
  param_1[0xb] = in_fd22;
  param_1[0xc] = in_fd24;
  param_1[0xd] = in_fd26;
  param_1[0xe] = in_fd28;
  param_1[0xf] = in_fd30;
  return;
}
/* GHIDRADEC_FUNCTION index=2039 start=0xf00952d8 */

void __fp_read_pfreg(undefined4 param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0xf00952e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(sub_F0095300 + param_2 * 8))();
  return;
}
/* GHIDRADEC_FUNCTION index=2040 start=0xf00952ec */

void __fp_write_pfreg(undefined4 param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0xf00952f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(locret_F0095400 + param_2 * 8))();
  return;
}
/* GHIDRADEC_FUNCTION index=2041 start=0xf0095500 */

void __fp_write_pfsr(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2042 start=0xf0095580 */

/* WARNING: Removing unreachable block (ram,0xf00955cc) */

void _fp_disabled(void)

{
  undefined *unaff_l1;
  
  if (unaff_l1 != &loc_F009514C) {
    _fp_is_disabled(_active_pcb + 0x234);
    sys_rtt();
    return;
  }
  _fpu_exists = 0;
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=2043 start=0xf00955dc */

void _mmu_getcr(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00955e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_getcr)();
  return;
}
/* GHIDRADEC_FUNCTION index=2044 start=0xf00955ec */

void _mmu_getctp(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00955f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_getctp)();
  return;
}
/* GHIDRADEC_FUNCTION index=2045 start=0xf00955fc */

void _mmu_getctx(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095604. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_getctx)();
  return;
}
/* GHIDRADEC_FUNCTION index=2046 start=0xf009560c */

void _mmu_probe(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095614. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_probe)();
  return;
}
/* GHIDRADEC_FUNCTION index=2047 start=0xf009561c */

void _mmu_setcr(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095624. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_setcr)();
  return;
}
/* GHIDRADEC_FUNCTION index=2048 start=0xf009562c */

void _mmu_setctp(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095634. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_setctp)();
  return;
}
/* GHIDRADEC_FUNCTION index=2049 start=0xf009563c */

void _mmu_setctx(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095644. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_setctx)();
  return;
}

