
/* WARNING: Removing unreachable block (ram,0xf005acf0) */
/* WARNING: Removing unreachable block (ram,0xf005accc) */
/* WARNING: Removing unreachable block (ram,0xf005adac) */
/* WARNING: Removing unreachable block (ram,0xf005ad58) */
/* WARNING: Removing unreachable block (ram,0xf005acb4) */
/* WARNING: Removing unreachable block (ram,0xf005ac88) */
/* WARNING: Removing unreachable block (ram,0xf005ac40) */
/* WARNING: Removing unreachable block (ram,0xf005abe8) */
/* WARNING: Removing unreachable block (ram,0xf005abc8) */
/* WARNING: Removing unreachable block (ram,0xf005ac08) */
/* WARNING: Removing unreachable block (ram,0xf005ac14) */
/* WARNING: Removing unreachable block (ram,0xf005abdc) */
/* WARNING: Removing unreachable block (ram,0xf005ac2c) */
/* WARNING: Removing unreachable block (ram,0xf005ac68) */
/* WARNING: Removing unreachable block (ram,0xf005aca0) */
/* WARNING: Removing unreachable block (ram,0xf005ad6c) */
/* WARNING: Removing unreachable block (ram,0xf005ad8c) */
/* WARNING: Removing unreachable block (ram,0xf005adb4) */
/* WARNING: Removing unreachable block (ram,0xf005acd8) */
/* WARNING: Removing unreachable block (ram,0xf005ac54) */
/* WARNING: Removing unreachable block (ram,0xf005abf4) */

undefined8 _ipc_port_destroy(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint *puVar7;
  undefined4 unaff_l4;
  uint *puVar8;
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
  uVar5 = param_1[10];
  if (uVar5 != 0) {
    param_1[10] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    *param_1 = 0;
    if ((uVar5 & 1) == 0) {
      piVar2 = param_1;
      _ipc_port_check_circularity(param_1,uVar5);
      if (piVar2 == (int *)0x0) {
        _ipc_notify_port_destroyed(uVar5,param_1);
        goto locret_F005ADBC;
      }
      _ipc_port_release_sonce(uVar5);
    }
    else {
      uVar5 = uVar5 & 0xfffffffe;
      piVar2 = param_1;
      _ipc_port_check_circularity(param_1,uVar5);
      if (piVar2 == (int *)0x0) {
        _ipc_notify_port_destroyed_compat(uVar5,param_1);
        goto locret_F005ADBC;
      }
      _ipc_port_release_send(uVar5);
    }
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
  }
  while( true ) {
    piVar2 = param_1 + 0x13;
    _ipc_thread_dequeue();
    if (piVar2 == (int *)0x0) break;
    piVar2[0x26] = 0;
    _thread_go();
  }
  uVar5 = param_1[2] & 0x7fffffff;
  param_1[2] = uVar5;
  _ipc_port_timestamp();
  param_1[3] = uVar5;
  *param_1 = 0;
  piVar2 = param_1 + 0x10;
  if (param_1[9] != 0) {
    _ipc_notify_send_once();
  }
  do {
    do {
    } while (*piVar2 != 0);
    piVar3 = piVar2;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  while (piVar3 = param_1 + 0x11, _ipc_kmsg_dequeue(), piVar3 != (int *)0x0) {
    *piVar2 = 0;
    _ipc_object_release(param_1);
    piVar3[7] = 0;
    _ipc_kmsg_destroy(piVar3);
    do {
      do {
      } while (*piVar2 != 0);
      piVar3 = piVar2;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
  }
  *piVar2 = 0;
  puVar7 = (uint *)param_1[0xb];
  if (puVar7 == (uint *)0x0) {
    uVar5 = param_1[2];
  }
  else {
    puVar8 = (uint *)puVar7[1];
    uVar6 = *puVar8;
    uVar5 = 1;
    puVar1 = puVar7;
    if (uVar6 < 2) {
      uVar5 = *puVar8;
    }
    else {
      do {
        if (puVar1[3] != 0) {
          uVar4 = puVar1[2];
          if ((uVar4 & 1) == 0) {
            _ipc_notify_dead_name(uVar4,puVar1[3]);
          }
          else {
            _ipc_port_delete_compat(param_1,uVar4 & 0xfffffffe);
          }
        }
        uVar5 = uVar5 + 1;
        puVar1 = puVar1 + 2;
      } while (uVar5 < uVar6);
      uVar5 = *puVar8;
    }
    _ipc_table_free(uVar5 << 3,puVar7);
    uVar5 = param_1[2];
  }
  if ((uVar5 & 0xffff) != 0) {
    _ipc_kobject_destroy(param_1);
  }
  _ipc_object_release(param_1);
locret_F005ADBC:
  return CONCAT44(param_2,param_1);
}
