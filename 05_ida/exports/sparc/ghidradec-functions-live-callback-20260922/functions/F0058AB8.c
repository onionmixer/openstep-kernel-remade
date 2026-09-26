
/* WARNING: Removing unreachable block (ram,0xf0058cb0) */
/* WARNING: Removing unreachable block (ram,0xf0058d40) */
/* WARNING: Removing unreachable block (ram,0xf0058cd4) */
/* WARNING: Removing unreachable block (ram,0xf0058bc0) */
/* WARNING: Removing unreachable block (ram,0xf0058b60) */
/* WARNING: Removing unreachable block (ram,0xf0058bd8) */
/* WARNING: Removing unreachable block (ram,0xf0058cf0) */
/* WARNING: Removing unreachable block (ram,0xf0058d4c) */
/* WARNING: Removing unreachable block (ram,0xf0058c74) */
/* WARNING: Removing unreachable block (ram,0xf0058b70) */

undefined8
_ipc_mqueue_receive(int *param_1,int *param_2,uint param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  undefined4 unaff_l1;
  uint *puVar7;
  uint *puVar8;
  undefined4 unaff_l3;
  int *piVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 uVar11;
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
  
  iVar5 = _active_threads;
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
  puVar8 = *(uint **)((int)register0x00000038 + 0x5c);
  piVar9 = *(int **)((int)register0x00000038 + 0x60);
  puVar7 = (uint *)(param_1 + 1);
  if (param_5 != 0) goto loc_F0058BC8;
  do {
    puVar6 = (uint *)*puVar7;
loc_F0058ADC:
    if (puVar6 != (uint *)0x0) {
      if (param_3 < puVar6[6]) {
        *puVar8 = puVar6[6];
        *param_1 = 0;
        uVar11 = 0x10004004;
      }
      else {
        puVar4 = (uint *)*puVar6;
        if (puVar4 == puVar6) {
          *puVar7 = 0;
        }
        else {
          puVar1 = (uint *)puVar6[1];
          *puVar7 = (uint)puVar4;
          puVar4[1] = (uint)puVar1;
          *puVar1 = (uint)puVar4;
        }
        param_2 = (int *)puVar6[7];
        iVar5 = param_2[0xd];
        param_2[0xd] = iVar5 + 1;
loc_F0058CC0:
        *param_1 = 0;
        if (puVar6[3] != 0) {
          _ipc_marequest_destroy();
          puVar6[3] = 0;
        }
        do {
          do {
          } while (*param_2 != 0);
          piVar2 = param_2;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if (param_2[2] < 0) {
          iVar3 = param_2[0xe];
          iVar10 = param_2[0x13];
          param_2[0xe] = iVar3 - 1U;
          if ((iVar10 != 0) && (iVar3 - 1U < (uint)param_2[0xf])) {
            _ipc_thread_rmqueue(param_2 + 0x13,iVar10);
            *(undefined4 *)(iVar10 + 0x98) = 0;
            _thread_go(iVar10);
          }
        }
        *param_2 = 0;
        *puVar8 = (uint)puVar6;
        *piVar9 = iVar5;
        uVar11 = 0;
      }
      goto locret_F0058D64;
    }
    if (((uint)param_2 & 0x100) == 0) {
      _thread_will_wait(iVar5);
      iVar3 = param_1[2];
    }
    else {
      if (param_4 == 0) {
        *param_1 = 0;
        uVar11 = 0x10004003;
        goto locret_F0058D64;
      }
      _thread_will_wait_with_timeout(iVar5,param_4);
      iVar3 = param_1[2];
    }
    if (iVar3 == 0) {
      param_1[2] = iVar5;
    }
    else {
      iVar10 = *(int *)(iVar3 + 0x94);
      *(int *)(iVar5 + 0x90) = iVar3;
      *(int *)(iVar5 + 0x94) = iVar10;
      *(int *)(iVar3 + 0x94) = iVar5;
      *(int *)(iVar10 + 0x90) = iVar5;
    }
    *(undefined4 *)(iVar5 + 0x98) = 0x10004001;
    *(uint *)(iVar5 + 0x9c) = param_3;
    *param_1 = 0;
    iVar3 = 0;
    if (param_6 != 0) {
      iVar3 = param_6;
    }
    _thread_block_with_continuation(iVar3);
loc_F0058BC8:
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = *(int *)(iVar5 + 0x98);
    if (iVar3 == 0) {
      puVar6 = *(uint **)(iVar5 + 0x9c);
      iVar5 = *(int *)(iVar5 + 0xa0);
      param_2 = (int *)puVar6[7];
      goto loc_F0058CC0;
    }
    if (iVar3 == 0x10004004) {
      *puVar8 = *(uint *)(iVar5 + 0x9c);
loc_F0058C68:
      *param_1 = 0;
      uVar11 = *(undefined4 *)(iVar5 + 0x98);
locret_F0058D64:
      return CONCAT44(param_2,uVar11);
    }
    if (0x10004004 < iVar3) {
      if ((iVar3 == 0x10004006) || (iVar3 == 0x10004009)) goto loc_F0058C68;
loc_F0058CB0:
      _panic(aIpcMqueueRecei);
      puVar6 = (uint *)*puVar7;
      goto loc_F0058ADC;
    }
    if (iVar3 != 0x10004001) goto loc_F0058CB0;
    _ipc_thread_rmqueue(param_1 + 2,iVar5);
    iVar3 = *(int *)(iVar5 + 0x44);
    if (iVar3 != 1) {
      if (iVar3 < 1) {
        puVar6 = (uint *)*puVar7;
      }
      else {
        if (iVar3 < 4) {
          *param_1 = 0;
          uVar11 = 0x10004005;
          goto locret_F0058D64;
        }
        puVar6 = (uint *)*puVar7;
      }
      goto loc_F0058ADC;
    }
    param_4 = 0;
  } while( true );
}

