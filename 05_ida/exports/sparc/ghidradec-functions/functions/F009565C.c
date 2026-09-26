
void _mmu_flushctx(int param_1)

{
  if ((*(uint *)(_contexts + param_1 * 4) & 3) != 1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0xf0095690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushctx)(param_1,param_1);
  return;
}
