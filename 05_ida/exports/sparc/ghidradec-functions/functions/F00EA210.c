
/* WARNING: Removing unreachable block (ram,0xf00ea2d8) */
/* WARNING: Removing unreachable block (ram,0xf00ea250) */

undefined8 sub_F00EA210(char *param_1,byte *param_2)

{
  char cVar1;
  byte *pbVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  byte *pbVar3;
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
  cVar1 = *param_1;
  if (cVar1 == '*') {
loc_F00EA25C:
    pbVar2 = (byte *)0x0;
    if (param_2 == (byte *)0x0) {
      pbVar2 = (byte *)0x0;
      goto locret_F00EA2E0;
    }
    while( true ) {
      pbVar3 = param_2 + 1;
      if (*param_2 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*param_2);
      if (*pbVar3 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*pbVar3 << 8);
      pbVar3 = param_2 + 2;
      if (*pbVar3 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*pbVar3 << 0x10);
      pbVar3 = param_2 + 3;
      if (*pbVar3 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*pbVar3 << 0x18);
      param_2 = param_2 + 4;
    }
  }
  else {
    pbVar3 = param_2;
    if (cVar1 < '+') {
      if (cVar1 == '%') goto loc_F00EA25C;
loc_F00EA2D4:
      pbVar2 = (byte *)((uint)param_2 >> 0x10 ^ (uint)param_2);
    }
    else {
      if (cVar1 != '@') goto loc_F00EA2D4;
      pbVar2 = param_2;
      _objc_msgSend(param_2,paHash);
    }
  }
  .urem();
  param_2 = pbVar3;
locret_F00EA2E0:
  return CONCAT44(param_2,pbVar2);
}
