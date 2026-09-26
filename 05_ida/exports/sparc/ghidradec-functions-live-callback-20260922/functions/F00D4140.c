
/* WARNING: Removing unreachable block (ram,0xf00d41c4) */

undefined8 -[EventDriver forceAutoDimState:](int param_1,undefined4 param_2,char param_3)

{
  undefined (*pauVar1) [12];
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
  if (param_3 == '\x01') {
    if (*(char *)(param_1 + 0x1d3) != '\0') goto locret_F00D41CC;
    pauVar1 = (undefined (*) [12])paDoautodim;
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x10);
      pauVar1 = (undefined (*) [12])paDoautodim;
    }
  }
  else {
    if (*(char *)(param_1 + 0x1d3) != '\x01') goto locret_F00D41CC;
    pauVar1 = paUndoautodim;
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      *(int *)(param_1 + 0x1a4) =
           *(int *)(*(int *)(param_1 + 0x168) + 0x10) + *(int *)(param_1 + 0x1a0);
      pauVar1 = paUndoautodim;
    }
  }
  _objc_msgSend(param_1,pauVar1);
locret_F00D41CC:
  return CONCAT44(param_2,param_1);
}

