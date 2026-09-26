
void _km_big(void)

{
  if ((unk_40B6904 & 0x10) == 0) {
    word_40B68E2 = 0x50;
    word_40B68E6 = 0x28;
    _kmem_alloc_wired(_kernel_map,&dword_40B68EC,(0xa60 / _km_coni) * 0x1fe);
    unk_40B6904 = unk_40B6904 | 0x10;
    dword_40B68E8 = 0;
  }
  return;
}
