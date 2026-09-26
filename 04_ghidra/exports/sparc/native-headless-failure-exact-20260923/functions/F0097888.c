
/* WARNING: Removing unreachable block (ram,0xf0097888) */
/* WARNING: Removing unreachable block (ram,0xf00978b0) */

void _clock_timer_init(void)

{
  code *pcVar1;
  
  DAT_f0131478 = 0;
  DAT_f0131468 = 0;
  _get_tod(&_time);
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(8);
  (*pcVar1)();
}

