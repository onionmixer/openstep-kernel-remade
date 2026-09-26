/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a83e8. */
id __cdecl -[IODirectDevice initFromDeviceDescription:](IODirectDevice *self, SEL a2, id a3)
{
  _DWORD *v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  v5.receiver = self; /*0x1a83fd*/
  v5.super_class = (Class)stru_1FA1A4.super_class; /*0x1a8406*/
  -[IODevice init](&v5, sel_init); /*0x1a840d*/
  -[IODirectDevice setDeviceDescription:](self, sel_setDeviceDescription_, a3); /*0x1a841b*/
  -[IODirectDevice initEISA](self, sel_initEISA); /*0x1a8428*/
  v3 = (_DWORD *)IOMalloc(8u); /*0x1a842f*/
  self->_private = v3; /*0x1a8434*/
  v3[1] = 0; /*0x1a843a*/
  *v3 = 0; /*0x1a8441*/
  return self; /*0x1a844c*/
}
