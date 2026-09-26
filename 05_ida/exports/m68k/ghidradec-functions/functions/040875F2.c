
uint _snd_stream_resume(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  cVar3 = '\0';
  bVar7 = *(byte *)(param_1 + 0x24);
  *(byte *)(param_1 + 0x24) = bVar7 & 0xef;
  if ((bVar7 & 8) == 0) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 != param_1 + 0xc) {
      bVar7 = *(byte *)(iVar1 + 0x2d);
      while ((bVar7 & 8) == 0) {
        if ((*(byte *)(iVar1 + 0x2c) & 8) != 0) {
          _snd_reply_resumed(*(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x2e));
        }
        iVar1 = *(int *)(iVar1 + 0x36);
        if (iVar1 == param_1 + 0xc) break;
        bVar7 = *(byte *)(iVar1 + 0x2d);
      }
    }
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 2;
    uVar2 = _thread_wakeup_prim(param_1,0,0);
  }
  else {
    cVar4 = param_1 < 0;
    cVar5 = param_1 == 0;
    cVar6 = '\0';
    bVar7 = 0;
    _snd_link_resume(param_1);
    uVar2 = (uint)(byte)(cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7);
  }
  return uVar2;
}
