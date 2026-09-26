/* GHIDRADEC_FUNCTION index=2300 start=0x4085452 */

void _snd_reply_ret_volume(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_24 = dword_40B21D8;
  uStack_1c = dword_40B21E0;
  uStack_18 = dword_40B21E4;
  uStack_10 = 0x132;
  uStack_20 = 0x20;
  uStack_14 = param_1;
  uStack_c = dword_40B21FC;
  uStack_8 = param_2;
  _msg_send(&uStack_24,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2301 start=0x40854bc */

void _snd_reply_ret_formats
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_34 = dword_40B21D8;
  uStack_2c = dword_40B21E0;
  uStack_28 = dword_40B21E4;
  uStack_20 = 0x140;
  uStack_30 = 0x30;
  uStack_24 = param_1;
  uStack_1c = dword_40B21FC & 0xffff005f | 0x50;
  uStack_18 = param_2;
  uStack_14 = param_3;
  uStack_10 = param_4;
  uStack_c = param_5;
  uStack_8 = param_6;
  _msg_send(&uStack_34,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2302 start=0x408554e */

undefined4 _snd_reply_dsp_msg(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_828;
  int iStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  int iStack_808;
  undefined auStack_804 [2048];
  
  uStack_828 = dword_40B21D8;
  uStack_820 = dword_40B21E0;
  uStack_818 = dword_40B21E8;
  uStack_814 = 0x13c;
  uStack_81c = 0;
  iStack_824 = 0x24;
  uStack_810 = dword_40B2200;
  uStack_80c = dword_40B2204;
  iStack_808 = dword_40C6E5A - dword_40C6E52 >> 2;
  _bcopy(dword_40C6E52,auStack_804,iStack_808 << 2);
  dword_40C6E5A = dword_40C6E52;
  _dsp_dev_loop();
  iStack_824 = iStack_824 + iStack_808 * 4;
  iVar1 = _object_copyin(dword_40C6EB8,param_1,6,0,&uStack_818);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_828,1,0);
    _port_release(uStack_818);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2303 start=0x4085648 */

undefined4 _snd_reply_dsp_err(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_a8;
  int iStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int iStack_88;
  undefined auStack_84 [128];
  
  uStack_a8 = dword_40B21D8;
  uStack_a0 = dword_40B21E0;
  uStack_98 = dword_40B21E8;
  uStack_94 = 0x13b;
  uStack_9c = 0;
  iStack_a4 = 0x24;
  uStack_90 = dword_40B2200;
  uStack_8c = dword_40B2204;
  iStack_88 = dword_40C6E66 - dword_40C6E5E >> 2;
  _bcopy(dword_40C6E5E,auStack_84,iStack_88 << 2);
  dword_40C6E66 = dword_40C6E5E;
  _dsp_dev_loop();
  iStack_a4 = iStack_a4 + iStack_88 * 4;
  iVar1 = _object_copyin(dword_40C6EB8,param_1,6,0,&uStack_98);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_a8,1,0);
    _port_release(uStack_98);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2304 start=0x408574e */

void _snd_reply_dsp_cmd_port(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_1c = dword_40B21D8;
  uStack_18 = dword_40B21DC;
  uStack_14 = dword_40B21E0;
  uStack_8 = 0x13d;
  uStack_10 = param_1;
  uStack_c = param_2;
  _msg_send(&uStack_1c,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2305 start=0x40857aa */

undefined4 _snd_reply_dsp_regs(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_24 = dword_40B21D8;
  uStack_1c = dword_40B21E0;
  uStack_14 = dword_40B21E8;
  uStack_10 = 0x13e;
  uStack_18 = 0;
  uStack_20 = 0x20;
  uStack_c = dword_40B21FC;
  uStack_8 = param_1;
  iVar1 = _object_copyin(dword_40C6EB8,_snd_var,6,0,&uStack_14);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_24,1,0);
    _port_release(uStack_14);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2306 start=0x4085856 */

undefined4 _snd_reply_dsp_cond_true(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_2c = dword_40B21D8;
  uStack_24 = dword_40B21E0;
  uStack_1c = dword_40B21E8;
  uStack_18 = 0x13f;
  uStack_20 = 0;
  uStack_28 = 0x28;
  uStack_14 = dword_40B21FC & 0xffff003f | 0x30;
  uStack_10 = *(undefined4 *)(param_1 + 4);
  uStack_c = *(undefined4 *)(param_1 + 8);
  uStack_8 = *(undefined4 *)(param_1 + 0x14);
  iVar1 = _object_copyin(dword_40C6EB8,*(undefined4 *)(param_1 + 0xc),6,0,&uStack_1c);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_2c,1,0);
    _port_release(uStack_1c);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2307 start=0x4085920 */

undefined4 _snd_audio_not_loaded(void)

{
  if (dword_40B2264 == 0) {
    _printf(aSounddspAudioD);
    dword_40B2264 = 1;
  }
  return 5;
}
/* GHIDRADEC_FUNCTION index=2308 start=0x40859d6 */

void _snd_server_loop(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  dword_40C6EB8 = *(int *)(_active_threads + 0xc);
  *(undefined4 *)(dword_40C6EB8 + 0x48) = 1;
  dword_40C6EC0 = *(undefined4 *)(dword_40C6EB8 + 0x7c);
  dword_40C6EC4 = _task_self();
  dword_40C6EBC = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  dword_40C6E98 = &dword_40C6E94;
  dword_40C6E94 = &dword_40C6E94;
  dword_40C6E90 = &dword_40C6E8C;
  dword_40C6E8C = &dword_40C6E8C;
  iVar2 = _port_set_allocate(dword_40C6EC0,&dword_40C6EA8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAlloc_0);
  }
  iVar2 = _port_allocate(dword_40C6EC0,&uStack_8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAlloc_1);
  }
  iVar2 = _object_copyin(dword_40C6EB8,uStack_8,6,0,&uStack_c);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundObjectCop);
  }
  iVar2 = _task_set_special_port(dword_40C6EB8,2,uStack_c);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundTaskSetSp);
  }
  iVar2 = _port_set_add(dword_40C6EC0,dword_40C6EA8,uStack_8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundPortSetAd);
  }
  uStack_c = _ipc_port_copy_send(dword_40B67DC);
  _object_copyout(dword_40C6EB8,uStack_c,6,&dword_40C6EC8);
  iVar2 = _port_allocate(dword_40C6EC0,&dword_40C6EB4);
  if (iVar2 == 0) {
    iVar2 = _port_set_add(dword_40C6EC0,dword_40C6EA8,dword_40C6EB4);
    if (iVar2 == 0) {
      _thread_wakeup_prim(&dword_40C6EC4,0,0);
      _task_name(aSoundDevice);
      _snd_device_init(0);
      _dsp_dev_init();
      _dsp_dev_reset_hard();
      _snd_stream_init();
      iVar2 = _snd_rcv_alloc_msg_frame();
      uVar1 = *(undefined4 *)(iVar2 + 4);
      do {
        while( true ) {
          while( true ) {
            *(undefined4 *)(iVar2 + 0xc) = dword_40C6EA8;
            *(undefined4 *)(iVar2 + 4) = uVar1;
            iVar3 = _msg_receive(iVar2,0,0);
            if (iVar3 == 0) break;
            if (iVar3 != -0xcf) {
              _printf(aSoundReceiveFa,iVar3);
            }
          }
          if (*(int *)(iVar2 + 0xc) != dword_40C6EB4) break;
          iVar3 = sub_4085E66(iVar2);
loc_4085C52:
          if (iVar3 != 0) {
            _snd_reply_illegal_msg
                      (0,*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),iVar3);
          }
        }
        if (*(int *)(iVar2 + 0xc) == 0x10013) {
          iVar3 = _snd_dsp_cmd_port_msg(iVar2);
          goto loc_4085C52;
        }
        iVar3 = _task_notify();
        if (iVar3 != *(int *)(iVar2 + 0xc)) {
          iVar3 = sub_408667A(iVar2);
          goto loc_4085C52;
        }
        if (*(int *)(iVar2 + 0x14) == 0x41) {
          sub_40870BA(*(undefined4 *)(iVar2 + 0x1c));
        }
        else {
          _printf(aSoundWierdNoti,*(int *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x1c));
        }
      } while( true );
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSoundCanTAlloc_2);
}
/* GHIDRADEC_FUNCTION index=2309 start=0x4085cc0 */

