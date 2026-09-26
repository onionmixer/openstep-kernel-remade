/* GHIDRADEC_FUNCTION index=2200 start=0xf0097144 */

void _memerr_init(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009714c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_memerr_init)();
  return;
}
/* GHIDRADEC_FUNCTION index=2201 start=0xf0097154 */

void _memerr_disable(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009715c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_memerr_disable)();
  return;
}
/* GHIDRADEC_FUNCTION index=2202 start=0xf0097164 */

void _flush_writebuffers(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009716c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_flush_writebuffers)();
  return;
}
/* GHIDRADEC_FUNCTION index=2203 start=0xf0097174 */

void _flush_writebuffers_to(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009717c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_flush_poke_writebuffers)();
  return;
}
/* GHIDRADEC_FUNCTION index=2204 start=0xf0097184 */

void _init_all_fsr(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009718c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_init_all_fsr)();
  return;
}
/* GHIDRADEC_FUNCTION index=2205 start=0xf0097194 */

void _p4m50_sys_setfunc(void)

{
  _v_set_diagled = _p4m50_set_diagled;
  _v_init_all_fsr = _p4m50_init_all_fsr;
  return;
}
/* GHIDRADEC_FUNCTION index=2206 start=0xf00971bc */

void _p4m50_set_diagled(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x2f);
  iVar2 = segment(0x2f);
  *(byte *)(iVar2 + -0xe800000) = *(byte *)(iVar1 + -0xe800000) | 0xc1;
  return;
}
/* GHIDRADEC_FUNCTION index=2207 start=0xf00971d4 */

void _p4m50_init_all_fsr(void)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  segment(0x2f);
  segment(0x2f);
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0x1ffff000) = 0;
  segment(0x2f);
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + 8) = 0;
  puVar2 = (uint *)segment(0x2f);
  puVar3 = (uint *)segment(0x2f);
  *puVar3 = *puVar2 | 3;
  iVar1 = segment(0x2f);
  iVar4 = segment(0x2f);
  *(uint *)(iVar4 + -0x1fffeff8) = *(uint *)(iVar1 + -0x1fffeff8) | 0x80100000;
  return;
}
/* GHIDRADEC_FUNCTION index=2208 start=0xf0097228 */

void ** _p4m690_sys_setfunc(void)

{
  return &_v_get_sysctl;
}
/* GHIDRADEC_FUNCTION index=2209 start=0xf0097238 */

void _sun4m_memerr_disable(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2210 start=0xf0097240 */

undefined4 _sun4m_get_sysctl(void)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  return *(undefined4 *)(iVar1 + -0xe100000);
}
/* GHIDRADEC_FUNCTION index=2211 start=0xf009724c */

void _sun4m_set_sysctl(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0xe100000) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2212 start=0xf0097258 */

void _sun4m_set_diagled(word param_1)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(word *)(iVar1 + -0xea00000) = param_1 ^ 0xffff;
  return;
}
/* GHIDRADEC_FUNCTION index=2213 start=0xf0097270 */

undefined4 _sun4m_get_diagmesg(void)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  return *(undefined4 *)(iVar1 + 0x1000);
}
/* GHIDRADEC_FUNCTION index=2214 start=0xf009727c */

void _sun4m_set_diagmesg(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + 0x1000) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2215 start=0xf0097288 */

void _sun4m_enable_dvma(void)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0x1fffeff8) = 0x10;
  return;
}
/* GHIDRADEC_FUNCTION index=2216 start=0xf009729c */

void _sun4m_disable_dvma(void)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0x1fffeff8) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2217 start=0xf00972ac */

void _sun4m_flush_writebuffers(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2218 start=0xf00972dc */

void _sun4m_flush_poke_writebuffers(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2219 start=0xf0097334 */

void _sun4m_init_all_fsr(void)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  segment(0x2f);
  segment(0x2f);
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0x1ffff000) = 0;
  segment(0x2f);
  segment(0x2f);
  segment(0x2f);
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + 8) = 0;
  puVar2 = (uint *)segment(0x2f);
  puVar3 = (uint *)segment(0x2f);
  *puVar3 = *puVar2 | 1;
  iVar1 = segment(0x2f);
  iVar4 = segment(0x2f);
  *(uint *)(iVar4 + -0x1fffeff8) = *(uint *)(iVar1 + -0x1fffeff8) | 0x80100000;
  return;
}
/* GHIDRADEC_FUNCTION index=2220 start=0xf0097394 */

