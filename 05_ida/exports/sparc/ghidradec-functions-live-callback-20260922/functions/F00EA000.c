
/* WARNING: Removing unreachable block (ram,0xf00ea0fc) */
/* WARNING: Removing unreachable block (ram,0xf00ea0b4) */
/* WARNING: Removing unreachable block (ram,0xf00ea01c) */
/* WARNING: Removing unreachable block (ram,0xf00ea03c) */
/* WARNING: Removing unreachable block (ram,0xf00ea0d8) */
/* WARNING: Removing unreachable block (ram,0xf00ea118) */
/* WARNING: Removing unreachable block (ram,0xf00ea00c) */

undefined8 -[IOFrameBufferDisplay validMode:](undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  _objc_msgSend(param_1,paDisplayinfo);
  puVar4 = aColorspace;
  _strlen();
  if (*param_3 != '\0') {
loc_F00EA038:
    pcVar2 = param_3;
    _strncmp(param_3,aColorspace,puVar4);
    if (pcVar2 != (char *)0x0) goto loc_f00ea048;
    param_3 = param_3 + (int)puVar4;
    while( true ) {
      cVar1 = *param_3;
      if ((cVar1 == '\0') || ((cVar1 != ' ' && (cVar1 != '\t')))) break;
      param_3 = param_3 + 1;
    }
    uVar6 = (uint)param_3 & -(uint)(cVar1 != '\0');
    goto loc_F00EA0A0;
  }
loc_F00EA09C:
  uVar6 = 0;
loc_F00EA0A0:
  if (uVar6 == 0) {
    uVar5 = 0;
  }
  else {
    uVar3 = uVar6;
    _strncmp(uVar6,&aBw8,4);
    if (uVar3 == 0) {
      uVar5 = 8;
    }
    else {
      uVar3 = uVar6;
      _strncmp(uVar6,aRgb2568,9);
      if (uVar3 == 0) {
        uVar5 = 0x100;
      }
      else {
        uVar3 = uVar6;
        _strncmp(uVar6,aRgb88824,9);
        if (uVar3 != 0) {
          _strncmp(uVar6,aRgb88832,9);
          uVar5 = 0;
          if (uVar6 != 0) goto locret_F00EA138;
        }
        uVar5 = 0x378;
      }
    }
  }
locret_F00EA138:
  return CONCAT44(param_2,uVar5);
loc_f00ea048:
  param_3 = param_3 + 1;
  if (*param_3 == '\0') goto loc_F00EA09C;
  goto loc_F00EA038;
}

