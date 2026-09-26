/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a91bc */

undefined4 _IOSetThreadPolicy(thread_act_t param_1,int param_2)

{
  policy_base_t base;
  kern_return_t kVar1;
  mach_msg_type_number_t unaff_EBP;
  boolean_t unaff_retaddr;
  
  base = (policy_base_t)0x0;
  if (param_2 == 2) {
    base = _min_quantum;
  }
  kVar1 = _thread_policy(param_1,param_2,base,unaff_EBP,unaff_retaddr);
  if (kVar1 == 4) {
    return 0xfffffd3e;
  }
  if (kVar1 != 5) {
    return 0;
  }
  return 0xfffffd3f;
}

