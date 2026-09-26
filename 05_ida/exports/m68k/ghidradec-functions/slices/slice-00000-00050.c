/* GHIDRADEC_FUNCTION index=0 start=0x4000310 */

void _start(void)

{
  func_0x04001318();
  return;
}
/* GHIDRADEC_FUNCTION index=1 start=0x4000318 */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: This function may have set the stack pointer */

void _intstacks(void)

{
                    /* WARNING: Read-only address (ram,0x04001314) is written */
                    /* WARNING: Read-only address (ram,0x04001310) is written */
  uRam04001310 = 0x400132e;
  puRam04001314 = (undefined *)register0x0000003c;
  _m68k_init();
  if (_cpu_type != '\0') {
    invalidateCacheLines(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=2 start=0x40013c4 */

undefined4 _curipl(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=3 start=0x40013d6 */

/* WARNING: Control flow encountered unimplemented instructions */

void _pflush_super(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=4 start=0x40013f4 */

/* WARNING: Control flow encountered unimplemented instructions */

void _pflush_user(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=5 start=0x4001412 */

/* WARNING: Control flow encountered unimplemented instructions */

void _tlb_update_read(void)

{
  if (_cpu_type != '\0') {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=6 start=0x4001440 */

/* WARNING: Control flow encountered unimplemented instructions */

void _tlb_update_write(void)

{
  if (_cpu_type != '\0') {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=7 start=0x400146e */

/* WARNING: Control flow encountered unimplemented instructions */

void _pmove_crp(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=8 start=0x4001498 */

/* WARNING: Control flow encountered unimplemented instructions */

undefined4 _pmove_tt1(undefined4 *param_1)

{
  if (_cpu_type != '\0') {
    return *param_1;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=9 start=0x40014be */

undefined4 __move_space(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = _active_threads;
  uVar1 = *(undefined4 *)(_active_threads + 0x70);
  *(code **)(_active_threads + 0x70) = _move_space_fault;
  if (param_3 == 0) {
    *param_1 = param_4;
  }
  else if (param_3 == 2) {
    *(sword *)param_1 = (sword)param_4;
  }
  else {
    *(char *)param_1 = (char)param_4;
  }
  *(undefined4 *)(iVar2 + 0x70) = uVar1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=10 start=0x4001522 */

void _move_space_fault(void)

{
  undefined4 in_D1;
  undefined4 in_A0;
  undefined4 in_A1;
  int unaff_A6;
  
  **(undefined4 **)(unaff_A6 + 0x18) = in_D1;
  **(undefined4 **)(unaff_A6 + 0x1c) = in_A0;
  **(undefined4 **)(unaff_A6 + 0x20) = in_A1;
  func_0x04001512();
  return;
}
/* GHIDRADEC_FUNCTION index=11 start=0x400153e */

void _cache_push_page(undefined4 param_1)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=12 start=0x4001558 */

void _cache_inval_page(undefined4 param_1)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=13 start=0x400157e */

void _get_vbr(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=14 start=0x400158a */

undefined4 _set_vbr(undefined4 param_1)

{
  return param_1;
}
/* GHIDRADEC_FUNCTION index=15 start=0x400159a */

undefined4 _copyoutstr(char *param_1,char *param_2,uint param_3,int *param_4)

{
  char cVar1;
  uint uVar2;
  word wVar3;
  
  uVar2 = param_3;
  if ((int)param_3 < 1) {
    return 1;
  }
  do {
    wVar3 = (sword)uVar2 - 1;
    if (wVar3 == 0xffff) {
      wVar3 = 0;
      break;
    }
    cVar1 = *param_1;
    *param_2 = cVar1;
    uVar2 = (uint)wVar3;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = (int)(sword)((sword)param_3 - wVar3);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=16 start=0x40015e2 */

/* WARNING: Possible PIC construction at 0x04001624: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x04001624) */

void _copyinstr(char *param_1,char *param_2,uint param_3,int *param_4)

{
  char cVar1;
  uint uVar2;
  word wVar3;
  
  uVar2 = param_3;
  if ((int)param_3 < 1) {
    return;
  }
  do {
    wVar3 = (sword)uVar2 - 1;
    if (wVar3 == 0xffff) {
      wVar3 = 0;
      break;
    }
    cVar1 = *param_1;
    *param_2 = cVar1;
    uVar2 = (uint)wVar3;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = (int)(sword)((sword)param_3 - wVar3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=17 start=0x400162a */

undefined4 _copystr(char *param_1,char *param_2,sword param_3,int *param_4)

{
  char cVar1;
  sword sVar2;
  
  sVar2 = param_3;
  do {
    sVar2 = sVar2 + -1;
    if (sVar2 == -1) {
      sVar2 = 0;
      break;
    }
    cVar1 = *param_1;
    *param_2 = cVar1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = (int)(sword)(param_3 - sVar2);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=18 start=0x400165e */

/* WARNING: Possible PIC construction at 0x040016ca: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x040016ca) */

uint _copyoutmsg(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  word wVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  sword sVar3;
  
  uVar2 = 0;
  if (param_3 != 0) {
    if ((int)param_3 < 1) {
      return param_3;
    }
    uVar2 = -(int)param_2 & 3;
    uVar1 = uVar2;
    while ((uVar1 != 0 && (wVar4 = (sword)uVar2 - 1, uVar2 = (uint)wVar4, wVar4 != 0xffff))) {
      *(undefined *)param_2 = *(undefined *)param_1;
      uVar1 = param_3 - 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
      param_3 = uVar1;
    }
    uVar1 = param_3 << 0x1e | param_3 >> 2;
    while( true ) {
      wVar4 = (word)(uVar1 >> 0x10);
      sVar3 = (sword)uVar1 + -1;
      uVar2 = CONCAT22(wVar4,sVar3);
      if (sVar3 == -1) break;
      *param_2 = *param_1;
      uVar1 = uVar2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    uVar2 = uVar2 << 2 | (uint)(wVar4 >> 0xe);
    puVar5 = param_1;
    puVar6 = param_2;
    if ((uVar1 & 0x80000000) != 0) {
      puVar5 = (undefined4 *)((int)param_1 + 2);
      puVar6 = (undefined4 *)((int)param_2 + 2);
      *(undefined2 *)param_2 = *(undefined2 *)param_1;
    }
    if ((uVar1 & 0x40000000) != 0) {
      *(undefined *)puVar6 = *(undefined *)puVar5;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=19 start=0x40016d0 */

/* WARNING: Possible PIC construction at 0x0400173c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0400173c) */

void _copyinmsg(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  sword sVar3;
  word wVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_3 != 0) {
    if ((int)param_3 < 1) {
      return;
    }
    uVar2 = -(int)param_2 & 3;
    uVar1 = uVar2;
    while ((uVar1 != 0 && (wVar4 = (sword)uVar2 - 1, uVar2 = (uint)wVar4, wVar4 != 0xffff))) {
      *(undefined *)param_2 = *(undefined *)param_1;
      uVar1 = param_3 - 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
      param_3 = uVar1;
    }
    uVar2 = param_3 << 0x1e | param_3 >> 2;
    while( true ) {
      wVar4 = (word)(uVar2 >> 0x10);
      sVar3 = (sword)uVar2 + -1;
      uVar2 = CONCAT22(wVar4,sVar3);
      if (sVar3 == -1) break;
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    wVar4 = wVar4 >> 0xe;
    puVar5 = param_1;
    puVar6 = param_2;
    if ((wVar4 & 2) != 0) {
      puVar5 = (undefined4 *)((int)param_1 + 2);
      puVar6 = (undefined4 *)((int)param_2 + 2);
      *(undefined2 *)param_2 = *(undefined2 *)param_1;
    }
    if ((wVar4 & 1) != 0) {
      *(undefined *)puVar6 = *(undefined *)puVar5;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=20 start=0x4001742 */

/* WARNING: Possible PIC construction at 0x040017c2: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x040017c2) */

uint _copywithin(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 != 0) {
    if ((int)param_3 < 1) {
      return 0x16;
    }
    if (param_1 < param_2) {
      param_1 = (undefined4 *)(param_3 + (int)param_1);
      param_2 = (undefined4 *)(param_3 + (int)param_2);
      uVar2 = (uint)param_2 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        param_1 = (undefined4 *)((int)param_1 + -1);
        param_2 = (undefined4 *)((int)param_2 + -1);
        *(undefined *)param_2 = *(undefined *)param_1;
        param_3 = param_3 - 1;
        uVar1 = param_3;
      }
      uVar2 = param_3;
      switch(param_3 & 0x1c) {
      case :
        goto loc_4001802;
      case :
        goto loc_4001800;
      case :
        goto loc_40017fe;
      case :
        goto loc_40017fc;
      case :
        goto loc_40017fa;
      case :
        goto loc_40017f8;
      case :
        goto loc_40017f6;
      }
      while (param_3 = uVar2 - 0x20, 0x1f < (int)uVar2) {
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017f6:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017f8:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017fa:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017fc:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017fe:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_4001800:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_4001802:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
        uVar2 = param_3;
      }
      if ((param_3 & 2) != 0) {
        param_1 = (undefined4 *)((int)param_1 + -2);
        param_2 = (undefined4 *)((int)param_2 + -2);
        *(undefined2 *)param_2 = *(undefined2 *)param_1;
      }
      if ((param_3 & 1) != 0) {
        *(undefined *)((int)param_2 + -1) = *(undefined *)((int)param_1 + -1);
        uVar2 = func_0x04001836();
        return uVar2;
      }
    }
    else if (param_2 != param_1) {
      uVar2 = -(int)param_2 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        *(undefined *)param_2 = *(undefined *)param_1;
        param_3 = param_3 - 1;
        param_1 = (undefined4 *)((int)param_1 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = param_3;
      }
      uVar2 = param_3;
      puVar4 = param_1;
      puVar6 = param_2;
      switch(param_3 & 0x1c) {
      case :
        goto loc_40017a4;
      case :
        goto loc_40017a2;
      case :
        goto loc_40017a0;
      case :
        goto loc_400179e;
      case :
        goto loc_400179c;
      case :
        goto loc_400179a;
      case :
        goto loc_4001798;
      }
      while (param_3 = uVar2 - 0x20, 0x1f < (int)uVar2) {
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_4001798:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
loc_400179a:
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_400179c:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
loc_400179e:
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_40017a0:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
loc_40017a2:
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_40017a4:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
        uVar2 = param_3;
      }
      puVar5 = puVar4;
      puVar7 = puVar6;
      if ((param_3 & 2) != 0) {
        puVar5 = (undefined4 *)((int)puVar4 + 2);
        puVar7 = (undefined4 *)((int)puVar6 + 2);
        *(undefined2 *)puVar6 = *(undefined2 *)puVar4;
      }
      if ((param_3 & 1) != 0) {
        *(undefined *)puVar7 = *(undefined *)puVar5;
      }
    }
  }
  return param_3;
}
/* GHIDRADEC_FUNCTION index=21 start=0x400182c */

undefined4 _FAULT_ERROR(void)

{
  return _fault_error;
}
/* GHIDRADEC_FUNCTION index=22 start=0x400183c */

undefined4 _fast_setjmp(undefined4 *param_1)

{
  undefined4 unaff_A6;
  undefined4 in_stack_00000000;
  
  *param_1 = in_stack_00000000;
  param_1[0xb] = unaff_A6;
  param_1[0xc] = register0x0000003c;
  return 0;
}
/* GHIDRADEC_FUNCTION index=23 start=0x400184e */

undefined4 _setjmp(undefined4 *param_1)

{
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  undefined4 in_stack_00000000;
  
  *param_1 = in_stack_00000000;
  param_1[1] = unaff_D2;
  param_1[2] = unaff_D3;
  param_1[3] = unaff_D4;
  param_1[4] = unaff_D5;
  param_1[5] = unaff_D6;
  param_1[6] = unaff_D7;
  param_1[7] = unaff_A2;
  param_1[8] = unaff_A3;
  param_1[9] = unaff_A4;
  param_1[10] = unaff_A5;
  param_1[0xb] = unaff_A6;
  param_1[0xc] = register0x0000003c;
  return 0;
}
/* GHIDRADEC_FUNCTION index=24 start=0x400185e */

undefined4 _longjmp(undefined4 *param_1)

{
  *(undefined4 *)param_1[0xc] = *param_1;
  return 1;
}
/* GHIDRADEC_FUNCTION index=25 start=0x400186e */

undefined4 _probe_rb(void)

{
  _probe_recover = 0;
  return 1;
}
/* GHIDRADEC_FUNCTION index=26 start=0x4001898 */

undefined4 _probe_rl(void)

{
  _probe_recover = 0;
  return 1;
}
/* GHIDRADEC_FUNCTION index=27 start=0x40018c2 */

void _simple_unlock(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=28 start=0x40018c4 */

undefined4 _simple_lock_try(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=29 start=0x40018c8 */

void _ovbcopy(void)

{
  _bcopy();
  return;
}
/* GHIDRADEC_FUNCTION index=30 start=0x40018ce */

void _blkclr(void)

{
  _bzero();
  return;
}
/* GHIDRADEC_FUNCTION index=31 start=0x40018d8 */

/* WARNING: Control flow encountered unimplemented instructions */

void __switch_context(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  unkbyte10 unaff_FP4;
  unkbyte10 unaff_FP5;
  unkbyte10 unaff_FP6;
  unkbyte10 unaff_FP7;
  undefined4 in_stack_00000000;
  
  *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) & 0xbf;
  saveFPUStateFrame(param_1[0x17]);
  if (*(char *)(param_1 + 0x17) != '\0') {
    *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) | 0x40;
    puVar1 = (undefined4 *)param_1[0x65];
    *puVar1 = in_FPCR;
    puVar1[3] = in_FPSR;
    puVar1[6] = in_FPIAR;
    *(unkbyte10 *)(param_1 + 0x4d) = in_FP0;
    *(unkbyte10 *)(param_1 + 0x50) = in_FP1;
    *(unkbyte10 *)(param_1 + 0x53) = unaff_FP2;
    *(unkbyte10 *)(param_1 + 0x56) = unaff_FP3;
    *(unkbyte10 *)(param_1 + 0x59) = unaff_FP4;
    *(unkbyte10 *)(param_1 + 0x5c) = unaff_FP5;
    *(unkbyte10 *)(param_1 + 0x5f) = unaff_FP6;
    *(unkbyte10 *)(param_1 + 0x62) = unaff_FP7;
    restoreFPUStateFrame(0);
  }
  *param_1 = in_D0;
  param_1[1] = in_D1;
  param_1[2] = unaff_D2;
  param_1[3] = unaff_D3;
  param_1[4] = unaff_D4;
  param_1[5] = unaff_D5;
  param_1[6] = unaff_D6;
  param_1[7] = unaff_D7;
  param_1[8] = param_1;
  param_1[9] = in_stack_00000000;
  param_1[10] = unaff_A2;
  param_1[0xb] = unaff_A3;
  param_1[0xc] = unaff_A4;
  param_1[0xd] = unaff_A5;
  param_1[0xe] = unaff_A6;
  param_1[0xf] = &param_1;
  restoreFPUStateFrame(param_2[0x17]);
  if (_cpu_type != '\0') {
    *param_2 = param_3;
                    /* WARNING: Could not recover jumptable at 0x0400197a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_2[9])();
    return;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=32 start=0x400197c */

/* WARNING: Control flow encountered unimplemented instructions */

void __switch_context_discard(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  unkbyte10 unaff_FP4;
  unkbyte10 unaff_FP5;
  unkbyte10 unaff_FP6;
  unkbyte10 unaff_FP7;
  
  *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) & 0xbf;
  saveFPUStateFrame(*(undefined4 *)(param_1 + 0x5c));
  if (*(char *)(param_1 + 0x5c) != '\0') {
    *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) | 0x40;
    puVar1 = *(undefined4 **)(param_1 + 0x194);
    *puVar1 = in_FPCR;
    puVar1[3] = in_FPSR;
    puVar1[6] = in_FPIAR;
    *(unkbyte10 *)(param_1 + 0x134) = in_FP0;
    *(unkbyte10 *)(param_1 + 0x140) = in_FP1;
    *(unkbyte10 *)(param_1 + 0x14c) = unaff_FP2;
    *(unkbyte10 *)(param_1 + 0x158) = unaff_FP3;
    *(unkbyte10 *)(param_1 + 0x164) = unaff_FP4;
    *(unkbyte10 *)(param_1 + 0x170) = unaff_FP5;
    *(unkbyte10 *)(param_1 + 0x17c) = unaff_FP6;
    *(unkbyte10 *)(param_1 + 0x188) = unaff_FP7;
    restoreFPUStateFrame(0);
  }
  restoreFPUStateFrame(param_2[0x17]);
  if (_cpu_type != '\0') {
    *param_2 = param_3;
                    /* WARNING: Could not recover jumptable at 0x04001a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_2[9])();
    return;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=33 start=0x4001a1a */

/* WARNING: Control flow encountered unimplemented instructions */

void __switch_context0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  restoreFPUStateFrame(param_2[0x17]);
  if (_cpu_type != '\0') {
    *param_2 = param_3;
                    /* WARNING: Could not recover jumptable at 0x04001a88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_2[9])();
    return;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=34 start=0x4001a8a */

/* WARNING: Control flow encountered unimplemented instructions */

undefined4 __stack_handoff(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  unkbyte10 unaff_FP4;
  unkbyte10 unaff_FP5;
  unkbyte10 unaff_FP6;
  unkbyte10 unaff_FP7;
  
  *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) & 0xbf;
  saveFPUStateFrame(*(undefined4 *)(param_1 + 0x5c));
  if (*(char *)(param_1 + 0x5c) != '\0') {
    *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) | 0x40;
    puVar1 = *(undefined4 **)(param_1 + 0x194);
    *puVar1 = in_FPCR;
    puVar1[3] = in_FPSR;
    puVar1[6] = in_FPIAR;
    *(unkbyte10 *)(param_1 + 0x134) = in_FP0;
    *(unkbyte10 *)(param_1 + 0x140) = in_FP1;
    *(unkbyte10 *)(param_1 + 0x14c) = unaff_FP2;
    *(unkbyte10 *)(param_1 + 0x158) = unaff_FP3;
    *(unkbyte10 *)(param_1 + 0x164) = unaff_FP4;
    *(unkbyte10 *)(param_1 + 0x170) = unaff_FP5;
    *(unkbyte10 *)(param_1 + 0x17c) = unaff_FP6;
    *(unkbyte10 *)(param_1 + 0x188) = unaff_FP7;
    restoreFPUStateFrame(0);
  }
  restoreFPUStateFrame(*(undefined4 *)(param_2 + 0x5c));
  if (_cpu_type != '\0') {
    uVar2 = *(undefined4 *)(param_2 + 0x58);
    if (_cpu_type == '\0') {
      uVar2 = _cache;
    }
    return uVar2;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=35 start=0x4001b16 */

undefined8 __return_with_state(undefined8 *param_1)

{
  return *param_1;
}
/* GHIDRADEC_FUNCTION index=36 start=0x4001b2c */

void __stack_attach(void)

{
  code *unaff_A2;
  
  (*unaff_A2)();
  return;
}
/* GHIDRADEC_FUNCTION index=37 start=0x4001b30 */

void _call_continuation(code *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x04001b3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}
/* GHIDRADEC_FUNCTION index=38 start=0x4001b3e */

void std_trap(word param_1)

{
  undefined *puVar1;
  undefined auStack_40 [8];
  
  puVar1 = auStack_40;
  if (((undefined *)0x4001318 < auStack_40) &&
     ((_stack_pointers < auStack_40 || (auStack_40 <= _stack_pointers + -0xff4)))) {
    puVar1 = _stack_pointers;
  }
  *(undefined **)(puVar1 + -4) = auStack_40;
  *(uint *)(puVar1 + -0x14) = param_1 & 0xfff;
  func_0x0400217c();
  return;
}
/* GHIDRADEC_FUNCTION index=39 start=0x4001b8a */

undefined8 ipl1(void)

{
  int iVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 *puVar2;
  byte in_stack_00000000;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  puVar2 = &uStack_40;
  if ((undefined4 *)0x4001318 < &uStack_40) {
    puVar2 = (undefined4 *)0x4001318;
  }
  uStack_40 = in_D0;
  uStack_3c = in_D1;
  puVar2[-1] = 0;
  puVar2[-2] = 0x4001bbe;
  _softint_run();
  iVar1 = _stack_pointers;
  if ((((in_stack_00000000 & 0x20) == 0) && (_active_threads != 0)) &&
     ((*(byte *)(*(int *)(_active_threads + 0x24) + 0x54) & 0x10) != 0)) {
    *(undefined4 **)(_stack_pointers + -4) = &uStack_40;
    *(undefined4 *)(iVar1 + -8) = 0x4002200;
    _check_for_ast();
  }
  return CONCAT44(uStack_40,uStack_3c);
}
/* GHIDRADEC_FUNCTION index=40 start=0x4001bc6 */

void ipl2(void)

{
  undefined *puVar1;
  undefined auStack_40 [8];
  
  puVar1 = auStack_40;
  if ((undefined *)0x4001318 < puVar1) {
    puVar1 = (undefined *)0x4001318;
  }
  *(undefined4 *)(puVar1 + -4) = 1;
  *(undefined4 *)(puVar1 + -8) = 0x4001bfa;
  _softint_run();
  func_0x040021d2();
  return;
}
/* GHIDRADEC_FUNCTION index=41 start=0x4001c02 */

void ipl3(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 in_D0;
  sword sVar3;
  undefined *puVar4;
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000002;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  *(uint *)(puVar4 + -4) = CONCAT22((sword)((uint)in_D0 >> 0x10),in_stack_00000000);
  *(undefined4 *)(puVar4 + -8) = in_stack_00000002;
  while( true ) {
    uVar2 = (_intr_mask & *_intrstat & 0x3fff) >> 2;
    if (uVar2 == 0) break;
    sVar3 = (word)(uVar2 != 0) * (sword)LZCOUNT(uVar2 << 0x14) + (word)(uVar2 == 0) * 0x1e + -0x12;
    pcVar1 = *(code **)(_ipl3_scan + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0xc) = *(undefined4 *)(_ipl3_arg + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0x10) = 0x4001c6e;
    (*pcVar1)();
  }
  dword_40B565C = dword_40B565C + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=42 start=0x4001c72 */

void ipl4(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 in_D0;
  sword sVar3;
  undefined *puVar4;
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000002;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  *(uint *)(puVar4 + -4) = CONCAT22((sword)((uint)in_D0 >> 0x10),in_stack_00000000);
  *(undefined4 *)(puVar4 + -8) = in_stack_00000002;
  while( true ) {
    uVar2 = (_intr_mask & *_intrstat & 0x7fff) >> 0xe;
    if (uVar2 == 0) break;
    sVar3 = (word)(uVar2 != 0) * (sword)LZCOUNT(uVar2 << 0x1f) + (word)(uVar2 == 0) * 0x12 + -0x11;
    pcVar1 = (code *)(&_ipl4_scan)[sVar3];
    *(undefined4 *)(puVar4 + -0xc) = (&_ipl4_arg)[sVar3];
    *(undefined4 *)(puVar4 + -0x10) = 0x4001cde;
    (*pcVar1)();
  }
  func_0x040021cc();
  return;
}
/* GHIDRADEC_FUNCTION index=43 start=0x4001ce2 */

void ipl5(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  puVar3 = (undefined4 *)_poll_intr;
  do {
    pcVar1 = (code *)*puVar3;
    *(undefined4 *)(puVar4 + -4) = 0x4001d14;
    iVar2 = (*pcVar1)();
    puVar3 = puVar3 + 1;
  } while (iVar2 == 0);
  func_0x040021cc();
  return;
}
/* GHIDRADEC_FUNCTION index=44 start=0x4001d1e */

void ipl6(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 in_D0;
  sword sVar3;
  undefined *puVar4;
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000002;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  *(uint *)(puVar4 + -4) = CONCAT22((sword)((uint)in_D0 >> 0x10),in_stack_00000000);
  *(undefined4 *)(puVar4 + -8) = in_stack_00000002;
  while( true ) {
    uVar2 = (_intr_mask & *_intrstat & 0x3fffffff) >> 0x12;
    if (uVar2 == 0) break;
    sVar3 = (word)(uVar2 != 0) * (sword)LZCOUNT(uVar2 << 0x14) + (word)(uVar2 == 0) * 0xe + -2;
    pcVar1 = *(code **)(_ipl6_scan + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0xc) = *(undefined4 *)(_ipl6_arg + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0x10) = 0x4001d86;
    (*pcVar1)();
  }
  func_0x040021cc();
  return;
}
/* GHIDRADEC_FUNCTION index=45 start=0x4001d8a */

void ipl7(void)

{
  code *pcVar1;
  uint uVar2;
  sword sVar3;
  undefined4 in_D0;
  undefined *puVar4;
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000002;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  *(uint *)(puVar4 + -4) = CONCAT22((sword)((uint)in_D0 >> 0x10),in_stack_00000000);
  *(undefined4 *)(puVar4 + -8) = in_stack_00000002;
  while( true ) {
    uVar2 = _intr_mask & *_intrstat & 0xc0000000;
    sVar3 = (word)(uVar2 != 0) * (sword)LZCOUNT(uVar2) + (word)(uVar2 == 0) * 2;
    if (uVar2 == 0) break;
    pcVar1 = *(code **)((int)&_ipl7_scan + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0xc) = *(undefined4 *)((int)&_ipl7_arg + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0x10) = 0x4001df6;
    (*pcVar1)();
  }
  func_0x040021cc();
  return;
}
/* GHIDRADEC_FUNCTION index=46 start=0x4001dfa */

void _call_nmi(void)

{
  _nmi();
  return;
}
/* GHIDRADEC_FUNCTION index=47 start=0x4001e1e */

/* WARNING: Control flow encountered bad instruction data */

undefined8 trap3(void)

{
  code *pcVar1;
  int iVar2;
  int in_D0;
  sword sVar3;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  dword_40B5658 = dword_40B5658 + 1;
  puVar5 = _stack_pointers;
  uStack_3c = in_D1;
  if ((in_D0 < 0) || (_mach_trap_count <= in_D0)) {
    uStack_40 = 4;
  }
  else {
    sVar3 = (sword)in_D0 << 4;
    puVar4 = _stack_pointers;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(sVar3) {
    case :
      puVar4 = _stack_pointers + -4;
      *(undefined4 *)(_stack_pointers + -4) = unaff_D7;
    case :
      puVar5 = puVar4 + -4;
      *(undefined4 *)(puVar4 + -4) = unaff_D6;
    case :
    case :
      puVar4 = puVar5 + -4;
      *(undefined4 *)(puVar5 + -4) = unaff_D5;
    case :
    case :
    case :
      puVar5 = puVar4 + -4;
      *(undefined4 *)(puVar4 + -4) = unaff_D4;
    case :
      *(undefined4 *)(puVar5 + -4) = unaff_D3;
      puVar4 = puVar5 + -8;
      *(undefined4 *)(puVar5 + -8) = unaff_D2;
    case :
    case :
    case :
    case :
    case :
      puVar5 = puVar4 + -4;
      *(undefined4 *)(puVar4 + -4) = in_D1;
    :
      pcVar1 = *(code **)(_mach_trap_table + sVar3 + 4);
      *(undefined4 *)(puVar5 + -4) = 0x4001e7e;
      uStack_40 = (*pcVar1)();
      break;
    case :
      return CONCAT44(*(undefined4 *)(_mach_trap_table + sVar3),in_D1);
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
      return CONCAT44(*(undefined4 *)(_mach_trap_table + sVar3),in_D1);
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if ((((*(byte *)(*(int *)(_active_threads + 0x24) + 0x54) & 0x10) != 0) ||
      (iVar2 = **(int **)(*(int *)(_active_threads + 0xc) + 0x30), *(char *)(iVar2 + 0x17) != '\0'))
     || (*(int *)(iVar2 + 0x18) != 0)) {
    *(undefined4 **)(puVar5 + -4) = &uStack_40;
    *(undefined4 *)(puVar5 + -8) = 0x4001eb4;
    _check_for_ast();
  }
  return CONCAT44(uStack_40,uStack_3c);
}
/* GHIDRADEC_FUNCTION index=48 start=0x4001ec8 */

undefined8 trap4(void)

{
  int iVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  iVar1 = _stack_pointers;
  dword_40B5658 = dword_40B5658 + 1;
  *(undefined4 **)(_stack_pointers + -4) = &uStack_40;
  *(undefined4 *)(iVar1 + -8) = 0x4001eee;
  uStack_40 = in_D0;
  uStack_3c = in_D1;
  _unix_syscall();
  return CONCAT44(uStack_40,uStack_3c);
}
/* GHIDRADEC_FUNCTION index=49 start=0x4001f02 */

undefined4 trap5(void)

{
  return *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x50);
}

