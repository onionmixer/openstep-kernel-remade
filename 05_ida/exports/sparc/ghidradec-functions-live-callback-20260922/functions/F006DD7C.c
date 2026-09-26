
/* WARNING: Removing unreachable block (ram,0xf006de2c) */
/* WARNING: Removing unreachable block (ram,0xf006ddf0) */
/* WARNING: Removing unreachable block (ram,0xf006de04) */
/* WARNING: Removing unreachable block (ram,0xf006ddcc) */
/* WARNING: Removing unreachable block (ram,0xf006dddc) */
/* WARNING: Removing unreachable block (ram,0xf006de24) */
/* WARNING: Removing unreachable block (ram,0xf006de34) */
/* WARNING: Removing unreachable block (ram,0xf006dd88) */

undefined8 sub_F006DD7C(undefined *param_1,int param_2)

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
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar2 = param_1;
  puVar1 = param_1;
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
    puVar2 = param_1;
    puVar1 = param_1;
  }
  do {
    param_2 = param_2 + -1;
loc_F006DD88:
    _miniMonGetchar();
    if (param_1 == (undefined *)0xa) {
      *puVar2 = 0;
locret_F006DE40:
      return CONCAT44(param_2,puVar2);
    }
    if (10 < (int)param_1) {
      if (param_1 == (undefined *)0xd) {
        _miniMonPutchar(10);
        *puVar2 = 0;
        goto locret_F006DE40;
      }
      if (param_1 != (undefined *)0x15) goto loc_F006DE10;
      param_1 = (undefined *)0xa;
      _miniMonPutchar();
      puVar2 = puVar1;
      goto loc_F006DD88;
    }
    if (param_1 == (undefined *)0x8) {
      param_1 = (undefined *)0x20;
      _miniMonPutchar();
      if (puVar2 != puVar1) {
        param_1 = (undefined *)0x8;
        _miniMonPutchar();
        param_2 = param_2 + 1;
        puVar2 = puVar2 + -1;
      }
      goto loc_F006DD88;
    }
loc_F006DE10:
    if (param_2 == 0) {
      _miniMonPutchar(8);
      _miniMonPutchar(0x20);
      param_1 = (undefined *)0x8;
      _miniMonPutchar();
      goto loc_F006DD88;
    }
    *puVar2 = (char)param_1;
    puVar2 = puVar2 + 1;
  } while( true );
}

