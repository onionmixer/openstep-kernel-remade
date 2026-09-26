
/* WARNING: Removing unreachable block (ram,0xf0094aec) */
/* WARNING: Removing unreachable block (ram,0xf0094ae4) */

void _call_continuation(code *param_1)

{
  code *pcVar1;
  
  _flush_user_windows();
  _reset_windows();
  (*param_1)();
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
