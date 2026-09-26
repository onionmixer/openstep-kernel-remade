/* GHIDRADEC_FUNCTION index=3050 start=0x407bcb6 */

void sub_407BCB6(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x250;
  piVar4 = (int *)(_sc_s5c + iVar3);
  iVar1 = *(int *)(*(int *)(*piVar4 + 0x10) + 8);
  *(undefined *)(iVar1 + 0x20) = 0x20;
  _dma_abort(iVar3 + 0x40c5944);
  *(uint *)(_sc_s5c + iVar3 + 0x30) = *(uint *)(_sc_s5c + iVar3 + 0x30) & 0xffffbfff;
  if (_sc_s5c[iVar3 + 0x21e] == '\x06') {
    _busdone(*(undefined4 *)(*piVar4 + 0x10));
  }
  cVar2 = _sc_s5c[iVar3 + 0x21e];
  if (cVar2 != '\0') {
    *(undefined *)(iVar1 + 3) = 3;
    _delay(500000);
    _sc_s5c[iVar3 + 0x21e] = 0;
  }
  _sfa_abort(*(undefined4 *)(_sc_s5c + iVar3 + 0x238),iVar3 + 0x40c5b7c,1);
  iVar1 = *(int *)(_sc_s5c + iVar3 + 0x226);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      *(undefined *)(iVar1 + 0x4f) = 7;
    }
    else {
      *(undefined *)(iVar1 + 0x4f) = 5;
    }
    *(undefined4 *)(_sc_s5c + iVar3 + 0x226) = 0;
    if (cVar2 != '\0') {
      _scsi_cintr(param_1);
    }
  }
  *(undefined *)(*piVar4 + 0x60) = 0;
  _scsi_restart(*piVar4);
  return;
}
/* GHIDRADEC_FUNCTION index=3051 start=0x407c04a */

void sub_407C04A(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x18);
  *(undefined *)(param_1 + 0x5a) = 2;
  (**(code **)(*(int *)(iVar1 + 0x14) + 0x12))(iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=3052 start=0x407c2f4 */

void sub_407C2F4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  bool bVar6;
  uint unaff_D2;
  undefined4 *puVar7;
  
  puVar7 = dword_40B4FD2;
  if ((undefined4 **)dword_40B4FD2 != &dword_40B4FD2) {
    do {
      bVar4 = *(byte *)((int)puVar7 + 0x5a);
      if (bVar4 != 1) {
        if (bVar4 < 2) {
          if (bVar4 != 0) {
loc_407C44C:
                    /* WARNING: Subroutine does not return */
            _panic(aScsiTimerScAct);
          }
          bVar6 = false;
          for (puVar1 = (undefined4 *)*puVar7; puVar1 != puVar7; puVar1 = (undefined4 *)puVar1[2]) {
            if ((*(char *)(puVar1 + 9) < '\0') &&
               (iVar5 = puVar1[8] - dword_40B4FCE, puVar1[8] = iVar5, iVar5 < 0)) {
              puVar2 = (undefined4 *)puVar1[2];
              puVar3 = (undefined4 *)puVar1[3];
              if (puVar2 == puVar7) {
                puVar7[1] = puVar3;
              }
              else {
                puVar2[3] = puVar3;
              }
              if (puVar3 == puVar7) {
                *puVar7 = puVar2;
              }
              else {
                puVar3[2] = puVar2;
              }
              *(undefined *)((int)puVar1 + 0x4f) = 6;
              *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) & 0x5f;
              *(undefined *)((int)puVar7 + 0x5a) = 3;
              (**(code **)(puVar1[5] + 0x16))(puVar1);
              bVar6 = true;
              unaff_D2 = (uint)*(byte *)(puVar1 + 7);
            }
          }
          if (bVar6) {
            _printf(aReselectTimeou,unaff_D2);
            (**(code **)(puVar7[5] + 8))(puVar7,1,aReselectTimeou_0);
            *(undefined *)((int)puVar7 + 0x5a) = 0;
            if ((int *)(puVar7[4] + 0x18) != *(int **)(puVar7[4] + 0x18)) {
              sub_407C04A(puVar7);
            }
          }
        }
        else {
          if (bVar4 != 2) goto loc_407C44C;
          if ((*(char *)((int)puVar7 + 0x5b) != '\0') &&
             (iVar5 = puVar7[0x17] - dword_40B4FCE, puVar7[0x17] = iVar5, iVar5 < 0)) {
            *(undefined *)((int)puVar7 + 0x5b) = 0;
            iVar5 = *(int *)(puVar7[4] + 0x18);
            (**(code **)(puVar7[5] + 8))(puVar7,0,aLostInterrupt);
            _scsi_msg(iVar5,*(undefined *)(iVar5 + 0x26),aScsiTimerTimeo);
          }
        }
      }
      puVar1 = puVar7 + 2;
      puVar7 = (undefined4 *)*puVar1;
    } while ((undefined4 **)*puVar1 != &dword_40B4FD2);
  }
  _timeout(sub_407C2F4,0,dword_40B4FCE);
  return;
}
/* GHIDRADEC_FUNCTION index=3053 start=0x407c894 */

