/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014b004 */

void _ipc_notify_init_port_destroyed(undefined4 *param_1)

{
  *param_1 = 0x80000012;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x45;
  *(undefined1 *)(param_1 + 6) = 0x10;
  *(undefined1 *)((int)param_1 + 0x19) = 0x20;
  *(ushort *)((int)param_1 + 0x1a) =
       CONCAT11((byte)((ushort)*(undefined2 *)((int)param_1 + 0x1a) >> 8) & 0xf0,1);
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0x1f | 0x10;
  param_1[7] = 0;
  return;
}

