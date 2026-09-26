
void dz(void)

{
  byte *pbVar1;
  uint auStack_8 [2];
  
  if (_cpu_type == '\0') {
    saveFPUStateFrame(auStack_8[0]);
    if (auStack_8[0]._0_1_ != '\0') {
      pbVar1 = (byte *)((int)auStack_8 + (auStack_8[0] >> 0x10 & 0xff));
      *pbVar1 = *pbVar1 | 8;
    }
    restoreFPUStateFrame(auStack_8[0]);
    std_trap();
    return;
  }
  return;
}