void sub_407C894(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = (undefined4 *)*param_1;
  bVar5 = false;
  iVar2 = *(int *)((int)param_1 + 0xd2);
  piVar3 = *(int **)((int)param_1 + 0xca);
  iVar7 = 0;
  do {
    sub_407CC7A(param_1,param_2);
    if (iVar7 == 0) {
      iVar7 = -1;
    }
    else {
      if (iVar7 < 0) {
        _printf(aWaitingForDriv);
        iVar7 = 1;
      }
      else {
        _printf(&asc_40A6047);
        iVar7 = iVar7 + 1;
      }
      if (param_2 == 0) {
        _timeout(sub_407CB90,puVar1,_hz * 2);
        _sleep(puVar1,0x28);
      }
      else {
        _delay(1000000);
      }
    }
    iVar6 = sub_407CCEE(param_1,param_2);
  } while ((iVar6 == 0) && (iVar7 < 0x14));
  if (0 < iVar7) {
    _printf(&asc_40A6049);
  }
  uVar4 = param_1[2];
  param_1[2] = uVar4 & 0xfffffffb;
  if (iVar7 < 0x14) {
    param_1[2] = uVar4 & 0xfffffffb | 2;
    sub_407E348(param_1,param_2);
    sub_407CA92(param_1);
    if ((**(byte **)((int)puVar1 + 0xb2) & 0x1f) == 5) {
      *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x800;
    }
    else {
      *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xf7ff;
      iVar7 = _kalloc(0x4c);
      uVar4 = iVar7 + 0xfU & 0xfffffff0;
      iVar6 = sub_407CC0E(param_1,param_2,uVar4,0x3c);
      if ((iVar6 == 0) && (*(char *)(uVar4 + 2) < '\0')) {
        *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x800;
      }
      _kfree(iVar7,0x4c);
    }
    if ((param_1[2] & 0x400) == 0) {
      _printf(aDiskUnformatte);
    }
    else if ((param_1[2] & 4) != 0) {
      _printf(aDiskLabelS,iVar2 + 0xc);
      _printf(aDiskCapacityDm,(uint)(piVar3[1] * *piVar3) >> 0x14,piVar3[1]);
    }
    if ((*(byte *)((int)param_1 + 10) & 8) != 0) {
      _printf(aDiskIsWritePro);
    }
  }
  else {
    bVar5 = true;
  }
  sub_407CBA2(param_1,param_2);
  if (bVar5) {
    *puVar1 = 0;
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xff7d;
  }
  else if (param_2 == 1) {
    sub_407F250(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3054 start=0x407ca92 */

void sub_407CA92(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(*param_1 + 8);
  iVar1 = *(int *)((int)param_1 + 0xd2);
  iVar4 = *(int *)((int)param_1 + 0xca);
  uVar2 = *(uint *)(iVar4 + 4);
  if (uVar2 == 0) {
    param_1[2] = param_1[2] & 0xfffffffb;
    _printf(aDeviceReturnsI);
    *(undefined4 *)(iVar4 + 4) = 0x200;
  }
  else if ((param_1[2] & 4U) == 0) {
    *(undefined4 *)((int)param_1 + 0xe) = 1;
    iVar5 = (int)*(sword *)(*(int *)(iVar5 + 0x10) + 0xc);
    if (-1 < iVar5) {
      *(undefined4 *)(_dk_bps + iVar5 * 4) = 0x7d000;
    }
  }
  else {
    uVar3 = *(uint *)(iVar1 + 0x5c);
    if ((uVar3 < uVar2) || (uVar3 % uVar2 != 0)) {
      param_1[2] = param_1[2] & 0xfffffffb;
      _printf(aFsBlockNotMult);
      _printf(aFsBlockDDevBlo,*(undefined4 *)(iVar1 + 0x5c),*(undefined4 *)(iVar4 + 4));
    }
    else {
      *(uint *)((int)param_1 + 0xe) = uVar3 / uVar2;
      iVar5 = (int)*(sword *)(*(int *)(iVar5 + 0x10) + 0xc);
      if (-1 < iVar5) {
        if (*(int *)(iVar1 + 0x6c) < 0x3c) {
          iVar4 = 0x3c;
        }
        else {
          iVar4 = *(int *)(iVar1 + 0x6c) / 0x3c;
        }
        *(int *)(_dk_bps + iVar5 * 4) = iVar4 * *(int *)(iVar1 + 100) * *(int *)(iVar1 + 0x5c);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3055 start=0x407cb90 */

void sub_407CB90(undefined4 param_1)

{
  _wakeup(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3056 start=0x407cba2 */

void sub_407CBA2(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  iVar1 = *param_1;
  _bzero(&uStack_56,0x52);
  uStack_46 = *(undefined4 *)(iVar1 + 0xb2);
  uStack_56 = 0x12;
  uVar2 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar2 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*(int *)(iVar1 + 8) + 0x1d) << 0x1d) >> 8),0x42);
  uStack_42 = 0x42;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  sub_407E678(param_1,&uStack_56,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=3057 start=0x407cc0e */

void sub_407CC0E(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  iVar1 = *param_1;
  _bzero(&uStack_56,0x52);
  uStack_56 = 0x1a;
  uVar2 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar2 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*(int *)(iVar1 + 8) + 0x1d) << 0x1d) >> 8),
                        (char)param_4);
  uStack_46 = param_3;
  uStack_42 = param_4;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  sub_407E678(param_1,&uStack_56,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=3058 start=0x407cc7a */

void sub_407CC7A(int *param_1,undefined4 param_2)

{
  uint uStack_56;
  undefined uStack_52;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = CONCAT13(0x1b,(int3)(((uint)*(byte *)(*(int *)(*param_1 + 8) + 0x1d) << 0x1d) >> 8));
  uStack_52 = 1;
  uStack_56 = uStack_56 | 0x10000;
  uStack_46 = 0;
  uStack_42 = 0;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  sub_407E678(param_1,&uStack_56,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=3059 start=0x407ccee */

undefined4 sub_407CCEE(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined uStack_56;
  uint uStack_55;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  int iStack_3a;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0;
  uStack_55 = uStack_55 & 0x1fffffff | (uint)*(byte *)(*(int *)(*param_1 + 8) + 0x1d) << 0x1d;
  uStack_46 = 0;
  uStack_42 = 0;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  iVar1 = sub_407E678(param_1,&uStack_56,param_2);
  if ((iVar1 == 0) && (iStack_3a == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3060 start=0x407cd5c */

undefined4 sub_407CD5C(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined uStack_56;
  undefined3 uStack_55;
  undefined uStack_52;
  undefined uStack_51;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  if ((*(byte *)((int)param_1 + 0xb) & 2) == 0) {
    uVar3 = 0;
  }
  else {
    _bzero(&uStack_56,0x52);
    _uStack_56 = CONCAT13(0x1b,(int3)(((uint)*(byte *)(*(int *)(*param_1 + 8) + 0x1d) << 0x1d) >> 8)
                         );
    uStack_52 = 2;
    uStack_51 = 0;
    uStack_46 = 0;
    uStack_42 = 0;
    uStack_4a = 0;
    uStack_3e = 0x14;
    uVar3 = sub_407E678(param_1,&uStack_56,0);
    iVar1 = *param_1;
    uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
            0xfffff;
    if ((((uVar2 ^ *_event_middle) & 0x80000) != 0) &&
       (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
      *_event_high = *_event_high + 1;
    }
    *(undefined4 *)(iVar1 + 0xba) = *_event_high;
    *(uint *)(iVar1 + 0xb6) = *_event_middle | uVar2;
    *(undefined4 *)*param_1 = 0;
    param_1[2] = param_1[2] & 0xfffffffd;
    *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) | 2;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=3061 start=0x407d376 */

undefined4 sub_407D376(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  puVar1 = (undefined4 *)*param_1;
  uVar6 = 0;
  if (param_1 == (int *)*puVar1) {
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x100;
    if ((*(byte *)(puVar1[2] + 0x24) & 0x20) == 0) {
      uVar6 = _scsi_dstart(puVar1[2]);
    }
  }
  else {
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x200;
    puVar4 = unk_40B503E;
    if ((undefined4 **)unk_40B503E == &unk_40B503E) {
                    /* WARNING: Subroutine does not return */
      _panic(aSdVstartSdEjec);
    }
    puVar2 = (undefined4 *)*unk_40B503E;
    puVar3 = (undefined4 *)unk_40B503E[1];
    puVar5 = puVar3;
    if ((undefined4 **)puVar2 != &unk_40B503E) {
      puVar2[1] = puVar3;
      puVar5 = dword_40B5042;
    }
    dword_40B5042 = puVar5;
    *puVar3 = puVar2;
    puVar4[2] = *puVar1;
    puVar4[3] = param_1;
    *dword_40B503A = puVar4;
    puVar4[1] = dword_40B503A;
    *puVar4 = &unk_40B5036;
    dword_40B503A = puVar4;
    _thread_wakeup_prim(&dword_40B5046,0,0);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=3062 start=0x407dcc4 */

void sub_407DCC4(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  
  _scsi_sensemsg(*(undefined4 *)(*param_1 + 8),*(undefined4 *)((int)param_1 + 0xc6));
  uVar2 = *(uint *)(*(int *)((int)param_1 + 0xc6) + 4) >> 8 |
          (uint)*(byte *)(*(int *)((int)param_1 + 0xc6) + 3) << 0x18;
  if ((*(byte *)((int)param_1 + 0xb) & 4) == 0) {
    puVar7 = aScsiBlockInErr_1;
  }
  else {
    uVar3 = uVar2 / *(uint *)((int)param_1 + 0xe);
    iVar6 = (int)*(sword *)(*(int *)((int)param_1 + 0xd2) + 0x70);
    if (iVar6 <= (int)uVar3) {
      piVar4 = (int *)(*(int *)((int)param_1 + 0xd2) + 0xbe);
      iVar5 = 0;
      iVar6 = uVar3 - iVar6;
      iVar1 = *piVar4;
      while (iVar1 < iVar6) {
        piVar4 = (int *)((int)piVar4 + 0x2e);
        iVar5 = iVar5 + 1;
        iVar1 = *piVar4;
        if ((iVar1 == -1) || (iVar5 == 8)) break;
      }
      _printf(aScsiBlockInErr,uVar2,iVar5 + 0x60,iVar6 - *(int *)((int)piVar4 + -0x2e));
      return;
    }
    puVar7 = aScsiBlockInErr_0;
  }
  _printf(puVar7,uVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=3063 start=0x407dd74 */

void sub_407DD74(int *param_1,int param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (iVar4 == 0) {
    iVar4 = param_1[1];
    param_1[1] = 0;
  }
  puVar2 = (uint *)_disksort_first(iVar4 + 0x60);
  if (puVar2 != (uint *)0x0) {
    puVar2[10] = param_2 + puVar2[10];
    *puVar2 = param_3 | *puVar2;
    if ((param_3 & 4) != 0) {
      if (param_4 == 0x10) {
        *(undefined2 *)(puVar2 + 7) = 6;
      }
      else if (param_4 == 0x11) {
        *(undefined2 *)(puVar2 + 7) = 0x1e;
      }
      else {
        *(undefined2 *)(puVar2 + 7) = 5;
      }
    }
    _disksort_remove(iVar4 + 0x60,puVar2);
    if ((uint *)(iVar4 + 0x18) == puVar2) {
      iVar3 = *(int *)(iVar4 + 0x5c);
      *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x14) - param_2;
      *(int *)(iVar3 + 0x1c) = param_4;
      if (param_4 == 2) {
        *(undefined *)(iVar3 + 0x20) = 2;
        puVar1 = *(undefined4 **)(iVar4 + 0xc6);
        *(undefined4 *)(iVar3 + 0x22) = *puVar1;
        *(undefined4 *)(iVar3 + 0x26) = puVar1[1];
        *(undefined4 *)(iVar3 + 0x2a) = puVar1[2];
        *(undefined4 *)(iVar3 + 0x2e) = puVar1[3];
        *(undefined4 *)(iVar3 + 0x32) = puVar1[4];
        *(undefined4 *)(iVar3 + 0x36) = puVar1[5];
        *(undefined2 *)(iVar3 + 0x3a) = *(undefined2 *)(puVar1 + 6);
      }
      else {
        *(undefined *)(iVar3 + 0x20) = *(undefined *)(param_1[2] + 0x4e);
      }
    }
    *(undefined *)(param_1 + 4) = 0;
    iVar3 = _disksort_first(iVar4 + 0x60);
    if (iVar3 == 0) {
      *(word *)(iVar4 + 10) = *(word *)(iVar4 + 10) & 0xfeff;
    }
    else {
      sub_407D376(iVar4);
    }
    _biodone(puVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSddoneNoBufOnS_0);
}
/* GHIDRADEC_FUNCTION index=3064 start=0x407e348 */

uint sub_407E348(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined auStack_a6 [2];
  int iStack_a4;
  undefined uStack_9f;
  undefined uStack_9e;
  undefined4 uStack_9a;
  undefined4 uStack_96;
  undefined4 uStack_92;
  undefined4 uStack_8e;
  uint uStack_8a;
  
  iVar2 = *param_1;
  uVar1 = sub_407E572(param_1,*(undefined4 *)((int)param_1 + 0xca),param_2);
  if (uVar1 == 0) {
    if (*(int *)(*(int *)((int)param_1 + 0xca) + 4) == 0) {
      _printf(aErrorInvalidDe);
      if ((**(byte **)(iVar2 + 0xb2) & 0x1f) == 5) {
        *(undefined4 *)(*(int *)((int)param_1 + 0xca) + 4) = 0x800;
      }
      else {
        *(undefined4 *)(*(int *)((int)param_1 + 0xca) + 4) = 0x200;
      }
    }
    uVar4 = *(uint *)(*(int *)((int)param_1 + 0xca) + 4);
    uVar4 = (uVar4 + 0x1c47) / uVar4;
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xfbff;
    *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) | 8;
    *(undefined *)(*param_1 + 0x15) = 2;
    iVar3 = 0;
    iVar2 = 0;
    do {
      _bzero(*(undefined4 *)((int)param_1 + 0xd2),0x1c48);
      _bzero(auStack_a6,0x52);
      auStack_a6[0] = 0x28;
      uStack_9f = (undefined)(uVar4 >> 8);
      uStack_9e = (undefined)uVar4;
      uStack_96 = *(undefined4 *)((int)param_1 + 0xd2);
      uStack_92 = 0x1c48;
      uStack_9a = 0;
      uStack_8e = 0x3c;
      iStack_a4 = iVar2;
      uVar1 = sub_407E678(param_1,auStack_a6,param_2);
      uVar1 = uStack_8a | uVar1;
      if (uVar1 == 0) {
        *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x400;
        uVar1 = _sdchecklabel(*(undefined4 *)((int)param_1 + 0xd2),iStack_a4);
        if (uVar1 != 0) {
          param_1[2] = param_1[2] | 4;
          break;
        }
      }
      iVar2 = uVar4 + iVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) & 0xfffffff7;
    *(undefined *)(*param_1 + 0x15) = 10;
  }
  else {
    *(undefined4 *)(*(int *)((int)param_1 + 0xca) + 4) = 0x200;
    param_1[2] = param_1[2] & 0xfffffffb;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3065 start=0x407e4a4 */

undefined4 sub_407E4A4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined auStack_a6 [2];
  int iStack_a4;
  undefined uStack_9f;
  undefined uStack_9e;
  undefined4 uStack_9a;
  undefined4 uStack_96;
  undefined4 uStack_92;
  undefined4 uStack_8e;
  
  iVar1 = sub_407E572(param_1,*(undefined4 *)(param_1 + 0xca),0);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
    sub_407CA92(param_1);
    uVar2 = 5;
    uVar5 = *(uint *)(*(int *)(param_1 + 0xca) + 4);
    uVar5 = (uVar5 + 0x1c47) / uVar5;
    iVar4 = 0;
    iVar1 = 0;
    do {
      _bzero(auStack_a6,0x52);
      auStack_a6[0] = 0x2a;
      uStack_9f = (undefined)(uVar5 >> 8);
      uStack_9e = (undefined)uVar5;
      uStack_96 = *(undefined4 *)(param_1 + 0xd2);
      uStack_92 = 0x1c48;
      uStack_9a = 1;
      uStack_8e = 0x3c;
      *(int *)(*(int *)(param_1 + 0xd2) + 4) = iVar1;
      iStack_a4 = iVar1;
      iVar3 = sub_407E678(param_1,auStack_a6,0);
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      iVar1 = uVar5 + iVar1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3066 start=0x407e572 */

bool sub_407E572(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_56 [12];
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(auStack_56,0x52);
  auStack_56[0] = 0x25;
  uStack_46 = param_2;
  uStack_42 = 8;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  iVar1 = sub_407E678(param_1,auStack_56,param_3);
  if (iVar1 != 0) {
    _printf(aErrorCanTReadD);
  }
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=3067 start=0x407e678 */

undefined4 sub_407E678(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined auStack_c [8];
  
  iVar6 = *param_1;
  puVar5 = (uint *)(param_1 + 6);
  uVar7 = 0;
  iVar2 = *(int *)(iVar6 + 8);
  while (((*puVar5 & 8) != 0 && (param_3 == 0))) {
    *puVar5 = *puVar5 | 0x40;
    _sleep(puVar5,0x14);
  }
  *puVar5 = 9;
  param_1[0x17] = param_2;
  _microtime(auStack_c);
  if (param_3 == 1) {
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffffb | 1;
  }
  else {
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffffe | 4;
  }
  *(sword *)((int)param_1 + 0x36) = (sword)param_1[1] << 3;
  iVar6 = _sdstrategy(puVar5);
  if (iVar6 == 0) {
    if (param_3 == 0) {
      _biowait(puVar5);
    }
    else {
      iVar6 = 0;
      bVar4 = *(byte *)((int)param_1 + 0x1b);
      while ((bVar4 & 2) == 0) {
        iVar6 = iVar6 + 1;
        if (iVar6 < 0xfa1) {
          _delay(1000);
        }
        else {
          _scsi_timeout(*(undefined4 *)(iVar2 + 0x18));
          iVar6 = 0;
        }
        bVar4 = *(byte *)((int)param_1 + 0x1b);
      }
    }
  }
  if (*(int *)(param_2 + 0x1c) == 2) {
    puVar3 = *(undefined4 **)((int)param_1 + 0xc6);
    *(undefined4 *)(param_2 + 0x22) = *puVar3;
    *(undefined4 *)(param_2 + 0x26) = puVar3[1];
    *(undefined4 *)(param_2 + 0x2a) = puVar3[2];
    *(undefined4 *)(param_2 + 0x2e) = puVar3[3];
    *(undefined4 *)(param_2 + 0x32) = puVar3[4];
    *(undefined4 *)(param_2 + 0x36) = puVar3[5];
    *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar3 + 6);
  }
  if ((*(int *)(param_2 + 0x1c) != 0) && (param_3 != 0)) {
    uVar7 = 5;
  }
  _microtime(&uStack_14);
  _timevalsub(&uStack_14,auStack_c);
  *(undefined4 *)(param_2 + 0x40) = uStack_14;
  *(undefined4 *)(param_2 + 0x44) = uStack_10;
  param_1[0x17] = 0;
  uVar1 = *puVar5;
  *puVar5 = uVar1 & 0xfffffff7;
  if (((uVar1 & 0x40) != 0) && (param_3 == 0)) {
    _wakeup(puVar5);
  }
  return uVar7;
}
/* GHIDRADEC_FUNCTION index=3068 start=0x407e802 */

int sub_407E802(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _kalloc(0xd6);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSdNewSvCouldnT);
  }
  _bzero(iVar2,0xd6);
  *(undefined4 *)(iVar2 + 4) = param_1;
  *(undefined4 *)(iVar2 + 8) = 0x80;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x5c) = 0;
  *(undefined *)(iVar2 + 0xc) = 0;
  *(undefined *)(iVar2 + 0xd) = 0;
  iVar3 = _kalloc(0x1c58);
  *(int *)(iVar2 + 0xce) = iVar3;
  uVar1 = iVar3 + 0xfU & 0xfffffff0;
  *(uint *)(iVar2 + 0xd2) = uVar1;
  if (uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSdNewSvCouldnT_0);
  }
  *(uint *)(iVar2 + 0xc6) = iVar2 + 0x95U & 0xfffffff0;
  *(uint *)(iVar2 + 0xca) = iVar2 + 0xbeU & 0xfffffff0;
  _disksort_init(iVar2 + 0x60);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=3069 start=0x407e8b8 */

void sub_407E8B8(int param_1)

{
  _disksort_free(param_1 + 0x60);
  *(undefined4 *)(unk_40B4FDE + *(int *)(param_1 + 4) * 4) = 0;
  _kfree(*(undefined4 *)(param_1 + 0xce),0x1c58);
  _kfree(param_1,0xd6);
  return;
}
/* GHIDRADEC_FUNCTION index=3070 start=0x407e900 */

void sub_407E900(int *param_1,int param_2)

{
  *param_1 = (int)(_sd_sdd + param_2 * 0xc2);
  *(int **)(_sd_sdd + param_2 * 0xc2) = param_1;
  param_1[2] = param_1[2] & 0xfffffffe;
  return;
}
/* GHIDRADEC_FUNCTION index=3071 start=0x407e934 */

void sub_407E934(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  undefined *puVar14;
  uint uStack_24;
  int *piStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  int iStack_8;
  
  iVar3 = sub_407E802(0x11);
  dword_40B5022 = iVar3;
  sub_407E900(iVar3,7);
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
  puVar4 = (undefined4 *)_kalloc(0x40);
  iVar5 = 0;
  do {
    puVar12 = puVar4;
    *dword_40B5042 = puVar12;
    puVar12[1] = dword_40B5042;
    *puVar12 = &unk_40B503E;
    iVar5 = iVar5 + 1;
    puVar4 = puVar12 + 4;
    dword_40B5042 = puVar12;
    puVar12 = unk_40B502E;
  } while (iVar5 < 4);
  do {
    while (puVar4 = unk_40B5036, (undefined4 **)puVar12 != &unk_40B502E) {
      piVar11 = (int *)puVar12[2];
      puVar4 = (undefined4 *)*puVar12;
      puVar1 = (undefined4 *)puVar12[1];
      puVar2 = puVar1;
      if ((undefined4 **)puVar4 != &unk_40B502E) {
        puVar4[1] = puVar1;
        puVar2 = dword_40B5032;
      }
      dword_40B5032 = puVar2;
      puVar2 = puVar4;
      if ((undefined4 **)puVar1 != &unk_40B502E) {
        *puVar1 = puVar4;
        puVar2 = unk_40B502E;
      }
      unk_40B502E = puVar2;
      if ((*(byte *)((int)piVar11 + 10) & 2) != 0) {
        iVar5 = *piVar11;
        piVar6 = (int *)_disksort_first(piVar11 + 0x18);
        piVar11[2] = piVar11[2] & 0xfffffdf7U | 1;
        *(undefined2 *)(piVar6 + 7) = 6;
        if (piVar11 + 6 == piVar6) {
          iVar7 = *(int *)(piVar11[0x17] + 0x14);
        }
        else {
          iVar7 = piVar6[5];
        }
        *(undefined *)(iVar5 + 0x10) = 0;
        sub_407DD74(iVar5,iVar7,4,0x10);
      }
      _kfree(puVar12,0x14);
      puVar12 = puVar4;
    }
    while (puVar12 = puVar4, (undefined4 **)puVar12 != &unk_40B5036) {
      piVar11 = (int *)**(int **)puVar12[3];
      puVar4 = (undefined4 *)*puVar12;
      if ((*(int **)puVar12[3])[1] == 0) {
        puVar1 = (undefined4 *)puVar12[1];
        puVar2 = puVar1;
        if ((undefined4 **)puVar4 != &unk_40B5036) {
          puVar4[1] = puVar1;
          puVar2 = dword_40B503A;
        }
        dword_40B503A = puVar2;
        puVar2 = puVar4;
        if ((undefined4 **)puVar1 != &unk_40B5036) {
          *puVar1 = puVar4;
          puVar2 = unk_40B5036;
        }
        unk_40B5036 = puVar2;
        if (((piVar11 != (int *)0x0) && (*(char *)((int)piVar11 + 0xb) < '\0')) && (*piVar11 != 0))
        {
          if (*(sword *)(piVar11 + 3) != 0) {
            _update((int)(sword)((sword)piVar11[1] << 3 | (sword)dword_40B5026 << 8),0xfffffff8);
          }
          sub_407CD5C(piVar11);
          if ((*(sword *)(piVar11 + 3) == 0) && ((*(byte *)((int)piVar11 + 0xb) & 0x40) == 0)) {
            sub_407F330(piVar11);
          }
        }
        piVar11 = (int *)puVar12[3];
        iVar5 = *piVar11;
        *(undefined *)(iVar5 + 0x10) = 4;
        *(int **)(iVar5 + 4) = piVar11;
        sub_407F13E(piVar11,0);
        *dword_40B5042 = puVar12;
        puVar12[1] = dword_40B5042;
        *puVar12 = &unk_40B503E;
        dword_40B5042 = puVar12;
      }
    }
    _lock_write(&unk_40B504A);
    iVar5 = 0;
    if (0 < dword_40B2084) {
      piStack_20 = (int *)unk_40B4FDE;
      puVar14 = _sd_sdd;
      do {
        if (*(int *)puVar14 == 0) {
          uStack_24 = (uint)*_eventc_h;
          uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)((uStack_24 << 0x10) >> 8),*_eventc_l) &
                     0xfffff;
          if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
             (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
            *_event_high = *_event_high + 1;
          }
          iStack_8 = *_event_high;
          uStack_c = *_event_middle | uStack_c;
          uStack_14 = *(undefined4 *)((int)puVar14 + 0xb6);
          uStack_10 = *(undefined4 *)((int)puVar14 + 0xba);
          _ts_add(&uStack_14,3000000);
          iVar7 = _ts_greater(&uStack_14,&uStack_c);
          if (iVar7 == 0) {
            byte_40C5E44 = *(undefined *)(*(int *)((int)puVar14 + 8) + 0x1c);
            byte_40C5E45 = *(undefined *)(*(int *)((int)puVar14 + 8) + 0x1d);
            _bcopy(*(undefined4 *)((int)puVar14 + 0xb2),dword_40C6478,0x42);
            dword_40B5056._0_2_ = *(undefined2 *)(*(int *)(*(int *)((int)puVar14 + 8) + 0x10) + 4);
            dword_40B5056._2_2_ = *(undefined2 *)(*(int *)(*(int *)((int)puVar14 + 8) + 0x10) + 6);
            iVar7 = sub_407CCEE(iVar3,0);
            if (iVar7 == 0) {
              if ((*(uint *)((int)puVar14 + 0xc) & 2) != 0) {
                *(uint *)((int)puVar14 + 0xc) = *(uint *)((int)puVar14 + 0xc) & 0xfffffffd;
                if (-1 < *(int *)((int)puVar14 + 0xbe)) {
                  _vol_panel_remove(*(int *)((int)puVar14 + 0xbe));
                  *(undefined4 *)((int)puVar14 + 0xbe) = 0xffffffff;
                }
              }
            }
            else if ((*(byte *)((int)puVar14 + 0xf) & 2) == 0) {
              sub_407C894(iVar3,0);
              iVar7 = *(int *)((int)puVar14 + 4);
              if (iVar7 == 0) {
                iVar10 = 0;
                puVar13 = unk_40B4FDE;
                do {
                  iVar7 = *(int *)puVar13;
                  if ((((iVar7 != 0) && (*(char *)(iVar7 + 0xb) < '\0')) &&
                      (iVar8 = sub_407EFCE(iVar3,iVar7), iVar8 == 0)) &&
                     ((*(byte *)(iVar7 + 0xb) & 2) == 0)) goto loc_407EE6C;
                  puVar13 = (undefined *)((int)puVar13 + 4);
                  iVar10 = iVar10 + 1;
                } while (iVar10 < 0x10);
                iVar7 = *piStack_20;
                if ((char)*(uint *)(iVar7 + 8) < '\0') {
                  if (dword_40B2084 < 0x10) {
                    piVar11 = (int *)(unk_40B4FDE + dword_40B2084 * 4);
                    iVar7 = dword_40B2084;
                    do {
                      if (*piVar11 == 0) {
                        uVar9 = sub_407E802(iVar7);
                        *(undefined4 *)(unk_40B4FDE + iVar7 * 4) = uVar9;
                        sub_407F042(iVar3,uVar9);
                        sub_407F0A8(uVar9,puVar14);
                        sub_407F250(uVar9);
                        goto loc_407EEF4;
                      }
                      piVar11 = piVar11 + 1;
                      iVar7 = iVar7 + 1;
                    } while (iVar7 < 0x10);
                  }
                  _printf(aSdVolCheckNoFr);
                  sub_407CD5C(iVar3);
                  sub_407E900(iVar3,7);
                  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
                }
                else {
                  *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 0x80;
                  sub_407F042(iVar3,iVar7);
                  sub_407F0A8(iVar7,puVar14);
                  sub_407F250(iVar7);
                }
              }
              else if ((*(byte *)(iVar7 + 0xb) & 0x40) == 0) {
                iVar10 = sub_407EFCE(iVar3,iVar7);
                if (iVar10 == 0) {
loc_407EE6C:
                  sub_407F0A8(iVar7,puVar14);
                }
                else {
                  sub_407CD5C(iVar3);
                  sub_407E900(iVar3,7);
                  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
loc_407EDD0:
                  if ((*(byte *)(iVar7 + 0xb) & 8) != 0) {
                    _vol_panel_remove(*(undefined4 *)(iVar7 + 0x12));
                    sub_407F13E(iVar7,1);
                  }
                }
              }
              else {
                iVar10 = 0;
                do {
                  if (((*(int *)(unk_40B4FDE + iVar10 * 4) != 0) && (iVar10 != *(int *)(iVar7 + 4)))
                     && (iVar8 = sub_407EFCE(iVar3,*(int *)(unk_40B4FDE + iVar10 * 4)), iVar8 == 0))
                  {
                    sub_407CD5C(iVar3);
                    sub_407E900(iVar3,7);
                    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 2;
                    goto loc_407EDD0;
                  }
                  iVar10 = iVar10 + 1;
                } while (iVar10 < 0x10);
                sub_407F042(iVar3,iVar7);
                sub_407F0A8(iVar7,puVar14);
              }
            }
            else if (*(int *)((int)puVar14 + 0xbe) < 0) {
              _vol_panel_request(0,6,1,0,2,(int)((int)puVar14 + -0x40c5e78) * 0x5f02a3a1 >> 1,0,
                                 &unk_40A62E7,&unk_40A62E7,0,(int)puVar14 + 0xbe);
            }
          }
        }
loc_407EEF4:
        piStack_20 = piStack_20 + 1;
        puVar14 = (undefined *)((int)puVar14 + 0xc2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < dword_40B2084);
    }
    _lock_done(&unk_40B504A);
    if (dword_40B207C < 1000000) {
      iStack_1c = 0;
      iStack_18 = dword_40B207C;
    }
    else {
      iStack_1c = dword_40B207C / 1000000;
      iStack_18 = dword_40B207C % 1000000;
    }
    dword_40B5046 = 0;
    _us_timeout(&loc_407EFAE,0,&iStack_1c,0);
    while (puVar12 = unk_40B502E, dword_40B5046 == 0) {
      _assert_wait(&dword_40B5046,0);
      _thread_block();
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3072 start=0x407efce */

undefined4 sub_407EFCE(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (((**(int **)(param_1 + 0xca) != **(int **)(param_2 + 0xca)) ||
      ((*(int **)(param_1 + 0xca))[1] != (*(int **)(param_2 + 0xca))[1])) ||
     (uVar1 = *(uint *)(param_1 + 8) & 4, (*(uint *)(param_2 + 8) & 4) != uVar1)) {
    return 1;
  }
  if (uVar1 != 0) {
    if (*(int *)(*(int *)(param_1 + 0xd2) + 0x28) != *(int *)(*(int *)(param_2 + 0xd2) + 0x28)) {
      return 1;
    }
    iVar2 = _strncmp(*(int *)(param_1 + 0xd2) + 0xc,*(int *)(param_2 + 0xd2) + 0xc,0x18);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=3073 start=0x407f042 */

void sub_407F042(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  _bcopy(*(undefined4 *)(param_1 + 0xd2),*(undefined4 *)(param_2 + 0xd2),0x1c48);
  puVar1 = *(undefined4 **)(param_2 + 0xca);
  uVar2 = (*(undefined4 **)(param_1 + 0xca))[1];
  *puVar1 = **(undefined4 **)(param_1 + 0xca);
  puVar1[1] = uVar2;
  uVar3 = *(uint *)(param_2 + 8) & 0xfffff3fb;
  *(uint *)(param_2 + 8) = uVar3;
  *(uint *)(param_2 + 8) =
       CONCAT22((sword)(uVar3 >> 0x10),(word)*(undefined4 *)(param_1 + 8) & 0xc04 | (word)uVar3) |
       0x80;
  *(undefined4 *)(param_2 + 0xe) = *(undefined4 *)(param_1 + 0xe);
  return;
}
/* GHIDRADEC_FUNCTION index=3074 start=0x407f0a8 */

byte sub_407F0A8(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  *param_2 = (int)param_1;
  *param_1 = param_2;
  param_2[1] = 0;
  uVar1 = param_1[2];
  param_1[2] = uVar1 & 0xffffffbe | 2;
  if ((uVar1 & 8) != 0) {
    param_1[2] = uVar1 & 0xffffffb6 | 2;
    _vol_panel_remove(*(undefined4 *)((int)param_1 + 0x12));
  }
  cVar3 = '\0';
  iVar2 = _disksort_first(param_1 + 0x18);
  cVar6 = '\0';
  bVar7 = 0;
  cVar4 = iVar2 < 0;
  cVar5 = iVar2 == 0;
  if (!(bool)cVar5) {
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xfdff;
    *(undefined *)(param_2 + 4) = 0;
    cVar4 = '\0';
    cVar6 = '\0';
    bVar7 = 0;
    iVar2 = param_2[2];
    cVar5 = '\0';
    if ((*(byte *)(iVar2 + 0x24) & 0x20) == 0) {
      cVar4 = iVar2 < 0;
      cVar5 = iVar2 == 0;
      cVar6 = '\0';
      bVar7 = 0;
      _scsi_dstart(iVar2);
    }
  }
  return cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=3075 start=0x407f13e */

void sub_407F13E(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1[2] & 0x84U) == 0x84) {
    iVar1 = _vol_panel_disk_label
                      (sub_407F1EE,*(int *)((int)param_1 + 0xd2) + 0xc,2,
                       (*param_1 + -0x40c5e78) * 0x5f02a3a1 >> 1,param_1,param_2,(int)param_1 + 0x12
                      );
  }
  else {
    iVar1 = _vol_panel_disk_num(sub_407F1EE,param_1[1],2,(*param_1 + -0x40c5e78) * 0x5f02a3a1 >> 1,
                                param_1,param_2,(int)param_1 + 0x12);
  }
  if (iVar1 != 0) {
    _printf(aSdAlertPanelVo,iVar1);
  }
  param_1[2] = param_1[2] | 8;
  return;
}
/* GHIDRADEC_FUNCTION index=3076 start=0x407f1ee */

void sub_407F1EE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x14);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  *dword_40B5032 = puVar1;
  puVar1[1] = dword_40B5032;
  *puVar1 = &unk_40B502E;
  dword_40B5032 = puVar1;
  _thread_wakeup_prim(&dword_40B5046,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3077 start=0x407f250 */

void sub_407F250(int *param_1)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  undefined auStack_a [6];
  
  if ((param_1[2] & 0x400U) == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = ((word)((word)param_1[2] ^ 4) & 7) >> 2;
  }
  _sprintf(auStack_a,&aSdD,param_1[1]);
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xb2) + 1) >> 0x1f;
  if ((*(byte *)((int)param_1 + 10) & 8) != 0) {
    uVar2 = uVar2 | 2;
  }
  wVar1 = (sword)param_1[1] << 3;
  _vol_notify_dev((int)(sword)(wVar1 | (sword)dword_40B5026 << 8),
                  (int)(sword)(wVar1 | (sword)dword_40B502A << 8),&unk_40A62E7,uVar3,auStack_a,uVar2
                 );
  return;
}
/* GHIDRADEC_FUNCTION index=3078 start=0x407f2e4 */

void sub_407F2E4(void)

{
  if ((_kernel_task == 0) || (dword_40B2080 != 0)) {
    _timeout(sub_407F2E4,0,_hz);
  }
  else {
    if (dword_40B2088 != 0) {
      _kernel_thread_noblock(_kernel_task,sub_407E934);
    }
    dword_40B2080 = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3079 start=0x407f330 */

void sub_407F330(int param_1)

{
  if (*(uint *)(param_1 + 4) < dword_40B2084) {
    *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xff7f;
  }
  else {
    sub_407E8B8(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3080 start=0x407f358 */

void sub_407F358(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc2;
  _bzero(_sd_sdd + iVar1,0xc2);
  *(undefined **)(_sd_sdd + iVar1 + 8) = _sd_sd + param_1 * 0x50;
  *(uint *)(_sd_sdd + iVar1 + 0xb2) = iVar1 + 0x40c5ee7U & 0xfffffff0;
  *(undefined4 *)(_sd_sdd + iVar1 + 0xc) = 0;
  *(undefined4 *)(_sd_sdd + iVar1 + 0x1c) = 0;
  _sd_sdd[iVar1 + 0x10] = 0;
  _sd_sdd[iVar1 + 0x15] = 10;
  *(undefined4 *)(_sd_sdd + iVar1 + 0xbe) = 0xffffffff;
  return;
}
/* GHIDRADEC_FUNCTION index=3081 start=0x407f682 */

void sub_407F682(undefined4 param_1)

{
  sub_407F6A6(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3082 start=0x407f6a6 */

void sub_407F6A6(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x42;
  piVar3 = (int *)(_sg_sgd + iVar2);
  _bzero(piVar3,0x42);
  *piVar3 = param_1;
  *(uint *)(_sg_sgd + iVar2 + 4) = iVar2 + 0x40c65efU & 0xfffffff0;
  iVar1 = iVar2 + 0x40c65d0;
  *(int *)(_sg_sgd + iVar2 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  _sg_sgd[iVar2 + 0x15] = 0;
  _sg_sgd[iVar2 + 0x17] = 0;
  *(undefined *)(*piVar3 + 0x1c) = 0xff;
  *(undefined *)(*piVar3 + 0x1d) = 0xff;
  return;
}
/* GHIDRADEC_FUNCTION index=3083 start=0x407fae2 */

void sub_407FAE2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = param_1 + 2;
  if (piVar4 == (int *)*piVar4) {
                    /* WARNING: Subroutine does not return */
    _panic(aSgdoneNoBufOnS);
  }
  *(undefined *)((int)param_1 + 0x15) = 0;
  iVar1 = *piVar4;
  piVar2 = *(int **)(iVar1 + 0x4a);
  piVar3 = *(int **)(iVar1 + 0x4e);
  if (piVar2 == piVar4) {
    param_1[3] = (int)piVar3;
  }
  else {
    *(int **)((int)piVar2 + 0x4e) = piVar3;
  }
  if (piVar3 == param_1 + 2) {
    *piVar3 = (int)piVar2;
  }
  else {
    *(int **)((int)piVar3 + 0x4a) = piVar2;
  }
  *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x14) - param_2;
  *(int *)(iVar1 + 0x1c) = param_3;
  if (param_3 == 2) {
    *(undefined *)(iVar1 + 0x20) = 2;
  }
  else {
    *(undefined *)(iVar1 + 0x20) = *(undefined *)(*param_1 + 0x4e);
  }
  if (param_1 + 2 == (int *)param_1[2]) {
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) | 1;
    _wakeup(iVar1);
  }
  else {
    _scsi_dstart(*param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3084 start=0x407fc78 */

undefined4 sub_407FC78(int *param_1,byte *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*param_2 < 8) && (param_2[1] < 8)) {
    iVar3 = *param_1;
    if (*(byte *)(iVar3 + 0x1c) != 0xff) {
      pcVar1 = (char *)(*(int *)(iVar3 + 0x18) + (uint)*(byte *)(iVar3 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar3 + 0x1d));
      *pcVar1 = *pcVar1 + -1;
      *(undefined *)(*param_1 + 0x1c) = 0xff;
      *(undefined *)(*param_1 + 0x1d) = 0xff;
    }
    if ((*(char *)(*(int *)(*param_1 + 0x18) + (uint)*param_2 * 8 + 0x18 + (uint)param_2[1]) != '\0'
        ) && (iVar3 = _suser(), iVar3 == 0)) {
      return 0xd;
    }
    pcVar1 = (char *)(*(int *)(*param_1 + 0x18) + (uint)*param_2 * 8 + 0x18 + (uint)param_2[1]);
    *pcVar1 = *pcVar1 + '\x01';
    *(byte *)(*param_1 + 0x1c) = *param_2;
    *(byte *)(*param_1 + 0x1d) = param_2[1];
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3085 start=0x407fd2c */

int sub_407FD2C(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined auStack_c [8];
  
  iVar6 = *param_1;
  if (*(char *)(iVar6 + 0x1c) == -1) {
    *(undefined4 *)(param_2 + 0x1c) = 0xb;
    return 0xd;
  }
  _microtime(auStack_c);
  if (*(int *)(param_2 + 0x14) == 0) {
    uStack_10 = 0;
  }
  else {
    iVar5 = _kmem_alloc_wired(_kernel_map,&uStack_10,*(int *)(param_2 + 0x14));
    if (iVar5 != 0) {
      *(undefined4 *)(param_2 + 0x1c) = 8;
      return 0xc;
    }
    if ((*(int *)(param_2 + 0xc) == 1) &&
       (iVar5 = _copyinmsg(*(undefined4 *)(param_2 + 0x10),uStack_10,*(undefined4 *)(param_2 + 0x14)
                          ), iVar5 != 0)) {
      _kmem_free(_kernel_map,uStack_10,*(undefined4 *)(param_2 + 0x14));
      *(undefined4 *)(param_2 + 0x1c) = 9;
      return iVar5;
    }
  }
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 0x10) = uStack_10;
  piVar2 = (int *)param_1[3];
  if (piVar2 == param_1 + 2) {
    *piVar2 = param_2;
  }
  else {
    *(int *)((int)piVar2 + 0x4a) = param_2;
  }
  *(int **)(param_2 + 0x4e) = piVar2;
  *(int **)(param_2 + 0x4a) = param_1 + 2;
  param_1[3] = param_2;
  iVar5 = 0;
  *(byte *)(param_2 + 0x48) = *(byte *)(param_2 + 0x48) & 0xfe;
  if ((*(byte *)(iVar6 + 0x24) & 0x20) == 0) {
    iVar5 = _scsi_dstart(iVar6);
  }
  if (iVar5 == 0) {
    bVar4 = *(byte *)(param_2 + 0x48);
    while ((bVar4 & 1) == 0) {
      _sleep(param_2,0x14);
      bVar4 = *(byte *)(param_2 + 0x48);
    }
  }
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  if (((*(int *)(param_2 + 0x3c) == 0) || (*(int *)(param_2 + 0xc) != 0)) ||
     (iVar6 = _copyoutmsg(uStack_10,uVar1,*(int *)(param_2 + 0x3c)), iVar6 == 0)) {
    if (*(int *)(param_2 + 0x14) != 0) {
      _kmem_free(_kernel_map,uStack_10,*(int *)(param_2 + 0x14));
    }
    puVar3 = (undefined4 *)param_1[1];
    *(undefined4 *)(param_2 + 0x22) = *puVar3;
    *(undefined4 *)(param_2 + 0x26) = puVar3[1];
    *(undefined4 *)(param_2 + 0x2a) = puVar3[2];
    *(undefined4 *)(param_2 + 0x2e) = puVar3[3];
    *(undefined4 *)(param_2 + 0x32) = puVar3[4];
    *(undefined4 *)(param_2 + 0x36) = puVar3[5];
    *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar3 + 6);
    _microtime(&uStack_18);
    _timevalsub(&uStack_18,auStack_c);
    *(undefined4 *)(param_2 + 0x40) = uStack_18;
    *(undefined4 *)(param_2 + 0x44) = uStack_14;
    iVar6 = 0;
  }
  else {
    _kmem_free(_kernel_map,uStack_10,*(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 0x1c) = 9;
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=3086 start=0x40800cc */

void sub_40800CC(void)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  sword sVar5;
  uint uVar6;
  uint unaff_D5;
  undefined *puVar7;
  uint uStack_24;
  uint *puVar8;
  
  puVar7 = &stack0xffffffe0;
  dword_40B5080 = (_gpflags & 0x1f) >> 4;
  dword_40B5084 = (_gpflags & 0xf) >> 3;
  byte_40C6CED = (undefined)_gpflags;
  if ((_vol_r == dword_40B5088) && (_vol_l == dword_40B508C)) {
    uStack_24 = _gpflags << 0x18;
    _mon_send(0xc4);
    puVar7 = &stack0xffffffe0;
  }
  else {
    _vol_r = _vol_r & 0x3f;
    _vol_l = _vol_l & 0x3f;
    if (_mon_rev != '\0') {
      uStack_24 = _gpflags << 0x18;
      _mon_send(0xc4);
      _delay(200);
      if (_vol_l == _vol_r) {
        uStack_24 = _vol_r << 0x18 | 0xc0000000;
        _mon_send(0xc2);
      }
      else {
        uStack_24 = _vol_r << 0x18 | 0x80000000;
        _mon_send(0xc2);
        _delay(200);
        _mon_send(0xc2,_vol_l << 0x18 | 0x40000000);
      }
      puVar8 = &uStack_24;
      uStack_24 = 200;
      _delay();
      dword_40B5088 = _vol_r;
      dword_40B508C = _vol_l;
      goto loc_4080342;
    }
    unaff_D5 = _gpflags << 0x18;
  }
  do {
    if ((_vol_r == dword_40B5088) && (_vol_l == dword_40B508C)) {
      return;
    }
    if (_vol_l == _vol_r) {
      uVar6 = _vol_r | 0x7c0;
      dword_40B5088 = _vol_r;
loc_4080278:
      dword_40B508C = _vol_l;
    }
    else {
      if (_vol_r == dword_40B5088) {
        uVar6 = _vol_l | 0x740;
        goto loc_4080278;
      }
      uVar6 = _vol_r | 0x780;
      dword_40B5088 = _vol_r;
    }
    *(uint *)(puVar7 + -4) = unaff_D5;
    *(undefined4 *)(puVar7 + -8) = 0xc4;
    *(undefined4 *)(puVar7 + -0xc) = 0x408028e;
    _mon_send();
    *(undefined4 *)(puVar7 + -0xc) = 200;
    *(undefined4 *)(puVar7 + -0x10) = 0x4080298;
    _delay();
    uVar4 = 10;
    do {
      uVar1 = (int)uVar6 >> (uVar4 & 0x3f) & 1;
      uVar2 = unaff_D5;
      if (uVar1 != 0) {
        uVar2 = unaff_D5 | 0x2000000;
      }
      *(uint *)(puVar7 + -4) = uVar2;
      *(undefined4 *)(puVar7 + -8) = 0xc4;
      *(undefined4 *)(puVar7 + -0xc) = 0x40802ba;
      _mon_send();
      *(undefined4 *)(puVar7 + -0xc) = 200;
      *(undefined4 *)(puVar7 + -0x10) = 0x40802c4;
      _delay();
      if (uVar1 == 0) {
        uVar1 = unaff_D5 | 0x4000000;
      }
      else {
        uVar1 = unaff_D5 | 0x6000000;
      }
      *(uint *)(puVar7 + -4) = uVar1;
      *(undefined4 *)(puVar7 + -8) = 0xc4;
      *(undefined4 *)(puVar7 + -0xc) = 0x40802e8;
      _mon_send();
      *(undefined4 *)(puVar7 + -0xc) = 200;
      *(undefined4 *)(puVar7 + -0x10) = 0x40802f2;
      _delay();
      wVar3 = (word)(uVar4 >> 0x10);
      sVar5 = (sword)uVar4 + -1;
      uVar4 = CONCAT22(wVar3,sVar5);
    } while ((sVar5 != -1) || (uVar4 = (uint)wVar3 * 0x10000 - 1, wVar3 != 0));
    *(uint *)(puVar7 + -4) = unaff_D5;
    *(undefined4 *)(puVar7 + -8) = 0xc4;
    *(undefined4 *)(puVar7 + -0xc) = 0x408030e;
    _mon_send();
    *(undefined4 *)(puVar7 + -0xc) = 200;
    *(undefined4 *)(puVar7 + -0x10) = 0x408031a;
    _delay();
    *(uint *)(puVar7 + -0x10) = unaff_D5 | 0x1000000;
    *(undefined4 *)(puVar7 + -0x14) = 0xc4;
    *(undefined4 *)(puVar7 + -0x18) = 0x4080328;
    _mon_send();
    *(undefined4 *)(puVar7 + -0x18) = 200;
    *(undefined4 *)(puVar7 + -0x1c) = 0x408032e;
    _delay();
    *(uint *)(puVar7 + -0x1c) = unaff_D5;
    *(undefined4 *)(puVar7 + -0x20) = 0xc4;
    *(undefined4 *)(puVar7 + -0x24) = 0x4080336;
    _mon_send();
    puVar8 = (uint *)(puVar7 + -4);
    *(undefined4 *)(puVar7 + -4) = 200;
    *(undefined4 *)(puVar7 + -8) = 0x4080342;
    _delay();
loc_4080342:
    puVar7 = (undefined *)((int)puVar8 + 4);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3087 start=0x4080388 */

void sub_4080388(void)

{
  uint uVar1;
  uint uVar2;
  word wStack_24;
  undefined uStack_22;
  byte bStack_21;
  undefined2 uStack_20;
  
  _nvram_check(&wStack_24);
  uVar1 = CONCAT31(CONCAT21(wStack_24,uStack_22),bStack_21) & 0xfc0fffff;
  wStack_24 = (word)(uVar1 >> 0x10) | (word)(((wRam040b508a & 0x3f) << 0x14) >> 0x10);
  uVar2 = CONCAT22((sword)uVar1,uStack_20) & 0xfc0fffff;
  uVar1 = uVar2 | (wRam040b508e & 0x3f) << 0x14;
  uStack_22 = (undefined)(uVar1 >> 0x18);
  bStack_21 = (byte)(uVar1 >> 0x10);
  uStack_20 = (undefined2)uVar2;
  bStack_21 = bStack_21 & 0xf3 | (byte)((dword_40B5084 & 1) << 2) | (byte)((dword_40B5080 & 1) << 3)
  ;
  _nvram_set(&wStack_24);
  return;
}
/* GHIDRADEC_FUNCTION index=3088 start=0x408061a */

void sub_408061A(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((&unk_40C6DF4)[param_1] == 0) {
    iVar2 = _kalloc(0x54);
    _snd_stream_queue_init(iVar2,iVar2,_dspq_start_complex);
    iVar1 = iVar2 + 0x3e;
    *(int *)(iVar2 + 0x42) = iVar1;
    *(int *)iVar1 = iVar1;
    (&unk_40C6DF4)[param_1] = iVar2;
    *(undefined4 *)(iVar2 + 0x32) = 0x10000;
    *(undefined4 *)(iVar2 + 0x36) = 0xc000;
    *(undefined4 *)(iVar2 + 0x46) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3089 start=0x408067a */

/* WARNING: Type propagation algorithm not settling */

undefined4 sub_408067A(int param_1)

{
  undefined4 uVar1;
  undefined4 ******ppppppuVar2;
  uint uVar3;
  int iVar4;
  word wVar5;
  undefined4 *******pppppppuVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 ******ppppppuVar11;
  undefined4 ******ppppppuVar12;
  int iVar13;
  uint uVar14;
  undefined uVar15;
  undefined4 *******unaff_A3;
  int iVar16;
  uint uStack_1c;
  undefined uStack_d;
  undefined4 *******pppppppuStack_c;
  undefined4 *******pppppppuStack_8;
  
  iVar13 = *(int *)(param_1 + 4) + -0x24;
  uVar10 = *(undefined4 *)(param_1 + 0x1c);
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  ppppppuVar2 = *(undefined4 *******)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x14) == 200) {
    if ((dword_40C6E84 & 0x20000) == 0) {
      iVar9 = param_1 + 0x24;
      pppppppuStack_c = &pppppppuStack_c;
      pppppppuStack_8 = &pppppppuStack_c;
      while (0 < iVar13) {
        uVar15 = (undefined)uVar1;
        uStack_d = (undefined)uVar10;
        switch(*(undefined4 *)(iVar9 + 4)) {
        case :
          uStack_1c = (uint)*(word *)(iVar9 + 0xe);
          ppppppuVar11 = (undefined4 ******)(*(int *)(iVar9 + 0x10) * uStack_1c >> 3);
          if ((*(byte *)(iVar9 + 0xb) & 8) == 0) {
            uVar8 = ~_page_mask;
            uVar3 = *(uint *)(iVar9 + 0x14);
            uVar14 = uVar3 % _page_size;
            uVar7 = (int)ppppppuVar11 + _page_mask + uVar14 & uVar8;
            unaff_A3 = (undefined4 *******)_kalloc(0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 0;
            pppppppuVar6 = unaff_A3 + 1;
            iVar16 = _vm_allocate(_kernel_map,pppppppuVar6,uVar7,1);
            if (iVar16 != 0) {
              return 0x68;
            }
            iVar16 = _vm_map_copy(_kernel_map,dword_40C6EBC,*pppppppuVar6,uVar7,uVar8 & uVar3,0,1);
            if (iVar16 != 0) {
              _vm_deallocate(_kernel_map,*pppppppuVar6,uVar7);
              return 0x68;
            }
            _vm_map_pageable(_kernel_map,*pppppppuVar6,(int)*pppppppuVar6 + uVar7,0);
            *pppppppuVar6 = (undefined4 ******)(uVar14 + (int)*pppppppuVar6);
            iVar13 = iVar13 + -0x18;
            iVar16 = iVar9 + 0x18;
          }
          else {
            unaff_A3 = (undefined4 *******)_kalloc((int)ppppppuVar11 + 0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 1;
            _bcopy(iVar9 + 0x14,(undefined4 ******)((int)unaff_A3 + 0x26),ppppppuVar11);
            unaff_A3[1] = (undefined4 ******)((int)unaff_A3 + 0x26);
            iVar13 = (iVar13 + -0x14) - (int)ppppppuVar11;
            iVar16 = iVar9 + 0x14 + (int)ppppppuVar11;
          }
          wVar5 = *(word *)(iVar9 + 0xe);
          if (wVar5 == 0x10) {
            ppppppuVar12 = (undefined4 ******)0x2;
loc_408089C:
            *unaff_A3 = ppppppuVar12;
          }
          else {
            if (0x10 < wVar5) {
              if (wVar5 == 0x18) {
                ppppppuVar12 = (undefined4 ******)0x3;
              }
              else {
                if (wVar5 != 0x20) goto loc_408089E;
                ppppppuVar12 = (undefined4 ******)0x4;
              }
              goto loc_408089C;
            }
            if (wVar5 == 8) {
              ppppppuVar12 = (undefined4 ******)0x1;
              goto loc_408089C;
            }
          }
loc_408089E:
          unaff_A3[2] = ppppppuVar11;
          unaff_A3[3] = unaff_A3[1];
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 0x10;
          iVar13 = iVar13 + -0x10;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x7;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          break;
        case :
          iVar16 = iVar9 + 0x14;
          iVar13 = iVar13 + -0x14;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x8;
          unaff_A3[1] = (undefined4 ******)(*(uint *)(iVar9 + 0xc) & 0xf89f0000);
          unaff_A3[2] = (undefined4 ******)(*(uint *)(iVar9 + 0x10) & 0xf89f0000);
          break;
        case :
          iVar4 = *(int *)(iVar9 + 0x20);
          if ((*(byte *)(iVar9 + 0x13) & 8) == 0) {
            unaff_A3 = (undefined4 *******)_kalloc(0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 0;
          }
          else {
            unaff_A3 = (undefined4 *******)_kalloc(iVar4 + 0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 1;
            _bcopy(iVar9 + 0x1c,(undefined4 ******)((int)unaff_A3 + 0x26),iVar4);
            unaff_A3[1] = (undefined4 ******)((int)unaff_A3 + 0x26);
          }
          *unaff_A3 = (undefined4 ******)0x9;
          if (*(undefined4 ******)(iVar9 + 0xc) == (undefined4 *****)0x0) {
            unaff_A3[1][4] = _snd_var;
          }
          else {
            unaff_A3[1][4] = *(undefined4 ******)(iVar9 + 0xc);
          }
          iVar16 = iVar4 + 0x1c + iVar9;
          iVar13 = (iVar13 + -0x1c) - iVar4;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 8;
          iVar13 = iVar13 + -8;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0xa;
          break;
        case :
          iVar16 = iVar9 + 8;
          iVar13 = iVar13 + -8;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0xb;
          break;
        case :
          iVar16 = iVar9 + 0x1c;
          iVar13 = iVar13 + -0x1c;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x0;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          unaff_A3[2] = *(undefined4 *******)(iVar9 + 0x10);
          unaff_A3[3] = *(undefined4 *******)(iVar9 + 0x18);
          break;
        case :
          ppppppuVar11 = *(undefined4 *******)(iVar9 + 0x14);
          if ((undefined4 ******)0x1fd0 < ppppppuVar11) {
            return 0x68;
          }
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          ppppppuVar12 = (undefined4 ******)_kalloc(ppppppuVar11);
          unaff_A3[1] = ppppppuVar12;
          *(undefined *)((int)unaff_A3 + 0x23) = 0;
          unaff_A3[4] = ppppppuVar2;
          wVar5 = *(word *)(iVar9 + 0xe);
          if (wVar5 == 0x10) {
            ppppppuVar12 = (undefined4 ******)0xe;
loc_4080922:
            *unaff_A3 = ppppppuVar12;
          }
          else {
            if (0x10 < wVar5) {
              if (wVar5 == 0x18) {
                ppppppuVar12 = (undefined4 ******)0xf;
              }
              else {
                if (wVar5 != 0x20) goto loc_4080924;
                ppppppuVar12 = (undefined4 ******)0x10;
              }
              goto loc_4080922;
            }
            if (wVar5 == 8) {
              ppppppuVar12 = (undefined4 ******)0xd;
              goto loc_4080922;
            }
          }
loc_4080924:
          unaff_A3[2] = ppppppuVar11;
          unaff_A3[3] = unaff_A3[1];
          iVar16 = iVar9 + 0x18;
          iVar13 = iVar13 + -0x18;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 0x10;
          iVar13 = iVar13 + -0x10;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x11;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          *(undefined *)((int)unaff_A3 + 0x23) = 0;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        :
          goto loc_40806AA;
        }
        *(undefined *)((int)unaff_A3 + 0x23) = 0;
        *(undefined *)(unaff_A3 + 8) = uStack_d;
        *(undefined *)((int)unaff_A3 + 0x21) = 3;
        *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
        *(undefined *)(unaff_A3 + 9) = 0;
        pppppppuVar6 = pppppppuStack_c;
joined_r0x04080ab2:
        pppppppuStack_c = unaff_A3;
        if ((undefined4 ********)pppppppuStack_8 != &pppppppuStack_c) {
          pppppppuStack_8[6] = unaff_A3;
          pppppppuStack_c = pppppppuVar6;
        }
        unaff_A3[7] = pppppppuStack_8;
        unaff_A3[6] = &pppppppuStack_c;
        iVar9 = iVar16;
        pppppppuStack_8 = unaff_A3;
      }
      if ((undefined4 ********)pppppppuStack_c == &pppppppuStack_c) {
        _dspq_execute();
      }
      else {
        if (pppppppuStack_8 == pppppppuStack_c) {
          *(undefined *)((int)unaff_A3 + 0x21) = 0;
        }
        else {
          *(undefined *)((int)pppppppuStack_8 + 0x21) = 2;
          *(undefined *)((int)pppppppuStack_c + 0x21) = 1;
        }
        _dspq_enqueue(&pppppppuStack_c);
      }
      uVar10 = 100;
    }
    else {
      uVar10 = 0x6d;
    }
  }
  else {
loc_40806AA:
    uVar10 = 0x66;
  }
  return uVar10;
}
/* GHIDRADEC_FUNCTION index=3090 start=0x4080b2e */

undefined4 sub_4080B2E(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(*(int *)(param_1 + 0x3c) + 0x26);
  *puVar1 = 9;
  *(undefined *)((int)puVar1 + 0x23) = 1;
  *(undefined *)(puVar1 + 9) = 0;
  _bcopy(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
         *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),
         *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),(int)puVar1 + 0x26,
         *(undefined4 *)(param_1 + 0x3c));
  if (dword_40C6E72 != (undefined4 *)0x0) {
    _dspq_free_msg(dword_40C6E72);
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(puVar1[1] + 0x10) = _snd_var;
  }
  else {
    *(int *)(puVar1[1] + 0x10) = *(int *)(param_1 + 0x28);
  }
  dword_40C6E6A = *(undefined4 *)(param_1 + 0x1c);
  dword_40C6E6E = *(undefined4 *)(param_1 + 0x20);
  dword_40C6E72 = puVar1;
  _dspq_execute();
  return 100;
}
/* GHIDRADEC_FUNCTION index=3091 start=0x4080be6 */

undefined4 sub_4080BE6(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if ((*(int *)(param_1 + 4) == 0x34) && (iVar1 = *(int *)(param_1 + 0x30), iVar1 - 1U < 0x13)) {
    if (*(int *)(param_1 + 0x2c) == 5) {
      uVar3 = *(int *)(param_1 + 0x20) * 2;
    }
    else {
      uVar3 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x20);
    }
    if (uVar3 <= _page_size) {
      if (*(int *)(param_1 + 0x2c) == 5) {
        uVar3 = *(int *)(param_1 + 0x20) * 2;
      }
      else {
        uVar3 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x20);
      }
      if (_page_size % uVar3 == 0) {
        iVar4 = (&unk_40C6DF4)[iVar1];
        if (iVar4 == 0) {
          iVar4 = _kalloc(0x54);
          pcVar6 = _dspq_start_simple;
          if ((dword_40C6E84 & 0x2000) != 0) {
            pcVar6 = _dspq_start_complex;
          }
          _snd_stream_queue_init(iVar4,iVar4,pcVar6);
          iVar2 = iVar4 + 0x3e;
          *(int *)(iVar4 + 0x42) = iVar2;
          *(int *)iVar2 = iVar2;
          (&unk_40C6DF4)[iVar1] = iVar4;
        }
        *(undefined4 *)(iVar4 + 0x46) = 0;
        *(undefined4 *)(iVar4 + 0x4a) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined2 *)(iVar4 + 0x4e) = *(undefined2 *)(param_1 + 0x22);
        *(undefined2 *)(iVar4 + 0x50) = *(undefined2 *)(param_1 + 0x26);
        *(undefined *)(iVar4 + 0x52) = *(undefined *)(param_1 + 0x2b);
        *(undefined *)(iVar4 + 0x53) = *(undefined *)(param_1 + 0x2f);
        uVar5 = _snd_dspcmd_def_dmasize(iVar1);
        *(undefined4 *)(iVar4 + 0x2a) = uVar5;
        uVar5 = _snd_dspcmd_def_high_water(iVar1);
        *(undefined4 *)(iVar4 + 0x32) = uVar5;
        uVar5 = _snd_dspcmd_def_low_water(iVar1);
        *(undefined4 *)(iVar4 + 0x36) = uVar5;
        return 100;
      }
    }
  }
  return 0x67;
}
/* GHIDRADEC_FUNCTION index=3092 start=0x4080d78 */

int sub_4080D78(int param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuStack_5c;
  undefined4 **ppuStack_58;
  undefined auStack_54 [12];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_18;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  sub_408061A(0);
  _bcopy(unk_40B20FA,auStack_54,0x50);
  uStack_44 = 0x10000;
  uStack_48 = *(undefined4 *)(param_1 + 0x10);
  uStack_18 = *(undefined4 *)(param_1 + 0x10);
  uStack_8 = *(undefined4 *)(param_1 + 0x3c);
  uStack_10 = *(undefined2 *)(param_1 + 0x34);
  uStack_e = *(undefined2 *)(param_1 + 0x36);
  uStack_c = *(undefined4 *)(param_1 + 0x38);
  iVar2 = _msg_send(auStack_54,0,0);
  if (iVar2 == 0) {
    ppuStack_5c = &ppuStack_5c;
    ppuStack_58 = &ppuStack_5c;
    pppuVar3 = (undefined4 ***)_kalloc(0x26);
    *pppuVar3 = (undefined4 **)0x5;
    pppuVar3[1] = *(undefined4 ***)(param_1 + 0x1c);
    *(undefined2 *)(pppuVar3 + 2) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)((int)pppuVar3 + 10) = *(undefined2 *)(param_1 + 0x26);
    *(undefined *)(pppuVar3 + 3) = *(undefined *)(param_1 + 0x2b);
    *(undefined *)((int)pppuVar3 + 0xd) = *(undefined *)(param_1 + 0x2f);
    *(undefined *)((int)pppuVar3 + 0xe) = 0;
    *(undefined *)((int)pppuVar3 + 0x23) = 0;
    *(undefined *)(pppuVar3 + 9) = 0;
    pppuVar1 = pppuVar3;
    if ((undefined4 ***)ppuStack_58 != &ppuStack_5c) {
      ppuStack_58[6] = pppuVar3;
      pppuVar1 = (undefined4 ***)ppuStack_5c;
    }
    ppuStack_5c = pppuVar1;
    pppuVar3[7] = ppuStack_58;
    pppuVar3[6] = &ppuStack_5c;
    ppuStack_58 = pppuVar3;
    _dspq_enqueue(&ppuStack_5c);
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=3093 start=0x4080e6e */

int sub_4080E6E(int param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuStack_54;
  undefined4 **ppuStack_50;
  undefined auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_14;
  undefined4 uStack_c;
  
  sub_408061A(0);
  _bcopy(unk_40B214A,auStack_4c,0x48);
  uStack_3c = 0x10000;
  uStack_40 = *(undefined4 *)(param_1 + 0x10);
  uStack_c = *(undefined4 *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x2c) == 5) {
    iStack_14 = *(int *)(param_1 + 0x20) * 2;
  }
  else {
    iStack_14 = *(int *)(param_1 + 0x20) * *(int *)(param_1 + 0x2c);
  }
  iVar2 = _msg_send(auStack_4c,0,0);
  if (iVar2 == 0) {
    ppuStack_54 = &ppuStack_54;
    ppuStack_50 = &ppuStack_54;
    pppuVar3 = (undefined4 ***)_kalloc(0x26);
    *pppuVar3 = (undefined4 **)0x6;
    pppuVar3[1] = *(undefined4 ***)(param_1 + 0x1c);
    *(undefined2 *)(pppuVar3 + 2) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)((int)pppuVar3 + 10) = *(undefined2 *)(param_1 + 0x26);
    *(undefined *)(pppuVar3 + 3) = *(undefined *)(param_1 + 0x2b);
    *(undefined *)((int)pppuVar3 + 0xd) = *(undefined *)(param_1 + 0x2f);
    *(undefined *)((int)pppuVar3 + 0xe) = 0;
    *(undefined *)(pppuVar3 + 8) = 2;
    *(undefined *)((int)pppuVar3 + 0x22) = 0;
    *(undefined *)((int)pppuVar3 + 0x21) = 0;
    *(undefined *)((int)pppuVar3 + 0x23) = 0;
    *(undefined *)(pppuVar3 + 9) = 0;
    pppuVar1 = pppuVar3;
    if ((undefined4 ***)ppuStack_50 != &ppuStack_54) {
      ppuStack_50[6] = pppuVar3;
      pppuVar1 = (undefined4 ***)ppuStack_54;
    }
    ppuStack_54 = pppuVar1;
    pppuVar3[7] = ppuStack_50;
    pppuVar3[6] = &ppuStack_54;
    ppuStack_50 = pppuVar3;
    _dspq_enqueue(&ppuStack_54);
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=3094 start=0x4080f78 */

undefined4 sub_4080F78(void)

{
  return 0x67;
}
/* GHIDRADEC_FUNCTION index=3095 start=0x4080f82 */

undefined4 sub_4080F82(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = dword_40C6E5A == dword_40C6E56;
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = _snd_var;
  }
  if (dword_40C6E5A != dword_40C6E52) {
    _snd_reply_dsp_msg(iVar1);
    iVar1 = dword_40C6E7C;
  }
  dword_40C6E7C = iVar1;
  if (bVar2) {
    _dsp_dev_loop();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=3096 start=0x4080fe0 */

undefined4 sub_4080FE0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = dword_40C6E66 == dword_40C6E62;
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = _snd_var;
  }
  if (dword_40C6E66 != dword_40C6E5E) {
    _snd_reply_dsp_err(iVar1);
    iVar1 = dword_40C6E80;
  }
  dword_40C6E80 = iVar1;
  if (bVar2) {
    _dsp_dev_loop();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=3097 start=0x40818b4 */

byte sub_40818B4(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(_slot_id_bmap + 0x2008002);
  if ((char)bVar2 < '\0') {
    if (((_snd_var == 0) && (dword_40C6E76 == 0)) || (dword_40C6E76 == 7)) {
      bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfc;
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfc;
    }
    else {
      if (((*(byte *)(_slot_id_bmap + 0x2008000) & 2) != 0) &&
         (*(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfd,
         (dword_40C6E84 & 0x2000) != 0)) {
        _softint_run(3);
      }
      if ((*(byte *)(_slot_id_bmap + 0x2008000) & 1) != 0) {
        if (((dword_40C6E84 & 0x2c00) == 0) && ((dword_40C6E84 & 0x100) != 0)) {
          bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
        }
        else {
          bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
        }
        *(byte *)(_slot_id_bmap + 0x2008000) = bVar2;
      }
      if (dword_40C6E76 == 3) {
        _dsp_dev_reset_chip();
      }
      if (((*(byte *)(_slot_id_bmap + 0x2008002) & 0x18) == 0x18) && ((dword_40C6E84 & 0x200) != 0))
      {
        dword_40C6E76 = 7;
        _printf(aDspAborted);
      }
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 0x40) != 0) {
        sub_40826E6(1);
      }
      if (((*(byte *)(_slot_id_bmap + 0x2008002) & 3) == 0) && (iVar1 = _dspq_check(), iVar1 == 0))
      {
        return 0;
      }
      bVar2 = _dsp_dev_loop();
    }
  }
  return bVar2;
}
/* GHIDRADEC_FUNCTION index=3098 start=0x40821fa */

void sub_40821FA(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_5 != 0x40000) || (param_2 == 0)) {
    uVar1 = 0;
    if ((param_1 == 0) && (param_3 == 4)) {
      uVar1 = param_2;
    }
    uVar1 = uVar1 & 0x1f;
    if (param_5 == 0x40000) {
      uVar2 = uVar1 | 0x10000;
    }
    else {
      uVar2 = uVar1 | 0x20000;
      if ((param_4 == 4) && (_dma_chip == 0x139)) {
        uVar2 = CONCAT22(2,(sword)uVar1) | 0x8000;
      }
    }
    dword_40C6E84 = dword_40C6E84 | 0x40;
    _dspq_enqueue_syscall(uVar2);
    _dspq_enqueue_cond(0x800000,0);
    dword_40C6E84 = dword_40C6E84 & 0xffffffbf;
    _dspq_execute();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3099 start=0x408229e */

undefined4 sub_408229E(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  word extraout_D0u;
  word wVar5;
  word extraout_D0u_00;
  byte bVar6;
  int iVar7;
  char cVar8;
  
  bVar6 = 1;
  if (param_4 == 0) {
    bVar6 = 2;
  }
  bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) & 0x18 | bVar6;
  iVar3 = (&unk_40C6DF4)[param_2];
  iVar2 = *(int *)(iVar3 + 0x3e);
  iVar7 = *(int *)(iVar2 + 0x2c);
  if (iVar7 == iVar3 + 0x3e) {
    *(int *)(iVar3 + 0x42) = iVar7;
  }
  else {
    *(int *)(iVar7 + 0x30) = iVar3 + 0x3e;
  }
  *(int *)(iVar3 + 0x3e) = iVar7;
  dword_40C6D1C = param_4;
  *(undefined4 *)(iVar2 + 0x18) = 4;
  if ((param_3 - 1 < 2) && (param_4 == 0)) {
    iVar7 = 10;
    bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
    while ((bVar4 & 4) == 0) {
      _delay(1);
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) goto loc_4082358;
      bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
    }
    if (iVar7 == 0) {
loc_4082358:
      _printf(aDspDmaTimedOut);
    }
    if (param_3 == 1) {
      *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
      *(undefined *)(_slot_id_bmap + 0x2008006) = 0;
    }
    else if (param_3 == 2) {
      *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
    }
  }
  sub_40826E6(1);
  _dma_enqueue(&_dsp_var,iVar2 + 0xc);
  wVar5 = extraout_D0u;
  if (param_3 == 2) {
    *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x40;
    cVar8 = '\0';
  }
  else if ((int)param_3 < 3) {
    cVar8 = 1 < param_3;
    if (param_3 == 1) {
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x60;
    }
  }
  else if (param_3 == 3) {
    uVar1 = *_scr2;
    *_scr2 = uVar1 & 0xdfffffff;
    wVar5 = (word)(uVar1 >> 0x10) & 0xdfff;
    *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x20;
    cVar8 = '\0';
  }
  else {
    cVar8 = 4 < param_3;
    if (param_3 == 4) {
      uVar1 = *_scr2;
      *_scr2 = uVar1 | 0x20000000;
      wVar5 = (word)(uVar1 >> 0x10) | 0x2000;
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x20;
      cVar8 = _dma_chip < 0x139;
      if (_dma_chip == 0x139) {
        _printf(aAttemptToUseBr);
        wVar5 = extraout_D0u_00;
      }
    }
  }
  bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 0x10;
  *(byte *)(_slot_id_bmap + 0x2008000) = bVar6;
  return CONCAT22(wVar5,(word)(byte)(cVar8 << 4 | ((char)bVar6 < '\0') << 3 | (bVar6 == 0) << 2));
}

