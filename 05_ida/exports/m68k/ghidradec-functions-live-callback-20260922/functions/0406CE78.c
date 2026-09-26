
int _fc_82077_reset(int *param_1,int *param_2)

{
  int iVar1;
  int **ppiVar2;
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  code *pcStack_14;
  int *piStack_10;
  
  iVar1 = *param_1;
  if ((param_2 != (int *)0x0) && (_fd_polling_mode == 0)) {
    piStack_10 = param_2;
    pcStack_14 = (code *)((int)(param_1 + -0x1030ddb) * -0x3fca482f >> 1);
    piStack_18 = (int *)aFcDControllerR;
    uStack_1c = 0x406ceb6;
    _printf();
  }
  *(undefined *)(iVar1 + 2) = 0;
  piStack_10 = (int *)0x32;
  pcStack_14 = (code *)0x406cec8;
  _delay();
  *(undefined *)(iVar1 + 2) = 4;
  *(undefined *)(iVar1 + 4) = 0;
  *(undefined *)(iVar1 + 7) = 0;
  *(undefined *)((int)param_1 + 0x25) = 0x40;
  *(undefined *)(iVar1 + 8) = 0x40;
  *(undefined4 *)((int)param_1 + 0x25e) = 0;
  *(uint *)((int)param_1 + 0x52) = *(uint *)((int)param_1 + 0x52) & 0xffffbfff;
  pcStack_14 = (code *)0x3;
  piStack_18 = param_1;
  uStack_1c = 0x406cefe;
  iVar1 = _fc_configure();
  if (iVar1 == 0) {
    piStack_10 = (int *)_fd_drive_info;
    pcStack_14 = (code *)0x3;
    piStack_18 = param_1;
    uStack_1c = 0x406cf1a;
    iVar1 = _fc_specify();
    if (iVar1 == 0) {
      piStack_10 = param_1;
      pcStack_14 = sub_406CD48;
      piStack_18 = (int *)0x736;
      uStack_1c = 0x406cf36;
      _install_scanned_intr();
      uStack_1c = 0x400;
      piStack_20 = param_1;
      uStack_24 = 0x406cf42;
      _fc_flags_bclr();
      ppiVar2 = (int **)&uStack_24;
      uStack_24 = 0x2000;
      goto loc_406CF70;
    }
  }
  if ((param_1[6] & 0x2000U) != 0) {
    piStack_10 = (int *)0x736;
    pcStack_14 = (code *)0x406cf5c;
    _uninstall_scanned_intr();
    pcStack_14 = (code *)0x2000;
    piStack_18 = param_1;
    uStack_1c = 0x406cf68;
    _fc_flags_bclr();
  }
  ppiVar2 = &piStack_10;
  piStack_10 = (int *)0x400;
loc_406CF70:
  *(int **)((int)ppiVar2 + -4) = param_1;
  *(undefined4 *)((int)ppiVar2 + -8) = 0x406cf78;
  _fc_flags_bset();
  return iVar1;
}

