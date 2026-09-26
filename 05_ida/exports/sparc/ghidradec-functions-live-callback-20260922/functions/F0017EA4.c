
/* WARNING: Removing unreachable block (ram,0xf0017fa0) */
/* WARNING: Removing unreachable block (ram,0xf0017f74) */
/* WARNING: Removing unreachable block (ram,0xf0017ee0) */
/* WARNING: Removing unreachable block (ram,0xf0017fc4) */
/* WARNING: Removing unreachable block (ram,0xf0017f94) */
/* WARNING: Removing unreachable block (ram,0xf0017fac) */
/* WARNING: Removing unreachable block (ram,0xf0017ea8) */

undefined8 _ttymodem(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  _ttynty();
  uVar2 = *(uint *)(param_1 + 0x40);
  if (((uVar2 & 2) == 0) && ((*(uint *)(param_1 + 0x3c) & 0x100000) != 0)) {
    if (param_2 == 0) {
      if ((uVar2 & 0x100) == 0) {
        *(uint *)(param_1 + 0x40) = uVar2 | 0x100;
        (**(code **)(DAT_f011ca04 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))(param_1,0);
        uVar3 = 1;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      *(uint *)(param_1 + 0x40) = uVar2 & 0xfffffeff;
      _ttstart(param_1);
      uVar3 = 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x40);
    if (param_2 == 0) {
      *(uint *)(param_1 + 0x40) = uVar2 & 0xffffffef;
      if ((uVar2 & 4) != 0) {
        if ((*(uint *)(iVar1 + 0x10) & 0x8000) == 0) {
          _ttwakeup(param_1);
          if ((*(uint *)(param_1 + 0x3c) & 0x1000000) == 0) {
            _gsignal((int)*(sword *)(param_1 + 0x44),1);
            _gsignal((int)*(sword *)(param_1 + 0x44),0x13);
            _ttyflush(param_1,3);
            uVar3 = 0;
          }
          else {
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 1;
        }
        goto locret_F0017FD0;
      }
    }
    else {
      *(uint *)(param_1 + 0x40) = uVar2 | 0x10;
      _wakeup();
    }
    uVar3 = 1;
  }
locret_F0017FD0:
  return CONCAT44(param_2,uVar3);
}

