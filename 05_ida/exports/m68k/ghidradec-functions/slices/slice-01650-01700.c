/* GHIDRADEC_FUNCTION index=1650 start=0x4053dae */

void _thread_swapin(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x12] & 0x300;
  if (uVar1 == 0x100) {
    param_1[0x12] = param_1[0x12] & 0xfffffcff | 0x200;
    *param_1 = &_swapin_queue;
    param_1[1] = dword_40C2B6C;
    *(undefined4 **)param_1[1] = param_1;
    dword_40C2B6C = param_1;
    _thread_wakeup_prim(&_swapin_queue,0,0);
  }
  else if (uVar1 != 0x200) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadSwapin);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1651 start=0x4053e1a */

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
/* GHIDRADEC_FUNCTION index=1652 start=0x4053e70 */

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
/* GHIDRADEC_FUNCTION index=1653 start=0x4053ede */

void _swapin_thread(void)

{
  _stack_privilege(_active_threads);
                    /* WARNING: Subroutine does not return */
  _swapin_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1654 start=0x4053ef8 */

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
/* GHIDRADEC_FUNCTION index=1655 start=0x4054124 */

sqword _calloutDeadlineFromInterval(undefined4 param_1,undefined4 param_2)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  return sVar1 + CONCAT44(param_1,param_2);
}
/* GHIDRADEC_FUNCTION index=1656 start=0x405414e */

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
/* GHIDRADEC_FUNCTION index=1657 start=0x40541fa */

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
/* GHIDRADEC_FUNCTION index=1658 start=0x40542da */

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
/* GHIDRADEC_FUNCTION index=1659 start=0x40543c4 */

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
/* GHIDRADEC_FUNCTION index=1660 start=0x405440c */

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
/* GHIDRADEC_FUNCTION index=1661 start=0x405444e */

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
/* GHIDRADEC_FUNCTION index=1662 start=0x405448e */

void _calloutEntryFree(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aCalloutentryfr);
  }
  _kfree(param_1,0x20);
  return;
}
/* GHIDRADEC_FUNCTION index=1663 start=0x40544d6 */

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
/* GHIDRADEC_FUNCTION index=1664 start=0x4054536 */

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
/* GHIDRADEC_FUNCTION index=1665 start=0x4054596 */

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
/* GHIDRADEC_FUNCTION index=1666 start=0x4054632 */

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
/* GHIDRADEC_FUNCTION index=1667 start=0x40546ce */

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
/* GHIDRADEC_FUNCTION index=1668 start=0x4054aaa */

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
/* GHIDRADEC_FUNCTION index=1669 start=0x4054b72 */

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
/* GHIDRADEC_FUNCTION index=1670 start=0x4054ba6 */

void _timer_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1671 start=0x4054bc0 */

void _timer_normalize(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  param_1[2] = uVar1 / 1000000 + param_1[2];
  *param_1 = *param_1 % 1000000;
  param_1[1] = uVar1 / 1000000 + param_1[1];
  return;
}
/* GHIDRADEC_FUNCTION index=1672 start=0x4054c08 */

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
/* GHIDRADEC_FUNCTION index=1673 start=0x4054c6c */

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
/* GHIDRADEC_FUNCTION index=1674 start=0x4054d22 */

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
/* GHIDRADEC_FUNCTION index=1675 start=0x4054fe2 */

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
/* GHIDRADEC_FUNCTION index=1676 start=0x40550f2 */

