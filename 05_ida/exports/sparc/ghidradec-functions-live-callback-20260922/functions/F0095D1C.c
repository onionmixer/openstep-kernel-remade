
void _srmmu_mmu_wu(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined in_DECOMPILE_MODE;
  int in_CWP;
  int iVar7;
  undefined8 uStackX_0;
  undefined4 uStackX_c;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  undefined8 uStackX_28;
  undefined8 uStackX_30;
  undefined8 uStackX_38;
  
  segment(4);
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 | 2;
  if (!(bool)in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)uStackX_20 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)uStackX_20;
    *(int *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uStackX_28 >> 0x20);
    *(int *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = (int)uStackX_28;
    *(int *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uStackX_30 >> 0x20);
    *(int *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = (int)uStackX_30;
    *(int *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uStackX_38 >> 0x20);
    *(int *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = (int)uStackX_38;
    *(int *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uStackX_0 >> 0x20);
    *(int *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = (int)uStackX_0;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uStackX_c;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uStackX_c;
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uStackX_10 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)uStackX_10;
    *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uStackX_18 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = (int)uStackX_18;
  }
  uVar3 = 0;
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  iVar7 = in_CWP + 1;
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(iVar7 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar7 * 0x10 + 1) * 4 + 0x8000) = param_2;
    *(undefined4 *)((iVar7 * 0x10 + 2) * 4 + 0x8000) = param_3;
    *(undefined4 *)((iVar7 * 0x10 + 3) * 4 + 0x8000) = 0;
    *(undefined4 *)((iVar7 * 0x10 + 4) * 4 + 0x8000) = param_5;
    *(undefined4 *)((iVar7 * 0x10 + 5) * 4 + 0x8000) = 0;
    *(BADSPACEBASE **)((iVar7 * 0x10 + 6) * 4 + 0x8000) = register0x00000038;
    *(undefined4 *)((iVar7 * 0x10 + 7) * 4 + 0x8000) = 0;
    *(int *)((iVar7 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar3 >> 0x20);
    *(int *)((iVar7 * 0x10 + 9) * 4 + 0x8000) = (int)uVar3;
    *(undefined4 *)((iVar7 * 0x10 + 10) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar7 * 0x10 + 0xb) * 4 + 0x8000) = uVar4;
    *(int *)((iVar7 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar5 >> 0x20);
    *(int *)((iVar7 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar5;
    *(int *)((iVar7 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
    *(int *)((iVar7 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar6;
  }
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & 0xfffffffd;
  segment(4);
  segment(4);
  wu_chk_flt();
  return;
}

