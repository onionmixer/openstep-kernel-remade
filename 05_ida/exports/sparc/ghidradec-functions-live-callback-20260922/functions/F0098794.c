
/* WARNING: Removing unreachable block (ram,0xf00987f4) */
/* WARNING: Removing unreachable block (ram,0xf0098808) */

undefined8 _fill_nodeinfo(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  undefined4 *puVar7;
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
  piVar4 = *(int **)(param_2 + 0x10);
  if (piVar4 == (int *)0x0) {
    puVar7 = *(undefined4 **)(param_2 + 8);
  }
  else {
    *piVar4 = *piVar4 + 1;
    puVar7 = *(undefined4 **)(param_2 + 8);
  }
  if (puVar7 < *(undefined4 **)(param_2 + 0xc)) {
    puVar6 = puVar7 + 2;
    do {
      uVar1 = puVar6[-1];
      if (uVar1 == 1) {
        uVar5 = *puVar7;
loc_F00987F0:
        _prom_getprop(param_1,uVar5,*puVar6);
        puVar2 = *(undefined4 **)(param_2 + 0xc);
      }
      else if (uVar1 < 2) {
        iVar3 = param_1;
        _prom_getproplen(param_1,*puVar7);
        if (iVar3 == -1) {
          *(undefined4 *)*puVar6 = 0;
        }
        else {
          *(undefined4 *)*puVar6 = 1;
        }
        puVar2 = *(undefined4 **)(param_2 + 0xc);
      }
      else {
        if (uVar1 == 2) {
          uVar5 = *puVar7;
          goto loc_F00987F0;
        }
        puVar2 = *(undefined4 **)(param_2 + 0xc);
      }
      puVar7 = puVar7 + 3;
      puVar6 = puVar6 + 3;
    } while (puVar7 < puVar2);
  }
  return CONCAT44(param_2,param_1);
}

