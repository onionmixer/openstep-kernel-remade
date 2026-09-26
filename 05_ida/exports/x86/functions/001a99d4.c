/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a99d4. */
id __cdecl -[IONetbufQueue free](IONetbufQueue *self, SEL a2)
{
  $199DFB5D1DF31DC82E78091AC4DEC886 *v2; // eax
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  while ( 1 ) /*0x1a99e8*/
  {
    v2 = -[IONetbufQueue dequeue](self, sel_dequeue); /*0x1a99e8*/
    if ( !v2 ) /*0x1a99f2*/
      break; /*0x1a99f2*/
    nb_free((int)v2); /*0x1a99f5*/
  }
  v4.receiver = self; /*0x1a9a07*/
  v4.super_class = (Class)stru_1FA294.super_class; /*0x1a9a10*/
  return -[Object free](&v4, sel_free); /*0x1a9a1c*/
}
