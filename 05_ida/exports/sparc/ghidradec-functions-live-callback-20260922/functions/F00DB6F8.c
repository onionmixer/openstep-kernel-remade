
/* WARNING: Removing unreachable block (ram,0xf00dba14) */
/* WARNING: Removing unreachable block (ram,0xf00db8dc) */
/* WARNING: Removing unreachable block (ram,0xf00db8bc) */
/* WARNING: Removing unreachable block (ram,0xf00db888) */
/* WARNING: Removing unreachable block (ram,0xf00db864) */
/* WARNING: Removing unreachable block (ram,0xf00db928) */
/* WARNING: Removing unreachable block (ram,0xf00db8fc) */
/* WARNING: Removing unreachable block (ram,0xf00db9e4) */
/* WARNING: Removing unreachable block (ram,0xf00db9b0) */
/* WARNING: Removing unreachable block (ram,0xf00db988) */
/* WARNING: Removing unreachable block (ram,0xf00db960) */
/* WARNING: Removing unreachable block (ram,0xf00dbaa4) */
/* WARNING: Removing unreachable block (ram,0xf00dbadc) */
/* WARNING: Removing unreachable block (ram,0xf00db7d8) */
/* WARNING: Removing unreachable block (ram,0xf00db7a4) */
/* WARNING: Removing unreachable block (ram,0xf00db77c) */
/* WARNING: Removing unreachable block (ram,0xf00db754) */
/* WARNING: Removing unreachable block (ram,0xf00db774) */
/* WARNING: Removing unreachable block (ram,0xf00db798) */
/* WARNING: Removing unreachable block (ram,0xf00db7cc) */
/* WARNING: Removing unreachable block (ram,0xf00db7ec) */
/* WARNING: Removing unreachable block (ram,0xf00dbaec) */
/* WARNING: Removing unreachable block (ram,0xf00dbac8) */
/* WARNING: Removing unreachable block (ram,0xf00db980) */
/* WARNING: Removing unreachable block (ram,0xf00db9a4) */
/* WARNING: Removing unreachable block (ram,0xf00db9d8) */
/* WARNING: Removing unreachable block (ram,0xf00db9f8) */
/* WARNING: Removing unreachable block (ram,0xf00db918) */
/* WARNING: Removing unreachable block (ram,0xf00db844) */
/* WARNING: Removing unreachable block (ram,0xf00db86c) */
/* WARNING: Removing unreachable block (ram,0xf00db894) */
/* WARNING: Removing unreachable block (ram,0xf00db8c8) */
/* WARNING: Removing unreachable block (ram,0xf00dba08) */
/* WARNING: Removing unreachable block (ram,0xf00dba90) */
/* WARNING: Removing unreachable block (ram,0xf00db810) */

undefined8 -[AudioStream control:atTime:](uint param_1,undefined4 param_2,uint param_3,int *param_4)

