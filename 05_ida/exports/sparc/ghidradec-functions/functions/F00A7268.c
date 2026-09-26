
/* WARNING: Removing unreachable block (ram,0xf00a7300) */
/* WARNING: Removing unreachable block (ram,0xf00a730c) */
/* WARNING: Removing unreachable block (ram,0xf00a72e4) */
/* WARNING: Removing unreachable block (ram,0xf00a72ec) */
/* WARNING: Removing unreachable block (ram,0xf00a7314) */
/* WARNING: Removing unreachable block (ram,0xf00a7328) */
/* WARNING: Removing unreachable block (ram,0xf00a726c) */

undefined8 _gets(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined uVar2;
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
    puVar1 = param_1;
  }
loc_F00A726C:
  do {
    _cngetc();
    param_1 = (undefined *)((uint)param_1 & 0x7f);
    if (param_1 == (undefined *)0xd) {
      *param_2 = 0;
locret_F00A733C:
      return CONCAT44(param_2,puVar1);
    }
    uVar2 = SUB41(param_1,0);
    if ((undefined *)0xd < param_1) {
      if (param_1 == (undefined *)0x40) {
loc_F00A7328:
        param_1 = (undefined *)0xa;
        _cnputc();
        param_2 = puVar1;
      }
      else {
        if (param_1 < (undefined *)0x41) {
          if (param_1 == (undefined *)0x15) goto loc_F00A7328;
          *param_2 = uVar2;
        }
        else {
          if (param_1 == (undefined *)0x7f) {
            if (param_2 != puVar1) {
              _cnputc(8);
              _cnputc(8);
              goto loc_F00A72F4;
            }
            goto loc_F00A7300;
          }
          *param_2 = uVar2;
        }
loc_F00A7334:
        param_2 = param_2 + 1;
      }
      goto loc_F00A726C;
    }
    if (param_1 != (undefined *)0x8) {
      if (param_1 != (undefined *)0xa) {
        *param_2 = uVar2;
        goto loc_F00A7334;
      }
      *param_2 = 0;
      goto locret_F00A733C;
    }
loc_F00A72F4:
    if (param_2 == puVar1) {
loc_F00A7300:
      param_1 = (undefined *)0x8;
      _cnputc();
    }
    else {
      _cnputc(0x20);
      param_1 = (undefined *)0x8;
      _cnputc();
      param_2 = param_2 + -1;
    }
  } while( true );
}
