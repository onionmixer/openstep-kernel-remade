
/* WARNING: Removing unreachable block (ram,0xf00677fc) */
/* WARNING: Removing unreachable block (ram,0xf006781c) */
/* WARNING: Removing unreachable block (ram,0xf0067778) */

undefined8 _mach_ports_register(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar8;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  int aiStack_18 [6];
  
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
  if ((param_1 != 0) && (uVar5 = 0, param_3 < 5)) {
    bVar8 = false;
    iVar2 = -3;
    if (param_3 != 0) {
      puVar3 = (undefined *)((int)register0x00000038 + -8);
      iVar2 = 0;
      do {
        uVar6 = uVar5;
        uVar5 = uVar6 + 1;
        *(undefined4 *)(puVar3 + -0x10) = *(undefined4 *)(iVar2 + param_2);
        puVar3 = puVar3 + 4;
        iVar2 = iVar2 + 4;
      } while (uVar5 < param_3);
      bVar8 = SBORROW4(uVar5,3);
      iVar2 = uVar6 - 2;
    }
    if (iVar2 == 0 || iVar2 < 0 != bVar8) {
      puVar3 = (undefined *)((int)register0x00000038 + uVar5 * 4 + -8);
      do {
        *(undefined4 *)(puVar3 + -0x10) = 0;
        uVar5 = uVar5 + 1;
        puVar3 = puVar3 + 4;
      } while ((int)uVar5 < 4);
    }
    do {
      do {
        piVar1 = (int *)(param_1 + 100);
      } while (*piVar1 != 0);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar2 = 0;
    if (*(int *)(param_1 + 0x68) != 0) {
      puVar3 = (undefined *)((int)register0x00000038 + -8);
      iVar4 = param_1;
      do {
        uVar7 = *(undefined4 *)(iVar4 + 0x78);
        iVar2 = iVar2 + 1;
        *(undefined4 *)(iVar4 + 0x78) = *(undefined4 *)(puVar3 + -0x10);
        *(undefined4 *)(puVar3 + -0x10) = uVar7;
        puVar3 = puVar3 + 4;
        iVar4 = iVar4 + 4;
      } while (iVar2 < 4);
      *(undefined4 *)(param_1 + 100) = 0;
      iVar2 = 0;
      puVar3 = (undefined *)((int)register0x00000038 + -8);
      do {
        iVar2 = iVar2 + 1;
        if ((*(int *)(puVar3 + -0x10) != 0) && (*(int *)(puVar3 + -0x10) != -1)) {
          _ipc_port_release_send();
        }
        puVar3 = puVar3 + 4;
      } while (iVar2 < 4);
      if (param_3 != 0) {
        _kfree(param_2,param_3 << 2);
      }
      uVar7 = 0;
      goto locret_F0067828;
    }
    *(undefined4 *)(param_1 + 100) = 0;
  }
  uVar7 = 4;
locret_F0067828:
  return CONCAT44(param_2,uVar7);
}

