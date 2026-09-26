
void _alert_done(void)

{
  sword sVar1;
  word wVar2;
  bool bVar3;
  
  _alert_key = 0;
  wVar2 = unk_40B6904 & 0xfeff;
  if ((unk_40B6904 & 0x20) != 0) {
    unk_40B6904 = unk_40B6904 & 0xfedf;
    wVar2 = unk_40B6904;
    if ((word_40B6938 != 0) &&
       (sVar1 = word_40B6938 + -1, bVar3 = word_40B6938 == 1, word_40B6938 = sVar1, bVar3)) {
      _kmrestore();
      _alert_lock_screen(0);
      wVar2 = unk_40B6904;
    }
  }
  unk_40B6904 = wVar2;
  return;
}

