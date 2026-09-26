
void _DoKbdRepeat(void)

{
  sword sVar1;
  bool bVar2;
  
  if (((word_40B1252 != -1) && (_eventsOpen != 0)) &&
     (sVar1 = word_40B1252 + -1, bVar2 = word_40B1252 == 1, word_40B1252 = sVar1, bVar2)) {
    if ((*(byte *)(word_40B1254 + 2 + _curMapping) & 0x20) != 0) {
      _DoCharGen(_curMapping,(int)word_40B1254,2);
    }
    word_40B1252 = sRam040c3652;
  }
  return;
}
