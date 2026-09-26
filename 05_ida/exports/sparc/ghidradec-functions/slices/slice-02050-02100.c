/* GHIDRADEC_FUNCTION index=2050 start=0xf009564c */

void _mmu_flushall(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095654. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushall)();
  return;
}
/* GHIDRADEC_FUNCTION index=2051 start=0xf009565c */

void _mmu_flushctx(int param_1)

{
  if ((*(uint *)(_contexts + param_1 * 4) & 3) != 1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0xf0095690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushctx)(param_1,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2052 start=0xf0095698 */

void _mmu_flushrgn(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushrgn)(param_1 & 0xff000000);
  return;
}
/* GHIDRADEC_FUNCTION index=2053 start=0xf00956b0 */

void _mmu_flushseg(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushseg)(param_1 & 0xfffc0000);
  return;
}
/* GHIDRADEC_FUNCTION index=2054 start=0xf00956c8 */

void _mmu_flushpage(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushpage)(param_1 & 0xfffff000);
  return;
}
/* GHIDRADEC_FUNCTION index=2055 start=0xf00956e0 */

void _mmu_flushpagectx(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushpagectx)(param_1 & 0xfffff000);
  return;
}
/* GHIDRADEC_FUNCTION index=2056 start=0xf00956f8 */

void _mmu_getsyncflt(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_getsyncflt)();
  return;
}
/* GHIDRADEC_FUNCTION index=2057 start=0xf0095708 */

void _mmu_getasyncflt(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_getasyncflt)();
  return;
}
/* GHIDRADEC_FUNCTION index=2058 start=0xf0095718 */

void _mmu_chk_wdreset(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_chk_wdreset)();
  return;
}
/* GHIDRADEC_FUNCTION index=2059 start=0xf0095728 */

void _mmu_log_module_err(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_log_module_err)();
  return;
}
/* GHIDRADEC_FUNCTION index=2060 start=0xf0095738 */

void _mmu_print_sfsr(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_print_sfsr)();
  return;
}
/* GHIDRADEC_FUNCTION index=2061 start=0xf0095748 */

void _mmu_sys_ovf(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_sys_ovf)();
  return;
}
/* GHIDRADEC_FUNCTION index=2062 start=0xf0095758 */

void _mmu_sys_unf(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_sys_unf)();
  return;
}
/* GHIDRADEC_FUNCTION index=2063 start=0xf0095768 */

void _mmu_wo(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_wo)();
  return;
}
/* GHIDRADEC_FUNCTION index=2064 start=0xf0095778 */

void _mmu_wu(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_wu)();
  return;
}
/* GHIDRADEC_FUNCTION index=2065 start=0xf0095788 */

void _mmu_writepte(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_writepte)();
  return;
}
/* GHIDRADEC_FUNCTION index=2066 start=0xf0095798 */

void _mmu_writeptp(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00957a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_writeptp)();
  return;
}
/* GHIDRADEC_FUNCTION index=2067 start=0xf00957a8 */

void _module_wkaround(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00957b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_module_wkaround)();
  return;
}
/* GHIDRADEC_FUNCTION index=2068 start=0xf00957b8 */

void _vac_noop(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2069 start=0xf00957c0 */

undefined4 _vac_inoop(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2070 start=0xf00957c8 */

void _vac_init(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00957d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_vac_init)();
  return;
}
/* GHIDRADEC_FUNCTION index=2071 start=0xf00957d8 */

void _cache_sync(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00957e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_cache_sync)();
  return;
}
/* GHIDRADEC_FUNCTION index=2072 start=0xf00957e8 */

void _vac_flushall(void)