{
  undefined (*pauVar1) [24];
  undefined4 *puVar2;
  undefined7 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 *puVar8;
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
  if (param_3 == 1) {
    if (*param_4 == 0) {
      if (param_4[1] == 0) {
        *(undefined *)(param_1 + 0x24) = 0;
        _objc_msgSend(param_1,paSendcontrolmes,3,8);
        pauVar1 = paDatapendingfor;
        uVar6 = *(undefined4 *)(param_1 + 8);
        uVar5 = param_1;
        _objc_msgSend(param_1,paChannel);
        _objc_msgSend(uVar6,pauVar1,uVar5);
        goto locret_F00DBAF4;
      }
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    else {
      *(int *)(param_1 + 0x4c) = *param_4;
    }
    puVar4 = (undefined4 *)0x28;
    *(int *)(param_1 + 0x50) = param_4[1];
    _IOMalloc();
    puVar8 = (undefined4 *)(param_1 + 0x3c);
    iVar7 = param_1 + 0x4c;
    if (*(int *)(param_1 + 0x3c) == 0) {
      puVar2 = puVar4;
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar2 != (undefined4 *)0x0) {
        _IOLog(aAudioStreamCon,aMachErr);
        _IOLog(aAudioDriverErr);
      }
      if (dword_F012EF3C == (undefined7 *)0x0) {
        puVar3 = paNxlock;
        _objc_msgSend(paNxlock,paAlloc);
        _objc_msgSend();
        dword_F012EF3C = puVar3;
      }
      _objc_msgSend(dword_F012EF3C,paLock);
      dword_F012EF38 = *(undefined4 *)(param_1 + 0x3c);
loc_F00DBA04:
      _current_task_EXTERNAL();
      _kernel_thread();
    }
  }
  else if (param_3 < 2) {
    if (*param_4 == 0) {
      if (param_4[1] == 0) {
        *(undefined *)(param_1 + 0x24) = 1;
        _objc_msgSend(param_1,paSendcontrolmes,2,4);
        goto locret_F00DBAF4;
      }
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    else {
      *(int *)(param_1 + 0x44) = *param_4;
    }
    puVar4 = (undefined4 *)0x28;
    *(int *)(param_1 + 0x48) = param_4[1];
    _IOMalloc();
    puVar8 = (undefined4 *)(param_1 + 0x38);
    iVar7 = param_1 + 0x44;
    if (*(int *)(param_1 + 0x38) == 0) {
      puVar2 = puVar4;
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar2 != (undefined4 *)0x0) {
        _IOLog(aAudioStreamCon,aMachErr);
        _IOLog(aAudioDriverErr);
      }
      if (dword_F012EF3C == (undefined7 *)0x0) {
        puVar3 = paNxlock;
        _objc_msgSend(paNxlock,paAlloc);
        _objc_msgSend();
        dword_F012EF3C = puVar3;
      }
      _objc_msgSend(dword_F012EF3C,paLock);
      dword_F012EF38 = *(undefined4 *)(param_1 + 0x38);
      goto loc_F00DBA04;
    }
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 4) {
        _objc_msgSend(param_1,paMarkabortionse,1);
      }
      else {
        _IOLog(aAudioUnrecogni,param_3);
      }
      goto locret_F00DBAF4;
    }
    if (*param_4 == 0) {
      if (param_4[1] == 0) {
        uVar5 = param_1;
        _objc_msgSend(param_1,paMarkabortionse,0);
        if ((uVar5 & 0xff) == 0) {
          _objc_msgSend(param_1,paSendcontrolmes,4,0x10);
        }
        goto locret_F00DBAF4;
      }
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    else {
      *(int *)(param_1 + 0x54) = *param_4;
    }
    puVar4 = (undefined4 *)0x28;
    *(int *)(param_1 + 0x58) = param_4[1];
    _IOMalloc();
    puVar8 = (undefined4 *)(param_1 + 0x40);
    iVar7 = param_1 + 0x54;
    if (*(int *)(param_1 + 0x40) == 0) {
      puVar2 = puVar4;
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar2 != (undefined4 *)0x0) {
        _IOLog(aAudioStreamCon,aMachErr);
        _IOLog(aAudioDriverErr);
      }
      if (dword_F012EF3C == (undefined7 *)0x0) {
        puVar3 = paNxlock;
        _objc_msgSend(paNxlock,paAlloc);
        _objc_msgSend();
        dword_F012EF3C = puVar3;
      }
      _objc_msgSend(dword_F012EF3C,paLock);
      dword_F012EF38 = *(undefined4 *)(param_1 + 0x40);
      goto loc_F00DBA04;
    }
  }
  *puVar4 = 1;
  puVar4[1] = 0x28;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[6] = 0x2200030;
  puVar4[7] = 0;
  puVar4[8] = 0;
  puVar4[9] = 0;
  puVar4[4] = *puVar8;
  puVar4[7] = param_1;
  puVar4[8] = param_3;
  puVar4[9] = iVar7;
  _msg_send(puVar4,1,1000);
locret_F00DBAF4:
  return CONCAT44(param_2,param_1);
}

