/* GHIDRADEC_FUNCTION index=2525 start=0x4095460 */

void _m68k_dbginit(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  dword_40B5620 = *(undefined4 *)(iVar1 + 0xbc);
  *(code **)(iVar1 + 0xbc) = __dbg_trap;
  _dbg_kresume();
  _adb_watchdog(0);
  _dbg_process(_dbg_connect_pkt);
  _adb_watchdog(1);
  return;
}
/* GHIDRADEC_FUNCTION index=2526 start=0x40954b2 */

int _dbg_kresume(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = _dbg_setjmp(unk_40B55CC);
  puVar1 = dword_40C9714;
  if (iVar2 == 0) {
    dword_40C9714 = dword_40C9714 + -4;
    *dword_40C9714 = word_40C971A;
    *(undefined4 *)(puVar1 + -3) = dword_40C971C;
    *(byte *)(puVar1 + -1) = *(byte *)(puVar1 + -1) & 0xf;
    dword_40B5610 = unk_40B55CC;
    iVar2 = __dbg_kresume();
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2527 start=0x409552a */

void _dbg_panic(undefined4 param_1)

{
  _nmi_prf(aDbgPanicS,param_1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2528 start=0x409554a */

undefined4 _dbg_trap(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  _adb_watchdog(0);
  _get_vbr();
  if (_client_running == 0) {
    dword_40B5630 = 5;
  }
  else {
    if ((*(word *)(param_1 + 0x46) & 0x2000) == 0) {
      iVar1 = (*(int *)(param_1 + 0x4c) << 4) >> 0x16;
      if (iVar1 == 9) {
        _adb_watchdog(1);
        uVar2 = dword_40B561C;
      }
      else {
        if (iVar1 != 0x2f) {
          _nmi_prf(aDbgTrapReturni,(*(int *)(param_1 + 0x4c) << 4) >> 0x14);
                    /* WARNING: Subroutine does not return */
          _dbg_panic(aDbgTrapBadUser);
        }
        _adb_watchdog(1);
        uVar2 = dword_40B5620;
      }
      return uVar2;
    }
    _client_running = 0;
    _bcopy(param_1,&_client_pcb,0xa2);
    dword_40B5634 = 0;
    dword_40B5638 = (*(int *)(param_1 + 0x4c) << 4) >> 0x14;
    switch(*(int *)(param_1 + 0x4c) >> 0x1c) {
    case :
    case :
      dword_40C9714 = dword_40C9714 + 8;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0xc;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0xc;
      break;
    :
                    /* WARNING: Subroutine does not return */
      _dbg_panic(aStackFrameScre);
    case :
      dword_40C9714 = dword_40C9714 + 0x3c;
      dword_40B5634 = dword_40C972A;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x14;
      dword_40B5634 = CONCAT22(dword_40C9722._0_2_,dword_40C9722._2_2_);
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x20;
      dword_40B5634 = dword_40C972A;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x5c;
      dword_40B5634 = dword_40C972A;
    }
    switch((CONCAT22(word_40C9720,dword_40C9722._0_2_) << 4) >> 0x16) {
    case :
    case :
      dword_40B5630 = 1;
      break;
    case :
      dword_40B5630 = 2;
      break;
    :
      dword_40B5630 = 5;
      break;
    case :
      if ((dword_40B5610 != 0) && (dword_40B5624 != 0)) {
        iVar1 = _get_vbr();
        *(undefined4 *)(iVar1 + 0x24) = dword_40B561C;
        word_40C971A = word_40C971A & 0x7fff;
        dword_40B5624 = 0;
      }
    case :
      dword_40B5630 = 6;
    }
  }
  _adb_watchdog(1);
                    /* WARNING: Subroutine does not return */
  _dbg_dispatch();
}
/* GHIDRADEC_FUNCTION index=2529 start=0x4095890 */

void _dbg_dispatch(void)

{
  int iVar1;
  
  iVar1 = dword_40B5610;
  if (dword_40B5610 != 0) {
    dword_40B5610 = 0;
    _dbg_longjmp(iVar1,dword_40B5630);
  }
                    /* WARNING: Subroutine does not return */
  _dbg_panic(aDebuggerScrewU);
}
/* GHIDRADEC_FUNCTION index=2530 start=0x40958d4 */

undefined4 _kdbg_connect(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (dword_40C9474 == 0) {
    _kdb_net._0_4_ = 0;
    _kdb_net._4_4_ = 0;
    _en_bufalloc(param_1);
    _dbg_connect_pkt = sub_40963BC(1);
    if (_dbg_connect_pkt == 0) {
      uVar1 = 0;
    }
    else if (*(int *)(_dbg_connect_pkt + 0x2e) == 8) {
      dword_40C9474 = 1;
      if (dword_40B5628 != 0) {
                    /* WARNING: Subroutine does not return */
        _dbg_dispatch();
      }
      __m68k_trap(0xf);
      uVar1 = 1;
    }
    else {
      _nmi_prf(aOldDebuggingIn,*(undefined4 *)(_dbg_connect_pkt + 0x2e));
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2531 start=0x409597a */

void _gdb_from_trap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword_40B5628 = dword_40B5628 + 1;
  if (dword_40B5628 == 1) {
    word_40C9720 = word_40C9720 & 0xf000 | 8;
    dword_40B5630 = 1;
    dword_40B5634 = param_4;
    _bcopy(param_1,&dword_40C96D8,0x48);
    dword_40C971C = param_3;
    word_40C971A = (undefined2)param_2;
    if (dword_40C9474 != 0) {
      _nmi_prf(aGdbFromTrapPcX,param_3,dword_40C9714,param_2,param_4);
                    /* WARNING: Subroutine does not return */
      _dbg_dispatch();
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2532 start=0x4095a30 */

void _dbg_from_ether(int param_1)

{
  if ((dword_40C9474 != 0) && (*(int *)(param_1 + 0x2e) == 0x11)) {
    _dbg_connect_pkt = param_1;
    dword_40B562C = 1;
    __m68k_trap(0xf);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2533 start=0x4095a66 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void _dbg_process(int param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piStack_28;
  int iStack_10;
  
  iVar2 = dword_40C8F00;
  iVar1 = dword_40C8F00 + 0x2a;
  if ((dword_40C9474 == 0) || (param_1 == 0)) {
    return;
  }
  _nmi_prf(aConnectingToDe);
loc_4095AAE:
  do {
    switch(*(undefined4 *)(param_1 + 0x2e)) {
    case :
      puVar3 = (undefined *)_index(param_1 + 0x42,0x3a);
      if (puVar3 != (undefined *)0x0) {
        *puVar3 = 0;
      }
      _nmi_prf(aDebuggingConne,param_1 + 0x42,puVar3 + 1);
      DAT_40c9470 = 0;
      *(undefined4 *)(iVar2 + 0x2e) = 2;
      break;
    case :
      *(undefined4 *)(iVar2 + 0x3a) = 1;
      *(undefined4 *)(iVar2 + 0x2e) = 5;
      break;
    :
      _nmi_prf(aKdbgUnknownRqT,*(undefined4 *)(iVar2 + 0x2e));
loc_4096144:
      *(undefined4 *)(iVar2 + 0x2e) = 0x16;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      *(int *)(iVar2 + 0x42) = _slot_id;
      *(undefined4 *)(iVar2 + 0x46) = 0x20000;
      *(undefined4 *)(iVar2 + 0x4a) = 1;
      *(int *)(iVar2 + 0x4e) = _slot_id + 0x1000000;
      *(undefined4 *)(iVar2 + 0x52) = 0x20000;
      *(undefined4 *)(iVar2 + 0x56) = 1;
      *(int *)(iVar2 + 0x5a) = _slot_id + 0x2000000;
      *(undefined4 *)(iVar2 + 0x5e) = 0xc0040;
      *(undefined4 *)(iVar2 + 0x62) = 3;
      *(int *)(iVar2 + 0x66) = _slot_id + 0x2100000;
      *(undefined4 *)(iVar2 + 0x6a) = 0x1e000;
      *(undefined4 *)(iVar2 + 0x6e) = 3;
      *(int *)(iVar2 + 0x72) = _slot_id + 0x4000000;
      if (_dma_chip == 0x139) {
        if (_machine_type == '\x03') {
          uVar4 = 0x2000000;
        }
        else {
          uVar4 = 0x4000000;
        }
      }
      else {
        uVar4 = 0x8000000;
      }
      *(undefined4 *)(iVar2 + 0x76) = uVar4;
      *(undefined4 *)(iVar2 + 0x7a) = 3;
      piStack_28 = (int *)(iVar2 + 0x7e);
      switch(_machine_type) {
      case :
      case :
        break;
      case :
        *piStack_28 = 0x4000000;
        *(undefined4 *)(iVar2 + 0x82) = 0x8000000;
        *(undefined4 *)(iVar2 + 0x86) = 3;
        *(undefined4 *)(iVar2 + 0x8a) = 0xc000000;
        *(undefined4 *)(iVar2 + 0x8e) = 0x10000000;
        *(undefined4 *)(iVar2 + 0x92) = 3;
        *(undefined4 *)(iVar2 + 0x96) = 0x24000000;
        *(undefined4 *)(iVar2 + 0x9a) = 0x28000000;
        *(undefined4 *)(iVar2 + 0x9e) = 3;
        *(undefined4 *)(iVar2 + 0xa2) = 0x2c000000;
        *(undefined4 *)(iVar2 + 0xa6) = 0x30000000;
        *(undefined4 *)(iVar2 + 0xaa) = 3;
        piStack_28 = (int *)(iVar2 + 0xae);
        break;
      :
        *piStack_28 = _slot_id + 0x2200000;
        *(undefined4 *)(iVar2 + 0x82) = 0x9000;
        *(undefined4 *)(iVar2 + 0x86) = 3;
        *(int *)(iVar2 + 0x8a) = _slot_id + 0x2210000;
        *(undefined4 *)(iVar2 + 0x8e) = 4;
        *(undefined4 *)(iVar2 + 0x92) = 3;
        *(int *)(iVar2 + 0x96) = _slot_id + 0x3e00000;
        *(undefined4 *)(iVar2 + 0x9a) = 0x80000;
        *(undefined4 *)(iVar2 + 0x9e) = 3;
        piStack_28 = (int *)(iVar2 + 0xa2);
      }
      *piStack_28 = 0x10000000;
      piStack_28[1] = 0x4000000;
      piStack_28[2] = 3;
      *(int *)(iVar2 + 0x3e) = (int)piStack_28 + (-0xc - iVar1);
      *(undefined4 *)(iVar2 + 0x2e) = 6;
      break;
    case :
      if (0x200 < *(int *)(param_1 + 0x3a)) {
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aBadLengthOfDat);
      }
      for (iStack_10 = 0; iStack_10 < *(int *)(param_1 + 0x3a); iStack_10 = iStack_10 + 4) {
        iVar5 = _rdmem(iStack_10 + *(int *)(param_1 + 0x36),4,iStack_10 + 0x18 + iVar1);
        if (iVar5 != 0) goto loc_4096144;
      }
      *(undefined4 *)(iVar2 + 0x2e) = 3;
      *(undefined4 *)(iVar2 + 0x3e) = *(undefined4 *)(param_1 + 0x3a);
      break;
    case :
      if (*(int *)(param_1 + 0x3e) != 0x200) {
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aBadLengthOfDat);
      }
      for (iStack_10 = 0; iStack_10 < 0x200; iStack_10 = iStack_10 + 4) {
        iVar5 = _wrmem(iStack_10 + *(int *)(param_1 + 0x36),4,
                       *(undefined4 *)(iStack_10 + 0x18 + param_1 + 0x2a));
        if (iVar5 != 0) goto loc_4096144;
      }
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
      _bcopy(&dword_40C96D8,iVar2 + 0x42,0x48);
      *(undefined4 *)(iVar2 + 0x3e) = 0x48;
      *(undefined4 *)(iVar2 + 0x2e) = 4;
      break;
    case :
      _bcopy(param_1 + 0x42,&dword_40C96D8,0x48);
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
    case :
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
    case :
      goto loc_4095eae;
    case :
      dword_40C9474 = 0;
      dword_40B562C = 1;
loc_4095eae:
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      sub_40964C0();
      if ((word_40C971A & 0x8000) != 0) {
        iVar5 = _get_vbr();
        dword_40B561C = *(undefined4 *)(iVar5 + 0x24);
        *(code **)(iVar5 + 0x24) = __dbg_trap;
        dword_40B5624 = 1;
      }
      _dbg_kresume();
      if (dword_40B562C != 0) goto loc_4095f18;
      _SENDEXC();
      goto loc_409615C;
    case :
      if ((*(int *)(param_1 + 0x3e) == 0) || (0x1ff < *(int *)(param_1 + 0x3e))) {
        _mon_boot(0);
      }
      else {
        *(undefined *)(*(int *)(param_1 + 0x3e) + param_1 + 0x2a + 0x18) = 0;
        _mon_call(param_1 + 0x42);
      }
    }
    sub_40964C0();
loc_409615C:
    param_1 = sub_40963BC(0);
  } while( true );
loc_4095f18:
  dword_40B562C = 0;
  param_1 = _dbg_connect_pkt;
  _dbg_connect_pkt = 0;
  goto loc_4095AAE;
}
/* GHIDRADEC_FUNCTION index=2534 start=0x4096178 */

int _rdmem(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = _dbg_setjmp(unk_40B55CC);
  if (iVar1 == 0) {
    dword_40B5610 = unk_40B55CC;
    sub_409630E();
    if (param_2 == 2) {
      *param_3 = (int)*(sword *)param_1;
      *param_3 = *param_3 & 0xffff;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
loc_409622C:
        dword_40B5610 = (undefined *)0x0;
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aRdmemBadSize);
      }
      *param_3 = (int)*(char *)param_1;
      *param_3 = *param_3 & 0xff;
    }
    else {
      if (param_2 != 4) goto loc_409622C;
      *param_3 = *param_1;
    }
    sub_4096358();
    dword_40B5610 = (undefined *)0x0;
    iVar1 = 0;
  }
  else {
    sub_4096358();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2535 start=0x409625a */

int _wrmem(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _dbg_setjmp(unk_40B55CC);
  if (iVar1 == 0) {
    dword_40B5610 = unk_40B55CC;
    sub_409630E();
    if (param_2 == 2) {
      *(sword *)param_1 = (sword)param_3;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
loc_40962D8:
        dword_40B5610 = (undefined *)0x0;
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aWrmemBadSize);
      }
      *(char *)param_1 = (char)param_3;
    }
    else {
      if (param_2 != 4) goto loc_40962D8;
      *param_1 = param_3;
    }
    _cache_push();
    dword_40B5610 = (undefined *)0x0;
    sub_4096358();
    _cache_push();
    iVar1 = 0;
  }
  else {
    sub_4096358();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2536 start=0x4096386 */

void _kdebug_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = dword_40C8F00;
  *(undefined4 *)(dword_40C8F00 + 0x2a) = param_2;
  _en_send(param_1,iVar1,0x242);
  return;
}
/* GHIDRADEC_FUNCTION index=2537 start=0x40964f2 */

void _SENDEXC(void)

{
  int iVar1;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 *puStack_10;
  int iStack_c;
  int *piStack_8;
  
  iVar1 = dword_40C8F04;
  piStack_8 = (int *)&_kdb_net;
  iStack_c = dword_40C8F04;
  puStack_10 = (undefined4 *)(dword_40C8F04 + 0x2a);
  *(undefined4 *)(dword_40C8F04 + 0x2e) = dword_40B5630;
  *(undefined4 *)(iVar1 + 0x3a) = dword_40B5638;
  *(undefined4 *)(iVar1 + 0x36) = dword_40B5634;
  *puStack_10 = DAT_40c9470;
  do {
    _en_send(0x474,iStack_c,0x242);
    for (iStack_18 = 0; iStack_18 < 50000; iStack_18 = iStack_18 + 1) {
      iStack_14 = _en_recv(&iStack_1c,0x242,piStack_8[2],_kdb_ipaddr);
      if (iStack_14 != 0) {
        if ((iStack_1c == 0x474) && (piStack_8[1] == *(int *)(iStack_14 + 0x2a))) {
          piStack_8[1] = piStack_8[1] + 1;
          return;
        }
        iStack_1c = 0x473;
        if (*piStack_8 + -1 == *(int *)(iStack_14 + 0x2a)) {
          _kdebug_send(0x473,*(int *)(iStack_14 + 0x2a));
        }
      }
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2538 start=0x409662a */

bool _inet_aton(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar1 = &uStack_8;
  iStack_c = 0;
  do {
    if (*param_1 == '\0') {
      bVar2 = (undefined4 *)((int)&uStack_8 + 3) == puVar1;
      if (bVar2) {
        *(char *)puVar1 = (char)iStack_c;
        *param_2 = uStack_8;
      }
      return bVar2;
    }
    if (*param_1 == '.') {
      if ((undefined4 *)((int)&uStack_8 + 3U) <= puVar1) {
        return false;
      }
      *(char *)puVar1 = (char)iStack_c;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iStack_c = 0;
    }
    else {
      if ((*param_1 < '0') || ('9' < *param_1)) {
        return false;
      }
      iStack_c = iStack_c * 10 + -0x30 + (int)*param_1;
      if ((0xff < iStack_c) || (iStack_c < 0)) {
        return false;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2539 start=0x4096700 */

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
/* GHIDRADEC_FUNCTION index=2540 start=0x4096736 */

undefined8 __dbg_trap(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined auStack_46 [4];
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  dword_40B5640 = (undefined *)register0x0000003c;
  uStack_42 = in_D0;
  uStack_3e = in_D1;
  dword_40B563C = _dbg_trap(auStack_46);
  *(undefined4 *)(dword_40B5640 + -4) = dword_40B563C;
  return CONCAT44(uStack_42,uStack_3e);
}
/* GHIDRADEC_FUNCTION index=2541 start=0x409677c */

undefined8 __dbg_kresume(void)

{
  _client_running = 1;
  return CONCAT44(dword_40C96D8,DAT_40c96dc._0_4_);
}
/* GHIDRADEC_FUNCTION index=2542 start=0x409679a */

undefined4 _dbg_setjmp(undefined4 *param_1)

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
  undefined4 in_stack_00000000;
  
  param_1[0x10] = in_stack_00000000;
  *param_1 = in_D0;
  param_1[1] = in_D1;
  param_1[2] = unaff_D2;
  param_1[3] = unaff_D3;
  param_1[4] = unaff_D4;
  param_1[5] = unaff_D5;
  param_1[6] = unaff_D6;
  param_1[7] = unaff_D7;
  param_1[8] = param_1;
  param_1[9] = in_A1;
  param_1[10] = unaff_A2;
  param_1[0xb] = unaff_A3;
  param_1[0xc] = unaff_A4;
  param_1[0xd] = unaff_A5;
  param_1[0xe] = unaff_A6;
  param_1[0xf] = register0x0000003c;
  return 0;
}
/* GHIDRADEC_FUNCTION index=2543 start=0x40967aa */

void _dbg_longjmp(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[8] = param_1[0x10];
                    /* WARNING: Could not recover jumptable at 0x040967bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[8])();
  return;
}
/* GHIDRADEC_FUNCTION index=2544 start=0x40967be */

void _stack_attach(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x28) = param_2;
  *(int *)(iVar1 + 0x38) = param_2 + 0xff4;
  *(int *)(iVar1 + 0x3c) = param_2 + 0xff4;
  *(code **)(iVar1 + 0x24) = __stack_attach;
  *(undefined4 *)(iVar1 + 0x28) = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=2545 start=0x40967f2 */

undefined4 _stack_detach(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = 0;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2546 start=0x4096806 */

void _stack_handoff(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = _stack_detach(param_1);
  _stack_attach(param_2,uVar2,0);
  _active_threads = param_2;
  if ((*(int *)(param_2 + 0xc) != *(int *)(param_1 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0xc) + 8) + 0x20), iVar1 != _kernel_pmap)) {
    _pmove_crp(iVar1);
  }
  __stack_handoff(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24));
  return;
}
/* GHIDRADEC_FUNCTION index=2547 start=0x4096872 */

void _switch_context(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  _active_threads = param_3;
  _active_stacks = *(undefined4 *)(param_3 + 0x28);
  _stack_pointers = *(int *)(param_3 + 0x28) + 0xff4;
  if ((*(int *)(param_3 + 0xc) != *(int *)(param_1 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(*(int *)(param_3 + 0xc) + 8) + 0x20), iVar1 != _kernel_pmap)) {
    _pmove_crp(iVar1);
  }
  *(int *)(param_1 + 0x30) = param_2;
  if (param_2 == 0) {
    __switch_context(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 0x24),param_1);
  }
  else {
    __switch_context_discard
              (*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 0x24),param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2548 start=0x40968fa */

void _pcb_module_init(void)

{
  _pcb_zone = _zinit(0x1a0,0x34000,0x6800,0,&aPcb);
  return;
}
/* GHIDRADEC_FUNCTION index=2549 start=0x4096924 */

void _pcb_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_pcb_zone);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  _bzero(uVar1,0x1a0);
  return;
}

