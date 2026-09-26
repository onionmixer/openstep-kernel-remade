
void _zone_bootstrap(void)

{
  _first_zone = 0;
  _last_zone = &_first_zone;
  _num_zones = 0;
  unk_40C2BA8 = __zone_default_space_hint;
  dword_40C2BAC = 1;
  _zone_free_space = &__zone_default_space;
  _zone_free_space_count = 1;
  _zone_zone = 0;
  _zone_zone = _zinit(0x3a,0x1d00,0x3a,0,&aZones);
  sub_40556D0(0x10,0x60);
  sub_40556D0(0x80,0x300);
  sub_40556D0(0x400,_page_size);
  return;
}

