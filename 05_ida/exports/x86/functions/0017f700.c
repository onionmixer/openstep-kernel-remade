/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f700. */
char __cdecl +[KernBus probeBus:](id a1, SEL a2, id a3)
{
  id v3; // eax

  v3 = objc_msgSend(a1, sel_alloc); /*0x17f715*/
  objc_msgSend(v3, sel_init); /*0x17f71e*/
  return 1; /*0x17f72a*/
}