int _zcram(int *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  char in_XF;
  bool bVar5;
  
  if (param_2 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aZcramMemoryAtZ);
  }
  uVar1 = param_1[6];
  bVar5 = *(char *)(param_1 + 10) < '\0';
  if (bVar5) {
    _lock_write((int)param_1 + 0x2a);
  }
  else {
    *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | bVar5 << 3 |
                                       (*(char *)(param_1 + 10) == '\0') << 2);
  }
  do {
    if (param_3 < uVar1) {
      if (*(char *)(param_1 + 10) < '\0') {
        iVar3 = _lock_done((int)param_1 + 0x2a);
      }
      else {
        iVar3 = *param_1;
      }
      return iVar3;
    }
    puVar2 = (uint *)param_1[2];
    if ((puVar2 == (uint *)0x0) || (param_2 <= puVar2)) {
      puVar2 = (uint *)(param_1 + 3);
    }
    do {
      puVar4 = puVar2;
      puVar2 = (uint *)*puVar4;
      if (puVar2 == (uint *)0x0) break;
    } while (puVar2 < param_2);
    *param_2 = (uint)puVar2;
    *puVar4 = (uint)param_2;
    param_1[2] = (int)param_2;
    param_3 = param_3 - uVar1;
    param_2 = (uint *)(uVar1 + (int)param_2);
    param_1[4] = uVar1 + param_1[4];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1677 start=0x405518c */

uint * _zone_free_space_add(undefined8 *param_1,int param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  if (param_1 == (undefined8 *)0x0) {
    param_1 = &__zone_default_space;
  }
  puVar2 = (uint *)(param_1 + 1);
  do {
    puVar5 = puVar2;
    puVar2 = (uint *)*puVar5;
    if (puVar2 == (uint *)0x0) goto loc_40551D8;
  } while ((puVar2 < param_3) && (param_3 != (uint *)(puVar2[1] + (int)puVar2)));
  if ((puVar2 == (uint *)0x0) || ((uint *)(puVar2[1] + (int)puVar2) < param_3)) {
loc_40551D8:
    if (0xf < (uint)(param_4 - param_2)) {
      if (puVar2 != (uint *)0x0) {
        puVar5 = puVar2;
      }
      puVar2 = (uint *)((int)param_3 + param_2);
      puVar2[1] = param_4 - param_2;
      uVar3 = *puVar5;
      *puVar2 = uVar3;
      if (uVar3 != 0) {
        *(uint **)(uVar3 + 8) = puVar2;
      }
      puVar2[2] = (uint)puVar5;
      *puVar5 = (uint)puVar2;
      *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + 1;
      uVar3 = puVar2[1] >> (*(uint *)(param_1 + 2) & 0x3f);
      if ((int)*(uint *)(param_1 + 3) < (int)uVar3) {
        uVar3 = *(uint *)(param_1 + 3);
      }
      puVar4 = (undefined4 *)(uVar3 * 0x10 + *(int *)((int)param_1 + 0x14) + -0x10);
      puVar5 = (uint *)*puVar4;
      if ((puVar5 == (uint *)0x0) || (puVar2 < puVar5)) {
        *puVar4 = puVar2;
      }
    }
  }
  else if (param_3 == (uint *)(puVar2[1] + (int)puVar2)) {
    sub_4054D62(param_1,puVar2);
    puVar1 = (uint *)((int)puVar2 + param_2);
    puVar1[1] = (param_4 + puVar2[1]) - param_2;
    uVar3 = *puVar2;
    *puVar1 = uVar3;
    if (uVar3 != 0) {
      *(uint **)(uVar3 + 8) = puVar1;
    }
    puVar1[2] = (uint)puVar5;
    *puVar5 = (uint)puVar1;
    uVar3 = puVar1[1] >> (*(uint *)(param_1 + 2) & 0x3f);
    if ((int)*(uint *)(param_1 + 3) < (int)uVar3) {
      uVar3 = *(uint *)(param_1 + 3);
    }
    puVar4 = (undefined4 *)(uVar3 * 0x10 + *(int *)((int)param_1 + 0x14) + -0x10);
    puVar5 = (uint *)*puVar4;
    param_3 = puVar2;
    if ((puVar5 == (uint *)0x0) || (puVar1 < puVar5)) {
      *puVar4 = puVar1;
    }
  }
  return param_3;
}
/* GHIDRADEC_FUNCTION index=1678 start=0x4055298 */

void _zone_collect(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  
  iVar3 = *(int *)(param_1 + 0x18);
  puVar4 = *(undefined8 **)(param_1 + 0x32);
  if ((puVar4 != (undefined8 *)0x0) && (puVar4 != &__zone_default_space)) {
    piVar11 = (int *)(puVar4 + 1);
    piVar6 = *(int **)(param_1 + 0xc);
    while (piVar6 != (int *)0x0) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - iVar3;
      piVar1 = (int *)*piVar6;
      piVar10 = (int *)*piVar11;
      if (piVar10 == (int *)0x0) {
loc_40552FC:
        piVar6[1] = iVar3;
        *piVar6 = (int)piVar10;
        if (piVar10 != (int *)0x0) {
          piVar10[2] = (int)piVar6;
        }
        piVar6[2] = (int)piVar11;
        *piVar11 = (int)piVar6;
        *(int *)((int)puVar4 + 0xc) = *(int *)((int)puVar4 + 0xc) + 1;
        uVar7 = (uint)piVar6[1] >> (*(uint *)(puVar4 + 2) & 0x3f);
        if ((int)*(uint *)(puVar4 + 3) < (int)uVar7) {
          uVar7 = *(uint *)(puVar4 + 3);
        }
        puVar8 = (undefined4 *)(uVar7 * 0x10 + *(int *)((int)puVar4 + 0x14) + -0x10);
        piVar10 = (int *)*puVar8;
        if ((piVar10 == (int *)0x0) || (piVar6 < piVar10)) {
          *puVar8 = piVar6;
        }
      }
      else {
        do {
          piVar9 = piVar10;
          piVar10 = piVar9;
          if (piVar6 <= (int *)(piVar9[1] + (int)piVar9)) break;
          piVar10 = (int *)*piVar9;
          piVar11 = piVar9;
        } while (piVar10 != (int *)0x0);
        if ((piVar10 == (int *)0x0) || ((int *)((int)piVar6 + iVar3) < piVar10)) goto loc_40552FC;
        if (piVar10 == (int *)((int)piVar6 + iVar3)) {
          iVar5 = piVar10[1];
          piVar6[1] = iVar3 + iVar5;
          iVar2 = *piVar10;
          *piVar6 = iVar2;
          if (iVar2 != 0) {
            *(int **)(iVar2 + 8) = piVar6;
          }
          piVar6[2] = (int)piVar11;
          *piVar11 = (int)piVar6;
          sub_4054DD6(puVar4,piVar6,iVar5,piVar10);
        }
        else {
          iVar2 = piVar10[1];
          if (piVar6 == (int *)((int)piVar10 + iVar2)) {
            piVar10[1] = iVar3 + iVar2;
            iVar5 = (int)piVar10 + iVar3 + iVar2;
            if (iVar5 == *piVar10) {
              sub_4054D62(puVar4,iVar5);
              piVar10[1] = *(int *)(*piVar10 + 4) + piVar10[1];
              iVar5 = *(int *)*piVar10;
              *piVar10 = iVar5;
              if (iVar5 != 0) {
                *(int **)(iVar5 + 8) = piVar10;
              }
              *(int *)((int)puVar4 + 0xc) = *(int *)((int)puVar4 + 0xc) + -1;
            }
            sub_4054E7E(puVar4,piVar10,iVar2);
          }
        }
      }
      *(int **)(param_1 + 0xc) = piVar1;
      piVar6 = piVar1;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1679 start=0x40553e2 */

void _zone_free_space_reclaim(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  
  piVar7 = (int *)0x0;
  piVar10 = &_zone_free_space;
  iVar8 = 1;
  if (1 < _zone_free_space_count) {
    do {
      piVar10 = piVar10 + 1;
      piVar3 = (int *)(*piVar10 + 8);
      while (piVar11 = piVar3, piVar3 = (int *)*piVar11, piVar3 != (int *)0x0) {
        if (_page_size <= (uint)piVar3[1]) {
          piVar4 = (int *)(~_page_mask & _page_mask + (int)piVar3);
          piVar5 = (int *)(~_page_mask & piVar3[1] + (int)piVar3);
          if (((piVar4 < piVar5) && (_zone_min <= piVar4)) && (piVar5 <= _zone_max)) {
            sub_4054D62(*piVar10,piVar3);
            if (piVar5 == (int *)(piVar3[1] + (int)piVar3)) {
              if (piVar4 == piVar3) {
                iVar1 = *piVar3;
                *piVar11 = iVar1;
                if (iVar1 != 0) {
                  *(int **)(*piVar3 + 8) = piVar11;
                }
                *(int *)(*piVar10 + 0xc) = *(int *)(*piVar10 + 0xc) + -1;
              }
              else {
                piVar3[1] = (int)piVar4 - (int)piVar3;
                iVar1 = *piVar10;
                uVar6 = (uint)((int)piVar4 - (int)piVar3) >> (*(uint *)(iVar1 + 0x10) & 0x3f);
                if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar6) {
                  uVar6 = *(uint *)(iVar1 + 0x18);
                }
                puVar9 = (undefined4 *)(uVar6 * 0x10 + *(int *)(iVar1 + 0x14) + -0x10);
                piVar2 = (int *)*puVar9;
                if ((piVar2 == (int *)0x0) || (piVar3 < piVar2)) {
                  *puVar9 = piVar3;
                }
              }
            }
            else {
              piVar5[1] = (piVar3[1] + (int)piVar3) - (int)piVar5;
              iVar1 = *piVar3;
              *piVar5 = iVar1;
              if (iVar1 != 0) {
                *(int **)(iVar1 + 8) = piVar5;
              }
              if (piVar4 == piVar3) {
                *piVar11 = (int)piVar5;
                piVar5[2] = (int)piVar11;
              }
              else {
                piVar3[1] = (int)piVar4 - (int)piVar3;
                *piVar3 = (int)piVar5;
                piVar5[2] = (int)piVar3;
                *(int *)(*piVar10 + 0xc) = *(int *)(*piVar10 + 0xc) + 1;
                iVar1 = *piVar10;
                uVar6 = (uint)piVar3[1] >> (*(uint *)(iVar1 + 0x10) & 0x3f);
                if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar6) {
                  uVar6 = *(uint *)(iVar1 + 0x18);
                }
                puVar9 = (undefined4 *)(uVar6 * 0x10 + *(int *)(iVar1 + 0x14) + -0x10);
                piVar2 = (int *)*puVar9;
                if ((piVar2 == (int *)0x0) || (piVar3 < piVar2)) {
                  *puVar9 = piVar3;
                }
              }
              iVar1 = *piVar10;
              uVar6 = (uint)piVar5[1] >> (*(uint *)(iVar1 + 0x10) & 0x3f);
              if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar6) {
                uVar6 = *(uint *)(iVar1 + 0x18);
              }
              puVar9 = (undefined4 *)(uVar6 * 0x10 + *(int *)(iVar1 + 0x14) + -0x10);
              piVar3 = (int *)*puVar9;
              if ((piVar3 == (int *)0x0) || (piVar5 < piVar3)) {
                *puVar9 = piVar5;
              }
            }
            piVar4[1] = (int)piVar5 - (int)piVar4;
            *piVar4 = (int)piVar7;
            piVar7 = piVar4;
            piVar3 = piVar11;
          }
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < _zone_free_space_count);
  }
  while (piVar7 != (int *)0x0) {
    piVar10 = (int *)*piVar7;
    _kmem_free(_zone_map,piVar7,piVar7[1]);
    piVar7 = piVar10;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1680 start=0x4055582 */

uint * _zget_space(undefined8 *param_1,uint param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint unaff_D3;
  uint *puVar6;
  int iStack_8;
  
  iStack_8 = 0;
  if (param_1 == (undefined8 *)0x0) {
    param_1 = &__zone_default_space;
  }
  if (param_2 < 0x11) {
    uVar4 = 0x10;
  }
  else {
    uVar4 = param_2 + 0xf & 0xfffffff0;
  }
  do {
    puVar3 = (uint *)sub_4054F1C(param_1,uVar4);
    if (puVar3 != (uint *)0x0) {
      puVar2 = (uint *)puVar3[2];
      if (puVar3[1] - uVar4 < 0x10) {
        uVar4 = *puVar3;
        *puVar2 = uVar4;
        if (uVar4 != 0) {
          *(uint **)(*puVar3 + 8) = puVar2;
        }
        *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + -1;
      }
      else {
        puVar1 = (uint *)((int)puVar3 + uVar4);
        puVar1[1] = puVar3[1] - uVar4;
        uVar4 = *puVar3;
        *puVar1 = uVar4;
        if (uVar4 != 0) {
          *(uint **)(uVar4 + 8) = puVar1;
        }
        puVar1[2] = (uint)puVar2;
        *puVar2 = (uint)puVar1;
        uVar4 = puVar1[1] >> (*(uint *)(param_1 + 2) & 0x3f);
        if ((int)*(uint *)(param_1 + 3) < (int)uVar4) {
          uVar4 = *(uint *)(param_1 + 3);
        }
        puVar6 = (uint *)(uVar4 * 0x10 + *(int *)((int)param_1 + 0x14) + -0x10);
        puVar2 = (uint *)*puVar6;
        if ((puVar2 == (uint *)0x0) || (puVar1 < puVar2)) {
          *puVar6 = (uint)puVar1;
        }
      }
loc_40556AE:
      if (iStack_8 == 0) {
        return puVar3;
      }
      _kmem_free(_zone_map,iStack_8,unaff_D3);
      return puVar3;
    }
    if (iStack_8 != 0) {
      puVar3 = (uint *)_zone_free_space_add(param_1,uVar4,iStack_8,unaff_D3);
      iStack_8 = 0;
      goto loc_40556AE;
    }
    unaff_D3 = ~_page_mask & _page_mask + uVar4;
    if (unaff_D3 <= _zdata_size) {
      _zdata_size = _zdata_size - unaff_D3;
      puVar3 = (uint *)_zone_free_space_add(param_1,uVar4,_zdata + _zdata_size,unaff_D3);
      goto loc_40556AE;
    }
    iVar5 = _kmem_alloc_zone(_zone_map,&iStack_8,unaff_D3,param_3);
    if (iVar5 != 0) {
      return (uint *)0x0;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1681 start=0x40557d8 */

void _zone_bootstrap(void)

{
  _first_zone = 0;
  _last_zone = &_first_zone;
  _num_zones = 0;
  unk_40C2BA8 = __zone_default_space_hint;
  dword_40C2BAC = 1;
  _zone_free_space = &__zone_default_space;
  _zone_free_space_count = 1;
  _zone_zone = 0;
  _zone_zone = _zinit(0x3a,0x1d00,0x3a,0,&aZones);
  sub_40556D0(0x10,0x60);
  sub_40556D0(0x80,0x300);
  sub_40556D0(0x400,_page_size);
  return;
}
/* GHIDRADEC_FUNCTION index=1682 start=0x4055870 */

void _zone_init(void)

{
  _zone_map = _kmem_suballoc(_kernel_map,&_zone_min,&_zone_max,_zone_map_size,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1683 start=0x4055b56 */

void _zalloc(undefined4 param_1)

{
  sub_405589E(param_1,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1684 start=0x4055b6c */

void _zalloc_noblock(undefined4 param_1)

{
  sub_405589E(param_1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1685 start=0x4055b80 */

int * _zget(int *param_1)

{
  int *piVar1;
  char in_XF;
  bool bVar2;
  
  if (param_1 != (int *)0x0) {
    bVar2 = *(char *)(param_1 + 10) < '\0';
    if (bVar2) {
      _lock_write((int)param_1 + 0x2a);
    }
    else {
      *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | bVar2 << 3 |
                                         (*(char *)(param_1 + 10) == '\0') << 2);
    }
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      param_1[1] = param_1[1] + 1;
      param_1[3] = *piVar1;
      if (piVar1 == (int *)param_1[2]) {
        param_1[2] = 0;
      }
    }
    if (*(char *)(param_1 + 10) < '\0') {
      _lock_done((int)param_1 + 0x2a);
    }
    return piVar1;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aZallocNullZone);
}
/* GHIDRADEC_FUNCTION index=1686 start=0x4055bfc */

int _zfree(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  char in_XF;
  bool bVar4;
  
  bVar4 = *(char *)(param_1 + 10) < '\0';
  if (bVar4) {
    _lock_write((int)param_1 + 0x2a);
  }
  else {
    *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | bVar4 << 3 |
                                       (*(char *)(param_1 + 10) == '\0') << 2);
  }
  if (_zone_check != 0) {
    for (piVar1 = (int *)param_1[3]; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (param_2 == piVar1) {
                    /* WARNING: Subroutine does not return */
        _panic(&aZfree);
      }
    }
  }
  piVar1 = (int *)param_1[2];
  if ((piVar1 == (int *)0x0) || (param_2 <= piVar1)) {
    piVar1 = param_1 + 3;
  }
  do {
    piVar3 = piVar1;
    piVar1 = (int *)*piVar3;
    if (piVar1 == (int *)0x0) break;
  } while (piVar1 < param_2);
  *param_2 = (int)piVar1;
  *piVar3 = (int)param_2;
  param_1[2] = (int)param_2;
  param_1[1] = param_1[1] + -1;
  if (*(char *)(param_1 + 10) < '\0') {
    iVar2 = _lock_done((int)param_1 + 0x2a);
  }
  else {
    iVar2 = *param_1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1687 start=0x4055c9a */

void _zcollectable(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1688 start=0x4055ca2 */

void _zchange(int param_1,char param_2,byte param_3,byte param_4,int param_5)

{
  *(byte *)(param_1 + 0x28) =
       *(byte *)(param_1 + 0x28) & 0x1f | param_2 << 7 | (param_3 & 1) << 6 | (param_4 & 1) << 5;
  if (param_5 == 0) {
    *(undefined8 **)(param_1 + 0x32) = &__zone_default_space;
  }
  if (*(char *)(param_1 + 0x28) < '\0') {
    _lock_init(param_1 + 0x2a,1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1689 start=0x4055cfc */

void _zone_gc(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  
  uVar1 = _num_zones;
  uVar2 = 0;
  bVar5 = false;
  piVar3 = _first_zone;
  if (0 < (int)_num_zones) {
    do {
      bVar4 = *(char *)(piVar3 + 10) < '\0';
      if (bVar4) {
        _lock_write((int)piVar3 + 0x2a);
      }
      else {
        *piVar3 = (int)(sword)(word)(byte)(bVar5 << 4 | bVar4 << 3 |
                                          (*(char *)(piVar3 + 10) == '\0') << 2);
      }
      if (*(char *)(piVar3 + 10) < '\0') {
loc_4055D58:
        _lock_done((int)piVar3 + 0x2a);
      }
      else {
        if ((*(undefined8 **)((int)piVar3 + 0x32) != (undefined8 *)0x0) &&
           (*(undefined8 **)((int)piVar3 + 0x32) != &__zone_default_space)) {
          _zone_collect(piVar3);
        }
        if (*(char *)(piVar3 + 10) < '\0') goto loc_4055D58;
      }
      piVar3 = *(int **)((int)piVar3 + 0x36);
      uVar2 = uVar2 + 1;
      bVar5 = uVar1 < uVar2;
    } while ((int)uVar2 < (int)uVar1);
  }
  _zone_free_space_reclaim();
  return;
}
/* GHIDRADEC_FUNCTION index=1690 start=0x4055d86 */

void _consider_zone_gc(void)

{
  if (_zone_gc_max_rate == 0) {
    _zone_gc_max_rate = _hz;
  }
  if ((_zone_gc_allowed != 0) && (_zone_gc_max_rate + _zone_gc_last_tick < _sched_tick)) {
    _zone_gc_last_tick = _sched_tick;
    _zone_gc();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1691 start=0x4055dca */

void _zone_reclaim(void)

{
  _zone_free_space_reclaim();
  return;
}
/* GHIDRADEC_FUNCTION index=1692 start=0x4055dd8 */

int _host_zone_info(int param_1,int *param_2,uint *param_3,int *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  bool bVar10;
  bool bVar11;
  undefined4 *puStack_4a;
  undefined auStack_46 [4];
  undefined4 uStack_42;
  undefined4 uStack_36;
  undefined4 uStack_32;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  undefined4 uStack_22;
  uint uStack_1e;
  undefined8 *puStack_14;
  undefined4 *puStack_c;
  int iStack_8;
  
  uVar1 = _num_zones;
  piVar9 = _first_zone;
  uVar6 = 0;
  uVar7 = 0;
  if (param_1 == 0) {
    iVar2 = 0x16;
  }
  else {
    if (*param_3 < _num_zones) {
      uVar6 = ~_page_mask & _page_mask + _num_zones * 0x50;
      iVar3 = _kmem_alloc_pageable(_ipc_kernel_map,&iStack_8,uVar6);
      iVar2 = iStack_8;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    else {
      iVar2 = *param_2;
    }
    if (*param_5 < uVar1) {
      uVar7 = ~_page_mask & _page_mask + uVar1 * 0x24;
      iVar3 = _kmem_alloc_pageable(_ipc_kernel_map,&puStack_c,uVar7);
      if (iVar3 != 0) {
        if (iVar2 == *param_2) {
          return iVar3;
        }
        _kmem_free(_ipc_kernel_map,iStack_8,uVar6);
        return iVar3;
      }
      puStack_4a = puStack_c;
    }
    else {
      puStack_4a = (undefined4 *)*param_4;
    }
    uVar5 = 0;
    bVar11 = false;
    puVar8 = puStack_4a;
    iVar3 = iVar2;
    if (uVar1 != 0) {
      do {
        bVar10 = *(char *)(piVar9 + 10) < '\0';
        if (bVar10) {
          _lock_write((int)piVar9 + 0x2a);
        }
        else {
          *piVar9 = (int)(sword)(word)(byte)(bVar11 << 4 | bVar10 << 3 |
                                            (*(char *)(piVar9 + 10) == '\0') << 2);
        }
        _bcopy(piVar9,auStack_46,0x3a);
        if (*(char *)(piVar9 + 10) < '\0') {
          _lock_done((int)piVar9 + 0x2a);
        }
        piVar9 = *(int **)((int)piVar9 + 0x36);
        _strncpy(iVar3,uStack_22,0x50);
        *puVar8 = uStack_42;
        puVar8[1] = uStack_36;
        puVar8[2] = uStack_32;
        puVar8[3] = uStack_2e;
        puVar8[4] = uStack_2a;
        puVar8[5] = uStack_1e >> 0x1f;
        puVar8[6] = (uStack_1e & 0x7fffffff) >> 0x1e;
        puVar8[7] = (uStack_1e & 0x3fffffff) >> 0x1d;
        uVar4 = 0;
        if ((puStack_14 != (undefined8 *)0x0) && (puStack_14 != &__zone_default_space)) {
          uVar4 = 1;
        }
        puVar8[8] = uVar4;
        uVar5 = uVar5 + 1;
        bVar11 = uVar1 < uVar5;
        puVar8 = puVar8 + 9;
        iVar3 = iVar3 + 0x50;
      } while (uVar5 < uVar1);
    }
    if (iVar2 != *param_2) {
      if (uVar6 != uVar1 * 0x50) {
        _bzero(iStack_8 + uVar1 * 0x50,uVar6 + uVar1 * -0x50);
      }
      _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar6,1,&iStack_8);
      *param_2 = iStack_8;
    }
    *param_3 = uVar1;
    if (puStack_4a != (undefined4 *)*param_4) {
      if (uVar7 != uVar1 * 0x24) {
        _bzero(puStack_c + uVar1 * 9,uVar7 + uVar1 * -0x24);
      }
      _vm_move(_ipc_kernel_map,puStack_c,_ipc_soft_map,uVar7,1,&puStack_c);
      *param_4 = (int)puStack_c;
    }
    *param_5 = uVar1;
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1693 start=0x4056040 */

undefined4
_host_zone_free_space_info
          (int param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  
  if (param_1 == 0) {
    return 0x16;
  }
  uVar11 = 0;
  uVar5 = 0;
  do {
    uVar7 = 0;
    uVar4 = 0;
    uVar6 = 0;
    uVar10 = 0;
    if (_zone_free_space_count != 0) {
      piVar3 = &_zone_free_space;
      do {
        uVar6 = *(int *)(*piVar3 + 0xc) + uVar6;
        uVar10 = uVar10 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar10 < _zone_free_space_count);
    }
    if (uVar10 < *param_3) {
      uVar4 = ~_page_mask & _page_mask + uVar10 * 0xc;
    }
    if (*param_5 < uVar6) {
      uVar7 = ~_page_mask & _page_mask + uVar6 * 8;
    }
    if ((uVar4 <= uVar11) && (uVar7 <= uVar5)) {
      puVar9 = puStack_8;
      if (uVar11 == 0) {
        puVar9 = (undefined4 *)*param_2;
      }
      puVar8 = puStack_c;
      if (uVar5 == 0) {
        puVar8 = (undefined4 *)*param_4;
      }
      uVar4 = 0;
      if (uVar10 != 0) {
        piVar3 = &_zone_free_space;
        do {
          puVar1 = (undefined4 *)*piVar3;
          *puVar9 = *puVar1;
          puVar9[1] = puVar1[1];
          puVar9[2] = puVar1[3];
          puVar9 = puVar9 + 3;
          for (puVar1 = (undefined4 *)puVar1[2]; puVar1 != (undefined4 *)0x0;
              puVar1 = (undefined4 *)*puVar1) {
            *puVar8 = puVar1;
            puVar8[1] = puVar1[1];
            puVar8 = puVar8 + 2;
          }
          piVar3 = piVar3 + 1;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar10);
      }
      if (uVar10 == 0) {
        *param_2 = 0;
        if (uVar11 != 0) {
          _kmem_free(_ipc_kernel_map,puStack_8,uVar11);
        }
      }
      else if (uVar11 != 0) {
        uVar4 = ~_page_mask & _page_mask + uVar10 * 0xc;
        _vm_map_pageable(_ipc_kernel_map,puStack_8,(int)puStack_8 + uVar4,1);
        _vm_move(_ipc_kernel_map,puStack_8,_ipc_soft_map,uVar4,1,&uStack_10);
        if (uVar11 != uVar4) {
          _kmem_free(_ipc_kernel_map,(int)puStack_8 + uVar4,uVar11 - uVar4);
        }
        *param_2 = uStack_10;
      }
      *param_3 = uVar10;
      if (uVar6 == 0) {
        *param_4 = 0;
        if (uVar5 != 0) {
          _kmem_free(_ipc_kernel_map,puStack_c,uVar5);
        }
      }
      else if (uVar5 != 0) {
        uVar11 = ~_page_mask & _page_mask + uVar6 * 8;
        _vm_map_pageable(_ipc_kernel_map,puStack_c,(int)puStack_c + uVar11,1);
        _vm_move(_ipc_kernel_map,puStack_c,_ipc_soft_map,uVar11,1,&uStack_14);
        if (uVar5 != uVar11) {
          _kmem_free(_ipc_kernel_map,(int)puStack_c + uVar11,uVar5 - uVar11);
        }
        *param_4 = uStack_14;
      }
      *param_5 = uVar6;
      return 0;
    }
    if (uVar11 < uVar4) {
      if (uVar11 != 0) {
        _kmem_free(_ipc_kernel_map,puStack_8,uVar11);
      }
      iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&puStack_8,uVar4);
      uVar11 = uVar5;
      puVar9 = puStack_c;
      if (iVar2 != 0) {
joined_r0x04056108:
        if (uVar11 != 0) {
          _kmem_free(_ipc_kernel_map,puVar9,uVar11);
        }
        return 6;
      }
      _vm_map_pageable(_ipc_kernel_map,puStack_8,uVar4 + (int)puStack_8,0);
      uVar11 = uVar4;
    }
    if (uVar5 < uVar7) {
      if (uVar5 != 0) {
        _kmem_free(_ipc_kernel_map,puStack_c,uVar5);
      }
      iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&puStack_c,uVar7);
      puVar9 = puStack_8;
      if (iVar2 != 0) goto joined_r0x04056108;
      _vm_map_pageable(_ipc_kernel_map,puStack_c,(int)puStack_c + uVar7,0);
      uVar5 = uVar7;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1694 start=0x4056360 */

void _kern_server_main(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  word wVar4;
  undefined4 uVar5;
  int iVar6;
  sword sVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  int iStack_44;
  int *apiStack_40 [15];
  
  iStack_44 = _kalloc(0x4d4);
  _bcopy(_kern_serv_proto,apiStack_40,0x3c);
  apiStack_40[0] = &iStack_44;
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x48) = 1;
  }
  _bzero(iStack_44,0x4d4);
  *(undefined4 *)(iStack_44 + 0x4c8) = 0xffffffff;
  uVar5 = _task_self();
  *(undefined4 *)(iStack_44 + 8) = uVar5;
  *(int *)(iStack_44 + 0xc) = _active_threads;
  iVar9 = iStack_44 + 0x34;
  *(int *)(iStack_44 + 0x38) = iVar9;
  *(int *)iVar9 = iVar9;
  piVar3 = (int *)(iStack_44 + 0x3c);
  *(int **)(iStack_44 + 0x40) = piVar3;
  *piVar3 = (int)piVar3;
  iVar9 = iStack_44 + 0x4c0;
  *(int *)(iStack_44 + 0x4c4) = iVar9;
  *(int *)iVar9 = iVar9;
  iVar6 = 0x13;
  iVar8 = 0x17c;
  iVar9 = iStack_44 + 0x130;
  do {
    piVar1 = *(int **)(iStack_44 + 0x40);
    if (piVar1 == piVar3) {
      *piVar3 = iStack_44 + iVar8;
    }
    else {
      piVar1[2] = iStack_44 + iVar8;
    }
    *(int **)(iVar9 + 0x58) = piVar1;
    *(int **)(iVar9 + 0x54) = piVar3;
    *(int *)(iStack_44 + 0x40) = iStack_44 + iVar8;
    iVar8 = iVar8 + -0x10;
    iVar9 = iVar9 + -0x10;
    wVar4 = (word)((uint)iVar6 >> 0x10);
    sVar7 = (sword)iVar6 + -1;
    iVar6 = CONCAT22(wVar4,sVar7);
  } while ((sVar7 != -1) || (iVar6 = (uint)wVar4 * 0x10000 + -1, wVar4 != 0));
  uVar5 = _thread_self(2,&iStack_48);
  iVar9 = _thread_get_special_port_EXTERNAL(uVar5);
  if ((iVar9 != 0) || (iStack_48 == 0)) {
    _printf(aKServerCanTFin);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  *(int *)(iStack_44 + 0x14) = iStack_48;
  uVar5 = _task_self(&uStack_4c);
  iVar9 = _port_allocate_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTAll);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  uVar5 = _thread_self(2,uStack_4c);
  iVar9 = _thread_set_special_port_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTSet);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  uVar5 = _task_self(&uStack_50);
  iVar9 = _port_set_allocate_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTAll_0);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  *(undefined4 *)(iStack_44 + 0x20) = uStack_50;
  uVar5 = _task_self(uStack_50,iStack_48);
  iVar9 = _port_set_add_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTAdd);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  iVar9 = _port_allocate_EXTERNAL(*(undefined4 *)(iStack_44 + 8),iStack_44 + 0x1c);
  if (iVar9 == 0) {
    _port_set_add_EXTERNAL
              (*(undefined4 *)(iStack_44 + 8),*(undefined4 *)(iStack_44 + 0x20),
               *(undefined4 *)(iStack_44 + 0x1c));
  }
  else {
    _kern_serv_panic(*(undefined4 *)(iStack_44 + 0x10),aKServerCanTGet);
  }
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    uVar5 = _task_self(2,*(undefined4 *)(iStack_44 + 0x1c));
    _task_set_special_port_EXTERNAL(uVar5);
  }
  _kern_serv_notify(&iStack_44,*(undefined4 *)(iStack_44 + 0x1c),*(undefined4 *)(iStack_44 + 0x10));
  uVar5 = _kern_serv_kernel_task_port();
  *(undefined4 *)(iStack_44 + 0x4cc) = uVar5;
  iVar9 = _kalloc(0x30);
  *(int *)(iStack_44 + 0x44) = iVar9;
  *(undefined4 *)(iStack_44 + 0x48) = 0x30;
loc_40566B0:
  while ((int *)(iStack_44 + 0x34) != *(int **)(iStack_44 + 0x34)) {
    puVar10 = *(undefined4 **)(iStack_44 + 0x34);
    iVar6 = puVar10[2];
    if (iVar6 == iStack_44 + 0x34) {
      *(int *)(iStack_44 + 0x38) = iVar6;
    }
    else {
      *(int *)(iVar6 + 0xc) = iStack_44 + 0x34;
    }
    *(int *)(iStack_44 + 0x34) = iVar6;
    (*(code *)*puVar10)(puVar10[1]);
    puVar2 = *(undefined4 **)(iStack_44 + 0x40);
    if (puVar2 == (undefined4 *)(iStack_44 + 0x3c)) {
      *puVar2 = puVar10;
    }
    else {
      puVar2[2] = puVar10;
    }
    puVar10[3] = puVar2;
    puVar10[2] = iStack_44 + 0x3c;
    *(undefined4 **)(iStack_44 + 0x40) = puVar10;
  }
  while( true ) {
    *(undefined4 *)(iVar9 + 0xc) = uStack_50;
    *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iStack_44 + 0x48);
    iVar6 = _msg_receive(iVar9,0x1500,1000);
    if (iVar6 != -0xcc) break;
    uVar5 = *(undefined4 *)(*(int *)(iStack_44 + 0x44) + 4);
    _kfree(*(int *)(iStack_44 + 0x44),*(undefined4 *)(iStack_44 + 0x48));
    *(undefined4 *)(iStack_44 + 0x48) = uVar5;
    iVar9 = _kalloc(uVar5);
    *(int *)(iStack_44 + 0x44) = iVar9;
  }
  if (-0xcc < iVar6) goto loc_40566F6;
  if (iVar6 != -0xcf) goto loc_4056740;
  goto loc_4056756;
loc_40566F6:
  if (iVar6 != -0xcb) {
    if (iVar6 != 0) {
loc_4056740:
      _kern_serv_panic(*(undefined4 *)(iStack_44 + 0x10),aKernServerMain);
    }
loc_4056756:
    if (*(int *)(iVar9 + 0xc) != *(int *)(iStack_44 + 0x1c)) {
      if (*(int *)(iVar9 + 0x14) - 0x40U < 0xd) {
        for (puVar10 = *(undefined4 **)(iStack_44 + 0x4c0);
            puVar10 != (undefined4 *)(iStack_44 + 0x4c0); puVar10 = (undefined4 *)puVar10[2]) {
          if (puVar10[1] == *(int *)(iVar9 + 0x1c)) {
            *(undefined4 *)(iVar9 + 0x10) = *puVar10;
            _msg_send(iVar9,0,0);
            iVar6 = puVar10[2];
            piVar3 = (int *)puVar10[3];
            if (iVar6 == iStack_44 + 0x4c0) {
              *(int **)(iStack_44 + 0x4c4) = piVar3;
            }
            else {
              *(int **)(iVar6 + 0xc) = piVar3;
            }
            if (piVar3 == (int *)(iStack_44 + 0x4c0)) {
              *piVar3 = iVar6;
            }
            else {
              piVar3[2] = iVar6;
            }
            _kfree(puVar10,0x10);
          }
        }
      }
      *(undefined4 *)(iStack_44 + 4) = *(undefined4 *)(iVar9 + 0xc);
      iVar6 = sub_405691C(iVar9,iStack_44);
      if ((iVar6 == -0x12f) && (*(int *)(iVar9 + 0xc) == iStack_48)) {
        _kern_serv_handler(iVar9,apiStack_40);
      }
      goto loc_40566B0;
    }
    if (*(int *)(iVar9 + 0x14) == 0x41) {
      if (*(code **)(iStack_44 + 0x4b8) == (code *)0x0) {
        if (*(code **)(iStack_44 + 0x4bc) != (code *)0x0) {
          (**(code **)(iStack_44 + 0x4bc))(*(undefined4 *)(iVar9 + 0x1c),0x41);
        }
      }
      else {
        iVar6 = (**(code **)(iStack_44 + 0x4b8))(*(undefined4 *)(iVar9 + 0x1c));
        if (iVar6 != 0) goto loc_40566B0;
      }
      _kern_serv_port_gone(&iStack_44,*(undefined4 *)(iVar9 + 0x1c));
      goto loc_40566B0;
    }
    if (*(code **)(iStack_44 + 0x4bc) != (code *)0x0) {
      (**(code **)(iStack_44 + 0x4bc))(*(undefined4 *)(iVar9 + 0x1c),*(int *)(iVar9 + 0x14));
    }
  }
  goto loc_40566B0;
}
/* GHIDRADEC_FUNCTION index=1695 start=0x40569ae */

void _kern_serv_port_gone(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    if (param_2 == *(int *)(iVar2 + 0x4b0)) {
      *(undefined4 *)(iVar2 + 0x4b0) = 0;
    }
    iVar1 = 0;
    do {
      if (param_2 == *(int *)(iVar2 + 0x18c)) {
        *(undefined4 *)(iVar2 + 0x18c) = 0;
        *(undefined4 *)(iVar2 + 400) = 0;
        return;
      }
      iVar2 = iVar2 + 0x10;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x32);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1696 start=0x40569f2 */

undefined4 _kern_serv_instance_loc(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1697 start=0x4056a06 */

undefined4 _kern_serv_version(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0x67;
  }
  else {
    *(int *)(*param_1 + 0x4c8) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1698 start=0x4056a28 */

undefined4 _kern_serv_load_objc(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1699 start=0x4056a32 */

undefined4 _kern_serv_boot_port(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x10) = param_2;
  return 0;
}

