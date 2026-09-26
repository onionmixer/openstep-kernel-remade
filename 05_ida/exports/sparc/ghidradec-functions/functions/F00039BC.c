
/* WARNING: Removing unreachable block (ram,0xf0003a94) */
/* WARNING: Removing unreachable block (ram,0xf00039f0) */

void interrupt(void)

{
  uint unaff_l4;
  uint uVar1;
  int iVar2;
  
  uVar1 = unaff_l4 & 0xf;
  iVar2 = uVar1 * 4;
  if (uVar1 == 0xf) {
    _set_intmask(0x80000000,0);
  }
  uVar1 = 0x10000 << (sbyte)uVar1;
  if ((uRamfeff4000 & uVar1) == 0) {
    uVar1 = uVar1 >> 0x10;
    if ((uRamfeff4000 & uVar1) == 0) {
      sys_rtt();
      return;
    }
  }
  else {
    iVar2 = iVar2 + 0x40;
  }
  if ((uVar1 & 0xffff8000) != 0) {
    uRamfeff4004 = uVar1;
  }
  (**(code **)(_int_vector + iVar2))();
  _flush_writebuffers_to();
  sys_rtt();
  return;
}
