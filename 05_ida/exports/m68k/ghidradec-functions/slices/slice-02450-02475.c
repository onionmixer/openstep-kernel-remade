/* GHIDRADEC_FUNCTION index=2450 start=0x40927d4 */

word _in_cksum(int *param_1,int param_2)

{
  sword sVar1;
  word wVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    do {
      if (param_2 <= *(sword *)(param_1 + 2)) {
        pbVar4 = (byte *)(param_1[1] + (int)param_1);
        goto loc_4092890;
      }
      uVar3 = (uint)*(sword *)(param_1 + 2);
      iVar5 = _oc_cksum(param_1[1] + (int)param_1,uVar3,iVar5);
      param_1 = (int *)*param_1;
      param_2 = param_2 - uVar3;
    } while ((uVar3 & 1) == 0);
    sVar1 = *(sword *)(param_1 + 2);
    if (sVar1 < param_2) {
      do {
        pbVar4 = (byte *)(param_1[1] + (int)param_1);
        if ((uVar3 & 1) == 0) {
          uVar3 = (uint)*(sword *)(param_1 + 2);
        }
        else {
          uVar3 = (int)sVar1 - 1;
          param_2 = param_2 + -1;
          iVar5 = (uint)*pbVar4 + iVar5;
          pbVar4 = pbVar4 + 1;
        }
        iVar5 = _oc_cksum(pbVar4,uVar3,iVar5);
        param_1 = (int *)*param_1;
        param_2 = param_2 - uVar3;
        sVar1 = *(sword *)(param_1 + 2);
      } while (sVar1 < param_2);
    }
  } while ((uVar3 & 1) == 0);
  pbVar4 = (byte *)(param_1[1] + (int)param_1) + 1;
  iVar5 = iVar5 + (uint)*(byte *)(param_1[1] + (int)param_1);
  param_2 = param_2 + -1;
loc_4092890:
  wVar2 = _oc_cksum(pbVar4,param_2,iVar5);
  return ~wVar2;
}
/* GHIDRADEC_FUNCTION index=2451 start=0x40928a8 */

sword _oc_cksum(int *param_1,uint param_2,int param_3)

{
  sword sVar1;
  uint uVar2;
  word wVar3;
  int *piVar4;
  
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) {
      param_3 = (uint)*(word *)((int)param_1 + (param_2 - 2)) + param_3;
    }
  }
  else {
    if ((param_2 & 2) != 0) {
      param_3 = (uint)*(word *)((int)param_1 + (param_2 - 3)) + param_3;
    }
    param_3 = (uint)*(byte *)((int)param_1 + (param_2 - 1)) * 0x100 + param_3;
  }
  uVar2 = param_2 >> 6;
  piVar4 = param_1;
  switch(param_2 & 0x3c) {
  case :
    goto loc_4092918;
  case :
    goto loc_4092914;
  case :
    goto loc_4092910;
  case :
    goto loc_409290c;
  case :
    goto loc_4092908;
  case :
    goto loc_4092904;
  case :
    goto loc_4092900;
  case :
    goto loc_40928fc;
  case :
    goto loc_40928f8;
  case :
    goto loc_40928f4;
  case :
    goto loc_40928f0;
  case :
    goto loc_40928ec;
  case :
    goto loc_40928e8;
  case :
    goto loc_40928e4;
  case :
    goto loc_40928e0;
  }
  while (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff) {
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928e0:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928e4:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928e8:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928ec:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928f0:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928f4:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928f8:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928fc:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092900:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_4092904:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092908:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_409290c:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092910:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_4092914:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092918:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
  }
  wVar3 = (word)((uint)param_3 >> 0x10);
  sVar1 = wVar3 + (word)param_3;
  if (CARRY2(wVar3,(word)param_3)) {
    sVar1 = sVar1 + 1;
  }
  return sVar1;
}
/* GHIDRADEC_FUNCTION index=2452 start=0x409295e */