int * _snd_get_owner(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == param_1) {
      return (int *)0x0;
    }
    if (param_2 == *piVar1) break;
    piVar1 = (int *)piVar1[2];
  }
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=2310 start=0x4087272 */

void _snd_stream_init(void)

{
  dword_40C6EB0 = &dword_40C6EAC;
  dword_40C6EAC = &dword_40C6EAC;
  return;
}
/* GHIDRADEC_FUNCTION index=2311 start=0x4087288 */

void _snd_stream_reset(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2312 start=0x4087290 */

void _snd_stream_queue_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  *param_1 = param_2;
  puVar1 = param_1 + 3;
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  _lock_init(param_1 + 1,1);
  *(undefined4 *)((int)param_1 + 0x26) = 0;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0x1f;
  param_1[7] = 0;
  *(undefined4 *)((int)param_1 + 0x3a) = param_3;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xef;
  param_1[8] = 0;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xfb;
  *(undefined4 *)((int)param_1 + 0x2e) = 4;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xf7;
  return;
}
/* GHIDRADEC_FUNCTION index=2313 start=0x40872f6 */

void _snd_stream_queue_reset(int param_1)

{
  _snd_stream_abort(param_1,0);
  while ((*(int *)(param_1 + 0x1c) != 0 && (*(int *)(_active_threads + 0x40) != 2))) {
    _assert_wait(param_1,1);
    _thread_block();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2314 start=0x408733c */

void _snd_stream_enqueue_region(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar1 = *(undefined4 **)((int)param_1 + 0x3a);
  *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xfd;
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xfb | (byte)(((*(byte *)(param_1 + 0xb) & 3) >> 1) << 2);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xfd |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 7) >> 2) << 1);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xf7 |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 3) >> 1) << 3);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xef |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 0xf) >> 3) << 4);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xdf |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 0x1f) >> 4) << 5);
  uVar3 = ~_page_mask;
  param_1[8] = *param_1 & uVar3;
  param_1[7] = *param_1 & uVar3;
  param_1[4] = *param_1;
  param_1[3] = param_1[4];
  param_1[2] = param_1[1] + *param_1;
  if (param_1[10] == 0) {
    param_1[10] = *(uint *)((int)puVar1 + 0x36);
  }
  if (param_1[9] == 0) {
    param_1[9] = *(uint *)((int)puVar1 + 0x32);
  }
  if (param_1[5] == 0) {
    param_1[5] = *(uint *)((int)puVar1 + 0x2a);
  }
  if (puVar1[7] == 0) {
    puVar4 = puVar1;
    if ((undefined4 **)dword_40C6EB0 != &dword_40C6EAC) {
      dword_40C6EB0[5] = puVar1;
      puVar4 = dword_40C6EAC;
    }
    dword_40C6EAC = puVar4;
    puVar1[6] = dword_40C6EB0;
    puVar1[5] = &dword_40C6EAC;
    dword_40C6EB0 = puVar1;
    uVar5 = _kernel_thread(dword_40C6EB8,sub_408771E);
    puVar1[7] = uVar5;
  }
  _lock_write(puVar1 + 1);
  puVar4 = puVar1 + 3;
  if (puVar4 != (undefined4 *)*puVar4) {
    *(byte *)((int)param_1 + 0x2d) =
         *(byte *)((int)param_1 + 0x2d) & 0xfb | *(byte *)(puVar1[4] + 0x2d) & 4;
  }
  puVar2 = (undefined4 *)puVar1[4];
  if (puVar2 == puVar4) {
    *puVar2 = param_1;
  }
  else {
    *(uint **)((int)puVar2 + 0x32) = param_1;
  }
  *(undefined4 **)((int)param_1 + 0x36) = puVar2;
  *(undefined4 **)((int)param_1 + 0x32) = puVar1 + 3;
  puVar1[4] = param_1;
  _lock_done(puVar1 + 1);
  *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) | 2;
  _thread_wakeup_prim(puVar1,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2315 start=0x40874ce */

void _snd_stream_abort(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != param_1 + 0xc) {
    do {
      if ((*(byte *)(iVar1 + 0x2d) & 8) == 0) break;
      iVar1 = *(int *)(iVar1 + 0x32);
    } while (iVar1 != param_1 + 0xc);
    for (; iVar1 != param_1 + 0xc; iVar1 = *(int *)(iVar1 + 0x32)) {
      if ((param_2 == 0) || (param_2 == *(int *)(iVar1 + 0x2e))) {
        *(byte *)(iVar1 + 0x2d) = *(byte *)(iVar1 + 0x2d) | 0x20;
        *(byte *)(iVar1 + 0x2c) = *(byte *)(iVar1 + 0x2c) | 2;
      }
    }
  }
  *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 2;
  _thread_wakeup_prim(param_1,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2316 start=0x408755c */

byte _snd_stream_pause(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  bool bVar9;
  byte bVar10;
  bool bVar11;
  bool bVar12;
  
  cVar3 = '\0';
  bVar10 = *(byte *)(param_1 + 0x24);
  *(byte *)(param_1 + 0x24) = bVar10 | 0x10;
  if ((bVar10 & 8) == 0) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = param_1 + 0xc;
    bVar11 = uVar1 < uVar2;
    bVar9 = SBORROW4(uVar1,uVar2);
    bVar5 = (int)(uVar1 - uVar2) < 0;
    bVar7 = uVar1 == uVar2;
    bVar12 = bVar11;
    if (!bVar7) {
      bVar10 = *(byte *)(uVar1 + 0x2d);
      while( true ) {
        bVar7 = false;
        bVar9 = false;
        bVar5 = (char)bVar10 < '\0';
        bVar12 = false;
        if ((bVar10 & 8) != 0) break;
        if ((*(byte *)(uVar1 + 0x2c) & 0x10) != 0) {
          _snd_reply_paused(*(undefined4 *)(uVar1 + 0x18),*(undefined4 *)(uVar1 + 0x2e));
        }
        uVar1 = *(uint *)(uVar1 + 0x36);
        bVar11 = uVar1 < uVar2;
        bVar9 = SBORROW4(uVar1,uVar2);
        bVar5 = (int)(uVar1 - uVar2) < 0;
        bVar7 = true;
        bVar12 = bVar11;
        if (uVar1 == uVar2) break;
        bVar10 = *(byte *)(uVar1 + 0x2d);
      }
    }
    bVar10 = bVar11 << 4 | bVar5 << 3 | bVar7 << 2 | bVar9 << 1 | bVar12;
  }
  else {
    cVar4 = param_1 < 0;
    cVar6 = param_1 == 0;
    cVar8 = '\0';
    bVar10 = 0;
    _snd_link_pause(param_1);
    bVar10 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar8 << 1 | bVar10;
  }
  return bVar10;
}
/* GHIDRADEC_FUNCTION index=2317 start=0x40875f2 */

uint _snd_stream_resume(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  cVar3 = '\0';
  bVar7 = *(byte *)(param_1 + 0x24);
  *(byte *)(param_1 + 0x24) = bVar7 & 0xef;
  if ((bVar7 & 8) == 0) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 != param_1 + 0xc) {
      bVar7 = *(byte *)(iVar1 + 0x2d);
      while ((bVar7 & 8) == 0) {
        if ((*(byte *)(iVar1 + 0x2c) & 8) != 0) {
          _snd_reply_resumed(*(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x2e));
        }
        iVar1 = *(int *)(iVar1 + 0x36);
        if (iVar1 == param_1 + 0xc) break;
        bVar7 = *(byte *)(iVar1 + 0x2d);
      }
    }
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 2;
    uVar2 = _thread_wakeup_prim(param_1,0,0);
  }
  else {
    cVar4 = param_1 < 0;
    cVar5 = param_1 == 0;
    cVar6 = '\0';
    bVar7 = 0;
    _snd_link_resume(param_1);
    uVar2 = (uint)(byte)(cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2318 start=0x408769c */

undefined4 _snd_stream_await(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != param_1 + 0xc) {
    do {
      if (((*(byte *)(iVar1 + 0x2d) & 8) == 0) &&
         ((param_2 == 0 || (param_2 == *(int *)(iVar1 + 0x2e))))) break;
      iVar1 = *(int *)(iVar1 + 0x32);
    } while (iVar1 != param_1 + 0xc);
    if (iVar1 != param_1 + 0xc) {
      *(byte *)(iVar1 + 0x2c) = *(byte *)(iVar1 + 0x2c) | 2;
      *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 2;
      _thread_wakeup_prim(param_1,0,0);
      return 0;
    }
  }
  return 0x6c;
}
/* GHIDRADEC_FUNCTION index=2319 start=0x408833a */

undefined4 _snd_unix_ioctl(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined auStack_1c [3];
  undefined uStack_19;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (param_2 == 0x20004108) {
    if (dword_40C6EC4 == 0) {
      _task_create(_kernel_task,0,&uStack_20);
      _thread_create(uStack_20,&uStack_24);
      _thread_start(uStack_24,_snd_server_loop);
      _thread_resume(uStack_24);
      if (dword_40C6EC4 == 0) {
        _assert_wait(&dword_40C6EC4,0);
        _thread_block();
      }
    }
    _object_copyin(*(undefined4 *)(_active_threads + 0xc),*param_3,6,0,param_3);
    _object_copyin(dword_40C6EB8,dword_40C6EB4,6,0,&uStack_28);
    uStack_19 = 1;
    uStack_18 = 0x18;
    uStack_14 = 0;
    uStack_10 = uStack_28;
    uStack_c = *param_3;
    uStack_8 = 0x12f;
    _msg_send_from_kernel(auStack_1c,0,0);
    _port_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c),*param_3);
    _port_deallocate(dword_40C6EC0,uStack_28);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2320 start=0x4088614 */

undefined4 _stopen(word param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar3 = uVar2 * 0x166;
  piVar5 = (int *)(_st_std + iVar3);
  puVar1 = *(undefined **)(_st_std + iVar3 + 0xc);
  if ((_st_std[iVar3 + 0x67] & 0x10) != 0) {
    return 0x10;
  }
  if ((1 < uVar2) || (*piVar5 == 0)) {
    return 6;
  }
  sub_408856E(*piVar5);
  iVar4 = sub_40887EA(piVar5,1);
  if ((iVar4 == 0) || (iVar4 = sub_40887EA(piVar5,1), iVar4 == 0)) {
    if ((param_1 & 2) == 0) {
loc_408871C:
      *(word *)(_st_std + iVar3 + 0x66) = *(word *)(_st_std + iVar3 + 0x66) | 0x10;
      return 0;
    }
    iVar4 = sub_4089510(piVar5,0,0);
    if (iVar4 == 0) {
      *(word *)(_st_std + iVar3 + 0x66) = *(word *)(_st_std + iVar3 + 0x66) | 0x20;
      *(undefined4 *)(puVar1 + 0x3c) = 0x11;
      iVar4 = sub_40889C2(piVar5,*(undefined4 *)(_st_std + iVar3 + 0xc),0);
      if (iVar4 == 0) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = puVar1[2] & 0x7f;
        puVar1[3] = 8;
        *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xff000000;
        *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & 0xff000000;
        puVar1[2] = puVar1[2] & 0x9f | 0x10;
        puVar1[0xc] = puVar1[0xc] & 0xdf | 0xe;
        iVar4 = sub_4088958(piVar5,*(undefined4 *)(_st_std + iVar3 + 0xc),0);
        if (iVar4 == 0) goto loc_408871C;
      }
    }
  }
  return 5;
}
/* GHIDRADEC_FUNCTION index=2321 start=0x408872e */

