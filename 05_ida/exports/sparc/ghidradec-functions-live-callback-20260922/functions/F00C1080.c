
/* WARNING: Removing unreachable block (ram,0xf00c119c) */
/* WARNING: Removing unreachable block (ram,0xf00c13cc) */
/* WARNING: Removing unreachable block (ram,0xf00c1350) */
/* WARNING: Removing unreachable block (ram,0xf00c1118) */
/* WARNING: Removing unreachable block (ram,0xf00c1228) */
/* WARNING: Removing unreachable block (ram,0xf00c11d8) */
/* WARNING: Removing unreachable block (ram,0xf00c11cc) */
/* WARNING: Removing unreachable block (ram,0xf00c1238) */
/* WARNING: Removing unreachable block (ram,0xf00c1218) */
/* WARNING: Removing unreachable block (ram,0xf00c126c) */
/* WARNING: Removing unreachable block (ram,0xf00c1128) */
/* WARNING: Removing unreachable block (ram,0xf00c13c4) */
/* WARNING: Removing unreachable block (ram,0xf00c115c) */
/* WARNING: Removing unreachable block (ram,0xf00c118c) */
/* WARNING: Removing unreachable block (ram,0xf00c1088) */

undefined8 sub_F00C1080(uint param_1,undefined4 param_2)

{
  byte bVar1;
  char *pcVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 uVar6;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  pcVar2 = (char *)((int)register0x00000038 + 0x48);
  sub_F00C0EF4();
  uVar6 = 0;
  if (pcVar2 == (char *)0x0) goto locret_F00C13F4;
  bVar1 = pcVar2[1];
  if (bVar1 == 1) {
    if ((param_1 & 0xff) == 0x7f) {
      sub_F00C13FC(*(undefined4 *)((int)register0x00000038 + 0x48),0);
    }
    else if ((param_1 & 0xff) == 0xff) {
      pcVar2[1] = '\x02';
    }
    else if ((param_1 & 0x80) == 0) {
      _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
    }
    else {
      sub_F00C13FC(*(undefined4 *)((int)register0x00000038 + 0x48),param_1 & 0x40 | 1);
    }
    goto locret_F00C13F4;
  }
  if (bVar1 < 2) {
    if (bVar1 == 0) {
      if ((param_1 & 0xff) == 0x7f) {
        pcVar2[1] = '\x01';
        uVar5 = *(undefined4 *)((int)register0x00000038 + 0x48);
        uVar3 = _hz;
        div(_hz,10);
        _timeout(_kbdidletimeout,uVar5,uVar3);
      }
      else if ((param_1 & 0xff) == 0xff) {
        pcVar2[1] = '\x02';
      }
      goto locret_F00C13F4;
    }
    cVar4 = pcVar2[2];
  }
  else {
    if (bVar1 == 2) {
      if ((param_1 & 0xff) == 4) {
        _kbdcmd(*(undefined4 *)((int)register0x00000038 + 0x48),0xf);
        uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      else {
        uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48);
        if ((param_1 & 0xff) != 0x81) {
          _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
          goto locret_F00C13F4;
        }
      }
      sub_F00C13FC(uVar3,param_1 & 0xff);
      if (_kbdclick == 0) {
        uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      else if (((0 < _kbdclick) &&
               (uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48), _kbdclick == 1)) ||
              (uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48), _keyclick != 0)) {
        _kbdcmd(uVar3,10);
        goto locret_F00C13F4;
      }
      _kbdcmd(uVar3,0xb);
      goto locret_F00C13F4;
    }
    if (bVar1 == 3) {
      if ((((param_1 & 0xff) == 0) && (pcVar2[2] != '\x04')) || ((param_1 & 0xff) == 0xff)) {
        _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
        goto locret_F00C13F4;
      }
      cVar4 = pcVar2[2];
    }
    else {
      cVar4 = pcVar2[2];
    }
  }
  switch(cVar4) {
  case :
    break;
  case :
    if (*(int *)(pcVar2 + 0xc) == 0) goto locret_F00C13F4;
    if ((param_1 & 0xff) == (uint)*(byte *)(*(int *)(pcVar2 + 0xc) + 0x25)) {
      _us_spin(100000);
      uVar6 = 0;
      _prom_enter_mon();
      pcVar2[2] = '\0';
      goto locret_F00C13F4;
    }
    pcVar2[2] = '\0';
    break;
  case :
    if ((param_1 & 0x80) == 0) {
      if ((param_1 & 0xff) == 0x7f) goto locret_F00C13F4;
      pcVar2[2] = '\0';
      break;
    }
    if (*pcVar2 == '\x01') {
      pcVar2[2] = '\x03';
      goto locret_F00C13F4;
    }
    if ((param_1 & 0xff) != 0xfe) {
      _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
      goto locret_F00C13F4;
    }
    goto loc_F00C1344;
  case :
    if ((param_1 & 0xff) == 0x7f) {
      pcVar2[2] = '\x02';
      goto locret_F00C13F4;
    }
    pcVar2[2] = '\0';
    break;
  case :
    pcVar2[0x2b] = (char)param_1;
    pcVar2[2] = '\0';
    goto locret_F00C13F4;
  case :
  case :
  case :
    if ((param_1 & 0xff) == 0x7f) goto locret_F00C13F4;
    goto loc_F00C13EC;
  :
    goto locret_F00C13F4;
  }
  uVar6 = 0;
  if ((*(int *)(pcVar2 + 0xc) == 0) ||
     ((param_1 & 0xff) != (uint)*(byte *)(*(int *)(pcVar2 + 0xc) + 0x24))) {
    if ((param_1 & 0xff) == 0xfe) {
loc_F00C1344:
      uVar6 = 0;
      pcVar2[2] = '\x04';
    }
    else {
      uVar6 = 1;
      if ((param_1 & 0xff) == 0x7f) {
        pcVar2[2] = '\x02';
loc_F00C13EC:
        uVar6 = 0;
      }
    }
  }
  else {
    pcVar2[2] = '\x01';
  }
locret_F00C13F4:
  return CONCAT44(uVar6,uVar6);
}

