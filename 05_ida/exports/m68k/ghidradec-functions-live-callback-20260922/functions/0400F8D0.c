
undefined4
_tty_ld_install(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  
  if (((((-1 < param_1) && (param_1 < _nldisp)) &&
       (iVar1 = param_1 * 0x30, (code *)(&_linesw)[param_1 * 0xc] == _nodev)) &&
      ((((*(code **)(unk_40AE4B0 + iVar1) == _nodev &&
         (*(code **)(unk_40AE4B0 + iVar1 + 4) == _nodev)) &&
        ((*(code **)(unk_40AE4B0 + iVar1 + 8) == _nodev &&
         ((*(code **)(unk_40AE4B0 + iVar1 + 0xc) == _nodev &&
          (*(code **)(unk_40AE4B0 + iVar1 + 0x10) == _nodev)))))) &&
       (*(code **)(unk_40AE4B0 + iVar1 + 0x14) == _nodev)))) &&
     (((*(code **)(unk_40AE4B0 + iVar1 + 0x1c) == _nodev &&
       (*(code **)(unk_40AE4B0 + iVar1 + 0x20) == _nodev)) &&
      (*(code **)(unk_40AE4B0 + iVar1 + 0x24) == _nodev)))) {
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x28) = param_2;
    (&_linesw)[param_1 * 0xc] = param_3;
    *(undefined4 *)(unk_40AE4B0 + iVar1) = param_4;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 4) = param_5;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 8) = param_6;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0xc) = param_7;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x10) = param_8;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x14) = param_9;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x1c) = param_10;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x20) = param_11;
    *(undefined4 *)(unk_40AE4B0 + iVar1 + 0x24) = param_12;
    return 0;
  }
  return 0xffffffff;
}