undefined4 _stclose(word param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((param_1 & 0xff) >> 3) * 0x166;
  uVar2 = 0;
  if ((_st_std[iVar1 + 0x67] & 8) != 0) {
    uVar2 = sub_4088840(_st_std + iVar1);
  }
  if ((param_1 & 1) == 0) {
    uVar2 = sub_4088898(_st_std + iVar1);
  }
  *(word *)(_st_std + iVar1 + 0x66) = *(word *)(_st_std + iVar1 + 0x66) & 0xffef;
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2322 start=0x4088a2a */

void _stread(sword param_1,undefined4 param_2)

{
  sub_4088A60((int)param_1,param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2323 start=0x4088a44 */

void _stwrite(sword param_1,undefined4 param_2)

{
  sub_4088A60((int)param_1,param_2,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2324 start=0x40890f8 */

int _stioctl(word param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  word wVar3;
  int iVar2;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uStack_8;
  
  iVar4 = 0;
  wVar3 = (word)(((uint)param_1 << 0x18) >> 0x1b);
  iVar2 = (sword)wVar3 * 0x166;
  piVar5 = (int *)(_st_std + iVar2);
  if (1 < wVar3) {
    return 6;
  }
  if (param_2 != -0x3fad92f5) {
    if (param_2 < -0x3fad92f4) {
      if (param_2 == -0x7ff992ff) {
        iVar4 = sub_408935A((int)(sword)param_1,param_3);
        goto loc_4089344;
      }
      if (param_2 < -0x7ff992fe) {
        if (param_2 == -0x7ffb92fb) {
          uVar6 = *param_3;
loc_4089238:
          iVar4 = sub_4089510(piVar5,uVar6,0);
          goto loc_4089344;
        }
      }
      else {
        if (param_2 == -0x7fbf92f9) {
          iVar4 = sub_4088958(piVar5,param_3,0);
          goto loc_4089344;
        }
        if (param_2 == -0x3fbf92f8) {
          iVar4 = sub_40889C2(piVar5,param_3,0);
          goto loc_4089344;
        }
      }
    }
    else {
      if (param_2 == 0x20006d09) {
        *(word *)(_st_std + iVar2 + 0x66) = *(word *)(_st_std + iVar2 + 0x66) | 0x20;
        goto loc_4089344;
      }
      if (param_2 < 0x20006d0a) {
        if (param_2 == 0x20006d06) {
          uVar6 = 0;
          goto loc_4089238;
        }
      }
      else {
        if (param_2 == 0x20006d0a) {
          *(word *)(_st_std + iVar2 + 0x66) = *(word *)(_st_std + iVar2 + 0x66) & 0xffdf;
          goto loc_4089344;
        }
        if (param_2 == 0x40166d02) {
          if (((_st_std[iVar2 + 0x67] & 2) != 0) || (iVar4 = sub_40888F0(piVar5,0), iVar4 == 0)) {
            iVar1 = *(int *)(_st_std + iVar2 + 0x10);
            if ((param_1 & 2) == 0) {
              *(undefined2 *)param_3 = 9;
            }
            else {
              *(undefined2 *)param_3 = 10;
            }
            *(word *)((int)param_3 + 2) = (word)*(byte *)(iVar1 + 2);
            *(word *)(param_3 + 1) = (word)*(byte *)(iVar1 + 0xc);
            *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)(iVar1 + 0x13);
            *(undefined2 *)(param_3 + 2) = *(undefined2 *)(iVar1 + 0x15);
            *(uint *)((int)param_3 + 10) =
                 *(uint *)(iVar1 + 4) >> 8 | (uint)*(byte *)(iVar1 + 3) << 0x18;
            *(word *)(_st_std + iVar2 + 0x66) = *(word *)(_st_std + iVar2 + 0x66) & 0xfffd;
          }
          goto loc_4089344;
        }
      }
    }
    iVar4 = 0x16;
    goto loc_4089344;
  }
  if (param_3[5] == 0) {
    uStack_8 = 0;
loc_40892D8:
    uVar6 = param_3[4];
    param_3[4] = uStack_8;
    *(uint *)((int)param_3 + 1) =
         *(uint *)((int)param_3 + 1) & 0x1fffffff | (uint)*(byte *)(*piVar5 + 0x1d) << 0x1d;
    iVar4 = sub_4089628(piVar5,param_3,0);
    param_3[4] = uVar6;
    if ((param_3[3] == 0) && (param_3[0xf] != 0)) {
      iVar4 = _copyoutmsg(uStack_8,uVar6,param_3[0xf]);
    }
  }
  else {
    iVar2 = _kmem_alloc_wired(_kernel_map,&uStack_8,param_3[5]);
    if (iVar2 != 0) {
      param_3[7] = 8;
      return 0xc;
    }
    if ((param_3[3] != 1) || (iVar4 = _copyinmsg(param_3[4],uStack_8,param_3[5]), iVar4 == 0))
    goto loc_40892D8;
    param_3[7] = 9;
  }
  if (param_3[5] != 0) {
    _kmem_free(_kernel_map,uStack_8,param_3[5]);
  }
loc_4089344:
  *(char *)(dword_40B57D4 + 100) = (char)iVar4;
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2325 start=0x4089786 */

undefined4 _vidopen(void)

{
  int iVar1;
  
  if ((dword_40B2282 == -1) && (iVar1 = _vidProbeForFB(), iVar1 == -1)) {
    return 0x13;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2326 start=0x40897aa */

void _vidclose(void)

{
  _ev_unregister_screen(dword_40B5184);
  dword_40B5184 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2327 start=0x40897c4 */

int _vidioctl(undefined4 param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined auStack_a4 [128];
  undefined uStack_24;
  uint uStack_23;
  byte bStack_13;
  undefined auStack_12 [14];
  
  iVar2 = *(int *)(_active_threads + 0x24);
  if (param_2 == 0x20007603) {
    if (-1 < *(int *)(iVar2 + 0x54)) {
      return 6;
    }
    (*(&off_40B229C)[dword_40B2282 * 0xb])();
  }
  else if (param_2 < 0x20007604) {
    if (param_2 == -0x7fcf89f8) {
      _bcopy(param_3,unk_40B2310,0x30);
      sub_4089C56();
    }
    else {
      if (param_2 < -0x7fcf89f7) {
        if (param_2 == -0x7ff789f9) {
          iVar2 = _suser();
          if (iVar2 != 0) {
            iVar2 = _rtc_alarm(param_3,0);
            return iVar2;
          }
        }
        else {
          if (param_2 != -0x7fdf89fc) {
            return 0x19;
          }
          iVar2 = _suser();
          if (iVar2 != 0) {
            _nvram_check(&uStack_24);
            iVar2 = _strncmp(auStack_12,(int)param_3 + 0x12,0xc);
            if (iVar2 != 0) {
              _strcpy(&_boot_dev,(int)param_3 + 0x12);
              _boot_info = 0;
              _boot_file = 0;
            }
            if ((*(byte *)((int)param_3 + 0x11) & 0x40) != (bStack_13 & 0x40)) {
              _rtc_set_auto_poweron((*(byte *)((int)param_3 + 0x11) & 0x7f) >> 6);
            }
            _nvram_set(param_3);
            return 0;
          }
        }
loc_40899B4:
        return (int)*(char *)(dword_40B57D4 + 100);
      }
      if (param_2 == -0x3ffb8a00) {
        if (*param_3 == 0x87654321) {
          _vidSuspendAnimation();
        }
        else if (*param_3 == 0x12345678) {
          _vidResumeAnimation();
        }
        else {
          _vidStopAnimation();
        }
        if (*(int *)(iVar2 + 0x54) < 0) {
          return 0x10;
        }
        if (*param_3 != 0x12345678) {
          _vidStopAnimation();
        }
        uVar1 = (*(&off_40B2298)[dword_40B2282 * 0xb])();
        *param_3 = uVar1;
        if (uVar1 == 0) {
          return 6;
        }
      }
      else {
        if (param_2 != -0x3ffb89fe) {
          return 0x19;
        }
        _nvram_check(&uStack_24);
        uVar1 = _SetCurBrightness(*param_3);
        uStack_23 = uStack_23 & 0xf03fffff | (uVar1 & 0x3f) << 0x16;
        *param_3 = uVar1 & 0x3f;
        _nvram_set(&uStack_24);
      }
    }
  }
  else {
    if (param_2 != 0x20007609) {
      if (param_2 < 0x2000760a) {
        if (param_2 == 0x20007605) {
          iVar2 = sub_408B27A();
          return iVar2;
        }
        if (param_2 == 0x20007606) {
          uVar1 = *param_3;
          (**(code **)((int)&DAT_40b2290 + dword_40B2282 * 0x2c))(auStack_a4);
          iVar2 = _copyoutmsg(auStack_a4,uVar1,0x80);
          return iVar2;
        }
      }
      else {
        if (param_2 == 0x40207604) {
          iVar2 = _suser();
          if (iVar2 != 0) {
            _nvram_check(param_3);
            return 0;
          }
          goto loc_40899B4;
        }
        if (param_2 < 0x40207605) {
          if (param_2 == 0x40087607) {
            iVar2 = _rtc_alarm(0,param_3);
            return iVar2;
          }
        }
        else if (param_2 == 0x40307608) {
          _bcopy(unk_40B2310,param_3,0x30);
          return 0;
        }
      }
      return 0x19;
    }
    iVar2 = 0;
    puVar3 = unk_40AD8AC;
    do {
      unk_40B2310[iVar2] = *puVar3;
      unk_40B2320[iVar2] = *puVar3;
      unk_40B2330[iVar2] = *puVar3;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 0x10);
    sub_4089C56();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2328 start=0x4089aac */

int _vidProbeForFB(void)

{
  int iVar1;
  sword sVar2;
  
  sVar2 = 2;
  do {
    iVar1 = (**(code **)(unk_40B228C + sVar2 * 0x2c))();
    if (iVar1 == 1) {
      dword_40B2282 = (int)sVar2;
      (**(code **)(unk_40B228C + sVar2 * 0x2c + 8))();
      return (int)sVar2;
    }
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return -1;
}
/* GHIDRADEC_FUNCTION index=2329 start=0x4089af0 */

void _vidGetConsoleInfo(undefined4 param_1)

{
  if (dword_40B2282 != -1) {
    (**(code **)((int)&DAT_40b2290 + dword_40B2282 * 0x2c))(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2330 start=0x4089b1e */

void _vidGetFBAddrAndSize(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined auStack_84 [64];
  undefined4 uStack_44;
  
  if ((dword_40B2282 == -1) && (iVar1 = _vidProbeForFB(), iVar1 == -1)) {
    *param_1 = 0;
    *param_2 = 0;
    return;
  }
  (**(code **)((int)&DAT_40b2290 + dword_40B2282 * 0x2c))(auStack_84);
  *param_1 = uStack_44;
  *param_2 = dword_40B6990 + dword_40B6984;
  return;
}
/* GHIDRADEC_FUNCTION index=2331 start=0x4089b88 */

void _vidStopAnimation(void)

{
  *(byte *)(_mon_global + 4) = *(byte *)(_mon_global + 4) & 0xf7;
  if (dword_40B2286 != 0) {
    _vidResumeAnimation();
  }
  _delay(100000);
  return;
}
/* GHIDRADEC_FUNCTION index=2332 start=0x4089bb6 */

void _vidSuspendAnimation(void)

{
  if ((dword_40B2282 != -1) && (byte_40B228A == '\0')) {
    (*(&off_40B22B0)[dword_40B2282 * 0xb])();
    byte_40B228A = '\x01';
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2333 start=0x4089bf0 */

void _vidResumeAnimation(void)

{
  if ((dword_40B2282 != -1) && (byte_40B228A != '\0')) {
    (*(&off_40B22B4)[dword_40B2282 * 0xb])();
    byte_40B228A = '\0';
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2334 start=0x4089c28 */

void _vidSetBrightness(undefined4 param_1)

{
  if (dword_40B2282 != -1) {
    (*(code *)(&DAT_40b22a8)[dword_40B2282 * 0xb])(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2335 start=0x4089c9e */

void _vidInterruptEnable(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((dword_40B2282 == -1) && (iVar1 = _vidProbeForFB(), iVar1 == -1)) {
    return;
  }
  dword_40B2286 = param_1;
  dword_40B5188 = param_2;
  (*(&off_40B22AC)[dword_40B2282 * 0xb])();
  return;
}
/* GHIDRADEC_FUNCTION index=2336 start=0x4089ce8 */

void _vidInterruptDisable(void)

{
  if (dword_40B2282 != -1) {
    dword_40B2286 = 0;
    dword_40B5188 = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2337 start=0x408b300 */

int _zsopen(word param_1,byte param_2)

{
  undefined *puVar1;
  word *pwVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  
  bVar9 = (byte)param_1;
  uVar3 = bVar9 & 0x1f;
  if (dword_40B51A4 == 0) {
    dword_40B51A4 = 1;
    dword_40B51B8 = sub_408BC84();
    sub_408D042();
  }
  if (uVar3 < 2) {
    iVar5 = uVar3 * 0x86;
    puVar1 = unk_40B51BC + iVar5;
    iVar6 = _ttynty(puVar1);
    iVar7 = uVar3 * 0x164;
    if ((param_1 & 0x1f) == 0) {
      *(int *)(DAT_40b52d0 + iVar7 + 0xc) = _slot_id_bmap + 0x2018001;
    }
    else {
      *(int *)(DAT_40b52d0 + iVar7 + 0xc) = _slot_id_bmap + 0x2018000;
    }
    if (((-1 < (char)unk_40B51BC[iVar5 + 0x41]) || (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0)
        ) && ((-1 < (char)bVar9 || ((*(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 8) == 0)))) {
      if ((param_1 & 0x40) == 0) {
        bVar4 = *(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 4;
      }
      else {
        bVar4 = *(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 2;
      }
      if (bVar4 == 0) {
        iVar8 = _zsacquire(uVar3,1,unk_40B2422);
        if (iVar8 != 0) {
          return iVar8;
        }
        if ((char)bVar9 < '\0') goto loc_408B402;
        *(int *)(DAT_40b5423 + iVar7 + 5) = *(int *)(DAT_40b5423 + iVar7 + 5) + 1;
loc_408B3FE:
        do {
          if (-1 < (char)bVar9) goto loc_408B40A;
loc_408B402:
          (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 0x10;
          do {
            if ((param_1 & 0x40) == 0) {
              (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 2;
            }
            else {
              (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 4;
            }
            if (((param_1 & 0x20) != 0) && (dword_40B51B8 == 2)) {
              (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 0x40;
            }
            if ((unk_40B51BC[iVar5 + 0x41] & 4) == 0) {
              *(word *)(unk_40B51BC + iVar5 + 0x38) = param_1;
              *(code **)(unk_40B51BC + iVar5 + 0x24) = sub_408CA1E;
              _ttychars(puVar1);
              if (unk_40B51BC[iVar5 + 0x47] == '\0') {
                unk_40B51BC[iVar5 + 0x47] = 0xd;
                unk_40B51BC[iVar5 + 0x48] = 0xd;
                *(undefined4 *)(unk_40B51BC + iVar5 + 0x3a) = 0xd8;
              }
              if ((char)bVar9 < '\0') {
                unk_40B51BC[iVar5 + 0x3a] = unk_40B51BC[iVar5 + 0x3a] | 1;
              }
              else {
                unk_40B51BC[iVar5 + 0x3a] = unk_40B51BC[iVar5 + 0x3a] & 0xfe;
              }
              if ((*(byte *)((int)&DAT_40b5400 + iVar7 + 2) & 1) == 0) {
                *(uint *)(unk_40B51BC + iVar5 + 0x3e) =
                     *(uint *)(unk_40B51BC + iVar5 + 0x3e) & 0xffffffef;
                sub_408BCB6(uVar3);
                pwVar2 = (word *)((int)&DAT_40b5400 + iVar7 + 2);
                *pwVar2 = *pwVar2 | 0x100;
              }
              sub_408BE8E(uVar3,0);
            }
            if ((DAT_40b5423[iVar7] & 4) != 0) {
loc_408B54A:
              sub_408CF32(uVar3,5,0);
              sub_408CD86(uVar3);
              if (((bVar9 & 0xc0) == 0x40) && ((*(uint *)(unk_40B51BC + iVar5 + 0x3e) & 0x10) == 0))
              {
                if (((param_2 & 4) == 0) && (-1 < *(sword *)(iVar6 + 0x12))) {
                  *(uint *)(unk_40B51BC + iVar5 + 0x3e) = *(uint *)(unk_40B51BC + iVar5 + 0x3e) | 2;
                  iVar8 = _sleep(DAT_40b52d0 + iVar7,0x11c);
                  if (iVar8 != 0) {
                    iVar5 = *(int *)(DAT_40b5423 + iVar7 + 5);
                    *(int *)(DAT_40b5423 + iVar7 + 5) = iVar5 + -1;
                    if (iVar5 != 1) {
                      return 4;
                    }
                    if (((&DAT_40b5400)[uVar3 * 0x59] & 0x18) != 0) {
                      return 4;
                    }
                    _zsclose((int)(sword)param_1,0);
                    return 4;
                  }
                  goto loc_408B3FE;
                }
              }
              else {
                *(uint *)(unk_40B51BC + iVar5 + 0x3e) = *(uint *)(unk_40B51BC + iVar5 + 0x3e) | 0x10
                ;
              }
              if (-1 < (char)bVar9) {
                (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 8;
                *(int *)(DAT_40b5423 + iVar7 + 5) = *(int *)(DAT_40b5423 + iVar7 + 5) + -1;
              }
              iVar5 = (*(code *)(&_linesw)[(char)unk_40B51BC[iVar5 + 0x45] * 0xc])
                                ((int)(sword)param_1,puVar1);
              return iVar5;
            }
            _ns_sleep(0,2000000000);
            sub_408CF32(uVar3,5,0);
            if ((bVar9 & 0xc0) == 0x40) {
              _ns_sleep(0,2000000000);
            }
            if ((char)bVar9 < '\0') goto loc_408B54A;
loc_408B40A:
          } while ((*(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 0x10) == 0);
          iVar8 = _sleep(DAT_40b52d0 + iVar7,0x11c);
          if (iVar8 != 0) {
            iVar5 = *(int *)(DAT_40b5423 + iVar7 + 5);
            *(int *)(DAT_40b5423 + iVar7 + 5) = iVar5 + -1;
            if ((iVar5 == 1) && (((&DAT_40b5400)[uVar3 * 0x59] & 0x18) == 0)) {
              (&DAT_40b5400)[uVar3 * 0x59] = 0;
              _zsrelease(uVar3);
            }
            return 4;
          }
        } while( true );
      }
    }
    iVar5 = 0x10;
  }
  else {
    iVar5 = 6;
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=2338 start=0x408b62e */

void _zsclose(word param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  char cStack_49;
  
  uVar16 = param_1 & 0x1f;
  iVar17 = uVar16 * 0x164;
  piVar19 = (int *)(DAT_40b52d0 + iVar17);
  puVar2 = *(undefined **)(DAT_40b52d0 + iVar17 + 0xc);
  iVar1 = uVar16 * 0x86;
  uVar3 = *(undefined4 *)(dword_40B57D4 + 0x28);
  uVar4 = *(undefined4 *)(dword_40B57D4 + 0x2c);
  uVar5 = *(undefined4 *)(dword_40B57D4 + 0x30);
  uVar6 = *(undefined4 *)(dword_40B57D4 + 0x34);
  uVar7 = *(undefined4 *)(dword_40B57D4 + 0x38);
  uVar8 = *(undefined4 *)(dword_40B57D4 + 0x3c);
  uVar9 = *(undefined4 *)(dword_40B57D4 + 0x40);
  uVar10 = *(undefined4 *)(dword_40B57D4 + 0x44);
  uVar11 = *(undefined4 *)(dword_40B57D4 + 0x48);
  uVar12 = *(undefined4 *)(dword_40B57D4 + 0x4c);
  uVar13 = *(undefined4 *)(dword_40B57D4 + 0x50);
  uVar14 = *(undefined4 *)(dword_40B57D4 + 0x54);
  uVar15 = *(undefined4 *)(dword_40B57D4 + 0x58);
  iVar18 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar18 == 0) {
    (**(code **)(unk_40AE4B0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))(unk_40B51BC + iVar1);
  }
  iVar18 = dword_40B57D4;
  *(undefined4 *)(dword_40B57D4 + 0x28) = uVar3;
  *(undefined4 *)(iVar18 + 0x2c) = uVar4;
  *(undefined4 *)(iVar18 + 0x30) = uVar5;
  *(undefined4 *)(iVar18 + 0x34) = uVar6;
  *(undefined4 *)(iVar18 + 0x38) = uVar7;
  *(undefined4 *)(iVar18 + 0x3c) = uVar8;
  *(undefined4 *)(iVar18 + 0x40) = uVar9;
  *(undefined4 *)(iVar18 + 0x44) = uVar10;
  *(undefined4 *)(iVar18 + 0x48) = uVar11;
  *(undefined4 *)(iVar18 + 0x4c) = uVar12;
  *(undefined4 *)(iVar18 + 0x50) = uVar13;
  *(undefined4 *)(iVar18 + 0x54) = uVar14;
  *(undefined4 *)(iVar18 + 0x58) = uVar15;
  sub_408CF32(uVar16,2,2);
  cStack_49 = (char)param_1;
  if ((cStack_49 < '\0') ||
     ((((*(uint *)(unk_40B51BC + iVar1 + 0x3e) & 0x202) != 0 ||
       ((*(uint *)(unk_40B51BC + iVar1 + 0x3e) & 4) == 0)) &&
      (*(int *)(unk_40B5418 + iVar17 + 0x10) == 0)))) {
    sub_408CF32(uVar16,0,0);
  }
  iVar18 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar18 == 0) {
    _ttyclose(unk_40B51BC + iVar1);
  }
  iVar1 = dword_40B57D4;
  *(undefined4 *)(dword_40B57D4 + 0x28) = uVar3;
  *(undefined4 *)(iVar1 + 0x2c) = uVar4;
  *(undefined4 *)(iVar1 + 0x30) = uVar5;
  *(undefined4 *)(iVar1 + 0x34) = uVar6;
  *(undefined4 *)(iVar1 + 0x38) = uVar7;
  *(undefined4 *)(iVar1 + 0x3c) = uVar8;
  *(undefined4 *)(iVar1 + 0x40) = uVar9;
  *(undefined4 *)(iVar1 + 0x44) = uVar10;
  *(undefined4 *)(iVar1 + 0x48) = uVar11;
  *(undefined4 *)(iVar1 + 0x4c) = uVar12;
  *(undefined4 *)(iVar1 + 0x50) = uVar13;
  *(undefined4 *)(iVar1 + 0x54) = uVar14;
  *(undefined4 *)(iVar1 + 0x58) = uVar15;
  (&DAT_40b5400)[uVar16 * 0x59] = (&DAT_40b5400)[uVar16 * 0x59] & 0x146;
  if (*(int *)(unk_40B5418 + iVar17 + 0x10) == 0) {
    _delay(1);
    *puVar2 = 1;
    _delay(1);
    *puVar2 = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 4) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 8) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 0xc) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 0x10) = 0;
    *(undefined4 *)(unk_40B5418 + iVar17) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17) = 0;
    (&DAT_40b5400)[uVar16 * 0x59] = 0;
    _zsrelease(uVar16);
    if (*piVar19 != 0) {
      _kfree(*piVar19,dword_40B51A8 * 2);
      *piVar19 = 0;
    }
  }
  _wakeup(piVar19);
  return;
}
/* GHIDRADEC_FUNCTION index=2339 start=0x408b8d8 */

undefined4 _zsread(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1 & 0x1f;
  iVar1 = uVar2 * 0x86;
  uVar3 = (**(code **)(DAT_40ae4b4 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))
                    (unk_40B51BC + iVar1,param_2);
  if (((DAT_40b5423[uVar2 * 0x164] & 1) == 0) && (-1 < (char)unk_40B51BC[iVar1 + 0x3f])) {
    sub_408C552(uVar2);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2340 start=0x408b964 */

void _zswrite(word param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (sword)(param_1 & 0x1f) * 0x86;
  (**(code **)(DAT_40ae4b8 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))(unk_40B51BC + iVar1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2341 start=0x408b9a8 */

int _zsioctl(word param_1,int param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar2 = param_1 & 0x1f;
  iVar1 = uVar2 * 0x86;
  iVar3 = uVar2 * 0x164;
  iVar4 = (**(code **)(DAT_40ae4bc + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))
                    (unk_40B51BC + iVar1,param_2,param_3,param_4);
  if (-1 < iVar4) {
    return iVar4;
  }
  iVar4 = _ttioctl(unk_40B51BC + iVar1,param_2,param_3,param_4);
  if (iVar4 < 0) {
    iVar4 = 0;
    if (param_2 == 0x20007479) {
      uVar7 = 1;
      uVar6 = 4;
      goto loc_408BB3E;
    }
    if (param_2 < 0x2000747a) {
      if (param_2 == -0x7ffb8b93) {
        uVar7 = 0;
      }
      else {
        if (-0x7ffb8b93 < param_2) {
          if (param_2 == -0x7ffb85ff) {
            *(uint *)(DAT_40b53f8 + iVar3) = *param_3;
            *(word *)(DAT_40b53f8 + iVar3 + 10) = *(word *)(DAT_40b53f8 + iVar3 + 10) | 0x80;
            goto loc_408BB90;
          }
          if (param_2 == 0x20007478) {
            uVar7 = 2;
            uVar6 = 4;
            goto loc_408BB3E;
          }
loc_408BB8E:
          iVar4 = 0x19;
          goto loc_408BB90;
        }
        if (param_2 == -0x7ffb8b95) {
          uVar7 = 2;
        }
        else {
          if (param_2 != -0x7ffb8b94) goto loc_408BB8E;
          uVar7 = 1;
        }
      }
      uVar6 = sub_408D24A(*param_3,uVar7);
    }
    else {
      if (param_2 == 0x4004746a) {
        uVar6 = sub_408CF32(uVar2,0,3);
        uVar5 = sub_408D284(uVar6);
        *param_3 = uVar5;
        goto loc_408BB90;
      }
      if (0x4004746a < param_2) {
        if (param_2 == 0x40047a00) {
          *param_3 = *(uint *)(DAT_40b53f8 + iVar3);
          goto loc_408BB90;
        }
        if (param_2 == 0x40047a02) {
          *param_3 = (uint)(dword_40B51B8 == 2);
          goto loc_408BB90;
        }
        goto loc_408BB8E;
      }
      if (param_2 == 0x2000747a) {
        uVar7 = 2;
        uVar6 = 2;
      }
      else {
        if (param_2 != 0x2000747b) goto loc_408BB8E;
        uVar7 = 1;
        uVar6 = 2;
      }
    }
loc_408BB3E:
    sub_408CF32(uVar2,uVar6,uVar7);
    goto loc_408BB90;
  }
  if (param_2 == -0x7ff98bf6) {
loc_408BA72:
    uVar6 = 0;
  }
  else {
    if (param_2 < -0x7ff98bf5) {
      if (param_2 < -0x7ffb8b83) goto loc_408BB90;
      if (param_2 < -0x7ffb8b80) goto loc_408BA72;
      if (param_2 != -0x7ff98bf7) goto loc_408BB90;
    }
    else {
      if (param_2 == -0x7fdb8bec) goto loc_408BA72;
      if ((param_2 < -0x7fdb8bec) || (-0x7fdb8bea < param_2)) goto loc_408BB90;
    }
    uVar6 = 1;
  }
  sub_408BE8E(uVar2,uVar6);
loc_408BB90:
  if (((DAT_40b5423[iVar3] & 1) == 0) && (-1 < (char)unk_40B51BC[iVar1 + 0x3f])) {
    sub_408C552(uVar2);
  }
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    iVar4 = 0;
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2342 start=0x408bbd2 */

undefined4 _zsstop(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  
  iVar2 = (sword)(*(word *)(param_1 + 0x38) & 0x1f) * 0x164;
  uVar3 = 0;
  cVar4 = '\0';
  bVar5 = false;
  bVar6 = (*(byte *)(param_1 + 0x41) & 0x20) == 0;
  if (!bVar6) {
    if ((unk_40B52E0[iVar2 + 0x123] & 1) == 0) {
      *(undefined4 *)(unk_40B52E0 + iVar2 + 0x28) = *(undefined4 *)(unk_40B52E0 + iVar2 + 0x100);
    }
    else {
      _dma_abort(unk_40B52E0 + iVar2);
    }
    uVar3 = *(uint *)(param_1 + 0x3e);
    bVar5 = (int)uVar3 < 0;
    bVar6 = false;
    if ((uVar3 & 0x100) == 0) {
      uVar1 = uVar3 | 8;
      *(uint *)(param_1 + 0x3e) = uVar1;
      bVar5 = (int)uVar1 < 0;
      bVar6 = uVar1 == 0;
    }
  }
  return CONCAT22((sword)(uVar3 >> 0x10),(word)(byte)(cVar4 << 4 | bVar5 << 3 | bVar6 << 2));
}
/* GHIDRADEC_FUNCTION index=2343 start=0x408bc40 */

void _zsselect(word param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (sword)(param_1 & 0x1f) * 0x86;
  (**(code **)(DAT_40ae4d4 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))(unk_40B51BC + iVar1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2344 start=0x408c27e */

uint _zs_tc(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int aiStack_14 [2];
  word wStack_a;
  word wStack_6;
  
  if ((param_1 == 0x86) && (param_2 == 0x10)) {
    uVar1 = 0x356;
    if (_dma_chip == 0x139) {
      uVar1 = 0x20356;
    }
  }
  else {
    iVar4 = 0;
    do {
      if (iVar4 == 0) {
        iVar3 = 10000000;
        if (_dma_chip == 0x139) {
          iVar3 = 0x3836a0;
        }
      }
      else {
        iVar3 = 0x3836a0;
        if (_dma_chip == 0x139) {
          iVar3 = 4000000;
        }
      }
      iVar2 = (param_2 * param_1 + iVar3) / (param_2 * 2 * param_1);
      *(int *)(&stack0xfffffff4 + iVar4 * 4) = iVar2 + -2;
      iVar3 = (iVar3 << 7) / (param_2 * 2 * iVar2) + param_1 * -0x80;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      aiStack_14[iVar4] = iVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    if (aiStack_14[0] < aiStack_14[1]) {
      uVar1 = wStack_a | 0x20000;
    }
    else {
      uVar1 = (uint)wStack_6;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2345 start=0x408d4b0 */

void _zsputc(word param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  
  uVar2 = param_1 & 0x1f;
  if ((param_1 & 0x1f) == 0) {
    pbVar5 = (byte *)(_slot_id_bmap + 0x2018001);
  }
  else {
    pbVar5 = (byte *)(_slot_id_bmap + 0x2018000);
  }
  if (uVar2 < 3) {
    if (*(int *)(unk_40B52C8 + uVar2 * 4) == 0) {
      *(undefined4 *)(unk_40B52C8 + uVar2 * 4) = 1;
      sub_408D2BE(pbVar5,0x2580);
    }
    if (param_2 != 0) {
      iVar4 = 30000;
      do {
        _delay(1);
        if ((*pbVar5 & 4) != 0) break;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      _delay(1);
      _delay(1);
      *(undefined *)(_slot_id_bmap + 0x2018001) = 3;
      _delay(1);
      bVar1 = *(byte *)(_slot_id_bmap + 0x2018001);
      bVar3 = 0x10;
      if ((param_1 & 0x1f) != 0) {
        bVar3 = 2;
      }
      _delay(1);
      pbVar5[2] = (byte)param_2;
      _delay(1);
      do {
      } while ((*pbVar5 & 4) == 0);
      _delay(1);
      if ((bVar3 & bVar1) == 0) {
        *pbVar5 = 0x28;
      }
      _delay(1);
      if (param_2 == 10) {
        _zsputc((int)(sword)param_1,0xd);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2346 start=0x408d5de */

uint _zsgetc(word param_1)

{
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = param_1 & 0x1f;
  if ((param_1 & 0x1f) == 0) {
    pbVar2 = (byte *)(_slot_id_bmap + 0x2018001);
  }
  else {
    pbVar2 = (byte *)(_slot_id_bmap + 0x2018000);
  }
  if (uVar1 < 3) {
    if (*(int *)(unk_40B52C8 + uVar1 * 4) == 0) {
      *(undefined4 *)(unk_40B52C8 + uVar1 * 4) = 1;
      sub_408D2BE(pbVar2,0x2580);
    }
    do {
      _delay(1);
    } while ((*pbVar2 & 1) == 0);
    _delay(1);
    uVar1 = pbVar2[2] & 0x7f;
    if (uVar1 == 0xd) {
      uVar1 = 10;
    }
    _zsputc((int)(sword)param_1,uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2347 start=0x408d686 */

uint _zstrygetc(word param_1)

{
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = param_1 & 0x1f;
  if ((param_1 & 0x1f) == 0) {
    pbVar2 = (byte *)(_slot_id_bmap + 0x2018001);
  }
  else {
    pbVar2 = (byte *)(_slot_id_bmap + 0x2018000);
  }
  if (uVar1 < 3) {
    _delay(1);
    if ((*pbVar2 & 1) == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      _delay(1);
      uVar1 = pbVar2[2] & 0x7f;
      if (uVar1 == 0xd) {
        uVar1 = 10;
      }
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2348 start=0x408d706 */

undefined4 _zsacquire(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 uVar1;
  
  if (((undefined *)(&off_40B243E)[param_1 * 2] == _zi_null) ||
     (param_3 == (undefined *)(&off_40B243E)[param_1 * 2])) {
    (&_zs_com)[param_1 * 2] = param_2;
    (&off_40B243E)[param_1 * 2] = param_3;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2349 start=0x408d73e */

void _zsrelease(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined *)(_slot_id_bmap + 0x2018001);
  }
  else {
    puVar1 = (undefined *)(_slot_id_bmap + 0x2018000);
  }
  _delay(1);
  *puVar1 = 1;
  _delay(1);
  *puVar1 = 0;
  (&_zs_com)[param_1 * 2] = 0;
  (&off_40B243E)[param_1 * 2] = _zi_null;
  return;
}

