
/* WARNING: Removing unreachable block (ram,0xf00d20d4) */
/* WARNING: Removing unreachable block (ram,0xf00d20bc) */
/* WARNING: Removing unreachable block (ram,0xf00d2064) */
/* WARNING: Removing unreachable block (ram,0xf00d2044) */
/* WARNING: Removing unreachable block (ram,0xf00d2024) */
/* WARNING: Removing unreachable block (ram,0xf00d2004) */
/* WARNING: Removing unreachable block (ram,0xf00d1ff4) */
/* WARNING: Removing unreachable block (ram,0xf00d1fd4) */
/* WARNING: Removing unreachable block (ram,0xf00d1fb8) */
/* WARNING: Removing unreachable block (ram,0xf00d1f9c) */
/* WARNING: Removing unreachable block (ram,0xf00d1f80) */
/* WARNING: Removing unreachable block (ram,0xf00d1f68) */
/* WARNING: Removing unreachable block (ram,0xf00d1f78) */
/* WARNING: Removing unreachable block (ram,0xf00d1f88) */
/* WARNING: Removing unreachable block (ram,0xf00d1fa4) */
/* WARNING: Removing unreachable block (ram,0xf00d1fc0) */
/* WARNING: Removing unreachable block (ram,0xf00d1fe8) */
/* WARNING: Removing unreachable block (ram,0xf00d1ffc) */
/* WARNING: Removing unreachable block (ram,0xf00d2018) */
/* WARNING: Removing unreachable block (ram,0xf00d2038) */
/* WARNING: Removing unreachable block (ram,0xf00d2058) */
/* WARNING: Removing unreachable block (ram,0xf00d20a0) */
/* WARNING: Removing unreachable block (ram,0xf00d20c8) */
/* WARNING: Removing unreachable block (ram,0xf00d20f0) */
/* WARNING: Removing unreachable block (ram,0xf00d1f58) */

undefined8 -[EventDriver init](int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined7 *puVar2;
  undefined7 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  
  puVar3 = paNxlock;
  puVar1 = paNew;
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
  puVar2 = paNxlock;
  _objc_msgSend(paNxlock,paNew);
  *(undefined7 **)(param_1 + 0x110) = puVar2;
  puVar2 = puVar3;
  _objc_msgSend(puVar3,puVar1);
  *(undefined7 **)(param_1 + 0x170) = puVar2;
  _objc_msgSend(puVar3,puVar1);
  *(undefined7 **)(param_1 + 0x214) = puVar3;
  _task_self();
  _port_allocate_EXTERNAL();
  if (puVar3 == (undefined7 *)0x0) {
    _task_self();
    _port_allocate_EXTERNAL();
    if (puVar3 == (undefined7 *)0x0) {
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar3 == (undefined7 *)0x0) {
        uVar4 = *(undefined4 *)(param_1 + 0x134);
        _IOGetKernPort();
        uVar5 = *(undefined4 *)(param_1 + 0x138);
        _ev_port_list = uVar4;
        _IOGetKernPort();
        iVar6 = *(int *)(param_1 + 0x13c);
        DAT_f010fa94 = uVar5;
        _IOGetKernPort();
        *(int *)(param_1 + 0x140) = iVar6;
        _task_self();
        _port_set_allocate_EXTERNAL();
        if (iVar6 == 0) {
          _task_self();
          _port_set_add_EXTERNAL();
          if (iVar6 == 0) {
            _task_self();
            _port_set_add_EXTERNAL();
            if (iVar6 == 0) {
              _task_self();
              _port_set_add_EXTERNAL();
              if (iVar6 == 0) {
                *(int *)(param_1 + 0x178) = param_1 + 0x174;
                *(int *)(param_1 + 0x174) = param_1 + 0x174;
                *(int *)((int)register0x00000038 + -0x10) = param_1;
                *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
                *(undefined2 *)(param_1 + 0x1a8) = 100;
                *(undefined2 *)(param_1 + 0x1aa) = 100;
                pcVar7 = sub_F00D1C1C;
                _IOForkThread(sub_F00D1C1C,param_1);
                _IOSetThreadPolicy();
                _IOSetThreadPriority(pcVar7,0x1c);
                if (*(char *)(param_1 + 0x108) == '\0') {
                  _objc_msgSend(param_1,paRegisterdevice);
                  *(undefined *)(param_1 + 0x108) = 1;
                }
              }
              else {
                param_1 = 0;
              }
            }
            else {
              param_1 = 0;
            }
          }
          else {
            param_1 = 0;
          }
        }
        else {
          param_1 = 0;
        }
      }
      else {
        param_1 = 0;
      }
    }
    else {
      param_1 = 0;
    }
  }
  else {
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}

