
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _adb_keybd_init(undefined4 param_1,uint *param_2)

{
  int iStack_8;
  
  _unk_40B4F42 = _unk_40B4F42 | 1;
  _uninstall_scanned_intr(0x33a);
  *(byte *)((int)param_2 + 1) = 3;
  _adb_listen(param_1,3,param_2,2);
  _adb_talk(param_1,3,param_2,&iStack_8);
  if ((iStack_8 == 2) && (*(byte *)((int)param_2 + 1) == 3)) {
    _unk_40B4F42 = _unk_40B4F42 | 2;
    _adb_talk(param_1,2,param_2,&iStack_8);
    if (1 < iStack_8) {
      byte_40B4F47 = (byte)(((uint)(word)(*(byte *)param_2 ^ 0x20) << 0x1a) >> 0x1f) << 6 |
                     (byte)(((uint)(word)(*(byte *)param_2 ^ 0x20) << 0x1a) >> 0x18) & 0x80 |
                     byte_40B4F47 & 0x3f;
      *(byte *)((int)param_2 + 1) =
           *(byte *)((int)param_2 + 1) & 0xfd | (byte)(((*param_2 & 0x3fffffff) >> 0x1d) << 1) | 5;
      _adb_listen(param_1,2,param_2,2);
    }
  }
  return;
}

