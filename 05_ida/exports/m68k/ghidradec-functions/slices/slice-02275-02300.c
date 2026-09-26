/* GHIDRADEC_FUNCTION index=2275 start=0x4083af0 */

void _dspq_free_msg(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  if ((param_1 == (uint *)0x0) || (*(char *)(param_1 + 9) == '\0')) {
    iVar3 = _curipl();
    if (iVar3 == 0) {
      if (param_1 == (uint *)0x0) {
        if ((uint **)dword_40B5098 != &dword_40B5098) {
          do {
            puVar2 = dword_40B5098;
            dword_40B5098 = (uint *)dword_40B5098[6];
            if ((uint **)dword_40B5098 == &dword_40B5098) {
              dword_40B509C = (uint *)&dword_40B5098;
            }
            else {
              dword_40B5098[7] = (uint)&dword_40B5098;
            }
            _dspq_free_msg(puVar2);
          } while ((uint **)dword_40B5098 != &dword_40B5098);
        }
      }
      else {
        dword_40C6E4E = dword_40C6E4E + -1;
        if (*(char *)((int)param_1 + 0x23) == '\0') {
          if ((*param_1 < 5) && (*param_1 != 0)) {
            _vm_map_pageable(_kernel_map,~_page_mask & param_1[1],
                             ~_page_mask & _page_mask + param_1[2] + param_1[1],1);
            _vm_deallocate(_kernel_map,param_1[1],param_1[2]);
          }
          iVar3 = 0x26;
        }
        else {
          iVar3 = 0x26;
          uVar1 = *param_1;
          if (uVar1 != 0) {
            if (uVar1 < 5) {
              iVar3 = param_1[2] + 0x26;
            }
            else if (uVar1 == 9) {
              iVar3 = *(int *)(param_1[1] + 4) + 0x26;
            }
          }
        }
        _kfree(param_1,iVar3);
        if ((dword_40C6E4E < 0x200) && ((dword_40C6E84 & 0x40000) != 0)) {
          _port_set_add(dword_40C6EC0,dword_40C6EA8,0x10013);
          dword_40C6E84 = dword_40C6E84 & 0xfffbffff;
        }
      }
    }
    else {
      if ((uint **)dword_40B509C == &dword_40B5098) {
        dword_40B5098 = param_1;
      }
      else {
        dword_40B509C[6] = (uint)param_1;
      }
      param_1[7] = (uint)dword_40B509C;
      param_1[6] = (uint)&dword_40B5098;
      dword_40B509C = param_1;
      _callout_dispatch(4,_dspq_free_msg,0);
    }
  }
  else {
    dword_40C6E4E = dword_40C6E4E + -1;
    if ((uint **)dword_40B5094 == &dword_40B5090) {
      dword_40B5090 = param_1;
    }
    else {
      dword_40B5094[6] = (uint)param_1;
    }
    param_1[7] = (uint)dword_40B5094;
    param_1[6] = (uint)&dword_40B5090;
    dword_40B5094 = param_1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2276 start=0x4083d22 */

uint _dspq_awaited_conditions(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    switch(*dword_40C6E46) {
    case :
      uVar2 = dword_40C6E46[1];
      if ((uVar2 & 0x1800) != 0) {
        uVar1 = 8;
      }
      if ((uVar2 & 0x600) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((uVar2 & 0x100) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((uVar2 & 0x800000) == 0) goto loc_4083DDE;
    case :
      uVar2 = 1;
      break;
    case :
    case :
    case :
    case :
      uVar2 = 4;
      break;
    :
      goto loc_4083DDE;
    case :
    case :
    case :
    case :
      uVar2 = 2;
    }
    uVar1 = uVar2 | uVar1;
  }
loc_4083DDE:
  if ((((uVar1 == 0) && ((dword_40C6E84 & 0x10000) != 0)) && (dword_40C6DFC != 0)) &&
     (dword_40C6DFC + 0x3e != *(int *)(dword_40C6DFC + 0x3e))) {
    uVar1 = 4;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2277 start=0x4083e1c */

undefined4 _dspq_start_simple(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 1;
  if (param_2 == 0) {
    iVar3 = 2;
  }
  if ((dword_40C6E84 & 0x20000) == 0) {
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x18) = 4;
      _dma_enqueue(&_dsp_var,param_1 + 0xc);
    }
    else {
      piVar1 = *(int **)((&unk_40C6DF4)[iVar3] + 0x42);
      if (piVar1 == (int *)((&unk_40C6DF4)[iVar3] + 0x3e)) {
        *piVar1 = param_1;
      }
      else {
        piVar1[0xb] = param_1;
      }
      *(int **)(param_1 + 0x30) = piVar1;
      *(int *)(param_1 + 0x2c) = (&unk_40C6DF4)[iVar3] + 0x3e;
      *(int *)((&unk_40C6DF4)[iVar3] + 0x42) = param_1;
    }
    if (((dword_40C6E84 & 0x10000) != 0) || ((undefined4 **)dword_40C6E46 != &dword_40C6E46)) {
      iVar3 = _dspq_check();
      if (iVar3 != 0) {
        _callout_dispatch(1,_dspq_execute,0);
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2278 start=0x4083ef2 */

undefined4 _dspq_start_complex(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = **(int **)(*(int *)(param_1 + 8) + 0x3a);
  if ((dword_40C6E84 & 0x20000) == 0) {
    uVar3 = 0;
    piVar4 = &unk_40C6DF4;
    do {
      if (iVar2 == *piVar4) break;
      piVar4 = piVar4 + 1;
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x13);
    piVar4 = *(int **)(iVar2 + 0x42);
    if (piVar4 == (int *)(iVar2 + 0x3e)) {
      *piVar4 = param_1;
    }
    else {
      piVar4[0xb] = param_1;
    }
    *(int **)(param_1 + 0x30) = piVar4;
    *(int *)(param_1 + 0x2c) = iVar2 + 0x3e;
    *(int *)(iVar2 + 0x42) = param_1;
    if (param_2 == 0) {
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
    }
    else {
      if (((dword_40C6E76 != 1) && (dword_40C6E76 != 2)) && (dword_40C6E76 != 6)) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
      }
      if ((word_40C6E7A == 1) || ((dword_40C6E76 == 1 && (word_40C6E40 == uVar3)))) {
        _dsp_dev_loop();
      }
    }
    if (((dword_40C6E84 & 0x10000) != 0) || ((undefined4 **)dword_40C6E46 != &dword_40C6E46)) {
      iVar2 = _dspq_check();
      if (iVar2 != 0) {
        _callout_dispatch(1,_dspq_execute,0);
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2279 start=0x40842fe */

uint _snd_link_init(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  byte bVar18;
  undefined4 uStack_1c;
  int iStack_c;
  int iStack_8;
  
  piVar13 = &dword_40C6DFC;
  if (param_1 == 0) {
    piVar13 = &dword_40C6DF8;
  }
  iVar1 = *piVar13;
  *(int *)((int)&dword_40B511A + param_1 * 0x3e) = iVar1;
  iVar2 = *(int *)(iVar1 + 0x2a);
  if (param_1 == 0) {
    puVar10 = &dword_40C6E94;
    uStack_1c = __NXAudioSndoutDevice;
  }
  else {
    puVar10 = &dword_40C6E8C;
    uStack_1c = __NXAudioSndinDevice;
  }
  (*___NXAudioGetBufferOptions)(uStack_1c,&iStack_8,&iStack_c);
  iVar4 = iStack_8;
  iVar5 = _snd_get_owner(puVar10,_snd_var);
  if (iVar5 == 0) {
    uVar6 = _printf(aSounddspLinkCo);
  }
  else {
    dword_40B21D0 = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) | 8;
    dword_40B21D4 = 1;
    iVar5 = iVar4;
    iVar12 = iVar2;
    if (iVar2 < iVar4) {
      iVar5 = iVar2;
      iVar12 = iVar4;
    }
    iVar5 = iVar12 / iVar5;
    iVar11 = iStack_c;
    if (param_1 != 0) {
      iVar11 = *(int *)(iVar1 + 0x2e);
    }
    *(int *)((int)&unk_40B516C + param_1 * 4) = iVar11 * iVar12;
    puVar10 = &unk_40B50A0 + param_1 * 2;
    (&dword_40B50A4)[param_1 * 2] = puVar10;
    (&unk_40B50A0)[param_1 * 2] = puVar10;
    puVar3 = &unk_40B50B0 + param_1 * 2;
    (&dword_40B50B4)[param_1 * 2] = puVar3;
    (&unk_40B50B0)[param_1 * 2] = puVar3;
    *(undefined **)(unk_40B50C0 + param_1 * 8 + 4) = unk_40B50C0 + param_1 * 8;
    *(undefined **)(unk_40B50C0 + param_1 * 8) = unk_40B50C0 + param_1 * 8;
    (&dword_40B50D4)[param_1 * 2] = &unk_40B50D0 + param_1 * 2;
    (&unk_40B50D0)[param_1 * 2] = &unk_40B50D0 + param_1 * 2;
    *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = 0;
    uVar7 = _kalloc(iVar11 * 0x38);
    uVar8 = _kalloc(iVar5 * iVar11 * 0x38);
    uVar9 = _kalloc(_page_mask + *(int *)((int)&unk_40B516C + param_1 * 4) & ~_page_mask);
    *(undefined4 *)((int)&unk_40B5164 + param_1 * 4) = uVar9;
    if (iVar12 == iVar4) {
      sub_408462A(uVar7,uVar9,iVar11,iVar4,_snd_link_snd_complete,param_1,puVar10);
      *(int *)((int)&unk_40B5174 + param_1 * 4) = iVar11;
      sub_408462A(uVar8,*(undefined4 *)((int)&unk_40B5164 + param_1 * 4),iVar11 * iVar5,iVar2,
                  sub_4084AFE,unk_40B50E0 + param_1 * 0x3e,puVar3);
      *(int *)((int)&unk_40B517C + param_1 * 4) = iVar11 * iVar5;
    }
    else {
      sub_408462A(uVar7,uVar9,iVar11,iVar2,sub_4084AFE,unk_40B50E0 + param_1 * 0x3e,puVar3);
      *(int *)((int)&unk_40B517C + param_1 * 4) = iVar11;
      iVar11 = iVar11 * iVar5;
      sub_408462A(uVar8,*(undefined4 *)((int)&unk_40B5164 + param_1 * 4),iVar11,iVar4,
                  _snd_link_snd_complete,param_1,puVar10);
      *(int *)((int)&unk_40B5174 + param_1 * 4) = iVar11;
      (*___NXAudioSetBufferOptions)(uStack_1c,0,iStack_8,iVar11);
    }
    (*___NXAudioInitLinkedStream)(dword_40B21D0);
    cVar17 = 1 < param_1;
    cVar16 = SBORROW4(1,param_1);
    cVar14 = (int)(1 - param_1) < 0;
    cVar15 = param_1 == 1;
    if ((bool)cVar15) {
      bVar18 = cVar17;
      _printf(aSounddspCodecD);
    }
    else {
      puVar10 = &unk_40B50B0 + param_1 * 2;
      puVar3 = (undefined4 *)(&unk_40B50B0)[param_1 * 2];
      cVar17 = puVar10 < puVar3;
      cVar16 = SBORROW4((int)puVar10,(int)puVar3);
      iVar2 = (int)puVar10 - (int)puVar3;
      cVar15 = puVar10 == puVar3;
      while (cVar14 = iVar2 < 0, bVar18 = cVar17, !(bool)cVar15) {
        iVar2 = (&unk_40B50B0)[param_1 * 2];
        puVar10 = *(undefined4 **)(iVar2 + 0x2c);
        if (puVar10 == &unk_40B50B0 + param_1 * 2) {
          (&dword_40B50B4)[param_1 * 2] = puVar10;
        }
        else {
          puVar10[0xc] = &unk_40B50B0 + param_1 * 2;
        }
        (&unk_40B50B0)[param_1 * 2] = puVar10;
        (**(code **)(iVar1 + 0x3a))(iVar2,1,0);
        puVar10 = &unk_40B50B0 + param_1 * 2;
        puVar3 = (undefined4 *)(&unk_40B50B0)[param_1 * 2];
        cVar17 = puVar10 < puVar3;
        cVar16 = SBORROW4((int)puVar10,(int)puVar3);
        iVar2 = (int)puVar10 - (int)puVar3;
        cVar15 = puVar10 == puVar3;
      }
    }
    uVar6 = (uint)(byte)(cVar17 << 4 | cVar14 << 3 | cVar15 << 2 | cVar16 << 1 | bVar18);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2280 start=0x408461c */

void _snd_link_abort(void)

{
  dword_40B21D4 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2281 start=0x4084838 */

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
/* GHIDRADEC_FUNCTION index=2282 start=0x4084a18 */

void _snd_link_pause(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2283 start=0x4084a20 */

byte _snd_link_resume(uint param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  if (param_1 == dword_40B511A) {
    bVar8 = &unk_40B50D0 < unk_40B50D0;
    bVar7 = SBORROW4(0x40b50d0,(int)unk_40B50D0);
    bVar4 = (int)&unk_40B50D0 - (int)unk_40B50D0 < 0;
    bVar5 = (undefined4 **)unk_40B50D0 == &unk_40B50D0;
    if (!bVar5) {
      do {
        puVar3 = unk_40B50D0;
        unk_40B50D0 = (undefined4 *)unk_40B50D0[0xb];
        if ((undefined4 **)unk_40B50D0 == &unk_40B50D0) {
          dword_40B50D4 = &unk_40B50D0;
        }
        else {
          unk_40B50D0[0xc] = &unk_40B50D0;
        }
        (**(code **)(param_1 + 0x3a))(puVar3,1,0);
      } while ((undefined4 **)unk_40B50D0 != &unk_40B50D0);
      bVar8 = false;
      bVar7 = false;
      bVar5 = true;
      bVar4 = false;
    }
  }
  else {
    bVar8 = param_1 < dword_40B5158;
    bVar7 = SBORROW4(param_1,dword_40B5158);
    bVar4 = (int)(param_1 - dword_40B5158) < 0;
    bVar5 = false;
    if (param_1 == dword_40B5158) {
      bVar8 = &unk_40B50D8 < unk_40B50D8._0_4_;
      iVar1 = (int)&unk_40B50D8 - (int)unk_40B50D8._0_4_;
      bVar6 = unk_40B50D8._0_4_ == &unk_40B50D8;
      puVar2 = unk_40B50D8._0_4_;
      while( true ) {
        bVar4 = iVar1 < 0;
        bVar7 = SBORROW4(0x40b50d8,(int)puVar2);
        bVar5 = true;
        unk_40B50D8._0_4_ = puVar2;
        if (bVar6) break;
        unk_40B50D8._0_4_ = *(undefined8 **)((int)puVar2 + 0x2c);
        if (unk_40B50D8._0_4_ == &unk_40B50D8) {
          unk_40B50D8._4_4_ = &unk_40B50D8;
        }
        else {
          *(undefined8 **)(unk_40B50D8._0_4_ + 6) = &unk_40B50D8;
        }
        (**(code **)(param_1 + 0x3a))(puVar2,0,0);
        bVar8 = &unk_40B50D8 < unk_40B50D8._0_4_;
        iVar1 = (int)&unk_40B50D8 - (int)unk_40B50D8._0_4_;
        bVar6 = unk_40B50D8._0_4_ == &unk_40B50D8;
        puVar2 = unk_40B50D8._0_4_;
      }
    }
  }
  return bVar8 << 4 | bVar4 << 3 | bVar5 << 2 | bVar7 << 1 | bVar8;
}
/* GHIDRADEC_FUNCTION index=2284 start=0x4084d8c */

int _snd_link_snd_complete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar2 = *(int *)(param_1 + 8);
  piVar8 = &dword_40C6DFC;
  if (iVar2 == 0) {
    piVar8 = &dword_40C6DF8;
  }
  iVar1 = *piVar8;
  iVar7 = 1;
  puVar4 = (undefined4 *)(&dword_40B50A4)[iVar2 * 2];
  if (puVar4 == &unk_40B50A0 + iVar2 * 2) {
    (&unk_40B50A0)[iVar2 * 2] = param_1;
  }
  else {
    puVar4[0xb] = param_1;
  }
  *(undefined4 **)(param_1 + 0x30) = puVar4;
  *(undefined4 **)(param_1 + 0x2c) = &unk_40B50A0 + iVar2 * 2;
  (&dword_40B50A4)[iVar2 * 2] = param_1;
  if (((iVar2 == 0) && ((dword_40C6E84 & 0x10) == 0)) ||
     ((iVar2 == 1 && ((dword_40C6E84 & 0x20) == 0)))) {
    _callout_dispatch(4,sub_40846D2,iVar2);
    iVar7 = 0;
  }
  else {
    puVar4 = &unk_40B50B0 + iVar2 * 2;
    puVar5 = (undefined4 *)(&unk_40B50B0)[iVar2 * 2];
    if (puVar5 == puVar4) {
      iVar7 = 0;
    }
    else if ((uint)puVar5[1] < *(uint *)(param_1 + 4)) {
      do {
        iVar6 = (&unk_40B50B0)[iVar2 * 2];
        puVar5 = *(undefined4 **)(iVar6 + 0x2c);
        if (puVar5 == puVar4) {
          (&dword_40B50B4)[iVar2 * 2] = puVar4;
        }
        else {
          puVar5[0xc] = puVar4;
        }
        (&unk_40B50B0)[iVar2 * 2] = puVar5;
        if ((*(uint *)(iVar6 + 0x10) < *(uint *)(param_1 + 0x10)) ||
           (*(uint *)(param_1 + 0x14) < *(uint *)(iVar6 + 0x14))) {
joined_r0x04084e9e:
          if (puVar5 == puVar4) {
            (&dword_40B50B4)[iVar2 * 2] = iVar6;
          }
          else {
            puVar5[0xc] = iVar6;
          }
          *(undefined4 **)(iVar6 + 0x2c) = puVar5;
          *(undefined4 **)(iVar6 + 0x30) = &unk_40B50B0 + iVar2 * 2;
          (&unk_40B50B0)[iVar2 * 2] = iVar6;
          return iVar7;
        }
        if ((*(byte *)(iVar1 + 0x24) & 0x10) != 0) {
          puVar4 = (undefined4 *)(&dword_40B50D4)[iVar2 * 2];
          if (puVar4 == &unk_40B50D0 + iVar2 * 2) {
            (&unk_40B50D0)[iVar2 * 2] = iVar6;
          }
          else {
            puVar4[0xb] = iVar6;
          }
          *(undefined4 **)(iVar6 + 0x30) = puVar4;
          *(undefined4 **)(iVar6 + 0x2c) = &unk_40B50D0 + iVar2 * 2;
          (&dword_40B50D4)[iVar2 * 2] = iVar6;
          return iVar7;
        }
        iVar7 = (**(code **)(iVar1 + 0x3a))(iVar6,1 - iVar2,0);
        if (iVar7 == 0) {
          puVar5 = (undefined4 *)(&unk_40B50B0)[iVar2 * 2];
          goto joined_r0x04084e9e;
        }
      } while (puVar4 != (undefined4 *)(&unk_40B50B0)[iVar2 * 2]);
    }
    else {
      puVar3 = (undefined4 *)puVar5[0xb];
      if (puVar3 == puVar4) {
        (&dword_40B50B4)[iVar2 * 2] = puVar3;
      }
      else {
        puVar3[0xc] = puVar4;
      }
      (&unk_40B50B0)[iVar2 * 2] = puVar3;
      if (puVar5[5] == *(int *)(param_1 + 0x14)) {
        if ((*(byte *)(iVar1 + 0x24) & 0x10) == 0) {
          iVar7 = (**(code **)(iVar1 + 0x3a))(puVar5,1 - iVar2,0);
          if (iVar7 == 0) {
            puVar4 = (undefined4 *)(&unk_40B50A0)[iVar2 * 2];
            if (puVar4 == &unk_40B50A0 + iVar2 * 2) {
              (&dword_40B50A4)[iVar2 * 2] = puVar5;
            }
            else {
              puVar4[0xc] = puVar5;
            }
            puVar5[0xb] = puVar4;
            puVar5[0xc] = &unk_40B50A0 + iVar2 * 2;
            (&unk_40B50A0)[iVar2 * 2] = puVar5;
          }
        }
        else {
          puVar4 = (undefined4 *)(&dword_40B50D4)[iVar2 * 2];
          if (puVar4 == &unk_40B50D0 + iVar2 * 2) {
            (&unk_40B50D0)[iVar2 * 2] = puVar5;
          }
          else {
            puVar4[0xb] = puVar5;
          }
          puVar5[0xc] = puVar4;
          puVar5[0xb] = &unk_40B50D0 + iVar2 * 2;
          (&dword_40B50D4)[iVar2 * 2] = puVar5;
        }
      }
      else {
        if (puVar3 == &unk_40B50B0 + iVar2 * 2) {
          (&dword_40B50B4)[iVar2 * 2] = puVar5;
        }
        else {
          puVar3[0xc] = puVar5;
        }
        puVar5[0xb] = puVar3;
        puVar5[0xc] = &unk_40B50B0 + iVar2 * 2;
        (&unk_40B50B0)[iVar2 * 2] = puVar5;
      }
    }
  }
  return iVar7;
}
/* GHIDRADEC_FUNCTION index=2285 start=0x408503e */

undefined4 * _snd_rcv_alloc_msg_frame(void)

{
  dword_40C6ED8 = 0x2000;
  return &_snd_rcv_msg;
}
/* GHIDRADEC_FUNCTION index=2286 start=0x4085056 */

void _snd_reply_ret_device(undefined4 param_1,undefined4 param_2)

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
  uStack_8 = 0x12f;
  uStack_10 = param_2;
  uStack_c = param_1;
  _msg_send(&uStack_1c,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2287 start=0x40850b2 */

void _snd_reply_ret_stream(undefined4 param_1,undefined4 param_2)

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
  uStack_8 = 0x130;
  uStack_10 = param_2;
  uStack_c = param_1;
  _msg_send(&uStack_1c,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2288 start=0x4085176 */

void _snd_reply_illegal_msg
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_28 = dword_40B21D8;
  uStack_20 = dword_40B21E0;
  uStack_14 = 0x13a;
  uStack_24 = 0x24;
  uStack_1c = param_1;
  uStack_18 = param_2;
  uStack_10 = dword_40B21FC & 0xffff002f | 0x20;
  uStack_c = param_3;
  uStack_8 = param_4;
  _msg_send(&uStack_28,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2289 start=0x40851fc */

undefined4
_snd_reply_recorded_data
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined auStack_34 [48];
  
  puVar1 = auStack_34;
  iVar3 = 0x30;
  if (param_5 != 0) {
    iVar3 = param_4 + 0x2c;
    puVar1 = (undefined *)_kalloc(iVar3);
  }
  puVar1[3] = 0;
  *(int *)(puVar1 + 4) = iVar3;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0x10) = param_1;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x14) = 300;
  *(undefined4 *)(puVar1 + 0x18) = dword_40B21FC;
  *(undefined4 *)(puVar1 + 0x1c) = param_2;
  *(undefined4 *)(puVar1 + 0x20) = dword_40B21F0;
  *(undefined4 *)(puVar1 + 0x24) = dword_40B21F4;
  *(undefined4 *)(puVar1 + 0x28) = dword_40B21F8;
  *(int *)(puVar1 + 0x28) = param_4;
  if (param_5 == 0) {
    *(undefined4 *)(puVar1 + 0x2c) = param_3;
  }
  else {
    puVar1[0x23] = puVar1[0x23] | 8;
    _bcopy(param_3,puVar1 + 0x2c,param_4);
  }
  uVar2 = _msg_send(puVar1,0x21,0);
  if (param_5 != 0) {
    _kfree(puVar1,iVar3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2290 start=0x40852c2 */

void _snd_reply_timed_out(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x12d);
  return;
}
/* GHIDRADEC_FUNCTION index=2291 start=0x40852dc */

void _snd_reply_ret_samples(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_28 = dword_40B21D8;
  uStack_20 = dword_40B21E0;
  uStack_1c = dword_40B21E4;
  uStack_24 = 0x24;
  uStack_14 = 0x12e;
  uStack_18 = param_1;
  uStack_10 = dword_40B21FC;
  uStack_c = param_2;
  uStack_8 = param_3;
  _msg_send(&uStack_28,0x21,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2292 start=0x408534c */

void _snd_reply_overflow(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x133);
  return;
}
/* GHIDRADEC_FUNCTION index=2293 start=0x4085366 */

void _snd_reply_started(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x135);
  return;
}
/* GHIDRADEC_FUNCTION index=2294 start=0x4085380 */

void _snd_reply_completed(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x136);
  return;
}
/* GHIDRADEC_FUNCTION index=2295 start=0x408539a */

void _snd_reply_aborted(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x137);
  return;
}
/* GHIDRADEC_FUNCTION index=2296 start=0x40853b4 */

void _snd_reply_paused(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x138);
  return;
}
/* GHIDRADEC_FUNCTION index=2297 start=0x40853ce */

void _snd_reply_resumed(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x139);
  return;
}
/* GHIDRADEC_FUNCTION index=2298 start=0x40853e8 */

void _snd_reply_ret_parms(undefined4 param_1,undefined4 param_2)

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
  uStack_10 = 0x131;
  uStack_20 = 0x20;
  uStack_14 = param_1;
  uStack_c = dword_40B21FC;
  uStack_8 = param_2;
  _msg_send(&uStack_24,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2299 start=0x4085452 */

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

