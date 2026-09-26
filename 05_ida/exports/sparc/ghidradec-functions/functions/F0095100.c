
void _syncfpu(void)

{
  undefined4 in_fsr;
  int in_TL;
  
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1000) != 0) {
    dword_F01128CC = in_fsr;
    return;
  }
  return;
}
