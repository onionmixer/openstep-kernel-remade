
void _snd_link_shutdown(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_D5;
  int unaff_A2;
  
  *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = _active_threads;
  if (param_1 == 0) {
    iVar7 = 0;
    if (dword_40B21D4 != 0) {
      iVar6 = 0;
      do {
        _assert_wait(0,1);
        iVar5 = _hz;
        if (_hz < 0) {
          iVar5 = _hz + 1;
        }
        _thread_set_timeout(iVar5 >> 1);
        _thread_block();
        _untimeout(_thread_timeout,_active_threads);
      } while ((_sound_active != 0) && (iVar6 = iVar6 + 1, iVar6 < 4));
    }
  }
  else {
    *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = _active_threads;
    iVar7 = *(int *)(dword_40C6DFC + 0x2e);
    unaff_D5 = dword_40C6DFC;
  }
  if (unk_40B50C0 + param_1 * 8 != *(undefined **)(unk_40B50C0 + param_1 * 8)) {
    do {
      puVar1 = *(undefined **)(unaff_A2 + 0x2c);
      puVar2 = *(undefined **)(unaff_A2 + 0x30);
      if (puVar1 == unk_40B50C0 + param_1 * 8) {
        *(undefined **)(unk_40B50C0 + param_1 * 8 + 4) = puVar2;
      }
      else {
        *(undefined **)(puVar1 + 0x30) = puVar2;
      }
      if (puVar2 == unk_40B50C0 + param_1 * 8) {
        *(undefined **)(unk_40B50C0 + param_1 * 8) = puVar1;
      }
      else {
        *(undefined **)(puVar2 + 0x2c) = puVar1;
      }
      puVar4 = (undefined4 *)(&dword_40B50A4)[param_1 * 2];
      if (puVar4 == &unk_40B50A0 + param_1 * 2) {
        (&unk_40B50A0)[param_1 * 2] = unaff_A2;
      }
      else {
        puVar4[0xb] = unaff_A2;
      }
      *(undefined4 **)(unaff_A2 + 0x30) = puVar4;
      *(undefined4 **)(unaff_A2 + 0x2c) = &unk_40B50A0 + param_1 * 2;
      (&dword_40B50A4)[param_1 * 2] = unaff_A2;
    } while (unk_40B50C0 + param_1 * 8 != *(undefined **)(unk_40B50C0 + param_1 * 8));
  }
  if (&unk_40B50D0 + param_1 * 2 != (undefined4 *)(&unk_40B50D0)[param_1 * 2]) {
    do {
      puVar4 = *(undefined4 **)(unaff_A2 + 0x2c);
      puVar3 = *(undefined4 **)(unaff_A2 + 0x30);
      if (puVar4 == &unk_40B50D0 + param_1 * 2) {
        (&dword_40B50D4)[param_1 * 2] = puVar3;
      }
      else {
        puVar4[0xc] = puVar3;
      }
      if (puVar3 == &unk_40B50D0 + param_1 * 2) {
        (&unk_40B50D0)[param_1 * 2] = puVar4;
      }
      else {
        puVar3[0xb] = puVar4;
      }
      puVar4 = (undefined4 *)(&dword_40B50B4)[param_1 * 2];
      if (puVar4 == &unk_40B50B0 + param_1 * 2) {
        (&unk_40B50B0)[param_1 * 2] = unaff_A2;
      }
      else {
        puVar4[0xb] = unaff_A2;
      }
      *(undefined4 **)(unaff_A2 + 0x30) = puVar4;
      *(undefined4 **)(unaff_A2 + 0x2c) = &unk_40B50B0 + param_1 * 2;
      (&dword_40B50B4)[param_1 * 2] = unaff_A2;
    } while (&unk_40B50D0 + param_1 * 2 != (undefined4 *)(&unk_40B50D0)[param_1 * 2]);
  }
  if (iVar7 != 0) {
    _assert_wait(unaff_D5,1);
    _thread_set_timeout(_hz);
    _thread_block();
    _untimeout(_thread_timeout,_active_threads);
  }
  *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = 0;
  sub_40846D2(param_1);
  return;
}

