
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Switch with 1 destination removed at 0x040650b0 : 2 cases all go to same destination */
/* WARNING: Switch with 1 destination removed at 0x04065240 : 2 cases all go to same destination */
/* WARNING: Switch with 1 destination removed at 0x040654b8 : 2 cases all go to same destination */
/* WARNING: Switch with 1 destination removed at 0x040656b6 : 2 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _adb_check_keyboard(uint *param_1)

{
  uint *puVar1;
  word wVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bStack_c;
  byte bStack_b;
  
  if (dword_40B4F3A == dword_40B4F3E) {
    iVar3 = _adb_poll_keyboard(&bStack_c);
    if (iVar3 != 0) {
      if ((bStack_c & 0x7f) != 0x7f) {
        puVar1 = (uint *)((int)&unk_40B4F36 + (dword_40B4F3E & 1) * 2);
        *puVar1 = *puVar1 & 0x80ffffff | (bStack_c & 0x7f) << 0x18;
        iVar3 = (dword_40B4F3E & 1) * 2;
        *(byte *)((int)&unk_40B4F36 + iVar3) =
             bStack_c & 0x80 | *(byte *)((int)&unk_40B4F36 + iVar3) & 0x7f;
        dword_40B4F3E = dword_40B4F3E + 1;
      }
      if ((bStack_b & 0x7f) != 0x7f) {
        puVar1 = (uint *)((int)&unk_40B4F36 + (dword_40B4F3E & 1) * 2);
        *puVar1 = *puVar1 & 0x80ffffff | (bStack_b & 0x7f) << 0x18;
        iVar3 = (dword_40B4F3E & 1) * 2;
        *(byte *)((int)&unk_40B4F36 + iVar3) =
             bStack_b & 0x80 | *(byte *)((int)&unk_40B4F36 + iVar3) & 0x7f;
        dword_40B4F3E = dword_40B4F3E + 1;
      }
      if (dword_40B4F3A != dword_40B4F3E) {
        wVar2 = *(word *)((int)&unk_40B4F36 + (dword_40B4F3A & 1) * 2);
        uVar5 = (uint)wVar2;
        dword_40B4F3A = dword_40B4F3A + 1;
        _unk_40B4F4A = CONCAT31((int3)(_unk_40B4F4A >> 8),
                                unk_40AD0F2[(uVar5 & 0x7fff) >> 8] & 0x7f |
                                (byte)(wVar2 >> 8) & 0x80);
        if ((unk_40AD0F2[(uVar5 & 0x7fff) >> 8] & 0x7f) == 0) {
          _unk_40B4F4A = _unk_40B4F4A & 0xffff7fff;
        }
        else {
          _unk_40B4F4A = _unk_40B4F4A | 0x8000;
        }
        if ((int)(uVar5 << 0x10) < 0) {
          if (((uVar5 & 0x7fff) >> 8) - 0x36 < 0x48) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
        }
        else if (((uVar5 & 0x7fff) >> 8) - 0x36 < 0x48) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        goto loc_4065884;
      }
    }
    uVar4 = 0;
  }
  else {
    wVar2 = *(word *)((int)&unk_40B4F36 + (dword_40B4F3A & 1) * 2);
    uVar5 = (uint)wVar2;
    dword_40B4F3A = dword_40B4F3A + 1;
    _unk_40B4F4A = CONCAT31((int3)(_unk_40B4F4A >> 8),
                            unk_40AD0F2[(uVar5 & 0x7fff) >> 8] & 0x7f | (byte)(wVar2 >> 8) & 0x80);
    if ((unk_40AD0F2[(uVar5 & 0x7fff) >> 8] & 0x7f) == 0) {
      _unk_40B4F4A = _unk_40B4F4A & 0xffff7fff;
    }
    else {
      _unk_40B4F4A = _unk_40B4F4A | 0x8000;
    }
    if (((int)(uVar5 << 0x10) < 0) && (((uVar5 & 0x7fff) >> 8) - 0x36 < 0x48)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
loc_4065884:
    *param_1 = _unk_40B4F4A;
    uVar4 = 1;
  }
  return uVar4;
}

