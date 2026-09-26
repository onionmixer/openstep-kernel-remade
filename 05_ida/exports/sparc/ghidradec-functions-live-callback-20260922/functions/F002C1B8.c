
/* WARNING: Removing unreachable block (ram,0xf002c224) */

undefined8 _if_handle_input(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (_ifnet != 0) {
    pcVar2 = *(code **)(_ifnet + 0x3c);
    iVar3 = _ifnet;
    while( true ) {
      if (pcVar2 == (code *)0x0) {
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      else if (*(int *)(iVar3 + 0x14) == 0) {
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      else {
        iVar1 = iVar3;
        (*pcVar2)(iVar3,param_1,param_2,param_3);
        if (iVar1 == 0) {
          uVar4 = 0;
          goto locret_F002C230;
        }
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      if (iVar3 == 0) break;
      pcVar2 = *(code **)(iVar3 + 0x3c);
    }
  }
  _nb_free(param_2);
  uVar4 = 0x2f;
locret_F002C230:
  return CONCAT44(param_2,uVar4);
}

