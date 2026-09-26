
/* WARNING: Removing unreachable block (ram,0xf00955cc) */

void _fp_disabled(void)

{
  undefined *unaff_l1;
  
  if (unaff_l1 != &loc_F009514C) {
    _fp_is_disabled(_active_pcb + 0x234);
    sys_rtt();
    return;
  }
  _fpu_exists = 0;
  sys_rtt();
  return;
}
