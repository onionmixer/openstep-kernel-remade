
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _reset_windows(void)

{
  int iVar1;
  int in_TL;
  
  iVar1 = (*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                     (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1f) + 1;
  if (iVar1 == __nwindows) {
    iVar1 = 0;
  }
  *(int *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
          (uint)(in_TL == 4) * 0x600c) = 1 << ((byte)iVar1 & 0x1f);
  return;
}