{
  if (_vac != 0) {
                    /* WARNING: Could not recover jumptable at 0xf0095804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_flushall)();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2073 start=0xf009580c */

void _vac_usrflush(void)

{
  if (_vac != 0) {
    DAT_f0134070._0_4_ = DAT_f0134070._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009583c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_usrflush)();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2074 start=0xf0095844 */

void _vac_ctxflush(int param_1)

{
  if ((_vac != 0) && ((*(uint *)(_contexts + param_1 * 4) & 3) == 1)) {
    _flush_cnt._0_4_ = _flush_cnt._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009589c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_ctxflush)(param_1,1,param_1);
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2075 start=0xf00958a4 */

void _vac_rgnflush(uint param_1,undefined4 param_2)

{
  if (_vac != 0) {
    DAT_f0134074._0_4_ = DAT_f0134074._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf00958e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_rgnflush)(param_1 & 0xff000000,param_2,param_2);
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2076 start=0xf00958e8 */

void _vac_segflush(undefined4 param_1,undefined4 param_2)

{
  if (_vac != 0) {
    DAT_f0134064._0_4_ = DAT_f0134064._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009591c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_segflush)(param_1,param_2,param_2);
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2077 start=0xf0095924 */

void _vac_pageflush(uint param_1)

{
  if (_vac != 0) {
    DAT_f0134068._0_4_ = DAT_f0134068._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009595c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_pageflush)(param_1 & 0xfffff000);
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2078 start=0xf0095964 */

void _vac_pagectxflush(uint param_1,undefined4 param_2)

{
  if (_vac != 0) {
    DAT_f0134068._0_4_ = DAT_f0134068._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf00959a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_pagectxflush)(param_1 & 0xfffff000,param_2,param_2);
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2079 start=0xf00959a8 */

void _vac_flush(void)

{
  if (_vac != 0) {
    DAT_f013406c._0_4_ = DAT_f013406c._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf00959d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_flush)();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2080 start=0xf00959e0 */

void _cache_on(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00959e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_cache_on)();
  return;
}
/* GHIDRADEC_FUNCTION index=2081 start=0xf00959f0 */

void _vac_parity_chk_dis(void)

{
  if (_vac != 0) {
                    /* WARNING: Could not recover jumptable at 0xf0095a0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_parity_chk_dis)();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2082 start=0xf0095a14 */

void _pac_pageflush(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095a1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_pac_pageflush)();
  return;
}
/* GHIDRADEC_FUNCTION index=2083 start=0xf0095a24 */

undefined4 _srmmu_mmu_getcr(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)segment(4);
  return *puVar1;
}
/* GHIDRADEC_FUNCTION index=2084 start=0xf0095a30 */

undefined4 _srmmu_mmu_getctp(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(undefined4 *)(iVar1 + 0x100);
}
/* GHIDRADEC_FUNCTION index=2085 start=0xf0095a3c */

undefined4 _srmmu_mmu_getctx(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(undefined4 *)(iVar1 + 0x200);
}
/* GHIDRADEC_FUNCTION index=2086 start=0xf0095a48 */

int _srmmu_mmu_probe(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0xfffff000;
  iVar1 = segment(3);
  iVar3 = 0;
  if (*(int *)((uVar4 | 0x400) + iVar1) != 0) {
    iVar1 = segment(3);
    uVar2 = *(uint *)((uVar4 | 0x200) + iVar1);
    if ((uVar2 & 3) == 2) {
      iVar3 = uVar2 + (param_1 >> 0xc & 0xfff) * 0x100;
    }
    else {
      iVar1 = segment(3);
      uVar2 = *(uint *)((uVar4 | 0x100) + iVar1);
      if ((uVar2 & 3) == 2) {
        iVar3 = uVar2 + (param_1 >> 0xc & 0x3f) * 0x100;
      }
      else {
        iVar1 = segment(3);
        iVar3 = *(int *)(uVar4 + iVar1);
      }
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2087 start=0xf0095abc */

void _srmmu_mmu_setcr(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)segment(4);
  *puVar1 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2088 start=0xf0095ac8 */

void _srmmu_mmu_setctp(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x100) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2089 start=0xf0095ad4 */

void _srmmu_mmu_setctx(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2090 start=0xf0095ae0 */

void _srmmu_mmu_flushall(void)

{
  int iVar1;
  
  iVar1 = segment(3);
  *(undefined4 *)(iVar1 + 0x400) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2091 start=0xf0095af0 */

void _srmmu_mmu_flushctx(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = segment(4);
  iVar2 = segment(0x20);
  iVar3 = segment(4);
  uVar4 = *(undefined4 *)(iVar3 + 0x200);
  if ((*(uint *)(*(int *)(iVar1 + 0x100) * 0x10 + param_2 * 4 + iVar2) & 3) == 1) {
    iVar1 = segment(4);
    *(int *)(iVar1 + 0x200) = param_2;
  }
  iVar1 = segment(3);
  *(undefined4 *)(iVar1 + 0x300) = 0;
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = uVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=2092 start=0xf0095b50 */

void _srmmu_mmu_flushrgn(uint param_1)

{
  func_0xf0095b64(param_1 | 0x200);
  return;
}
/* GHIDRADEC_FUNCTION index=2093 start=0xf0095b58 */

void _srmmu_mmu_flushseg(uint param_1)

{
  func_0xf0095b64(param_1 | 0x100);
  return;
}
/* GHIDRADEC_FUNCTION index=2094 start=0xf0095b60 */

void _srmmu_mmu_flushpage(int param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  *(undefined4 *)(param_1 + iVar1) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2095 start=0xf0095b70 */

void _srmmu_mmu_flushpagectx(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = segment(4);
  iVar2 = segment(0x20);
  iVar3 = segment(4);
  uVar4 = *(undefined4 *)(iVar3 + 0x200);
  if ((*(uint *)(*(int *)(iVar1 + 0x100) * 0x10 + param_2 * 4 + iVar2) & 3) == 1) {
    iVar1 = segment(4);
    *(int *)(iVar1 + 0x200) = param_2;
  }
  iVar1 = segment(3);
  *(undefined4 *)(param_1 + iVar1) = 0;
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = uVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=2096 start=0xf0095bd0 */

void _srmmu_mmu_getsyncflt(void)

{
  segment(4);
  segment(4);
  return;
}
/* GHIDRADEC_FUNCTION index=2097 start=0xf0095be4 */

void _srmmu_mmu_getasyncflt(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = segment(4);
  param_1[1] = *(undefined4 *)(iVar1 + 0x600);
  iVar1 = segment(4);
  *param_1 = *(undefined4 *)(iVar1 + 0x500);
  param_1[2] = 0xffffffff;
  return;
}
/* GHIDRADEC_FUNCTION index=2098 start=0xf0095c08 */

uint _srmmu_mmu_chk_wdreset(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(uint *)(iVar1 + 0x700) & 4;
}
/* GHIDRADEC_FUNCTION index=2099 start=0xf0095c18 */

void _srmmu_mmu_sys_ovf(void)

{
  uint *puVar1;
  uint uVar2;
  
  segment(4);
  puVar1 = (uint *)segment(4);
  uVar2 = *puVar1;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2 | 2;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2 & 0xfffffffd;
  segment(4);
  segment(4);
  st_chk_flt();
  return;
}

