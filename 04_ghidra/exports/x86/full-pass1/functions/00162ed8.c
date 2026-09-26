/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162ed8 */

void _thread_timeout_setup(int param_1)

{
  *(code **)(param_1 + 0x138) = _thread_timeout;
  *(int *)(param_1 + 0x13c) = param_1;
  _init_timeout_element(param_1 + 0x118);
  *(code **)(param_1 + 0x168) = _thread_depress_timeout;
  *(int *)(param_1 + 0x16c) = param_1;
  _init_timeout_element(param_1 + 0x148);
  return;
}

