
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _trash_user_windows(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_TL;
  
  if (*(int *)(_active_pcb + 0xc) != 0) {
    uVar1 = *(uint *)(_active_pcb + 0xc);
    *(undefined4 *)(_active_pcb + 0xc) = 0;
    iVar3 = __nwindows + -1;
    for (; uVar1 != 0; uVar1 = uVar1 & ~uVar2) {
      uVar2 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                        (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
      uVar2 = uVar2 << ((byte)iVar3 & 0x1f) | uVar2 >> 1;
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar2;
    }
  }
  *(undefined4 *)(_active_pcb + 0x230) = 0;
  return;
}
