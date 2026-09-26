
/* WARNING: Removing unreachable block (ram,0xf00d9ab4) */
/* WARNING: Removing unreachable block (ram,0xf00d9a94) */
/* WARNING: Removing unreachable block (ram,0xf00d9a7c) */
/* WARNING: Removing unreachable block (ram,0xf00d9a54) */
/* WARNING: Removing unreachable block (ram,0xf00d9a30) */
/* WARNING: Removing unreachable block (ram,0xf00d9a08) */
/* WARNING: Removing unreachable block (ram,0xf00d99ec) */
/* WARNING: Removing unreachable block (ram,0xf00d99d0) */
/* WARNING: Removing unreachable block (ram,0xf00d99b4) */
/* WARNING: Removing unreachable block (ram,0xf00d999c) */
/* WARNING: Removing unreachable block (ram,0xf00d9974) */
/* WARNING: Removing unreachable block (ram,0xf00d9964) */
/* WARNING: Removing unreachable block (ram,0xf00d993c) */
/* WARNING: Removing unreachable block (ram,0xf00d9918) */
/* WARNING: Removing unreachable block (ram,0xf00d98f0) */
/* WARNING: Removing unreachable block (ram,0xf00d98bc) */
/* WARNING: Removing unreachable block (ram,0xf00d9894) */
/* WARNING: Removing unreachable block (ram,0xf00d9870) */
/* WARNING: Removing unreachable block (ram,0xf00d9840) */
/* WARNING: Removing unreachable block (ram,0xf00d9810) */
/* WARNING: Removing unreachable block (ram,0xf00d97fc) */
/* WARNING: Removing unreachable block (ram,0xf00d97d8) */
/* WARNING: Removing unreachable block (ram,0xf00d97a0) */
/* WARNING: Removing unreachable block (ram,0xf00d9774) */
/* WARNING: Removing unreachable block (ram,0xf00d974c) */
/* WARNING: Removing unreachable block (ram,0xf00d9738) */
/* WARNING: Removing unreachable block (ram,0xf00d9764) */
/* WARNING: Removing unreachable block (ram,0xf00d9784) */
/* WARNING: Removing unreachable block (ram,0xf00d97b0) */
/* WARNING: Removing unreachable block (ram,0xf00d97e8) */
/* WARNING: Removing unreachable block (ram,0xf00d9808) */
/* WARNING: Removing unreachable block (ram,0xf00d982c) */
/* WARNING: Removing unreachable block (ram,0xf00d9868) */
/* WARNING: Removing unreachable block (ram,0xf00d9878) */
/* WARNING: Removing unreachable block (ram,0xf00d98a8) */
/* WARNING: Removing unreachable block (ram,0xf00d98d8) */
/* WARNING: Removing unreachable block (ram,0xf00d990c) */
/* WARNING: Removing unreachable block (ram,0xf00d9928) */
/* WARNING: Removing unreachable block (ram,0xf00d9954) */
/* WARNING: Removing unreachable block (ram,0xf00d996c) */
/* WARNING: Removing unreachable block (ram,0xf00d9988) */
/* WARNING: Removing unreachable block (ram,0xf00d99a8) */
/* WARNING: Removing unreachable block (ram,0xf00d99c8) */
/* WARNING: Removing unreachable block (ram,0xf00d99d8) */
/* WARNING: Removing unreachable block (ram,0xf00d99fc) */
/* WARNING: Removing unreachable block (ram,0xf00d9a20) */
/* WARNING: Removing unreachable block (ram,0xf00d9a44) */
/* WARNING: Removing unreachable block (ram,0xf00d9a6c) */
/* WARNING: Removing unreachable block (ram,0xf00d9a88) */
/* WARNING: Removing unreachable block (ram,0xf00d9aa4) */
/* WARNING: Removing unreachable block (ram,0xf00d985c) */
/* WARNING: Removing unreachable block (ram,0xf00d9720) */

