
/* WARNING: Removing unreachable block (ram,0xf00b1e7c) */
/* WARNING: Removing unreachable block (ram,0xf00b1e54) */
/* WARNING: Removing unreachable block (ram,0xf00b1de4) */
/* WARNING: Removing unreachable block (ram,0xf00b1db4) */
/* WARNING: Removing unreachable block (ram,0xf00b1d8c) */
/* WARNING: Removing unreachable block (ram,0xf00b1d04) */
/* WARNING: Removing unreachable block (ram,0xf00b1cd8) */
/* WARNING: Removing unreachable block (ram,0xf00b1cbc) */
/* WARNING: Removing unreachable block (ram,0xf00b1cec) */
/* WARNING: Removing unreachable block (ram,0xf00b1d7c) */
/* WARNING: Removing unreachable block (ram,0xf00b1d98) */
/* WARNING: Removing unreachable block (ram,0xf00b1dd0) */
/* WARNING: Removing unreachable block (ram,0xf00b1dfc) */
/* WARNING: Removing unreachable block (ram,0xf00b1e6c) */
/* WARNING: Removing unreachable block (ram,0xf00b1ef8) */
/* WARNING: Removing unreachable block (ram,0xf00b1ca4) */

undefined8 _consconfig(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  word wVar6;
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
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
  iVar1 = -1;
  *(undefined2 *)((int)register0x00000038 + -0x14) = 0xffff;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  _prom_stdin_stdout_equivalence();
  puVar5 = (undefined *)((int)register0x00000038 + -0x118);
  if ((iVar1 != 0) &&
     (puVar3 = puVar5, _prom_get_stdin_dev_name(puVar5,0x100), puVar3 == (undefined *)0x0)) {
    puVar2 = &unk_F011D158;
    _strcmp(&unk_F011D158,puVar5);
    puVar5 = DAT_f013ec00;
    if (puVar2 == (undefined8 *)0x0) {
      _prom_get_stdin_unit();
      puVar3 = DAT_f013ec00;
      if (puVar5 != (undefined *)0xffffffff) {
        wVar6 = 0;
        _prom_get_stdin_subunit();
        if ((puVar3 != (char *)0x0) && (wVar6 = 0, *puVar3 != '\0')) {
          wVar6 = (sword)(char)*puVar3 - 0x61U & 1;
        }
        _rconsdev = wVar6 + (sword)((int)puVar5 << 1) | 0x2600;
      }
    }
  }
  iVar1 = (int)(sword)_rconsdev;
  if (iVar1 != 0) {
    _kbddev = _rconsdev;
    _consdev = _rconsdev;
    _walk_devs(_top_devinfo,_findcons,(undefined *)((int)register0x00000038 + -0x18));
    _options_devinfo = *(undefined4 *)((int)register0x00000038 + -0x10);
    _set_keyclick();
    goto locret_F00B1F3C;
  }
  _prom_stdin_is_keyboard();
  if (iVar1 == 0) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x118);
    puVar5 = puVar3;
    _prom_get_stdin_dev_name(puVar3,0x100);
    if (puVar5 != (undefined *)0x0) goto loc_F00B1E44;
    puVar2 = &unk_F011D160;
    _strcmp(&unk_F011D160,puVar3);
    if (puVar2 != (undefined8 *)0x0) goto loc_F00B1E44;
    _prom_get_stdin_unit();
    pcVar4 = (char *)(int)(sword)_kbddev;
    if (puVar2 != (undefined8 *)0xffffffff) {
      wVar6 = 0;
      _prom_get_stdin_subunit();
      if ((pcVar4 != (char *)0x0) && (wVar6 = 0, *pcVar4 != '\0')) {
        wVar6 = (sword)*pcVar4 - 0x61U & 1;
      }
      _kbddev = wVar6 + (sword)((int)puVar2 << 1) | 0x2600;
      goto loc_F00B1E44;
    }
  }
  else {
loc_F00B1E44:
    pcVar4 = (char *)(int)(sword)_kbddev;
  }
  if (pcVar4 != (char *)0xffffffff) {
    _zsgetspeed();
  }
  _walk_devs(_top_devinfo,_findcons,(undefined *)((int)register0x00000038 + -0x18));
  _options_devinfo = *(undefined4 *)((int)register0x00000038 + -0x10);
  _set_keyclick();
  iVar1 = *(int *)((int)register0x00000038 + -0x18);
  if (iVar1 != -1) {
    if (_mousedev == 0xffff) {
      _mousedev = (sword)iVar1 * 2 + 1U | 0x2600;
    }
    if (_kbddev == 0xffff) {
      _kbddev = (word)(iVar1 << 1) | 0x2600;
    }
  }
  if (_kbddev == 0xffff) {
    _panic(aNoKeyboardFoun);
  }
  _kbddevopen = 0;
  if (_fbdev == -1) {
    _fbdev = *(sword *)((int)register0x00000038 + -0x14);
  }
  _consdev = _kbddev & 0xff | 0xc00;
  _rconsdev = _consdev;
locret_F00B1F3C:
  return CONCAT44(param_2,param_1);
}
