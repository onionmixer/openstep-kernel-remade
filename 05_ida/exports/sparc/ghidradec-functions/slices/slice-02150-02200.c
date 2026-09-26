/* GHIDRADEC_FUNCTION index=2150 start=0xf0096c94 */

void _splnet(void)

{
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) < 0x100) {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2151 start=0xf0096cc4 */

undefined4 _splsoftclock(void)

{
  int in_TL;
  
  return *(undefined4 *)
          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008 +
          (uint)(in_TL == 4) * 0x700c);
}
/* GHIDRADEC_FUNCTION index=2152 start=0xf0096ce0 */

undefined4 _spl0(void)

{
  int in_TL;
  
  return *(undefined4 *)
          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008 +
          (uint)(in_TL == 4) * 0x700c);
}
/* GHIDRADEC_FUNCTION index=2153 start=0xf0096cfc */

undefined4 _splvm(void)

{
  return _splvm_val;
}
/* GHIDRADEC_FUNCTION index=2154 start=0xf0096d04 */

uint _splr(uint param_1)

{
  uint uVar1;
  int in_TL;
  
  uVar1 = *(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00;
  if ((param_1 & 0xf00) <= uVar1) {
    return uVar1;
  }
  return param_1 & 0xf00;
}
/* GHIDRADEC_FUNCTION index=2155 start=0xf0096d24 */

uint _splx(void)

{
  int in_TL;
  
  return *(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                   (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00;
}
/* GHIDRADEC_FUNCTION index=2156 start=0xf0096d44 */

uint _curipl(void)

{
  int in_TL;
  
  return (*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00) >> 8;
}
/* GHIDRADEC_FUNCTION index=2157 start=0xf0096d54 */

undefined4 _setjmp(undefined4 *param_1)

{
  undefined4 in_o7;
  undefined auStackX_0 [92];
  
  *param_1 = in_o7;
  param_1[1] = register0x00000038;
  return 0;
}
/* GHIDRADEC_FUNCTION index=2158 start=0xf0096d64 */

/* WARNING: Removing unreachable block (ram,0xf0096d68) */

undefined8 _longjmp(undefined4 param_1,undefined4 param_2)

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
  _flush_windows();
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=2159 start=0xf0096d80 */

void _usec_delay(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = _Cpudelay == 0;
  iVar3 = _Cpudelay;
  do {
    do {
      bVar2 = !bVar4;
      bVar4 = iVar3 + -1 == 0;
      iVar3 = iVar3 + -1;
    } while (bVar2);
    iVar1 = param_1 + -1;
    bVar2 = 0 < param_1;
    bVar4 = _Cpudelay == 0;
    param_1 = iVar1;
    iVar3 = _Cpudelay;
  } while (iVar1 != 0 && bVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=2160 start=0xf0096da8 */

int _movtuc(int param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1) {
    bVar1 = *param_2;
    while( true ) {
      cVar2 = *(char *)(param_4 + (uint)bVar1);
      *(char *)(param_3 + iVar3) = cVar2;
      if (cVar2 == '\0') {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      if (param_1 <= iVar3) break;
      bVar1 = param_2[iVar3];
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2161 start=0xf0096de8 */

void _caller(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2162 start=0xf0096df0 */

void _callee(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2163 start=0xf0096df8 */

void _getvbr(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2164 start=0xf0096e00 */

undefined4 _getpsr(void)

{
  int in_TL;
  
  return *(undefined4 *)
          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008 +
          (uint)(in_TL == 4) * 0x700c);
}
/* GHIDRADEC_FUNCTION index=2165 start=0xf0096e08 */

void _getsp(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2166 start=0xf0096e10 */

void __insque(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  param_1[1] = (int)param_2;
  *param_1 = iVar1;
  *param_2 = (int)param_1;
  *(int **)(iVar1 + 4) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2167 start=0xf0096e28 */

void __remque(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = (int *)param_1[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=2168 start=0xf0096e3c */

bool _servicing_interrupt(void)

{
  undefined auStackX_0 [92];
  
  return auStackX_0 < DAT_f0106001;
}
/* GHIDRADEC_FUNCTION index=2169 start=0xf0096e5c */

void _siron(void)

{
  _set_intreg(0x20000,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2170 start=0xf0096e68 */

undefined _ldstub(undefined *param_1)

{
  undefined uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0xff;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2171 start=0xf0096e74 */

undefined4 _swapl(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = param_1;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2172 start=0xf0096e80 */

void _tas(undefined4 param_1)

{
  _swapl(0xffffffff,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2173 start=0xf0096e8c */

void _tac(undefined4 param_1)

{
  _swapl(0,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2174 start=0xf0096e98 */

void _stackpointer(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2175 start=0xf0096ea0 */

void _framepointer(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2176 start=0xf0096ea8 */

bool _simple_lock_try(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  *param_1 = -1;
  return cVar1 == '\0';
}
/* GHIDRADEC_FUNCTION index=2177 start=0xf0096ec4 */

void _getidprom(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x20;
  do {
    iVar1 = iVar2 + -1;
    *(undefined *)(param_1 + iVar1) = *(undefined *)(iVar2 + -0x1000029);
    iVar2 = iVar1;
  } while (iVar1 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2178 start=0xf0096ee8 */

void _set_intmask(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0xfeff8008;
  if (param_2 != 0) {
    puVar1 = (undefined4 *)0xfeff800c;
  }
  *puVar1 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2179 start=0xf0096f04 */

void _set_intreg(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0xfeff4004;
  if (param_2 != 0) {
    puVar1 = (undefined4 *)0xfeff4008;
  }
  *puVar1 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2180 start=0xf0096f30 */

void _take_interrupt_target(void)

{
  uRamfeff8010 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2181 start=0xf0096f40 */

undefined4 _getprocessorid(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2182 start=0xf0096f4c */

void _chk_cpuid(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2183 start=0xf0096f58 */

undefined4 _ldphys(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (_cache == 3) {
    puVar2 = (uint *)segment(4);
    uVar4 = *puVar2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4 | 0x8000;
    iVar1 = segment(0x20);
    uVar3 = *(undefined4 *)(param_1 + iVar1);
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4;
  }
  else {
    iVar1 = segment(0x20);
    uVar3 = *(undefined4 *)(param_1 + iVar1);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2184 start=0xf0096fb4 */

void _stphys(int param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  if (_cache == 3) {
    puVar2 = (uint *)segment(4);
    uVar3 = *puVar2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar3 | 0x8000;
    iVar1 = segment(0x20);
    *(undefined4 *)(param_1 + iVar1) = param_2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar3;
  }
  else {
    iVar1 = segment(0x20);
    *(undefined4 *)(param_1 + iVar1) = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2185 start=0xf0097010 */

undefined4 _swphys(undefined4 param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_i0;
  int unaff_i1;
  
  if (_cache == 3) {
    puVar2 = (uint *)segment(4);
    uVar4 = *puVar2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4 | 0x8000;
    iVar1 = segment(0x20);
    uVar3 = *(undefined4 *)(param_2 + iVar1);
    *(undefined4 *)(param_2 + iVar1) = param_1;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4;
  }
  else {
    iVar1 = segment(0x20);
    *(undefined4 *)(unaff_i1 + iVar1) = unaff_i0;
    uVar3 = param_1;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2186 start=0xf009706c */

void _iommu_set_ctl(undefined4 param_1)

{
  uRamfefe0000 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2187 start=0xf0097078 */

void _iommu_set_base(undefined4 param_1)

{
  uRamfefe0004 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2188 start=0xf0097088 */

void _iommu_flush_all(void)

{
  uRamfefe0014 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2189 start=0xf0097098 */

void _iommu_addr_flush(undefined4 param_1)

{
  uRamfefe0018 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2190 start=0xf00970a8 */

undefined4 _get_sfsr(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(undefined4 *)(iVar1 + 0x300);
}
/* GHIDRADEC_FUNCTION index=2191 start=0xf00970b4 */

void _get_sysctl(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00970bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_get_sysctl)();
  return;
}
/* GHIDRADEC_FUNCTION index=2192 start=0xf00970c4 */

void _set_sysctl(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00970cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_set_sysctl)();
  return;
}
/* GHIDRADEC_FUNCTION index=2193 start=0xf00970d4 */

void _set_diagled(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00970dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_set_diagled)();
  return;
}
/* GHIDRADEC_FUNCTION index=2194 start=0xf00970e4 */

void _get_diagmesg(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00970ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_get_diagmesg)();
  return;
}
/* GHIDRADEC_FUNCTION index=2195 start=0xf00970f4 */

void _set_diagmesg(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00970fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_get_diagmesg)();
  return;
}
/* GHIDRADEC_FUNCTION index=2196 start=0xf0097104 */

void _enable_dvma(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009710c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_enable_dvma)();
  return;
}
/* GHIDRADEC_FUNCTION index=2197 start=0xf0097114 */

void _disable_dvma(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009711c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_disable_dvma)();
  return;
}
/* GHIDRADEC_FUNCTION index=2198 start=0xf0097124 */

void _l15_async_fault(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009712c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_l15_async_fault)();
  return;
}
/* GHIDRADEC_FUNCTION index=2199 start=0xf0097134 */

void _ebe_handler(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009713c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_ebe_handler)();
  return;
}

