
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _adb_mouse(byte *param_1,int param_2)

{
  undefined4 unaff_A6;
  undefined auStack_8 [2];
  byte bStack_6;
  byte bStack_5;
  undefined2 uStack_4;
  undefined uStack_2;
  undefined uStack_1;
  
  uStack_2 = (undefined)((uint)unaff_A6 >> 8);
  uStack_1 = (undefined)unaff_A6;
  if (6 < param_2 - 2U) {
    return;
  }
  bStack_6 = (~(*param_1 & 0x7f) + 1) * '\x02';
  uStack_4 = (undefined2)((uint)unaff_A6 >> 0x10);
  bStack_5 = (~(param_1[1] & 0x7f) + 1) * '\x02';
  if (param_2 == 3) {
    if ((_unk_40B4F42 & 0x20000) != 0) {
      if ((param_1[2] & 2) != 0) {
        param_1[2] = param_1[2] | 5;
      }
      bStack_6 = bStack_6 | param_1[2] & 1 ^ 1;
      bStack_5 = bStack_5 | ((byte)((uint)*(undefined4 *)(param_1 + 2) >> 0x18) & 7) >> 2 ^ 1;
      goto loc_4065B80;
    }
    if ((_unk_40B4F42 & 0x80000) != 0) {
      if (-1 < (char)param_1[1]) {
        param_1[2] = param_1[2] & 0x7f;
        *param_1 = *param_1 & 0x7f;
      }
      bStack_6 = bStack_6 | (byte)((uint)*(undefined4 *)(param_1 + 2) >> 0x1f);
      bStack_5 = bStack_5 | (byte)((uint)*(undefined4 *)param_1 >> 0x1f);
      goto loc_4065B80;
    }
  }
  bStack_5 = bStack_5 | (byte)((uint)*(undefined4 *)param_1 >> 0x1f);
  bStack_6 = bStack_6 | (byte)((uint)*(undefined4 *)(param_1 + 1) >> 0x1f);
  if ((_unk_40B4F42 & 0x20000) != 0) {
    _unk_40B4F42 = _unk_40B4F42 & 0xfffdffff;
    _adb_mouse_init(3,param_1);
  }
loc_4065B80:
  _ev_m_intr(auStack_8);
  return;
}