void _kdp_exception(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2453 start=0x4092966 */

void _kdp_exception_ack(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2454 start=0x409296e */

void _kdp_machine_read_regs(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2455 start=0x4092976 */

void _kdp_machine_write_regs(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2456 start=0x409297e */

void _kdp_machine_hostinfo(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2457 start=0x4092986 */

void _kdp_panic(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2458 start=0x409298e */

void _kdp_reboot(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2459 start=0x4092996 */

void _kdp_intr_disbl(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2460 start=0x409299e */

void _kdp_intr_enbl(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2461 start=0x40929a6 */

void _kdp_en_send_pkt(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2462 start=0x40929ae */

void _kdp_en_recv_pkt(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2463 start=0x40929b6 */

void _kdp_us_spin(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2464 start=0x40929be */

void _kdp_flush_cache(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2465 start=0x40929c6 */

undefined4 _check_cpu_subtype(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == 1) || (param_1 == -1)) || (param_1 == dword_40B5DD0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2466 start=0x40929ec */

undefined4 _grade_cpu_subtype(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) || (param_1 == -1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
    if (param_1 != dword_40B5DD0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2467 start=0x4092a1a */

void _kpmon_null(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2468 start=0x4092a22 */

void _pmonlogevent(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint uStack_c;
  undefined4 uStack_8;
  
  uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
             0xfffff;
  if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  uStack_8 = *_event_high;
  uStack_c = *_event_middle | uStack_c;
  (*_pmon_event_log_p)(param_1,param_2,&uStack_c,param_3,param_4,param_5);
  return;
}
/* GHIDRADEC_FUNCTION index=2469 start=0x4092aee */

void _pmonlogcontext(undefined4 param_1,undefined4 param_2,int param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_3 != _vm_saved_context_thread) {
    _vm_saved_context_flushed = 0;
    _vm_saved_context_thread = param_3;
    _vm_saved_context_data0 = uRam040c32c2;
    _vm_saved_context_data1 = uRam040c2c0e;
    pcVar3 = param_4 + 1;
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
    iVar2 = 0;
    do {
      pcVar3 = pcVar3 + -1;
      if (pcVar3 <= param_4) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    _strncpy(&_vm_saved_context_name,pcVar3,0xc);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2470 start=0x4092b56 */

void _pmonlogexec(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar3 = uRam040c32c2;
  uVar2 = uRam040c2c0e;
  pcVar5 = param_4 + 1;
  cVar1 = *pcVar5;
  while (cVar1 != '\0') {
    pcVar5 = pcVar5 + 1;
    cVar1 = *pcVar5;
  }
  iVar4 = 0;
  do {
    pcVar5 = pcVar5 + -1;
    if (pcVar5 <= param_4) break;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  _strncpy(&uStack_10,pcVar5,0xc);
  _pmonlogevent(param_1,param_2,param_3,CONCAT22(uVar3,uVar2),0);
  _pmonlogevent(param_1,0x8000000,uStack_10,uStack_c,uStack_8);
  return;
}
/* GHIDRADEC_FUNCTION index=2471 start=0x4092be4 */

void _pmonlogcontextflush(undefined4 param_1,undefined4 param_2)

{
  if (_vm_saved_context_flushed == 0) {
    _vm_saved_context_flushed = 1;
    _pmonlogevent(param_1,param_2,_vm_saved_context_thread,
                  CONCAT22(_vm_saved_context_data0,_vm_saved_context_data1),0);
    _pmonlogevent(param_1,0x20000000,_vm_saved_context_name,dword_40C9484,unk_40C9488);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2472 start=0x4092c50 */

int _abs(int param_1)

{
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=2473 start=0x4092c60 */

uint _bcmp(int *param_1,int *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  sword sVar6;
  word wVar7;
  bool bVar8;
  
  if (((0x40 < (int)param_3) && ((((uint)param_1 ^ (uint)param_2) & 3) == 0)) &&
     (uVar5 = -(int)param_1 & 3, uVar5 != 0)) {
    param_3 = param_3 - uVar5;
    uVar5 = uVar5 - 1;
    do {
      cVar1 = *(char *)param_1;
      param_1 = (int *)((int)param_1 + 1);
      cVar2 = *(char *)param_2;
      param_2 = (int *)((int)param_2 + 1);
      if (cVar2 != cVar1) break;
      wVar7 = (sword)uVar5 - 1;
      uVar5 = (uint)wVar7;
    } while (wVar7 != 0xffff);
    if (cVar2 != cVar1) {
      return 1;
    }
  }
  while( true ) {
    uVar5 = param_3 >> 2;
    bVar8 = true;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    if ((int)uVar5 < 0x10000) goto loc_4092CE6;
    sVar6 = -1;
    do {
      iVar3 = *param_1;
      param_1 = param_1 + 1;
      iVar4 = *param_2;
      param_2 = param_2 + 1;
      if (iVar4 != iVar3) break;
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    if (iVar4 != iVar3) {
      return 1;
    }
    param_3 = param_3 - 0x40000;
  }
  goto loc_4092D02;
  while (wVar7 = (sword)uVar5 - 1, uVar5 = (uint)wVar7, wVar7 != 0xffff) {
loc_4092CE6:
    iVar3 = *param_1;
    param_1 = param_1 + 1;
    iVar4 = *param_2;
    param_2 = param_2 + 1;
    if (iVar4 != iVar3) break;
  }
  if (iVar4 != iVar3) {
    return 1;
  }
  param_3 = param_3 & 3;
  uVar5 = 0;
  bVar8 = true;
loc_4092D02:
  while ((bVar8 && (wVar7 = (sword)param_3 - 1, param_3 = (uint)wVar7, wVar7 != 0xffff))) {
    cVar1 = *(char *)param_1;
    param_1 = (int *)((int)param_1 + 1);
    cVar2 = *(char *)param_2;
    param_2 = (int *)((int)param_2 + 1);
    bVar8 = cVar2 == cVar1;
  }
  if (!bVar8) {
    return 1;
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2474 start=0x4092d1a */

void _memmove(void)

{
  func_0x04092d38();
  return;
}

