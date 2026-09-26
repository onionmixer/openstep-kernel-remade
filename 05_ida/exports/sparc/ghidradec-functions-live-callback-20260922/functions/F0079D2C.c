
/* WARNING: Removing unreachable block (ram,0xf007a094) */
/* WARNING: Removing unreachable block (ram,0xf007a1a0) */
/* WARNING: Removing unreachable block (ram,0xf007a238) */
/* WARNING: Removing unreachable block (ram,0xf007a318) */
/* WARNING: Removing unreachable block (ram,0xf007a2a4) */
/* WARNING: Removing unreachable block (ram,0xf007a140) */
/* WARNING: Removing unreachable block (ram,0xf007a040) */
/* WARNING: Removing unreachable block (ram,0xf007a004) */
/* WARNING: Removing unreachable block (ram,0xf0079fec) */
/* WARNING: Removing unreachable block (ram,0xf0079fc8) */
/* WARNING: Removing unreachable block (ram,0xf0079fa0) */
/* WARNING: Removing unreachable block (ram,0xf0079f58) */
/* WARNING: Removing unreachable block (ram,0xf0079f44) */
/* WARNING: Removing unreachable block (ram,0xf0079f24) */
/* WARNING: Removing unreachable block (ram,0xf0079f0c) */
/* WARNING: Removing unreachable block (ram,0xf0079eec) */
/* WARNING: Removing unreachable block (ram,0xf0079edc) */
/* WARNING: Removing unreachable block (ram,0xf0079ec8) */
/* WARNING: Removing unreachable block (ram,0xf0079ea8) */
/* WARNING: Removing unreachable block (ram,0xf0079e98) */
/* WARNING: Removing unreachable block (ram,0xf0079e78) */
/* WARNING: Removing unreachable block (ram,0xf0079e64) */
/* WARNING: Removing unreachable block (ram,0xf0079e50) */
/* WARNING: Removing unreachable block (ram,0xf0079e1c) */
/* WARNING: Removing unreachable block (ram,0xf0079d80) */
/* WARNING: Removing unreachable block (ram,0xf0079d48) */
/* WARNING: Removing unreachable block (ram,0xf0079d90) */
/* WARNING: Removing unreachable block (ram,0xf0079e28) */
/* WARNING: Removing unreachable block (ram,0xf0079e5c) */
/* WARNING: Removing unreachable block (ram,0xf0079e70) */
/* WARNING: Removing unreachable block (ram,0xf0079e8c) */
/* WARNING: Removing unreachable block (ram,0xf0079ea0) */
/* WARNING: Removing unreachable block (ram,0xf0079eb4) */
/* WARNING: Removing unreachable block (ram,0xf0079ed4) */
/* WARNING: Removing unreachable block (ram,0xf0079ee4) */
/* WARNING: Removing unreachable block (ram,0xf0079f00) */
/* WARNING: Removing unreachable block (ram,0xf0079f14) */
/* WARNING: Removing unreachable block (ram,0xf0079f30) */
/* WARNING: Removing unreachable block (ram,0xf0079f50) */
/* WARNING: Removing unreachable block (ram,0xf0079f68) */
/* WARNING: Removing unreachable block (ram,0xf0079f88) */
/* WARNING: Removing unreachable block (ram,0xf0079fd8) */
/* WARNING: Removing unreachable block (ram,0xf0079ff4) */
/* WARNING: Removing unreachable block (ram,0xf007a020) */
/* WARNING: Removing unreachable block (ram,0xf007a118) */
/* WARNING: Removing unreachable block (ram,0xf007a1c0) */
/* WARNING: Removing unreachable block (ram,0xf007a2ec) */
/* WARNING: Removing unreachable block (ram,0xf007a33c) */
/* WARNING: Removing unreachable block (ram,0xf007a190) */
/* WARNING: Removing unreachable block (ram,0xf007a080) */
/* WARNING: Removing unreachable block (ram,0xf007a0b4) */
/* WARNING: Removing unreachable block (ram,0xf0079d30) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf0079d48 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void _kern_server_main(void)

{
  int extraout_o0;
  undefined8 in_o0_1;
  undefined4 *puVar2;
  undefined8 uVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 unaff_l0;
  int *piVar9;
  undefined4 uVar10;
  undefined4 unaff_l1;
  undefined4 *puVar11;
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
  _kalloc(0x4d4);
  extraout_o0 = (int)((qword)in_o0_1 >> 0x20);
  *(int *)((int)register0x00000038 + -0x4c) = extraout_o0;
  _memcpy((undefined *)((int)register0x00000038 + -0x48),(int)in_o0_1,0x3c);
  *(undefined **)((int)register0x00000038 + -0x48) = (undefined *)((int)register0x00000038 + -0x4c);
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x50) = 1;
  }
  _bzero(*(undefined4 *)((int)register0x00000038 + -0x4c));
  *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4c8) = 0xffffffff;
  _task_self();
  puVar2 = *(undefined4 **)((int)register0x00000038 + -0x4c);
  iVar8 = 0x17c;
  puVar2[2] = extraout_o0;
  puVar11 = puVar2 + 0xf;
  puVar7 = puVar2 + 0x4c;
  puVar2[3] = _active_threads;
  *puVar2 = 0;
  puVar2[0xe] = puVar2 + 0xd;
  puVar2[0xd] = puVar2 + 0xd;
  puVar2[0x10] = puVar11;
  puVar2[0xf] = puVar11;
  puVar2[0x131] = puVar2 + 0x130;
  puVar2[0x130] = puVar2 + 0x130;
  do {
    puVar6 = (undefined4 *)puVar2[0x10];
    if (puVar11 == puVar6) {
      puVar2[0xf] = (int)puVar2 + iVar8;
    }
    else {
      puVar6[2] = (int)puVar2 + iVar8;
    }
    puVar7[0x16] = puVar6;
    puVar7[0x15] = puVar11;
    puVar2[0x10] = (int)puVar2 + iVar8;
    puVar7 = puVar7 + -4;
    iVar8 = iVar8 + -0x10;
  } while ((int)puVar2 <= (int)puVar7);
  _thread_self();
  _thread_get_special_port_EXTERNAL
            (extraout_o0,(int)in_o0_1,(undefined *)((int)register0x00000038 + -0x50));
  if ((extraout_o0 == 0) && (*(int *)((int)register0x00000038 + -0x50) != 0)) {
    uVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x50),
                     *(undefined4 *)((int)register0x00000038 + -0x4c));
  }
  else {
    _printf(aKServerCanTFin);
    _thread_terminate(_active_threads);
    _thread_halt_self();
    uVar1 = *(undefined8 *)((int)register0x00000038 + -0x50);
  }
  iVar3 = (int)uVar1;
  iVar8 = (int)((qword)uVar1 >> 0x20);
  *(int *)(iVar3 + 0x14) = iVar8;
  _task_self();
  _port_allocate_EXTERNAL();
  if (iVar8 != 0) {
    _printf(aKServerCanTAll);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  _thread_self();
  _thread_set_special_port_EXTERNAL(iVar8,iVar3,*(undefined4 *)((int)register0x00000038 + -0x54));
  if (iVar8 != 0) {
    _printf(aKServerCanTSet);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  _task_self();
  _port_set_allocate_EXTERNAL();
  if (iVar8 != 0) {
    _printf(aKServerCanTAll_0);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x20) =
       *(undefined4 *)((int)register0x00000038 + -0x58);
  _task_self();
  _port_set_add_EXTERNAL(iVar8,iVar3,*(undefined4 *)((int)register0x00000038 + -0x50));
  if (iVar8 != 0) {
    _printf(aKServerCanTAdd);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  _port_allocate_EXTERNAL(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 8));
  if (iVar8 == 0) {
    _port_set_add_EXTERNAL
              (*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 8),iVar3,
               *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x1c));
  }
  else {
    _kern_serv_panic(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x10));
  }
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    _task_self();
    _task_set_special_port_EXTERNAL
              (iVar8,iVar3,*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x1c));
  }
  _kern_serv_notify((undefined *)((int)register0x00000038 + -0x4c),iVar3,
                    *(undefined4 *)(iVar8 + 0x10));
  _kern_serv_kernel_task_port();
  *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4cc) = iVar8;
  _kalloc(0x30);
  iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  *(int *)(iVar4 + 0x44) = iVar8;
  *(undefined4 *)(iVar4 + 0x48) = 0x30;
loc_F007A020:
  _splusclock();
  piVar9 = *(int **)((int)register0x00000038 + -0x4c);
  do {
    do {
    } while (*piVar9 != 0);
    _simple_lock_try(piVar9);
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  } while (iVar8 == 0);
  while (iVar4 + 0x34 != iVar3) {
    puVar11 = *(undefined4 **)(iVar4 + 0x34);
    iVar5 = puVar11[2];
    if (iVar4 + 0x34 == iVar5) {
      *(int *)(iVar4 + 0x38) = iVar5;
    }
    else {
      *(int *)(iVar5 + 0xc) = iVar4 + 0x34;
    }
    puVar2 = *(undefined4 **)((int)register0x00000038 + -0x4c);
    puVar2[0xd] = iVar5;
    *puVar2 = 0;
    _splx(iVar8);
    (*(code *)*puVar11)(puVar11[1]);
    _splusclock();
    piVar9 = *(int **)((int)register0x00000038 + -0x4c);
    do {
      do {
      } while (*piVar9 != 0);
      _simple_lock_try(piVar9);
      iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    } while (iVar8 == 0);
    iVar5 = *(int *)(iVar4 + 0x40);
    if (iVar4 + 0x3c == iVar5) {
      *(undefined4 **)(iVar4 + 0x3c) = puVar11;
    }
    else {
      *(undefined4 **)(iVar5 + 8) = puVar11;
    }
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    puVar11[3] = iVar5;
    puVar11[2] = iVar4 + 0x3c;
    *(undefined4 **)(iVar4 + 0x40) = puVar11;
  }
  **(undefined4 **)((int)register0x00000038 + -0x4c) = 0;
  _splx();
  while( true ) {
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x58);
    *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar4 + 0x48);
    _msg_receive(iVar8,iVar3,1000);
    if (iVar8 != -0xcc) break;
    uVar10 = *(undefined4 *)(*(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x44) + 4);
    _kfree();
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x48) = uVar10;
    _kalloc();
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x44) = 0xffffff34;
  }
  if (-0xcc < iVar8) goto loc_F007A170;
  iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  if (iVar8 != -0xcf) goto loc_F007A1B8;
  goto loc_F007A1CC;
loc_F007A170:
  if (iVar8 != -0xcb) {
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    if (iVar8 != 0) {
loc_F007A1B8:
      _kern_serv_panic(*(undefined4 *)(iVar8 + 0x10));
      iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    }
loc_F007A1CC:
    if (*(int *)(iVar8 + 0xc) != *(int *)(iVar4 + 0x1c)) {
      if ((*(int *)(iVar8 + 0x14) - 0x40U < 0xd) &&
         (puVar11 = *(undefined4 **)(iVar4 + 0x4c0), (undefined4 *)(iVar4 + 0x4c0) != puVar11)) {
        do {
          if (iVar3 == *(int *)(iVar8 + 0x1c)) {
            *(undefined4 *)(iVar8 + 0x10) = *puVar11;
            _msg_send(iVar8,iVar3,0);
            iVar5 = puVar11[2];
            iVar4 = puVar11[3];
            if (*(int *)((int)register0x00000038 + -0x4c) + 0x4c0 == iVar5) {
              *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4c4) = iVar4;
            }
            else {
              *(int *)(iVar5 + 0xc) = iVar4;
            }
            if (*(int *)((int)register0x00000038 + -0x4c) + 0x4c0 == iVar4) {
              *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4c0) = iVar5;
            }
            else {
              *(int *)(iVar4 + 8) = iVar5;
            }
            _kfree(puVar11);
          }
          puVar11 = (undefined4 *)puVar11[2];
        } while ((undefined4 *)(iVar8 + 0x4c0) != puVar11);
      }
      *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 4) = *(undefined4 *)(iVar8 + 0xc);
      sub_F007A3DC();
      if ((iVar8 == -0x12f) && (iRamfffffedd == *(int *)((int)register0x00000038 + -0x50))) {
        _kern_serv_handler(0xfffffed1);
      }
      goto loc_F007A020;
    }
    if (*(int *)(iVar8 + 0x14) == 0x41) {
      if (*(code **)(iVar4 + 0x4b8) == (code *)0x0) {
        if (*(code **)(iVar4 + 0x4bc) != (code *)0x0) {
          (**(code **)(iVar4 + 0x4bc))(*(undefined4 *)(iVar8 + 0x1c));
        }
      }
      else {
        (**(code **)(iVar4 + 0x4b8))(*(undefined4 *)(iVar8 + 0x1c));
        if (iVar8 != 0) goto loc_F007A020;
      }
      _kern_serv_port_gone((undefined *)((int)register0x00000038 + -0x4c));
      goto loc_F007A020;
    }
    if (*(code **)(iVar4 + 0x4bc) != (code *)0x0) {
      (**(code **)(iVar4 + 0x4bc))(*(undefined4 *)(iVar8 + 0x1c));
    }
  }
  goto loc_F007A020;
}

