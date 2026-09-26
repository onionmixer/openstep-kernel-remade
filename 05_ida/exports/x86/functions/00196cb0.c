/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196cb0. */
int __cdecl -[kmDevice setIntValues:forParameter:count:](
        kmDevice *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  objc_super v6; // [esp+Ch] [ebp-8h] BYREF

  if ( !strcmp(a4, aPrettyshutdown) ) /*0x196cd0*/
  {
    prettyShutdown = *(_WORD *)a3; /*0x196cff*/
    return 0; /*0x196d06*/
  }
  else
  {
    v6.receiver = self; /*0x196ce2*/
    v6.super_class = (Class)stru_1FA014.super_class; /*0x196ceb*/
    return -[IODevice setIntValues:forParameter:count:](&v6, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x196cf2*/
  }
}
