
/* WARNING: Removing unreachable block (ram,0xf0045388) */

undefined8 _svckudp_dup(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  uint *puVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  uVar4 = *(uint *)(*(int *)(param_1[7] + 0x30) + 4);
  _dupchecks = _dupchecks + 1;
  puVar3 = *(uint **)(_drhashtbl + (uVar4 & 0x1f) * 4);
  if (puVar3 != (uint *)0x0) {
    uVar1 = *puVar3;
    while( true ) {
      if (uVar1 == uVar4) {
        if (puVar3[7] == *param_1) {
          if (puVar3[6] == param_1[1]) {
            if (puVar3[5] == param_1[2]) {
              puVar2 = puVar3 + 1;
              _bcmp(puVar2,param_1[7] + 0x10,0x10);
              if (puVar2 == (uint *)0x0) {
                uVar5 = 1;
                _dupreqs._0_4_ = _dupreqs._0_4_ + 1;
                goto locret_F00453C4;
              }
              puVar3 = (uint *)puVar3[9];
            }
            else {
              puVar3 = (uint *)puVar3[9];
            }
          }
          else {
            puVar3 = (uint *)puVar3[9];
          }
        }
        else {
          puVar3 = (uint *)puVar3[9];
        }
      }
      else {
        puVar3 = (uint *)puVar3[9];
      }
      if (puVar3 == (uint *)0x0) break;
      uVar1 = *puVar3;
    }
  }
  uVar5 = 0;
locret_F00453C4:
  return CONCAT44(param_2,uVar5);
}