void _p4m35_sys_setfunc(void)

{
  _v_get_sysctl = _p4m35_get_sysctl;
  _v_set_sysctl = _p4m35_set_sysctl;
  _v_get_diagmesg = _p4m35_stub;
  _v_set_diagmesg = _p4m35_stub;
  _v_set_diagled = _p4m35_stub;
  _v_enable_dvma = _p4m35_enable_dvma;
  _v_disable_dvma = _p4m35_disable_dvma;
  _v_l15_async_fault = _p4m35_l15_async_fault;
  _v_memerr_init = _p4m35_memerr_init;
  _v_memerr_disable = _p4m35_memerr_disable;
  _v_ebe_handler = _p4m35_ebe_handler;
  _v_flush_writebuffers = _p4m35_stub;
  _v_flush_poke_writebuffers = _p4m35_stub;
  _v_init_all_fsr = _p4m35_init_all_fsr;
  return;
}
/* GHIDRADEC_FUNCTION index=2221 start=0xf009742c */

undefined4 _p4m35_get_sysctl(void)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  return *(undefined4 *)(iVar1 + 0x79f00000);
}
/* GHIDRADEC_FUNCTION index=2222 start=0xf0097438 */

void _p4m35_set_sysctl(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  *(undefined4 *)(iVar1 + 0x79f00000) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2223 start=0xf0097444 */

void _p4m35_enable_dvma(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x20);
  iVar2 = segment(0x20);
  *(uint *)(iVar2 + 0x10002000) = *(uint *)(iVar1 + 0x10002000) | 0x1f0000;
  return;
}
/* GHIDRADEC_FUNCTION index=2224 start=0xf009745c */

void _p4m35_disable_dvma(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x20);
  iVar2 = segment(0x20);
  *(uint *)(iVar2 + 0x10002000) = *(uint *)(iVar1 + 0x10002000) & 0xffe0ffff;
  return;
}
/* GHIDRADEC_FUNCTION index=2225 start=0xf0097474 */

void _p4m35_memerr_init_asm(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 | 0x1000;
  return;
}
/* GHIDRADEC_FUNCTION index=2226 start=0xf009748c */

void _p4m35_memerr_disable_asm(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & 0xffffefff;
  return;
}
/* GHIDRADEC_FUNCTION index=2227 start=0xf00974a4 */

void _p4m35_init_all_fsr(void)

{
  int iVar1;
  int iVar2;
  
  segment(0x20);
  segment(0x20);
  iVar1 = segment(0x20);
  iVar2 = segment(0x20);
  *(uint *)(iVar2 + 0x10002000) = *(uint *)(iVar1 + 0x10002000) | 0x80000;
  return;
}
/* GHIDRADEC_FUNCTION index=2228 start=0xf00974d4 */