undefined8 -[IOAudio initFromDeviceDescription:](uint param_1,undefined4 param_2,int param_3)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [14];
  undefined (*pauVar3) [17];
  undefined8 *puVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  undefined (*pauVar10) [13];
  undefined (*pauVar11) [13];
  int iVar12;
  code *pcVar13;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar14;
  undefined *puVar15;
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
  *(uint *)((int)register0x00000038 + -0x10) = param_1;
  puVar5 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142258;
  puVar15 = aKernelserverin;
  _objc_msgSendSuper(puVar5,paInitfromdevice,param_3);
  if (puVar5 != (undefined *)0x0) {
    uVar6 = param_1;
    _objc_msgSend(param_1,paAttachinterrup_0);
    if (uVar6 != 0) {
      param_1 = 0;
      goto locret_F00D9ABC;
    }
    _task_self();
    pauVar2 = paInterruptport_0;
    uVar7 = param_1;
    _objc_msgSend(param_1,paInterruptport_0);
    _port_set_backlog_EXTERNAL(uVar6,uVar7,0x10);
    uVar6 = param_1;
    _objc_msgSend(param_1,paReset);
    if ((uVar6 & 0xff) != 0) {
      _objc_msgSend(param_1,paInitaudiohardw);
      _objc_msgSend(param_3,paConfigtable_0);
      if (param_3 == 0) {
        puVar5 = aAudioNoConfigt;
      }
      else {
        _objc_msgSend();
        puVar14 = (undefined *)((int)register0x00000038 + -0x118);
        _strlen(aKernelserverin);
        _strncpy(puVar14,param_3,0x100 - (int)puVar15);
        _strcat(puVar14,aKernelserverin);
        puVar5 = puVar14;
        _objc_lookUpClass();
        if (puVar5 == (undefined *)0x0) {
          _IOLog(aAudioNoKernelS,puVar14);
          goto loc_F00D9834;
        }
        _objc_msgSend(puVar5,paKernelserverin_0);
        if (puVar5 != (undefined *)0x0) {
          _audioKernServInit();
          _audio_makeIMuLawTab();
          uVar8 = 0x20;
          _IOMalloc();
          *(undefined4 *)(param_1 + 0x174) = uVar8;
          puVar4 = paIoaudio;
          puVar9 = paIoaudio;
          _objc_msgSend(paIoaudio,paInstance_0);
          if (puVar9 != (undefined8 *)0x0) {
            _IOLog(aAudioReplacing);
          }
          _objc_msgSend(puVar4,paSetinstance,param_1);
          pauVar11 = paAudiochannel;
          puVar1 = paAlloc;
          pauVar10 = paAudiochannel;
          _objc_msgSend(paAudiochannel,paAlloc);
          _objc_msgSend();
          *(undefined (**) [13])(param_1 + 0x128) = pauVar10;
          pauVar10 = paAddchannel;
          _objc_msgSend(puVar4,paAddchannel);
          _objc_msgSend(pauVar11,puVar1);
          _objc_msgSend();
          *(undefined (**) [13])(param_1 + 300) = pauVar11;
          _objc_msgSend(puVar4,pauVar10);
          pauVar3 = paSetlocalchanne;
          _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paSetlocalchanne,0);
          iVar12 = *(int *)(param_1 + 300);
          _objc_msgSend(iVar12,pauVar3,0);
          _task_self();
          _port_set_allocate_EXTERNAL();
          if (iVar12 != 0) {
            _IOLog(aAudioPortSetAl,iVar12);
          }
          *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)((int)register0x00000038 + -0x11c);
          uVar6 = param_1;
          _objc_msgSend(param_1,pauVar2);
          _task_self();
          _port_set_add_EXTERNAL();
          puVar5 = (undefined *)0xf00fc000;
          if (uVar6 != 0) {
            puVar5 = aAudioPortSetAd;
            _IOLog();
          }
          _task_self();
          _port_allocate_EXTERNAL();
          puVar15 = (undefined *)0xf00fc000;
          if (puVar5 != (undefined *)0x0) {
            puVar15 = aAudioPortAlloc;
            _IOLog();
          }
          *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)((int)register0x00000038 + -0x11c);
          _task_self();
          _port_set_add_EXTERNAL();
          if (puVar15 != (undefined *)0x0) {
            _IOLog(aAudioPortSetAd);
          }
          uVar8 = *(undefined4 *)(param_1 + 0x134);
          _IOConvertPort(uVar8,1,0);
          *(undefined4 *)(param_1 + 0x134) = uVar8;
          pauVar10 = paAudiocommand;
          _objc_msgSend(paAudiocommand,puVar1);
          _objc_msgSend();
          *(undefined (**) [13])(param_1 + 0x130) = pauVar10;
          _objc_msgSend(param_1,paSettimeout,0xffffffff);
          pcVar13 = sub_F00D7228;
          _IOForkThread(sub_F00D7228,param_1);
          _IOSetThreadPolicy();
          _IOSetThreadPriority(pcVar13,0x1e);
          _IOForkThread(sub_F00D73BC,param_1);
          _objc_msgSend(param_1,paRegisterdevice);
          goto locret_F00D9ABC;
        }
        puVar5 = aAudioNoKernelS_0;
      }
      param_1 = 0;
      _IOLog(puVar5);
      goto locret_F00D9ABC;
    }
  }
loc_F00D9834:
  param_1 = 0;
locret_F00D9ABC:
  return CONCAT44(param_2,param_1);
}

