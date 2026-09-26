/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1924. */
id __cdecl -[EventDriver _performSpecialKeyMsg:](EventDriver *self, SEL a2, id a3)
{
  int v3; // eax
  int v4; // ebx
  const char *v5; // eax
  int v7; // [esp-4h] [ebp-14h]

  v3 = msg_send(a3, 1, 0); /*0x1b193b*/
  v4 = v3; /*0x1b1940*/
  if ( v3 )
  {
    v7 = v3; /*0x1b1949*/
    v5 = -[IODevice name](self, sel_name); /*0x1b1952*/
    IOLog((int)"%s: _performSpecialKeyMsg msg_send returned %d\n", v5, v7);
  }
  if ( v4 == -102 ) /*0x1b196b*/
    -[EventDriver setSpecialKeyPort:keyFlavor:keyPort:]( /*0x1b1982*/
      self,
      sel_setSpecialKeyPort_keyFlavor_keyPort_,
      self->ev_port,
      *((_DWORD *)a3 + 7),
      0);
  IOFree((int)a3, 56); /*0x1b1990*/
  return self; /*0x1b199a*/
}
