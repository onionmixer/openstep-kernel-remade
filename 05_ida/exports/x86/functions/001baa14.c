/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1baa14. */
id __cdecl -[OutputStream freeRegion:](OutputStream *self, SEL a2, $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3)
{
  int v3; // eax
  int v4; // eax
  objc_super v6; // [esp+4h] [ebp-8h] BYREF

  v3 = kern_serv_kernel_task_port(); /*0x1baa1e*/
  v4 = vm_deallocate_EXTERNAL(v3, a3->var0, a3->var4); /*0x1baa2b*/
  if ( v4 )
    IOLog((int)"Audio: stream vm_deallocate error %d\n", v4);
  v6.receiver = self; /*0x1baa50*/
  v6.super_class = (Class)stru_1FA514.super_class; /*0x1baa59*/
  return -[AudioStream freeRegion:](&v6, sel_freeRegion_, a3); /*0x1baa65*/
}
