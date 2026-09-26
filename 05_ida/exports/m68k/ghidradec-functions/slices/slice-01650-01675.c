/* GHIDRADEC_FUNCTION index=1650 start=0x4053e1a */

byte _thread_doswapin(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  _stack_alloc(param_1,_thread_continue);
  cVar3 = '\0';
  uVar1 = *(uint *)(param_1 + 0x48);
  uVar2 = uVar1 & 0xfffffcff;
  *(uint *)(param_1 + 0x48) = uVar2;
  cVar4 = (int)uVar2 < 0;
  cVar6 = '\0';
  bVar7 = 0;
  cVar5 = (uVar1 & 4) == 0;
  if (!(bool)cVar5) {
    cVar4 = param_1 < 0;
    cVar5 = param_1 == 0;
    cVar6 = '\0';
    bVar7 = 0;
    _thread_setrun(param_1,1);
  }
  return cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=1651 start=0x4053e70 */

void _swapin_thread_continue(void)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  
  do {
    while (piVar2 = _swapin_queue, (int **)_swapin_queue == &_swapin_queue) {
loc_4053EB8:
      _assert_wait(&_swapin_queue,0);
      _thread_block_with_continuation(_swapin_thread_continue);
    }
    *(int ***)(*_swapin_queue + 4) = &_swapin_queue;
    piVar1 = (int *)*_swapin_queue;
    bVar3 = _swapin_queue == (int *)0x0;
    _swapin_queue = piVar1;
    if (bVar3) goto loc_4053EB8;
    _thread_doswapin(piVar2);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1652 start=0x4053ede */

void _swapin_thread(void)

{
  _stack_privilege(_active_threads);
                    /* WARNING: Subroutine does not return */
  _swapin_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1653 start=0x4053ef8 */

void _calloutInitialize(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  if (dword_40AFF2C == 0) {
    dword_40B4DC4 = &dword_40B4DC0;
    dword_40B4DC0 = &dword_40B4DC0;
    dword_40B4DCC = &dword_40B4DC8;
    dword_40B4DC8 = &dword_40B4DC8;
    dword_40B4DBC = &dword_40B4DB8;
    dword_40B4DB8 = &dword_40B4DB8;
    puVar3 = unk_40B45B8;
    puVar1 = &unk_40B45B4;
    do {
      puVar2 = puVar1;
      *puVar2 = &dword_40B4DB8;
      *(undefined4 **)puVar3 = dword_40B4DBC;
      **(undefined4 **)puVar3 = puVar2;
      puVar3 = (undefined *)((int)puVar3 + 0x20);
      puVar1 = puVar2 + 8;
      dword_40B4DBC = puVar2;
    } while (puVar2 + 8 < unk_40B45B8 + 0x7fc);
    _kernel_thread(_kernel_task,&loc_4054964,0);
    _set_timer_expire_func(0,sub_405497E);
    dword_40AFF2C = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1654 start=0x4054124 */

sqword _calloutDeadlineFromInterval(undefined4 param_1,undefined4 param_2)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  return sVar1 + CONCAT44(param_1,param_2);
}
/* GHIDRADEC_FUNCTION index=1655 start=0x405414e */

void _calloutDispatch(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = dword_40B4DB8;
  if (dword_40AFF2C != 0) {
    if ((int **)dword_40B4DB8 == &dword_40B4DB8) {
                    /* WARNING: Subroutine does not return */
      _panic(aInternalentrya);
    }
    *(int ***)(*dword_40B4DB8 + 4) = &dword_40B4DB8;
    piVar1 = dword_40B4DB8 + 2;
    dword_40B4DB8 = (int *)*dword_40B4DB8;
    *piVar1 = param_1;
    piVar2[3] = param_2;
    piVar2[4] = 0;
    piVar2[5] = 0;
    piVar2[6] = 0;
    *piVar2 = (int)&dword_40B4DC0;
    piVar2[1] = (int)dword_40B4DC4;
    *(int **)piVar2[1] = piVar2;
    dword_40B4DC4 = piVar2;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    piVar2[7] = 1;
    sub_4054786();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1656 start=0x40541fa */

void _calloutDispatchUnique(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = dword_40B4DB8;
  if (dword_40AFF2C != 0) {
    puVar3 = dword_40B4DC0;
    if ((undefined4 **)dword_40B4DC0 != &dword_40B4DC0) {
      do {
        if ((param_1 == puVar3[2]) && (param_2 == puVar3[3])) break;
        puVar3 = (undefined4 *)*puVar3;
      } while ((undefined4 **)puVar3 != &dword_40B4DC0);
      if ((undefined4 **)puVar3 != &dword_40B4DC0) {
        return;
      }
    }
    if ((int **)dword_40B4DB8 == &dword_40B4DB8) {
                    /* WARNING: Subroutine does not return */
      _panic(aInternalentrya);
    }
    *(int ***)(*dword_40B4DB8 + 4) = &dword_40B4DB8;
    piVar1 = dword_40B4DB8 + 2;
    dword_40B4DB8 = (int *)*dword_40B4DB8;
    *piVar1 = param_1;
    piVar2[3] = param_2;
    piVar2[4] = 0;
    piVar2[5] = 0;
    piVar2[6] = 0;
    *piVar2 = (int)&dword_40B4DC0;
    piVar2[1] = (int)dword_40B4DC4;
    *(int **)piVar2[1] = piVar2;
    dword_40B4DC4 = piVar2;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    piVar2[7] = 1;
    sub_4054786();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1657 start=0x40542da */

void _calloutDispatchDelayed(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar5 = dword_40B4DB8;
  if (dword_40AFF2C != 0) {
    if ((int **)dword_40B4DB8 == &dword_40B4DB8) {
                    /* WARNING: Subroutine does not return */
      _panic(aInternalentrya);
    }
    *(int ***)(*dword_40B4DB8 + 4) = &dword_40B4DB8;
    piVar6 = dword_40B4DB8 + 2;
    dword_40B4DB8 = (int *)*dword_40B4DB8;
    *piVar6 = param_1;
    piVar5[3] = param_2;
    piVar5[4] = 0;
    piVar5[5] = param_3;
    piVar5[6] = param_4;
    for (piVar6 = dword_40B4DC8; (int **)piVar6 != &dword_40B4DC8; piVar6 = (int *)*piVar6) {
      uVar1 = piVar5[5];
      uVar2 = piVar5[6];
      uVar3 = piVar6[5];
      uVar4 = piVar6[6];
      if (uVar1 < uVar3 || uVar2 < uVar4 && uVar1 == uVar3) break;
      if (uVar1 == (uVar2 < uVar4) + uVar3 && uVar2 == uVar4) goto loc_4054390;
    }
    piVar6 = (int *)piVar6[1];
loc_4054390:
    *piVar5 = *piVar6;
    piVar5[1] = (int)piVar6;
    *(int **)(*piVar6 + 4) = piVar5;
    *piVar6 = (int)piVar5;
    piVar5[7] = 2;
    if (piVar5 == dword_40B4DC8) {
      sub_4053F9C(piVar5);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1658 start=0x40543c4 */

byte _calloutRemove(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar2 = '\0';
  iVar1 = sub_4054012(param_1,param_2,0);
  cVar5 = '\0';
  bVar6 = 0;
  cVar3 = iVar1 < 0;
  cVar4 = '\0';
  if (iVar1 == 0) {
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    sub_405409E(param_1,param_2,0);
  }
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=1659 start=0x405440c */

byte _calloutRemoveAll(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  sub_4054012(param_1,param_2,1);
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  sub_405409E(param_1,param_2,1);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1660 start=0x405444e */

void _calloutEntryAllocate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x20);
  *(undefined4 *)(iVar1 + 8) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1661 start=0x405448e */

void _calloutEntryFree(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aCalloutentryfr);
  }
  _kfree(param_1,0x20);
  return;
}
/* GHIDRADEC_FUNCTION index=1662 start=0x40544d6 */

byte _calloutEntryDispatch(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = (int)param_1[7] < 0;
  cVar3 = '\0';
  if (param_1[7] == 0) {
    param_1[3] = param_1[4];
    param_1[5] = 0;
    param_1[6] = 0;
    *param_1 = &dword_40B4DC0;
    param_1[1] = dword_40B4DC4;
    *(undefined4 **)param_1[1] = param_1;
    dword_40B4DC4 = param_1;
    cVar1 = 0xfffffffe < dword_40B4DD0;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    param_1[7] = 1;
    cVar2 = '\0';
    cVar3 = '\0';
    cVar4 = '\0';
    bVar5 = 0;
    sub_4054786();
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1663 start=0x4054536 */

byte _calloutEntryDispatchWithArgument(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = (int)param_1[7] < 0;
  cVar3 = '\0';
  if (param_1[7] == 0) {
    param_1[3] = param_2;
    param_1[5] = 0;
    param_1[6] = 0;
    *param_1 = &dword_40B4DC0;
    param_1[1] = dword_40B4DC4;
    *(undefined4 **)param_1[1] = param_1;
    dword_40B4DC4 = param_1;
    cVar1 = 0xfffffffe < dword_40B4DD0;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    param_1[7] = 1;
    cVar2 = '\0';
    cVar3 = '\0';
    cVar4 = '\0';
    bVar5 = 0;
    sub_4054786();
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1664 start=0x4054596 */

undefined4 _calloutEntryDispatchDelayed(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 extraout_D0u;
  uint in_D0;
  uint uVar6;
  int *piVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  uVar6 = in_D0 & 0xffff0000;
  uVar5 = (undefined2)(in_D0 >> 0x10);
  cVar8 = '\0';
  cVar11 = '\0';
  cVar9 = param_1[7] < 0;
  cVar10 = '\0';
  bVar12 = 0;
  if (param_1[7] == 0) {
    param_1[3] = param_1[4];
    param_1[5] = param_2;
    param_1[6] = param_3;
    for (piVar7 = dword_40B4DC8; uVar5 = (undefined2)(uVar6 >> 0x10),
        (int **)piVar7 != &dword_40B4DC8; piVar7 = (int *)*piVar7) {
      uVar1 = param_1[5];
      uVar2 = param_1[6];
      uVar3 = piVar7[5];
      uVar4 = piVar7[6];
      uVar6 = uVar1 - ((uVar2 < uVar4) + uVar3);
      uVar5 = (undefined2)(uVar6 >> 0x10);
      if (uVar1 < uVar3 || uVar2 < uVar4 && uVar1 == uVar3) break;
      if (uVar1 == (uVar2 < uVar4) + uVar3 && uVar2 == uVar4) goto loc_40545FE;
    }
    piVar7 = (int *)piVar7[1];
loc_40545FE:
    *param_1 = *piVar7;
    param_1[1] = (int)piVar7;
    *(int **)(*piVar7 + 4) = param_1;
    *piVar7 = (int)param_1;
    param_1[7] = 2;
    cVar8 = param_1 < dword_40B4DC8;
    cVar11 = SBORROW4((int)param_1,(int)dword_40B4DC8);
    cVar9 = (int)param_1 - (int)dword_40B4DC8 < 0;
    cVar10 = '\0';
    bVar12 = cVar8;
    if (param_1 == dword_40B4DC8) {
      cVar9 = (int)param_1 < 0;
      cVar10 = param_1 == (int *)0x0;
      cVar11 = '\0';
      bVar12 = 0;
      sub_4053F9C(param_1);
      uVar5 = extraout_D0u;
    }
  }
  return CONCAT22(uVar5,(word)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12));
}
/* GHIDRADEC_FUNCTION index=1665 start=0x4054632 */

undefined4
_calloutEntryDispatchWithArgumentDelayed(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 extraout_D0u;
  uint in_D0;
  uint uVar6;
  int *piVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  uVar6 = in_D0 & 0xffff0000;
  uVar5 = (undefined2)(in_D0 >> 0x10);
  cVar8 = '\0';
  cVar11 = '\0';
  cVar9 = param_1[7] < 0;
  cVar10 = '\0';
  bVar12 = 0;
  if (param_1[7] == 0) {
    param_1[3] = param_2;
    param_1[5] = param_3;
    param_1[6] = param_4;
    for (piVar7 = dword_40B4DC8; uVar5 = (undefined2)(uVar6 >> 0x10),
        (int **)piVar7 != &dword_40B4DC8; piVar7 = (int *)*piVar7) {
      uVar1 = param_1[5];
      uVar2 = param_1[6];
      uVar3 = piVar7[5];
      uVar4 = piVar7[6];
      uVar6 = uVar1 - ((uVar2 < uVar4) + uVar3);
      uVar5 = (undefined2)(uVar6 >> 0x10);
      if (uVar1 < uVar3 || uVar2 < uVar4 && uVar1 == uVar3) break;
      if (uVar1 == (uVar2 < uVar4) + uVar3 && uVar2 == uVar4) goto loc_405469A;
    }
    piVar7 = (int *)piVar7[1];
loc_405469A:
    *param_1 = *piVar7;
    param_1[1] = (int)piVar7;
    *(int **)(*piVar7 + 4) = param_1;
    *piVar7 = (int)param_1;
    param_1[7] = 2;
    cVar8 = param_1 < dword_40B4DC8;
    cVar11 = SBORROW4((int)param_1,(int)dword_40B4DC8);
    cVar9 = (int)param_1 - (int)dword_40B4DC8 < 0;
    cVar10 = '\0';
    bVar12 = cVar8;
    if (param_1 == dword_40B4DC8) {
      cVar9 = (int)param_1 < 0;
      cVar10 = param_1 == (int *)0x0;
      cVar11 = '\0';
      bVar12 = 0;
      sub_4053F9C(param_1);
      uVar5 = extraout_D0u;
    }
  }
  return CONCAT22(uVar5,(word)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12));
}
/* GHIDRADEC_FUNCTION index=1666 start=0x40546ce */

undefined8 _calloutEntryRemove(int *param_1)

{
  uint uVar1;
  int unaff_D2;
  char in_XF;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  
  uVar1 = param_1[7];
  if (uVar1 == 1) {
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    dword_40B4DD0 = dword_40B4DD0 + -1;
    param_1[7] = 0;
    bVar5 = param_1 < &unk_40B45B4;
    bVar4 = SBORROW4((int)param_1,0x40b45b4);
    bVar2 = (int)(param_1 + -0x102d16d) < 0;
    bVar3 = param_1 == &unk_40B45B4;
    bVar6 = bVar5;
    if (!bVar5) {
      bVar5 = param_1 < &DAT_40b4db4;
      bVar4 = SBORROW4((int)param_1,0x40b4db4);
      bVar2 = (int)(param_1 + -0x102d36d) < 0;
      bVar3 = param_1 == &DAT_40b4db4;
      bVar6 = false;
      if (bVar5) {
        *param_1 = (int)&dword_40B4DB8;
        param_1[1] = (int)dword_40B4DBC;
        *(int **)param_1[1] = param_1;
        dword_40B4DBC = param_1;
        bVar2 = (int)param_1 < 0;
        bVar3 = param_1 == (int *)0x0;
        bVar4 = false;
        bVar6 = false;
      }
    }
  }
  else {
    bVar5 = 2 < uVar1;
    bVar4 = SBORROW4(2,uVar1);
    bVar2 = (int)(2 - uVar1) < 0;
    bVar3 = false;
    bVar6 = bVar5;
    if (uVar1 == 2) {
      *(int *)(*param_1 + 4) = param_1[1];
      *(int *)param_1[1] = *param_1;
      param_1[7] = 0;
      bVar5 = param_1 < &unk_40B45B4;
      bVar4 = SBORROW4((int)param_1,0x40b45b4);
      bVar2 = (int)(param_1 + -0x102d16d) < 0;
      bVar3 = param_1 == &unk_40B45B4;
      bVar6 = bVar5;
      if (!bVar5) {
        bVar5 = param_1 < &DAT_40b4db4;
        bVar4 = SBORROW4((int)param_1,0x40b4db4);
        bVar2 = (int)(param_1 + -0x102d36d) < 0;
        bVar3 = param_1 == &DAT_40b4db4;
        bVar6 = false;
        if (bVar5) {
          *param_1 = (int)&dword_40B4DB8;
          param_1[1] = (int)dword_40B4DBC;
          *(int **)param_1[1] = param_1;
          dword_40B4DBC = param_1;
          bVar2 = (int)param_1 < 0;
          bVar3 = param_1 == (int *)0x0;
          bVar4 = false;
          bVar6 = false;
        }
      }
    }
  }
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(bVar5 << 4 | bVar2 << 3 | bVar3 << 2 | bVar4 << 1 | bVar6)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}
/* GHIDRADEC_FUNCTION index=1667 start=0x4054aaa */

bool _kern_timestamp(undefined4 param_1)

{
  int iVar1;
  uint uStack_c;
  undefined4 uStack_8;
  
  uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
             0xfffff;
  if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  uStack_8 = *_event_high;
  uStack_c = *_event_middle | uStack_c;
  iVar1 = _copyoutmsg(&uStack_c,param_1,8);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=1668 start=0x4054b72 */

void _init_timers(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar3 = _kernel_timer;
  puVar1 = &_current_timer;
  do {
    _timer_init(puVar3);
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar3 = puVar3 + 0x10;
    puVar1 = puVar2;
  } while ((int)puVar2 < 0x40c2b81);
  return;
}
/* GHIDRADEC_FUNCTION index=1669 start=0x4054ba6 */

void _timer_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1670 start=0x4054bc0 */

void _timer_normalize(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  param_1[2] = uVar1 / 1000000 + param_1[2];
  *param_1 = *param_1 % 1000000;
  param_1[1] = uVar1 / 1000000 + param_1[1];
  return;
}
/* GHIDRADEC_FUNCTION index=1671 start=0x4054c08 */

void _timer_read(uint *param_1,int *param_2)

{
  uint uVar1;
  
  do {
    uVar1 = *param_1;
  } while (param_1[1] != param_1[2]);
  *param_2 = uVar1 / 1000000 + param_1[1];
  param_2[1] = uVar1 % 1000000;
  return;
}
/* GHIDRADEC_FUNCTION index=1672 start=0x4054c6c */

void _thread_read_times(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  do {
    uVar1 = *(uint *)(param_1 + 0xd8);
  } while (*(int *)(param_1 + 0xdc) != *(int *)(param_1 + 0xe0));
  *param_2 = uVar1 / 1000000 + *(int *)(param_1 + 0xdc);
  param_2[1] = uVar1 % 1000000;
  do {
    uVar1 = *(uint *)(param_1 + 0xe8);
  } while (*(int *)(param_1 + 0xec) != *(int *)(param_1 + 0xf0));
  *param_3 = uVar1 / 1000000 + *(int *)(param_1 + 0xec);
  param_3[1] = uVar1 % 1000000;
  return;
}
/* GHIDRADEC_FUNCTION index=1673 start=0x4054d22 */

int _timer_delta(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  do {
    iVar3 = param_1[1];
    iVar1 = *param_1;
  } while (iVar3 != param_1[2]);
  iVar4 = param_2[1];
  iVar2 = *param_2;
  param_2[1] = iVar3;
  *param_2 = iVar1;
  return (iVar1 + (iVar3 - iVar4) * 1000000) - iVar2;
}
/* GHIDRADEC_FUNCTION index=1674 start=0x4054fe2 */

int _zinit(int param_1,int param_2,int param_3,byte param_4,undefined4 param_5)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if (_zone_zone == 0) {
    iVar3 = _zget_space(&__zone_default_space,0x3a,0);
  }
  else {
    iVar3 = _zalloc(_zone_zone);
  }
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aZinit);
  }
  if (param_3 == 0) {
    param_3 = _page_size;
  }
  if (param_1 == 0) {
    param_1 = 4;
  }
  uVar4 = ~_page_mask & _page_mask + param_2;
  uVar1 = ~_page_mask & param_3 + _page_mask;
  if (uVar4 < uVar1) {
    uVar4 = uVar1;
  }
  *(undefined4 *)(iVar3 + 0xc) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0x10) = 0;
  *(uint *)(iVar3 + 0x14) = uVar4;
  *(uint *)(iVar3 + 0x18) = param_1 + 0xfU & 0xfffffff0;
  *(uint *)(iVar3 + 0x1c) = uVar1;
  *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0x7fffffff | (uint)param_4 << 0x1f;
  *(undefined4 *)(iVar3 + 0x24) = param_5;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 0x20) = 0;
  bVar2 = *(byte *)(iVar3 + 0x28) & 0x9f | 0x10;
  *(byte *)(iVar3 + 0x28) = bVar2;
  if ((char)bVar2 < '\0') {
    _lock_init(iVar3 + 0x2a,1);
  }
  sub_405577E(iVar3);
  *(undefined4 *)(iVar3 + 0x36) = 0;
  *_last_zone = iVar3;
  _last_zone = (int *)(iVar3 + 0x36);
  _num_zones = _num_zones + 1;
  return iVar3;
}

