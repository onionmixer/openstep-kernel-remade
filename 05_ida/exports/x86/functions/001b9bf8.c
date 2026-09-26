/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9bf8. */
id __cdecl -[InputStream freeRegion:](InputStream *self, SEL a2, $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3)
{
  int v3; // eax
  unsigned int var0; // [esp-8h] [ebp-14h]
  unsigned int var4; // [esp-4h] [ebp-10h]
  objc_super v7; // [esp+4h] [ebp-8h] BYREF

  var4 = a3->var4; /*0x1b9c05*/
  var0 = a3->var0; /*0x1b9c08*/
  v3 = kern_serv_kernel_task_port(); /*0x1b9c09*/
  if ( vm_deallocate_EXTERNAL(v3, var0, var4) )
    IOLog((int)"Audio: stream vm_deallocate error %s\n", "MACH ERR");
  v7.receiver = self; /*0x1b9c38*/
  v7.super_class = (Class)stru_1FA4C4.ext; /*0x1b9c41*/
  return -[AudioStream freeRegion:](&v7, sel_freeRegion_, a3); /*0x1b9c4d*/
}