undefined4 _p4m35_stub(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2229 start=0xf00974dc */

undefined4 _get_efsr_vaddr(void)

{
  return uRamfefef008;
}
/* GHIDRADEC_FUNCTION index=2230 start=0xf00974e8 */

undefined4 _get_efar0_vaddr(void)

{
  return uRamfefef010;
}
/* GHIDRADEC_FUNCTION index=2231 start=0xf00974f4 */

undefined4 _get_efar1_vaddr(void)

{
  return uRamfefef014;
}
/* GHIDRADEC_FUNCTION index=2232 start=0xf0097500 */

void _SMbuf_syncmode(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x2f);
  iVar2 = segment(0x2f);
  *(uint *)(iVar2 + -0x1fffeff8) = *(uint *)(iVar1 + -0x1fffeff8) & 0x7fffffff;
  return;
}
/* GHIDRADEC_FUNCTION index=2233 start=0xf009751c */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void window_underflow(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  qword in_l0_1;
  undefined8 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  int iVar12;
  undefined8 uVar13;
  undefined8 in_i0_1;
  undefined8 uVar14;
  undefined8 in_i2_3;
  undefined8 uVar15;
  undefined8 in_i4_5;
  undefined8 uVar16;
  qword in_fp_7;
  undefined8 uVar17;
  qword qVar18;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar19;
  
  iVar12 = __nwindows + -1;
  uVar7 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  uVar9 = uVar7 << 1;
  *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008
           + (uint)(in_TL == 4) * 0x600c) = uVar7 >> ((byte)iVar12 & 0x1f) | uVar9;
  qVar18 = in_l0_1 & 0x4000000000;
  iVar19 = in_CWP + -1;
  if (!(bool)in_DECOMPILE_MODE) {
    in_i0_1 = CONCAT44(*(undefined4 *)(iVar19 * 0x40 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000));
    in_i2_3 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000));
    in_i4_5 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000));
    in_fp_7 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 6) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000));
    in_l0_1 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 8) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 9) * 4 + 0x8000));
    uVar7 = *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000);
    uVar9 = *(uint *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000);
    iVar12 = *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000);
  }
  uVar2 = (undefined4)in_i0_1;
  uVar1 = (undefined4)((qword)in_i0_1 >> 0x20);
  uVar3 = (undefined4)((qword)in_i2_3 >> 0x20);
  uVar4 = (undefined4)((qword)in_i4_5 >> 0x20);
  puVar5 = (undefined8 *)(in_fp_7 >> 0x20);
  if (qVar18 != 0) {
    iVar12 = in_CWP + -2;
    uVar6 = *puVar5;
    uVar8 = (undefined4)puVar5[1];
    uVar11 = puVar5[2];
    uVar13 = puVar5[3];
    uVar14 = puVar5[4];
    uVar15 = puVar5[5];
    uVar16 = puVar5[6];
    uVar17 = puVar5[7];
    if (!(bool)in_DECOMPILE_MODE) {
      *(int *)(iVar12 * 0x40 + 0x8000) = (int)((qword)uVar14 >> 0x20);
      *(int *)((iVar12 * 0x10 + 1) * 4 + 0x8000) = (int)uVar14;
      *(int *)((iVar12 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uVar15 >> 0x20);
      *(int *)((iVar12 * 0x10 + 3) * 4 + 0x8000) = (int)uVar15;
      *(int *)((iVar12 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uVar16 >> 0x20);
      *(int *)((iVar12 * 0x10 + 5) * 4 + 0x8000) = (int)uVar16;
      *(int *)((iVar12 * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uVar17 >> 0x20);
      *(int *)((iVar12 * 0x10 + 7) * 4 + 0x8000) = (int)uVar17;
      *(int *)((iVar12 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
      *(int *)((iVar12 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
      *(undefined4 *)((iVar12 * 0x10 + 10) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar12 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
      *(int *)((iVar12 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
      *(int *)((iVar12 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
    }
    uVar6 = 0;
    uVar8 = 0;
    uVar11 = 0;
    uVar13 = 0;
    iVar12 = iVar12 + 1;
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar12 * 0x40 + 0x8000) = uVar1;
      *(undefined4 *)((iVar12 * 0x10 + 1) * 4 + 0x8000) = uVar2;
      *(undefined4 *)((iVar12 * 0x10 + 2) * 4 + 0x8000) = uVar3;
      *(undefined4 *)((iVar12 * 0x10 + 3) * 4 + 0x8000) = 0;
      *(undefined4 *)((iVar12 * 0x10 + 4) * 4 + 0x8000) = uVar4;
      *(undefined4 *)((iVar12 * 0x10 + 5) * 4 + 0x8000) = 0;
      *(undefined8 **)((iVar12 * 0x10 + 6) * 4 + 0x8000) = puVar5;
      *(undefined4 *)((iVar12 * 0x10 + 7) * 4 + 0x8000) = 0;
      *(int *)((iVar12 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
      *(int *)((iVar12 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
      *(undefined4 *)((iVar12 * 0x10 + 10) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar12 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
      *(int *)((iVar12 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
      *(int *)((iVar12 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
    }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  iVar19 = in_CWP + -2;
  qVar18 = in_fp_7;
  if (!(bool)in_DECOMPILE_MODE) {
    in_i0_1 = CONCAT44(*(undefined4 *)(iVar19 * 0x40 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000));
    in_i2_3 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000));
    in_i4_5 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000));
    qVar18 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 6) * 4 + 0x8000),
                      *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000));
    in_l0_1 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 8) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 9) * 4 + 0x8000));
    uVar7 = *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000);
    uVar9 = *(uint *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000);
    iVar12 = *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000);
  }
  uVar8 = (undefined4)((qword)in_i0_1 >> 0x20);
  if ((in_fp_7 & 0x700000000) != 0) {
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar8;
      *(int *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
      *(int *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)in_i2_3 >> 0x20);
      *(int *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = (int)in_i2_3;
      *(int *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)in_i4_5 >> 0x20);
      *(int *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = (int)in_i4_5;
      *(int *)((iVar19 * 0x10 + 6) * 4 + 0x8000) = (int)(qVar18 >> 0x20);
      *(int *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = (int)qVar18;
      *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)(in_l0_1 >> 0x20);
      *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
      *(uint *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar7;
      *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar7;
      *(uint *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = uVar9;
      *(undefined4 *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = 0;
      *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = iVar12;
      *(undefined4 *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = 0;
    }
    uVar6 = 0;
    uVar8 = 0;
    uVar11 = 0;
    uVar13 = 0;
    iVar19 = iVar19 + 1;
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar1;
      *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = uVar2;
      *(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = uVar3;
      *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = 0;
      *(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = uVar4;
      *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = 0;
      *(undefined8 **)((iVar19 * 0x10 + 6) * 4 + 0x8000) = puVar5;
      *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = 0;
      *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
      *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
      *(undefined4 *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
      *(int *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
      *(int *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
      *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
      *(int *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
    }
    *(undefined4 *)
     ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
     (uint)(in_TL == 4) * 0x600c) = 0;
    sys_trap();
    return;
  }
  uVar10 = 0xf0000000;
  if (puVar5 < &dword_F0000000) {
                    /* WARNING: Could not recover jumptable at 0xf00975c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_mmu_wu)();
    return;
  }
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar8;
    *(int *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
    *(int *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)in_i2_3 >> 0x20);
    *(int *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = (int)in_i2_3;
    *(int *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)in_i4_5 >> 0x20);
    *(int *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = (int)in_i4_5;
    *(int *)((iVar19 * 0x10 + 6) * 4 + 0x8000) = (int)(qVar18 >> 0x20);
    *(int *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = (int)qVar18;
    *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)(in_l0_1 >> 0x20);
    *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
    *(uint *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar7;
    *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = uVar10;
    *(undefined4 *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = 0;
    *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = iVar12;
    *(undefined4 *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = 0;
  }
  uVar6 = 0;
  uVar8 = 0;
  uVar11 = 0;
  uVar13 = 0;
  iVar19 = iVar19 + 1;
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar1;
    *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = uVar2;
    *(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = uVar3;
    *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = 0;
    *(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = 0;
    *(undefined8 **)((iVar19 * 0x10 + 6) * 4 + 0x8000) = puVar5;
    *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = 0;
    *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
    *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
    *(undefined4 *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
    *(int *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
    *(int *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
    *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
    *(int *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
  }
  func_0xf00975f0();
  return;
}
/* GHIDRADEC_FUNCTION index=2234 start=0xf00975e4 */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf0097678) */

void wu_chk_flt(void)

{
  undefined4 unaff_g1;
  undefined8 in_g2_3;
  undefined4 unaff_g4;
  byte bVar1;
  undefined4 unaff_g5;
  undefined8 in_g6_7;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint unaff_l4;
  undefined4 unaff_l5;
  undefined (*pauVar3) [676];
  undefined4 uVar4;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 uVar6;
  undefined4 unaff_i2;
  undefined4 uVar7;
  undefined4 unaff_i3;
  undefined4 uVar8;
  undefined4 unaff_i4;
  undefined4 uVar9;
  undefined4 unaff_i5;
  undefined4 uVar10;
  undefined *unaff_fp;
  undefined *puVar11;
  undefined4 unaff_i7;
  undefined4 uVar12;
  undefined4 in_Y;
  bool in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar13;
  
  pauVar3 = _active_pcb;
  if ((unaff_l4 & 2) != 0) {
    uVar4 = *(undefined4 *)(*_active_pcb + 0x2a0);
    *(undefined4 *)(*_active_pcb + 0x244) = unaff_g1;
    *(undefined8 *)(*pauVar3 + 0x248) = in_g2_3;
    *(qword *)(*pauVar3 + 0x250) = CONCAT44(unaff_g4,unaff_g5);
    *(undefined8 *)(*pauVar3 + 600) = in_g6_7;
    *(undefined4 *)(*pauVar3 + 0x240) = in_Y;
    iVar13 = in_CWP + -1;
    uVar5 = unaff_i0;
    uVar6 = unaff_i1;
    uVar7 = unaff_i2;
    uVar8 = unaff_i3;
    uVar9 = unaff_i4;
    uVar10 = unaff_i5;
    puVar11 = unaff_fp;
    uVar12 = unaff_i7;
    if (!in_DECOMPILE_MODE) {
      uVar5 = *(undefined4 *)(iVar13 * 0x40 + 0x8000);
      uVar6 = *(undefined4 *)((iVar13 * 0x10 + 1) * 4 + 0x8000);
      uVar7 = *(undefined4 *)((iVar13 * 0x10 + 2) * 4 + 0x8000);
      uVar8 = *(undefined4 *)((iVar13 * 0x10 + 3) * 4 + 0x8000);
      uVar9 = *(undefined4 *)((iVar13 * 0x10 + 4) * 4 + 0x8000);
      uVar10 = *(undefined4 *)((iVar13 * 0x10 + 5) * 4 + 0x8000);
      puVar11 = *(undefined **)((iVar13 * 0x10 + 6) * 4 + 0x8000);
      uVar12 = *(undefined4 *)((iVar13 * 0x10 + 7) * 4 + 0x8000);
      unaff_l0 = *(undefined4 *)((iVar13 * 0x10 + 8) * 4 + 0x8000);
      unaff_l1 = *(undefined4 *)((iVar13 * 0x10 + 9) * 4 + 0x8000);
      unaff_l3 = *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000);
      unaff_l4 = *(uint *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000);
      unaff_l5 = *(undefined4 *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000);
      pauVar3 = *(undefined (**) [676])((iVar13 * 0x10 + 0xe) * 4 + 0x8000);
      uVar4 = *(undefined4 *)((iVar13 * 0x10 + 0xe) * 4 + 0x8000);
    }
    bVar1 = (byte)*(undefined4 *)
                   ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c);
    if (!in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar13 * 0x40 + 0x8000) = uVar5;
      *(undefined4 *)((iVar13 * 0x10 + 1) * 4 + 0x8000) = uVar6;
      *(undefined4 *)((iVar13 * 0x10 + 2) * 4 + 0x8000) = uVar7;
      *(undefined4 *)((iVar13 * 0x10 + 3) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar13 * 0x10 + 4) * 4 + 0x8000) = uVar9;
      *(undefined4 *)((iVar13 * 0x10 + 5) * 4 + 0x8000) = uVar10;
      *(undefined **)((iVar13 * 0x10 + 6) * 4 + 0x8000) = puVar11;
      *(undefined4 *)((iVar13 * 0x10 + 7) * 4 + 0x8000) = uVar12;
      *(undefined4 *)((iVar13 * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
      *(undefined4 *)((iVar13 * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
      *(undefined4 *)((iVar13 * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
      *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
      *(uint *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
      *(undefined4 *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
      *(undefined (**) [676])((iVar13 * 0x10 + 0xe) * 4 + 0x8000) = pauVar3;
      *(undefined4 *)((iVar13 * 0x10 + 0xf) * 4 + 0x8000) = uVar4;
    }
    uVar5 = 0;
    uVar6 = 0;
    uVar7 = 0;
    iVar13 = 0;
    puVar2 = (undefined *)0x0;
    uRam00000260 = CONCAT44(unaff_i0,unaff_i1);
    uRam00000268 = CONCAT44(unaff_i2,unaff_i3);
    uRam00000270 = CONCAT44(unaff_i4,unaff_i5);
    uRam00000278 = CONCAT44(unaff_fp,unaff_i7);
    uRam00000234 = 0;
    uRam00000238 = 0;
    uRam0000023c = 0;
    *(undefined4 *)
     ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
     (uint)(in_TL == 4) * 0x600c) = 0;
    *(int *)(iVar13 + 0xc) = 1 << (bVar1 & 0x1f);
    *(undefined4 *)(iVar13 + 0x230) = 0;
    _trap(9,iVar13 + 0x234,uVar7,uVar6,2);
    *(undefined4 *)(puVar2 + 0x5c) = uVar5;
    sys_rtt();
    return;
  }
  if ((*(uint *)(*_active_pcb + 0x294) & 1) == 0) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=2235 start=0xf00976e4 */

qword _checksum_16(word *param_1,int param_2)

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
  uVar1 = 0;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = uVar1 + *param_1;
    param_1 = param_1 + 1;
  }
  uVar1 = (uVar1 >> 0x10) + (uVar1 & 0xffff);
  if (0xffff < uVar1) {
    uVar1 = uVar1 - 0xffff;
  }
  return CONCAT44(0xffffffff,uVar1) & 0xffffffff0000ffff;
}
/* GHIDRADEC_FUNCTION index=2236 start=0xf0097744 */

/* WARNING: Removing unreachable block (ram,0xf00977a0) */
/* WARNING: Removing unreachable block (ram,0xf00977dc) */
/* WARNING: Removing unreachable block (ram,0xf0097794) */

undefined8 _sparc_hardclock(undefined4 param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
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
  puVar2 = (undefined8 *)0x2710;
  qword_F0131478 =
       CONCAT44((int)((qword)qword_F0131478 >> 0x20) + (uint)(0xffffd8ef < (uint)qword_F0131478),
                (uint)qword_F0131478 + 10000);
  if (dword_F0131494 != 0) {
    _clock_interrupt(_tick,((uint)param_2 >> 6 ^ 1) & 1);
    puVar2 = param_2;
    _hardclock(param_1);
  }
  if (dword_F0131490 != (code *)0x0) {
    param_2 = &qword_F0131488;
    if ((qword_F0131488._0_4_ != 0) || (qword_F0131488._4_4_ != (undefined8 *)0x0)) {
      uVar1 = 1;
      _clock_value();
      if ((qword_F0131488._0_4_ <= uVar1) &&
         ((qword_F0131488._0_4_ != uVar1 || (qword_F0131488._4_4_ <= puVar2)))) {
        qword_F0131488 = 0;
        (*dword_F0131490)(0,0,0);
      }
    }
  }
  return CONCAT44(param_2,DAT_f0131400);
}
/* GHIDRADEC_FUNCTION index=2237 start=0xf009783c */

undefined8 _hardclock_init(undefined4 param_1,undefined4 param_2)

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
  dword_F0131494 = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2238 start=0xf0097854 */

undefined8 _statclock_init(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=2239 start=0xf0097860 */

/* WARNING: Removing unreachable block (ram,0xf0097864) */

undefined8 _us_spin(undefined4 param_1,undefined4 param_2)

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
  _usec_delay(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2240 start=0xf0097874 */

/* WARNING: Removing unreachable block (ram,0xf0097878) */

undefined8 _us_spin_calibrate(undefined4 param_1,undefined4 param_2)

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
  _setcpudelay();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2241 start=0xf0097888 */
//Error decompiling function: _clock_timer_init @ 0xf0097888
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=2242 start=0xf0097908 */

/* WARNING: Removing unreachable block (ram,0xf009790c) */

undefined8 _clock_value(int param_1)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
  undefined8 uVar4;
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
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  sub_F0097AB4((undefined *)((int)register0x00000038 + -0x10));
  uVar3 = (uint)*(undefined8 *)((int)register0x00000038 + -0x10);
  iVar1 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
  uVar2 = uVar3 * 0x7d >> 0x1d |
          ((uVar3 * 0x1f >> 0x1e |
           (((uVar3 >> 0x1b | iVar1 << 5) - iVar1) - (uint)(uVar3 * 0x20 < uVar3)) * 4) + iVar1 +
          (uint)CARRY4(uVar3 * 0x7c,uVar3)) * 8;
  uVar3 = uVar3 * 1000;
  *(qword *)((int)register0x00000038 + -0x10) = CONCAT44(uVar2,uVar3);
  if (param_1 == 0) {
    uVar4 = CONCAT44(uVar2 + (int)((qword)qword_F0131468 >> 0x20) +
                     (uint)CARRY4(uVar3,(uint)qword_F0131468),uVar3 + (uint)qword_F0131468);
    *(undefined8 *)((int)register0x00000038 + -0x10) = uVar4;
  }
  else if (param_1 == 1) {
    uVar4 = CONCAT44(uVar2,uVar3);
  }
  else {
    uVar4 = 0;
  }
  return CONCAT44((int)uVar4,(int)((qword)uVar4 >> 0x20));
}
/* GHIDRADEC_FUNCTION index=2243 start=0xf00979a4 */

/* WARNING: Removing unreachable block (ram,0xf00979f0) */
/* WARNING: Removing unreachable block (ram,0xf00979c8) */
/* WARNING: Removing unreachable block (ram,0xf00979e0) */
/* WARNING: Removing unreachable block (ram,0xf00979f8) */
/* WARNING: Removing unreachable block (ram,0xf00979bc) */

undefined8 _set_clock(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
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
  if (param_1 == 0) {
    iVar1 = param_1;
    uVar3 = param_2;
    _splusclock();
    iVar2 = 1;
    _clock_value();
    qword_F0131468 = CONCAT44((param_2 - iVar2) - (uint)(param_3 < uVar3),param_3 - uVar3);
    _splx(iVar1);
    _ns_time_to_timeval(param_2,param_3,(undefined *)((int)register0x00000038 + -0x10));
    _set_tod(*(undefined4 *)((int)register0x00000038 + -0x10));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2244 start=0xf0097a08 */

undefined8 _clock_attributes(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar1;
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
  if (param_1 == 0) {
    puVar1 = unk_F00F4FD8;
  }
  else if (param_1 == 1) {
    puVar1 = unk_F00F4FC8;
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2245 start=0xf0097a3c */

undefined8 _timer_attributes(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar1;
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
  puVar1 = (undefined *)0x0;
  if (param_1 == 0) {
    puVar1 = unk_F00F4FE8;
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2246 start=0xf0097a5c */

undefined8 _set_timer_expire_func(undefined4 param_1,int param_2)

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
  if (dword_F0131490 == 0) {
    dword_F0131490 = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2247 start=0xf0097a7c */

/* WARNING: Removing unreachable block (ram,0xf0097a94) */

undefined8 _set_timer(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
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
  if (param_1 == 0) {
    iVar1 = 1;
    uVar2 = param_2;
    _clock_value();
    qword_F0131488 = CONCAT44(iVar1 + param_2 + (uint)CARRY4(uVar2,param_3),uVar2 + param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2248 start=0xf0097b64 */

/* WARNING: Removing unreachable block (ram,0xf0097c04) */
/* WARNING: Removing unreachable block (ram,0xf0097b68) */

undefined8 _event_set_ts(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
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
  puVar2 = param_1;
  _splusclock();
  if ((int)uRamfeffd004 < 0) {
    uVar3 = 1;
    uVar5 = CONCAT44((int)((qword)qword_F0131478 >> 0x20) +
                     (uint)(0xffffd8ef < (uint)qword_F0131478),(uint)qword_F0131478 + 10000);
  }
  else {
    uVar3 = uRamfeffd004 >> 10;
    uVar5 = qword_F0131478;
  }
  uVar1 = (uint)uVar5 + uVar3;
  iVar4 = (int)((qword)uVar5 >> 0x20) + (uint)CARRY4((uint)uVar5,uVar3);
  uVar5 = CONCAT44(iVar4,uVar1);
  if ((DAT_f0131480._0_4_ == iVar4) && (DAT_f0131480._4_4_ == uVar1)) {
    uVar5 = CONCAT44(iVar4 + (uint)(0xfffffffe < uVar1),uVar1 + 1);
  }
  *(undefined8 *)((int)register0x00000038 + -0x10) = uVar5;
  DAT_f0131480 = uVar5;
  _splx(puVar2);
  uVar5 = *(undefined8 *)((int)register0x00000038 + -0x10);
  param_1[1] = (int)((qword)uVar5 >> 0x20);
  *param_1 = (int)uVar5;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2249 start=0xf0097c28 */

/* WARNING: Removing unreachable block (ram,0xf0097cc8) */
/* WARNING: Removing unreachable block (ram,0xf0097c2c) */

undefined8 _event_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
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
  bool bVar5;
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
  _splusclock();
  if ((int)uRamfeffd004 < 0) {
    uVar2 = 1;
    uVar4 = CONCAT44((int)((qword)qword_F0131478 >> 0x20) +
                     (uint)(0xffffd8ef < (uint)qword_F0131478),(uint)qword_F0131478 + 10000);
  }
  else {
    uVar2 = uRamfeffd004 >> 10;
    uVar4 = qword_F0131478;
  }
  uVar3 = (uint)uVar4 + uVar2;
  iVar1 = (int)((qword)uVar4 >> 0x20) + (uint)CARRY4((uint)uVar4,uVar2);
  if ((DAT_f0131480._0_4_ == iVar1) && (DAT_f0131480._4_4_ == uVar3)) {
    bVar5 = 0xfffffffe < uVar3;
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + (uint)bVar5;
  }
  DAT_f0131480 = CONCAT44(iVar1,uVar3);
  *(qword *)((int)register0x00000038 + -0x10) = CONCAT44(iVar1,uVar3);
  _splx(param_1);
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}

