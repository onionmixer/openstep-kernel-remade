/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2bc8. */
void __cdecl -[EventDriver canBecomeOwner:](EventDriver *self, SEL a2, id a3)
{
  id v3; // eax
  const char *v4; // eax
  const char *v5; // [esp-14h] [ebp-1Ch]
  const char *v6; // [esp-10h] [ebp-18h]

  v3 = objc_msgSend(a3, sel_becomeOwner_, self); /*0x1b2bdc*/
  if ( v3 )
  {
    v6 = -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v3); /*0x1b2bf6*/
    v5 = (const char *)objc_msgSend(a3, sel_name); /*0x1b2c07*/
    v4 = -[IODevice name](self, sel_name); /*0x1b2c10*/
    IOLog((int)"%s: becomeOwner of %s failed (%s)\n", v4, v5, v6);
  }
}
