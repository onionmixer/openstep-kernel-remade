/* GHIDRADEC_FUNCTION index=3050 start=0x407c04a */

void sub_407C04A(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x18);
  *(undefined *)(param_1 + 0x5a) = 2;
  (**(code **)(*(int *)(iVar1 + 0x14) + 0x12))(iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=3051 start=0x407c2f4 */

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
/* GHIDRADEC_FUNCTION index=3052 start=0x407c894 */

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
/* GHIDRADEC_FUNCTION index=3053 start=0x407ca92 */

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
/* GHIDRADEC_FUNCTION index=3054 start=0x407cb90 */

void sub_407CB90(undefined4 param_1)

{
  _wakeup(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3055 start=0x407cba2 */

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
/* GHIDRADEC_FUNCTION index=3056 start=0x407cc0e */

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
/* GHIDRADEC_FUNCTION index=3057 start=0x407cc7a */

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
/* GHIDRADEC_FUNCTION index=3058 start=0x407ccee */

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
/* GHIDRADEC_FUNCTION index=3059 start=0x407cd5c */

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
/* GHIDRADEC_FUNCTION index=3060 start=0x407d376 */

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
/* GHIDRADEC_FUNCTION index=3061 start=0x407dcc4 */

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
/* GHIDRADEC_FUNCTION index=3062 start=0x407dd74 */

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
/* GHIDRADEC_FUNCTION index=3063 start=0x407e348 */

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
/* GHIDRADEC_FUNCTION index=3064 start=0x407e4a4 */

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
/* GHIDRADEC_FUNCTION index=3065 start=0x407e572 */

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
/* GHIDRADEC_FUNCTION index=3066 start=0x407e678 */

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
/* GHIDRADEC_FUNCTION index=3067 start=0x407e802 */

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
/* GHIDRADEC_FUNCTION index=3068 start=0x407e8b8 */

void sub_407E8B8(int param_1)

{
  _disksort_free(param_1 + 0x60);
  *(undefined4 *)(unk_40B4FDE + *(int *)(param_1 + 4) * 4) = 0;
  _kfree(*(undefined4 *)(param_1 + 0xce),0x1c58);
  _kfree(param_1,0xd6);
  return;
}
/* GHIDRADEC_FUNCTION index=3069 start=0x407e900 */

void sub_407E900(int *param_1,int param_2)

{
  *param_1 = (int)(_sd_sdd + param_2 * 0xc2);
  *(int **)(_sd_sdd + param_2 * 0xc2) = param_1;
  param_1[2] = param_1[2] & 0xfffffffe;
  return;
}
/* GHIDRADEC_FUNCTION index=3070 start=0x407e934 */

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
/* GHIDRADEC_FUNCTION index=3071 start=0x407efce */

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
/* GHIDRADEC_FUNCTION index=3072 start=0x407f042 */

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
/* GHIDRADEC_FUNCTION index=3073 start=0x407f0a8 */

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
/* GHIDRADEC_FUNCTION index=3074 start=0x407f13e */

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

