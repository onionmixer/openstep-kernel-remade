
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Switch with 1 destination removed at 0x04064b5c : 2 cases all go to same destination */
/* WARNING: Switch with 1 destination removed at 0x04064d5a : 2 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _adb_keyboard(byte *param_1,int param_2)

{
  uint *puVar1;
  word wVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 - 2U < 7) {
    if ((*param_1 & 0x7f) == 0x7f) {
      _printf(aAdbKeyboardEve_0,param_2);
      _AllKeysUp();
    }
    else {
      puVar1 = (uint *)((int)&unk_40B4F36 + (dword_40B4F3E & 1) * 2);
      *puVar1 = *puVar1 & 0x80ffffff | (*param_1 & 0x7f) << 0x18;
      iVar4 = (dword_40B4F3E & 1) * 2;
      *(byte *)((int)&unk_40B4F36 + iVar4) =
           *param_1 & 0x80 | *(byte *)((int)&unk_40B4F36 + iVar4) & 0x7f;
      dword_40B4F3E = dword_40B4F3E + 1;
      if ((param_1[1] & 0x7f) != 0x7f) {
        puVar1 = (uint *)((int)&unk_40B4F36 + (dword_40B4F3E & 1) * 2);
        *puVar1 = *puVar1 & 0x80ffffff | (param_1[1] & 0x7f) << 0x18;
        iVar4 = (dword_40B4F3E & 1) * 2;
        *(byte *)((int)&unk_40B4F36 + iVar4) =
             param_1[1] & 0x80 | *(byte *)((int)&unk_40B4F36 + iVar4) & 0x7f;
        dword_40B4F3E = dword_40B4F3E + 1;
      }
      if (dword_40B4F3A != dword_40B4F3E) {
        do {
          wVar2 = *(word *)((int)&unk_40B4F36 + (dword_40B4F3A & 1) * 2);
          dword_40B4F3A = dword_40B4F3A + 1;
          _byte_40B4F4D =
               CONCAT13(unk_40AD0F2[(wVar2 & 0x7fff) >> 8] & 0x7f | (byte)(wVar2 >> 8) & 0x80,
                        (int3)_byte_40B4F4D);
          if ((unk_40AD0F2[(wVar2 & 0x7fff) >> 8] & 0x7f) == 0) {
            byte_40B4F4C = byte_40B4F4C & 0x7f;
          }
          else {
            byte_40B4F4C = byte_40B4F4C | 0x80;
          }
          if ((int)((uint)wVar2 << 0x10) < 0) {
            if (((wVar2 & 0x7fff) >> 8) - 0x36 < 0x48) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
          }
          else if (((wVar2 & 0x7fff) >> 8) - 0x36 < 0x48) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          if (_eventsOpen != 0) {
            _byte_40B4F4D = _byte_40B4F4D & 0x80ffffff | ((wVar2 & 0x7fff) >> 8) << 0x18;
          }
          uVar3 = (wVar2 & 0x7fff) >> 8;
          if ((char)byte_40B4F4C < '\0') {
            if (uVar3 != 0x32) {
              if (uVar3 == 0x43) {
                while ((byte_40B4F4C & 0x28) == 0x28) {
                  _km_reset();
                }
              }
              goto loc_4064FD0;
            }
            if ((int)_byte_40B4F4D < 0) goto loc_4064FD0;
            if ((byte_40B4F4C & 0x28) == 0x28) {
              _adb_force_NMI();
            }
            else {
              if ((byte_40B4F4C & 8) == 0) goto loc_4064FD0;
              _adb_watchdog(0);
              _mini_mon(&aRestart,aRestartPowerOf);
              _adb_watchdog(1);
            }
            _AllKeysUp();
          }
          else {
loc_4064FD0:
            _ev_k_intr(&unk_40B4F4A);
          }
        } while (dword_40B4F3A != dword_40B4F3E);
      }
    }
  }
  else {
    _printf(aAdbKeyboardEve,param_2);
  }
  return;
}

