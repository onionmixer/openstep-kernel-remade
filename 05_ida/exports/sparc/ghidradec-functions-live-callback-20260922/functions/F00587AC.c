
/* WARNING: Removing unreachable block (ram,0xf00588ec) */
/* WARNING: Removing unreachable block (ram,0xf00587fc) */
/* WARNING: Removing unreachable block (ram,0xf00588c0) */
/* WARNING: Removing unreachable block (ram,0xf00587b4) */

undefined8 _ipc_mqueue_send_interrupt(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  puVar6 = (undefined4 *)param_1[7];
  puVar7 = puVar6;
  _simple_lock_try();
  if (puVar7 == (undefined4 *)0x0) {
    uVar8 = 0x800;
  }
  else if ((int)puVar6[2] < 0) {
    puVar7 = (undefined4 *)(puVar6[0xc] + 0x10);
    if (puVar6[0xc] == 0) {
      puVar7 = puVar6 + 0x10;
    }
    puVar1 = puVar7;
    _simple_lock_try();
    piVar2 = puVar7 + 2;
    if (puVar1 == (undefined4 *)0x0) {
      *puVar6 = 0;
      uVar8 = 0x800;
    }
    else {
      *puVar6 = 0;
      puVar6[0xe] = puVar6[0xe] + 1;
      iVar5 = *piVar2;
      while (iVar5 != 0) {
        iVar4 = *(int *)(iVar5 + 0x90);
        if (iVar4 == iVar5) {
          *piVar2 = 0;
        }
        else {
          iVar3 = *(int *)(iVar5 + 0x94);
          *piVar2 = iVar4;
          *(int *)(iVar4 + 0x94) = iVar3;
          *(int *)(iVar3 + 0x90) = iVar4;
          *(int *)(iVar5 + 0x90) = iVar5;
          *(int *)(iVar5 + 0x94) = iVar5;
        }
        if ((uint)param_1[6] <= *(uint *)(iVar5 + 0x9c)) {
          *(undefined4 *)(iVar5 + 0x98) = 0;
          *(int **)(iVar5 + 0x9c) = param_1;
          iVar4 = puVar6[0xd];
          puVar6[0xd] = iVar4 + 1;
          *(int *)(iVar5 + 0xa0) = iVar4;
          *puVar7 = 0;
          uVar8 = 0;
          _thread_go();
          goto locret_F00588F4;
        }
        *(undefined4 *)(iVar5 + 0x98) = 0x10004004;
        *(int *)(iVar5 + 0x9c) = param_1[6];
        _thread_go();
        iVar5 = *piVar2;
      }
      iVar5 = puVar7[1];
      if (iVar5 == 0) {
        puVar7[1] = param_1;
        *param_1 = (int)param_1;
        param_1[1] = (int)param_1;
      }
      else {
        piVar2 = *(int **)(iVar5 + 4);
        *param_1 = iVar5;
        param_1[1] = (int)piVar2;
        *(int **)(iVar5 + 4) = param_1;
        *piVar2 = (int)param_1;
      }
      *puVar7 = 0;
      uVar8 = 0;
    }
  }
  else {
    *puVar6 = 0;
    uVar8 = 0x10000003;
  }
locret_F00588F4:
  return CONCAT44(param_2,uVar8);
}

