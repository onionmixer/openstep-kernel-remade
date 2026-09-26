
void _RecordBrightness(void)

{
  undefined uStack_24;
  uint uStack_23;
  
  _nvram_check(&uStack_24);
  uStack_23 = uStack_23 & 0xf03fffff | (_curBright & 0x3f) << 0x16;
  _nvram_set(&uStack_24);
  return;
}

