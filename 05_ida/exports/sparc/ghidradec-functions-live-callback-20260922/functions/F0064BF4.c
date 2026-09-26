
/* WARNING: Removing unreachable block (ram,0xf0064c50) */
/* WARNING: Removing unreachable block (ram,0xf0064cd8) */
/* WARNING: Removing unreachable block (ram,0xf0064c48) */

undefined8 _host_processors(int param_1,int *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
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
  uVar7 = 0;
  if (param_1 == 0) {
    uVar8 = 4;
  }
  else {
    iVar4 = 0;
    iVar2 = 0;
    do {
      if (*(int *)((int)&_machine_slot + iVar2) != 0) {
        uVar7 = uVar7 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x20;
    } while (iVar4 < 1);
    if (uVar7 == 0) {
      _panic(aHostProcessors);
    }
    puVar1 = (undefined4 *)(uVar7 << 2);
    _kalloc();
    if (puVar1 == (undefined4 *)0x0) {
      uVar8 = 6;
    }
    else {
      iVar5 = 0;
      iVar4 = 0;
      iVar2 = 0;
      puVar3 = puVar1;
      do {
        if (*(int *)((int)&_machine_slot + iVar2) != 0) {
          *puVar3 = *(undefined4 *)((int)&_processor_ptr + iVar4);
          puVar3 = puVar3 + 1;
        }
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar5 < 1);
      *param_3 = uVar7;
      *param_2 = (int)puVar1;
      uVar6 = 0;
      if (uVar7 != 0) {
        do {
          uVar8 = *puVar1;
          uVar6 = uVar6 + 1;
          _convert_processor_to_port();
          *puVar1 = uVar8;
          puVar1 = puVar1 + 1;
        } while (uVar6 < uVar7);
      }
      uVar8 = 0;
    }
  }
  return CONCAT44(param_2,uVar8);
}

