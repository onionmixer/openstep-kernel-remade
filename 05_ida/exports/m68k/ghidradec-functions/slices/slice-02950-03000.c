/* GHIDRADEC_FUNCTION index=2950 start=0x404eaae */

int sub_404EAAE(undefined4 *param_1)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _PMGetPowerEvent(&uStack_8);
  if (iVar1 == 0) {
    switch(uStack_8) {
    case :
    case :
      dword_40B39C2 = 1;
      _PMSetPowerState(0x10000,1);
      break;
    case :
    case :
    case :
      dword_40B39C2 = 2;
      _PMSetPowerState(0x10000,2);
      dword_40B39C2 = 0;
      _PMSetPowerState(0x10000,0);
      break;
    case :
    case :
    case :
      if (dword_40B39C2 != 0) {
        dword_40B39C2 = 0;
        _PMSetPowerState(0x10000,0);
      }
    case :
      _PMUpdateClock();
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uStack_8;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2951 start=0x404fd9a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_404FD9A(undefined2 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  undefined auStack_3a [6];
  byte abStack_34 [2];
  undefined2 uStack_32;
  sword sStack_30;
  undefined uStack_2c;
  word wStack_2a;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined uStack_18;
  undefined uStack_17;
  sword sStack_16;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined2 uStack_a;
  sword sStack_8;
  undefined2 uStack_6;
  
  if (dword_40B3FBA == 0) {
    _kdp_panic(aKdpReply);
  }
  puVar1 = DAT_40b39ac + dword_40B3FB2;
  dword_40B3FB2 = dword_40B3FB2 + -0x1c;
  _bcopy(puVar1,&uStack_20,0x1c);
  uVar2 = uStack_14;
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_17 = 0x11;
  sStack_16 = word_40B3FB8 + 8;
  uStack_14 = uStack_10;
  uStack_10 = uVar2;
  uStack_c = 0x473;
  uStack_a = param_1;
  uStack_6 = 0;
  sStack_8 = sStack_16;
  _bcopy(&uStack_20,unk_40B39C8 + dword_40B3FB2,0x1c);
  _bcopy(unk_40B39C8 + dword_40B3FB2,abStack_34,0x14);
  uStack_32 = word_40B3FB8 + 0x1c;
  sStack_30 = _ip_id;
  _ip_id = _ip_id + 1;
  abStack_34[0] = 0x45;
  uStack_2c = byte_40AEBC7;
  wStack_2a = 0;
  iVar7 = 0;
  iVar4 = 0;
  iVar6 = 4;
  pbVar5 = abStack_34;
  do {
    iVar7 = (uint)pbVar5[3] + (uint)pbVar5[1] + iVar7;
    iVar4 = (uint)pbVar5[2] + (uint)*pbVar5 + iVar4;
    pbVar5 = pbVar5 + 4;
    bVar8 = iVar6 != 0;
    iVar6 = iVar6 + -1;
  } while (bVar8);
  uVar3 = iVar7 + iVar4 * 0x100;
  uVar3 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
  if (0xffff < uVar3) {
    uVar3 = (uint)(word)((sword)uVar3 + 1);
  }
  wStack_2a = ~(word)uVar3;
  _bcopy(abStack_34,unk_40B39C8 + dword_40B3FB2,0x14);
  iVar6 = dword_40B3FB2;
  _unk_40B3FB6 = _unk_40B3FB6 + 0x1c;
  iVar7 = (int)&dword_40B39BA + dword_40B3FB2;
  iVar4 = dword_40B3FB2 + 0x40b39c0;
  dword_40B3FB2 = dword_40B3FB2 + -0xe;
  _bcopy(iVar4,auStack_3a,6);
  _bcopy(iVar7,iVar4,6);
  _bcopy(auStack_3a,iVar7,6);
  *(undefined2 *)(&byte_40B39C6 + iVar6) = 0x800;
  _unk_40B3FB6 = _unk_40B3FB6 + 0xe;
  _bcopy(unk_40B39C8,unk_40B3FBE,0x5f6);
  _kdp_en_send_pkt(unk_40B39C8 + dword_40B3FB2,_unk_40B3FB6);
  byte_40B39C6 = byte_40B39C6 + '\x01';
  return;
}
/* GHIDRADEC_FUNCTION index=2952 start=0x404ffa6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_404FFA6(undefined2 param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  byte abStack_34 [2];
  undefined2 uStack_32;
  sword sStack_30;
  undefined uStack_2c;
  word wStack_2a;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined uStack_18;
  undefined uStack_17;
  sword sStack_16;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined2 uStack_a;
  sword sStack_8;
  undefined2 uStack_6;
  
  if (dword_40B3FBA != 0) {
    _kdp_panic(aKdpSend);
  }
  puVar1 = DAT_40b39ac + dword_40B3FB2;
  dword_40B3FB2 = dword_40B3FB2 + -0x1c;
  _bcopy(puVar1,&uStack_20,0x1c);
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_17 = 0x11;
  sStack_16 = word_40B3FB8 + 8;
  uStack_14 = _adr;
  uStack_10 = dword_40C25BE;
  uStack_c = 0x473;
  uStack_a = param_1;
  uStack_6 = 0;
  sStack_8 = sStack_16;
  _bcopy(&uStack_20,unk_40B39C8 + dword_40B3FB2,0x1c);
  _bcopy(unk_40B39C8 + dword_40B3FB2,abStack_34,0x14);
  uStack_32 = word_40B3FB8 + 0x1c;
  sStack_30 = _ip_id;
  _ip_id = _ip_id + 1;
  abStack_34[0] = 0x45;
  uStack_2c = byte_40AEBC7;
  wStack_2a = 0;
  iVar6 = 0;
  iVar3 = 0;
  iVar5 = 4;
  pbVar4 = abStack_34;
  do {
    iVar6 = (uint)pbVar4[3] + (uint)pbVar4[1] + iVar6;
    iVar3 = (uint)pbVar4[2] + (uint)*pbVar4 + iVar3;
    pbVar4 = pbVar4 + 4;
    bVar7 = iVar5 != 0;
    iVar5 = iVar5 + -1;
  } while (bVar7);
  uVar2 = iVar6 + iVar3 * 0x100;
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  if (0xffff < uVar2) {
    uVar2 = (uint)(word)((sword)uVar2 + 1);
  }
  wStack_2a = ~(word)uVar2;
  _bcopy(abStack_34,unk_40B39C8 + dword_40B3FB2,0x14);
  iVar5 = dword_40B3FB2;
  _unk_40B3FB6 = _unk_40B3FB6 + 0x1c;
  iVar6 = (int)&dword_40B39BA + dword_40B3FB2;
  iVar3 = dword_40B3FB2 + 0x40b39c0;
  dword_40B3FB2 = dword_40B3FB2 + -0xe;
  _bcopy(&unk_40C25B8,iVar3,6);
  _bcopy(&unk_40C25C2,iVar6,6);
  *(undefined2 *)(&byte_40B39C6 + iVar5) = 0x800;
  _unk_40B3FB6 = _unk_40B3FB6 + 0xe;
  _kdp_en_send_pkt(unk_40B39C8 + dword_40B3FB2,_unk_40B3FB6);
  return;
}
/* GHIDRADEC_FUNCTION index=2953 start=0x4050186 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_4050186(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  byte abStack_34 [20];
  undefined auStack_20 [9];
  char cStack_17;
  undefined4 uStack_14;
  undefined4 uStack_10;
  sword sStack_a;
  word wStack_8;
  
  if (dword_40B3FBA != 0) {
    _kdp_panic(aKdpPoll);
  }
  dword_40B3FB2 = 0;
  _kdp_en_recv_pkt(unk_40B39C8,&unk_40B3FB6,3);
  iVar3 = dword_40B3FB2;
  iVar2 = dword_40B3FB2;
  if ((_unk_40B3FB6 != 0) && (0x29 < _unk_40B3FB6)) {
    puVar1 = unk_40B39C8 + dword_40B3FB2;
    iVar2 = dword_40B3FB2 + 0xe;
    if (*(sword *)(unk_40B39C8 + dword_40B3FB2 + 0xc) == 0x800) {
      iVar2 = dword_40B3FB2 + 0x40b39d6;
      dword_40B3FB2 = dword_40B3FB2 + 0xe;
      _bcopy(iVar2,auStack_20,0x1c);
      _bcopy(unk_40B39C8 + dword_40B3FB2,abStack_34,0x14);
      dword_40B3FB2 = dword_40B3FB2 + 0x1c;
      iVar2 = dword_40B3FB2;
      if (((cStack_17 == '\x11') && ((abStack_34[0] & 0xf) < 6)) && (sStack_a == 0x473)) {
        if (dword_40C259E == 0) {
          _bcopy(puVar1,&unk_40C25B8,6);
          _adr = uStack_10;
          _bcopy(iVar3 + 0x40b39ce,&unk_40C25C2,6);
          dword_40C25BE = uStack_14;
        }
        _unk_40B3FB6 = wStack_8 - 8;
        dword_40B3FBA = 1;
        iVar2 = dword_40B3FB2;
      }
    }
  }
  dword_40B3FB2 = iVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=2954 start=0x40502a6 */

void sub_40502A6(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_e;
  byte bStack_c;
  byte bStack_b;
  
  dword_40C25A2 = param_1;
  do {
    while (dword_40B3FBA == 0) {
      sub_4050186();
    }
    _bcopy(unk_40B39C8 + dword_40B3FB2,&bStack_c,8);
    if ((bStack_c & 1) == 0) {
      if (byte_40B39C6 - 1 == (uint)bStack_b) {
        _kdp_en_send_pkt(unk_40B3FBE + dword_40B45A8,dword_40B45AC);
      }
      else if (byte_40B39C6 == bStack_b) {
        iVar1 = _kdp_packet(unk_40B39C8 + dword_40B3FB2,&unk_40B3FB6,&uStack_e);
        if (iVar1 != 0) {
          sub_404FD9A(uStack_e);
        }
      }
      else {
        _safe_prf(aKdpBadSequence,(uint)bStack_b,(uint)byte_40B39C6);
      }
    }
    dword_40B3FBA = 0;
  } while (dword_40C25A6 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2955 start=0x405038c */

void sub_405038C(void)

{
  int iVar1;
  undefined *puVar2;
  undefined2 uStack_e;
  char cStack_c;
  char cStack_b;
  
  _safe_prf(aWaitingForRemo);
  _safe_prf(aTypeCToContinu);
  byte_40B39C6 = '\0';
  do {
    while (dword_40B3FBA == 0) {
      iVar1 = _kmtrygetc();
      if (iVar1 == 99) {
        puVar2 = aContinuing_0;
        goto loc_405046C;
      }
      if (iVar1 == 0x72) {
        _safe_prf(aRebooting_0);
        _kdp_reboot();
      }
      sub_4050186();
    }
    _bcopy(unk_40B39C8 + dword_40B3FB2,&cStack_c,8);
    if (((cStack_c == '\0') && (cStack_b == byte_40B39C6)) &&
       (iVar1 = _kdp_packet(unk_40B39C8 + dword_40B3FB2,&unk_40B3FB6,&uStack_e), iVar1 != 0)) {
      sub_404FD9A(uStack_e);
    }
    dword_40B3FBA = 0;
  } while (dword_40C259E == 0);
  puVar2 = aConnectedToRem;
loc_405046C:
  _safe_prf(puVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=2956 start=0x405047c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_405047C(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined2 uStack_6;
  
  iVar2 = 300;
  do {
    dword_40B3FB2 = 0x2a;
    _kdp_exception(unk_40B39F2,&unk_40B3FB6,&uStack_6,param_1,param_2,param_3);
    sub_404FFA6(uStack_6);
    sub_4050186();
    if (dword_40B3FBA != 0) {
      _kdp_exception_ack(unk_40B39C8 + dword_40B3FB2,_unk_40B3FB6);
    }
    dword_40B3FBA = 0;
    if (dword_40C25AE == 0) {
      dword_40B3FBA = 0;
      return;
    }
    _kdp_us_spin(100000);
    if (dword_40C25AE == 0) {
      return;
    }
    wVar1 = (word)((uint)iVar2 >> 0x10);
    sVar3 = (sword)iVar2 + -1;
    iVar2 = CONCAT22(wVar1,sVar3);
  } while ((sVar3 != -1) || (iVar2 = (uint)wVar1 * 0x10000 + -1, wVar1 != 0));
  if (dword_40C25AE != 0) {
    _safe_prf(aKdpExceptionAc);
    _kdp_reset();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2957 start=0x4053f9c */

void sub_4053F9C(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar7 = _clock_value(1);
  uVar6 = (uint)((qword)uVar7 >> 0x20);
  uVar4 = (uint)uVar7;
  if (*(uint *)(param_1 + 0x14) < uVar6 ||
      *(uint *)(param_1 + 0x18) < uVar4 && *(uint *)(param_1 + 0x14) == uVar6) {
    uVar6 = 0;
    uVar5 = 0;
  }
  else {
    puVar3 = (uint *)_timer_attributes(0);
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    uVar5 = *(uint *)(param_1 + 0x18) - uVar4;
    uVar6 = *(int *)(param_1 + 0x14) - ((*(uint *)(param_1 + 0x18) < uVar4) + uVar6);
    if ((uVar1 <= uVar6 && (uVar5 >= uVar2 || uVar6 != uVar1)) &&
        (uVar6 != (uVar5 < uVar2) + uVar1 || uVar5 != uVar2)) {
      uVar6 = uVar1;
      uVar5 = uVar2;
    }
  }
  _set_timer(0,uVar6,uVar5);
  return;
}
/* GHIDRADEC_FUNCTION index=2958 start=0x4054012 */

undefined4 sub_4054012(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  puVar2 = dword_40B4DC0;
  if ((undefined4 **)dword_40B4DC0 != &dword_40B4DC0) {
    do {
      if ((param_1 == puVar2[2]) && (param_2 == puVar2[3])) {
        puVar3 = (undefined4 *)*puVar2;
        puVar3[1] = puVar2[1];
        *(undefined4 *)puVar2[1] = *puVar2;
        dword_40B4DD0 = dword_40B4DD0 + -1;
        puVar2[7] = 0;
        if ((&DAT_40b45b3 < puVar2) && (puVar2 < &DAT_40b4db4)) {
          *puVar2 = &dword_40B4DB8;
          puVar2[1] = dword_40B4DBC;
          *(undefined4 **)puVar2[1] = puVar2;
          dword_40B4DBC = puVar2;
        }
        uVar1 = 1;
        if (param_3 == 0) {
          return 1;
        }
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar2 = puVar3;
    } while ((undefined4 **)puVar3 != &dword_40B4DC0);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2959 start=0x405409e */

undefined4 sub_405409E(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  puVar2 = dword_40B4DC8;
  if ((undefined4 **)dword_40B4DC8 != &dword_40B4DC8) {
    do {
      if ((param_1 == puVar2[2]) && (param_2 == puVar2[3])) {
        puVar3 = (undefined4 *)*puVar2;
        puVar3[1] = puVar2[1];
        *(undefined4 *)puVar2[1] = *puVar2;
        puVar2[7] = 0;
        if ((&DAT_40b45b3 < puVar2) && (puVar2 < &DAT_40b4db4)) {
          *puVar2 = &dword_40B4DB8;
          puVar2[1] = dword_40B4DBC;
          *(undefined4 **)puVar2[1] = puVar2;
          dword_40B4DBC = puVar2;
        }
        uVar1 = 1;
        if (param_3 == 0) {
          return 1;
        }
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar2 = puVar3;
    } while ((undefined4 **)puVar3 != &dword_40B4DC8);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2960 start=0x4054786 */

void sub_4054786(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = dword_40B4DD8;
  iVar1 = dword_40B4DD0 + dword_40B4DD4;
  _thread_wakeup_prim(&dword_40B4DD0,1,0);
  if (iVar2 < iVar1) {
    _thread_wakeup_prim(&dword_40B4DD8,1,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2961 start=0x40547dc */

void sub_40547DC(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar3 = _active_threads;
  while (0 < dword_40B4DD0) {
    if ((int **)dword_40B4DC0 == &dword_40B4DC0) {
      piVar5 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_40B4DC0 + 4) = &dword_40B4DC0;
      piVar5 = dword_40B4DC0;
      dword_40B4DC0 = (int *)*dword_40B4DC0;
    }
    dword_40B4DD0 = dword_40B4DD0 + -1;
    pcVar1 = (code *)piVar5[2];
    iVar2 = piVar5[3];
    piVar5[7] = 0;
    piVar4 = piVar5;
    if ((&DAT_40b45b3 < piVar5) && (piVar5 < &DAT_40b4db4)) {
      *piVar5 = (int)&dword_40B4DB8;
      piVar5[1] = (int)dword_40B4DBC;
      *(int **)piVar5[1] = piVar5;
      piVar4 = (int *)0x0;
      dword_40B4DBC = piVar5;
    }
    dword_40B4DD4 = dword_40B4DD4 + 1;
    (*pcVar1)(iVar2,piVar4);
    dword_40B4DD4 = dword_40B4DD4 + -1;
  }
  if (dword_40B4DD8 - dword_40B4DD4 < 5) {
    _assert_wait(&dword_40B4DD0,0);
    _thread_block_with_continuation(sub_40547DC);
  }
  dword_40B4DD8 = dword_40B4DD8 + -1;
  _thread_terminate(uVar3);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=2962 start=0x40548dc */

void sub_40548DC(void)

{
  _stack_privilege(_active_threads);
  sub_40547DC();
  return;
}
/* GHIDRADEC_FUNCTION index=2963 start=0x40548f6 */

void sub_40548F6(void)

{
  if (dword_40B4DD8 < dword_40B4DD0 + dword_40B4DD4) {
    dword_40B4DD8 = dword_40B4DD8 + 1;
    _kernel_thread(*(undefined4 *)(_active_threads + 0xc),sub_40548DC,0);
    _thread_block_with_continuation(sub_40548F6);
  }
  _assert_wait(&dword_40B4DD8,0);
  _thread_block_with_continuation(sub_40548F6);
  return;
}
/* GHIDRADEC_FUNCTION index=2964 start=0x405497e */

byte sub_405497E(void)

{
  int ****ppppiVar1;
  int ****ppppiVar2;
  int *****pppppiVar3;
  int iVar4;
  int *****pppppiVar5;
  int ****ppppiVar6;
  int ****ppppiVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  undefined8 uVar11;
  int ****appppiStack_c [2];
  
  uVar11 = _clock_value(1);
  ppppiVar6 = (int ****)((qword)uVar11 >> 0x20);
  ppppiVar7 = (int ****)uVar11;
  appppiStack_c[0] = (int ****)appppiStack_c;
  appppiStack_c[1] = appppiStack_c[0];
  if ((int ******)dword_40B4DC8 != &dword_40B4DC8) {
    do {
      pppppiVar3 = dword_40B4DC8;
      ppppiVar1 = dword_40B4DC8[5];
      ppppiVar2 = dword_40B4DC8[6];
      if ((ppppiVar6 <= ppppiVar1 && (ppppiVar2 >= ppppiVar7 || ppppiVar1 != ppppiVar6)) &&
          (ppppiVar1 != (int ****)((uint)(ppppiVar2 < ppppiVar7) + (int)ppppiVar6) ||
          ppppiVar2 != ppppiVar7)) break;
      (*dword_40B4DC8)[1] = (int ***)dword_40B4DC8[1];
      *pppppiVar3[1] = (int ***)*pppppiVar3;
      pppppiVar3[7] = (int ****)0x0;
      *pppppiVar3 = (int ****)appppiStack_c;
      pppppiVar3[1] = appppiStack_c[1];
      *pppppiVar3[1] = (int ***)pppppiVar3;
      appppiStack_c[1] = (int ****)pppppiVar3;
    } while ((int ******)dword_40B4DC8 != &dword_40B4DC8);
    if ((int ******)dword_40B4DC8 != &dword_40B4DC8) {
      sub_4053F9C(dword_40B4DC8);
    }
  }
  pppppiVar3 = appppiStack_c;
  while( true ) {
    ppppiVar6 = appppiStack_c[0];
    bVar9 = SBORROW4((int)pppppiVar3,(int)appppiStack_c[0]);
    iVar4 = (int)pppppiVar3 - (int)appppiStack_c[0];
    bVar10 = pppppiVar3 < appppiStack_c[0];
    if (pppppiVar3 == (int *****)appppiStack_c[0]) break;
    (*appppiStack_c[0])[1] = (int **)pppppiVar3;
    bVar9 = false;
    bVar10 = false;
    iVar4 = 0;
    if ((int *****)appppiStack_c[0] == (int *****)0x0) break;
    pppppiVar5 = (int *****)*appppiStack_c[0];
    *appppiStack_c[0] = (int ***)&dword_40B4DC0;
    appppiStack_c[0] = (int ****)pppppiVar5;
    ppppiVar6[1] = (int ***)dword_40B4DC4;
    *ppppiVar6[1] = (int **)ppppiVar6;
    iVar4 = dword_40B4DD8;
    dword_40B4DC4 = (int *****)ppppiVar6;
    ppppiVar6[7] = (int ***)0x1;
    iVar8 = dword_40B4DD4 + dword_40B4DD0 + 1;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    _thread_wakeup_prim(&dword_40B4DD0,1,0);
    if (iVar4 < iVar8) {
      _thread_wakeup_prim(&dword_40B4DD8,1,0);
    }
  }
  return (pppppiVar3 < appppiStack_c[0]) << 4 | (iVar4 < 0) << 3 | 4U | bVar9 << 1 | bVar10;
}
/* GHIDRADEC_FUNCTION index=2965 start=0x4054d62 */

void sub_4054D62(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = (uint)param_2[1] >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  piVar3 = (int *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
  if (param_2 == (undefined4 *)*piVar3) {
    if ((int)uVar2 < (int)uVar1) {
      for (puVar4 = (undefined4 *)*param_2;
          (puVar4 != (undefined4 *)0x0 && (param_2[1] != puVar4[1])); puVar4 = (undefined4 *)*puVar4
          ) {
      }
    }
    else {
      puVar4 = (undefined4 *)*param_2;
      if (puVar4 != (undefined4 *)0x0) {
        do {
          if (*(uint *)(param_1 + 4) <= (uint)puVar4[1]) break;
          puVar4 = (undefined4 *)*puVar4;
        } while (puVar4 != (undefined4 *)0x0);
      }
    }
    *piVar3 = (int)puVar4;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2966 start=0x4054dd6 */

void sub_4054DD6(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = (uint)param_2[1] >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  uVar3 = param_3 >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar3) {
    uVar3 = uVar1;
  }
  piVar4 = (int *)(uVar3 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
  if (uVar2 == uVar3) {
    if (param_4 != *piVar4) {
      return;
    }
  }
  else {
    if (param_4 == *piVar4) {
      if ((int)uVar3 < (int)uVar1) {
        for (puVar5 = (undefined4 *)*param_2;
            (puVar5 != (undefined4 *)0x0 && (param_3 != puVar5[1])); puVar5 = (undefined4 *)*puVar5)
        {
        }
      }
      else {
        puVar5 = (undefined4 *)*param_2;
        if (puVar5 != (undefined4 *)0x0) {
          do {
            if (*(uint *)(param_1 + 4) <= (uint)puVar5[1]) break;
            puVar5 = (undefined4 *)*puVar5;
          } while (puVar5 != (undefined4 *)0x0);
        }
      }
      *piVar4 = (int)puVar5;
    }
    piVar4 = (int *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
    if (((undefined4 *)*piVar4 != (undefined4 *)0x0) && ((undefined4 *)*piVar4 <= param_2)) {
      return;
    }
  }
  *piVar4 = (int)param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2967 start=0x4054e7e */

void sub_4054E7E(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = (uint)param_2[1] >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  uVar3 = param_3 >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar3) {
    uVar3 = uVar1;
  }
  if (uVar2 != uVar3) {
    piVar4 = (int *)(uVar3 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
    if (param_2 == (undefined4 *)*piVar4) {
      if ((int)uVar3 < (int)uVar1) {
        for (puVar6 = (undefined4 *)*param_2;
            (puVar6 != (undefined4 *)0x0 && (param_3 != puVar6[1])); puVar6 = (undefined4 *)*puVar6)
        {
        }
      }
      else {
        puVar6 = (undefined4 *)*param_2;
        if (puVar6 != (undefined4 *)0x0) {
          do {
            if (*(uint *)(param_1 + 4) <= (uint)puVar6[1]) break;
            puVar6 = (undefined4 *)*puVar6;
          } while (puVar6 != (undefined4 *)0x0);
        }
      }
      *piVar4 = (int)puVar6;
    }
    puVar5 = (undefined4 *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
    puVar6 = (undefined4 *)*puVar5;
    if ((puVar6 == (undefined4 *)0x0) || (param_2 < puVar6)) {
      *puVar5 = param_2;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2968 start=0x4054f1c */

int * sub_4054F1C(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_2 <= (uint)piVar3[1]) {
    sub_4054D62(param_1,piVar3);
    return piVar3;
  }
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = param_2 >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  piVar3 = (int *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
  if ((int)uVar2 < (int)uVar1) {
    do {
      piVar5 = (int *)*piVar3;
      if (piVar5 != (int *)0x0) {
        piVar4 = (int *)*piVar5;
        if (piVar4 == (int *)0x0) goto loc_4054FD4;
        goto loc_4054F82;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 4;
    } while ((int)uVar2 < *(int *)(param_1 + 0x18));
  }
  piVar5 = (int *)*piVar3;
  if (piVar5 == (int *)0x0) {
    return (int *)0x0;
  }
  if ((uint)piVar5[1] < param_2) {
    piVar5 = (int *)*piVar5;
    while( true ) {
      if (piVar5 == (int *)0x0) {
        return (int *)0x0;
      }
      if (param_2 <= (uint)piVar5[1]) break;
      piVar5 = (int *)*piVar5;
    }
    return piVar5;
  }
  piVar4 = (int *)*piVar5;
  if (piVar4 != (int *)0x0) {
    do {
      if (*(uint *)(param_1 + 4) <= (uint)piVar4[1]) break;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
  }
loc_4054FD4:
  *piVar3 = (int)piVar4;
  return piVar5;
  while (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0) {
loc_4054F82:
    if (piVar5[1] == piVar4[1]) break;
  }
  goto loc_4054FD4;
}
/* GHIDRADEC_FUNCTION index=2969 start=0x40556d0 */

uint * sub_40556D0(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  
  if (_zone_free_space_count < 8) {
    puVar1 = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    puVar2 = (uint *)_zget_space(&__zone_default_space,0x1c,0);
    *puVar2 = param_1;
    puVar2[1] = param_2;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
      puVar2[4] = puVar2[4] + 1;
    }
    uVar3 = puVar2[1] >> (puVar2[4] & 0x3f);
    puVar2[6] = uVar3;
    uVar3 = _zget_space(&__zone_default_space,uVar3 << 4,0);
    puVar2[5] = uVar3;
    _bzero(uVar3,puVar2[6] << 4);
    *puVar1 = puVar2;
  }
  else {
    puVar2 = (uint *)0x0;
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=2970 start=0x405577e */

void sub_405577E(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = unk_40C2BD4;
  if ((*(int *)(param_1 + 0x10) == 0) && (iVar3 = 1, 1 < _zone_free_space_count)) {
    do {
      iVar1 = **(int **)puVar4;
      uVar2 = -iVar1 & iVar1 + *(int *)(param_1 + 0x18) + -1;
      if (uVar2 <= (uint)(*(int **)puVar4)[1]) {
        *(uint *)(param_1 + 0x18) = uVar2;
        *(int *)(param_1 + 0x32) = *(int *)puVar4;
        return;
      }
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < _zone_free_space_count);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2971 start=0x405589e */

/* WARNING: Type propagation algorithm not settling */

uint * sub_405589E(uint *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char in_XF;
  bool bVar5;
  uint *puStack_8;
  
  if (param_1 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aZallocNullZone);
  }
  bVar5 = *(char *)(param_1 + 10) < '\0';
  if (bVar5) {
    _lock_write((int)param_1 + 0x2a);
  }
  else {
    bVar3 = in_XF << 4;
    in_XF = '\0';
    *param_1 = (int)(sword)(word)(byte)(bVar3 | bVar5 << 3 | (*(char *)(param_1 + 10) == '\0') << 2)
    ;
  }
  puStack_8 = (uint *)param_1[3];
  do {
    if (puStack_8 == (uint *)0x0) goto loc_40558EA;
    param_1[1] = param_1[1] + 1;
    param_1[3] = *puStack_8;
    in_XF = puStack_8 < (uint *)param_1[2];
    if (puStack_8 == (uint *)param_1[2]) {
      param_1[2] = 0;
    }
    while( true ) {
      if (puStack_8 != (uint *)0x0) goto loc_4055B30;
loc_40558EA:
      if (param_1[8] == 0) break;
      if (param_2 == 0) {
        if (-1 < *(char *)(param_1 + 10)) {
          return (uint *)0x0;
        }
        _lock_done((int)param_1 + 0x2a);
        return (uint *)0x0;
      }
      _assert_wait(param_1 + 8,1);
      if (*(char *)(param_1 + 10) < '\0') {
        _lock_done((int)param_1 + 0x2a);
      }
      else {
        in_XF = (*param_1 & 0x10) != 0;
      }
      _thread_block_with_continuation(0);
      if (*(char *)(param_1 + 10) < '\0') {
        _lock_write((int)param_1 + 0x2a);
      }
      else {
        bVar3 = in_XF << 4;
        in_XF = '\0';
        *param_1 = (int)(sword)(word)(byte)(bVar3 | (*(char *)(param_1 + 10) == '\0') << 2);
      }
    }
    if (*(char *)(param_1 + 10) < '\0') {
      uVar1 = param_1[7];
    }
    else {
      uVar1 = param_1[6];
    }
    in_XF = param_1[5] < uVar1 + param_1[4];
    if ((bool)in_XF) {
      bVar3 = *(byte *)(param_1 + 10);
      if ((bVar3 & 0x20) != 0) {
loc_4055B30:
        cVar2 = *(char *)(param_1 + 10);
        goto joined_r0x04055b34;
      }
      if ((bVar3 & 0x10) == 0) {
        if (_zone_ignore_overflow == 0) {
          if ((char)bVar3 < '\0') {
            _lock_done((int)param_1 + 0x2a);
          }
          if (param_2 == 0) {
            return (uint *)0x0;
          }
          _printf(aZoneSEmpty,param_1[9]);
                    /* WARNING: Subroutine does not return */
          _panic(&aZalloc);
        }
      }
      else {
        uVar1 = param_1[5];
        in_XF = CARRY4(uVar1 >> 1,uVar1);
        param_1[5] = (uVar1 >> 1) + uVar1;
      }
    }
    if ((*(char *)(param_1 + 10) < '\0') && (param_1[8] = 1, *(char *)(param_1 + 10) < '\0')) {
      _lock_done((int)param_1 + 0x2a);
    }
    else {
      in_XF = (*param_1 & 0x10) != 0;
    }
    if (-1 < *(char *)(param_1 + 10)) {
      puStack_8 = (uint *)_zget_space(*(undefined4 *)((int)param_1 + 0x32),param_1[6],param_2);
      if (puStack_8 == (uint *)0x0) {
        if (param_2 == 0) {
          return (uint *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        _panic(&aZalloc);
      }
      if (*(char *)(param_1 + 10) < '\0') {
        _lock_write((int)param_1 + 0x2a);
      }
      else {
        *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | (*(char *)(param_1 + 10) == '\0') << 2);
      }
      param_1[1] = param_1[1] + 1;
      param_1[4] = param_1[6] + param_1[4];
      cVar2 = *(char *)(param_1 + 10);
joined_r0x04055b34:
      if (-1 < cVar2) {
        return puStack_8;
      }
      _lock_done((int)param_1 + 0x2a);
      return puStack_8;
    }
    iVar4 = _kmem_alloc_pageable(_zone_map,&puStack_8,param_1[7]);
    if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aZalloc);
    }
    _zcram(param_1,puStack_8,param_1[7]);
    if (*(char *)(param_1 + 10) < '\0') {
      _lock_write((int)param_1 + 0x2a);
    }
    else {
      bVar3 = in_XF << 4;
      in_XF = '\0';
      *param_1 = (int)(sword)(word)(byte)(bVar3 | (*(char *)(param_1 + 10) == '\0') << 2);
    }
    param_1[8] = 0;
    _thread_wakeup_prim(param_1 + 8,0,0);
    puStack_8 = (uint *)param_1[3];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2972 start=0x40568a0 */

undefined4 sub_40568A0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    uVar1 = (**(code **)(param_2 + 4))(param_1,*(undefined4 *)(param_2 + 8));
  }
  else {
    iVar2 = _kalloc(0x2000);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 8);
    (**(code **)(param_2 + 4))(param_1,iVar2);
    if (*(int *)(iVar2 + 0x1c) == -0x131) {
      uVar1 = 0;
    }
    else {
      uVar1 = _msg_send(iVar2,0,0);
    }
    _kfree(iVar2,0x2000);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2973 start=0x405691c */

int sub_405691C(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_2 + 0x4b4);
  iVar4 = -200;
  if (param_2 == 0) {
    return -0x12f;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == *(int *)(param_2 + 0x4ac)) {
    iVar4 = -0x12f;
  }
  else {
    if (iVar1 != *(int *)(param_2 + 0x4b0)) {
      iVar2 = 0;
      iVar3 = param_2;
      do {
        if (iVar1 == *(int *)(iVar3 + 0x18c)) break;
        iVar3 = iVar3 + 0x10;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x32);
      if (iVar2 == 0x32) goto loc_4056990;
      *(int *)(param_2 + 0x4b0) = iVar1;
      *(int *)(param_2 + 0x4b4) = iVar2;
    }
    iVar4 = sub_40568A0(param_1,param_2 + iVar2 * 0x10 + 0x18c);
  }
loc_4056990:
  if (iVar4 == -200) {
    *(undefined4 *)(param_2 + 0x4ac) = *(undefined4 *)(param_1 + 0xc);
    iVar4 = -0x12f;
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2974 start=0x4056f98 */

undefined8 sub_4056F98(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 extraout_D0u;
  undefined4 uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  uVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
  uVar4 = ~_page_mask;
  uVar2 = uVar4 & _page_mask + uVar3;
  bVar10 = CARRY4(_page_mask,uVar3) << 4 | ((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2;
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 0;
  uVar5 = CONCAT22((sword)(uVar4 >> 0x10),4);
  if (iVar1 != 0) {
    _vm_read_EXTERNAL(*(undefined4 *)(param_1 + 0x4cc),*(undefined4 *)(param_1 + 0x24),uVar2,
                      &uStack_8,auStack_c);
    uVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
    cVar6 = (uVar3 >> 4 & 1) != 0;
    _kern_serv_log_data(iVar1,uStack_8,(int)uVar3 >> 5);
    _port_deallocate_EXTERNAL(*(undefined4 *)(param_1 + 8),iVar1);
    iVar1 = *(int *)(param_1 + 8);
    cVar7 = iVar1 < 0;
    cVar8 = iVar1 == 0;
    cVar9 = '\0';
    bVar10 = 0;
    _vm_deallocate_EXTERNAL(iVar1,uStack_8,uVar2);
    bVar10 = cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10;
    iVar1 = *(int *)(param_1 + 0x24);
    *(int *)(param_1 + 0x28) = iVar1;
    uVar5 = CONCAT22(extraout_D0u,(word)(byte)((iVar1 < 0) << 3 | (iVar1 == 0) << 2));
  }
  return CONCAT44(uVar5,(int)(sword)(word)bVar10);
}
/* GHIDRADEC_FUNCTION index=2975 start=0x4057042 */

void sub_4057042(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = ~_page_mask & _page_mask + param_2 * 0x20;
  iVar2 = _kalloc(uVar1);
  *param_1 = iVar2;
  param_1[2] = (uVar1 & 0xffffffe0) + iVar2;
  param_1[1] = *param_1;
  _printf(aKernServLogIni,param_1,param_1[2],*param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2976 start=0x405709e */

void sub_405709E(int *param_1)

{
  _kfree(*param_1,~_page_mask & _page_mask + (param_1[2] - *param_1));
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2977 start=0x405718e */

void sub_405718E(int param_1)

{
  _send_notification(*(undefined4 *)(param_1 + 0xc),0x42,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2978 start=0x4057404 */

void sub_4057404(undefined4 param_1,undefined4 param_2)

{
  _printf(aNotificationSe,param_2,param_1);
                    /* WARNING: Subroutine does not return */
  _panic(aNotificationSe_0);
}
/* GHIDRADEC_FUNCTION index=2979 start=0x405742c */

void sub_405742C(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x14) == 0x76543) {
    puVar1 = (undefined4 *)_kalloc(0x14);
    puVar1[2] = *(undefined4 *)(param_1 + 0x1c);
    puVar1[3] = *(undefined4 *)(param_1 + 0x20);
    puVar1[4] = *(undefined4 *)(param_1 + 0x28);
    *dword_40B4DEC = puVar1;
    puVar1[1] = dword_40B4DEC;
    *puVar1 = &dword_40B4DE8;
    dword_40B4DEC = puVar1;
  }
  else {
    _printf(aNotifyServerBo,*(int *)(param_1 + 0x14));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2980 start=0x4057498 */

void sub_4057498(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  puVar1 = dword_40B4DE8;
  if (*(int *)(param_1 + 0x14) == 0x41) {
joined_r0x040574ce:
    puVar4 = puVar1;
    if ((undefined4 **)puVar4 != &dword_40B4DE8) {
      puVar1 = (undefined4 *)*puVar4;
      if (puVar4[3] != *(int *)(param_1 + 0x1c)) goto loc_40574FE;
      puVar2 = (undefined4 *)puVar4[1];
      puVar3 = puVar2;
      if ((undefined4 **)puVar1 != &dword_40B4DE8) {
        puVar1[1] = puVar2;
        puVar3 = dword_40B4DEC;
      }
      dword_40B4DEC = puVar3;
      *puVar2 = puVar1;
      goto loc_4057566;
    }
    if (iVar7 == 0) {
      _printf(aPnNotifyPortNo);
    }
  }
  else {
    _printf(aPnNotifyMsgIdD,*(int *)(param_1 + 0x14));
  }
  return;
loc_40574FE:
  if (*(int *)(param_1 + 0x1c) == puVar4[2]) {
    *(undefined4 *)(param_1 + 0x10) = puVar4[3];
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined *)(param_1 + 3) = 1;
    *(undefined *)(param_1 + 0x18) = 2;
    *(undefined *)(param_1 + 0x19) = 0x20;
    *(undefined4 *)(param_1 + 0x1c) = puVar4[4];
    iVar6 = _msg_send(param_1,1,0);
    if (iVar6 != 0) {
      _printf(aPnNotifyMsgSen,iVar6);
    }
    puVar2 = (undefined4 *)*puVar4;
    puVar3 = (undefined4 *)puVar4[1];
    puVar5 = puVar3;
    if ((undefined4 **)puVar2 != &dword_40B4DE8) {
      puVar2[1] = puVar3;
      puVar5 = dword_40B4DEC;
    }
    dword_40B4DEC = puVar5;
    *puVar3 = puVar2;
loc_4057566:
    _kfree(puVar4,0x14);
    iVar7 = iVar7 + 1;
  }
  goto joined_r0x040574ce;
}
/* GHIDRADEC_FUNCTION index=2981 start=0x4058090 */

void sub_4058090(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) == 0x40) && (*(char *)(param_1 + 3) == '\0')) {
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (((*(int *)(param_1 + 0x20) == 0x6200018 && (*(int *)(param_1 + 0x28) == 0x2200018)) &&
         (*(int *)(param_1 + 0x30) == 0x2200018)))) && (*(int *)(param_1 + 0x38) == 0x2200018)) {
      uVar1 = _catch_exception_raise
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                         *(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x2c),
                         *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x3c));
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2982 start=0x405b7d2 */

void sub_405B7D2(int *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint uStack_7f4;
  undefined *puStack_7f0;
  uint uStack_7ec;
  byte *pbStack_7e8;
  undefined auStack_7e4 [2016];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_40B0594)) &&
     (param_1[8] == dword_40B0598)) {
    pbVar1 = param_2 + 0x2c;
    uStack_7ec = 0x19;
    if ((uint)param_1[7] < 0x19) {
      uStack_7ec = param_1[7];
    }
    puVar2 = auStack_7e4;
    uStack_7f4 = 0x38;
    if ((uint)param_1[9] < 0x38) {
      uStack_7f4 = param_1[9];
    }
    puStack_7f0 = puVar2;
    pbStack_7e8 = pbVar1;
    uVar3 = _convert_port_to_host(param_1[2],&pbStack_7e8,&uStack_7ec,&puStack_7f0,&uStack_7f4);
    iVar4 = _host_zone_info(uVar3);
    *(int *)(param_2 + 0x1c) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_40B059C;
      *(undefined4 *)(param_2 + 0x24) = dword_40B05A0;
      *(undefined4 *)(param_2 + 0x28) = dword_40B05A4;
      bVar5 = pbVar1 != pbStack_7e8;
      if (bVar5) {
        param_2[0x23] = param_2[0x23] & 0xf7 | 2;
        *(byte **)pbVar1 = pbStack_7e8;
      }
      *(uint *)(param_2 + 0x28) = uStack_7ec * 0x50;
      iVar4 = 4;
      if ((param_2[0x23] & 8) != 0) {
        iVar4 = uStack_7ec * 0x50;
      }
      *(undefined4 *)(param_2 + iVar4 + 0x2c) = dword_40B05A8;
      *(undefined4 *)(param_2 + iVar4 + 0x30) = dword_40B05AC;
      *(undefined4 *)(param_2 + iVar4 + 0x34) = dword_40B05B0;
      bVar6 = puVar2 == puStack_7f0;
      if (bVar6) {
        _bcopy(puStack_7f0,param_2 + iVar4 + 0x38,uStack_7f4 * 0x24);
      }
      else {
        param_2[iVar4 + 0x2f] = param_2[iVar4 + 0x2f] & 0xf7 | 2;
        *(undefined **)(param_2 + iVar4 + 0x38) = puStack_7f0;
      }
      *(uint *)(param_2 + iVar4 + 0x34) = uStack_7f4 * 9;
      if ((param_2[iVar4 + 0x2f] & 8) == 0) {
        iVar4 = iVar4 + 0x3c;
      }
      else {
        iVar4 = iVar4 + 0x38 + uStack_7f4 * 0x24;
      }
      if (!bVar6 || bVar5) {
        *param_2 = *param_2 | 0x80;
      }
      *(int *)(param_2 + 4) = iVar4;
    }
  }
  else {
    param_2[0x1c] = 0xff;
    param_2[0x1d] = 0xff;
    param_2[0x1e] = 0xfe;
    param_2[0x1f] = 0xd0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2983 start=0x405b960 */

void sub_405B960(int *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint uStack_814;
  undefined *puStack_810;
  uint uStack_80c;
  byte *pbStack_808;
  undefined auStack_804 [2048];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_40B05B4)) &&
     (param_1[8] == dword_40B05B8)) {
    pbVar1 = param_2 + 0x2c;
    uStack_80c = 0xaa;
    if ((uint)param_1[7] < 0xaa) {
      uStack_80c = param_1[7];
    }
    puVar2 = auStack_804;
    uStack_814 = 0x100;
    if ((uint)param_1[9] < 0x100) {
      uStack_814 = param_1[9];
    }
    puStack_810 = puVar2;
    pbStack_808 = pbVar1;
    uVar3 = _convert_port_to_host(param_1[2],&pbStack_808,&uStack_80c,&puStack_810,&uStack_814);
    iVar4 = _host_zone_free_space_info(uVar3);
    *(int *)(param_2 + 0x1c) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_40B05BC;
      *(undefined4 *)(param_2 + 0x24) = dword_40B05C0;
      *(undefined4 *)(param_2 + 0x28) = dword_40B05C4;
      bVar5 = pbVar1 != pbStack_808;
      if (bVar5) {
        param_2[0x23] = param_2[0x23] & 0xf7 | 2;
        *(byte **)pbVar1 = pbStack_808;
      }
      *(uint *)(param_2 + 0x28) = uStack_80c * 3;
      iVar4 = 4;
      if ((param_2[0x23] & 8) != 0) {
        iVar4 = uStack_80c * 0xc;
      }
      *(undefined4 *)(param_2 + iVar4 + 0x2c) = dword_40B05C8;
      *(undefined4 *)(param_2 + iVar4 + 0x30) = dword_40B05CC;
      *(undefined4 *)(param_2 + iVar4 + 0x34) = dword_40B05D0;
      bVar6 = puVar2 == puStack_810;
      if (bVar6) {
        _bcopy(puStack_810,param_2 + iVar4 + 0x38,uStack_814 << 3);
      }
      else {
        param_2[iVar4 + 0x2f] = param_2[iVar4 + 0x2f] & 0xf7 | 2;
        *(undefined **)(param_2 + iVar4 + 0x38) = puStack_810;
      }
      *(uint *)(param_2 + iVar4 + 0x34) = uStack_814 * 2;
      if ((param_2[iVar4 + 0x2f] & 8) == 0) {
        iVar4 = iVar4 + 0x3c;
      }
      else {
        iVar4 = iVar4 + 0x38 + uStack_814 * 8;
      }
      if (!bVar6 || bVar5) {
        *param_2 = *param_2 | 0x80;
      }
      *(int *)(param_2 + 4) = iVar4;
    }
  }
  else {
    param_2[0x1c] = 0xff;
    param_2[0x1d] = 0xff;
    param_2[0x1e] = 0xfe;
    param_2[0x1f] = 0xd0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2984 start=0x405bd24 */

void sub_405BD24(int *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  uint uStack_7fc;
  undefined *puStack_7f8;
  uint uStack_7f4;
  byte *pbStack_7f0;
  undefined auStack_7ec [2024];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_40B0600)) &&
     (param_1[8] == dword_40B0604)) {
    uVar3 = _convert_port_to_space(param_1[2]);
    pbVar1 = param_2 + 0x48;
    uStack_7f4 = 0x38;
    if ((uint)param_1[7] < 0x38) {
      uStack_7f4 = param_1[7];
    }
    puVar2 = auStack_7ec;
    uStack_7fc = 0x2e;
    if ((uint)param_1[9] < 0x2e) {
      uStack_7fc = param_1[9];
    }
    puStack_7f8 = puVar2;
    pbStack_7f0 = pbVar1;
    uVar4 = _mach_port_space_info
                      (uVar3,param_2 + 0x24,&pbStack_7f0,&uStack_7f4,&puStack_7f8,&uStack_7fc);
    *(undefined4 *)(param_2 + 0x1c) = uVar4;
    _space_deallocate(uVar3);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_40B0608;
      *(undefined4 *)(param_2 + 0x3c) = dword_40B060C;
      *(undefined4 *)(param_2 + 0x40) = dword_40B0610;
      *(undefined4 *)(param_2 + 0x44) = dword_40B0614;
      bVar6 = pbVar1 != pbStack_7f0;
      if (bVar6) {
        param_2[0x3f] = param_2[0x3f] & 0xf7 | 2;
        *(byte **)pbVar1 = pbStack_7f0;
      }
      *(uint *)(param_2 + 0x44) = uStack_7f4 * 9;
      iVar5 = 4;
      if ((param_2[0x3f] & 8) != 0) {
        iVar5 = uStack_7f4 * 0x24;
      }
      *(undefined4 *)(param_2 + iVar5 + 0x48) = dword_40B0618;
      *(undefined4 *)(param_2 + iVar5 + 0x4c) = dword_40B061C;
      *(undefined4 *)(param_2 + iVar5 + 0x50) = dword_40B0620;
      bVar7 = puVar2 == puStack_7f8;
      if (bVar7) {
        _bcopy(puStack_7f8,param_2 + iVar5 + 0x54,uStack_7fc * 0x2c);
      }
      else {
        param_2[iVar5 + 0x4b] = param_2[iVar5 + 0x4b] & 0xf7 | 2;
        *(undefined **)(param_2 + iVar5 + 0x54) = puStack_7f8;
      }
      *(uint *)(param_2 + iVar5 + 0x50) = uStack_7fc * 0xb;
      if ((param_2[iVar5 + 0x4b] & 8) == 0) {
        iVar5 = iVar5 + 0x58;
      }
      else {
        iVar5 = iVar5 + 0x54 + uStack_7fc * 0x2c;
      }
      if (!bVar7 || bVar6) {
        *param_2 = *param_2 | 0x80;
      }
      *(int *)(param_2 + 4) = iVar5;
    }
  }
  else {
    param_2[0x1c] = 0xff;
    param_2[0x1d] = 0xff;
    param_2[0x1e] = 0xfe;
    param_2[0x1f] = 0xd0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2985 start=0x405c12e */

void sub_405C12E(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_8c [4];
  undefined4 uStack_88;
  undefined4 uStack_80;
  int iStack_7c;
  undefined auStack_34 [40];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  *(undefined4 *)(iVar2 + 0x48) = 1;
  dword_40B4DF0 = _task_self();
  iVar1 = _port_set_allocate_EXTERNAL(dword_40B4DF0,&uStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerPortS);
  }
  iVar1 = _port_allocate_EXTERNAL(dword_40B4DF0,&uStack_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerPortA);
  }
  iVar1 = _port_set_add_EXTERNAL(dword_40B4DF0,uStack_8,uStack_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerPortS_0);
  }
  iVar2 = _object_copyin(iVar2,uStack_c,6,0,&_ux_exception_port);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aUxHandlerObjec);
  }
  _thread_wakeup_prim(&_ux_exception_port,0,0);
  _task_name(aUxExcept);
  do {
    while( true ) {
      uStack_80 = uStack_8;
      uStack_88 = 0x58;
      iVar1 = _msg_receive(auStack_8c,0,0);
      iVar2 = iStack_7c;
      if (iVar1 != 0) break;
      iVar1 = _exc_server(auStack_8c,auStack_34);
      if (iVar1 != 0) {
        _msg_send(auStack_34,0,0);
      }
      if (iVar2 != 0) {
        _port_deallocate_EXTERNAL(dword_40B4DF0,iVar2);
      }
    }
  } while (iVar1 == -0xcc);
                    /* WARNING: Subroutine does not return */
  _panic(aExceptionHandl);
}
/* GHIDRADEC_FUNCTION index=2986 start=0x405c390 */

void sub_405C390(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _machine_exception(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    switch(param_1) {
    case :
      if (param_2 == 1) {
        uVar2 = 0xb;
      }
      else {
        uVar2 = 10;
      }
      break;
    case :
      uVar2 = 4;
      break;
    case :
      uVar2 = 8;
      break;
    case :
      uVar2 = 7;
      break;
    case :
      if (param_2 == 0x10001) {
        uVar2 = 0xd;
      }
      else if (param_2 < 0x10002) {
        if (param_2 != 0x10000) {
          return;
        }
        uVar2 = 0xc;
      }
      else {
        if (param_2 != 0x10002) {
          return;
        }
        uVar2 = 6;
      }
      break;
    case :
      uVar2 = 5;
      break;
    :
      goto loc_405C432;
    }
    *param_4 = uVar2;
  }
loc_405C432:
  return;
}
/* GHIDRADEC_FUNCTION index=2987 start=0x405d448 */

int sub_405D448(int param_1,int *param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  iVar3 = 0;
  if (param_4 == 0) {
    iStack_8 = *param_2;
  }
  else {
    iStack_8 = *(int *)(param_1 + 0x10);
  }
  uVar1 = ~_page_mask & _page_mask + param_3;
  iVar2 = 0;
  if (param_5 != _kernel_object) {
    iVar2 = param_5;
  }
  iVar2 = _vm_map_find(param_1,iVar2,0,&iStack_8,uVar1,param_4);
  iVar2 = -(int)-(iVar2 != 0);
  if (iVar2 == 0) {
    if (param_5 == _kernel_object) {
      iVar3 = iStack_8 + -0x10000000;
      _vm_object_reference(param_5);
      _lock_write(param_1);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      _vm_map_delete(param_1,iStack_8,uVar1 + iStack_8);
      _vm_map_insert(param_1,param_5,iVar3,iStack_8,uVar1 + iStack_8);
      _lock_done(param_1);
    }
    iVar3 = sub_405D774(param_5,iVar3,uVar1,param_6);
    if (iVar3 == 0) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      _vm_map_delete(param_1,iStack_8,uVar1 + iStack_8);
      _lock_done(param_1);
      iVar2 = 6;
    }
    else {
      _vm_map_pageable(param_1,iStack_8,uVar1 + iStack_8,0);
      *param_2 = iStack_8;
      iVar2 = 0;
    }
  }
  else if (param_5 != _kernel_object) {
    _vm_object_deallocate(param_5);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2988 start=0x405d774 */

undefined4 sub_405D774(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  do {
    if (param_3 == 0) {
      return 1;
    }
    while (iVar1 = _vm_page_alloc_sequential(param_1,param_2,1), iVar1 == 0) {
      if (param_4 == 0) {
        return 0;
      }
      _thread_wakeup_prim(&_vm_pages_needed,0,0);
      _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
    }
    _vm_page_zero_fill(iVar1);
    *(byte *)(iVar1 + 0x20) = *(byte *)(iVar1 + 0x20) & 0x7f;
    param_3 = param_3 - _page_size;
    param_2 = _page_size + param_2;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2989 start=0x4060982 */

byte sub_4060982(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  
  _vm_page_remove(param_1);
  bVar4 = *(byte *)((int)param_1 + 0x1e);
  if ((bVar4 & 0x10) == 0) {
    if ((bVar4 & 0x40) != 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar2 = (undefined4 *)param_1[1];
      puVar3 = puVar2;
      if (puVar1 != &_vm_page_queue_active) {
        puVar1[1] = puVar2;
        puVar3 = dword_40C2C14;
      }
      dword_40C2C14 = puVar3;
      *puVar2 = puVar1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xbf;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if (*(char *)((int)param_1 + 0x1e) < '\0') {
      puVar1 = (undefined4 *)*param_1;
      puVar2 = (undefined4 *)param_1[1];
      puVar3 = puVar2;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar2;
        puVar3 = dword_40C23DC;
      }
      dword_40C23DC = puVar3;
      *puVar2 = puVar1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
      if ((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) {
        dword_40C2C1C = param_1;
      }
      else {
        _vm_page_queue_free[1] = param_1;
      }
      *param_1 = _vm_page_queue_free;
      param_1[1] = &_vm_page_queue_free;
      _vm_page_queue_free = param_1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x10;
      bVar6 = 0xfffffffe < _vm_page_free_count;
      bVar5 = SCARRY4(_vm_page_free_count,1);
      _vm_page_free_count = _vm_page_free_count + 1;
      bVar4 = bVar6 << 4 | ((int)_vm_page_free_count < 0) << 3 | (_vm_page_free_count == 0) << 2 |
              bVar5 << 1 | bVar6;
    }
  }
  return bVar4;
}
/* GHIDRADEC_FUNCTION index=2990 start=0x4060af6 */

void sub_4060AF6(undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
      if ((param_2 <= (uint)puVar1[6]) && ((uint)puVar1[6] < param_3)) {
        _vm_policy_apply(param_1,puVar1,param_4);
      }
    }
    param_3 = param_3 - param_2;
    uVar2 = param_1[4];
    if ((uVar2 != 0) && (uVar2 < param_3)) {
      param_3 = uVar2;
    }
    sub_4060AF6(param_1[7],param_1[8] + param_2,param_3 + param_1[8] + param_2,param_4);
    _thread_wakeup_prim(param_1,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2991 start=0x4060b78 */

void sub_4060B78(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  _lock_read(param_1);
  for (iVar5 = *(int *)(param_1 + 0xc); param_1 + 8 != iVar5; iVar5 = *(int *)(iVar5 + 4)) {
    if ((*(byte *)(iVar5 + 0x18) & 0xa0) == 0) {
      uVar1 = *(uint *)(iVar5 + 8);
      if ((uVar1 <= param_3) && (uVar2 = *(uint *)(iVar5 + 0xc), param_2 < uVar2)) {
        if (param_2 < uVar1) {
          param_2 = uVar1;
        }
        uVar4 = param_3;
        if (uVar2 < param_3) {
          uVar4 = uVar2;
        }
        iVar3 = (param_2 + *(int *)(iVar5 + 0x14)) - uVar1;
        sub_4060AF6(*(undefined4 *)(iVar5 + 0x10),iVar3,(iVar3 + uVar4) - param_2,param_4);
      }
    }
    else {
      sub_4060B78(*(undefined4 *)(iVar5 + 0x10),param_2,param_3,param_4);
    }
  }
  _lock_done(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2992 start=0x4060c18 */

void sub_4060C18(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  _lock_read(param_1);
  iVar2 = *(int *)(param_1 + 0xc);
  if (param_1 + 8 != iVar2) {
    do {
      if ((*(byte *)(iVar2 + 0x18) & 0xa0) == 0) {
        if (((*(uint *)(iVar2 + 8) <= param_3) && (param_2 < *(uint *)(iVar2 + 0xc))) &&
           (iVar1 = *(int *)(iVar2 + 0x10), iVar1 != 0)) {
          do {
            *(uint *)(iVar1 + 0x43) =
                 *(uint *)(iVar1 + 0x43) & 0xf0ffffff | ((param_4 & 0xffff) >> 0xc) << 0x18;
            *(word *)(iVar1 + 0x44) = (sword)param_4 << 4 | *(word *)(iVar1 + 0x44) & 0xf;
            iVar1 = *(int *)(iVar1 + 0x1c);
          } while (iVar1 != 0);
        }
      }
      else {
        sub_4060C18(*(undefined4 *)(iVar2 + 0x10),param_2,param_3,param_4);
      }
      iVar2 = *(int *)(iVar2 + 4);
    } while (param_1 + 8 != iVar2);
  }
  _lock_done(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2993 start=0x40618d0 */

undefined4 sub_40618D0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = 0;
  _lock_read(param_1);
  iVar6 = *(int *)(param_1 + 0xc);
  do {
    if (param_1 + 8 == iVar6) {
      _lock_done(param_1);
      return uVar5;
    }
    if ((*(byte *)(iVar6 + 0x18) & 0xa0) == 0) {
      uVar1 = *(uint *)(iVar6 + 8);
      if ((uVar1 <= param_3) && (uVar2 = *(uint *)(iVar6 + 0xc), param_2 < uVar2)) {
        if (param_2 < uVar1) {
          param_2 = uVar1;
        }
        uVar4 = param_3;
        if (uVar2 <= param_3) {
          uVar4 = uVar2;
        }
        iVar3 = (param_2 + *(int *)(iVar6 + 0x14)) - uVar1;
        iVar3 = sub_4061A64(*(undefined4 *)(iVar6 + 0x10),iVar3,(iVar3 + uVar4) - param_2);
        if (iVar3 != 0) goto loc_406195C;
      }
    }
    else {
      iVar3 = sub_40618D0(*(undefined4 *)(iVar6 + 0x10),param_2,param_3);
      if (iVar3 == 5) {
loc_406195C:
        uVar5 = 5;
      }
    }
    iVar6 = *(int *)(iVar6 + 4);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2994 start=0x406197e */

undefined sub_406197E(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  
  iVar3 = *(int *)(param_1 + 0x24);
  if (((*(byte *)(param_2 + 0x1e) & 4) == 0) ||
     (iVar2 = _pmap_is_modified(*(undefined4 *)(param_2 + 0x22)), iVar2 != 0)) {
    if ((char)*(byte *)(param_2 + 0x20) < '\0') {
      *(byte *)(param_2 + 0x20) = *(byte *)(param_2 + 0x20) | 0x40;
      _assert_wait(param_2,0);
      _thread_block();
      uVar4 = 2;
    }
    else {
      *(sword *)(param_1 + 0x40) = *(sword *)(param_1 + 0x40) + 1;
      *(byte *)(param_2 + 0x20) = *(byte *)(param_2 + 0x20) | 0x80;
      if (*(char *)(param_2 + 0x1e) < '\0') {
        _vm_page_activate(param_2);
      }
      _vm_page_deactivate(param_2);
      _pmap_remove_all(*(undefined4 *)(param_2 + 0x22));
      dword_40C2400 = dword_40C2400 + 1;
      if (iVar3 == 0) {
        *(sword *)(param_1 + 0x40) = *(sword *)(param_1 + 0x40) + -1;
        uVar4 = 1;
      }
      else {
        iVar3 = _vm_pager_put(iVar3,param_2);
        uVar4 = iVar3 != 0;
        bVar1 = *(byte *)(param_2 + 0x20);
        *(byte *)(param_2 + 0x20) = bVar1 & 0x7f;
        *(byte *)(param_2 + 0x20) = bVar1 & 0x7f;
        if ((bVar1 & 0x40) != 0) {
          *(byte *)(param_2 + 0x20) = bVar1 & 0x3f;
          _thread_wakeup_prim(param_2,0,0);
        }
        *(sword *)(param_1 + 0x40) = *(sword *)(param_1 + 0x40) + -1;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2995 start=0x4061a64 */

undefined4 sub_4061A64(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  bVar2 = true;
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
loc_4061A82:
    piVar5 = (int *)*param_1;
    if (piVar5 != param_1) {
      do {
        if ((param_2 <= (uint)piVar5[6]) && ((uint)piVar5[6] < param_3)) {
          iVar3 = sub_406197E(param_1,piVar5);
          if (iVar3 == 1) {
            bVar2 = false;
          }
          else if ((iVar3 != 0) && (iVar3 == 2)) goto loc_4061A82;
        }
        piVar5 = (int *)piVar5[2];
        if (piVar5 == param_1) break;
      } while( true );
    }
    param_3 = param_3 - param_2;
    uVar1 = param_1[4];
    if ((uVar1 != 0) && (uVar1 < param_3)) {
      param_3 = uVar1;
    }
    iVar3 = sub_4061A64(param_1[7],param_1[8] + param_2,param_3 + param_1[8] + param_2);
    if (iVar3 != 0) {
      iVar4 = 5;
    }
    _thread_wakeup_prim(param_1,0,0);
    if ((iVar4 == 5) || (!bVar2)) {
      return 5;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2996 start=0x40628fa */

/* WARNING: Removing unreachable block (ram,0x0406294c) */

void sub_40628FA(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  if ((char)(param_1 >> 0x18) != '\0') {
    iVar2 = (&unk_40B4E00)[param_1 >> 0x18];
    uVar3 = param_1 & 0xffffff;
    _lock_write(iVar2 + 0x34);
    if (*(int *)(iVar2 + 0x14) <= (int)uVar3) {
                    /* WARNING: Subroutine does not return */
      _panic(aVnodePagerDeal);
    }
    if ((int)uVar3 < *(int *)(iVar2 + 0x24)) {
      *(uint *)(iVar2 + 0x24) = uVar3;
    }
    pbVar1 = (byte *)(*(int *)(iVar2 + 0x10) + ((int)uVar3 >> 3));
    *pbVar1 = *pbVar1 & ~('\x01' << (param_1 & 7));
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
    _lock_done(iVar2 + 0x34);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2997 start=0x4062a70 */

undefined4 sub_4062A70(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  param_2 = param_2 >> (_page_shift & 0x3f);
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    if (*(uint *)(param_1 + 0x10) << 2 < 0x41) {
      iVar1 = *(int *)(param_1 + 8);
      cVar2 = *(char *)(iVar1 + param_2 * 4);
    }
    else {
      uVar3 = param_2 >> 4;
      param_2 = param_2 & 0xf;
      iVar1 = *(int *)(*(int *)(param_1 + 8) + uVar3 * 4);
      if (iVar1 == 0) {
        return 0;
      }
      cVar2 = *(char *)(iVar1 + param_2 * 4);
    }
    if (cVar2 != '\0') {
      *param_3 = *(undefined4 *)(iVar1 + param_2 * 4);
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2998 start=0x4062ad4 */

undefined4 sub_4062AD4(int param_1,uint param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  uVar7 = param_2 >> (_page_shift & 0x3f);
  iVar1 = sub_4062A70(param_1,param_2,param_4);
  if (param_3 == 1) {
    if (iVar1 != 0) {
      return 0;
    }
    goto loc_4062B16;
  }
  if (iVar1 == 0) {
loc_4062B4A:
    uVar5 = uVar7 + 1;
    uVar6 = *(uint *)(param_1 + 0x10);
    if (uVar6 < uVar5) {
      if (uVar5 * 4 < 0x41) {
        piVar3 = (int *)_kalloc_noblock(uVar5 * 4);
        if (piVar3 != (int *)0x0) {
          iVar1 = 0;
          piVar8 = piVar3;
          if (0 < *(int *)(param_1 + 0x10)) {
            do {
              *piVar8 = *(int *)(*(int *)(param_1 + 8) + iVar1 * 4);
              iVar1 = iVar1 + 1;
              piVar8 = piVar8 + 1;
            } while (iVar1 < *(int *)(param_1 + 0x10));
          }
          iVar1 = *(int *)(param_1 + 0x10);
          if (iVar1 < (int)uVar5) {
            piVar8 = piVar3 + iVar1;
            do {
              *(undefined *)piVar8 = 0;
              piVar8 = piVar8 + 1;
              iVar1 = iVar1 + 1;
            } while (iVar1 < (int)uVar5);
          }
          iVar1 = *(int *)(param_1 + 0x10);
          if (0 < iVar1) {
loc_4062CD6:
            iVar1 = iVar1 << 2;
loc_4062CDA:
            _kfree(*(undefined4 *)(param_1 + 8),iVar1);
          }
loc_4062CE6:
          *(int **)(param_1 + 8) = piVar3;
loc_4062CEA:
          *(uint *)(param_1 + 0x10) = uVar5;
          goto loc_4062CEE;
        }
      }
      else if (uVar6 == 0) {
        iVar1 = ((uVar7 >> 4) + 1) * 4;
        piVar3 = (int *)_kalloc_noblock(iVar1);
        if (piVar3 != (int *)0x0) {
          _bzero(piVar3,iVar1);
          goto loc_4062CE6;
        }
      }
      else if (uVar6 << 2 < 0x41) {
        iVar1 = ((uVar7 >> 4) + 1) * 4;
        piVar3 = (int *)_kalloc_noblock(iVar1);
        if (piVar3 != (int *)0x0) {
          _bzero(piVar3,iVar1);
          iVar4 = _kalloc_noblock(0x40);
          *piVar3 = iVar4;
          if (iVar4 != 0) {
            iVar1 = 0;
            if (0 < *(int *)(param_1 + 0x10)) {
              do {
                *(undefined4 *)(*piVar3 + iVar1 * 4) =
                     *(undefined4 *)(*(int *)(param_1 + 8) + iVar1 * 4);
                iVar1 = iVar1 + 1;
              } while (iVar1 < *(int *)(param_1 + 0x10));
            }
            for (uVar6 = *(uint *)(param_1 + 0x10); uVar6 < 0x10; uVar6 = uVar6 + 1) {
              *(undefined *)(*piVar3 + uVar6 * 4) = 0;
            }
            iVar1 = *(int *)(param_1 + 0x10);
            goto loc_4062CD6;
          }
          _kfree(piVar3,iVar1);
        }
      }
      else {
        iVar1 = ((uVar7 >> 4) + 1) * 4;
        if (((uVar6 - 1 >> 4) + 1) * 4 == iVar1) goto loc_4062CEA;
        piVar3 = (int *)_kalloc_noblock(iVar1);
        if (piVar3 != (int *)0x0) {
          _bzero(piVar3,iVar1);
          uVar6 = 0;
          piVar8 = piVar3;
          if (*(int *)(param_1 + 0x10) - 1U >> 4 != 0xffffffff) {
            do {
              *piVar8 = *(int *)(*(int *)(param_1 + 8) + uVar6 * 4);
              uVar6 = uVar6 + 1;
              piVar8 = piVar8 + 1;
            } while (uVar6 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
          }
          iVar1 = (*(int *)(param_1 + 0x10) - 1U >> 4) * 4 + 4;
          goto loc_4062CDA;
        }
      }
    }
    else {
loc_4062CEE:
      if ((uint)(*(int *)(param_1 + 0x10) << 2) < 0x41) {
        iVar1 = _vnode_pager_findpage(*(undefined4 *)(param_1 + 4),param_4);
        if (iVar1 != 5) {
          iVar1 = *(int *)(param_1 + 8);
          goto loc_4062D78;
        }
      }
      else {
        uVar6 = uVar7 >> 4;
        uVar7 = uVar7 & 0xf;
        if (*(int *)(*(int *)(param_1 + 8) + uVar6 * 4) == 0) {
          uVar2 = _kalloc_noblock(0x40);
          *(undefined4 *)(*(int *)(param_1 + 8) + uVar6 * 4) = uVar2;
          if (*(int *)(*(int *)(param_1 + 8) + uVar6 * 4) == 0) goto loc_4062B16;
          uVar5 = 0;
          do {
            *(undefined *)(*(int *)(*(int *)(param_1 + 8) + uVar6 * 4) + uVar5 * 4) = 0;
            uVar5 = uVar5 + 1;
          } while (uVar5 < 0x10);
        }
        iVar1 = _vnode_pager_findpage(*(undefined4 *)(param_1 + 4),param_4);
        if (iVar1 != 5) {
          iVar1 = *(int *)(*(int *)(param_1 + 8) + uVar6 * 4);
loc_4062D78:
          *(uint *)(iVar1 + uVar7 * 4) = *param_4;
          goto loc_4062D7C;
        }
      }
    }
loc_4062B16:
    uVar2 = 5;
  }
  else {
    if (*(int *)((&unk_40B4E00)[*(byte *)param_4] + 0x24) < (int)(*param_4 & 0xffffff)) {
      sub_40628FA(*param_4);
      goto loc_4062B4A;
    }
loc_4062D7C:
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2999 start=0x40635b6 */

void sub_40635B6(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (param_1._0_1_ != '\0') {
    iVar1 = 0;
    if (0 < dword_40B06E8) {
      puVar3 = unk_40B4E40;
      do {
        if (param_1._0_1_ == *puVar3) {
          uVar2 = *(uint *)puVar3 & 0xffffff;
          if (uVar2 < (param_1 & 0xffffff)) {
            uVar2 = param_1 & 0xffffff;
          }
          *(uint *)puVar3 = uVar2 | *(uint *)puVar3 & 0xff000000;
          return;
        }
        puVar3 = (undefined *)((int)puVar3 + 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < dword_40B06E8);
    }
    *(uint *)(unk_40B4E40 + dword_40B06E8 * 4) = param_1;
    dword_40B06E8 = dword_40B06E8 + 1;
  }
  return;
}

