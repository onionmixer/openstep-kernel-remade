
/* WARNING: Removing unreachable block (ram,0xf00584c0) */
/* WARNING: Removing unreachable block (ram,0xf0058774) */
/* WARNING: Removing unreachable block (ram,0xf00586a8) */
/* WARNING: Removing unreachable block (ram,0xf0058600) */
/* WARNING: Removing unreachable block (ram,0xf00585c0) */
/* WARNING: Removing unreachable block (ram,0xf0058594) */
/* WARNING: Removing unreachable block (ram,0xf0058534) */
/* WARNING: Removing unreachable block (ram,0xf00585a4) */
/* WARNING: Removing unreachable block (ram,0xf00585b0) */
/* WARNING: Removing unreachable block (ram,0xf00585d8) */
/* WARNING: Removing unreachable block (ram,0xf0058540) */
/* WARNING: Removing unreachable block (ram,0xf0058684) */
/* WARNING: Removing unreachable block (ram,0xf0058790) */
/* WARNING: Removing unreachable block (ram,0xf00584d8) */
/* WARNING: Removing unreachable block (ram,0xf0058494) */

undefined8 _ipc_mqueue_send(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar9;
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
  piVar6 = (int *)param_1[7];
  do {
    do {
    } while (*piVar6 != 0);
    piVar7 = piVar6;
    _simple_lock_try();
  } while (piVar7 == (int *)0x0);
  if (piVar6[3] == _ipc_space_kernel) {
    *piVar6 = 0;
    _ipc_kobject_server();
    if (param_1 == (int *)0x0) {
      uVar8 = 0;
    }
    else {
      _ipc_mqueue_send();
      uVar8 = 0;
    }
locret_F00587A4:
    return CONCAT44(param_2,uVar8);
  }
  do {
    iVar1 = piVar6[2];
loc_F00584F8:
    iVar5 = _active_threads;
    if (-1 < iVar1) {
      iVar1 = piVar6[1];
      piVar6[1] = iVar1 + -1;
      *piVar6 = 0;
      if (iVar1 + -1 == 0) {
        _zfree((&_ipc_object_zones)[(piVar6[2] & 0x7fffffffU) >> 0x10],piVar6);
        param_1[7] = 0;
      }
      else {
        param_1[7] = 0;
      }
loc_F0058540:
      _ipc_kmsg_destroy(param_1);
      uVar8 = 0;
      goto locret_F00587A4;
    }
    if ((uint)piVar6[0xe] < (uint)piVar6[0xf]) {
loc_F005863C:
      uVar4 = param_1[5];
loc_F0058640:
      if ((uVar4 & 0x40000000) != 0) {
        *piVar6 = 0;
        goto loc_F0058540;
      }
      piVar6[0xe] = piVar6[0xe] + 1;
      if (piVar6[0xc] == 0) {
        piVar7 = piVar6 + 0x10;
      }
      else {
        piVar7 = (int *)(piVar6[0xc] + 0x10);
      }
      do {
        do {
        } while (*piVar7 != 0);
        piVar2 = piVar7;
        _simple_lock_try();
        piVar9 = piVar7 + 2;
      } while (piVar2 == (int *)0x0);
      *piVar6 = 0;
      iVar1 = *piVar9;
      while( true ) {
        if (iVar1 == 0) {
          iVar1 = piVar7[1];
          if (iVar1 == 0) {
            piVar7[1] = (int)param_1;
            *param_1 = (int)param_1;
            param_1[1] = (int)param_1;
          }
          else {
            piVar6 = *(int **)(iVar1 + 4);
            *param_1 = iVar1;
            param_1[1] = (int)piVar6;
            *(int **)(iVar1 + 4) = param_1;
            *piVar6 = (int)param_1;
          }
          *piVar7 = 0;
          uVar8 = 0;
          goto locret_F00587A4;
        }
        iVar5 = *(int *)(iVar1 + 0x90);
        if (iVar5 == iVar1) {
          *piVar9 = 0;
        }
        else {
          iVar3 = *(int *)(iVar1 + 0x94);
          *piVar9 = iVar5;
          *(int *)(iVar5 + 0x94) = iVar3;
          *(int *)(iVar3 + 0x90) = iVar5;
          *(int *)(iVar1 + 0x90) = iVar1;
          *(int *)(iVar1 + 0x94) = iVar1;
        }
        if ((uint)param_1[6] <= *(uint *)(iVar1 + 0x9c)) break;
        *(undefined4 *)(iVar1 + 0x98) = 0x10004004;
        *(int *)(iVar1 + 0x9c) = param_1[6];
        _thread_go();
        iVar1 = *piVar9;
      }
      *(undefined4 *)(iVar1 + 0x98) = 0;
      *(int **)(iVar1 + 0x9c) = param_1;
      iVar5 = piVar6[0xd];
      piVar6[0xd] = iVar5 + 1;
      *(int *)(iVar1 + 0xa0) = iVar5;
      *piVar7 = 0;
      if ((param_2 & 0x20000) == 0) {
        _thread_go(iVar1);
        uVar8 = 0;
      }
      else {
        _thread_go_and_switch(param_4,iVar1);
        uVar8 = 0;
      }
      goto locret_F00587A4;
    }
    if ((param_2 & 0x10000) != 0) {
      uVar4 = param_1[5];
      goto loc_F0058640;
    }
    if (*(char *)((int)param_1 + 0x17) == '\x12') goto loc_F005863C;
    if ((param_2 & 0x10) == 0) {
      _thread_will_wait(_active_threads);
    }
    else {
      if (param_3 == 0) {
        *piVar6 = 0;
        uVar8 = 0x10000004;
        goto locret_F00587A4;
      }
      _thread_will_wait_with_timeout(_active_threads,param_3);
    }
    _ipc_thread_enqueue(piVar6 + 0x13,iVar5);
    *(undefined4 *)(iVar5 + 0x98) = 0x10000001;
    *piVar6 = 0;
    _thread_block_with_continuation(0);
    do {
      do {
      } while (*piVar6 != 0);
      piVar7 = piVar6;
      _simple_lock_try();
    } while (piVar7 == (int *)0x0);
    if (*(int *)(iVar5 + 0x98) == 0) {
      iVar1 = piVar6[2];
      goto loc_F00584F8;
    }
    _ipc_thread_rmqueue(piVar6 + 0x13,iVar5);
    iVar1 = *(int *)(iVar5 + 0x44);
    if (iVar1 != 1) {
      if (iVar1 < 1) {
        iVar1 = piVar6[2];
      }
      else {
        if (iVar1 < 4) {
          *piVar6 = 0;
          uVar8 = 0x10000007;
          goto locret_F00587A4;
        }
        iVar1 = piVar6[2];
      }
      goto loc_F00584F8;
    }
    param_3 = 0;
  } while( true );
}
