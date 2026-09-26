/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168bb8 */

undefined4
_host_stack_usage(int param_1,undefined4 *param_2,int *param_3,uint *param_4,uint *param_5,
                 undefined4 *param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_c;
  int local_8;
  
  if (param_1 == 0) {
    uVar1 = 0x16;
  }
  else {
    do {
    } while (_stack_usage_lock != 0);
    LOCK();
    UNLOCK();
    local_c = _stack_max_usage;
    LOCK();
    _stack_usage_lock = 0;
    UNLOCK();
    _stack_statistics(&local_8,&local_c);
    *param_2 = 0;
    *param_3 = local_8;
    uVar2 = _page_mask + local_8 * 0xff4 & ~_page_mask;
    *param_4 = uVar2;
    *param_5 = uVar2;
    *param_6 = local_c;
    *param_7 = 0;
    uVar1 = 0;
  }
  return uVar1;
}

