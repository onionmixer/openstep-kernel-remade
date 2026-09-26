
void _swift_mmu_getsyncflt(void)

{
  uint unaff_l4;
  
  if ((unaff_l4 & 0xf) != 1) {
    segment(4);
  }
  segment(4);
  return;
}

