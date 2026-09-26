
/* WARNING: Removing unreachable block (ram,0xf00c1460) */

undefined8 _settable(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + 0x44);
  sub_F00C0EF4();
  if ((puVar1 == (undefined *)0x0) || (_keytables == (undefined (*) [44])0x0)) {
    uVar2 = 0;
  }
  else if ((param_2 & 0x80) == 0) {
    if ((param_2 & 0x800) == 0) {
      if ((param_2 & 0x30) == 0) {
        if ((param_2 & 0x200) == 0) {
          if ((param_2 & 0xe) == 0) {
            if ((param_2 & 1) == 0) {
              uVar2 = *(undefined4 *)*_keytables;
            }
            else {
              uVar2 = *(undefined4 *)(*_keytables + 8);
            }
          }
          else {
            uVar2 = *(undefined4 *)(*_keytables + 4);
          }
        }
        else {
          uVar2 = *(undefined4 *)(*_keytables + 0xc);
        }
      }
      else {
        uVar2 = *(undefined4 *)(*_keytables + 0x14);
      }
    }
    else {
      uVar2 = *(undefined4 *)(*_keytables + 0x10);
    }
  }
  else {
    uVar2 = *(undefined4 *)(*_keytables + 0x18);
  }
  return CONCAT44(param_2,uVar2);
}

