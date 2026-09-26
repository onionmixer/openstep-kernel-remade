
/* WARNING: Removing unreachable block (ram,0xf00039b0) */

void fault(void)

{
  uint unaff_g6;
  
  if ((unaff_g6 >> 2 & 7) == 0) {
    return;
  }
  _trap();
  sys_rtt();
  return;
}

