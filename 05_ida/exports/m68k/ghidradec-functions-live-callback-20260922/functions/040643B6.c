
void _adb_resume_poll(void)

{
  word in_D1w;
  
  dword_40B0858 = 0;
  sub_40645EA(in_D1w & 0xcff | (word)((dword_40B0834 & 0xf) << 0xc) | 0xc00,0,0,0);
  return;
}

