
/* WARNING: Removing unreachable block (ram,0xf00811c0) */

undefined8
sub_F00811AC(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = param_1;
  _machine_exception(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    switch(param_1) {
    case :
      uVar2 = 10;
      if (param_2 == 1) {
        uVar2 = 0xb;
      }
      break;
    case :
      uVar2 = 4;
      break;
    case :
      uVar2 = 8;
      break;
    case :
      uVar2 = 7;
      break;
    case :
      if (param_2 == 0x10001) {
        uVar2 = 0xd;
      }
      else if (param_2 < 0x10002) {
        uVar2 = 0xc;
        if (param_2 != 0x10000) goto def_F00811EC;
      }
      else {
        uVar2 = 6;
        if (param_2 != 0x10002) goto def_F00811EC;
      }
      break;
    case :
      uVar2 = 5;
      break;
    :
      goto def_F00811EC;
    }
    *param_4 = uVar2;
  }
def_F00811EC:
  return CONCAT44(param_2,param_1);
}

