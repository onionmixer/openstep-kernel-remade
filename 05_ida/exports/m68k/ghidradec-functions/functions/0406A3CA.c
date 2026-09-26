
void _HideWaitCursor(void)

{
  *(undefined4 *)(_evg + 0x40) = 0;
  sub_406A9D4(0);
  return;
}
