
uint _evmmap(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uStack_20;
  code *pcStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined *puStack_10;
  
  puVar5 = (undefined4 *)&stack0xfffffff4;
  if (_eventsOpen == 0) {
    dword_40B4F66 = _totalShmemSize;
    puStack_10 = (undefined *)(~_page_mask & _page_mask + _totalShmemSize);
    if (puStack_10 <= param_2) {
      return 0xffffffff;
    }
    puStack_14 = &dword_40B4F6A;
    uStack_18 = _kernel_map;
    pcStack_1c = (code *)0x4067b86;
    iVar2 = _kmem_alloc_wired();
    piVar1 = dword_40B4F6A;
    if (iVar2 != 0) {
      puStack_10 = aEvNoSpaceForSh;
                    /* WARNING: Subroutine does not return */
      puStack_14 = (undefined4 *)0x4067b9a;
      _panic();
    }
    _eop = dword_40B4F6A;
    *dword_40B4F6A = 8;
    piVar1[1] = *piVar1 + 0xcca;
    _evg = (int)piVar1 + *piVar1;
    _evs = piVar1[1] + (int)piVar1;
    *(undefined *)(_evg + 0x45) = 1;
    *(undefined *)(_evg + 0x46) = 1;
    dword_40B4F92 = _evg;
    *(undefined2 *)(_evg + 0x48) = 0x50;
    _waitFrameRate = 5;
    _waitSustain = 0x14;
    _waitSusTime = 0;
    dword_40B4FAE = 0x50;
    dword_40B4F92 = dword_40B4F92 + 0x14;
    dword_40B4F96 = _process_mouse_event;
    dword_40B4F72 = &_keySema;
    puStack_10 = (undefined *)0x4067c34;
    iVar2 = _adb_keybd_present();
    if (iVar2 == 0) {
      dword_40B4F76 = _process_kbd_event;
    }
    else {
      dword_40B4F76 = _process_adb_event;
    }
    puStack_10 = (undefined *)dword_40B4FAE;
    puStack_14 = (undefined4 *)0x4067c5a;
    _InitMouse();
    puStack_14 = (undefined4 *)0x0;
    uStack_18 = 0x4067c62;
    _InitKbd();
    _eventsOpen = 1;
    uStack_18 = 0;
    pcStack_1c = _evvert;
    puVar5 = &uStack_20;
    uStack_20 = 2;
    _callout_dispatch();
    _eventTask = *(undefined4 *)(_active_threads + 0xc);
  }
  *(uint *)((int)puVar5 + -4) = (int)dword_40B4F6A + param_2;
  *(undefined4 *)((int)puVar5 + -8) = 0x4067c98;
  uVar3 = _pmap_kernel();
  *(undefined4 *)((int)puVar5 + -8) = uVar3;
  *(undefined4 *)((int)puVar5 + -0xc) = 0x4067ca0;
  uVar4 = _pmap_resident_extract();
  return uVar4 >> (_page_shift & 0x3f);
}

