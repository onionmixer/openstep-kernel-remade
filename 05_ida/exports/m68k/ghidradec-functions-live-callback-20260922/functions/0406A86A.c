
void _evdispatch(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  code *pcVar5;
  
  iVar1 = _evScreen + param_2 * 0x28;
  uVar4 = 0;
  if ((param_1 < 4) || ((*(byte *)(iVar1 + 0x14) & 0x60) != 0)) {
    *(byte *)(iVar1 + 0x14) =
         *(byte *)(iVar1 + 0x14) & 0x9f |
         (DAT_40b127c[(param_1 & 3) + ((*(byte *)(iVar1 + 0x14) & 0x7f) >> 5) * 4] & 3) << 5;
    uVar2 = (*(byte *)(iVar1 + 0x14) & 0x7f) >> 5;
    if (uVar2 == 2) {
      pcVar5 = *(code **)(iVar1 + 0x20);
loc_406A8F0:
      if (pcVar5 != (code *)0x0) {
        uVar4 = (*pcVar5)(iVar1,*(undefined4 *)(_evg + 0x18),*(undefined4 *)(_evg + 0x1c));
      }
    }
    else if (uVar2 < 3) {
      if ((uVar2 == 1) && (*(code **)(iVar1 + 0x18) != (code *)0x0)) {
        uVar4 = (**(code **)(iVar1 + 0x18))(iVar1);
      }
    }
    else if (uVar2 == 3) {
      pcVar5 = *(code **)(iVar1 + 0x1c);
      goto loc_406A8F0;
    }
    if (uVar4 == 0) {
      *(byte *)(iVar1 + 0x14) = (byte)(((uint)*(byte *)(iVar1 + 0x14) << 0x19) >> 0x1e);
    }
  }
  if (param_1 == 4) {
    dword_40B4FB2 = param_3;
  }
  else if (-1 < *(char *)(iVar1 + 0x14)) goto loc_406A96C;
  if (*(code **)(iVar1 + 0x24) != (code *)0x0) {
    cVar3 = (**(code **)(iVar1 + 0x24))(iVar1,dword_40B4FB2);
    *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) & 0x7f | cVar3 << 7;
    uVar4 = *(byte *)(iVar1 + 0x14) >> 7 | uVar4;
  }
loc_406A96C:
  uVar2 = 1 << (param_2 & 0x3f);
  _evRetryMask = _evRetryMask & ~uVar2;
  if (uVar4 != 0) {
    _evRetryMask = uVar2 | _evRetryMask;
  }
  return;
}

