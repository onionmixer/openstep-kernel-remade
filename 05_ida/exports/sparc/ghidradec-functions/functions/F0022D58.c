
/* WARNING: Removing unreachable block (ram,0xf0022e00) */
/* WARNING: Removing unreachable block (ram,0xf0022db8) */
/* WARNING: Removing unreachable block (ram,0xf0022df4) */

undefined8 _unp_disconnect(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  int *piVar3;
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
  puVar2 = (undefined4 *)param_1[3];
  if (puVar2 != (undefined4 *)0x0) {
    param_1[3] = 0;
    if (*(sword *)*param_1 == 1) {
      _soisdisconnected();
      puVar2[3] = 0;
      _soisdisconnected(*puVar2);
    }
    else if (*(sword *)*param_1 == 2) {
      piVar1 = (int *)puVar2[4];
      if ((int *)puVar2[4] == param_1) {
        puVar2[4] = param_1[5];
      }
      else {
        do {
          piVar3 = piVar1;
          if (piVar3 == (int *)0x0) {
            _panic(aUnpDisconnect);
            piVar1 = piRam00000014;
          }
          else {
            piVar1 = (int *)piVar3[5];
          }
        } while (piVar1 != param_1);
        piVar3[5] = param_1[5];
      }
      param_1[5] = 0;
      *(word *)(*param_1 + 6) = *(word *)(*param_1 + 6) & 0xfffd;
    }
  }
  return CONCAT44(param_2,param_1);
}
