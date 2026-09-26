
/* WARNING: Removing unreachable block (ram,0xf001e528) */
/* WARNING: Removing unreachable block (ram,0xf001e550) */
/* WARNING: Removing unreachable block (ram,0xf001e588) */

undefined8 _mcldup(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (*(sword *)(param_1 + 0xc) == 1) {
    iVar2 = param_1 + *(int *)(param_1 + 4);
    *(int *)(param_2 + 4) = iVar2 - param_2;
    *(undefined2 *)(param_2 + 0xc) = 1;
    iVar2 = iVar2 - _mbutl >> 10;
    _mclrefcnt[iVar2] = _mclrefcnt[iVar2] + '\x01';
  }
  else if (*(sword *)(param_1 + 0xc) == 2) {
    piVar1 = (int *)(*(sword *)(param_2 + 8) + 4);
    _kalloc();
    *piVar1 = *(sword *)(param_2 + 8) + 4;
    _bcopy(param_1 + *(int *)(param_1 + 4) + param_3,piVar1 + 1,(int)*(sword *)(param_2 + 8));
    *(int *)(param_2 + 4) = (int)piVar1 + (-param_3 - (param_2 + -4));
    *(undefined2 *)(param_2 + 0xc) = 2;
    *(code **)(param_2 + 0x10) = sub_F001E4AC;
    *(int **)(param_2 + 0x14) = piVar1;
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  else {
    _panic(&aMcldup);
  }
  return CONCAT44(param_2,param_1);
}

